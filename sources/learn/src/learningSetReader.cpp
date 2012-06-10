/** 
* @file
* Implementation of LearningSetReader class
* 
* Parses given folder file structure building learning set based on its contents
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "learningSetReader.h"
#include "audioSample.h"
#include "fft.h"
#include <boost/filesystem.hpp>

using namespace learn;
using namespace std;
using namespace boost::filesystem;


bool LearningSetReader::initialize(const std::string& learningSetsFolder) throw (...)
{
	filesByCategory_.clear();

	path root_path(learningSetsFolder);
	if (!is_directory(root_path))
		throw std::runtime_error("Given path is not a folder");

	for (directory_iterator dir_iter(root_path); dir_iter != directory_iterator(); ++dir_iter)
	{
		const path& dir_path = dir_iter->path();
		if (is_directory(dir_path))
		{
			//treat each folder in given patch as category with name as folder name and assign to it files inside (including subfolders, recursively)
			for (recursive_directory_iterator file_iter(dir_path); file_iter != recursive_directory_iterator(); ++file_iter)
			{
				const path& file_path = file_iter->path();
				if (is_regular_file(file_path))
				{
					filesByCategory_.insert(pair<string,string>(dir_path.filename().string(), file_path.string()));
				}			
			}
		}
	}

	learningSampleIter_ = filesByCategory_.begin();
	learningSampleCounter_ = 0;

	return !filesByCategory_.empty();
}


auto_ptr< set<string> > LearningSetReader::getCategories() const
{
	auto_ptr< std::set<string> > categories(new set<string>);

	std::multimap<std::string, std::string>::const_iterator citer;
	for (citer = filesByCategory_.begin(); citer != filesByCategory_.end(); ++citer)
		categories->insert(citer->first);

	return categories;
}


auto_ptr< LearningSample<string> > LearningSetReader::getNextLearningSample(unsigned short sampleTimeMs, float* outProgress)
{
	media::AudioSample audioSample;
	string category;
	string filePath;

	while (learningSampleIter_ != filesByCategory_.end() && !audioSample.getSize())
	{
		category = learningSampleIter_->first;
		filePath = learningSampleIter_->second;

		if (!fileReader_.is_open())
			fileReader_.openFile(filePath);
		
		try
		{
			fileReader_.readTo(audioSample, sampleTimeMs);
		}
		catch(...)
		{
			/// end of file reached - read next file
			++learningSampleIter_;
			++learningSampleCounter_;
			fileReader_.closeFile();
		}
	}
	
	if (!audioSample.getSize())
		return auto_ptr< LearningSample<string> >(); /// returns empty pointer


	std::auto_ptr<media::FFTSample> fftSample = media::FFT::getInstance().calculateFFT(audioSample);
		
	auto_ptr< LearningSample<string> > learningSample(new LearningSample<string>(boost::shared_ptr<media::FFTSample>(fftSample), category));
	
	if (outProgress)
		*outProgress = learningSampleCounter_*100/(float)filesByCategory_.size();

	return learningSample;
}
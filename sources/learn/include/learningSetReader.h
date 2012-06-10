/** 
* @file
* Declaration of LearningSetReader class
*
* Parses given folder file structure building learning set based on its contents
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __LEARNING_SET_READER_H__
#define __LEARNING_SET_READER_H__

#include <memory>
#include <set>
#include "learningSample.h"
#include "waveReader.h"

namespace learn
{

class LearningSetReader
{
public:
	bool initialize(const std::string& learningSetsFolder); /// parses given folder structure. Reads categories and file names. May throw. Returns true if files in correct file structure were found, false otherwise
	std::auto_ptr< std::set<std::string> > getCategories() const; /// returns smart pointer to vector of learning categories represented as text labels (taken from folder names)

	std::auto_ptr< LearningSample<std::string> > getNextLearningSample(unsigned short sampleTimeMs, float* outProgress=NULL); /// when class is initialized, every time it is called it returns another learning sample of requested length. Progress may be reported to the outProgress variable pointer. May throw exceptions from FileReader

protected:
	std::multimap<std::string, std::string>					filesByCategory_;		/// assigns path to the files to category labels
	std::multimap<std::string, std::string>::const_iterator	learningSampleIter_;	/// iterator that points to a file path to be read next
	unsigned long											learningSampleCounter_; /// counts already read samples

	media::WaveReader										fileReader_; /// file reader object
};

}; //namespace

#endif
/** 
* @file
* Implementation of Teacher class
* 
* Controls teaching process of neural network. Uses data provided by LearningSetReader class
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "teacher.h"

using namespace learn;
using namespace std;


void Teacher::doLearn(const string& learningSetsFolder, learn::progress_callback progressCallback, const boost::shared_ptr< neur::NeuralNetwork<> >& neuralNetwork)
{
	abortLearning(); /// stops current learning process, if any

	learningDone_= false;
	abortFlag_ = false;
	thread_ = boost::thread(&Teacher::learningThread, this, progressCallback, neuralNetwork, learningSetsFolder, spectralResolution_, maximumFrequency_);
}


bool Teacher::abortLearning() throw()
{
	if (!thread_.joinable())
		return false; /// thread is not running
	else
	{
		abortFlag_ = true;
		thread_.join();
		return true;
	}
}


void Teacher::learningThread(learn::progress_callback progressCallback, const boost::shared_ptr< neur::NeuralNetwork<> > neuralNetwork, const string learningSetsFolder, float spectralResolution, unsigned short maximumFrequency)
{
	float progress = 0;

	try
	{
		progressCallback(progress, NULL);

		learningSetReader_ = auto_ptr<LearningSetReader>(new LearningSetReader);
		if (!learningSetReader_.get())
			throw std::bad_alloc();
		
		if (!learningSetReader_->initialize(learningSetsFolder))
			throw std::runtime_error("No appropirate file structure found at given path");
		
		std::auto_ptr< std::set<std::string> > categories = learningSetReader_->getCategories();
		if (!categories.get() || !categories->size())
			throw std::runtime_error("No appropirate file structure found at given path");

		//neuralNetwork->initializeNetwork((unsigned long)(maximumFrequency/spectralResolution), categories);

		unsigned short sampleTime = (unsigned short)(1000/spectralResolution);

		while (!abortFlag_ && progress < 100)
		{
			auto_ptr< LearningSample<string> > learningSample = learningSetReader_->getNextLearningSample(sampleTime, &progress);
			if (!learningSample.get())
				progress = 100;
			else
			{
				boost::this_thread::sleep(boost::posix_time::milliseconds(20));//TMP!
			}
			progressCallback(progress, NULL);
		}
		
		if (progress == 100)
			learningDone_ = true;
	}
	catch (std::exception& e)
	{
		progressCallback(progress, &e);
	}
	catch(...)
	{
		std::bad_exception e;
		progressCallback(progress, &e);
	}

	learningSetReader_.release();
}
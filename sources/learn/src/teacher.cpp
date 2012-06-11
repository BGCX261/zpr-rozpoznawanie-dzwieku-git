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
#include <string>

using namespace learn;
using namespace std;


void Teacher::doLearn(const string& learningSetsFolder, learn::progress_callback progressCallback, const boost::shared_ptr< neur::NeuralNetwork<> >& neuralNetwork)
{
	abortLearning(); /// stops current learning process, if any

	learningDone_= false;
	abortFlag_ = false;

	if (!neuralNetwork.get())
		throw std::runtime_error("Invalid pointer to neural network");

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


void Teacher::learningThread(learn::progress_callback progressCallback, const boost::shared_ptr<neur::NeuralNetwork<> > neuralNetwork, const string learningSetsFolder, float spectralResolution, unsigned short maximumFrequency)
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

		std::vector<unsigned long> hiddenLayersNeuronNums;
		unsigned long hiddenLayerNeuronsNum = 10; /// TODO - make it changable
		hiddenLayersNeuronNums.push_back(hiddenLayerNeuronsNum);
		neuralNetwork->initializeNetwork((unsigned long)(maximumFrequency/spectralResolution), hiddenLayersNeuronNums, categories);

		unsigned short sampleTime = (unsigned short)(1000/spectralResolution);

		while (!abortFlag_ && progress < 100)
		{
			auto_ptr< LearningSample<string> > learningSample = learningSetReader_->getNextLearningSample(sampleTime, &progress);
			if (!learningSample.get())
				progress = 100;
			else
			{
				neur::ResultSet<string> desirableResult;
				std::map<string, float>& desirableResultMap = desirableResult.getWritable();

				for (std::set<std::string>::const_iterator citer = categories->begin(); citer != categories->end(); ++citer)
					desirableResultMap[*citer] = ((*citer == learningSample->getCategory()) ? 100.0f : 0.0f);

				neuralNetwork->learnPattern(learningSample->getSample().get()->get(), desirableResult);
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

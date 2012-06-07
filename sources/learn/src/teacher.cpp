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


void Teacher::doLearn(const string& learningSetsFolder, learn::progress_callback progressCallback, const boost::shared_ptr<neur::NeuralNetwork>& neuralNetwork)
{
	abortLearning(); /// stops current learning process, if any

	learningDone_= false;
	abortFlag_ = false;
	thread_ = boost::thread(&Teacher::learningThread, this, progressCallback, neuralNetwork);
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


void Teacher::learningThread(learn::progress_callback progressCallback, const boost::shared_ptr<neur::NeuralNetwork>& neuralNetwork)
{
	float progress = 0;

	try
	{
		progressCallback(progress, NULL);

		while (!abortFlag_ && progress < 100)
		{
			boost::this_thread::sleep(boost::posix_time::milliseconds(50));//TMP!
			++progress;
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
}
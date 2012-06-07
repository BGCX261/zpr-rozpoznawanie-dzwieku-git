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


void Teacher::doLearn(const string& learningSetsFolder, const binary_function<float, const std::exception&, bool>& progressCallback, const boost::shared_ptr<neur::NeuralNetwork>& neuralNetwork)
{
	abortLearning(); /// stops current learning process, if any

	stopFlag_ = false;
	thread_ = boost::thread(&Teacher::learningThread, this, progressCallback, neuralNetwork);
}


bool Teacher::abortLearning() throw()
{
	if (!thread_.joinable())
		return false; /// thread is not running
	else
	{
		stopFlag_ = true;
		thread_.join();
		return true;
	}
}


void Teacher::learningThread(const binary_function<float, const std::exception&, bool>& progressCallback, const boost::shared_ptr<neur::NeuralNetwork>& neuralNetwork)
{
	while (!stopFlag_)
	{

	}
}
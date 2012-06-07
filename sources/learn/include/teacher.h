/** 
* @file
* Declaration of Teacher class
*
* Controls teaching process of neural network. Uses data provided by LearningSetReader class
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __TEACHER_H__
#define __TEACHER_H__

#include <string>
#include <exception>
#include <boost\thread.hpp>
#include "neuralNetwork.h"

namespace learn /// namespace for learning process modules
{

class Teacher
{
public:
	Teacher() : stopFlag_(false) {}

	void doLearn(const std::string& learningSetsFolder, const std::binary_function<float, const std::exception&, bool>& progressCallback, const boost::shared_ptr<neur::NeuralNetwork>& neuralNetwork); /// starts learning process using given folder with learning sets. Non-blocking (another thread) - raporting learning progress through callback
	bool abortLearning() throw(); /// aborts learning process. Returns true if process was stopped, false if learning was not in progress

protected:
	void learningThread(const std::binary_function<float, const std::exception&, bool>& progressCallback, const boost::shared_ptr<neur::NeuralNetwork>& neuralNetwork);

	boost::thread thread_;
	volatile bool stopFlag_;
};

}; //namespace

#endif
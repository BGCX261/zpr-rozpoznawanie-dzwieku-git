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
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include "neuralNetwork.h"
#include "learningSetReader.h"

namespace learn /// namespace for learning process modules
{

typedef const boost::function<void(float progress, const std::exception* e)>&		progress_callback; /// progress is in %. e == NULL when there is no error.

class Teacher
{
public:
	Teacher(float spectralResolution=5, unsigned short maximumFrequency=4000) : spectralResolution_(spectralResolution), maximumFrequency_(maximumFrequency), abortFlag_(false), learningDone_(false) {}
	
	void doLearn(const std::string& learningSetsFolder, learn::progress_callback progressCallback, const boost::shared_ptr<neur::NeuralNetwork<> >& neuralNetwork); /// starts learning process using given folder with learning sets. Non-blocking (another thread) - raporting learning progress through callback
	bool abortLearning() throw(); /// aborts learning process. Returns true if process was stopped, false if learning was not in progress
	void waitTillLearning() throw() { thread_.join(); } /// will block till learning process is in progress
	bool isLearningDone() const throw() { return learningDone_; } /// returns learning done flag
	bool wasLearningAborted() const throw() { return abortFlag_; } /// returns learning done flag

	void setSpectralResolution(float spectralResolution) throw() { spectralResolution_ = spectralResolution; }; /// sets desired spectral resolution [Hz] for teaching process. Higher resolution needs longer samples and may be less effective
	void setMaximumFrequency(unsigned short maximumFrequency) throw() { maximumFrequency_ = maximumFrequency; }; /// sets high limit of frequency range [Hz] in teaching process. Higher values need samples with higher sample rates and may introduce undesirable disturbance

protected:
	void learningThread(learn::progress_callback progressCallback, const boost::shared_ptr< neur::NeuralNetwork<> > neuralNetwork, const std::string learningSetsFolder, float spectralResolution, unsigned short maximumFrequency); /// function of thread doing learning process

	float			spectralResolution_;	/// desired spectral resolution [Hz] for teaching process. Higher resolution needs longer samples and may be less effective
	unsigned short	maximumFrequency_;		/// high limit of frequency range [Hz] in teaching process. Higher values need samples with higher sample rates and may introduce undesirable disturbance

	boost::thread	thread_;	/// thread in which learning will be done
	volatile bool	abortFlag_;	/// flag to stop learning process
	volatile bool	learningDone_; /// flag indicating if learning ended successfully

	std::auto_ptr<LearningSetReader>	learningSetReader_;
};

}; //namespace

#endif
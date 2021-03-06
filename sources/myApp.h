/** 
* @file
* Declaration of MyApp class - base class for application, controlling learning/classifying process 
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __MY_APP_H__
#define __MY_APP_H__

#include <string>
#include <exception>
#include <boost/thread.hpp>
#include <boost//shared_ptr.hpp>
#include "neuralNetwork.h"
#include "teacher.h"

class MyApp
{
private:
	MyApp(); /// private constructor for a singleton use
	MyApp(const MyApp&); /// private copy constructor for a singleton use
	virtual ~MyApp();

public:
	static MyApp& getInstance() throw() /// get instance to the singleton
	{
		static MyApp instance;
		return instance;
	}

	void doWork(); /// main application logic

	void setLearningSetsFolder(const std::string& learningSetsFolder) throw() { learningSetsFolder_ = learningSetsFolder; } /// sets folder from which to read learning sets
	void setLearningFactor(float learningFactor) throw() { learningFactor_ = learningFactor; }
    void doLearn(learn::progress_callback progressCallback); /// starts learning process using current set folder with learning sets. Non-blocking (another thread) - raporting learning progress through callback
	
    bool abortLearning() throw() { return teacher_.abortLearning(); } /// aborts learning process. Returns true if process was stopped, false if learning was not in progress
	void waitTillAbort() throw(); /// waits till user presses a key to interrupt process
	bool waitTillLearning(); /// blocks until either neural network will be learned (true returned) or user will abort operation (false returned)

	void learnCallback(float progress, const std::exception* e); /// callback for handling progress / error notifies

	std::auto_ptr< neur::ResultSet<std::string> > doCategorizeFile(const std::string& filePath); /// examines sound sample from file with learned neural network
	void doRecognizeAndPresent(const std::string& filePath); /// calls doCategorizeFile and presents results to the user

protected:
	void printProgramHeader() const throw(); /// prints out first lines to the console

	std::string									learningSetsFolder_; /// path to a folder with learning sets
	learn::Teacher								teacher_; /// class controlling learning process
	boost::shared_ptr<neur::NeuralNetwork<> >	neuralNetwork_; /// pointer to learned neural network

	float										learningFactor_; /// learning factor. Has great influence to the learning process

	volatile bool								stopAbortLoop_; /// flag to stop thread waiting for a key input
};

#endif

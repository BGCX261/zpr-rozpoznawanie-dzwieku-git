/** 
* @file
* Implementation of MyApp - base class for application, controlling learning/classifying process 
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "myApp.h"
#include "mygetch.h"
#include "fft.h"

using namespace std;


MyApp::MyApp()
{
	media::FFT::initialize();
	printProgramHeader();
}

MyApp::~MyApp()
{
	neuralNetwork_.reset();
	media::FFT::deinitialize();
#ifdef _WIN32
	cout << endl << endl;
	system("PAUSE");
#endif
}

void MyApp::printProgramHeader() const throw()
{
	cout << "==============================================================================" << endl;
	cout << "| Students project for ZPR classes, 2012L, Warsaw University of Technology   |" << endl;
	cout << "|                                                                            |" << endl;
	cout << "|              Guitar sounds recognition based on its spectrum               |" << endl;
	cout << "|           Classifier induction algorithm based on neural network           |" << endl;
	cout << "|                                                                            |" << endl;
	cout << "| Project tutor: PhD Eng. Rafal Biedrzycki                                   |" << endl;
	cout << "|                                                                            |" << endl;
	cout << "| Authors: Lukasz Rychter, Maciej Sikora                                     |" << endl;
	cout << "==============================================================================" << endl;
}


void MyApp::doLearn(learn::progress_callback progressCallback)
{
	cout << endl
		 << "Starting learning process. Press ESC to abort\n";

	neuralNetwork_ = boost::shared_ptr< neur::NeuralNetwork<> >(new neur::NeuralNetwork<>);
	teacher_.doLearn(learningSetsFolder_, progressCallback, neuralNetwork_);
}


void MyApp::waitTillAbort() throw()
{
	int c;
	do
	{
		c = mygetch();
	}
	while (c != 27 && !stopAbortLoop_); //27 is escape button

	if (!stopAbortLoop_)
	{
		abortLearning();
	
		cout << "Learning process aborted by user" << endl;
	}
}


bool MyApp::waitTillLearning()
{
	stopAbortLoop_ = false;
	boost::thread abortThread(&MyApp::waitTillAbort, this);

	teacher_.waitTillLearning();

	if (teacher_.isLearningDone())
		cout << "Learning process ended successfully." << endl;

	if (!teacher_.wasLearningAborted())
	{
		cout << endl 
			 << "Press any key to continue...";

		stopAbortLoop_ = true;
		abortThread.join();
	}

	return teacher_.isLearningDone();
}


void MyApp::learnCallback(float progress, const std::exception* e)
{
	cout << "Learning progress: " << fixed << setprecision(1) << progress << "%\r";

	if (e)
	{
		cout << endl 
			 << "learnCallback(): Exception occured in learning process - \"" << e->what() << "\"" 
			 << endl;
	}
}


const neur::ResultSet<> MyApp::doCategorizeFile(const string& filePath)
{
	neur::ResultSet<> results;

	return results;
}
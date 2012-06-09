/** 
* @file
* Implementation of MyApp - base class for application, controlling learning/classifying process 
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "myApp.h"
#include "mygetch.h"

using namespace std;


MyApp::MyApp()
{
	printProgramHeader();
}

MyApp::~MyApp()
{
#ifdef _WIN32
	cout << endl << endl;
	system("PAUSE");
#endif
}

void MyApp::printProgramHeader() const throw()
{
	cout << "EiTI, Politechnika Warszawska, ZPR 2012L" << endl;
	cout << endl;
	cout << "Projekt pod kierownictwem dr inz. Rafala Biedrzyckiego:" << endl;
	cout << endl;
	cout << "\tRozpoznawanie dzwiekow gitarowych na podstawie ich widma" << endl;
	cout << "\tAlgorytm indukcji klasyfikatora bazujacy na sieci neuronowej" << endl;
	cout << endl;
	cout << "Autorzy: Lukasz Rychter, Maciej Sikora" << endl;
}


void MyApp::doLearn(learn::progress_callback progressCallback) throw()
{
	cout << endl
		 << "Starting learning process. Press ESC to abort\n";

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
	cout << "Learning progress: " << progress << "%\r";

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
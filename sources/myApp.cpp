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
#include "waveReader.h"

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


void MyApp::doWork()
{
	string learningSetsFolder("sounds/learn");
	float learningFactor = 0.01f;

	int c;
	do
	{
		cout << endl;
		cout << "1. Choose folder from which to read learning sets (current=\"" << learningSetsFolder << "\")" << endl;
		cout << "2. Set learning factor (current=" << fixed << setprecision(3) << learningFactor << ")" << endl;
		cout << "3. Run learning process (press enter)" << endl;
		cout << endl;	

		do
		{
			c = mygetch();
		}
		while (c != '1' && c != '2' && c != '3' && c != 27 && c != 13);

		switch (c)
		{
			case '1':
				cout << "Choose folder from which to read learning sets:" << endl;
				cin >> learningSetsFolder;
				break;
			case '2':
				cout << "Set learning factor: ";
				cin >> learningFactor;
				break;
			case 13: /// enter
			case '3':
				break;
			case 27:
				cout << "Escape pressed - exiting";
				break;
			default:
				cout << "Unknown option" << endl;
		}
	}
	while (c != '3' && c != 13 && c != 27);

	if (c == '3' || c == 13)
	{
		setLearningSetsFolder(learningSetsFolder);
		setLearningFactor(learningFactor);

		doLearn(boost::bind(&MyApp::learnCallback, this, _1, _2));
		waitTillLearning();

		//recognition part
		string fileToRecognize("sounds/verify/A/1.wav");
		do
		{
			cout << endl;
			cout << endl;
			cout << "1. Choose wave file to recognize (current=\"" << fileToRecognize << "\"):" << endl;
			cout << "2. Recognize (press enter)" << endl;
			cout << "3. Exit (press escape)" << endl;
			cout << endl;

			do
			{
				c = mygetch();
			}
			while (c != '1' && c != '2' && c != '3' && c != 27 && c != 13);

			switch (c)
			{
				case '1':
					cout << "Choose wave file to recognize:" << endl;
					cin >> fileToRecognize;
					break;
				case 13: /// enter
				case '2':
					doRecognizeAndPresent(fileToRecognize);
					break;
				case '3':
					cout << "Exiting";
					break;
				case 27:
					cout << "Escape pressed - exiting";
					break;
				default:
					cout << "Unknown option" << endl;
			}
		}
		while (c != '3' && c != 27);
	}
}


void MyApp::doLearn(learn::progress_callback progressCallback)
{
	cout << endl
		 << "Starting learning process. Press ESC to abort\n";

	neuralNetwork_ = boost::shared_ptr< neur::NeuralNetwork<> >(new neur::NeuralNetwork<>(learningFactor_));

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


std::auto_ptr< neur::ResultSet<std::string> > MyApp::doCategorizeFile(const string& filePath)
{
	if (!neuralNetwork_.get())
		throw std::runtime_error("Neural network is not initialized");
	
	media::AudioSample audioSample;
	media::WaveReader fileReader(filePath);
	fileReader.readTo(audioSample);
		
	std::auto_ptr<media::FFTSample> fftSample = media::FFT::getInstance().calculateFFT(audioSample);
	if (!fftSample.get())
		throw std::runtime_error("Calculating FFT failed");
		
	return neuralNetwork_->recognizePattern(fftSample->get());
}


void MyApp::doRecognizeAndPresent(const std::string& filePath)
{
	std::auto_ptr< neur::ResultSet<std::string> > result;
	try
	{
		result = doCategorizeFile(filePath);
		if (!result.get())
			throw std::runtime_error("No results returned");
	}
	catch (std::exception& e)
	{
		cout << endl 
			 << "main(): Exception occured during recognition process - \"" << e.what() << "\"" 
			 << endl;
		return;
	}
	catch(...)
	{
		cout << endl 
			 << "main(): Unknown exception occured during recognition process" 
			 << endl;
		return;
	}

	const std::map<string, float>& resultMap = result->get();
	
	float errorSum = 0;
	for (std::map<string, float>::const_iterator iter=resultMap.begin(); iter!=resultMap.end(); ++iter)
		errorSum += iter->second*iter->second;
	
	for (std::map<string, float>::const_iterator iter=resultMap.begin(); iter!=resultMap.end(); ++iter)
		cout << iter->first << "  ===>  " << fixed << setprecision(1) << iter->second*iter->second*100/errorSum << "%" << endl;
		
	/*for (std::map<string, float>::const_iterator iter=resultMap.begin(); iter!=resultMap.end(); ++iter)
		cout << iter->first << "  ===>  " << fixed << setprecision(1) << iter->second << endl;*/
}
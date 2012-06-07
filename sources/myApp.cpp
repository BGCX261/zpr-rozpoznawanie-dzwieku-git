/** 
* @file
* Implementation of MyApp - base class for application, controlling learning/classifying process 
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "myApp.h"

using namespace std;


MyApp::MyApp()
{
	printProgramHeader();
}

void MyApp::printProgramHeader()
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



void MyApp::doLearn(const std::binary_function<float, const std::exception&, void>& progressCallback) throw()
{
	teacher_.doLearn(learningSetsFolder_, progressCallback, neuralNetwork_);
}


void MyApp::learnCallback(float progress, const std::exception& e)
{

}


const neur::ResultSet<> MyApp::doCategorizeFile(const string& filePath) throw(...)
{
	neur::ResultSet<> results;

	return results;
}
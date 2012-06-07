/** 
* @file
* Implementation of MyApp - base class for application, controlling learning/classifying process 
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "myApp.h"

using namespace std;


void MyApp::doLearn(const binary_function<float, const exception&, bool>& progressCallback) throw()
{
	teacher_.doLearn(learningSetsFolder_, progressCallback, neuralNetwork_);
}



const neur::ResultSet<> MyApp::doCategorizeFile(const string& filePath) throw(...)
{
	neur::ResultSet<> results;

	return results;
}
/** 
* @file
* Students project for "ZPR" classes, 2012L, Warsaw University of Technology
*
* Guitar sounds recognition based on its spectrum \n
* Classifier induction algorithm based on neural network
*
* Project tutor: PhD Eng. Rafal Biedrzycki
*
* Authors: Lukasz Rychter, Maciej Sikora
*/

#include "stdafx.h"
#include <iostream>
#include <boost\bind.hpp>

#include "myApp.h"

using namespace std;

int main()
{
	MyApp& myApp = MyApp::getInstance();
	myApp.setLearningSetsFolder("sounds");
	
	try
	{
		myApp.doLearn(boost::bind(&MyApp::learnCallback, &myApp, _1, _2));
		myApp.waitTillLearning();
	}
	catch (std::exception& e)
	{
		cout << endl 
			 << "main(): Exception occured in learning process - \"" << e.what() << "\"" 
			 << endl;
	}
	catch(...)
	{
			cout << endl 
			 << "main(): Unknown exception occured in learning process" 
			 << endl;
	}

	return 0;
}

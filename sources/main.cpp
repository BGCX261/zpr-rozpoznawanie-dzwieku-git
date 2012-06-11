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
#include <boost/bind.hpp>

#include "myApp.h"

using namespace std;

int main()
{
	MyApp& myApp = MyApp::getInstance();

	try
	{
        myApp.doWork();
	}
	catch (std::exception& e)
	{
		cout << endl 
			 << "main(): Exception occured - \"" << e.what() << "\"" 
			 << endl;
	}
	catch(...)
	{
			cout << endl 
			 << "main(): Unknown exception occured" 
			 << endl;
	}

	return 0;
}

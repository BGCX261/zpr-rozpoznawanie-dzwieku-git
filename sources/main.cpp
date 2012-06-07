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

#include "myApp.h"

using namespace std;

int main()
{
	MyApp& myApp = MyApp::getInstance();
	myApp.setLearningSetsFolder("sounds");

	cout << "EiTI, Politechnika Warszawska, ZPR 2012L" << endl;
	cout << endl;
	cout << "Projekt pod kierownictwem dr inz. Rafala Biedrzyckiego:" << endl;
	cout << endl;
	cout << "\tRozpoznawanie dzwiekow gitarowych na podstawie ich widma" << endl;
	cout << "\tAlgorytm indukcji klasyfikatora bazujacy na sieci neuronowej" << endl;
	cout << endl;
	cout << "Autorzy: Lukasz Rychter, Maciej Sikora" << endl;

#ifdef _WIN32
	cout << endl << endl;
	system("PAUSE");
#endif

	return 0;
}

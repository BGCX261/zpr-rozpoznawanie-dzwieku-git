/** 
* @file
* Projekt ZPR 2012L, Politechnika Warszawska
*
* Rozpoznawanie dzwiekow gitarowych na podstawie ich widma \n
* Algorytm indukcji klasyfikatora bazujacy na sieci neuronowej
*
* Prowadzacy: dr inz. Rafal Biedrzycki
*
* Autorzy: Lukasz Rychter, Maciej Sikora
*/

#include "stdafx.h"

using namespace std;


int main()
{
#ifdef _WIN32
	locale oldloc;
	try
	{
		locale myloc("Polish");
		oldloc = locale::global(myloc);
	}
	catch(...) {}
#endif

	cout << endl;
	cout << "Projekt ZPR pod kierownictwem dr inż. Rafała Biedrzyckiego:" << endl;
	cout << "\"Zaimplementować algorytm indukcji klasyfikatora bazujący na sieci neuronowej\"" << endl;
	cout << endl;
	cout << "Autorzy: Łukasz Rychter, Maciej Sikora" << endl;
	cout << endl;
	
#ifdef _WIN32
	locale::global(oldloc);

	system("PAUSE");
#endif

	return 0;
}

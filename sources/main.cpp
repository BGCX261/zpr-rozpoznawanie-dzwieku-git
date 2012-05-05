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

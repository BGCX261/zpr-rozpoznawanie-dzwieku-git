#include "stdafx.h"

using namespace std;

int main()
{
	locale myloc ("Polish");
	locale oldloc = locale::global(myloc);

	cout << "Projekt ZPR pod kierownictwem dr in�. Rafa�a Biedrzyckiego:" << endl;
	cout << "\"Zaimplementowa� algorytm indukcji klasyfikatora bazuj�cy na sieci neuronowej\"" << endl;
	cout << endl;
	cout << "Autorzy: �ukasz Rychter, Maciej Sikora" << endl;
	cout << endl;
	
	locale::global (oldloc);

	system("PAUSE");

	return 0;
}
/**
* @file
* File containing multiplatform implementation of mygetch function \n
* It is multiplatform implementation of asynchrously getting char from console, without echoing it
*/

/// Lukasz Rychter
/// Maciej Sikora

#ifndef __MY_GETCH_H__
#define __MY_GETCH_H__

#ifdef _WIN32

#include <conio.h>

int mygetch()
{
	return _getch();
}

#else

#include <termios.h>
#include <unistd.h>

int mygetch()
{
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}

#endif //_WIN32

#endif //__MY_GETCH_H__ 
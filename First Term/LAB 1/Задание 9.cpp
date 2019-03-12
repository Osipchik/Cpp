#include <iostream.h>
#include <locale.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int G;
	char sign;

	cout << "Year - 2018\n";

	cout << "G=";
	cin >> G;

	G = 2018 - G;

	cout << G;

	G = G % 10;

	switch (G)
	{
	   case 0: cout << "\tлет\n";
		  break;
	   case 1: cout << "\tгод\n";
		   break;
	   case 2:
	   case 3:
	   case 4: cout << "\tгода\n";
		   break;
	   case 5:
	   case 6:
	   case 7:
	   case 8:
	   case 9: cout << "\tлет\n";
		   break;
	}
	getch();
}


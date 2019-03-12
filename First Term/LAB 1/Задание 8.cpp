#include <iostream.h>
#include <math.h>
#include <locale.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int N, k, ost;

	cout << "N < 20" << '\n';
	cout << "\nN=";
	cin >> N;

	cout << "\nk<80" << '\n';
	cout << "\nk=";
	cin >> k;

	N = N + k;
	ost=N % 10;

	'\n';

	switch (ost)
	{
	 case 0: cout << '\n' << N << "\tрублей" << '\n';
		break;
	 case 1: cout << '\n' << N << "\tрубль" << '\n';
		 break;
	 case 2:
	 case 3:
	 case 4: cout << '\n' << N << "\tрубля" << '\n';
		 break;
	 case 5:
	 case 6:
	 case 7:
	 case 8:
	 case 9: cout << '\n' << N << "\tрублей" << '\n';
		 break;
	}
	getch();
}


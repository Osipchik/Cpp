#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int DEC(int n6);
char* FIF(int n10, int n6);
void FIF_no_arr(int n10, int n6);

int main()
{
	setlocale(LC_ALL, "ru");
	int n6;
	cin >> n6;

	char* n15 = FIF(DEC(n6), n6);
	cout << " С массивом: " << n15;
	delete[] n15;

	cout << "\n Без массива: ";
	FIF_no_arr(DEC(n6), n6);
}

int DEC(int n6)
{
	int n10 = 0, a, n = 0;

	a = n6;
	while (a > 0)
	{
		n++;
		a = n6 / pow(10, n);
	}
	for (int b = 0, j = n - 1; j >= 0; j--)
	{
		a = n6 / pow(10, j);
		n10 += (a - b) * pow(6, j);
		b = a * 10;
	}
	return n10;
}

char* FIF(int n10, int n6)
{
	int a = n6, n = 0;

	while (a > 0)
	{
		n++;
		a = n6 / pow(10, n);
	}

	char *n15 = new char[n + 1];

	for (int i = 0; n10 > 0; i++)
	{
		if (n10 % 15 > 9)
		{
			n15[i] = n10 % 15 + 'A' - 10;
			n10 /= 15;
			n15[i + 1] = '\0';
			continue;
		}
		n15[i] = n10 % 15 + '0';
		n10 /= 15;
		n15[i + 1] = '\0';
	}
	//n15[n] = '\0';

	_strrev(n15);

	return n15;
}

void FIF_no_arr(int n10, int n6)
{
	int n = 0;
	while (n6 > 0)
	{
		n++;
		n6 /= pow(10, n);
	}

	long int n15 = 0;

	for (int i = 0; n10 > 0; i++)
	{
		if (n10 % 15 > 9)
		{
			n15 = n15 * 100 + (n10 % 15 + 65 - 10);
			n10 /= 15;
			continue;
		}
		n15 = n15 * 100 + (n10 % 15 + 48);
		n10 /= 15;
	}

	for (int i = 0; n15 > 0; i++)
	{
		if (n15 % 100 > 9)
		{
			cout << char(n15 % 100);
			n15 /= 100;
			continue;
		}
		cout << char(n15 % 100);
		n15 /= 100;
	}
}
#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int a;
	double A = 1.0010000;

	if (int(A) != 0) a = A * pow(10, 7) - 1;
	else a = A * pow(10, 7);

	int *dop = new int[8];
	for (int i = 7; i > -1; i--, a /= 10)
	{
		if (a % 10 >= 1) dop[i] = 1;
		else dop[i] = 0;
	}
	for (int i = 0; i < 8; i++)
		cout << dop[i];

	delete[] dop;
	return 0;
}
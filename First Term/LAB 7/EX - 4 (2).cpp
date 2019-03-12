#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void sum(string A, string B);
string FIF(int n10);

int main()
{
	int n10A = 43, n10B = 100;

	sum(FIF(n10A), FIF(n10B));

	system("pause");
	return 0;
}

void sum(string A, string B)
{
	//reverse(A.begin(), A.end());
	//reverse(B.begin(), B.end());

	int size;
	if (A.size() < B.size()) size = B.size() + 1;
	else size = A.size() + 1;

	//string *summa = new string[size];
	string summa = "";
	int n = size, s = size - 1;

	for (int i = 0, a = 0; i < s; i++)
	{
		if (A[i] > 64 && B[i] > 64)                                                          /// оба - буквы
			a = A[i] + B[i] - 110 + a;
		else if (A[i] > 47 && A[i] < 58 && B[i] > 47 && B[i] < 58)                           /// оба - цифры
			a = A[i] + B[i] - 96 + a;
		else if (A[i] > 47 && A[i] < 58 && B[i] > 64 || B[i] > 47 && B[i] < 58 && A[i] > 64) /// один - цифра, другой буква
			a = A[i] + B[i] - 103 + a;
		else if (A[i] > 47 && A[i] < 58 || B[i] > 47 && B[i] < 58)                           /// один - цифра, одного нет
			a = A[i] + B[i] - 48 + a;
		else if (A[i] > 64 || B[i] > 64)                                                     /// один - буква, одного нет
			a = A[i] + B[i] - 'A' - 10 + a;
		cout << a << endl;
		if (a < 10)
			summa += a + '0';
		else if (a > 9 && a < 15)
			summa += a + 'A' - 10;

		if (a > 14)
		{
			summa += a / 15 + 48;

			if (a % 15 > 9)
			{
				summa += a % 15 + 'A' - 10;
				continue;
			}

			else if (a % 15 < 10)
			{
				summa += a % 15 + '0';
				continue;
			}

			if (A[i + 1] > 47 || B[i + 1] > 47)
				a = a / 15;
			else a = 0;
		}
		//a = 0;
		//cout << " a = " << a << '\t' << a%15 << "\t summa = " << summa << endl;
	}

	reverse(summa.begin(), summa.end());
	cout << summa << endl;
}

string FIF(int n10)
{
	string n15;

	for (int i = 0; n10 > 0; i++)
	{
		if (n10 % 15 > 9)
		{
			n15 += n10 % 15 + 'A' - 10;
			n10 /= 15;
			continue;
		}
		n15 += n10 % 15 + '0';
		n10 /= 15;
	}
	return n15;
}

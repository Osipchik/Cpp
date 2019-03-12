#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void sum(string A, string B);

int main()
{
	string A = "A2B", B = "11";
	sum(A, B);
	//system("pause");
	return 0;
}

void sum(string A, string B)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int size;
	if (A.size() < B.size()) size = B.size() + 1;
	else size = A.size() + 1;

	string sum = "";
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
			a = A[i] + B[i] - 55 + a;
		/*cout << a << endl;*/
		if (a < 10)
			sum += a + '0';
		else if (a > 9 && a < 15)
			sum += a + 'A' - 10;

		if (a > 14)
		{
			sum += a / 15 + 48;

			if (a % 15 > 9)
			{
				sum += a % 15 + 'A' - 10;
				continue;
			}
			else if (a % 15 < 10)
			{
				sum += a % 15 + '0';
				continue;
			}

			if (A[i + 1] > 47 || B[i + 1] > 47)
				a = a / 15;
			else a = 0;
		}
		a = 0;
	}

	reverse(sum.begin(), sum.end());
	cout << sum << endl;
}
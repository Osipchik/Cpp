#include "pch.h"
#include <iostream>


using namespace std;

int* sum(double A, double B); //!!!
int* pr(int* sum); //!!!
void solve(double A, double B);
void solve_raz(double A, double B);
int* raz(double A, double B);

int main()
{
	double A = 0.0001011, B = 0.1010010;

	if (int(A) == 1 && int(B) == 0) solve_raz(A, B);
	else if (int(A) == 0 && int(B) == 1) solve_raz(B, A);
	else if (int(A) == int(B)) solve(A, B);

	system("pause");
	return 0;
}

int* sum(double A, double B)
{
	int	rez = (A + B) * 10000000;
	//cout << rez << endl;
	int *sum = new int[8];
	for (int i = 7; i > -1; rez /= 10, i--)
		sum[i] = rez % 10;

	for (int i = 7; i > -1; i--)
	{
		if (sum[i] > 1)
		{
			if (i == 0) break;
			sum[i] -= 2;
			sum[i - 1] += 1;
		}
		if (sum[0] >= 1) sum[0] = 1;
	}

	return sum;
}

int* pr(int* sum)
{
	int a = 0;
	for (int i = 0; i < 8; i++)
	{
		a = a * 10 + sum[i];
	}
	if (sum[0] == 0)  return sum;

	a = a - 1;

	int *pr = new int[8];
	for (int i = 7; i > -1; a /= 10, i--)
		pr[i] = a % 10;

	for (int i = 1; i < 8; i++)
	{
		if (pr[i] == 1)
		{
			pr[i] = 0;
			continue;
		}
		if (pr[i] == 0.)
		{
			pr[i] = 1;
			continue;
		}
	}
	return pr;
}

void solve(double A, double B)
{
	cout << " sum = ";
	int *len = sum(A, B);
	int *len2 = pr(len);
	for (int i = 0; i < 8; i++)
		cout << len[i];
	cout << endl;

	delete[] len;
	delete[] len2;
}

int* raz(double A, double B)
{
	int	rez = (A - B) * 10000000;
	int *raz = new int[8];
	for (int i = 7; i > -1; rez /= 10, i--)
	{
		if (rez % 10 == 1 || rez % 10 == 9) raz[i] = 1;
		else raz[i] = 0;
	}

	return raz;
}

void solve_raz(double A, double B)
{
	cout << " raz = ";
	int *ln = raz(A, B);
	int *len = pr(ln);
	for (int i = 0; i < 8; i++)
		cout << len[i];
	cout << endl;

	delete[] ln;
	delete[] len;
}
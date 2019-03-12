//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

//using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double t1, t2, x1, x2, a, b, c;
	char sign;

	cout << "a=";
	cin >> a;

	cout << "\nb=";
	cin >> b;

	cout << "\nc=";
	cin >> c;


	double D = pow(b, 2) - 4 * a * c;


	if (D >= 0)
	{
		t1 = ((-1) * b - sqrt(D)) / (2*a);

		if (t1 >= 0) x1 = sqrt(t1);

		t2 = ((-1) * b + sqrt(D)) / (2*a);

		if (t2>= 0) x2 = sqrt(t2);
	}
        else
	{
		cout << "\nНет корней",

		cout << "\n чтобы повторить ввод нажмите Y",
		cin >> sign;
		if (sign == 'y') restart ;
	}

	if (x1 == x2) cout << "x1=" << x1, exit(0);

	cout << "\nx1=+-" << x1<<'\n';
	cout << "x2=+-" << x2;

	getch ();
}
//---------------------------------------------------------------------------

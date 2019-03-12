//---------------------------------------------------------------------------

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <iostream.h>
#include <cmath.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{

	float k, L, x1, x2;
	double m;

	cout << "x1=";
	cin >> x1;

	cout << "\nx2=";
	cin >> x2;

	cout << "\nm=";
	cin >> m;

	k = pow(cos(pow(x1, 2)), 3) + pow(sin(pow(x2, 3)), 2);
	cout << "\nk=" << k;

	if (k < 1) L = pow(k, 3) + pow(m, 0.2);
	else if (k >= 1)  L = pow(k, 2) + exp(m);

	cout << "\nL=" << L;

	getch ();
	return 0;
}
//---------------------------------------------------------------------------

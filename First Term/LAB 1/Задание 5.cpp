//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	float a, b, c, d, z;

	cout << "a=";
	cin >> a;

	cout << "\nb=";
	cin >> b;

	cout << "\nc=";
	cin >> c;

	cout << "\nd=";
	cin >> d;

	if (c >= d && a < d) z = a + b / c;
	else if (c < d&&a >= d) z = a - d / c;
	else z = 0;

	cout << "\nz=" << z;

	getch ();
	return 0;
}
//---------------------------------------------------------------------------

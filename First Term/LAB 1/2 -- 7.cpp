//---------------------------------------------------------------------------

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

int _tmain()
{
	float s, x, y, b;

	cout << "x=";
	cin >> x;

	cout << "\nb=";
	cin >> b;

	cout << "\ny=";
	cin >> y;

	if (x*b > 1 && x*b < 10) s = exp(-x);
	 else if (x*b > 12 && x*b < 40) s = pow (x, 1/3);
	 else s = y * pow(x, 2);

	 cout << "s=" << s;

	getch ();
	return 0;
}
//---------------------------------------------------------------------------

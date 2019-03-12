//---------------------------------------------------------------------------

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>

int _tmain()
{
	float Y, a, b, c;
	int N;

	cout << "a=";
	cin >> a;

	cout << "\nb=";
	cin >> b;

	cout << "\nc=";
	cin >> c;

	cout << "\nN=";
	cin >> N;

	switch (N)
	{
	case 2: Y = b * c - pow(a, 2);
		break;
	case 56: Y = b * c;
		break;
	case 7: Y = pow(a, 2) + c;
		break;
	case 3: Y = a - b * c;
		break;
	default: Y = pow(a + b, 3);
		break;
	}

	cout << "\nY=" << Y<<'\n';

	getch ();
	return 0;
}
//---------------------------------------------------------------------------

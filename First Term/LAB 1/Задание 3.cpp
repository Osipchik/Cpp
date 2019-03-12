//---------------------------------------------------------------------------

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <iostream.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int a, b, z;

	cout << "a=";
	cin >> a;

	cout << "\nb=";
	cin >> b;

	bool max = a>b;

	max == 1 ? z = a: z = b;

	cout << "\nz=" <<z << '\n';

	getch ();
	return 0;
}
//---------------------------------------------------------------------------

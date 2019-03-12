
#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int k, s, f, M = 0;
	float K, y;

	cout << "k=";
	cin >> k;
	K = k;

	f = k % 10;

	while ( k >= 10)
	 {
		k = k / 10;
	 }

	M = k + f;
	cout << "\nM=" << M << endl;

	switch (M)
	{
		case 3:
		case 5: y = pow(tan(K), 2) + pow(sin(K), 2)/2.7; break;
		case 7:
		case 8:
		case 9: y =  log(fabs(K - 6)); break;
		case 10: y = exp (0.2*K); break;
		default: y = k * pow(sin(K),2); break;
	}

	cout << "\ny=" << y;
	getch ();
	return 0;
}
//---------------------------------------------------------------------------

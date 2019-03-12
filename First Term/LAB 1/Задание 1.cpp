
#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

int _tmain()
{
	int x, y;
	float a, b, c;

	cout << "x=";
	cin >> x;

	cout << "\ny=";
	cin >> y;

	if (x < y) x = 0, cout << "\nx=" << x<< '\n';
	else if (x > y) y = 0, cout<<"\ny=" << y << '\n';
	else if (x == y) y = 0 , x = 0, cout << "\nx=" << x << "y=" << y << '\n';


	cout << "a=";
	cin >> a;

	cout << "\nb=";
	cin >> b;

	cout << "\nc=";
	cin >> c;


	if (a > b && a > c) a = a - (0.3), cout << "\na=" << a << '\n';
	else if (b > a && b > c) b = b - (0.3), cout << "\nb=" << b << '\n';
	else if (c> a && c > b) c = c - (0.3), cout << "\nc=" << c << '\n';

	getch();
}

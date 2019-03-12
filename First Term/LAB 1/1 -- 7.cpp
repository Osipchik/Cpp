
#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <tchar.h>

int _tmain()
{
  int f;
  float z, c, d;
  double x, y;

  cout << "d=";
  cin >> d;

  cout << "\nc=";
  cin >> c;

  cout << "\nz=";
  cin >> z;


  x = z >= 0 ? pow(z, 3) : pow(z, 2) - z;

  cout << "\nx=" << x << "\nChoose f(x), input 1, 2 or 3" << '\n';

  cin >> f;

  while (f != 1 && f != 2 && f != 3)
      {
        cout << "\nx=" << x << "\nChoose f(x), input 1, 2 or 3" << '\n';

        cin >> f;
      }

  switch (f)
  {
	case 1: f = 2 * x; break;
	case 2: f = pow(x, 2); break;
	case 3: f = x / 3; break;
	default: cout << "\ninput number"; getch (); exit(1);
  }

  cout << "f(x)=" << x;

  y = pow(sin(c*f + pow(d, 2) + pow(x, 2)), 3);

  cout << "\nY=" << y;

  getch ();
}

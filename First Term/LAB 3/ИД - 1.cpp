
#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <cmath>

int main()
{
   int n, xn, j = 1, fact = 1;
   float x;
   double y, s = 1.;

   //cout << " enter number of row members\n";
   //cin >> n;

   cout << " input xn \n";
   cin >> xn;
   n = xn;
   for (int i = 0 ; i != n*2; i++)
   {
   	fact = fact * (n*2 - i);
   }

   while (j <= xn)
   {
    cout << "\n (0.1 < x < 1) \n input x";
    cout << "\n x" << j << " = ";
    cin >> x;

    if (x <= 0.1 || x >= 1) continue;

    y = ((exp(x) + exp((-1)*x)) / 2);
    s += (pow(x, 2 * n) / fact);

    cout << "\n S(x"<<j<<") = " <<s<< "\n Y(x" <<j<< ") = " << y << endl;//" fact = " << fact << endl;

    j++;
   }
   getch();
   return 0;
}

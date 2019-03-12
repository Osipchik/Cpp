
#include <tchar.h>
#include <iostream.h>
#include <cmath>
#include <conio.h>

int main()
{
   float n, h, f, x = 2, R = 100, r;

   cout << " input number of parts n = ";
   cin >> n;

   h = 2 / n;

   do
   {
     f = abs(log(x) + 3 * tan(x) + sqrt(x));

     if (R > f)
     {
       R = f;
       r = x;
     }

   x += h;

   } while (x <= 4);

   cout << "\n root = " << r;

   getch();
   return 0;
}


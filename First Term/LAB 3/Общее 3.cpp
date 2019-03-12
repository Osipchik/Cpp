
#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

int main()
{
   int M = 20, A = 0;
   float X, H, B, y;

   B = M_PI/2;
   H = (B - A)/M;

   cout << " |        X           |          Y          |\n";
   cout << " |--------------------|---------------------|\n";

   for (int i = 0; X <= B; X = A + i * H, i++)
    {
      y = sin(X) - cos(X);
      printf(" |     %f       |      %f      |\n", X, y);
    }
   getch ();
   return 0;
}

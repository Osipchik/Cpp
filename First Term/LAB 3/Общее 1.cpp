
#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

int main()
{
   int i = 1, b;
   float a, N = 0;

   while (i < 31)
       {
         a = i % 2 == 0 ? a = i/2 : i;
         b = i % 2 == 0 ? b = powl(i, 3) : i*i;
         N = N + powl ((a-b), 2);
         i++;
       }

    cout << "\nN = " << N;

   getch();
   return 0;
}

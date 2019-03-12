
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include "matrix.h"

int _tmain(int argc, _TCHAR* argv[])
{
   int n, m;
   cout << "input size: rows, cols - ";
   cin >> n >> m;


   int **arr = CreateMatrix(n, m);
   int **Arr = CreateMatrix(n, m);

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         arr[i][j] = 3 * i*j - 3;
         cout << arr[i][j] << '\t';
      }
      cout << endl;
   }
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         arr[i][j] = 2 * i*j - 2;
         cout << arr[i][j] << '\t';
      }
      cout << endl;
   }

   FreeMatrix(arr, n);
   FreeMatrix(Arr, n);

   getch();
   return 0;
}


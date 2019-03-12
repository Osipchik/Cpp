
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <ctime>
#include <iomanip>

int foo1(int *array);
int foo2(int *array);

int j = 0, lim;

int main()
{
   srand(time(NULL));
   int n;
   cout << " input n - ";
   cin >> n;
   cout << endl;
   lim = n;
   int *arrA = new int[n];

   for (int i = 0; i < n; i++)
   {
      arrA[i] = rand() % 20 - rand() % 20;
      cout << arrA[i] << '\t';
   }
   cout << endl << endl;

   *arrA = foo1(arrA);
   *arrA = foo2(arrA);

   delete[] arrA;

   getch();
   return 0;
}

int foo1(int *array)
{
   if (j == (lim/2)) return 0;

   if ((-10) < powl(array[j], 3) && powl(array[j], 3) < 20) cout << setw(2) << "yes - " << array[j] << endl;
   else cout << setw(2) << "no - " << array[j] << endl;

   j++;
   return foo1(array);
}

int foo2(int *array)
{
   if (j == lim) return 0;

   if (((-10) < powl(array[j], 3)) && powl(array[j], 3) < 20) cout << setw(2) << "yes - " << array[j] << endl;
   else cout << setw(2) << "no - " << array[j] << endl;

   j++;
   return foo2(array);
}

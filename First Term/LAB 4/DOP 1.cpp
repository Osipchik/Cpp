
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <ctime>

int main()
{
   int size = 4, f = 0;
   srand(time(NULL));
   cout << " input size of matrix - ";
   cin >> size;
   cout << endl;

   int **pa = new int *[size];
   for (int i = 0; i < size; i++)
   	pa[i] = new int[2];

   int **arr = new int *[size];
   for (int i = 0; i < size; i++)
   	arr[i] = new int[size];

   for (int i = 0; i < size; i++)
   	for (int j = 0; j < size; j++)
   		arr[i][j] = rand() % 20;

   for (int i = 0; i < size; i++)
   {
   	for (int j = 0; j < size; j++)
   	cout << arr[i][j] << '\t';
   	cout << endl;
   }

   for (int i = 0, p; i < size; i++)
   {
   	p = 0;
   	for (int j = 0; j < size; j++)
             for (int t = j + 1; t < size; t++)
	     	if (arr[i][j] == arr[i][t]) p += 2;

	pa[i][0] = i;
        pa[i][1] = p;
    }

    int min = 1000;

    for (int i = 0; i < size; i++)
    {
       if (pa[i][1] < min && pa[i][1] != 0)
       {
           min = pa[i][1];
    	   f = i;
       }
    }

    cout << "\n min = " << min << "\t f = " << f;

    cout << "\n arr(min) : ";
    for (int j = 0; j < size; j++)
    	cout << arr[f][j] << '\t';

    for (int i = 0; i < size; i++)
    	delete[] arr[i];
    delete[] arr;
    for (int i = 0; i < size; i++)
    	delete[] pa[i];
    delete[] pa;
    getch();
    return 0;
}

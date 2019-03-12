
#include <tchar.h>
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int n, y = 0;
    cin >> n;
    srand(time(NULL));

    int **A = new int *[n];
    for (int i = 0; i < n; i++)
    	A[i] = new int[n];

    int **arr2 = new int *[n];
    for (int i = 0; i < n; i++)
    	arr2[i] = new int[n];

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    	{
    	    A[i][j] = rand() % 10 - rand() % 10;
	    arr2[i][j] = 999;
	}

    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < n; j++)
    	cout << A[i][j] << '\t';
    	cout << endl;
    }
    cout << "\n======================================================\n\n";
    for (int i = 0, x = 0; i < n; i++, x = 0)
    {
    	for (int j = 0; j < n; j++)
            for (int t = j + 1; t < n; t++)
    	    	if (A[i][j] == A[i][t]) x++;
	if (x != 0) y++;
    }

    int **B = new int *[y];

    for (int i = 0, x = 0, rows = 0; i < n; i++, x = 0)
    {
    	for (int j = 0; j < n; j++)
    	{
    	    for (int t = j + 1; t < n; t++)
	    	if (A[i][j] == A[i][t])
	    	{
		   arr2[i][j] = A[i][j];
		   arr2[i][t] = A[i][t];
		}
		if (arr2[i][j] != 999) x++;
	}
	if (x != 0)
	{
	   B[rows] = new int[x];
	   for (int j = 0, k = 0; j < n; j++)
	       if (arr2[i][j] != 999)
	       {
		  B[rows][k] = arr2[i][j];
		  cout << B[rows][k] << '\t';
		  k++;
	       }
	   rows++;
	   cout << endl;
	 }
   }
   for (int i = 0; i < n; i++)
   	delete[] A[i];
   delete[] A;

   for (int i = 0; i < n; i++)
   	delete[] arr2[i];
   delete[] arr2;

   for (int i = 0; i < y; i++)
   	delete[] B[i];
   delete[] B;
   getch();
   return 0;
}

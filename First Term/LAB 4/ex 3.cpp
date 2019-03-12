
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <cmath>
#include <ctime>

int main()
{
    int size, n, c = 2;
    srand(time(NULL));
    cout << " input size of matrix - ";
    cin >> size;
    cout << "\n input degree of matrix - ";
    cin >> n;

    float **arr = new float *[size];
    for (int i = 0; i < size; i++)
	arr[i] = new float[size];

    float **arry = new float *[size];
    for (int i = 0; i < size; i++)
    	arry[i] = new float[size];

    float **ARR = new float *[size];
    for (int i = 0; i < size; i++)
    	ARR[i] = new float[size];

    for (int i = 0; i < size; i++)
    	for (int j = 0; j < size; j++)
	    arr[i][j] = (rand() % 999) / 100.0;

    for (int i = 0; i < size; i++)
    {
    	if (n == 1) break;
    	for (int j = 0; j < size; j++)
        {
	    ARR[i][j] = 0;
	    for (int f = 0; f < size; f++)
	    ARR[i][j] += arr[i][f] * arr[f][j];
	}
    }

    do
    {
       if (n == 1 || n == 2) break;
       for (int i = 0; i < size; i++)
      	  for (int j = 0; j < size; j++)
	  {
	     arry[i][j] = 0;
	     for (int f = 0; f < size; f++)
	     arry[i][j] += ARR[i][f] * arr[f][j];
          }
       for (int i = 0; i < size; i++)
          for (int j = 0; j < size; j++)
             for (int f = 0; f < size; f++)
		  ARR[i][j] = arry[i][j];

       c++;
     } while (c != n);
     cout << endl;
     for (int i = 0; i < size; i++)
     {
     	for (int j = 0; j < size; j++)
     	cout << arr[i][j] << '\t';
     	cout << endl;
     }
     cout << endl;
     for (int i = 0; i < size; i++)
     {
     	for (int j = 0; j < size; j++)
            if (n == 1) cout << arr[i][j] << '\t';
     	    else cout << ARR[i][j] << '\t';
	cout << endl;
     }

     for (int i = 0; i < size; i++)
     	delete[] arr[i];
     delete[] arr;

     for (int i = 0; i < size; i++)
     	delete[] ARR[i];
     delete[] ARR;

     for (int i = 0; i < size; i++)
     	delete[] arry[i];
     delete[] arry;
     getch();
     return 0;
}

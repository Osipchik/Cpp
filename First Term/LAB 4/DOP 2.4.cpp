
#include <tchar.h>
#include <conio.h>
#include <iostream.H>

int main()
{
    int rows, cols;
    cout <<" inpun size of matrix \n rows -";
    cin >> rows;
    cout <<"\n cols - ";
    cin >>cols;

    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++) arr[i] = new int[cols];

    int **array = new int *[rows];
    for (int i = 0; i < rows; i++) array[i] = new int[cols];
    for (int i = 0, n; i < rows; i++)
    	for (int j = 0; j < cols; j++)
    	    arr[i][j] = rand()%20;

    for (int i = 0; i < rows; i++)
    {
    	for (int j = 0; j < cols; j++) cout << arr[i][j] << '\t';
    	    cout << endl;
    }


    int **mass = new int *[rows];
    for (int i = 0; i < cols; i++) mass[i] = new int[cols];

    for (int i = 1, t = 1; i < rows; i++)
    {
    	for (int j = cols - t; j < cols; j++)
	{
	    if (cols - t == 0) break;
	    mass[i][j] = arr[i][j];
	}
	t++;
    }

    int x = 0, I, J, f = 0, s = -1, t = 0, tut, utu, rez;

    while  (true)
    {
    	int min = 21;
    	for (int i = 0, lim = 0; i < rows; i++, lim++)
    	{
    	    for (int j = 0; j < cols - lim; j++)
	    {
	    	if (arr[i][j] < min)
	    	{
                    min = arr[i][j];
		    I = i;
		    J = j;
		}
	    }
	}
        x++;
	s++;

	if (s == cols - t)
	{
	    s = 0;
            f++;
	    t++;
	}
	if (f == rows) break;

	mass[f][s] = arr[I][J];
	arr[I][J] = 21;
    }

    cout << "\n x = " << x << endl;

    for (int i = 0; i < rows; i++)
    {
    	for (int j = 0; j < cols; j++) cout << arr[i][j] << '\t';
	    cout << endl;
    }

    cout << "\n ----------------------------------------------------------\n";

    for (int i = 0; i < rows; i++)
    {
    	for (int j = 0; j < cols; j++) cout << mass[i][j] << '\t';
	cout << endl;
    }

    for (int i = 0; i < rows; i++) delete[] arr[i];
    delete[] arr;

    for (int i = 0; i < rows; i++) delete[] mass[i];
    delete[] mass;
    getch();
    return 0;
}

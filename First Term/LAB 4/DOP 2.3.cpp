
#include <tchar.h>
#include <conio.h>
#include <iostream.h>

int main()
{
    int size, n = 1;

    cout << " input size of matrix - ";
    cin >> size;
    int **arr = new int *[size];
    for (int i = 0; i < size; i++)
    	arr[i] = new int[size];
    cout << endl;

    for (int t = 0; t != (size - 1); t++)
    {
    	for (int j = (0 + t); j < (size - t); j++, n++)
	    arr[0 + t][j] = n;

        for (int i = (1 + t); i < (size - t); i++, n++)
       	    arr[i][size - 1 - t] = n;

	for (int j = (size - 2 - t); j >= (0 + t); j--, n++)
	    arr[size - 1 - t][j] = n;

	for (int i = (size - 2 - t); i >= (1 + t); i--, n++)
	    arr[i][0 + t] = n;
    }

    for (int i = 0; i < size; i++)
    {
    	for (int j = 0; j < size; j++)
        {
	    cout << arr[i][j] << '\t';
	}
	cout << endl;
    }

    for (int i = 0; i < size; i++)
    	delete[] arr[i];
    delete[] arr;
    getch();
    return 0;
}

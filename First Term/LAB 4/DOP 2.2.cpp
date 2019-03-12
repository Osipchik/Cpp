
#include <tchar.h>
#include <conio.h>
#include <iostream.h>

int main()
{
    int size, M;
    cout << " input size - ";
    cin >> size;

    M = (size * (size * size + 1)) / 2;

    int **kv = new int *[size];
    for (int i = 0; i < size; i++)
    	kv[i] = new int[size];

    for (int i = 0; i < size; i++)
    	for (int j = 0; j < size; j++)
    	    kv[i][j] = (1 + ((i + j + 1 + ((size - 1) / 2)) % size)*size + ((i + (j + 1) * 2 + 3) % size));


    for (int i = 0; i < size; i++)
    {
    	for (int j = 0; j < size; j++)
	    cout << kv[i][j] << '\t';
        cout << endl;
    }

    cout << endl << M;
    for (int i = 0; i < size; i++)
    	delete[] kv[i];
    delete[] kv;
    getch();
    return 0;
}


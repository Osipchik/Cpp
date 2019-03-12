
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <ctime>

int main()
{
    srand(time(NULL));
    const int ROWS = 4, COLS = 5;
    int arr[ROWS][COLS];
    int s = 0;

    for (int i = 0, num; i < ROWS; i++)
    {
    	//cout << "\n input number - ";
    	for (int j = 0; j < COLS; j++)
        {
    	     //cin >> num;
    	     //arr[i][i] = num;
	     arr[i][j] = rand() % 30 - rand() % 30;
	     cout << arr[i][j] << '\t';
	}
	cout << endl;
    }

    for (int i = 0; i < ROWS; i++)
    {
     	for (int j = i + 1; j < COLS; j++)
     	{
            if (arr[i][j] < 0)
     	    {
                cout << "\n a[" << i << "][" << j << "]" << arr[i][j] << endl;
		s++;
	    }
	}
    }
    cout << "\n number of negative numbers - " << s;
    getch();
    return 0;
}

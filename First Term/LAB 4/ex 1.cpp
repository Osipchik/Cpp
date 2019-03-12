
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <cmath>
int main()
{
    const int N = 6;
    int a[N], b[N];

    for (int i = 0; i < N; i++)
    {
	cout << " input a[" << i << "] = ";
	cin >> a[i];
    }

    cout << endl;

    for (int i = 0; i < N; i++)
    {
	b[i] = a[N - 1 - i];
	cout << b[i] << endl;
    }
    getch();
    return 0;
}


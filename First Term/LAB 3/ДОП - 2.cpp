
#include <tchar.h>
#include <iostream.h>
#include <cmath>
#include <conio.h>

int main()
{
    int n, a = 0;


    cout << " input n \n";
    cin >> n;

    for (int i = 1; i < n; i++)
    {
	a = ((n%i) == 0) ? a + i : a + 0;
    }

    if (a == n) cout << "yes";
    else cout << "no";
    getch();
    return 0;
}

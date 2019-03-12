

#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>

int main()
{
    double d = 0, e = 0.001, sum = 0;
    int n = 1;

    do
     {
        d = ((1 / powl(2, n)) + (1 / powl(3, n)));
        sum += d;
        n++;
     }while (d > e);

    cout << "\n summa = " << sum << endl;

    getch();
    return 0;
}

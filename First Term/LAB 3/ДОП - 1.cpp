
#include <tchar.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>

int main()
{
    int a, b, c, sum;

    for (int i = 100, on, tw, th; i < 1000; i++)
    {
	 c = i % 10;
	 b = (i / 10) % 10;
	 a = (i / 100);

	 for (int f = 1, fact_a = 1; f <= a; f++)
	 {
	      	on = fact_a *= f;
	 }

	 for (int f = 1, fact_b = 1; f <= b; f++)
	 {
	     tw = fact_b *= f;
	 }

	 for (int f = 1, fact_c = 1; f <= c; f++)
	 {
	     th = fact_c *= f;
	 }

	 if (b == 0) tw = 0;
	 if (c == 0) th = 0;

	 sum = on + tw + th;

	 if (sum == i) cout << " i = " << i << endl;
	 //cout << " i = " << i << " a = " << a << " b = " << b << " c = " << c << " fact_a = " << on << " fact_b = " << tw << " fact_c = " << th << " sum = " << sum << endl;
    }
    getch();
    return 0;
}

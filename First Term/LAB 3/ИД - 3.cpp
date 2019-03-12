
#include <tchar.h>
#include <iostream.h>
#include <cmath>
#include <conio.h>

int main()
{
    float f;

    cout << " |     X      |     F(x)     |\n";
    cout << " |------------|--------------|\n";

    for (float x = 0.4; x <= 0.81; x += 0.1)
    {
    	f = x * (1 - cos(x));

        cout << " |    " << x << "     |   " << f << "   |\n";
	//printf(" |  %f  |  %f  |\n", x, f);
    }

    getch();
    return 0;
}


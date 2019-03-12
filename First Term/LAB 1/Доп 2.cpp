
#pragma hdrstop
#pragma argsused


#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

int _tmain()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int a, b, c, x, y;


    cout << "Ведите параметры фигуры:";

    cout << "\n a=";
    cin >> a;

    cout << "\n b=";
    cin >> b;

    cout << "\n c=";
    cin >> c;

    cout << "\n Параметры отверстия:";

    cout << "\n x=";
    cin >> x;

    cout << "\n y=";
    cin >> y;

   while (a != x && b != x && c != x || a != y && b != y && c != y)
   {
    cout << "Повторите ввод";

    cout << "\n Ведите параметры фигуры:";

    cout << "\n a=";
    cin >> a;

    cout << "\n b=";
    cin >> b;

    cout << "\n c=";
    cin >> c;

    cout << "\n Параметры отверстия:";

    cout << "\n x=";
    cin >> x;

    cout << "\n y=";
    cin >> y;
   }


    cout << "\n Кирпич пройдет в отверстие";

    getch ();
    return 0;
}
//---------------------------------------------------------------------------

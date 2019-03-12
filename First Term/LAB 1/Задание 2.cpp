#include <stdio.h>
#include <tchar.h>
#include <iostream.h>
#include <windows.h>
#include <conio.h>

int main()
{
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);

  int d;
  char znak, sign;

  lb:

  cout << "znak=";
  cin >> znak;

  switch (znak)
  {
   case '-': cout << "\n d = 45"; break;
   case '+': cout << "\n d = 39"; break;
   case '*': cout << "\n d = -34"; break;
   case '/': cout << "\n d = 55"; break;
   default:
    { cout << "\n Неправельный ввод";
      cout << "\n Для повтора нажмите Y";
      cin >> sign;
      gotu lb;
    }
  }

 getch();
 }


#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

int main()
{
  int n = 1;
  float e = 1/1000, d;

  do
  {
   d = d + 1/pow(2., n) + 1/pow(3., n);
   n++;
  }
  while (d < e);

  cout << "summa d = " << d;

  getch();
  return 0;
}
//---------------------------------------------------------------------------

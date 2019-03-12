#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <cmath>

double integral1(double h, int n, double *I);
double integral2(double h, int n, double *I);
double integral3(double h, int n, double *I);
double integral4(double h, int n, double *I);

int main()
{
   int n = 100;
   double rez, h;

   rez = 0;
   h = (1.2-0.4)/n;
   integral1(h, n, &rez);

   rez = 0;
   h = (0.9-0.3)/n;
   integral2(h, n, &rez);

   rez = 0;
   h = (2.7-1.2)/n;
   integral3(h, n, &rez);

   rez = 0;
   h = (2.4-1.6)/n;
   integral4(h, n, &rez);

   getch();
   return 0;
}


double integral1(double h, int n, double *I)
{
   static int i = 1;
   static double x, fn,  xn = 0.4 + n * h;
   static double ffn  = (sqrt(0.5 * 0.4 + 2) / (sqrt(2 * 0.16 + 1) + 0.8) + sqrt(0.5 * xn + 2) / (sqrt(2 * xn*xn + 1) + 0.8)) / 2;

   if (i > n - 1)
   {
    cout << "\n value(1) = " << h*(*I + ffn);
    return 0;
   }

   x = 0.4 + i * h;
   fn = sqrt(0.5 * x + 2) / (sqrt(2 * x*x + 1) + 0.8);
   *I += fn;

   i++;
   return integral1(h, n, I);
}

double  integral2(double h, int n, double *I)
{
   static int i = 1;
   static double x, fn , xn = 0.3 + n * h;
   static double ffn  = (cos(0.8 * 0.3 + 1.2) / (1.5 + sin(0.09 + 0.6)) + cos(0.8 * xn + 1.2) / (1.5 + sin(xn*xn + 0.6)))/2;

   if (i > n - 1)
   {
     cout << "\n value(2) = " << h*(*I + ffn);
     return 0;
   }

   x = 0.3 + i * h;
   fn = cos(0.8 * x + 1.2) / (1.5 + sin(x*x + 0.6));
   *I += fn;

   i++;
   return integral2(h, n, I);
}

double integral3(double h, int n, double *I)
{
   static int i = 1;
   static double x, fn , xn = 1.2 + n * h;
   static double ffn  = (1 / sqrt(1.44 + 3.2) + 1 / sqrt(xn*xn + 3.2)) / 2;

   if (i > n - 1)
   {
     cout << "\n value(3) = " << h*(*I + ffn);
     return 0;
   }

   x = 1.2 + i * h;
   fn = 1 / sqrt(x*x + 3.2);
   *I += fn;

   i++;
   return integral3(h, n, I);
}

double integral4(double h, int n, double *I)
{
   static int i = 1;
   static double x, fn , xn = 1.6 + n * h;
   static double ffn  = ((1.6 + 1) * sin(1.6) + (xn + 1) * sin(xn)) / 2;

   if (i > n - 1)
   {
     cout << "\n value(4) = " << h*(*I + ffn);
     return 0;
   }

   x = 1.6 + i * h;
   fn = (x + 1) * sin(x);
   *I += fn;

   i++;
   return integral4(h, n, I);
}


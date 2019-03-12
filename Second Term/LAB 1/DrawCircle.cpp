//---------------------------------------------------------------------------


#pragma hdrstop

#include "DrawCircle.h"

//---------------------------------------------------------------------------

void DrawCircle::Circle(TForm *Form, TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2, TEdit *EditScale,
     TEdit *SetTime, TEdit *EditR, TEdit *EditX0, TEdit *EditY0, TLabel *LabelSquare, TLabel *LabelPerimeter)
{

    int X0, Y0, X, Y, a, b, Time, angle;
    double scale, Xmove = 0, Ymove = 0;

    int X1, Y1, X2, Y2;
    int Xlast, Ylast, L, Count = 0, NTick = 0, sTime = 0;
    Get(X1, Y1, X2, Y2, scale, Time, angle, Xlast, Ylast, EditX1, EditY1, EditX2, EditY2, EditScale, SetTime, EditR, EditX0, EditY0);

    double ch, ChScale = 0, ChAngle;
    X0 = (X1 + X2) / 2;
    Y0 = (Y1 + Y2) / 2;
    SetTickE(X0, Y0, Xlast, Ylast, Time, Xmove, Ymove, sTime);

    //Label10->Caption = FloatToStr(Ymove);

    if (Xlast == 0 && Ylast == 0)
    {
       EditX0->Text = X0;
       EditY0->Text = Y0;
    }

    a = abs(X2 - X1) / 2;
    b = abs(Y2 - Y1) / 2;

    if (Time == 0)
    {
        ChAngle = angle;
        ChScale = scale - 1;
    }
    else if (Time != 0 && Xmove == 0 && Ymove == 0)
    {
        NTick = (Time - 300) / 35;
        ChAngle = ((double)angle / (double)NTick) * M_PI / 180;
        ChScale = (scale - 1) / (double)NTick;
        sTime = 35;
    }
    else if (Xmove != 0 || Ymove != 0)
    {
        NTick = Time / sTime;
        ChAngle = ((double)angle / (double)NTick) * M_PI / 180;
        ChScale = (scale - 1) / (double)NTick;
    }
    if (angle == 0 && scale == 1 && Xmove == 0 && Ymove == 0) NTick = 0;

    Draw(X0, Y0, a, b, NTick, sTime, ChAngle, ChScale, Xmove, Ymove, Form, Xlast, Ylast, LabelSquare, LabelPerimeter);
}



void DrawCircle::Draw(int X0, int Y0, int a, int b, int NTick, int sTime, double ChAngle, double ChScale, double Xmove, double Ymove,
     TForm *Form, int Xlast, int Ylast, TLabel *LabelSquare, TLabel *LabelPerimeter)
{
   int L, X, Y, Square, Count = NTick;
   double ch, ChAngleCpy = ChAngle, ChScaleCpy = ChScale, XmoveCpy = Xmove, YmoveCpy = Ymove;

   do
   {
       L = 4 * (1 + ChScale) * ((a * b * M_PI) + (a - b) * (a - b)) / (a + b);
       ch = (double)700 / (double)L;

       Application->ProcessMessages();
       Sleep(sTime);

       Form->Repaint();
       Form->Canvas->Pen->Width = 4;

       for (double deg = 0; deg < 90; deg += ch)
       {
           X = (a * (1 + ChScale) * cos(deg * M_PI / 180)) * cos(ChAngle) - (b * (1 + ChScale) * sin(deg * M_PI / 180)) * sin(ChAngle);
           Y = (a * (1 + ChScale) * cos(deg * M_PI / 180)) * sin(ChAngle) + (b * (1 + ChScale) * sin(deg * M_PI / 180)) * cos(ChAngle);

           Form->Canvas->MoveTo(X + X0 + Xmove, Y + Y0 + Ymove);
           Form->Canvas->LineTo(X + X0 + Xmove + 1, Y + Y0 + Ymove);

           Form->Canvas->MoveTo(-X + X0 + Xmove, -Y + Y0 + Ymove);
           Form->Canvas->LineTo(-X + X0 + Xmove + 1, -Y + Y0 + Ymove);

           X = (a * (1 + ChScale) * cos((deg + 270) * M_PI / 180)) * cos(ChAngle) - (b * (1 + ChScale) * sin((deg + 270) * M_PI / 180)) * sin(ChAngle);
           Y = (a * (1 + ChScale) * cos((deg + 270) * M_PI / 180)) * sin(ChAngle) + (b * (1 + ChScale) * sin((deg + 270) * M_PI / 180)) * cos(ChAngle);

           Form->Canvas->MoveTo(X + X0 + Xmove, Y + Y0 + Ymove);
           Form->Canvas->LineTo(X + X0 + Xmove + 1, Y + Y0 + Ymove);

           Form->Canvas->MoveTo(-X + X0 + Xmove, -Y + Y0 + Ymove);
           Form->Canvas->LineTo(-X + X0 + Xmove + 1, -Y + Y0 + Ymove);
       }

       ChAngle += ChAngleCpy;
       ChScale += ChScaleCpy;
       Xmove += XmoveCpy;
       Ymove += YmoveCpy;

       Square = M_PI * a * b * (1 + ChScale)*(1 + ChScale);
       LabelSquare->Caption = IntToStr(Square);
       LabelPerimeter->Caption = IntToStr(L);
       Count--;
       if (Count <= 0) break;
   }while(true);
}

#pragma package(smart_init)

//---------------------------------------------------------------------------


#pragma hdrstop

#include "DrawPolygon.h"

//---------------------------------------------------------------------------

DrawPol::DrawPol(int valueN)
    {
        N = valueN;
        XY = new int*[valueN];
        for (int i = 0; i < valueN; i++)
        XY[i] = new int[2];
    }

DrawPol::~DrawPol()
    {
        for (int i = 0; i < N; i++)
            delete[] XY[i];
        delete[] XY;
    }

void DrawPol::Polygon(TEdit *EditN, TForm *Form, TEdit *EditX0, TEdit *EditY0, TEdit *EditR,
     TEdit *EditMoveToX, TEdit *EditMoveToY, TEdit *SetTime, TEdit *EditScale, TLabel *LabelSquare, TLabel *LabelPerimeter)
{
    int X0, Y0, MoveToX = 0, MoveToY, Time, sTime, ANGLE;
    double Xmove = 0, Ymove = 0, scale;

    Get(Time, X0, Y0, MoveToX, MoveToY, scale, ANGLE, SetTime, EditX0, EditY0, EditMoveToX, EditMoveToY, EditScale, EditR);
    SetTickP(Time, sTime, X0, Y0, MoveToX, MoveToY, Xmove, Ymove);

    if (N) Draw(XY, X0, Y0, N, ANGLE, Form, Time, scale, sTime, Xmove, Ymove, LabelSquare, LabelPerimeter);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DrawPol::Draw(int** XY, int X0, int Y0, int N, int ANGLE, TForm *Form, int Time,
     double scale, int sTime, double Xmove, double Ymove, TLabel *LabelSquare, TLabel *LabelPerimeter)
{
       double alpha, angle;
       angle = 360 / N;

       Form->Repaint();
       Form->Canvas->Pen->Width = 3;

       int Radius = 100;
       int NTick = 0, Count = 0, RCpy = Radius;

       double ChScale = 0, ChScaleCpy = 0, ChAngle = 0, ChAngleCpy = 0;
       if (Time && sTime == 0)
       {
          NTick = Time / 35;
          Count = NTick;

          ChScale = (scale - 1) / NTick;
          ChScaleCpy = ChScale;

          ChAngle = (double)ANGLE / (double)NTick;
          ChAngleCpy = ChAngle;
          sTime = 35;
       }
       else if (sTime != 0)
       {
          Count = Time / sTime;

          ChScale = (scale - 1) / Count;
          ChAngle = (double)ANGLE / (double)Count;
       }
       else
       {
          ChScale = scale - 1;
          ChAngle = ANGLE;
       }
       ChScaleCpy = ChScale;
       ChAngleCpy = ChAngle;

//////////////////////////////////////////////////–»—Œ¬¿À ¿///////////////////////////////////////////////
       if (scale == 1&& ANGLE == 0&& Xmove == 0 && Ymove == 0) Count = 0;
       int Square, Perimeter;
       double Xc = Xmove, Yc = Ymove;
       do
       {
          Radius = RCpy * (1 + ChScale);
          for (int i = 0; i < N; i++)
          {
          alpha = (angle * i + ChAngle) * M_PI / 180;
          XY[i][0] = Radius * cos(alpha) - Radius * sin(alpha) + X0 + Xmove;
          XY[i][1] = Radius * sin(alpha) + Radius * cos(alpha) + Y0 + Ymove;
          }
          ChScale += ChScaleCpy;
          ChAngle += ChAngleCpy;
          Xmove += Xc;
          Ymove += Yc;

          Application->ProcessMessages();
          Sleep(sTime);

          Form->Repaint();
          Form->Canvas->MoveTo(XY[0][0], XY[0][1]);
          for (int i = 1; i < N; i++)
          {
              Form->Canvas->LineTo(XY[i][0], XY[i][1]);
          }
          Form->Canvas->LineTo(XY[0][0], XY[0][1]);

        ///////////////////////////////—◊»“¿≈Ã œÀŒŸ¿ƒ‹ » œ≈–»Ã≈“–//////////////////////////
          Square = (N / 2) * Radius *Radius * sin((2 * M_PI) / N);
          LabelSquare->Caption = IntToStr(Square);

          Perimeter = N * sin(M_PI / N) * (2 * Radius);
          LabelPerimeter->Caption = FloatToStr(Perimeter);
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////
          Count--;
          if (Count <= 0) break;
       }while(true);
}

#pragma package(smart_init)

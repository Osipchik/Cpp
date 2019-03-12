//---------------------------------------------------------------------------


#pragma hdrstop

#include "DrawRectangle.h"

//---------------------------------------------------------------------------

void DrawRect::Rectangle(TForm *Form, TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2,
                        TEdit *EditX0, TEdit *EditY0, TEdit *EditScale, TEdit *SetTime, TEdit *EditR, TLabel *LabelSquare, TLabel *LabelPerimeter)
{
   int xy[4][2], XY[4][2], Xlast, Ylast, Time, sTime;
   double scale, Xmove, Ymove, SCALE = 1, angle;

   Get(xy, EditX1, EditY1, EditX2, EditY2, EditX0, EditY0, Xlast, Ylast, EditScale, scale, SetTime, Time, EditR, angle);
   SetTick(xy, XY, 1, Xlast, Ylast, Time, Xmove, Ymove, sTime);

   int X0 = (xy[0][0] + xy[1][0]) / 2, Y0 = (xy[1][1] + xy[2][1]) / 2;
   double XmoveCpy = Xmove, YmoveCpy = Ymove;

   if (Time > 0 && sTime != 0 || Xmove != 0 || Ymove != 0)
   {
       Draw_on_motion(Form, Time, sTime, scale, xy, XY, Xmove, Ymove, Xlast, Ylast, angle, LabelSquare, LabelPerimeter);
   }
   else
   {
       Draw_on_place(Form, Time, scale, xy, XY, angle, LabelSquare, LabelPerimeter);
   }

   if (Xlast == 0) EditX0->Text = X0;
   if (Ylast == 0) EditY0->Text = Y0;
   else
   {
      EditX0->Text = Xlast;
      EditY0->Text = Ylast;
   }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void DrawRect::Draw_on_motion(TForm *Form, int Time, int sTime, double scale, int (&xy)[4][2],
     int (&XY)[4][2], double Xmove, double Ymove, int Xlast, int Ylast, int angle, TLabel *LabelSquare, TLabel *LabelPerimeter)
{
      double ChScale, XmoveCpy = Xmove, YmoveCpy = Ymove, ChAngle;
      int x0 = (xy[0][0] + xy[2][0]) / 2,  y0 = (xy[0][1] + xy[2][1]) / 2, NTick = 0, Square = 0, Perimeter = 0;
      int X0, Y0;

     if (Time != 0)
     {
        NTick = Time / sTime;
        ChScale = (scale - 1) / (double)NTick;
        ChAngle = (double)angle / (double)NTick ;
     }
     else
     {
        ChAngle = angle;
        ChScale = scale - 1;
        Xlast -= Xlast / 10;
        Ylast -= Ylast / 10;
     }

      double ChScaleCpy = ChScale, ChAngleCpy = ChAngle;
      do
      {
         Application->ProcessMessages();
         Sleep(sTime);

         SetScaleR(xy, XY, ChScale);
         TurnR(XY, xy, ChAngle, x0, y0);

         if (Xmove >= 1 || Xmove <= -1)
         {
            XY[0][0] += Xmove;
            XY[1][0] += Xmove;
            XY[2][0] += Xmove;
            XY[3][0] += Xmove;
            Xmove = Xmove > 0 ? Xmove-- : Xmove++;
         }

         if (Ymove >= 1 || Ymove <= -1)
         {
            XY[0][1] += Ymove;
            XY[1][1] += Ymove;
            XY[2][1] += Ymove;
            XY[3][1] += Ymove;
            Ymove = Ymove > 0 ? Ymove-- : Ymove++;
         }

         Form->Repaint();
         Form->Canvas->Pen->Width = 3;
         Form->Canvas->MoveTo(XY[0][0], XY[0][1]);
         Form->Canvas->LineTo(XY[1][0], XY[1][1]);
         Form->Canvas->LineTo(XY[2][0], XY[2][1]);
         Form->Canvas->LineTo(XY[3][0], XY[3][1]);
         Form->Canvas->LineTo(XY[0][0], XY[0][1]);

         Xmove += XmoveCpy;
         Ymove += YmoveCpy;
         ChScale += ChScaleCpy;
         ChAngle += ChAngleCpy;

         X0 = (XY[0][0] + XY[2][0]) / 2;
         Y0 = (XY[0][1] + XY[2][1]) / 2;

         /////////////////////////Ñ×ÈÒÀÅÌ ÏËÎÙÀÄÜ È ÏÅÐÈÌÅÒÐ//////////////////////////
         Square = sqrt(pow(XY[0][0] - XY[1][0], 2) + pow(XY[0][1] - XY[1][1], 2)) * sqrt(pow(XY[1][0] - XY[2][0], 2) + pow(XY[1][1] - XY[2][1], 2));
         LabelSquare->Caption = IntToStr(Square);

         Perimeter = sqrt(pow(XY[0][0] - XY[1][0], 2) + pow(XY[0][1] - XY[1][1], 2)) + sqrt(pow(XY[1][0] - XY[2][0], 2) + pow(XY[1][1] - XY[2][1], 2));
         LabelPerimeter->Caption = IntToStr(Perimeter*2);
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////
         if (Xmove > 0 || Ymove > 0)
         {
            if (X0 + Y0 >= Xlast + Ylast) break;
         }
         else if (Xmove < 0 || Ymove < 0)
         {
            if (X0 + Y0 <= Xlast + Ylast) break;
         }
         else break;
      }while (true);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void DrawRect::Draw_on_place(TForm *Form, int Time, double scale, int (&xy)[4][2], int (&XY)[4][2], double angle, TLabel *LabelSquare, TLabel *LabelPerimeter)
{
      double ChScale = scale - 1, ChAngle;
      int X0 = abs((xy[0][0] + xy[2][0]) / 2), Y0 = abs((xy[0][1] + xy[2][1]) / 2), NTick = 0, Counter = 0, Square = 0, Perimeter = 0;
      int XLast = xy[0][0] < X0 ? xy[0][0] - abs((X0 - xy[0][0]) * abs(scale - 1)) : xy[0][0] + abs((X0 - xy[0][0]) * abs(scale - 1));

   ////////////////////////////////////////////////////////
      int sTime = 0;
      if (Time != 0)
      {
         NTick = (Time - 300) / 35;
         ChAngle = ((double)angle / (double)NTick);
         ChScale = (scale - 1) / (double)NTick;
         sTime = 35;
      }
      else
      {
         ChAngle = angle;
         ChScale = scale - 1;
      }

   ////////////////////////////////////////////////////////

      double ChScaleCpy = ChScale, ChAngleCpy = ChAngle;
      do
      {
         Application->ProcessMessages();
         Sleep(sTime);

         SetScaleR(xy, XY, ChScale);
         TurnR(XY, xy, ChAngle, X0, Y0);

         Form->Repaint();
         Form->Canvas->Pen->Width = 3;
         Form->Canvas->MoveTo(XY[0][0], XY[0][1]);
         Form->Canvas->LineTo(XY[1][0], XY[1][1]);
         Form->Canvas->LineTo(XY[2][0], XY[2][1]);
         Form->Canvas->LineTo(XY[3][0], XY[3][1]);
         Form->Canvas->LineTo(XY[0][0], XY[0][1]);

         ChScale += ChScaleCpy;
         ChAngle += ChAngleCpy;
         Counter++;

         /////////////////////////Ñ×ÈÒÀÅÌ ÏËÎÙÀÄÜ È ÏÅÐÈÌÅÒÐ//////////////////////////
         Square = sqrt(pow(XY[0][0] - XY[1][0], 2) + pow(XY[0][1] - XY[1][1], 2)) * sqrt(pow(XY[1][0] - XY[2][0], 2) + pow(XY[1][1] - XY[2][1], 2));
         LabelSquare->Caption = IntToStr(Square);

         Perimeter = sqrt(pow(XY[0][0] - XY[1][0], 2) + pow(XY[0][1] - XY[1][1], 2)) + sqrt(pow(XY[1][0] - XY[2][0], 2) + pow(XY[1][1] - XY[2][1], 2));
         LabelPerimeter->Caption = IntToStr(Perimeter*2);
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////

         if (ChScale != 0 && ChAngle != 0)
         {
            if (ChAngle > 0 && ChAngle >= angle+1) break;
            else if (ChAngle < 0 && ChAngle <= angle+1) break;
         }
         else if (Counter == NTick || Time == 0) break;

         if (angle == 0)
         {
            if (ChScale > 0 && ChScale >= scale - 1) break;
            else if (ChScale < 0 && ChScale <= scale - 1) break;
            else if (ChScale == 0) break;
         }

      }while (true);
}
#pragma package(smart_init)

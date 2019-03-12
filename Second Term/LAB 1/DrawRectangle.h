//---------------------------------------------------------------------------

#ifndef DrawRectangleH
#define DrawRectangleH
//---------------------------------------------------------------------------
#include "GetParametr.h"
#include "Motion.h"
#include <math.h>


class DrawRect : private GetParametr, private Motion
{
public:
   void Rectangle(TForm *Form, TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2,
                  TEdit *EditX0, TEdit *EditY0, TEdit *EditScale, TEdit *SetTime, TEdit *EditR, TLabel *Label10, TLabel *LabelPerimeter);
private:
   void Draw_on_motion(TForm *Form, int Time, int sTime, double scale, int (&xy)[4][2],
     int (&XY)[4][2], double Xmove, double Ymove, int Xlast, int Ylast, int angle, TLabel *LabelSquare, TLabel *LabelPerimeter);
   void Draw_on_place(TForm *Form, int Time, double scale, int (&xy)[4][2], int (&XY)[4][2], double angle, TLabel *LabelSquare, TLabel *LabelPerimeter);
};

#endif

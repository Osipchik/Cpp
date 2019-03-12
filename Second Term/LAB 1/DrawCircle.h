//---------------------------------------------------------------------------

#ifndef DrawCircleH
#define DrawCircleH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>

#include "GetParametr.h"
#include "Motion.h"

class DrawCircle : private GetParametr, private Motion
{
public:
    void Circle(TForm *Form, TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2, TEdit *EditScale,
     TEdit *SetTime, TEdit *EditR, TEdit *EditX0, TEdit *EditY0, TLabel *LabelSquare, TLabel *LabelPerimeter);

    void Draw(int X0, int Y0, int a, int b, int NTick, int sTime, double ChAngle, double ChScale, double Xmove, double Ymove,
         TForm *Form, int Xlast, int Ylast, TLabel *LabelSquare, TLabel *LabelPerimeter);
};

#endif

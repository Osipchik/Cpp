//---------------------------------------------------------------------------

#ifndef DrawTreangleH
#define DrawTreangleH
//---------------------------------------------------------------------------
#include "GetParametr.h"
#include "Motion.h"

#include <math.h>
class DrawTreangle : private GetParametr, private Motion
{
public:
    void Treangle(TForm *Form, TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2, TEdit *EditX3, TEdit *EditY3,
    TEdit *EditX0, TEdit *EditY0,  TEdit *EditScale, TEdit *SetTime, TEdit *EditR, TLabel *LabelSquare, TLabel *LabelPerimeter);
private:
    void Draw_on_motion(TForm *Form, int Time, int sTime, double scale, int (&xy)[3][2], int (&XY)[3][2], double Xmove,
        double Ymove, int Xlast, int Ylast, int angle, TLabel *LabelSquare, TLabel *LabelPerimeter);

    void Draw_on_place(TForm *Form, int Time, double scale, int (&xy)[3][2], int (&XY)[3][2], double angle, TLabel *LabelSquare, TLabel *LabelPerimeter);
};

#endif

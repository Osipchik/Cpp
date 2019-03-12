//---------------------------------------------------------------------------

#ifndef DrawPolygonH
#define DrawPolygonH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>

#include "GetParametr.h"
#include "Motion.h"

class DrawPol : private GetParametr,  private Motion
{
    int N;
    int** XY;
public:

    DrawPol(int valueN);
    ~DrawPol();

    void Polygon(TEdit *EditN, TForm *Form,  TEdit *EditX0, TEdit *EditY0, TEdit *EditR,
         TEdit *EditMoveToX, TEdit *EditMoveToY, TEdit *SetTime, TEdit *EditScale, TLabel *LabelSquare, TLabel *LabelPerimeter);

    void Draw(int** XY, int X0, int Y0, int N, int ANGLE, TForm *Form, int Time,
         double scale, int sTime,  double Xmove, double Ymove, TLabel *LabelSquare, TLabel *LabelPerimeter);
};

#endif

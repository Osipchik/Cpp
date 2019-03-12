//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit2.h"

//---------------------------------------------------------------------------

void ScaleX::SetScaleX(int (&xy)[4][2], int (&XY)[4][2], double scale)
{
    int X0 = (xy[0][0] + xy[1][0]) / 2, Y0 = (xy[1][1] + xy[2][1]) / 2;
    if (scale >= 1)
        for (int i = 0; i < 4; i++)
        {
            XY[i][0] = xy[i][0] < X0 ? xy[i][0] - abs(X0 - xy[i][0]) * abs((scale - 1)*100)/100 : xy[i][0] + abs(X0 - xy[i][0]) * abs((scale - 1)*100)/100;
            XY[i][1] = xy[i][1] < Y0 ? xy[i][1] - abs(Y0 - xy[i][1]) * abs((scale - 1)*100)/100 : xy[i][1] + abs(Y0 - xy[i][1]) * abs((scale - 1)*100)/100;
        }
    else
        for (int i = 0; i < 4; i++)
        {
            XY[i][0] = xy[i][0] < X0 ? xy[i][0] + abs(X0 - xy[i][0]) * abs((scale - 1)*100)/100 : xy[i][0] - abs(X0 - xy[i][0]) * abs((scale - 1)*100)/100;
	    XY[i][1] = xy[i][1] < Y0 ? xy[i][1] + abs(Y0 - xy[i][1]) * abs((scale - 1)*100)/100 : xy[i][1] - abs(Y0 - xy[i][1]) * abs((scale - 1)*100)/100;
        }
}

#pragma package(smart_init)

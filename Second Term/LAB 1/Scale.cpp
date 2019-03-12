//---------------------------------------------------------------------------


#pragma hdrstop

#include "Scale.h"

//---------------------------------------------------------------------------

void Scale::SetScaleR(int (&xy)[4][2], int (&XY)[4][2], double ChScale)
{
    int X0 = (xy[0][0] + xy[2][0]) / 2, Y0 = (xy[0][1] + xy[2][1]) / 2;
    if (ChScale >= 0)
        for (int i = 0; i < 4; i++)
        {
            XY[i][0] = xy[i][0] < X0 ? xy[i][0] - abs(X0 - xy[i][0]) * abs((ChScale)*100)/100 : xy[i][0] + abs(X0 - xy[i][0]) * abs((ChScale)*100)/100;
            XY[i][1] = xy[i][1] < Y0 ? xy[i][1] - abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100 : xy[i][1] + abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100;
        }
    else
        for (int i = 0; i < 4; i++)
        {
            XY[i][0] = xy[i][0] < X0 ? xy[i][0] + abs(X0 - xy[i][0]) * abs((ChScale)*100)/100 : xy[i][0] - abs(X0 - xy[i][0]) * abs((ChScale)*100)/100;
	    XY[i][1] = xy[i][1] < Y0 ? xy[i][1] + abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100 : xy[i][1] - abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100;
        }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Scale::SetScaleT(int (&xy)[3][2],  int (&XY)[3][2], double ChScale)
{
    int X0 = (xy[0][0] + xy[1][0] + xy[2][0]) / 3, Y0 = (xy[0][1] + xy[1][1] + xy[2][1]) / 3;
    if (ChScale >= 0)
        for (int i = 0; i < 3; i++)
        {
            XY[i][0] = xy[i][0] < X0 ? xy[i][0] - abs(X0 - xy[i][0]) * abs((ChScale)*100)/100 : xy[i][0] + abs(X0 - xy[i][0]) * abs((ChScale)*100)/100;
            XY[i][1] = xy[i][1] < Y0 ? xy[i][1] - abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100 : xy[i][1] + abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100;
        }
    else
        for (int i = 0; i < 3; i++)
        {
            XY[i][0] = xy[i][0] < X0 ? xy[i][0] + abs(X0 - xy[i][0]) * abs((ChScale)*100)/100 : xy[i][0] - abs(X0 - xy[i][0]) * abs((ChScale)*100)/100;
	    XY[i][1] = xy[i][1] < Y0 ? xy[i][1] + abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100 : xy[i][1] - abs(Y0 - xy[i][1]) * abs((ChScale)*100)/100;
        }
}
#pragma package(smart_init)

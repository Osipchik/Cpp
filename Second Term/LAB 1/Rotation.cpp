//---------------------------------------------------------------------------


#pragma hdrstop

#include "Rotation.h"

//---------------------------------------------------------------------------

void Rotation::TurnR(int (&XY)[4][2], int (&xy)[4][2], double ChAngle, int X0, int Y0)
{
    int xyTemp[4][2];

    double alpha = ChAngle * M_PI / 180;

    for (int i = 0; i < 4; i++)
    {
        xyTemp[i][0] = XY[i][0];
        xyTemp[i][1] = XY[i][1];
    }

    for (int i = 0; i < 4; i++)
    {
        XY[i][0] = (xyTemp[i][0] - X0) * cos(alpha) - (xyTemp[i][1] - Y0) * sin(alpha) + X0;
        XY[i][1] = (xyTemp[i][0] - X0) * sin(alpha) + (xyTemp[i][1] - Y0) * cos(alpha) + Y0;
    }
}


void Rotation::TurnT(int (&XY)[3][2], int (&xy)[3][2], double ChAngle, int X0, int Y0)
{
    int xyTemp[3][2];

    double alpha = ChAngle * M_PI / 180;

    for (int i = 0; i < 3; i++)
    {
        xyTemp[i][0] = XY[i][0];
        xyTemp[i][1] = XY[i][1];
    }

    for (int i = 0; i < 3; i++)
    {
        XY[i][0] = (xyTemp[i][0] - X0) * cos(alpha) - (xyTemp[i][1] - Y0) * sin(alpha) + X0;
        XY[i][1] = (xyTemp[i][0] - X0) * sin(alpha) + (xyTemp[i][1] - Y0) * cos(alpha) + Y0;
    }
}
#pragma package(smart_init)

//---------------------------------------------------------------------------

#ifndef RotationH
#define RotationH
//---------------------------------------------------------------------------
#include <math.h>

class Rotation
{
public:
    void TurnR(int (&XY)[4][2], int (&xy)[4][2], double ChAngle, int X0, int Y0);

    void TurnT(int (&XY)[3][2], int (&xy)[3][2], double ChAngle, int X0, int Y0);
};

#endif

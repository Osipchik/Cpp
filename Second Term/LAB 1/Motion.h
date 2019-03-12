//---------------------------------------------------------------------------

#ifndef MotionH
#define MotionH
//---------------------------------------------------------------------------
#include "Scale.h"
#include "Rotation.h"

#include <math.h>
#include <vcl.h>

class Motion : public Scale, public Rotation
{
public:
   void SetTick(int (&xy)[4][2], int (&XY)[4][2], double scale,
        int Xlast, int Ylast, int Time, double &Xmove, double &Ymove, int &sTime);

   void SetTickT(int (&xy)[3][2], int (&XY)[3][2], double scale,
        int Xlast, int Ylast, int Time, double &Xmove, double &Ymove, int &sTime);

   void SetTickP(int Time,int &sTime, int X0, int Y0,int MoveToX, int MoveToY, double &Xmove, double &Ymove);

   void SetTickE(int X0, int Y0, int Xlast, int Ylast, int Time, double &Xmove, double &Ymove, int &sTime);
};
#endif

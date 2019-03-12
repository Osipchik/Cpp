//---------------------------------------------------------------------------

#ifndef ScaleH
#define ScaleH
//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>

class Scale
{
public:
   void SetScaleR(int (&xy)[4][2],  int (&XY)[4][2], double scale);

   void SetScaleT(int (&xy)[3][2],  int (&XY)[3][2], double scale);
};

#endif

//---------------------------------------------------------------------------

#ifndef myGridH
#define myGridH
//---------------------------------------------------------------------------

#include "Unit1.h"
#include "myStruct.h"
#include "MyException.h"

class myGrid
{
public:
    void GridColumnsName(TStringGrid *StringGrid);
    void AddRow(TStringGrid *StringGrid);
    void FillList(TStringGrid *StringGrid, StrudientInfo &info);
};

#endif

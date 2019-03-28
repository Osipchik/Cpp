//---------------------------------------------------------------------------

#ifndef myGridH
#define myGridH
//---------------------------------------------------------------------------

#include "Unit1.h"
#include "myList.h"
#include "myStruct.h"
#include "MyException.h"

class myGrid
{
public:
    void GridColumnsName(TStringGrid *StringGrid);
    void AddRow(TStringGrid *StringGrid);
    void FillCells(TStringGrid *StringGrid, List<StrudientInfo> &list, int index);
    void FillList(TStringGrid *StringGrid, StrudientInfo &info);
};

#endif

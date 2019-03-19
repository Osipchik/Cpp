//---------------------------------------------------------------------------

#ifndef OrderArrayH
#define OrderArrayH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>

#include "OpenFile.h"

class OrderArray : protected OpenFiles
{
private:
     String OrderNum;
     String TempStr;

public:
     OrderArray();
     void LoadInfo(TMemo *Memo, int LineNumber);
     void AddComboItems (TComboBox *ComboBox);
     void ShowOrderFile(TMemo *Memo);
};

#endif

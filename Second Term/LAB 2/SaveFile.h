//---------------------------------------------------------------------------

#ifndef SaveFileH
#define SaveFileH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>

class SaveFile
{
private:
     String FName;

public:
     SaveFile();
     void Save(TMemo *Memo, TSaveDialog *SaveDialog);
     String Price(TMemo *Memo);
};

#endif

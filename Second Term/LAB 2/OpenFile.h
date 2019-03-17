//---------------------------------------------------------------------------

#ifndef OpenFileH
#define OpenFileH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>

class OpenFiles
{
private:
     String FName;

     TFileStream *LoadFromFile;
     TStringList *LoadFile;

public:
     TStringList* OpenF(String FName);
};

#endif

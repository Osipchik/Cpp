//---------------------------------------------------------------------------


#pragma hdrstop

#include "OpenFile.h"

//---------------------------------------------------------------------------

TStringList* OpenFiles::OpenF(String FName)
{
     this->FName = FName;
     LoadFromFile = new TFileStream(FName + ".txt", fmOpenReadWrite);
     LoadFile = new TStringList;
     LoadFile->LoadFromStream(LoadFromFile);
     delete LoadFromFile;
     return LoadFile;
}

#pragma package(smart_init)

//---------------------------------------------------------------------------


#pragma hdrstop

#include "OpenFile.h"

//---------------------------------------------------------------------------
#include <string.h>

TStringList* OpenFiles::OpenF(String FName)
{
     this->FName = FName;
     if (FileExists(FName + ".txt"))
     {
        LoadFromFile = new TFileStream(FName + ".txt", fmOpenReadWrite);
        LoadFile = new TStringList;
        LoadFile->LoadFromStream(LoadFromFile);
        delete LoadFromFile;
        return LoadFile;
     }
     else
     {
        wchar_t message[] = L"File does not exist";
        wchar_t tytle[] = L"Error";
        Application->MessageBoxW(message, tytle, MB_ICONWARNING) == IDYES;
     }
     //return LoadFile;
}

#pragma package(smart_init)

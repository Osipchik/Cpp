//---------------------------------------------------------------------------

#ifndef VectorH
#define VectorH
//---------------------------------------------------------------------------
#include <vcl.h>
#include "OpenFile.h"

struct Info
{
    String OrderNum;
    String OrderCode;
    int Amount;
    int Coast;
    String Name;
};

class Vector : protected OpenFiles
{
private:
    Info info;
    String word;
    int lenght;
    String Word(String line, int &index);

public:
    Vector();
    void add(String str, String FileName, int index = 0, int order = 0);
    void add(String str, int index = 0);
    String Show(int order = 0);
    int Price();
    int Coast;
    int Amount;
};

#endif

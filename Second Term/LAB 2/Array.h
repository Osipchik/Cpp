//---------------------------------------------------------------------------

#ifndef ArrayH
#define ArrayH
//---------------------------------------------------------------------------
#include <vcl.h>
#include "Vector.h"

class Array
{
private:
    Vector *vector;
    Vector *vecTmp;
    int size;
    int price;
    template<typename T> void Swap(T& a, T& b);

public:
    Array();
    ~Array();
    void Add (String line, String FileName, int index = 0, int order = 0);
    String Show (int index, int order = 0);
    int Price ();
    void qSort (int first, int last, int d = 1);
    void reverce ();
};

#endif

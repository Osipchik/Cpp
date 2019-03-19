//---------------------------------------------------------------------------

#ifndef SortMemoH
#define SortMemoH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>
#include <vector.h>

struct MemoLines
{
     String amount;
     String coast;
     String MemoStr;
};

class SortMemo
{
private:
     int count;
     vector<MemoLines> vec;

public:
     void GetWord(TMemo *Memo);
};

#endif

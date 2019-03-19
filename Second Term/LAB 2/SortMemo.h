//---------------------------------------------------------------------------

#ifndef SortMemoH
#define SortMemoH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>
#include <vector.h>
#include <algorithm>

struct MemoLines
{
     int amount;
     int coast;
     String MemoStr;
};

class SortMemo
{
private:
     int count;
     vector<MemoLines> vec;
     void GetWord(TMemo *Memo);
     void qSortAmount(int first, int last);
     void qSortCoast(int first, int last);

public:
     void ShowA(TMemo *Memo);
     void ShowC(TMemo *Memo);
     void ShowAm(TMemo *Memo);
     void ShowCm(TMemo *Memo);
};

#endif

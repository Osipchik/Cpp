//---------------------------------------------------------------------------


#pragma hdrstop

#include "SortMemo.h"

//---------------------------------------------------------------------------

void SortMemo::GetWord(TMemo *Memo)
{
     count = Memo->Lines->Count;
     vec.resize(count);
     String word = "";

     while (count)
     {
         count--;
         vec[count].MemoStr = Memo->Lines->Strings[count];
         for (int i = 1; i < Memo->Lines->Strings[count].Length(); i++)
         {
       	     if (Memo->Lines->Strings[count][i] == ' ' && vec[count].amount == 0)
       	     {
       	        i++;
                word = "";
       	        while (Memo->Lines->Strings[count][i] != ' ')
       	        {
       	   	    word += Memo->Lines->Strings[count][i];
     	   	    i++;
     	        }
                vec[count].amount = StrToInt(word);

                i++;
                word = "";
     	        while (Memo->Lines->Strings[count][i] != ' ')
     	        {
     	   	    word += Memo->Lines->Strings[count][i];
     	   	    i++;
     	        }
                vec[count].coast = StrToInt(word);
     	     }
     	     else if (vec[count].amount != 0 && vec[count].coast != 0)
             {
                //Memo->Lines->Add(IntToStr(vec[count].amount) + "  " + IntToStr(vec[count].coast));
     	        break;
             }
         }
     }
}

void SortMemo::qSortAmount(int first, int last)
{
     int i = first, r = last;

     int priv = vec[(i + r) / 2].amount;

     while (i <= r)
     {
     	 while (vec[i].amount < priv)
             i++;
	 while (vec[r].amount > priv)
	     r--;
	 if (i <= r)
	     swap(vec[i++], vec[r--]);
     }

     if (first < r)
     	qSortAmount(first, r);
     if (last > i)
     	qSortAmount(i, last);
}


void SortMemo::qSortCoast(int first, int last)
{
     int i = first, r = last;

     int priv = vec[(i + r) / 2].coast;

     while (i <= r)
     {
     	 while (vec[i].coast < priv)
             i++;
	 while (vec[r].coast > priv)
	     r--;
	 if (i <= r)
	     swap(vec[i++], vec[r--]);
     }

     if (first < r)
     	qSortCoast(first, r);
     if (last > i)
     	qSortCoast(i, last);
}


void SortMemo::ShowA(TMemo *Memo)
{
     GetWord(Memo);
     qSortAmount(0, vec.size()-1);

     reverse(vec.begin(), vec.end());
     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Add(this->vec[i].MemoStr);
     }

     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Delete(0);
     }
}


void SortMemo::ShowC(TMemo *Memo)
{
     GetWord(Memo);
     qSortCoast(0, vec.size()-1);

     reverse(vec.begin(), vec.end());
     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Add(this->vec[i].MemoStr);
     }

     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Delete(0);
     }
}

void SortMemo::ShowAm(TMemo *Memo)
{
     GetWord(Memo);
     qSortAmount(0, vec.size()-1);

     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Add(this->vec[i].MemoStr);
     }

     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Delete(0);
     }
}

void SortMemo::ShowCm(TMemo *Memo)
{
     GetWord(Memo);
     qSortCoast(0, vec.size()-1);

     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Add(this->vec[i].MemoStr);
     }

     for (int i = 0; i < vec.size(); i++)
     {
         Memo->Lines->Delete(0);
     }
}


#pragma package(smart_init)

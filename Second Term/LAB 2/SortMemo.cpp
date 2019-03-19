//---------------------------------------------------------------------------


#pragma hdrstop

#include "SortMemo.h"

//---------------------------------------------------------------------------

void SortMemo::GetWord(TMemo *Memo)
{
     count = Memo->Lines->Count;
     vec.resize(count);

     while (count)
     {
         count--;
         vec[count].MemoStr = Memo->Lines->Strings[count];
         for (int i = 1; i < Memo->Lines->Strings[count].Length(); i++)
         {
       	     if (Memo->Lines->Strings[count][i] == ' ' && vec[count].amount == "")
       	     {
       	        i++;
       	        while (Memo->Lines->Strings[count][i] != ' ')
       	        {
       	   	    vec[count].amount += Memo->Lines->Strings[count][i];
     	   	    i++;
     	        }
     	     }
     	     else if (Memo->Lines->Strings[count][i] != ' ' && vec[count].coast == "" && vec[count].amount != "")
     	     {
     	        while (Memo->Lines->Strings[count][i] != ' ')
     	        {
     	   	    vec[count].coast += Memo->Lines->Strings[count][i];
     	   	    i++;
     	        }
     	     }
     	     else if (vec[count].amount != "" && vec[count].coast != "")
             {
                Memo->Lines->Add(vec[count].amount + "  " + vec[count].coast);
     	        break;
             }
         }
     }
}


#pragma package(smart_init)

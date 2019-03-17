//---------------------------------------------------------------------------


#pragma hdrstop

#include "SaveFile.h"

//---------------------------------------------------------------------------

SaveFile::SaveFile()
{
    FName = "Prise List";
};


void SaveFile::Save(TMemo *Memo, TSaveDialog *SaveDialog)
{
     SaveDialog->FileName = FName;
     if (SaveDialog->Execute())
     {
        Memo->Lines->SaveToFile(SaveDialog->FileName);
     }
     Memo->Lines->Add(String('\n') + String(Price(Memo)));
}

String SaveFile::Price(TMemo *Memo)
{
     int count = Memo->Lines->Count, index = 1, price = 0;
     String amount = "", coast = "", Sprice = "";

     while (count >= 0)
     {
           for (int i = 1; i < Memo->Lines->Strings[count].Length(); i++)
	   {
	   	if (Memo->Lines->Strings[count][i] == ' ' && amount == "")
	   	{
	   	   i++;
	   	   while (Memo->Lines->Strings[count][i] != ' ')
	   	   {
	   	   	amount += Memo->Lines->Strings[count][i];
		   	i++;
		   }
		}
		else if (Memo->Lines->Strings[count][i] != ' ' && coast == "" && amount != "")
		{
		   while (Memo->Lines->Strings[count][i] != ' ')
		   {
		   	coast += Memo->Lines->Strings[count][i];
		   	i++;
		   }
		}
		else if (amount != "" && coast != "")
                {
		   break;
                }
	   }
           if (amount != "" && coast != "") price += coast.ToInt() * amount.ToInt();
           coast = "";
           amount = "";
           count--;
     }

     return String(price) ;
}

#pragma package(smart_init)

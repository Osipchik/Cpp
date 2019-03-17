//---------------------------------------------------------------------------


#pragma hdrstop

#include "OrderArray.h"

//---------------------------------------------------------------------------

OrderArray::OrderArray()
{
    OrderNum = "";
};

void OrderArray::ShowOrderFile(TMemo *Memo)
{
    TStringList *PriceList = OpenF("Price list");
    TStringList *OrderList = OpenF(OrderNum);
    OrderList->Delete(0);

    String PriceStr = "", OrderStr = "", tempWord = "";

    for (int i = 0; i < OrderList->Count; i++, OrderStr = "")
    {
        for (int j = 1; OrderList->Strings[i][j] != ' '; j++)
        {
            OrderStr += OrderList->Strings[i][j];
        }

        for (int indexi = 0; indexi < PriceList->Count; indexi++, PriceStr = "")
        {
            if (PriceList->Strings[indexi].Pos(OrderStr))
            {
               for (int indexj = OrderStr.Length() + 1; indexj < PriceList->Strings[indexi].Length(); indexj++)
               {
                   PriceStr += PriceList->Strings[indexi][indexj];
               }
               Memo->Lines->Add(OrderList->Strings[i] + PriceStr);
            }
        }
    }
    delete OrderList;
    delete PriceList;
}


void OrderArray::AddComboItems (TComboBox *ComboBox)
{
     ComboBox->Items->Add(OrderNum);
}


void OrderArray::LoadFile(TOpenDialog *OpenDialog, TMemo *Memo, int LineNumber)
{
     TempStr = Memo->Lines->Strings[LineNumber];
     int index = 1;

     while (TempStr[index] != ' ')
     {
         OrderNum += TempStr[index];
         index++;
     }
}

#pragma package(smart_init)

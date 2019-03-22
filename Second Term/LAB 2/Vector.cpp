//---------------------------------------------------------------------------


#pragma hdrstop

#include "Vector.h"

//---------------------------------------------------------------------------

Vector::Vector()
{
    info.OrderNum = "";
    info.OrderCode = "";
    info.Amount = 0;
    info.Coast = 0;
    info.Name = "";

    Coast = Amount = 0;
}

void Vector::add(String str, String FileName, int index, int order)
{
     lenght = 1 + index;
     if (order == 1) info.OrderNum = Word(str, lenght);
     else
     {
        TStringList *PriceList = OpenF(FileName);

        info.OrderCode = Word(str, lenght);
        info.Amount = Word(str, lenght).ToInt();

        lenght = info.OrderCode.Length() + 2;
        int i = 0;
        while (i < PriceList->Count)
        {
           if (PriceList->Strings[i].Pos(info.OrderCode)) break;
           i++;
        }
        info.Coast = Word(PriceList->Strings[i], lenght).ToInt();
        info.Name = Word(PriceList->Strings[i], lenght);

        delete PriceList;
     }
}


void Vector::add(String str, int index)
{
     lenght = 1 + index;

     info.OrderCode = Word(str, lenght);
     info.Amount = Word(str, lenght).ToInt();
     info.Coast = Word(str, lenght).ToInt();
     info.Name = Word(str, lenght);

     Coast = info.Coast;
     Amount = info.Amount;
}

String Vector::Word(String line, int &index)
{
     word = "";

     while (line[index] == ' ' || line[index] == '\t' && index < line.Length())
         index++;

     while (line[index] != ' ' && line[index] != '\t' && index < line.Length())
     {
         word += line[index];
         index++;
     }
     if (word.Length() == 0) word = "0";
     return word;
}


String Vector::Show(int order)
{
     if (order == 1)
        return info.OrderNum;
     else
        return info.OrderCode + " " + '\t' + '\t' + IntToStr(info.Amount) + " " + '\t' + IntToStr(info.Coast) + " " + '\t' + info.Name + " ";
}


int Vector::Price()
{
    return info.Amount * info.Coast;
}


#pragma package(smart_init)

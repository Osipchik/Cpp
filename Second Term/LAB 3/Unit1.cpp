//---------------------------------------------------------------------------

#include <windows.h>
#include <locale.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "myList.h"
#include "myList.cpp"
#include "myGrid.h"
#include "MyException.h"
#include "myStruct.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

StrudientInfo info;
List<StrudientInfo> list;
myGrid SG;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
     setlocale(LC_ALL, "ru");
     SG.GridColumnsName(StringGrid1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
     StringGrid1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
     if (StringGrid1->Row < 10 && list.GetSize() == StringGrid1->RowCount - 1 || StringGrid1->RowCount == 1)
     {
         SG.AddRow(StringGrid1);

         if (StringGrid1->RowCount > 1)
         {
            ButtonDelete->Visible = true;
            Edit1->Visible = true;
         }
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
     if (Edit1->Text.IsEmpty())
     {
        if (StringGrid1->RowCount != 1 && list.GetSize() != 0)
        {
           StringGrid1->RowCount -= 1;
           list.pop_back();
        }
     }
     else if (Edit1->Text.ToInt() - 1 <= list.GetSize() && Edit1->Text != '0')
     {
        int index = Edit1->Text.ToInt() - 1;
        StringGrid1->RowCount--;
        list.remove(index);
        while (index < list.GetSize())
        {
            //SG.FillCells(StringGrid1, list, index);

            StringGrid1->Cells[1][index+1] = list[index].Surname;
            StringGrid1->Cells[2][index+1] = list[index].Name;
            StringGrid1->Cells[3][index+1] = list[index].Patronymic;
            StringGrid1->Cells[4][index+1] = list[index].Math;
            StringGrid1->Cells[5][index+1] = list[index].Physics;
            StringGrid1->Cells[6][index+1] = list[index].Language;
            StringGrid1->Cells[7][index+1] = list[index].GPA / 100.0;
            index++;

        }
     }
     if (StringGrid1->RowCount == 1)
     {
        ButtonDelete->Visible = false;
        Edit1->Visible = false;
        Edit1->Clear();
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, wchar_t &Key)
{
     if (Key == 13)
     {
     Memo1->Lines->Add(IntToStr(StringGrid1->Row) + '\t' + IntToStr(list.GetSize()));
       try
       {
          SG.FillList(StringGrid1, info);
          //if (list.GetSize() == StringGrid1->Row - 1) list.remove(StringGrid1->Row - 1);
          //list.insert(StringGrid1->Row - 1, info);
            //list.push_back(info);
          if (list.GetSize() < StringGrid1->RowCount - 1) list.push_back(info);
          else
          {
              //Memo1->Lines->Add(StringGrid1->Row);
              list.remove(StringGrid1->Row - 1);
              list.insert(StringGrid1->Row - 1, info);
          }
          //if (list[StringGrid1->Row].Surname.IsEmpty()) list.push_back(info);
          //else
          //{
          //  list[StringGrid1->Row - 1] = info;
          //}

       }
       catch(MyException &ex)
       {
          ex.FillCell(StringGrid1);
       }
     }
     if (Key == ' ')
     {
         if (StringGrid1->Col != StringGrid1->ColCount - 2 && StringGrid1->Col != 7)
            StringGrid1->Col++;
         else if (list.GetSize() == StringGrid1->RowCount - 1)
         {
            int row = StringGrid1->RowCount;
            StringGrid1->RowCount = row + 1;
            StringGrid1->Rows[row]->Clear();
            StringGrid1->Cells[0][row] = row;
            StringGrid1->Row++;
            StringGrid1->Col = 1;
         }
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFindClick(TObject *Sender)
{
     if (!EditFind->Text.IsEmpty())
     {
         for (int index = 0; index < list.GetSize(); index++)
         {
             if (list[index].Surname == EditFind->Text)
             {
                StringGrid1->Cells[1][1] = list[index].Surname;
                StringGrid1->Cells[2][1] = list[index].Name;
                StringGrid1->Cells[3][1] = list[index].Patronymic;
                StringGrid1->Cells[4][1] = list[index].Math;
                StringGrid1->Cells[5][1] = list[index].Physics;
                StringGrid1->Cells[6][1] = list[index].Language;
                StringGrid1->Cells[7][1] = list[index].GPA / 100.0;

                StringGrid1->RowCount = 2;
             }
         }
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Memo1->Lines->Add("row = " + IntToStr(StringGrid1->Row) +  "\t list = " + IntToStr(list.GetSize()));
     for (int index = 1; index-1 < list.GetSize() ; index++)
     {
         if (index < StringGrid1->RowCount)
         {
            StringGrid1->Cells[1][index] = list[index-1].Surname;
            StringGrid1->Cells[2][index] = list[index-1].Name;
            StringGrid1->Cells[3][index] = list[index-1].Patronymic;
            StringGrid1->Cells[4][index] = list[index-1].Math;
            StringGrid1->Cells[5][index] = list[index-1].Physics;
            StringGrid1->Cells[6][index] = list[index-1].Language;
            StringGrid1->Cells[7][index] = list[index-1].GPA / 100.0;
         }
         else
         {
            int row = StringGrid1->RowCount;
            StringGrid1->RowCount = row + 1;
            StringGrid1->Rows[row]->Clear();
            StringGrid1->Cells[0][row] = row;

            StringGrid1->Cells[1][index] = list[index-1].Surname;
            StringGrid1->Cells[2][index] = list[index-1].Name;
            StringGrid1->Cells[3][index] = list[index-1].Patronymic;
            StringGrid1->Cells[4][index] = list[index-1].Math;
            StringGrid1->Cells[5][index] = list[index-1].Physics;
            StringGrid1->Cells[6][index] = list[index-1].Language;
            StringGrid1->Cells[7][index] = list[index-1].GPA / 100.0;
         }
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
     int mid = 0, count = list.GetSize(), row;
   if (count > 0)
   {
     StringGrid1->RowCount = 1;
     for (int i = 0; i < count; i++)
     {
         mid += list[i].GPA;
     }
     mid /= count;

     Memo1->Lines->Add(mid / 100);
     for (int i = 0; i < count; i++)
     {
         if (list[i].GPA > mid)
         {
            row = StringGrid1->RowCount;
            StringGrid1->RowCount++;
            StringGrid1->Rows[row]->Clear();
            StringGrid1->Cells[0][row] = row;

            StringGrid1->Cells[1][row] = list[i].Surname;
            StringGrid1->Cells[2][row] = list[i].Name;
            StringGrid1->Cells[3][row] = list[i].Patronymic;
            StringGrid1->Cells[4][row] = list[i].Math;
            StringGrid1->Cells[5][row] = list[i].Physics;
            StringGrid1->Cells[6][row] = list[i].Language;
            StringGrid1->Cells[7][row] = list[i].GPA / 100.0;
         }
     }
   }
}
//---------------------------------------------------------------------------


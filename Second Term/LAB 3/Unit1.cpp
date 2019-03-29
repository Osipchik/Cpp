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
     if (StringGrid1->RowCount < 11 && list.GetSize() == StringGrid1->RowCount - 1 || StringGrid1->RowCount == 1)
     {
         SG.AddRow(StringGrid1);
     }

     if (list.GetSize() > 0)
     {
        ButtonDelete->Visible = true;
        Edit1->Visible = true;
        ButtonFind->Visible = true;
        EditFind->Visible = true;
        ButtonShow->Visible = true;
        Button2->Visible = true;
        Button3->Visible = true;
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
     else 
     {
        String str = Edit1->Text;
        try
        {
           for (int i = 1; i-1 < str.Length(); i++)
               if (str[i] > '0' && str[i] > '9' || str[i] == ' ') throw MyException();

           int index = Edit1->Text.ToInt() - 1;
           if (index >= 0)
           {
              StringGrid1->RowCount--;
              list.remove(index);
              while (index < list.GetSize())
              {
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
        }
        catch (MyException &ex)
        {
           ex.FillEdit(Edit1);
        }
     }

     if (StringGrid1->RowCount == 1)
     {
        ButtonDelete->Visible = false;
        Edit1->Visible = false;
        Edit1->Clear();
     }

     if (list.GetSize() == 0)
     {
        ButtonDelete->Visible = false;
        Edit1->Visible = false;
        ButtonFind->Visible = false;
        EditFind->Visible = false;
        ButtonShow->Visible = false;
        Button2->Visible = false;
        Button3->Visible = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, wchar_t &Key)
{
     if (Key == 13)
     {
       try
       {
          SG.FillList(StringGrid1, info);
          if (list.GetSize() < StringGrid1->RowCount - 1) list.push_back(info);
          else
          {
              list.remove(StringGrid1->Row - 1);
              list.insert(StringGrid1->Row - 1, info);
          }

       }
       catch(MyException &ex)
       {
          ex.FillCell(StringGrid1);
       }
     }

     if (Key == ' ')
     {
         if (StringGrid1->Col != StringGrid1->ColCount - 2 && StringGrid1->Col != 7) StringGrid1->Col++;
         else if (list.GetSize() == StringGrid1->RowCount - 1 && StringGrid1->RowCount < 11) SG.AddRow(StringGrid1);

         if (list.GetSize() > 0)
         {
            ButtonDelete->Visible = true;
            Edit1->Visible = true;
            ButtonFind->Visible = true;
            EditFind->Visible = true;
            ButtonShow->Visible = true;
            Button2->Visible = true;
            Button3->Visible = true;
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

void __fastcall TForm1::ButtonShowClick(TObject *Sender)
{
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

     for (int i = 0; i < count; i++)
     {
         if (list[i].GPA >= mid)
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

void __fastcall TForm1::Button3Click(TObject *Sender)
{
     for (int i = 0; i < list.GetSize(); i++)
         if (list[i].GPA == 0) list.remove(i); 

     StringGrid1->RowCount = 1; 
        
     for (int index = 1; index-1 < list.GetSize(); index++)
     {
         SG.AddRow(StringGrid1);
         
         StringGrid1->Cells[1][index] = list[index-1].Surname;
         StringGrid1->Cells[2][index] = list[index-1].Name;
         StringGrid1->Cells[3][index] = list[index-1].Patronymic;
         StringGrid1->Cells[4][index] = list[index-1].Math;
         StringGrid1->Cells[5][index] = list[index-1].Physics;
         StringGrid1->Cells[6][index] = list[index-1].Language;
         StringGrid1->Cells[7][index] = list[index-1].GPA / 100.0;
     }  

     if (list.GetSize() == 0)
     {
        ButtonDelete->Visible = false;
        Edit1->Visible = false;
        ButtonFind->Visible = false;
        EditFind->Visible = false;
        ButtonShow->Visible = false;
        Button2->Visible = false;
        Button3->Visible = false;
     }
}
//---------------------------------------------------------------------------


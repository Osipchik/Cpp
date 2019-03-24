//---------------------------------------------------------------------------

#include <windows.h>
#include <locale.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "myList.h"
#include "myList.cpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct StrudientInfo
{
   String Surname;
   String Name;
   String Patronymic;
   int Math;
   int Physics;
   int Language;
   int GPA;
} info;

List<StrudientInfo> list;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    setlocale(LC_ALL, "ru");
    StringGrid1->ColWidths[0] = 25;
    StringGrid1->Cells[0][0] = "№";
    StringGrid1->Cells[0][1] = "1";
    StringGrid1->Cells[1][0] = "Фамилия";
    StringGrid1->Cells[2][0] = "Имя";
    StringGrid1->Cells[3][0] = "Отчество";
    StringGrid1->Cells[4][0] = "Математика";
    StringGrid1->Cells[5][0] = "Физика";
    StringGrid1->Cells[6][0] = "Язык";
    StringGrid1->Cells[7][0] = "Средний балл";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
     StringGrid1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
     int row = StringGrid1->RowCount;
     StringGrid1->RowCount = row + 1;
     StringGrid1->Rows[row]->Clear();
     StringGrid1->Cells[0][row] = row;
     StringGrid1->Row++;
     StringGrid1->Col = 1;

     if (StringGrid1->RowCount > 1)
     {
        ButtonDelete->Visible = true;
        Edit1->Visible = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
     if (Edit1->Text.IsEmpty())
     {
        if (StringGrid1->RowCount != 1)
        {
           StringGrid1->RowCount -= 1;
           list.pop_back();
        }
     }
     else
     {
        int index = Edit1->Text.ToInt() - 1;
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
            StringGrid1->Cells[7][index+1] = list[index].GPA;
            index++;
        }
     }
     if (StringGrid1->RowCount == 1)
     {
        ButtonDelete->Visible = false;
        Edit1->Visible = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, wchar_t &Key)
{
     if (Key == 13)
     {
        int col = 1, row = StringGrid1->Row;
        info.Surname = StringGrid1->Cells[col][row];
        info.Name = StringGrid1->Cells[col+1][row];
        info.Patronymic = StringGrid1->Cells[col+2][row];
        info.Math = StrToInt(StringGrid1->Cells[col+3][row]);
        info.Physics = StrToInt(StringGrid1->Cells[col+4][row]);
        info.Language = StrToInt(StringGrid1->Cells[col+5][row]);
        info.GPA = ((info.Math + info.Physics + info.Language) * 100) / 3;
        StringGrid1->Cells[7][StringGrid1->Row] = info.GPA / 100.0;

        list.push_back(info);
     }
     if (Key == ' ')
     {
         if (StringGrid1->Col != StringGrid1->ColCount - 2)
            StringGrid1->Col++;
         else
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
                StringGrid1->Cells[7][1] = list[index].GPA;

                StringGrid1->RowCount = 2;
             }
         }
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     for (int index = 1; index < list.GetSize()-1 ; index++)
     {
         if (index < StringGrid1->RowCount)
         {
            StringGrid1->Cells[1][index] = list[index].Surname;
            StringGrid1->Cells[2][index] = list[index].Name;
            StringGrid1->Cells[3][index] = list[index].Patronymic;
            StringGrid1->Cells[4][index] = list[index].Math;
            StringGrid1->Cells[5][index] = list[index].Physics;
            StringGrid1->Cells[6][index] = list[index].Language;
            StringGrid1->Cells[7][index] = list[index].GPA;
         }
         else
         {
            int row = StringGrid1->RowCount;
            StringGrid1->RowCount = row + 1;
            StringGrid1->Rows[row]->Clear();
            StringGrid1->Cells[0][row] = row;

            StringGrid1->Cells[1][index] = list[index].Surname;
            StringGrid1->Cells[2][index] = list[index].Name;
            StringGrid1->Cells[3][index] = list[index].Patronymic;
            StringGrid1->Cells[4][index] = list[index].Math;
            StringGrid1->Cells[5][index] = list[index].Physics;
            StringGrid1->Cells[6][index] = list[index].Language;
            StringGrid1->Cells[7][index] = list[index].GPA;
         }
     }
}
//---------------------------------------------------------------------------


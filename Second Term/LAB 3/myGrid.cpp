//---------------------------------------------------------------------------


#pragma hdrstop

#include "myGrid.h"

//---------------------------------------------------------------------------


void myGrid::GridColumnsName(TStringGrid *StringGrid)
{
     StringGrid->ColWidths[0] = 25;
     StringGrid->Cells[0][0] = "№";
     StringGrid->Cells[0][1] = "1";
     StringGrid->Cells[1][0] = "Фамилия";
     StringGrid->Cells[2][0] = "Имя";
     StringGrid->Cells[3][0] = "Отчество";
     StringGrid->Cells[4][0] = "Математика";
     StringGrid->Cells[5][0] = "Физика";
     StringGrid->Cells[6][0] = "Язык";
     StringGrid->Cells[7][0] = "Средний балл";
}


void myGrid::AddRow(TStringGrid *StringGrid)
{
     int row = StringGrid->RowCount;
     StringGrid->RowCount = row + 1;
     StringGrid->Rows[row]->Clear();
     StringGrid->Cells[0][row] = row;
     StringGrid->Row++;
     StringGrid->Col = 1;
}


void myGrid::FillList(TStringGrid *StringGrid,  StrudientInfo &info)
{
     int col = 1, row = StringGrid->Row;
     String str;
      while(col < 7)
      {
         str = StringGrid->Cells[col][row];
         if (str.IsEmpty()) throw MyException(col, row);

         if (col > 3)
         {
           for (int i = 1; i-1 < str.Length(); i++)
               if (str[i] < '0' || str[i] > '9' || str[i] == ' ') throw MyException(col, row);
         }
         col++;
      }

     col = 1;
     info.Surname = StringGrid->Cells[col][row];
     info.Name = StringGrid->Cells[col+1][row];
     info.Patronymic = StringGrid->Cells[col+2][row];

     info.Math = StrToInt(StringGrid->Cells[col+3][row]);
     info.Physics = StrToInt(StringGrid->Cells[col+4][row]);
     info.Language = StrToInt(StringGrid->Cells[col+5][row]);
     info.GPA = ((info.Math + info.Physics + info.Language) * 100) / 3;
     StringGrid->Cells[7][StringGrid->Row] = info.GPA / 100.0;

}


#pragma package(smart_init)

//---------------------------------------------------------------------------

#ifndef MyExceptionH
#define MyExceptionH
//---------------------------------------------------------------------------

#include <exception>
#include <vcl.h>
#include "Unit1.h"

class MyException :public std::exception
{
public:
      MyException(int col, int row) : std::exception()
      {
         this->cols = col;
         this->rows = row;
      };
      MyException()
      {
      };
      void FillCell (TStringGrid *SG){ SG->Cells[cols][rows] = "0000"; };
      void FillEdit (TEdit *Edit){ Edit->Text = "0"; };
private:
      int cols;
      int rows;
};

#endif

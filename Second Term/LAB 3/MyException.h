//---------------------------------------------------------------------------

#ifndef MyExceptionH
#define MyExceptionH
//---------------------------------------------------------------------------

#include <exception>
#include <vcl.h>
#include "Unit1.h"
 //using namespace std;

class MyException :public std::exception
{
public:
      MyException(int col, int row) : std::exception()
      {
         this->cols = col;
         this->rows = row;
      };
      void FillCell(TStringGrid *SG){ SG->Cells[cols][rows] = "0000"; };
private:
      int cols;
      int rows;
};

#endif

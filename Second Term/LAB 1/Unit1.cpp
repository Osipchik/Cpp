//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include "DrawRectangle.h"
#include "DrawTreangle.h"
#include "DrawPolygon.h"
#include "DrawCircle.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   DrawRect R;
   R.Rectangle(Form1, EditX1, EditY1, EditX2, EditY2, EditX0, EditY0, EditScale, SetTime, EditR, LabelSquare, LabelPerimeter);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   DrawTreangle T;
   T.Treangle(Form1, EditX1, EditY1, EditX2, EditY2, EditX3, EditY3, EditX0, EditY0, EditScale,
   SetTime, EditR, LabelSquare, LabelPerimeter);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    int N = EditN->Text.ToInt();
    DrawPol P(N);
    P.Polygon(EditN, Form1, EditX0, EditY0, EditR, EditMoveToX, EditMoveToY, SetTime, EditScale, LabelSquare, LabelPerimeter);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    DrawCircle C;
    C.Circle(Form1, EditX1, EditY1, EditX2, EditY2, EditScale, SetTime, EditR, EditX0, EditY0, LabelSquare, LabelPerimeter);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "SaveFIle.h"
#include "OrderArray.h"
#include "SortMemo.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

OrderArray *OArray;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
__fastcall TForm1::~TForm1()
{
   delete[] OArray;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
     SaveFile *Saves = new SaveFile();
     Saves->Save(Memo1, SaveDialog1);
     delete Saves;
     ComboBox1->Items->Clear();
     //delete[] OArray;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
     OArray[ComboBox1->ItemIndex].ShowOrderFile(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
     String FName = OpenDialog1->FileName;
     if (OpenDialog1->Execute()) Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
     int MemoCount = Memo1->Lines->Count;

     ComboBox1->Items->Clear();

     OArray = new OrderArray[MemoCount];
     if (Memo1->Lines->Count > 1)
        for (int i = 0; i < MemoCount; i++)
        {
            OArray[i].LoadInfo(Memo1, i);
            OArray[i].AddComboItems(ComboBox1);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
     Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
     SortMemo sort;
     if (ComboBox2->ItemIndex == 0) sort.ShowA(Memo1);
     if (ComboBox2->ItemIndex == 1) sort.ShowC(Memo1);
     if (ComboBox2->ItemIndex == 2) sort.ShowAm(Memo1);
     if (ComboBox2->ItemIndex == 3) sort.ShowCm(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
     Memo1->Lines->Add(EditOrder->Text + ' ' + EditData->Text + ' ' + EditInfo->Text);

     delete[] OArray;

     ComboBox1->Items->Clear();
     int MemoCount = Memo1->Lines->Count;
     OArray = new OrderArray[MemoCount];
     if (Memo1->Lines->Count > 1)
        for (int i = 0; i < MemoCount; i++)
        {
            OArray[i].LoadInfo(Memo1, i);
            OArray[i].AddComboItems(ComboBox1);
        }
}
//---------------------------------------------------------------------------


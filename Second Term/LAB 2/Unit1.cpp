//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Array.h"
#include "OpenFile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonLoadClick(TObject *Sender)
{
     if (OpenDialog1->Execute())
     {
        Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
        ComboBox1->Items->Clear();
        Array arr;
        int count = Memo1->Lines->Count;
        for (int i = 0; i < count; i++)
        {
            arr.Add(Memo1->Lines->Strings[i], "Price list", 0, 1);
            ComboBox1->Items->Add(arr.Show(i, 1));
        }

        Label3->Visible = true; Label3->Caption = "Code:";
        Label4->Visible = true; Label4->Caption = "Data:";
        Label5->Visible = true; Label5->Caption = "Info:";
        Edit1->Visible = true;
        Edit2->Visible = true;
        Edit3->Visible = true;
        ButtonAdd->Visible = true;
     }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    if (FileExists(ComboBox1->Text + ".txt"))
    {
        Label2->Visible = true;
        ComboBox2->Visible = true;
        ButtonSave->Visible = true;
        Label6->Visible = true;
        Edit4->Visible = true;
        Label3->Visible = true; Label3->Caption = "Code:";
        Label4->Visible = true; Label4->Caption = "Amount:";
        Label5->Visible = true; Label5->Caption = "Coast:";
        Label6->Visible = true; Label6->Caption = "Name:";
        Edit1->Visible = true;
        Edit2->Visible = true;
        Edit3->Visible = true;
        Edit4->Visible = true;
        ButtonAdd->Visible = true;
        ButtonSave->Visible = true;

        Array arr;
        Memo1->Lines->Clear();
        OpenFiles open;

        TStringList *OrderList = open.OpenF(ComboBox1->Text);
        TStringList *PriceList = open.OpenF("Price list");
        OrderList->Delete(0);

        int count = OrderList->Count - 1;
        for (int i = 0; i <= count; i++)
        {
          arr.Add(OrderList->Strings[i], "Price list");
          Memo1->Lines->Add(IntToStr(i+1) + "." + '\t' + arr.Show(i));
        }
        delete OrderList;
        delete PriceList;
    }
    else
    {
        wchar_t message[] = L"File does not exist";
        wchar_t tytle[] = L"Error";
        Application->MessageBoxW(message, tytle, MB_ICONWARNING) == IDYES;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSaveClick(TObject *Sender)
{
     int Price = 0;
     Array arr;
     int count = Memo1->Lines->Count;
     for (int i = 0; i < count; i++)
         arr.Add(Memo1->Lines->Strings[i], "", 3);

     if (SaveDialog1->Execute())
     {
        Memo1->Lines->Insert(0, " Total price: " + IntToStr(arr.Price()));
        Memo1->Lines->SaveToFile(SaveDialog1->FileName);
        Memo1->Lines->Delete(0);
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonClearClick(TObject *Sender)
{
    Memo1->Lines->Clear();
    Label2->Visible = false;
    ComboBox2->Visible = false;
    ButtonSave->Visible = false;

    Label3->Visible = false;
    Label4->Visible = false;
    Label5->Visible = false;
    Label6->Visible = false;
    Edit1->Visible = false;
    Edit2->Visible = false;
    Edit3->Visible = false;
    Edit4->Visible = false;
    ButtonAdd->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
     Array arr;
     int count = Memo1->Lines->Count;
     for (int i = 0; i < count; i++)
         arr.Add(Memo1->Lines->Strings[i], "", 3);

     switch (ComboBox2->ItemIndex)
     {
        case 0:
        {
           arr.qSort(0, Memo1->Lines->Count - 1);
           arr.reverce();
           break;
        }
        case 1:
        {
           arr.qSort(0, Memo1->Lines->Count - 1);
           break;
        }
        case 2:
        {
           arr.qSort(0, Memo1->Lines->Count - 1, 0);
           arr.reverce();
           break;
        }
        case 3:
        {
           arr.qSort(0, Memo1->Lines->Count - 1, 0);
           break;
        }
     }

     Memo1->Lines->Clear();
     for (int i = 0; i < count; i++)
         Memo1->Lines->Add(IntToStr(i+1) + "." + '\t' + arr.Show(i));
}
//---------------------------------------------------------------------------
Array array;
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
     if (Label5->Caption == "Info:")
     {
        if (Edit1->Text != "" && Edit2->Text != "" && Edit3->Text != "")
        {
           Memo1->Lines->Add(Edit1->Text + " " + Edit2->Text + " " + Edit3->Text);
           ComboBox1->Items->Add(Edit1->Text);
        }
     }
     else
     {
        if (Edit1->Text != "" && Edit2->Text != 0 && Edit3->Text != 0 && Edit4->Text != "")
        {
           int i = 1 + StrToInt(Memo1->Lines->Strings[Memo1->Lines->Count - 1][1]);
           int amount = 0, coast = 0;

           try
           {
              amount = Edit2->Text.ToInt();
              coast = Edit3->Text.ToInt();
           }
           catch(...)
           {
           }
           Memo1->Lines->Add(IntToStr(i) + "." + '\t' + Edit1->Text + '\t' + '\t' + amount + '\t' + coast + '\t' + Edit4->Text);
           int count = Memo1->Lines->Count;
           if (array.GetSize() != 0 ) array.Add(Memo1->Lines->Strings[count-1], "", 3);
           else
           {
              for (int i = 0; i < count; i++)
                  array.Add(Memo1->Lines->Strings[i], "", 3);
           }
        }
     }
     Edit1->Text = "";
     Edit2->Text = "";
     Edit3->Text = "";
     Edit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
     int count = Memo1->Lines->Count;

     try
     {
        int index = Edit5->Text.ToInt() - 1;
        if (array.GetSize() == 0)
        {
           for (int i = 0; i < index; i++)
               array.Add(Memo1->Lines->Strings[i], "", 3);
           for (int i = index + 1; i < count; i++)
               array.Add(Memo1->Lines->Strings[i], "", 3);
        }
        else array.remove(index);

        Memo1->Lines->Clear();
        for (int i = 0; i < count - 1; i++)
            Memo1->Lines->Add(IntToStr(i+1) + "." + '\t' + array.Show(i));
     }
     catch(...)
     {
     }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     Memo1->Lines->Clear();
     for (int i = 0; i < array.GetSize(); i++)
     {
         Memo1->Lines->Add(IntToStr(i+1) + "." + '\t' + array.Show(i));
     }
}
//---------------------------------------------------------------------------


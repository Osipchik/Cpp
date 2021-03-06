//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *ButtonLoad;
	TOpenDialog *OpenDialog1;
	TComboBox *ComboBox1;
	TButton *ButtonSave;
	TSaveDialog *SaveDialog1;
	TLabel *Label1;
	TComboBox *ComboBox2;
	TLabel *Label2;
	TButton *ButtonClear;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *ButtonAdd;
	TEdit *Edit4;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button3;
	TEdit *Edit5;
	TButton *Button1;
	void __fastcall ButtonLoadClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

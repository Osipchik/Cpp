//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TButton *ButtonAdd;
	TButton *ButtonDelete;
	TEdit *Edit1;
	TButton *ButtonFind;
	TEdit *EditFind;
	TButton *ButtonShow;
	TButton *Button2;
	TButton *Button3;
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall StringGrid1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ButtonFindClick(TObject *Sender);
	void __fastcall ButtonShowClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

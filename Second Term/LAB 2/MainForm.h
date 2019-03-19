//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *Button1;
	TSaveDialog *SaveDialog1;
	TButton *Button2;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TOpenDialog *OpenDialog1;
	TButton *Button3;
	TComboBox *ComboBox2;
	TLabel *Label2;
	TButton *Button4;
	TEdit *EditOrder;
	TEdit *EditData;
	TEdit *EditInfo;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TBevel *Bevel1;
	TBevel *Bevel2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
        __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 446
  ClientWidth = 601
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 141
    Top = 70
    Width = 41
    Height = 24
    AutoSize = False
    Caption = 'Orders'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Label2: TLabel
    Left = 36
    Top = 70
    Width = 57
    Height = 24
    AutoSize = False
    Caption = 'Sort by'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Label3: TLabel
    Left = 33
    Top = 198
    Width = 41
    Height = 24
    AutoSize = False
    Caption = 'Orders'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Label4: TLabel
    Left = 33
    Top = 228
    Width = 41
    Height = 24
    AutoSize = False
    Caption = 'Data'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Label5: TLabel
    Left = 33
    Top = 258
    Width = 41
    Height = 24
    AutoSize = False
    Caption = 'Info'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 218
    Height = 121
  end
  object Bevel2: TBevel
    Left = 8
    Top = 156
    Width = 218
    Height = 145
    Shape = bsFrame
  end
  object Memo1: TMemo
    Left = 239
    Top = 8
    Width = 354
    Height = 428
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button1: TButton
    Left = 16
    Top = 23
    Width = 97
    Height = 28
    Caption = ' Save File'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 119
    Top = 23
    Width = 97
    Height = 28
    Caption = 'Load File'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 119
    Top = 94
    Width = 97
    Height = 22
    Style = csOwnerDrawFixed
    TabOrder = 3
    OnChange = ComboBox1Change
  end
  object Button3: TButton
    Left = 72
    Top = 343
    Width = 97
    Height = 32
    Caption = 'Clear list'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
  object ComboBox2: TComboBox
    Left = 16
    Top = 94
    Width = 97
    Height = 22
    Style = csOwnerDrawFixed
    TabOrder = 5
    OnChange = ComboBox2Change
    Items.Strings = (
      'amount max'
      'coast max'
      'amount min'
      'coast min')
  end
  object Button4: TButton
    Left = 25
    Top = 164
    Width = 176
    Height = 28
    Caption = 'Add to list'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = Button4Click
  end
  object EditOrder: TEdit
    Left = 80
    Top = 198
    Width = 121
    Height = 26
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
  end
  object EditData: TEdit
    Left = 80
    Top = 230
    Width = 121
    Height = 26
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
  end
  object EditInfo: TEdit
    Left = 80
    Top = 262
    Width = 121
    Height = 26
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.doc'
    Filter = 'Text Files(*.txt)|*.txt|.doc|*.doc'
    Left = 88
    Top = 400
  end
  object OpenDialog1: TOpenDialog
    Left = 24
    Top = 400
  end
end

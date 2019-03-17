object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 444
  ClientWidth = 697
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
    Left = 64
    Top = 82
    Width = 41
    Height = 24
    AutoSize = False
    Caption = 'Files'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Memo1: TMemo
    Left = 176
    Top = 8
    Width = 521
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
    Left = 8
    Top = 272
    Width = 153
    Height = 25
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
    Left = 8
    Top = 52
    Width = 153
    Height = 25
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
    Left = 8
    Top = 104
    Width = 153
    Height = 22
    Style = csOwnerDrawFixed
    TabOrder = 3
    OnChange = ComboBox1Change
  end
  object Button3: TButton
    Left = 48
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Clerar'
    TabOrder = 4
    OnClick = Button3Click
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.doc'
    Filter = 'Text Files(*.txt)|*.txt|.doc|*.doc'
    Left = 72
    Top = 304
  end
  object OpenDialog1: TOpenDialog
    Left = 64
    Top = 8
  end
end

object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 452
  ClientWidth = 746
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 8
    Top = 35
    Width = 596
    Height = 217
    ColCount = 8
    DefaultColWidth = 80
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing, goEditing]
    TabOrder = 0
    Touch.ParentTabletOptions = False
    Touch.TabletOptions = [toPressAndHold, toTouchUIForceOn]
    OnClick = StringGrid1Click
    OnKeyPress = StringGrid1KeyPress
  end
  object ButtonAdd: TButton
    Left = 368
    Top = 334
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = ButtonAddClick
  end
  object ButtonDelete: TButton
    Left = 496
    Top = 336
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 2
    OnClick = ButtonDeleteClick
  end
  object Edit1: TEdit
    Left = 600
    Top = 338
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Memo1: TMemo
    Left = 24
    Top = 304
    Width = 313
    Height = 140
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object ButtonFind: TButton
    Left = 24
    Top = 8
    Width = 75
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 5
    OnClick = ButtonFindClick
  end
  object EditFind: TEdit
    Left = 105
    Top = 8
    Width = 81
    Height = 21
    TabOrder = 6
  end
  object Button1: TButton
    Left = 408
    Top = 288
    Width = 99
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1089#1087#1080#1089#1086#1082
    TabOrder = 7
    OnClick = Button1Click
  end
end

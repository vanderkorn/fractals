object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1043#1077#1086#1084#1077#1090#1088#1080#1095#1077#1089#1082#1080#1077' '#1092#1088#1072#1082#1090#1072#1083#1099
  ClientHeight = 515
  ClientWidth = 714
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ImageFract: TImage
    Left = 8
    Top = 8
    Width = 500
    Height = 500
  end
  object ButtonGo: TButton
    Left = 514
    Top = 474
    Width = 193
    Height = 33
    Caption = #1053#1072#1088#1080#1089#1086#1074#1072#1090#1100' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonGoClick
  end
  object ComboBoxFract: TComboBox
    Left = 515
    Top = 437
    Width = 193
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 23
    ParentFont = False
    TabOrder = 1
    Text = #1051#1080#1085#1080#1103' '#1050#1086#1093#1072' '#1048#1090#1077#1088#1072#1090'.'
    Items.Strings = (
      #1051#1080#1085#1080#1103' '#1050#1086#1093#1072' '#1048#1090#1077#1088#1072#1090'.'
      #1051#1080#1085#1080#1103' '#1050#1086#1093#1072' '#1056#1077#1082#1091#1088#1089'.'
      #1042#1077#1090#1074#1100' '#1055#1072#1087#1086#1088#1086#1090#1085#1080#1082#1072
      #1044#1088#1072#1082#1086#1085' '#1061#1072#1088#1090#1077#1088#1072'-'#1061#1077#1081#1090#1091#1101#1103)
  end
  object EditIter: TEdit
    Left = 514
    Top = 400
    Width = 167
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = '0'
  end
  object UpDown1: TUpDown
    Left = 681
    Top = 400
    Width = 30
    Height = 31
    Associate = EditIter
    Max = 1000
    TabOrder = 3
  end
end

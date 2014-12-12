object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1060#1088#1072#1082#1090#1072#1083#1099
  ClientHeight = 384
  ClientWidth = 581
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
    Left = 13
    Top = 8
    Width = 400
    Height = 300
    OnMouseDown = ImageFractMouseDown
    OnMouseMove = ImageFractMouseMove
    OnMouseUp = ImageFractMouseUp
  end
  object ButtonPusk: TButton
    Left = 419
    Top = 275
    Width = 154
    Height = 33
    Caption = #1055#1091#1089#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonPuskClick
  end
  object ComboBoxType: TComboBox
    Left = 419
    Top = 227
    Width = 154
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 23
    ItemIndex = 0
    ParentFont = False
    TabOrder = 1
    Text = #1052#1072#1085#1076#1077#1083#1100#1073#1088#1086#1090
    Items.Strings = (
      #1052#1072#1085#1076#1077#1083#1100#1073#1088#1086#1090
      #1046#1091#1083#1080#1072
      #1053#1100#1102#1090#1086#1085)
  end
  object EditMaxIter: TEdit
    Left = 419
    Top = 177
    Width = 130
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = '50'
  end
  object UpDownMaxIter: TUpDown
    Left = 549
    Top = 177
    Width = 24
    Height = 31
    Associate = EditMaxIter
    Max = 1000
    Position = 50
    TabOrder = 3
  end
end

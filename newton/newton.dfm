object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1060#1088#1072#1082#1090#1072#1083' '#1053#1100#1102#1090#1086#1085#1072
  ClientHeight = 488
  ClientWidth = 853
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object ImageFract: TImage
    Left = 8
    Top = 8
    Width = 400
    Height = 300
    OnMouseDown = ImageFractMouseDown
    OnMouseMove = ImageFractMouseMove
    OnMouseUp = ImageFractMouseUp
  end
  object ImageFract2: TImage
    Left = 414
    Top = 8
    Width = 400
    Height = 300
    OnMouseDown = ImageFract2MouseDown
    OnMouseMove = ImageFract2MouseMove
    OnMouseUp = ImageFract2MouseUp
  end
  object ImageFract3: TImage
    Left = 8
    Top = 314
    Width = 400
    Height = 300
    OnMouseDown = ImageFract3MouseDown
    OnMouseMove = ImageFract3MouseMove
    OnMouseUp = ImageFract3MouseUp
  end
  object EditMaxIter: TEdit
    Left = 454
    Top = 330
    Width = 123
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '20'
  end
  object UpDown1: TUpDown
    Left = 577
    Top = 330
    Width = 26
    Height = 31
    Associate = EditMaxIter
    Max = 1000
    Position = 20
    TabOrder = 1
  end
  object Button1: TButton
    Left = 454
    Top = 392
    Width = 144
    Height = 33
    Caption = #1053#1072#1088#1080#1089#1086#1074#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object RadioGroup: TRadioGroup
    Left = 690
    Top = 330
    Width = 124
    Height = 95
    Caption = 'i*i=?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      '-1'
      '0'
      '1')
    ParentFont = False
    TabOrder = 3
  end
end

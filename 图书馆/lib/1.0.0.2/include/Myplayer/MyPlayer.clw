; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyPlayerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyPlayer.h"

ClassCount=4
Class1=CMyPlayerApp
Class2=CMyPlayerDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_MYPLAYER_DIALOG
Class4=CMyDlgAbout
Resource3=IDD_DIALOG1
Resource4=IDR_MENU1

[CLS:CMyPlayerApp]
Type=0
HeaderFile=MyPlayer.h
ImplementationFile=MyPlayer.cpp
Filter=N

[CLS:CMyPlayerDlg]
Type=0
HeaderFile=MyPlayerDlg.h
ImplementationFile=MyPlayerDlg.cpp
Filter=D
LastObject=ID_MENUITEMOpen
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MyPlayerDlg.h
ImplementationFile=MyPlayerDlg.cpp
Filter=D

[DLG:IDD_MYPLAYER_DIALOG]
Type=1
Class=CMyPlayerDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_FULLY,button,1342242817
Control3=IDC_VOLUME_ADD,button,1342242817
Control4=IDC_VOLUME_REDUCE,button,1342242817
Control5=IDC_VOLUME_MUTE,button,1342242817
Control6=IDC_ACTIVEMOVIECONTROL1,{05589FA1-C356-11CE-BF01-00AA0055595A},1342242816
Control7=IDC_EDIT1,edit,1350633600
Control8=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG1]
Type=1
Class=CMyDlgAbout
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177294
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287

[CLS:CMyDlgAbout]
Type=0
HeaderFile=MyDlgAbout.h
ImplementationFile=MyDlgAbout.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUITEM32771
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEMOpen
Command2=ID_MENUITEMExit
Command3=ID_MENUITEMFull
Command4=ID_MENUITEMAdd
Command5=ID_MENUITEMDelete
Command6=ID_MENUITEMW
Command7=ID_MENUITEMAbout
CommandCount=7


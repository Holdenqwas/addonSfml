/*************************************************************************\
*                                                                         *
* ������� ��������������� ����������� ������������� ������������ �������  *
*   "�����" ��� Windows                                                   *
* HelloExe.cpp - ������ ���������, ���������� � �������� ������ �����     *
* ����: C++ (Microsoft Visual C++)                                        *
*                                                                         *
* ����������� � �������� ������� ������ ������������ �����������,         *
*                                                                         *
\*************************************************************************/

#include <windows.h>
#include <commdlg.h>
#include <stdio.h>
#include <time.h>
#include "DSAPI.h"
#include "DSExt.h"

HWND MainHWnd = NULL;

// �������� �� ������������ ��� ����� WS ��� ������
bool GetSaveWSFile(char *Result){
	OPENFILENAME ofn;
	bool Res;
	strcpy(Result,"");
	ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = MainHWnd;
	ofn.hInstance = NULL;
    ofn.lpstrFilter ="����� WS (*.ws)\000*.ws\000��� ����� (*.*)\000*.*\000\000";
    ofn.lpstrCustomFilter = NULL;
    ofn.nMaxCustFilter = 0;
    ofn.nFilterIndex = 0;
    ofn.lpstrFile = Result;
    ofn.nMaxFile = 256;
    ofn.lpstrFileTitle = NULL; 
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.lpstrTitle = "�������� ���� ������� ������� ��� ������";
    ofn.Flags = OFN_HIDEREADONLY;
    ofn.nFileOffset = 0;
    ofn.nFileExtension = 0; 
    ofn.lpstrDefExt = "WS";
    ofn.lCustData = 0;
    ofn.lpfnHook = NULL;
    ofn.lpTemplateName = NULL; 
	Res = GetSaveFileName(&ofn) ? true : false;
	return Res;
}

/* ������ �������� ������ ����������� ������ (���-�� �������� ���� � �����
   ���������, ��������� � ���� ������ ��� ����������� �������). �������
   CreateCurveData ������ ����������� ������ �� ������ ��� � ����������
   �������������, ��������� ��������� PCURVE �� ����� ��������� ��������
   WSIGF.RES. ������ ������������� �������� ��� �������, ��������� ������
   � ����������� ��� ������ ���� �� �������, ����������� ���������� ������
   ������ (� ������� ����� �������).
     Method - ����� ���
     Roof - ������
     Sole - �������
     Step - ��� ������������� (������ ���� ������ ����!)
     hObj - ��������� �� ����������, � ������� ��������� ��������� Handle 
            ������ */
bool CreateCurveData(const char *Method, long Roof, long Sole, long Step, OType *hObj)
{
  /* ��������� ��������� �������� ������� ����� */
  char SystemResFileName[MAX_PATH+1];
  GetAlgPath(SystemResFileName,MAX_PATH);
  strcat(SystemResFileName,"WSIGF.RES");
  /* �������� ������ �� ������� ��� ����������� ������ */
  if (ObjTDInit(SystemResFileName,"PCURVE",hObj)) return false;
  PutFieldString(*hObj,MGIS,Method); // ������ ������ ������
  /* ������������� ���������� � ���� "��������" ������������� ���������,
     ��������� ������ */
  PutFieldString(*hObj,"��������","FXC-PNG Hello"); // ����. 25 ��������
  OType hArr = hNil;
  GetArrayByName(&hArr,"",*hObj);
  SetField(*hObj,hArr,Roof,Sole,Step);
  DoneHandle(&hArr);
  return true;
} // CreateCurveData

/* ������ �������� ����������� ������. ������� CreateLayerData
   ������ ����������� ������ ������ �� ������ ���, ������ � �������,
   ��������� ��������� HCURVE �� ����� ��������� �������� WSIGF.RES.
     Method - ����� ���
     Roof - ������
     Sole - �������
     hObj - ��������� �� ����������, � ������� ��������� ��������� Handle 
            ������ */
bool CreateLayerData(const char *Method, long Roof, long Sole, OType *hObj)
{
  /* ��������� ��������� �������� ������� ����� */
  char SystemResFileName[MAX_PATH+1];
  GetAlgPath(SystemResFileName,MAX_PATH);
  strcat(SystemResFileName,"WSIGF.RES");
  /* �������� ������ �� ������� ��� ����������� ������ */
  if (ObjTDInit(SystemResFileName,"HCURVE"/*"���������"*/,hObj)) return false;
  PutFieldString(*hObj,MGIS,Method); // ������ ������ ������
  //PutFieldString(*hObj,"�������������",Method); - ��� ������� "���������" 
  /* ������������� ���������� � ���� "��������" ������������� ���������,
     ��������� ������ */
  PutFieldString(*hObj,"��������","FXC-PNG Hello"); // ����. 25 ��������
  OType hArr = hNil;
  GetArrayByName(&hArr,"",*hObj);
  SetField(*hObj,hArr,Roof,Sole,0);
  DoneHandle(&hArr);
  return true;
} // CreateLayerData

/* ���������� �������� ������ ������ � ������� PCURVE ���������� WS-����� */
void SaveTestData(const char *FileName)
{
  OType hObj;
  long Roof = 140000; // ������ - 1400.00 �
  long Sole = 150000; // ������� - 1500.00 �
  long Step = 20; // ��� ������������� - 0.2 �
  if (CreateCurveData("��������, T1",140000,150000,20,&hObj))
  {
    srand( (unsigned)time( NULL ) );
    OType hArr;
	GetArrayByName(&hArr,"",hObj);
	/* ���������� ������ ������ */
	for (int i = 0; i <= (Sole-Roof)/Step; i++)
	{
	  ArrayPutSingleColumnData(hArr,1,i,(float)0.0001*rand()*rand());
	}
	DoneHandle(&hArr);
	/* ���������� ������ */
	int ErrCode = Save_WS("PCURVE","PCURVE",FileName,false,hObj);
	if (ErrCode)
	{
	  char Msg[255];
	  sprintf(Msg,"������� Save_WS ���������� ��� ������ %d",ErrCode);
      MessageBox(0,
        Msg,
        "���������� ������� SaveTestData", 
        MB_OK | MB_ICONERROR | MB_TASKMODAL);
	}
	else
	{
      MessageBox(0,
        "�������� ���������� ������",
        "���������� ������� SaveTestData", 
        MB_OK | MB_ICONERROR | MB_TASKMODAL);
	}
    DoneHandle(&hObj);
  }
} // SaveTestData

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow )
{
  if (!DSExtLoad())
  {
    return -1;
  }
  char WorkSpace[256];
  // ������ ����� ����� ��� ������
  if (!GetSaveWSFile(WorkSpace))
  {
    return -2;
  }
  SaveTestData(WorkSpace);
  DSExtFree();
  return 0;
}
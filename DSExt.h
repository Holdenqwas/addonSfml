/***************************************************************************\
*                                                                           *
* ������� ��������������� ����������� ������������� ������������ �������    *
*   "�����" ��� Windows                                                     *
* ���������� ���������� ������� ������� ������                              *
* ����: C++                                                                 *
* ������: 1.12                                                              *
* (C) ��� ������, 1999 - 2009                                               *
*                                                                           *
\***************************************************************************/

#ifndef _DSEXT_
#define _DSEXT_
#include <windows.h>
#include "DSAPI.h"

#ifdef _MSC_VER
  /* Microsoft Visual C++ */
  #pragma pack( push, ENTER_DSEXT, 1 )
#else
  #ifdef __BORLANDC__
    // Borland C++ or Builder
    #if __BCPLUSPLUS__ > 0x520
      // Builder
      #pragma option push -a1 -VF
    #else
      // Borland C++
      #pragma option -a1 -VF
    #endif
  #else
    /* What else??? */
    #pragma option -a1 -VF
  #endif
#endif

#ifndef _LONGBOOL_
#define _LONGBOOL_
typedef long LongBoolean;
#endif

/*****************************************************************************\
*                                                                             *
*    ��������� ������������                                                   *
*                                                                             *
\*****************************************************************************/

/*****************************************************************************\
* ���������                                                                   *
\*****************************************************************************/

extern char *DepthString; /* �������� ������� ������ � ������� */
extern char *DepthUnit;   /* ������� ��������� ������ � ������� */
extern char *DepthShift;  /* �������� ���� ��� ���������� ������ �� ������� */

/* ����� ��� CreateLayerCurve */
const long clcSrcBed         = 0x00000001; /* �������� ������ - ����������� */
const long clcTranslateFirst = 0x00000002; /* ������� �������������� */
const long clcUniteEqual     = 0x00000004; /* ���������� ������ � ����������� ������ */


/* ��������� � ���� ��� �������������� ������� */

typedef void* TTwoDWindow; /* ���� �������������� ������� */

const int hgMaxArrCols = 32; /* ����. ���������� ������� �������,
                                ������� ����� ���� ���������� */
const int hgMaxFontNameLen = 64; /* ������ ������, ��������� ��� �������� ������ */
const long hgAllCols = 0xFFFFFFFF; /* ����� ��� ����������� ���� ������� */

/* ����� ����������� ������� � �������������� ������� */
const long hgafCommonNet        = 0x00000001; /* ����� ����� ��� ���� ������ */
const long hgafDrawAxes         = 0x00000002; /* �������� ����� ����� */
const long hgafDrawLabels       = 0x00000004; /* �������� ����� */
const long hgafDisableArgLabels = 0x00000008; /* �� �������� ����� ��������� */
const long hgafUseArgParams     = 0x00000010; /* ������ ��������� �������������
                                                 ��������� ������� */
const long hgafUseFuncParams    = 0x00000020; /* ������ ��������� �������������
                                                 ������� ������� */

typedef long TCols; /* ����� ���������� ������� ������� */

typedef struct {
        long Index;
        long Number;
        char abReserved1[3];
        char bColor;
        char PtType;
        char PtSize;
        char LineSize;
        long LabelWidth;
        long LabelDec;
        long LinesCount;
        RECT GraphRect;
        float MinValue;
        float MaxValue;
        float StartValue;
        float EndValue;
        float PixelsPerUnit;
        char abReserved2[512];
} TColParams, *PColParams;

typedef char THGColorDepth;

const THGColorDepth hgcdMono  = 0;
const THGColorDepth hgcd4bit  = 1;
const THGColorDepth hgcd8bit  = 2;
const THGColorDepth hgcd16bit = 3;
const THGColorDepth hgcd24bit = 4;

typedef struct {
        char Name[hgMaxFontNameLen+1];
        long Height;
        char abReserved[256];
} THGrFontParam, *PHGrFontParam;

typedef struct {
        long Width;
        long Height;
        float ArgMin;
        float ArgMax;
        long ArgLinesCount;
        THGColorDepth ColorDepth;
        THGrFontParam TitleFont;
        THGrFontParam LegendFont;
        THGrFontParam GraphFont;
        char abReserved1[3];
        char BGColor;
        char abReserved2[3];
        char GraphBGColor;
        TCols SelectedCols;
        long Flags;

        long AreaStartIndex;
        long AreaEndIndex;
        TColParams ArgParams;
        long FuncParamCount;
        TColParams FuncParams[hgMaxArrCols];
        TColParams WholeArgParams;
        TColParams WholeFuncParams;

        char Title[1025];
        long KeyStrLen;
        long LeftMargin;
        long RightMargin;
        float BlankValue;
        float GlobalFuncMin;
        float GlobalFuncMax;
        long GlobalFuncLinesCount;
        char SubstParams[4097];
        char abReserved3[1025];
} THGraphAreaRec, *PHGraphAreaRec;

/*****************************************************************************\
* CALLBACK - �������                                                          *
\*****************************************************************************/

/* ��� �������������� ������� */

typedef LongBoolean (__stdcall *TTwoDCloseWindowCallback)(TTwoDWindow Window, long dwCookie);
typedef LongBoolean (__stdcall *TTwoDCloseControlWindowCallback)(long dwCookie);

/* ������ */

typedef void (__stdcall *PProcess)(long Min, long Val, long Max);
typedef float (__stdcall *TTransform)(float Y);
typedef float(__stdcall *TArgTransform)(float X, float Y);
typedef float (__stdcall *TWinTransform)(float *X, long XLastIndex, float *Y, long YLastIndex, unsigned short Count, unsigned short Index);
typedef void (__stdcall *TStartTransform)();
typedef void (__stdcall *TCrvTransform)(float X);
typedef float (__stdcall *TGetTransform)();

// ����������� ������� ��������� �������, � ������� �������� ����������
typedef unsigned char TMinimalDepthUnit;

const TMinimalDepthUnit mduUnknown  = 0; // ����������
const TMinimalDepthUnit mduCm       = 1; // ���������� (�� ���������)
const TMinimalDepthUnit mduPU       = 2; // ������� ���� ����������
const TMinimalDepthUnit mduInch     = 3; // �����
const TMinimalDepthUnit mduHalfInch = 4; // ���������

// ���������������� ������� ��������� �������
typedef unsigned char TUserDepthUnit;

const TUserDepthUnit uduUnknown = 0; // ����������
const TUserDepthUnit uduMeter   = 1; // ����� (�� ���������)
const TUserDepthUnit uduFoot    = 2; // ����
const TUserDepthUnit uduInch    = 3; // �����
const TUserDepthUnit uduYard    = 4; // ����

/*****************************************************************************\
* �������� � ������� �������                                                  *
\*****************************************************************************/

/* ��������� ������*/
extern "C" LongBoolean DSExtLoad(void);

/* ������������ � ������ ��� ������������ � �������� ������������ �������� */
extern "C" LongBoolean DSExtConnect(void);

/* ��������� ������. �� ����� ��������, ���� DSExt �������� ������� DSExtConnect */
extern "C" void DSExtFree(void);

/*****************************************************************************\
* ������ ��������                                                             *
\*****************************************************************************/

/* ��������-��������� - �������� HINSTANCE ��������� */
HINSTANCE GetAlgHandle();
/* ��������-��������� - �������� ������� ��������� (DLL) */
long GetAlgPath(char *Path, long MaxLen);
/* ��������-��������� - �������� ������� ������� (EXE) */
long GetSystemPath(char *Path, long MaxLen);
/* ��������-��������� - ������ ������ ���� ���� ������ */
void SetMainWndHandle(HWND WndHandle);

/* �������� �������� �������� ������� ��� long � ���������� R
   �� Handl'� ������� A, ������� Index � ����� ������� ColName
   ���������� true, ���� ��� ������ � �������� �������� ������� �� ����� */
LongBoolean GetNBALongInt(OType A, long Index, const char *ColName, long *R);

/* �� ��, �� �������� ������ ��� float */
LongBoolean GetNBASingle(OType A, long Index, const char *ColName, float *R);

/* �� ��, �� �������� ������ ��� ������ (��� R ������ ���� �������� 256 ����) */
LongBoolean GetNBAString(OType A, long Index, const char *ColName, char *R);

/* �� �� ������ �������, �� �������� ������� �� ���� Name ������ � Handl'�� A */
LongBoolean GetNBFLongInt(OType A, const char *Name, long *R);
LongBoolean GetNBFSingle(OType A, const char *Name, float *R);
LongBoolean GetNBFString(OType A, const char *Name, char *R);
LongBoolean GetNBFStringLong(OType A, const char *Name, char *R, long RSize);

/* �� �� 6 �������, �� �������� ������������ � ������ */
void PutArrayLongInt(OType A, long Index, const char *ColName, long V);
void xPutArraySingle(OType A, long Index, const char *ColName, float V);
void xPutArrayString(OType A, long Index, const char *ColName, const char *V);
void PutFieldLongInt(OType A, const char *Name, long V);
void PutFieldSingle(OType A, const char *Name, float V);
void PutFieldString(OType A, const char *Name, const char *V);

/* ������ �������� ���� �� ��� ������� � ������ (� �� �� �����) */
void PutFieldLongIntI(OType A, long Index, long V);
void PutFieldSingleI(OType A, long Index, float V);
void PutFieldStringI(OType A, long Index, const char *V);

/* �������� ���������� � ������ �� Handl'�� ������ � ������� � ���� ������:
   (������� � ���� ������ DatServ, � �� ������ ��������!)
   Column - ����� (�� 1) ������� ������ (���� ����, ����� 0)
   Step - ��� ������������� � �� (���� ���� � ���������)
   (�� ������� ���� ���� �� ���� ���������� ������ ���������
   � ������������� ���������, ����� ������ ������������)
   Roof, Sole - ������ � ������� � �� */
long GetCurveInformation(OType DataHandle, OType ArrayHandle,
                             unsigned char *Column,
                             long *Step, long *Roof, long *Sole);

/* ���������� � KeyStrLong (����� ������ ����� �� ����� 256 ����) ������
   �������� ����� ������, ���������� Handl'�� DataHandle. � ������ �������
   (��� ���������� �������� �����) ������������ EmptyStr */
void DataKeyStrLong(const char *EmptyStr, OType DataHandle,
                    unsigned short RowNumber, char *KeyStrLong);

/* ���������� ����� ����� � ������� �������, �������������� ���������� �������� */
//long GetValueIndex(OType ArrayHandle, unsigned char Column, float Value);

/* �� �� ����� - ����������� �������, �� ������ ��� ���������� �������� */
//long GetMonValueIndex(OType ArrayHandle, unsigned char Column, float Value);

/* �� �� �����, �� ��� ���� ����� */
//long GetInterIndex(OType ArrayHandle, unsigned char Column, float Roof, float Sole,
//                   long *RoofIndex, long *RoofSole);

/* �� �� �����, �� ��� ���������� ����� */
/* ValuesLastIndex = ���������� ��������� � ������� Values ����� 1 */
/* IndicesLastIndex = ���������� ��������� � ������� Indices ����� 1 */
/* Count - ������� ����� ���� */
//long GetArrayIndex(OType ArrayHandle, unsigned char Column, long Count,
//                   float *Values, long ValuesLastIndex,
//                   long *Indices, long IndicesLastIndex);

/* ��������/�������� ��������� ������������� ������ - ������, ������� � ���
   (���� ����). � ������ ���������� ������ ������ ���� ������ �������
   ��� ����������� */
long GetField(OType DataHandle, OType ArrHandle, long *Roof, long *Sole, long *Step);
long SetField(OType DataHandle, OType ArrHandle, long Roof, long Sole, long Step);

/* �������� ������ � ������� �� ������� (� ��) */
long GetIndex(OType DataHandle, OType ArrayHandle, long Depth);

/* �������� ������ ���� �� ������� Delta (� ��) (���� Delta < 0, ��, ���� �����,
   ������ ���������� ����� :) */
long ShiftDepth(OType DataHandle, OType ArrHandle, unsigned char ColNumber, long Delta, unsigned short Option);

/* ������������� �������� � ������� (��� ����. �������� ���������� ������� P
   � � ��������� ������������ � ���� �� �������, ������ ���� ����������
   Ind, ����� ���������� ������� �����, ������� ��� �������� �������) */
long Transform(OType DataHandle, OType ArrHandle, unsigned char Column,
               long Roof, long Sole, TTransform P, PProcess Ind);

/* �� ��, ��� � Transform (��.), ������ � P ��������� ��� �������� */
long ArgTransform(OType DataHandle, OType ArrHandle, unsigned char Column,
                  long Roof, long Sole, TArgTransform P, PProcess Ind);

/* ��� ���� ������ �������, � � �����������������-�� ������ :) */
long WinTransform(OType DataHandle, OType ArrHandle, unsigned char Column,
                  long Roof, long Sole, unsigned char WinSize, TWinTransform P,
                  float *MinV, float *MaxV, PProcess Ind);

/*������������� ���������� ���� ��� ������ ������ ObjHandle*/
unsigned short ObjDialogDLL(const char *Title,OType ObjHandle);
/*�� ��, � �������� ������ DataHandle*/
unsigned short ObjDlgDLL(const char *Title,OType DataHandle,OType ObjHandle);
/* ������ ��� ����� ��� ������ ������ */
unsigned short Tbl_Dlg(const char *aTitle,OType *PDObj,OType TDPtr);

/*������������� ���������� ���� ��� ������� ANewArr, ArrD - ��������� �������*/
/* Start-��������� �������, Step-��� ���������� ��� ������ ������� ��� ������ �����*/
unsigned short ArrDialog(const char *ATitle,OType ArrD,OType ANewArr,
  unsigned char WinSize,unsigned char FieldWidth,float Start,float Step);
/* �� �� �����, ��� ArrDialog, �� ����� �� �������� ������ */
unsigned short ArrDialogNew(const char* ATitle,OType ArrD,OType ANewArr,
  unsigned char WinSize,unsigned char FieldWidth,float Start,float Step,	// ��� ��� ����������
  long StartNumber,unsigned char StartColumn);
/*������������� ���������� ���� ��� ������� ArrHandle*/
unsigned short SArrDialog(const char* ATitle,OType ArrHandle);
/* �� �� �����, ��� SArrDialog, �� ����� �� �������� ������ */
unsigned short SArrDialogNew(const char* ATitle,OType ArrHandle,
  long StartNumber, unsigned short StartColumn);
/* ������ ������� � ���������� ������� �������. SysData - ��������� ������� �� �������� */
unsigned short ArrDialogD(const char *ATitle, OType ArrD, OType ANewArr, OType SysData,
  unsigned char WinSize, unsigned char FieldWidth, float aStartValue, float aStepValue);
/* ������ ��� ������ ������ O � ������� LF               */
/* ���� RowNumber > 0, �� ������ ������������ ��� �������*/
unsigned short ChoiceObjByKey(OType LF,unsigned char Width,unsigned short *RowNumber,LongBoolean Force,OType *O);
/*������ ��� ������ ������ �� ������ List                 */
/*���� Selectable=true, �� �������� ����� ���������� �����*/
void SelectString(const char *Title,const char *Prompt,void *List,
 unsigned short *RowNumber,LongBoolean Selectable,LongBoolean ForceSelect,char *Res);
void* SelectSetOfString(const char *Title,void *AimList,void *SelList);
/* ������ ��� ������ ������� LRHandle � ���� LFile Handle */
short ChoiceLogRec(const char *TableList,long Mode,OType LFileHandle,OType *LRHandle,
 LongBoolean NewTable,LongBoolean ForceSelect);
void* GetSetObjIdn(OType LF,unsigned short Width,void *OldList,LongBoolean MultiSel);
void* LogRecGetKeyContent(OType LRHandle,unsigned char AWidth);
/* ������ ��� ������ ������� ArrHandle � ������ ObjHandle*/
short ChoiceArrayByName(OType ObjHandle,OType *ArrHandle,char *ArrayName,unsigned short *BegLine);
/* ������ ��� ������ ������� ������� ArrHandle*/
short ChoiceColumnName(OType ArrHandle,char *ColumnName,unsigned char *ColumnNumber,unsigned short *BegLine);
void* GetColumnList(OType ArrayHandle);
//void* GetInputLine(RECT R,unsigned char RC,char *Min,char *Max,unsigned char ALen,unsigned char Dec);
/* ������ ��� ������ ��������� ������� TDescHandle � ������ �������� ResFileName*/
short ChoiceTDesc(const char *ResFileName,OType *TDescHandle);
/* ������������� ���� ��� �������������� ������� ��� ������ aDataObj*/
void ShowH(RECT R,OType *aDataObj,const char *Title,const char *ArrayName,const char *UnitName,unsigned short Option);
/* �� ��, ��� ����� ������� ������� Column*/
void ShowHEx(RECT R,OType *aDataObj,const char *Title,const char *ArrayName,const char *UnitName,
 unsigned short Option,unsigned short XOption,unsigned short YOption,unsigned char Column);
void ShowVertObj(OType* aDataObj, const char* ArrayName);

void SelectDir(char* Dir);
unsigned short InputString(const char* Title, const char* aLabel, unsigned short Len, char* Value);
unsigned short InputSingle(const char* Title, const char* aLabel, float Min, float Max, float* Value);
unsigned short InputWord(const char* Title, const char* aLabel, unsigned short Min, unsigned short Max, unsigned short* Value);
unsigned short SelectTwo(const char* Title, const char* aLabel1, const char* aLabel2, unsigned short* Value);
unsigned short InputJoint(const char* Title, const char* LabelW1, const char* LabelW2, const char* LabelS,
  unsigned short MinW, unsigned short MaxW, float MinS, float MaxS,
  unsigned short* ValueW1, unsigned short* ValueW2, float* ValueS);
unsigned short OperateDataObj(OType* Data, char* ResFName, char* LoadFName, char* Selected_Aim,
  unsigned short* RowNumber, LongBoolean Selectable, void** ObjColl, void** IdnColl,
  unsigned short LROption, unsigned short ObjOption, OType* O);
unsigned short TempOperateDataObj(OType* Data, char* ResFName, char* LoadFName, char* Selected_Aim,
  unsigned short* RowNumber, LongBoolean Selectable, void** ObjColl, void** IdnColl,
  unsigned short LROption, unsigned short ObjOption, OType* O);
void StartLongProcess(const char* Msg, long AMin, long AMax);
void LongProcessBack(long Pos);
void StopLongProcess(void);
LongBoolean LongProcessCancelled(void);
/* ����� ����� */
void GetFilename(const char *AWildCard,const char *ATitle,char *FileName);
void GetColumnName(OType ArrHandle,unsigned char Column,char *ColName);

/* FROM SclTools.pas */

/* ��������� ��������� Factor ��� �������� � FDUnit �� ����� ���� FDName   */
/* � ������ ���������� ��������� � ���� �������� ������ �� �������� � ���� */
/* ModuleName - �������������� ���������� ��� ����������� �������          */
/* ������������� ������ GetFDFactor � ������� ��� GUI                      */
long D_GetFDFactor(const char *ModuleName,OType TDescHandle,const char *FDName,const char *FDUnit,float *Factor);

/* �� �� �� ������ ����  */
long D_GetFDNFactor(const char *ModuleName,OType TDescHandle,long Index,const char *FDUnit,float *Factor);

/* ��������� �������� ���� Name ������ A � �������� �������� UnitName */
/* � ������ ���������� ��������� � ���� �������� ������ �� �������� � ���� */
LongBoolean GetFULongInt(OType A,const char *Name,const char *UnitName,long *R);
LongBoolean GetFUSingle (OType A,const char *Name,const char *UnitName,float *R);
LongBoolean GetFUString (OType A,const char *Name,const char *UnitName,char *R);

/* ��������� �������� ���� Name ������ A � �������� �������� UnitName */
/* � ������ ���������� ��������� � ���� �������� ������ �� �������� � ���� */
LongBoolean PutFULongInt(OType A,const char *Name,const char *UnitName,long R);
LongBoolean PutFUSingle (OType A,const char *Name,const char *UnitName,float R);
LongBoolean PutFUString (OType A,const char *Name,const char *UnitName,const char *R);

/* ��������� ������ � ���� � ��������������� ��������� ���� */
short Save_WSExR(const char *Selected_Aim, const char *TName, const char *SaveFName,
        LongBoolean CheckThisCopy, OType ObjHandle);

/* ������� ����������� ������ � ������� ��������� � ������������� �� ������� */
/* hInterArr = hNil      : �� ���������                 */
/* lpTranslateStr = NULL : �� �������������� �� ������� */
/* Flags                 : ��. ��������� clcXXXX        */
long CreateLayerCurve(OType hSrcObj,OType hSrcArr,unsigned char ucSrcCol,
           OType hInterArr,const char *lpTranslateStr,OType hDestObj,OType hDestArr,
           unsigned char ucDestCol,long Flags);

void ResDialog(const char *lpResFileName, const char *lpTablName);
void *GetNewClsList(const char *lpClsName);

/* ������������� ������ �� ���� � ���������� ��������� ����
  !������!(!������!@e:\prime98\00.LAS.1.�����������) */
long DoFuncDic(const char *InputStr, const char *FlName, const char *DicWSName,
           OType WSBase, OType DataObj, char *OutStr,
           long OutStrLen);
/* ��������� ������ ������� DicObj �� ����� ���� DicWSName � ������� TablName �
  �� ����� ������� DicName */
short GetDicObj(const char *DicWSName, const char *TablName, const char *DicName,
           OType *DicObj);
/* ��������� ���������������� ����� �� ������� */
long GetNewName(const char *OldName, OType DicObj, unsigned char Col1, unsigned char Col2,
           char *OutStr, long OutStrLen);

unsigned short Tbl(const char *lpszTitle, OType *lphObj, OType hSysData, OType hTD,
           const char *lpszTableName, short wReserved);
long GetKDataObj(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, OType *Value);

long GetKDataS(const char *K_BaseName, const char* TableName,const char *Region, const char *Field,
           const char *Plast, const char *Name, char *Value);
long GetKDataR(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, float *Value);
long PutKDataS(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, const char *Value);
long PutKDataR(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, float Value);

/* ������� ��� �������������� ������� */
TTwoDWindow TwoDWndCreate(const char* lpWindowName, float fArgMin, float fStep,
  long dwPointCount, long dwFuncCount, float fArgStart, float fArgStop,
  long dwArgLineCount, float fFuncMin, float fFuncMax,
  long dwFuncLineCount, const char* lpFuncPrefix, const char* lpArgUnitName,
  const char* lpFuncUnitName, long dwFlags);
TTwoDWindow TwoDWndCreateByDataHandle(OType hObj, OType hArr,
  const char* lpWindowName, long dwFlags);
HWND TwoDWndGetHandle(TTwoDWindow TwoDWindow);
LongBoolean TwoDWndShow(TTwoDWindow TwoDWindow, LongBoolean bShow);
long TwoDWndShowModal(TTwoDWindow TwoDWindow);
LongBoolean TwoDWndSetRect(TTwoDWindow TwoDWindow, const RECT* lprcBounds);
LongBoolean TwoDWndSetCallback_CloseWindow(TTwoDWindow TwoDWindow,
  long dwCookie, TTwoDCloseWindowCallback lpFunc);
LongBoolean TwoDWndSetData(TTwoDWindow TwoDWindow, float *lpfData,
  long dwDataCount, long dwFuncIndex);
LongBoolean TwoDWndGetData(TTwoDWindow TwoDWindow, float *lpfData,
  long dwDataCount, long dwFuncIndex);
LongBoolean TwoDWndGetAreaDisplayParams(TTwoDWindow TwoDWindow,
  long dwReserved, THGraphAreaRec *dp);
LongBoolean TwoDWndSetAreaDisplayParams(TTwoDWindow TwoDWindow,
  long dwReserved, const THGraphAreaRec *dp);
LongBoolean TwoDWndDestroy(TTwoDWindow TwoDWindow);
LongBoolean TwoDControlWndShow(LongBoolean bShow);
LongBoolean AddWin2dToControlWindow(TTwoDWindow TwoDWindow);
LongBoolean TwoDControlWndSetCallback_CloseWindow(long dwCookie,
  TTwoDCloseControlWindowCallback lpFunc);

/* ��������� ������ ������ LAS */
long AnsiLasLineNew(const char *lpOriginStr, const char *lpDicWSName, char *lpBlankValue, long nBlankValueSize,
  long *lpdwPosM, OType hDataObj, OType hLogFile, long dwRoof, long dwSole, long dwStep,
  char *lpLasLine, long nLasLineSize);
long AnsiGetFuncStr(char *lpInputStr, long nInputStrSize, unsigned short *lpwErrCode, char *lpFuncStr, long nFuncStrSize);
long AnsiGetWord(char *lpInputStr, long nInputStrSize, unsigned short *lpwErrCode, char *lpWord, long nWordSize);
long AnsiRemovePar(const char *lpInStr, char cMark, unsigned short wOption, char *lpResultStr, long nResultStrSize);
/*----------- ��������� ������ ------------------------------------------*/
long AnsiGetWSValue(const char *lpReference, short *lpsError, char *lpWSValue, long nWSValueSize);
/* ������ �� ���� */
long AnsiGetTableValue(const char *lpReference, OType hWSBase, short *lpsError, char *lpTableValue, long nTableValueSize);
/* ������ �� ������ */
long AnsiGetObjValue(const char *lpReference, OType hDataHandle, short *lpsError, char *lpObjValue, long nObjValueSize);
/* ��������� ������ � �������� ��� ��� */
/* LogFile - ���� ������ �� �������    */
/* ��������, ������� @LAS.1.�������  */
long AnsiUpdateStrC(const char *lpInStr, OType hLogFile, char *lpOut, long nOutSize, const char *lpDicWSName);
long AnsiUpdateStrCData(const char *lpInStr, OType hLogFile, OType hDataHandle, char *lpOut, long nOutSize, const char *lpDicWSName);
/*----------- ��������� �������� ------------------------------------------*/
/* ������������� ������ �� ���� � ���������� ��������� ����
  !������!(!������!@e:\prime98\00.LAS.1.�����������) */
long AnsiDoFuncDic(const char *lpInputStr, const char *lpFlName, const char *lpDicWSName, OType hWSBase, OType hDataObj, char *lpFuncRes, long nFuncResSize);
/* ��������� ������ ������� DicObj �� ����� ���� DicWSName � ������� TablName �
  �� ����� ������� DicName*/
short AnsiGetDicObj(const char *lpDicWSName, const char *lpTablName, const char *lpDicName, OType *lphDicObj);
/* ��������� ���������������� ����� �� �������*/
long AnsiGetNewName(const char *lpOldName, OType hDicObj, unsigned char nCol1, unsigned char nCol2, char *lpNewName, long nNewNameSize);
/* ��������� ��������� */
long AnsiGetToken(const char *lpP, long *lpdwI, char *lpToken, long nTokenSize);
long AnsiGetFuncDicName(const char *lpInputStr, const char *lpFlName, const char *lpDicWSName, OType hDataObj, char *lpFuncDicName, long nFuncDicNameSize);
/*--------------------------------------------------------------------------*/
void AnsiSetCurrWSName(const char *lpWSName);
void AnsiSetCurrTablName(const char *lpTablName);
void AnsiSetCurrObjName(const char *lpObjName);
void AnsiSetCurrRecName(const char *lpRecName);
void AnsiSetCurrArrName(const char *lpArrName);
void AnsiSetCurrArrColName(const char *lpArrColumn);
void AnsiSetCurrObValName(const char *lpObValName);
void AnsiSetCurrArrColNumber(unsigned char nColumn);
void AnsiSetCurrBaseHandle(OType hBaseHandle);
void AnsiSetCurrTablHandle(OType hTablHandle);
void AnsiSetCurrObjHandle(OType hObjHandle);
void AnsiSetCurrArrHandle(OType hArrHandle);
void AnsiSetCurrObValHandle(OType hObValHandle);
OType AnsiGetCurrBaseHandle(void);
OType AnsiGetCurrTablHandle(void);
OType AnsiGetCurrObjHandle(void);
OType AnsiGetCurrArrHandle(void);
unsigned char AnsiGetCurrArrColNumber(void);
OType AnsiGetCurrObValHandle(void);
long AnsiGetCurrWSName(char *lpCurrWSName, long nCurrWSNameSize);
long AnsiGetCurrTablName(char *lpTableName, long nTableNameSize);
long AnsiGetCurrObjName(char *lpObjName, long nObjNameSize);
long AnsiGetCurrRecName(char *lpRecName, long nRecNameSize);
long AnsiGetCurrArrName(char *lpArrName, long nArrNameSize);
long AnsiGetCurrObValName(char *lpObValName, long nObValNameSize);

/* ��������/��������� ������-����������� ����� �������
   ��� �����, ������������ ��������� AnsiGetObjValue � �.�. */
LongBoolean AnsiSetRowDelimiter(const char *lpValue);
long AnsiGetRowDelimiter(char *lpValue, long nValueSize);
/* ��������/��������� ������-����������� �������� �������
  ��� �����, ������������ ��������� AnsiGetObjValue � �.�. */
LongBoolean AnsiSetColDelimiter(const char *lpValue);
long AnsiGetColDelimiter(char *lpValue, long nValueSize);

/* ���������� ����� ������ */
void InitTableObjCache(OType hWSFile);
void DestroyTableObjCache(void);
short GetCachedTableHandle(const char *lpName, OType hWSFile, long *lpdwCachedHandle);
short GetCachedTableObjByIdN(long *dwCachedHandle, unsigned short wIdN, OType *lphObj);
void DisableTableObjCache(void);
void EnableTableObjCache(void);
LongBoolean IsTableObjCacheEnabled(void);

/* �������� �������� ����������� ������� ��������� ������� ��� ����������� ��������� */
char *StdDepthUnit(void);
/* �������� �������� ����������� ������� ��������� ������� ��� ��������� �� HINSTANCE ��� DLL */
TMinimalDepthUnit StdDepthUnitOfInstance(HINSTANCE hInstDLL);
/* �������������� ����������� ������� ��������� ������� �� 1 ����� ��������� ������� DSExt API */
void TemporarySetNewDepthUnit(const char *lpszUnitName, void *lpReserved);
/* �������� �������� ����������� ���������������� ������� ��������� ������� ��� ����������� ��������� */
char *StdUserDepthUnit(void);
/* �������� �������� ����������� ���������������� ������� ��������� ������� ��� ��������� �� HINSTANCE ��� DLL */
TUserDepthUnit UserDepthUnitOfInstance(HINSTANCE hInstDLL);
/* �������������� ����������� ���������������� ������� ��������� ������� �� 1 ����� ��������� ������� DSExt API */
void TemporarySetNewUserDepthUnit(const char *lpszUnitName, void *lpReserved);
/* �������� ���������� ����� ���������� DSExt ���������� � ����������� ������ (�������)
  ���� �����, � ���������, �������� ���������� �� ������������ �������� ��������� ������ */
void DSExtUpdateInstanceData(HINSTANCE hInstDLL, void *lpReserved);

#ifdef _MSC_VER
  // Microsoft Visual C++
  #pragma pack( pop, ENTER_DSEXT )
#else
  #ifdef __BORLANDC__
    // Borland C++ or Builder
    #if __BCPLUSPLUS__ > 0x520
      // Builder
      #pragma option pop
    #else
      // Borland C++
      //#pragma option -a4
      #pragma option -VF-
    #endif
  #else
    // What else???
  #endif
#endif

#endif


/***************************************************************************\
*                                                                           *
* ������� ��������������� ����������� ������������� ������������ �������    *
*   "�����" ��� Windows                                                     *
* ��������� � ������� ������                                                *
* ����: C++                                                                 *
* ������: 1.06.07                                                           *
* (C) ��� ������, 1999 - 2009                                               *
*                                                                           *
\***************************************************************************/

#ifndef _DSAPI_
#define _DSAPI_
#include <windows.h>

#ifdef _MSC_VER
  // Microsoft Visual C++
  #pragma pack( push, ENTER_DSAPI, 1 )
#else
  #ifdef __BORLANDC__
    // Borland C++ or Builder
    #if (__BCPLUSPLUS__ > 0x520)
      // Builder
      #pragma option push -a1 -VF
    #else
      // Borland C++
      #pragma option -a1 -VF
    #endif
  #else
    // What else???
    #pragma option -a1 -VF
  #endif
#endif

#ifndef _LONGBOOL_
#define _LONGBOOL_
typedef long LongBoolean;
#endif

#ifndef PASSTRING
#define PASSTRING

typedef struct {
	unsigned char Length;
	char Value[255];
} PasString, *PPasString;

typedef struct {
	unsigned char Length;
	char Value[8];
} string8;

typedef struct {
	unsigned char Length;
	char Value[16];
} string16;

typedef struct {
	unsigned char Length;
	char Value[32];
} string32;

typedef struct {
	unsigned char Length;
	char Value[64];
} string64;

#endif PASSTRING

/*
Default Time structure; since the compiler reverses the storage Order
a TimeRec (4-byte value) can be cast as a Longint and used in "<"
and ">" comparisons.
*/

typedef struct {
	unsigned char decsec; /* 0..99; */
	unsigned char second; /* 0..59; */
	unsigned char minute; /* 0..59; */
	unsigned char hour;   /* 0..23; */
} TimeRecType;

/*
Default Date structure; since the compiler reverses the storage Order
a Daterec (4-byte value) can be cast as a Longint and used in "<"
and ">" comparisons.
*/

typedef struct {
	unsigned char day;   /* 1..31; */
	unsigned char month; /* 1..12; */
	short year;
} DateRecType;


extern unsigned char MinByte;
extern unsigned char BlankByte;
extern unsigned char MaxByte;

extern short MinInt;
extern short MaxInt;
extern short BlankInt;
extern unsigned short MinWord;
extern unsigned short MaxWord;
extern unsigned short BlankWord;
extern long MinLongInt;
extern long MaxLongInt;
extern long BlankLongInt;
extern float MinSingle;
extern float MaxSingle;
extern float BlankSingle;

extern double MinDouble;
extern double MaxDouble;
extern double BlankDouble;

extern TimeRecType MinTime;
extern TimeRecType BlankTime;
extern TimeRecType MaxTime;
extern DateRecType MinDate;
extern DateRecType BlankDate;
extern DateRecType MaxDate;
extern char BlankStr[256];

/* ��������� ������ ������� ������ !!! */
#define MaxNameLen 32
#define MnemoLen   8+1
#define FNameLen   12
#define ShortLen   20+1
#define LongLen    60+1
#define MaxPathLen 81

typedef char NameStr[MaxNameLen+1];
typedef char FNameStr[FNameLen+1];
typedef char ShortStr[ShortLen+1];
typedef char PathStr[MaxPathLen+1];
typedef char MnemoStr[MnemoLen+1];

typedef char sz255[256];
typedef unsigned char TSByteArray[256];

/* ��������� ������ ��� ������ � ������� */

typedef unsigned char ClassType;
const unsigned char _NoDef = 0;
const unsigned char _TDesc = 1;
const unsigned char _FDesc = 2;
const unsigned char _SysData = 3;
const unsigned char _LFile = 4;
const unsigned char _LogRec = 5;
const unsigned char _Obj = 6;
const unsigned char _Curve = 7;
const unsigned char _Arr = 8;
const unsigned char _ObVal = 9;
const unsigned char _SO = 10;
const unsigned char _Node = 11;

typedef struct {
	unsigned short  H;
	ClassType       T;
	unsigned char   M;
} OType;

typedef struct {
	unsigned short Mode;
	ShortStr TablName;
	PathStr BaseName;
	PathStr WorkPath;
	unsigned short OperCount;
} CSODataType;

typedef struct {
	char Name1[9];
	char Name2[9];
	float Scale;
} CScalLineType;

typedef struct {
	NameStr afldName;
	unsigned char aRC;
	NameStr afldUnitName;
	short aLen;
	short aDec;
	MnemoStr aMin;
	MnemoStr aMax;
	unsigned short aMask;
	PathStr fldComment;
} TCFDData, *PCFDData;

typedef float ArrS10[10];

extern OType hNil;

#define FullAppTypeNumber  20
#define ShortAppTypeNumber 10
#define SetAppTypeNumber1  12

extern char TAppStr[FullAppTypeNumber+1][3];

extern char TAppFullStr[FullAppTypeNumber+1][8];

extern char TAppShortStr[SetAppTypeNumber1+1][8];

extern char *DTSkip; // ������ ������
extern char *ArrLen; // ���������� �����
extern char *FType; // ��� ����� ������
extern char *DataType; // ��������� ��� ������
extern char *DataDirection; // ����������� ������
extern char *cDevider; // �����������
extern char *cStrDeviderR; // ������ �����������
extern char *cStrDeviderL; // ����� �����������
extern char *cTerminatorCode; // ���������� ������

extern char *cFileName; // ��� �����
extern char *cFullFileName; // ������ ��� �����
extern char *cFileExt; // ���������� �����
extern char *cFileDir; // ���� �����
extern char *NullSingle; // ������ ��������
extern char *SHAG; // ��� ������������� ������
extern char *ED_IZM_S; // ������� ��������� ���� �������������
extern char *MGIS; // ����� ���
extern char *cWELL; // ��������
extern char *PARAMETR; // �������� ���������
extern char *ED_IZM; // ������� ��������� ��������� ���
extern char *KR_CFR; // ������ ������ ���
extern char *PD_CFR; // ������� ������ ���
extern char *cNVersion; // ����� ������
extern char *cHistory; // �������

/* ��������� ����� ������ � ������ */
extern char *ScaleFile; // ���� ���������� �������������
extern char *DicFile; // ���� ��������
extern char *DicTable; // ������� ��������
extern char *ClsTable; // ������� �������

#define SUCCESS            0
#define NoDefData          1
#define ArrayExpected      2
#define UnrecogRCodePtr    3
#define NotObj             4
#define NoTempateToDataObj 5
#define NoObjDescriptor    6

/* ���������� ������� Goto_BeginTable, Goto_NextTable, GetCurTable */
#define ERLRNotFind          301
#define ERLRNum              302
#define LrIsLast             303
#define DataNotOpen          200
#define LRCursorNotOpen      201
#define EFLRNotOpen          202
#define CurLRNotExist        203
#define ObjIsLast            204
#define NotLogFile           205
#define ImpossibleGoto_Begin 206
#define Not_is_EFLR          207
#define AbsentDdef           208
#define NoObjNext            209
#define NoLRNext             210
#define LRNumNotFound        211
#define ERLRNotFound         212
#define NoEFLRLoad           213
#define ErrPutLRHead         214
#define NoLRNum              215
#define NoObjNum             216
#define ObjNameNotFound      217
#define NoLR_goto_End        218
#define NoTemplate           219
#define LRTypeNotFound       220
#define NoLRCursor           221
#define CurObjNotExist       222
#define DiffTempateDataObj   223
#define NoMemory             224
#define StrmError            225
#define ErrGoto_End_LF       226
#define NoObjCursor          227

#define ErrGradient 230
#define ErrSmooth   231
#define ErrFiltr    232
#define ErrLogarifm 233
#define ErrLinModif 234

#define StepNotFound      251
#define OutOfMem          253
#define errGetDataByIndex 254
#define CommonError       255
#define StreamError2      256

#define MaxColumns 132 /* ������������ ����� ������� � ������� */
/* ����� ��� ���������������� �������� */
#define fxFixed 0x20      /* ��� ������ � ������ */
#define fxRead  0x40      /* ��� ������          */
#define fxWrite 0x80      /* ��� ������          */
#define fxReadWrite 0xC0  /* ��� ������ � ������ */

/* ��������� ��� ������ ������ �� WS */
#define cNoObj       0
#define cObj_Normal  1
#define cObj_Deleted 2
#define cObj_All     cObj_Normal + cObj_Deleted
#define cObjTemplate 4
#define cObjArray    8
#define cObjObject   16
#define cObjPict     32
#define cObjMemo     64
#define cObjNoKey    cObjArray + cObjPict + cObjMemo
#define cObjFull     cObjTemplate + cObjArray + cObjObject + cObjPict + cObjMemo
#define cObj         cObjFull + cObj_Normal

/* ��������� ��� ������ ������ �� WS */
#define cNoLR         0
#define cLR_Normal    1
#define cLR_Deleted   2
#define cLR_All       cLR_Normal + cLR_Deleted
#define cLRTemplate   4
#define cLRCurDataObj 8
#define cLRFull       cLRTemplate + cLRCurDataObj
#define cLR           cLRFull + cLR_Normal

/* ������� ����� ��� ����� ������� DataObj */
#define sBlank    0x0000
#define sModified 0x0001
#define sCreated  0x0002

/* ���� ������ PutScale, GetScale */
#define serr_INVSCALE -2 /* �������� ������� (=0) */
#define serr_STREAM   -1 /* ������ ������         */
#define serr_REPEAT    1 /* ������ ��������       */

/*****************************************************************************\
* �������� � ������� �������                                                  *
\*****************************************************************************/

/* ��������� ������*/
extern "C" long DatservLoad(void);

/* ������������ � ������ ��� ������������ � �������� ������������ �������� */
extern "C" LongBoolean DatservConnect(void);

/* ��������� ������. �� ����� ��������, ���� DatServ �������� ������� DatservConnect */
extern "C" void DatservFree(void);


/*****************************************************************************\
* ������ ��������                                                             *
\*****************************************************************************/

/* ���������� ������, ��������� � ������� ������ �� ��� ��������� */
void  DoneDSObj(void *P);
/* ���������� ������, ���������� � ������� ������ */
void  DSFreeMem(void *P,unsigned short Size);
/* ���������� ������ �� ����������� */
short DoneHandle(OType *Handle);
/* ������� ����� ������� */
short CopyHandle(OType Handle,OType *NewHandle);
/* ������� ����� ������� � ����� ������������ */
short CopyNewHandle(OType Handle,OType *NewHandle);
/* �������� ��� ������� */
short HandleGetType(OType Handle,unsigned char *aType);
/* �������� �������� ������� ������ */
void  ClearDatServ(void);

/*=================================================================================*/
/* ��������� ������� */

/* ������� ������ ��������� ������� */
short InitTDesc(const char *TablName,OType *TDescHandle);
/* �������� ��������� ������� �� �����*/
short GetTDesc(OType DataHandle,const char *TablName,OType *TDescHandle);
/* �� ��, �� ����� �������� */
short GetTDescF(const char *FileName,const char *TablName,OType *TDescHandle);
/* �������� ��� ��������� �������. Result = 32 - ������ ���������� ���� ����� */
short TDCheckDesc(OType TDescHandle,OType TDescHandle1,unsigned char *Result);
/* �������� ����� �������� � ��������� */
short TDGetArrayCounter(OType TDHandle);
/* �������� ����� �������� � ��������� */
short TDGetObjCounter(OType TDHandle);
/* �������� ��� ��������� */
short TDGetName(OType TDHandle,char *Res);
/* �������� ������� ��� ��������� */
short TDGetLongName(OType TDHandle,char *Res);
/* �������� ���������� ��� ��������� */
short TDGetAnglName(OType TDHandle,char *Res);
/* �������� ������� ��� ��������� */
short TDGetRusName(OType TDHandle,char *Res);
/* �� ��, �� ������� ��� ���������� */
short TDSetName(OType TDHandle,const char *Name);
short TDSetLongName(OType TDHandle,const char *Name);
short TDSetAnglName(OType TDHandle,const char *Name);
short TDSetRusName(OType TDHandle,const char *Name);
/* �������� ������ ������� �� ����������� ������ ������� */
short TDGetArrayIndexByNumber(unsigned char Number,OType TDHandle);
/* �������� ������ ������� �� ����� ������� */
short TDGetArrayIndex(const char *AName,OType TDHandle);
/* �������� ����� �������� � ��������� */
short TDGetArrayNumber(OType TDHandle,const char *AName);
/* �������� ������ ������� �� ����������� ������ ������� */
short TDGetObjIndexByNumber(unsigned char Number,OType TDHandle);
/* �������� ������ ������� �� ��� ����� */
short TDGetObjIndex(const char *AName,OType TDHandle);
/* �������� ����� �������� � ��������� */
short TDGetObjNumber(OType TDHandle,const char *AName);
/* �������� ������ ���� �� ��� ����� */
short TDGetFieldIndex(const char *AName,OType TDHandle);
/* �������� ��������� ���� FDHandle � ��������� ������ TDHandle*/
short TDInsertFD(OType TDHandle, OType FDHandle);
/* �������� ��������� ���� FDHandle � ��������� ������ TDHandle � ������� ������� i*/
short TDAtInsertFD(OType TDHandle,short i,OType FDHandle);
/* �������� ��������� ���� FDHandle � ��������� ������ TDHandle � ������� ������� i*/
short TDAtPutFD(OType TDHandle,short i,OType FDHandle);
/* ������� ��������� ���� FDHandle � ��������� ������ TDHandle � ������� ������� i*/
short TDAtFreeFD(OType TDHandle,short i);
/* ��������� ������ ���� S1 � ��������� ������ TDHandle */
LongBoolean TDCheckRepeating(OType TDHandle, char *S1);
/* �������� ��������� ������ TDHandle � ���� �������� */
short PutTDesc(const char *ResFileName,OType TDHandle,LongBoolean ChkCopy);
/* ������� ��� ��������� ����� � ��������� ������ */
short TDFreeAll(OType TDHandle);
/* Weren't in DOS !*/
short GetTDescName(OType TDescHandle,char *Name);
/* ������ ��������� �������� ���� �� ����� ���� */
short GetTDescFldsN(OType TDescHandle,const char *FieldName,PCFDData PFDesc);
/* ������ ��������� �������� ���� �� ������� ���� */
short GetTDescFldsI(OType TDescHandle,unsigned short FieldNumber,PCFDData PFDesc);

/* �������� ������ �� ���� �������� �����. ELen - ����� �� ������ ��� */
short GetTDKeyStr(OType TDescHandle,unsigned char SLen,char *KeyStr);
short MakeDKeyTablDesc(OType TDescHandle,OType *KeyTD);
/* �������� ������ �� �������� MasterDesc ����� */
short GetAnyKeyStr(OType MasterDesc, OType SlaveDesc,unsigned char SLen,char *KeyStr);
/* �������� �������������� �������� �� ����� �� ��������� ������� */
short GetTDDefinedValue(OType TDescHandle,const char *FieldName,OType *ObValHandle);
float GetDefSingle(OType TDescHandle, const char *FieldName);
long GetDefLong(OType TDescHandle, const char *FieldName);
short GetDefStr(OType TDescHandle, const char *FieldName, char *Value);
/* �������� ������� �������������� */
short TDGetAtomNameAt(OType TDHandle, short i, char *AtomName);
/* �������� ������� �������������� */
short TDInsertNewAtom(OType TDHandle, const char *Name);

/*=================================================================================*/
/* ��������� ���� */

/* ������� ��������� ���� */
/* afldType  = ( 0-Nodef, 1- _Byte, 2- _Short, 3- _Word, 4-_LongInt, 5-_Single,
6-_Double, 7-_String,8- _Date, 9- _Time,10- _Array,11-_Object,
12-_StringC, 13-_Table,14-_User1,15- _User2,16- _User3,17- _Blob,
18-_Boolean, 19-_Memo); */
short InitFDesc(const char *afldName,const char *afldUnitName,unsigned char afldType,
				short afldLen,OType *FDescHandle);
/* �������� ��������� ���� �� ����� */
short GetFDescByName(OType TDescHandle,const char *FieldName,OType *FDescHandle);
/* �������� ����� ���������� ����� � ��������� �������*/
short GetTDescCounter(OType TDescHandle,unsigned short *TDCounter);
/* ����������/�������� �������� Slave � ���� */
short SetFDescSlave(OType FDescHandle,LongBoolean M);
/* �������� �������� Slave � ���� */
LongBoolean  IsFDescSlave(OType FDescHandle);
/* �������� ��������� ���� �� ������ */
short GetFDescByNumber(OType TDescHandle,unsigned short FieldNumber,OType *FDescHandle);
/* �������� �������� ��������� ���� */
short GetFDescFlds(OType FDescHandle,PCFDData FDesc);
/* ���������� �������� ��������� ���� */
short SetFDescFlds(OType FDescHandle,PCFDData FDesc);

/* �������� ��� ��������� ����. ���� ���������� Result
0 - ��� ������� ���������,
+8 - ���������� ����,
+4 - ���������� �����;
+2 - ���������� ������ ���������;
+1 - ���������� ���� */
short LFDescCompary(OType FDescHandle,OType FDescHandle1,unsigned char *Result);

/* �������� ������ � ���� */
short GetFDescAccess(OType FDescHandle,unsigned char *Access);
/* �������� ����� ���� */
/* unsigned short Mask;       F E D C B A 9 8 7 6 5 4 3 2 1 */
/*                            � � � � � � � � � � � � � � � */
/*                        ----- � � � � � � � � � � � � � � */
/*                        ------- � � � � � � � � � � � � � */
/*                        --------- � � � � � � � � � � � � */
/* ������ �� ������       ----------- � � � � � � � � � � � */
/* ������� ������         ------------- � � � � � � � � � � */
/* ������������ ��������  --------------- � � � � � � � � � */
/* ������� ������/������� (temp)----------- � � � � � � � � */
/* 1 �������� �������� write ---------------- � � � � � � � */
/* 1 �������� �������� read ------------------- � � � � � � */
/* 1 �������� ��������      --------------------- � � � � � */
/* 1 ������ � �������. �����. --------------------- � � � � */
/* 1 ������ � ���. ����������� ---------------------- � � � */
/* 0/1 ������ � (����/�����)   ------------------------ � � */
/* 0/1 K1/K2 (���� �������� ����)------------------------ � */
/* 0/1 ������/���� ����     ------------------------------- */
unsigned short GetFDMask(OType FDescHandle);
/* ���������� ����� ���� */
short SetFDMask(OType FDescHandle,unsigned short Mask);
/* �������� ��� ���� ���� */
short GetFDescRC(OType FDescHandle,unsigned char *RC);
/* �������� ���� ���� */
short GetFDescKey(OType FDescHandle,unsigned char *Key);
/* ������� ���� �������� */
short SetFDescKey(OType FDescHandle);
/* ���������� ������� ������� ������ */
void GetSystemDir(char *Dir);
/* �������� � ���� ���������� ������������� ����� �����. */
short PutScale(CScalLineType *SL);
/* ��������� ���� ���������� ������������� */
short GetScale(CScalLineType *SL);
/* �������� ��������� ��� �������� �������� ���� � ��. FDUnit �� ����� ����*/
short GetFDFactor(OType TDescHandle,const char *FDName,const char *FDUnit,float *Factor);
/* �������� ��������� ��� �������� �������� ���� � ��. FDUnit �� ������� ����*/
short GetFDNFactor(OType TDescHandle,short Index,const char *FDUnit,float *Factor);
/* �� ��, � ������������ ������������� */
/* Unit1 - ��.��� ����, ��� �������� �� ������ �����. Unit1->FDUnit */
short GetFDFactorEx(OType TDescHandle,const char *FDName,const char *FDUnit,char *Unit1,float *Factor);
short GetFDNFactorEx(OType TDescHandle,short Index,const char *FDUnit,char *Unit1,float *Factor);
/* �������� � ���� ��������� ������� */
short GetFDArrDesc(OType FDescHandle,OType *TDHandle);
/* ��������� ���� ��������� ������� */
short SetFDArrDesc(OType FDescHandle,OType TDHandle);
/* ���������� � ���� ������������� (������) */
short SetFDClass(OType FDescHandle,const char *ClsName);
/* �������� � ���� ��� ������������� */
short GetFDClass(OType FDescHandle,char *ClsName);

/*=================================================================================*/
/* ������� ������ */
/* �������� ���������� ������� ������ �� ��������� ResFileName*/
short CreateSysData(const char *ResFileName,OType *DataHandle);
/* �������� ���������� ������� ������ �� ��������� ResFileName*/
short InitSysData(const char *ResFileName,OType *DataHandle);
/* ��������� ���� FileName � ������� ������ */
short GetLogFile(const char *FileName,LongBoolean *Status,OType DataHandle,OType *LFHandle);
/* ������� ���� LFHandle �� ������� ������ */
short RemoveLogFile(OType DataHandle,OType LFHandle);
/* �������� ��� ����� �������� � ������� ������ */
short GetResFileName(OType DataHandle,char *Res);
/* �������� ������ ����� �������� ��� �������� ������ */
unsigned short ResStreamSt(OType DataHandle);
/* �������� �� ��������� ������� ������ */
LongBoolean ResIsModified(OType DataHandle);
/* �������� ����� �������� */
short PackRes(OType DataHandle);
short ResPutTD(OType DataHandle,OType TDesc,const char *Key);
short ResDeleteTD(OType DataHandle,const char *Key);
short ResRemoveMemTD(OType DataHandle,const char *TablName);
LongBoolean ExistInRes(const char *Key,OType DataHandle);
short ResGetKeyCounter(OType DataHandle);
short ResGetKeyAt(OType DataHandle,short i,char *Res);
short ResGetMemTD(OType DataHandle,short Index,OType *TDesc);
short ResAddMemTD(OType DataHandle,OType TDesc);

/* ========================================================================= */
/* ���� ������ �� WS */
/* ������ �������� ���� ������ ��� ������� ������ */
short SysLFInitOpen(const char *FileName,OType *LFHandle);

short SysLFInitOpenEx(const char *FileName, OType *LFHandle, int LROption, int ObjOption);

/* �������� ���������� ������ ���� ������ */
short SysLFCreate(const char *FileName,OType DataHandle,OType *LFHandle);
/* ������ ����� ������ � ��������� ������������ ������ � ������� ���� */
/* CheckIntent (24 - ������ ���������), CheckCopy (28 - ������ �������� �����) */
short SaveNewObj(const char *SelectedAim,const char *aTablName,LongBoolean CheckCopy,LongBoolean CheckIntent,OType LFHandle,OType ObjHandle);
/* �� ��, ��� � SaveNewObj, �� ���������� Handle ���������� ������� */
/* (���������������� ��������� ����) */
short SaveNewObjEx(const char *SelectedAim,const char *aTablName,LongBoolean CheckCopy,LongBoolean CheckIntent,OType LFHandle,OType ObjHandle,OType *NewObjHandle);
/* ��������� ��� ���� ������ */
short LFAppend (OType MainLF,OType OtherLF,unsigned short Option);
/* ��������� ���� � ������ ���� bName. Delta - ������� �������� */
short LFPackTo(OType LFHandle,const char *bName,long *Delta);
/* ����� ������ ������ � ���� �� ������� */
short FindFirst(OType LFHandle,OType SOHandle,OType *ObjHandle);
/* ����� ������ ������ � ������� ���� �� ������� */
short FindFirstLocal(OType LFHandle,OType SOHandle,const char *TablName,OType *ObjHandle);
/* ����� ��������� ������ � ���� �� ������� */
short FindNext(OType LFHandle,OType *ObjHandle);
/* ������� � ������ ������� � ���� */
short Goto_BeginTable(OType LFHandle);
/* ������� � ��������� ������� � ���� */
short Goto_NextTable(OType LFHandle);

/*============================================================================*/
/* ������� */

// ��������� Option ��� �-�� GetIndexViewsList
const long civlName          = 0;      // ������ ���
const long civlTablName      = 1;      // +���_������� ;
const long civlVerNumber     = 2;      // +����� ������;
const long civlPackKeyStr    = 4;      // + �������� ����;
const long civlDataClass     = 8;      // + ����� ������;
const long civlTopBottomStep = 16;     //+������, �������, ���
const long civlIndexNumber   = 32;     //+���������� ����� ������� � �������
const long civlCurves        = 256 ;   // ���������� ������� ������
const long civlBedCurves     = 512 ;   // ���������� ����������� ������
const long civlLitol         = 1024;   // ���������� ������� ���������
const long civlStrat         = 2048;   // ���������� ������� ������������
const long civlSlaveOnly     = 0x1000; // ���������� ������ ������ �������
const long civlNameOnly      = 0x2000; // ���������� ������ ��� (��� ���������� ����� ��������)
const long civlNoFirstSymbol = 0x4000; // �� ������� ������ ������ � ��� (#,!)
const long civlIncludeParams = 0x8000;

long GetIndexViewsList(const char *WSName, const char *TablName, const char *Delim, long Option, char *Res);
long GetWSViewsList(const char *WSName, const char *TablName, const char *Delim, long Option, char **Res);
long GetWSViewsListXml(const char *WSName,const char *TablName, int Option, char **Res);
long FreeDSMem(char *pointer, int Size, int Option);

/*============================================================================*/
/* ������� WS */

/* �������� ������� �������. 0-��� ������ */
short TableExist(const char *TableName,OType LFHandle);
/* �������� ������� ������� ���� */
short GetCurTable(OType LFHandle,OType *LRHandle);
/* �������� ������� �� ����� � ���� */
short Get_Table(const char *TableName,OType LF,OType *LRHandle);
short Get_TableNew(const char *TableName,OType LFHandle,OType *LRHandle);
/* ���������� ���� ��� */
short GetTableName(OType LRHandle,char *Res);
/**/
short GetWSHandle(OType LRHandle, OType *WSHandle);
short LRChangeName(OType LRHandle,const char *NewName);
/* �������� ��������� */
short LRPutTDesc(OType LRHandle,OType TDHandle);

/* ������� � ������ ������ ������� */
short Goto_BeginObj(OType LRHandle);
/* ������� ������� � ������ ������ ������� */
short Goto_FastBeginObj(OType LRHandle);
/* ������� � ��������� ������ ������� */
short Goto_NextObj(OType LRHandle);
/* ������ ������� � ��������� ������ ������� */
short Goto_FastNextObj(OType LRHandle);
/* �������� ������ aDataObj.*/
short LRPutObj (OType LRHandle,OType aDataObj,LongBoolean CheckCopy,LongBoolean aNewTable);
/* �������� ������� ������ � ������� */
unsigned char LRCheckKeyObj (OType LRHandle,OType aDataObj,OType TDescHandle,unsigned short *IdN,OType *FindedObjHandle);
/*============================================================================*/
/* ������ ������� WS */

/* ������� ������� ������ ������� */
short GetCurObj(OType LRHandle,OType *ObjHandle);
short GetFastCurObj(OType LRHandle,OType *ObjHandle);
/* ������ ���������� ����� �����������, ���� ���� ������ ��������� */
short GetTrueCurObj(OType LRHandle,OType *ObjHandle);
short GetTrueFastCurObj(OType LRHandle,OType *ObjHandle);
/* ������� ����� ������� �� ��� ������ ��������� */
short ObjTDCopy(OType TableHandle,OType ObjHandle,OType *NewObjHandle);
/* ������� ������ ����� ������� */
short ObjCopyBlank(OType ObjHandle,OType *NewObjHandle);
/* ���������� ������ */
short BlankObj(OType ObjHandle);
/* ���������� ������ �� ��� ������ IdN ( ��������� ���������� � 1) */
short GetObjByIdN(OType LRHandle,unsigned short Idn,OType *ObjHandle);
short GetObjByEIdN(OType LRHandle,unsigned short ObjType,unsigned short Idn,OType *ObjHandle);
/* ������� ������ ������� � ������� ������ �� ��������� �� ����� ��������*/
short ObjTDInit(const char *ResFileName,const char *TablName,OType *ObjHandle);
/* ������� ������ ������� � ������� ������ �� ���������*/
short ObjTDInitH(OType TableHandle,OType *ObjHandle);
/* ��������� � ������ ������ (ObVal, Arr, Obj) � ������� i */
short ObjAtPut(OType ObjHandle,short I,OType Handle);
/* ���������� � ��������� ���� ���������� ������ */
short ObjWriteASCII(OType ObjHandle,const char *FileName,LongBoolean Owrw);
/* ���������� ������ �� ��� ������������������ ������ �� ���� */
short GetWSObj(OType LFHandle,unsigned short IdN,const char *TablName,OType *ObjHandle);
/* ���������� ������ �� ��� �������� ������ KeyStr �� ���� */
short GetWSKeyObj(OType LFHandle,const char *TablName,const char *KeyStr,OType *ObjHandle);
/* ����������� �� �������� ����� ImportFile �������� ��������� � TDescHandle*/
short ImportObj (OType TDescHandle,const char *ImportFile,const char *TablName,OType *ObjHandle);
/* ������������ �� ������� ���� ExporFile */
short ExportObj (const char *ExportFile,OType ObjHandle);
/* ������� ������ ������ */
short ObjInit(OType *ObjHandle);
/* �������� �������� ���� ������. SLen - ����� �� ������ ���� */
short GetKeyStr(OType ObjHandle,unsigned short ID,unsigned char SLen,char *S);
short ObjGetAnyKeyStr(OType ObjHandle,OType SlaveDesc,unsigned short ID,unsigned char SLen,char *S);
/* �������� ����� �������� ����� ������. SLen - ����� �� ������ ���� */
short GetMetaKeyStr(OType ObjHandle,unsigned char SLen,char *S);
/* �������� ����� ������ ������ � ������� */
unsigned short GetRowNumber(OType ObjHandle,OType LFHandle,const char *TableName);
/* �������� ��������� � �������-������ */
short GetTemplate(OType ObjHandle,OType *THandle);
/**/
short SetTemplate(OType ObjHandle,OType THandle);
/* �������� � ������ ���� � ���������� */
short ObjAdd_ObVal(OType ObjHandle,OType  ObValHandle,OType FDHandle);
short ObjAddAt_ObVal(OType ObjHandle,OType ObValHandle,OType FDHandle,short Index);
/* �������� � ������ ������ � ���������� */
short ObjAdd_Arr(OType ObjHandle,OType ArrHandle,OType FDHandle);
/* ������� � ����� ��� �������� ������ */
short MoveToBuf(OType ObjHandle,void *Buf, long bufsize);
/* �������� �� ������ ��� �������� ������ */
short MoveFromBuf(OType ObjHandle,void *Buf, long bufsize);
/* �������� ������ ������ ������ ��� ������ */
long GetObjBinarySize(OType ObjHandle);
/* �������� ���������� �� ��������� ������ */
LongBoolean GetObjState(OType ObjHandle,unsigned short Mask);
/* ��������� ���������� �� ��������� ������ */
short SetObjState(OType ObjHandle,unsigned short Mask,LongBoolean Enable);
/* ���������� ������ (������ ������) �� ����� �� ������� ������ */
short GetObjByName (OType MainObjHandle,const char *AName,OType *ObjHandle);
/* ���������� ������ ������ ������ �� ������ �� ������� ������ */
short GetObjByNumber(OType MainObjHandle,short ObjNumber,OType *ObjHandle);
/* ��������� �������������� ����� ������ ���� ����� */
LongBoolean ChkGroup(OType ObjHandle1,OType ObjHandle2);
/* �������� ������, �������� � ��� ���� ��� ��� ������� */
/* Option and 1 = 1 - ����������� �������� TakeData */
short ReplaceArr(OType ObjHandle,const char *ArrName,unsigned char Column1,unsigned char Column2,unsigned short Option);
/* ������ ��������� ������ �� ������� */
short DeleteObj(OType ObjHandle,OType LRHandle);
/* ��������������� ������ ����� ����������� �������� */
short RestoreObj(OType ObjHandle,OType LRHandle);
/* �������� �������� ����� �� ������ ������ */
/* Option 0-������ ������ ���������, 1-������ �����, 2-��� �����*/
short ObjTakeByTDesc(OType ToObjHandle,OType FromObjHandle,unsigned short Option);
short ObjGetHandleIndex(OType ObjHandle,OType Handle);
/* ������ �� ��������� ������ �� ��������� */
short ImportStrObj(OType TDescHandle,char *Str,OType *ObjHandle);
/* ��� ��������� ������� � ������ ����� */
short AddHistory(OType ObjHandle,const char *FieldName,const char *HistStr);
short IncVersion(OType ObjHandle,const char *FieldName);

/*============================================================================*/
/* ������ ������ */

/* ��� ������������ ������������� � �������������� ������� */
short InitCurve(OType DataHandle,unsigned short ArrayNumber,OType *CurveHandle);
unsigned short CurveGetCount(OType CurveHandle);
short CurveSetParams(OType CurveHandle,float aRoof,float aSole,float aStep,const char *fldUnit);
short CurveGetParams(OType CurveHandle,float *aRoof,float *aSole,float *aStep,char *fldUnit);
short CurveSetMinMaxVal(OType CurveHandle,unsigned short index,OType MinVal,OType MaxVal);
short CurveGetMinMaxVal(OType CurveHandle,unsigned short index,OType *MinVal,OType *MaxVal,long B,long E);
short CurveDoMinMaxVal(OType CurveHandle,long StartN,long EndN);
short CurveGetArr(OType CurveHandle,OType *ArrHandle);
short CurveGetColor(OType CurveHandle,unsigned short index,unsigned char *Color);
short CurveSetColor(OType CurveHandle,unsigned short index,unsigned char Color);
short CurveSetStatus(OType CurveHandle,unsigned char Status);
short CurveGetStatus(OType CurveHandle,unsigned char *Status);
short CurveGetDataHandle(OType CurveHandle,OType *ObjHandle);

/*============================================================================*/
/* ������ ������ WS */

short ArrayFInit(const char *ArrayName,unsigned char Colums,TSByteArray Ty,long MaxLen,OType *ArrHandle);
/* ������� ������ �� ����� � ������ */
short GetArrayByName(OType *ArrHandle,const char *AName,OType ObjHandle);
/* ������� ������ �� ������ */
short GetArrayByNumber(OType *ArrHandle,unsigned short Number,OType ObjHandle);
/* ������� ����� ������� �� ����� � ������ */
short CopyArrayByName(OType *ArrHandle, const char *AName, OType ObjHandle);
/* ������� ����� ������� �� ������ */
short CopyArrayByIndex(OType *ArrHandle, short Index, OType ObjHandle);
/* �������� ��� ������� */
short ArrayGetName(OType ArrHandle,char *Res);
/* �������� ��������� ������� */
short ArrayGetDesc(OType ArrHandle,OType *TDesc);
/* �������� ��������� ������� */
short ArrayReplaceDesc(OType ArrHandle,OType TDesc);
/* ������������� ������� �� ������ �������� ����� AFileName*/
/* APosition ������� � ������ ������ ������� � �����*/
short ArrayInit(long APosition,const char *AFileName,OType TDHandle,LongBoolean aEraseFlag,OType *ArrHandle);
/* short ArrayWriteBin(OType ArrHandle,TXStream *S); */
short ArrayGetState(OType ArrHandle,unsigned short *State);
short ArraySetState(OType ArrHandle,unsigned short State);
/* ������� ������ ������ �� ��������� */
short ArrayTDInit(OType *ArrHandle,const char *ResFileName,const char *TablName,const char *ArrayName);
/* ������� ������ ������ �� ��������� ���� */
short ArrayFDInit(OType *ArrHandle,OType FieldHandle);
/* ������� ������ ������ �� ��������� ������ �� ����� */
short ArrayTDInitH(OType *ArrHandle,OType TDescHandle,const char *ArrayName);
/* �������� ������ �� ������� */
short GetArrayByIndex(OType *ArrHandle,short Index,OType ObjHandle);
/* ������� ������ ����� ������� */
short ArrayCopyBlank(OType ArrHandle,OType *O);
/* ������� ������ ������ �� ������ ������� */
short ArrayGetObjData(OType ArrHandle,long Index,OType *ObjHandle);
/* �������� ������ ������ �� ������� ������� */
short ArrayGetColumnObj(OType ArrHandle,unsigned char Column,long Index,OType *ObjHandle);
/* �������� ������ ������ � ������ ������� */
/* ����������� ������ ����������� ����, ���� ����������������� */
/* ������ ������� �� ������������ */
short ArrayPutObjData(OType ArrHandle,long Index,OType ObjHandle);
/* �������� ������ �� ������ */
short ArrayPutData(OType ArrHandle,long Index,unsigned short Count,void *PBuf);
/* �� ��, �� ��� ����������� �� 64K ������� */
short ArrayPutHugeData(OType ArrHandle,long Index,long Count,void *PBuf);
/* �������� ������ � ����� */
short ArrayGetData(OType ArrHandle,long Index,unsigned short Count,void *PBuf);
/* �� ��, �� ��� ����������� �� 64K ������� */
short ArrayGetHugeData(OType ArrHandle,long Index,long Count,void *PBuf);
/* ��������� ���������� ������� �� ������� B �� E ����� P*/
short MoveSingleColumnData(OType ArrHandle,unsigned char Column,long B,long E,void *P);
/* ��������� �������� ������� �� ������� B �� E �� ������ P */
short LoadSingleColumnData(OType ArrHandle, unsigned char Column, long B, long E, void *P);
/* �������� �������� �������� ������� � ���� ������ */
short ArrayGetStrColumnData(OType ArrHandle,unsigned char Column,long Index,char *Res);
/* �������� �������� �������� ������� � ���� ��������������� ������ */
short ArrayGetFStrColumnData(OType ArrHandle,unsigned char Column,long Index,char *Res);
/* �������� �������� �������� ������� � ���� float */
float ArrayGetSingleColumnData(OType ArrHandle,unsigned char Column,long Index);

/* �������� �������� Count ��������� ������� � ���� ������ float */
short ArrayGetSingleColData(OType ArrHandle,unsigned char Column,long Index,unsigned short Count,float *Buf, long BufLastIndex);

/* ������� ��������� �������� �������� ������� � ���� float */
/* ���������� ������� ������� ����� �-� � ����� ArrHandle */
float ArrayGetSingle(unsigned char Column,long Index);
/* ������ � ������� �� ������ ������� */
int GetArraySingle(OType ArrHandle, long Index, const char *ColName, float *Value);
long GetArrayLong(OType ArrHandle, long Index, const char *ColName);
long GetArrayString(OType ArrHandle, long Index, const char *ColName, char *Value);
long GetArrayFString(OType ArrHandle, long Index, const char *ColName, char *Value);
long PutArraySingle(OType ArrHandle, long Index, const char *ColName, float Value);
long PutArrayLong(OType ArrHandle, long Index, const char *ColName, long Value);
long PutArrayString(OType ArrHandle, long Index, const char *ColName, const char *Value);
long  ArrayGetLongColumnData(OType ArrHandle,unsigned char Column,long Index);
/* ��������� �������� �������� ������� � ���� ������ */
short ArrayPutStrColumnData(OType ArrHandle,unsigned char Column,long Index,const char *S);
/* ��������� �������� �������� ������� � ���� float */
short ArrayPutSingleColumnData(OType ArrHandle,unsigned char Column,long Index,float S);
/* ��������� �������� �������� ������� � ���� long */
short ArrayPutLongColumnData(OType ArrHandle,unsigned char Column,long Index,long L);
/* �������� ����� ��������� ������� */
long ArrayGetLen(OType ArrHandle);
/* ���������� ����� ��������� ������� */
short ArraySetLen(OType ArrHandle,long Len);
/* �������� ������ ������ ������� */
short ArrayGetElementSize(OType ArrHandle,unsigned short *ElementSize);
short ArrayGetItemType(OType ArrHandle,unsigned char Column,unsigned char *ItemType,unsigned short *ItemSize);
/* �������� ������ ������ */
short ArrayBlankValue(OType ArrHandle,void *BP);
/* ��������� ������ �� ������� */
short ArrayValIsBlank(OType ArrHandle,unsigned char Column,long StartIndex,long EndIndex,LongBoolean *Res);
/* ���������� ������ */
short ArrayBlankIndex(OType ArrHandle,long Index);
/* ��������� �� ������� ������� ������� */
LongBoolean ArrayColumnIsBlank(OType ArrHandle,unsigned char Column);
/* ���������� ������� ������� */
short ArrayDoBlankColumn(OType ArrHandle, unsigned char Column, long Start, long Stop);
/* ��������� �� ������� ������� ������� */
LongBoolean ArrayColumnIndexIsBlank(OType ArrHandle,unsigned char Column,long Index);
/* �������� ����� ������� ������� */
short ArrayGetColumns(OType ArrHandle,unsigned char *Colums);
/* �������� ����� ������� �� ����� ������� */
short ArrayGetColNumByName(OType ArrHandle,const char *ColName,unsigned char *Column);
/* ������� � ������� � ��������� ��������� ����� �� ���� ������ */
/* ����� ������� ������������� ����������� �� 1 */
short ArrayDeleteLine(OType ArrHandle,long Index);
/* ������� � ������� ������� ������� � ��������� ��������� ����� �� ���� ������*/
/* ����� ������� �� ����������� !*/
short ArrayDeleteColumnLine(OType ArrHandle,unsigned char Column,long Index);
/* ��������� ������ ������. ��������� ������ ���������� ���� */
short ArrayInsertLine(OType ArrHandle,long Index);
short ArrayInsertLineN(OType ArrHandle,long Index,long LCount);
/* ��������� ������ ������� � ������. ��������� �������� ���������� ���� */
short ArrayInsertColumnLine(OType ArrHandle,unsigned char Column,long Index);
/* �������� ������� �� Delta ��������� � ����������� �� ����� */
short ArrayShiftColumnLine(OType ArrHandle,unsigned char Column,long Delta);
/* �������� ������� � ������ BegN �� Delta ��������� � ����������� �� ����� */
short ArrayAtShiftColumnLine(OType ArrHandle,unsigned char Column,long BegN,long Delta);
/* ������� �� ������� ��������� �������� ��������� */
short ArrayDelInter(OType ArrHandle,long Start,long Stop);
/* Option = 0 - ������ �������; 1-���������� � ����� */
short ArrayCopyColumn(OType FromArrHandle,OType ToArrHandle,unsigned char FromColumn,unsigned char ToColumn,unsigned char Option);
/* �������� ������ �������� �� �������� */
short GetNearstRigthNumber(OType ArrHandle,unsigned char Column,float Value,long *Number);
/* �������� ����� �������� �������� �������� � Value */
short GetNumberByValue(OType ArrHandle,unsigned char Column,float Value,long *Number);
/* �������� ������ �������� �� �������� */
long GetFirstNumberByValue(OType ArrayHandle,unsigned char Column,float Value,long *Number);
/* ����������� ������ ����� ������ */
short ArrayRevert(OType ArrHandle);
/* �������� ������������� �������� */
short ArrayChangeNull(OType ArrHandle,float NewNull,float OldNull,unsigned char BegCol,unsigned char EndCol,unsigned char ArgCol);
/* ��������� ����������� � ������������ �������� ������� */
short ArrayDoMinMax(OType ArrHandle,long StartN,long EndN);
/* �������� ����������� � ������������ �������� ������� */
short ArrayGetMinMax(OType ArrHandle,unsigned short Column,OType *MinVal,OType *MaxVal);
/* �� ��, ���������� ��� ��������������� ������� ����� */
short ArrayGetMinMaxH(OType ArrHandle,unsigned short Column,long BegN,long EndN, float *MinVal,float *MaxVal,float *MidVal,long *MinN,long *MaxN);
/* ���������� ����� ������� �� �������� ������� */
short ArraySort(OType ArrHandle,unsigned char Column,long StartN,long EndN);

/*=================================================================================*/
/*  ������� */

/* ���������� �������� 2-������ ������� ��            */
/* PMode: ������������ 1-��������, 2-������������, 3-���������� */
/* DMask: ����������� �������������� 0-������, 1-��������    */
/* AMode: ������ ������������ ��� �
0 - ��� �������������� �������� �,
1 - ������,     2 - ������,
4 - ln �����������, 8 - exp �����������,
16- lg ����������, 32 - exp ����������.
FMode - �� �� ��� ��� Y             */
/* ����� ������� ��������� = 1 ������ */
/* ��� 2-������ ������� FuncColumn (>1) - ����� ������� �-�� */
float GetPal2Value(OType ArrHandle,float ArgValue,unsigned char FuncColumn, unsigned short DMask,unsigned short PMode,unsigned short Amode,unsigned short FMode);

/* ���������� �������� 3-������ ������� �� �������� ������������� */
/* QValue-�������� ��������� */
float GetPal3Value(OType ArrHandle,float ArgValue,float QValue,unsigned short QMode, unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode);

/* �������������� ������� �� ��������� ������� */
short DoPal2Value(OType ArrHandle,OType PalArrHandle,unsigned char Column,unsigned char PalFuncCol,long BegN,long EndN,unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode);

/* �������������� ������� �� ���������� ������� */
short DoPal3Value(OType ArrHandle,OType PalArrHandle,unsigned char Column,long BegN,long EndN,float QValue,unsigned short QMode,unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode);

/* ������� ��� ����������� ������� ���������� �������� ������� ������� */
float GetPalParam(OType ArrHandle,unsigned char Col);

/* ���������� ������� 3-������ ������� �� ��������� ������� Value*/
unsigned char GetPalColumn(OType ArrHandle,float Value);

/* ���������� � ������� */
short ASqr(OType FromArr,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* ���������� ����������� ����� */
short ASqrt(OType FromArr,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

short ArrayRevLin(OType ArrHandle,OType FromArrHandle,float A,float B,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* ��������� ���������� */
short ArrayExponent(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);
/* ��������� ���������� �� ��������� 10 */
short ArrayExp10(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* �������� � ������� */
short ArrayPower(OType ArrHandle,OType FromArrHandle,float Delta,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);
/* ������������� */
short ArrayLogarifm(OType ArrHandle,OType FromArrHandle,float Modul,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);
/* ���������� ��������� */
short ArrayGradient(OType ArrHandle,OType FromArrHandle,unsigned short FN,float Delta,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN);

/* ������������ ������ */
short ArrayFiltr(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* ������ ������������ 0*/
short ArrayKendal0(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* ������ ������������ 1*/
short ArrayKendal1(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* ������ ������������ 2*/
short ArrayKendal2(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* ���������. �ind= 1-���., 2-����. */
short ArraySkin(OType ArrHandle,OType FromArrHandle,unsigned short Kind,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* ����������� ������� ���������� ��������� */
short ArraySmooth(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN);

/* ����������� ������� �������� ��������������� */
short ArrayMeanSmooth(OType ArrHandle, OType FromArrHandle, unsigned short FN,
  unsigned char FirstCol, unsigned char LastCol,
  long BegN, long EndN);

/* ����������/������ */
short ArrayRubber(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN,long NewN,unsigned short Option);

/* �������� �������������� Ax+B */
short ArrayLinModif(OType ArrHandle,OType FromArrHandle,float A,float B,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* �������������� �� ��������� �����������, �������� �������� TarArrHandle
XTarCol, YTarCol - ������ ������� ��������� � ������� � ������� TarArrHandle */
short ArrayScaling(OType ArrHandle,OType FromArrHandle,OType TarArrHandle,unsigned char XTarCol,unsigned char YTarCol,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* �������� �����. �������� � ���������� �� ������������� */
short ArrGetPolinom(OType ArrHandle,OType From,float Step,unsigned char n,unsigned char ArgColumn,unsigned char Column,long startN,long endN,float *aMdlSqDiv,float *aMaxAbsDiv,float *aMaxRelDiv,ArrS10 *bb);

/* �������� ������� � ��������� */
short ArrayMean(OType ArrHandle,unsigned char BegCol,unsigned char EndCol,unsigned char ArgCol,long BegN,long EndN,float *MeanVal,float *Disp);

/* �������� ������� ��� ��������� �������� Roof, Sole */
long ArrayGetInterIndex(OType ArrHandle,unsigned char Column,float Roof,float Sole,long *RoofIndex,long *SoleIndex);

/* ��������� ����� ��� ���� ������� �������.
���� Option = 0, �� ������� ������
Option = 1, �� ������� ���������� */
short ArrayExtract(OType ArrHandle,unsigned char Column1,unsigned char Column2,unsigned short Option,OType *NewArr);
/* �������� ������� � ������
  AtIndex- ������ ������� �� 0
  Option - ��� ���� +
  Option and 4 = 4, �� ��������� �� �����
  �������� ������� � ����� ������, ���� (Option and 8) = 8 */
short ArrayAddColumn(OType ArrHandle, OType FDesc, unsigned short AtIndex, unsigned short Option, OType *NewArr);
/* ������� �������
  Option - ��� ���� +
  Option and 4 = 4, �� ��������� �� ����� */
short ArrayDelColumn(OType ArrHandle, unsigned short Column, unsigned short Option, OType *NewArr);

/* ����� ������ �� ������� � ������ �������������� ���������, ��. ��� � �.�. */
short ArrayTakeData(OType MainArrHandle, OType FromArrHandle);
short ArrayTakeDataEx(OType MainArrHandle, OType FromArrHandle, unsigned short Option);


/* ������ � BLOB-������ */
long GetBlobByIndex(OType *BlobHandle, long Index, OType DataHandle);
long GetBlobSize(OType BlobHandle, long *Size);
long SetBlobLen(OType BlobHandle, long Len);
long BlobReadBuf(OType BlobHandle, long Position, long Size, void *Buf);
long BlobWriteBuf(OType BlobHandle, long Position, long Size, void *Buf);

/*============================================================================*/
/* ������� ���� ������ WS */

/* ������� ���� ������ �� ����� */
short GetFieldVal(const char *AName,OType ObjHandle,OType *ObValHandle,unsigned char *T);
/* ��������� ������� � ��������������� ��. ��������� */
/* Unit - ������� ��������� ��� ���������� Value  */
short ObjGetFieldSingle(const char *AName,OType ObjHandle,const char *aUnit,float *Value);
/* Unit1 - ������� ��������� � ������� AName, ���� �����. Unit1->Unit �� ������ */
short ObjGetFieldSingleEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,float *Value);
short ObjGetFieldLong(const char *AName,OType ObjHandle,const char *aUnit,long *Value);
short ObjGetFieldLongEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,long *Value);
/* ���������� �������� � ��������������� ������� ��������� */
/* Unit - �������� ������� ��������� ��� Value  */
short ObjPutFieldSingle(const char *AName,OType ObjHandle,const char *aUnit,float Value);
/* Unit1 - ������� ��������� � ������� AName, ���� �����. Unit->Unit1 �� ������ */
short ObjPutFieldSingleEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,float Value);
short ObjPutFieldLong(const char *AName,OType ObjHandle,const char *aUnit,long Value);
short ObjPutFieldLongEx(const char *AName,OType ObjHandle, const char *aUnit,char *Unit1, long Value);
short CopyFieldVal(const char *AName, OType ObjHandle, OType *ObValHandle, unsigned char *T);
short CopyObVal(OType ObValHandle, OType *NewObValHandle);
/* ������� ���� ������ �� ������ */
short GetObValByIndex( short Index,OType ObjHandle,OType *ObValHandle);
/* ������� ���� ������ �� ������ */
short CopyObValByIndex( short Index,OType ObjHandle,OType *ObValHandle);
/* �������� ���� ������ �� ������ */
short ReplaceObValByIndex( short Index,OType ObjHandle,OType ObValHandle);
/* ������� ���� � ������������ � ���������� � ��������� Value */
short ObValFDInit(OType FDescHandle,const char *Value,OType *ObValHandle);
/* ������ MakeValueS */
short MakeObValS(unsigned char aType,const char *Value,unsigned short aLen,OType *ObValHandle);
/* ������� ���� ���� float */
short ObValSingleInit( float Value,OType *ObValHandle);
/* ������� ���� ��������� ���� */
short ObValBoolInit(unsigned char Value,OType *ObValHandle);
short ObValDoubleInit(double Value,OType *ObValHandle);
short ObValIntInit( short Value,OType *ObValHandle);
short ObValWordInit(unsigned short Value,OType *ObValHandle);
short ObValByteInit(unsigned char Value,OType *ObValHandle);
short ObValStrInit(const char *Value,OType *ObValHandle);
/* ������� ���� ���� StringC */
short ObValStringInit(const char *Value,unsigned short Len,OType *ObValHandle);
/* ������� ���� ���� long */
short ObValLongIntInit(long Value,OType *ObValHandle);
/* ��������� ���� �� ������������� �������� */
short ObValIsBlank(OType ObValHandle,LongBoolean *IsBlank);
/* ���������� �������� � ������ */
short ObValMoveVal(OType ObValHandle,void *Buf);
/* ���������� �������� � ���� */
short ObValPutVal(OType ObValHandle,void *Buf);
/* �������� �������� ���� ����� String */
short ObValGetStr(OType ObValHandle,char *Res);
/* �������� ��������������� �������� ���� ����� String */
short ObValGetFStr(OType ObValHandle,unsigned short L,unsigned short D, char *Res);
/* �� ��, �� �������� ��� ������� (> 255) ����� */
short ObValGetFPChar(OType ObValHandle, unsigned short L, unsigned short D, char *FStr, long SizeIncludingEOL);
/* �������� �������� ���� ����� float */
float ObValGetSingle(OType ObValHandle);
/* �������� �������� ���� ����� long */
long ObValGetLongInt(OType ObValHandle);
/* �������� ����� ���� � ������ */
short ObValGetSize(OType ObValHandle,unsigned short *Size);
/* �� ��, �� �������� ��� ������� �������� (> 64K) */
short ObValGetLongSize(OType ObValHandle, long *Size);
/* ���������� ��������� �� �������� ���� */
short ObValGetPointer(OType ObValHandle,void *P);
/* ����������� �������� ���� ����� String */
short ObValPutStr(const char *S,OType ObValHandle);
/* ����������� �������� ���� ����� float */
short ObValPutSingle(float S,OType ObValHandle);
/* ����������� �������� ���� ����� long */
short ObValPutLongInt(long Li,OType ObValHandle);
/* ���������� �������� �� ��������� � ������ */
LongBoolean ObValCompare(OType ObValHandle,const char *Value);
/**/
short ObValGetType(OType ObValHandle,unsigned char *aType);
unsigned char ObValEqual  (OType V1,OType V2);
unsigned char ObValLess  (OType V1,OType V2);
unsigned char ObValELess  (OType V1,OType V2);
unsigned char ObValGreater (OType V1,OType V2);
unsigned char ObValEGreater(OType V1,OType V2);
/* short ObValLoad( TXStream *S,OType *ObValHandle); */
/* short ObValStore( TXStream *S,OType ObValHandle); */
/* short ObValReadStr( Text *S,OType ObValHandle); */
/* short ObValWriteStr( Text *S,OType ObValHandle); */
short ObValIncDec (OType V1,OType V2,unsigned char OP);
short PassObVal(OType V1,OType V2);

/*============================================================================*/
/* �������� � ������ WS */

/* ��������� ������ �� ���� */
short Load_WS(const char *ResFName,const char *LoadFName,
  const char *Selected_Aim,const char *TName,unsigned short *RowNumber,
  OType *ObjHandle);
/* ��������� ������ �� ����, ���� ���� ��� ��� ��������� */
short Load_WSEx(const char *ResFName,const char *LoadFName,
  const char *Selected_Aim,const char *TName,unsigned short *RowNumber,
  OType *ObjHandle);

/* ��������� ������ � ���� */
short Save_WS(const char *Selected_Aim,const char *TName,const char *SaveFName,LongBoolean CheckCopy,OType ObjHandle);

/* ��������� ������, ���� ������ CheckIntent=True � ���������=24, �� ���������� ���������� ������
   ����� NewObjHandle = hNil. NewObjHandle ���������� ���������� �������������� */
short Save_WSEx(const char *Selected_Aim, const char *TName, const char *SaveFName,
				LongBoolean CheckCopy, LongBoolean CheckIntent,
				OType ObjHandle, OType *NewObjHandle);

short Save_WSExRW(const char *Selected_Aim, const char *TName, const char *SaveLogFileName,
	LongBoolean CheckThisCopy, OType ObjHandle);

/* ============================================================================*/
/* �������� ������������� �������� �� ��������� */
void SetBlank(unsigned char vType,const char *Value);
float GetBlankSingle(void);

/* ������� � ����� �������� */
short MakeWhereData(OType *WhereDataH,const char *fldName,const char *fldValue);
/* ��������� ���� ������� */
short AddWhereData(OType WhereDataH,const char *fldName,const char *fldValue);
/* ������� ������ ��� ������ ��� ������� FindFirst, FindNext */
short SearchDataInit(OType WhereDataH,OType SelectTD,OType *SearchDataH);
/* ������ ������� ������ ��� ������ ��� ������� FindFirst, FindNext */
/* Name1 = Val1, Name2=Val2, Name3=Val3 - ������� ������      */
short SSearchDataInit(const char *Name1,const char *Val1,const char *Name2,const char *Val2,const char *Name3,const char *Val3,OType TableHandle,OType *SearchDataH);
/* ���������� ��� ���������. ���������� ��� ������ � ������� TDescH */
short PrepareCond(OType SearchDataH,OType TDescH);
short GetSOData(OType SOHandle,CSODataType *SOData);
short SetSOData(OType SOHandle,CSODataType SOData);
short SetSOpers(OType SOHandle,short Index,const char *SOPer);
short AddSOper(OType SOHandle,const char *Oper);
short SetSTable(OType SOHandle,const char *TablName);
/* ��������� ������� SearchDataH �� ������� DataObjH */
short CompCond(OType SearchDataH,OType DataObjH,LongBoolean *Result);
short LoadSO(OType *SearchDataH,const char *FName);
short StoreSO(OType SearchDataH,const char *FName);
void  DatServCounters(void);
void  DoTxtMaket(OType RedObjHandle,OType RezObjHandle,const char *MetName,const char *FName);

void *DSGetTableCollection(OType LFHandle);

/* ������� ��� ��������� ��������� ������� ������ � ���������� �����*/
short GetSysDataCount(void);
short GetSysLogFileCount(void);
short GetSysLRCursorCount(void);
short GetSysLogRecCount(void);
short GetSysDataObjCount(void);
short GetSysArrayCount(void);
short GetSysObValCount(void);
short GetSysTDescCount(void);
short GetSysFDescCount(void);

/* �������� ������ �������. 0 - OK, -1 - ���������� ������ */
short CheckResVersion(const char *ResFileName, const char *TableName, const char *CurrentResVersion);

/* ��������� ������������ ����� ������� (��� ������� �������) */
long GetLenLimit(OType O);

/* �������� ���������� ����� � ���� ���� Memo */
long MemoGetLineCount(OType hMemo);
/* �������� ������ �� ���� ���� Memo �� � ������� */
long MemoGetLine(OType hMemo, long Index, char *Str, long StrMaxLen);
/* �������� ������ � �������� �������� � ���� ���� Memo ����� ��������� */
long MemoSetLine(OType hMemo, long Index, const char *Str);
/* �������� ����� ������ ����� ������� � �������� �������� � ���� ���� Memo */
long MemoInsertLine(OType hMemo, long Index, const char *Str);
/* ������� ������ � �������� �������� �� ���� ���� Memo */
long MemoDeleteLine(OType hMemo, long Index);
/* �������� ������ � ����� ���� ���� Memo */
long MemoAddLine(OType hMemo, const char *Str);

void SetChangeBlankNotifyProc(void *Proc);
void GetDatservBlanks(
  unsigned char *_BlankByte,
  short *_BlankInt,
  unsigned short *_BlankWord,
  long *_BlankLongInt,
  float *_BlankSingle,
  double *_BlankDouble,
  TimeRecType *_BlankTime,
  DateRecType *_BlankDate,
  char *_BlankStr);
void SetDatservBlanks(
  unsigned char _BlankByte,
  short _BlankInt,
  unsigned short _BlankWord,
  long _BlankLongInt,
  float _BlankSingle,
  double _BlankDouble,
  TimeRecType _BlankTime,
  DateRecType _BlankDate,
  const char *_BlankStr);

extern "C" void GetBlanks(void);
extern "C" void SetBlanks(void);

//void SetCallWatchBases(void *Bases);
//long GetMaxHandleIndex(ClassType CType);
//long GetHandleAllocCount(OType H);
//LongBoolean GetHandleCallers(OType H, void *List, long ListCount);
//LongBoolean ChangeHandleOwner(OType H, void *NewOwner);
//LongBoolean ObtainHandleOwnership(OType H);
//LongBoolean CheckChangeHandleOwner(OType H, void *PrevOwner, void *NewOwner);
//LongBoolean CheckObtainHandleOwnership(OType H, void *PrevOwner);
//short DoneHandleByCaller(OType *Handle, void *Caller);
//
// �������������� �������� ���� ����/�����
LongBoolean GetDateByFormat(const char *Value, const char *Format, DateRecType *DSDateRec);
LongBoolean GetTimeByFormat(const char *Value, const char *Format, TimeRecType *DSTimeRec);
//
//// ������ � ������� ������
//// ������� ������ �� ���� ������
//long ClearAllBuf(void);
//long ClearSubBuf(const char *SubName);
//// �������� ������ � �����
//long SetBufData(const char *Name, const char *SubName, const char *StrValue, double RValue,
//          void *PValue, long DType, long Option, void *Reserved);
//// ��������� ������ �� ������
//long GetBufData(const char *Name, const char *SubName, char *StrValue,
//          double *RValue, void **PValue, long *DType,
//          long Option, void *Reserved);
//
//// �-� ��� ��������� ���������� � ������ �� ��������
//long GetPlanCurveInfo(const char *WSName, const char *CurveKeyStr, const char *Tmp, long Option,
//                      char *ValueName, char *IndexStr, char *Reserv,
//                      long *ArrayIndex, long *RowIndex, long *Count, long *TmpInt);
//// ��������� ������ ����. �����, ��������������� ������� IfStr
//// ���������� �������� �������������� ������ ��� KeyDataStrList � ������� ���� ������ � MaxListLen
//// ��� ErrStr ����������� ����� �������� ����� � 255 ��������.
//short LRGetKeyStrListByCond(OType LRHandle,
//                  const char *IfStr, const char *KeyDataStrList, const char *ErrStr,
//                  long MaxListLen, long  Option);
//
void DSDoneObject(void *P);
///* ========================================================================= */
///* ������� ��� ������ � ������������� �������� */
///* ������� ������ */
//
PPasString DSNewPString(const char *S);
///* ��������������� ����� ��� ������ */
//PPasString DSMemPString(unsigned char Len);
///* �������� �������� ������ */
//PPasString DSGetPString(PPasString P);
///* �������� ����� ������ */
//function DSLenPString(PPasString P): Byte;
//void DSPutPString(PPasString P, const char *S, unsigned char I, unsigned char N);
//void DSFillPString(PPasString P, char Ch, unsigned char I, unsigned char N);
///* ���������� ������ */
//void DSFreePString(PPasString P);
///* ========================================================================= */
//void *DSGetMemLib(long ASize);
//void *DSFreeMemLib(void *P, long ASize);
//void *DSAllocMemLib(long ASize);
//void DSReallocMemLib(void **P, long NewSize);
//void DSPCharDispose(char *P);
///* ========================================================================= */


/* ������� ����� ��������� �������� */
void* DSInitList(long Limit = 8, long Delta = 8);
/* ������� ����� ��������� ����� */
void* DSInitStringList(long Limit = 8, long Delta = 8);
/* ������� ����� ��������� ���������� */
void* DSInitEmptyList(long Limit = 8, long Delta = 8);
/* ������� ����� ��������� ��������������� ����� */
void* DSInitUnsortList(long Limit = 8, long Delta = 8);
/* ���������� ����� ��������� ��������� */
long DSListCount(void *List);
/* ���������� ������� �� ��� ������� */
void* DSListAt(void *List,long Index);
/* ������� ������� �� ��������� */
void DSListAtDelete(void *List,long Index);
/* ���������� ������� ��������� */
void DSListAtFree(void *List,long Index);
/* �������� ������� � ��������� */
void DSListAtInsert(void *List,long Index,void* Item);
/* �������� ������� ��������� */
void DSListAtPut(void *List,long Index,void *Item);
/* ������� ������� ��������� */
void DSListDelete(void *List,void *Item);
/* ������� �� ��������� ��� ��� �������� */
void DSListDeleteAll(void *List);
/* ���������� ������� ��������� */
void DSListFree(void *List,void *Item);
/* ���������� ��� �������� ��������� */
void DSListFreeAll(void *List);
/* ���������� ������ ������� �������� � ��������� */
long DSListIndexOf(void *List,void *Item);
/* ��������� ������� � ��������� */
void DSListInsert(void *List,void *Item);
/* ������� �� ��������� ������ �������� */
void DSListPack(void *List);
/* ����� ������ � ��������� (������ ��� ��������� �����) */
long DSListSearch(void *List,const char *Key);

typedef void* TDSStream;

long CreateDSStream(int Option, TDSStream &Stream);
long StoreBufTD(void** Buf, long Option, OType TDHandle);
long LoadBufTD(void** Buf, int Count, long Option, OType &TDHandle);
short LFGetPackState(OType LFHandle);
short GetWSName(OType LRHandle, const char* WSName);
short TableExistX(const char* TableName, OType LFHandle, int Option);
int DSGetTableNames(OType LFHandle, unsigned short LROption, char **Names);

// procedure(Mode : Integer; Xml : PChar);
typedef void (__stdcall *TOnSaveDataProc)(int Mode, const char *Xml);

//procedure SetOnSaveDataProc(Proc : TOnSaveDataProc); stdcall; export;
void SetOnSaveDataProc(TOnSaveDataProc Proc);

#ifdef _MSC_VER
  // Microsoft Visual C++
  #pragma pack( pop, ENTER_DSAPI )
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

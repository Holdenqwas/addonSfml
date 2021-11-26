/***************************************************************************\
*                                                                           *
* Ñèñòåìà èíôîðìàöèîííîãî îáåñïå÷åíèÿ ãåîôèçè÷åñêèõ èññëåäîâàíèé ñêâàæèí    *
*   "ÏÐÀÉÌ" äëÿ Windows 95/98/NT                                            *
* Èíòåðôåéñ ê ñåðâåðó äàííûõ                                                *
* ßçûê: C++                                                                 *
* Âåðñèÿ: 1.03.09                                                           *
* (C) ÍÏÔ ÃåîÒÝÊ, 1999, 2002                                                *
*                                                                           *
\***************************************************************************/

#if _MSC_VER > 1000
  #pragma once
#else
#endif // _MSC_VER > 1000
#include <windows.h>
#include <string.h>
#include "dsapi.h"

extern unsigned char MinByte = 0;
extern unsigned char BlankByte = 222;
extern unsigned char MaxByte = 255;

extern short MinInt = -32768;
extern short MaxInt = 32767;
extern short BlankInt = 32767;
extern unsigned short  MinWord = 0;
extern unsigned short  MaxWord = 65535;
extern unsigned short  BlankWord = 65535;
extern long MinLongInt = -2147483647;
extern long MaxLongInt = 2147483647;
extern long BlankLongInt = 2147483647;
extern float MinSingle = -3.4E+38F;
extern float MaxSingle = 3.4E+38F;
extern float BlankSingle = -999.25F;

extern double MinDouble = -1.7e+308;
extern double MaxDouble = 1.7e+308;
extern double BlankDouble = -999.25;

extern TimeRecType MinTime = {0, 0, 0, 0};
extern TimeRecType BlankTime = {0, 0, 0, 0};
extern TimeRecType MaxTime = {99, 59, 59, 23};
extern DateRecType MinDate = {1, 1, 0};
extern DateRecType BlankDate = {1, 1, 0};
extern DateRecType MaxDate = {31, 12, 2100};
extern char BlankStr[256] = "";

extern OType hNil = {0, 0, 0};

extern char TAppStr[FullAppTypeNumber+1][3] =
{
	"Nd","B","I","W","L","S","R","C","D","T",
		"A","O","c","T","U1","U2","U3","Bb","U","Mm","Pc"
};

extern char TAppFullStr[FullAppTypeNumber+1][8] =
{
	"NoDef","Byte","Short","Word","LongInt",
		"Single","Double","String","Date","Time",
		"Array","Object","StringC","Table","User1",
		"User2","User3","Blob","Boolean","Memo","Pict"
};

extern char TAppShortStr[SetAppTypeNumber1+1][8] =
{
	"Byte","Short","Word","LongInt",
		"Single","Double","String","Date","Time",
		"Boolean","StringC","Array","Object"
};

extern char *DTSkip           = "ÍÀ×ÀËÎ_ÊÐÈÂÎÉ";
extern char *ArrLen           = "Ñ×ÅÒ×ÈÊ_ÊÎË_ÒÎ×ÅÊ";
extern char *FType            = "ÒÈÏ_ÔÀÉËÀ_ÄÀÍÍÛÕ";
extern char *DataType         = "ÑÈÑÒÅÌÍÛÉ_ÒÈÏ_ÄÀÍÍÛÕ";
extern char *DataDirection    = "ÍÀÏÐÀÂËÅÍÈÅ_ÄÀÍÍÛÕ";
extern char *cDevider         = "ÐÀÇÄÅËÈÒÅËÜ";
extern char *cStrDeviderR     = "ÐÀÇÄÅËÈÒÅËÜ_ÑÒÐÎÊÈ_Ï";
extern char *cStrDeviderL     = "ÐÀÇÄÅËÈÒÅËÜ_ÑÒÐÎÊÈ_Ë";
extern char *cTerminatorCode  = "ÒÅÐÌÈÍÀÒÎÐ_ÑÒÐÎÊÈ";

extern char *cFileName        = "ÈÌß_ÔÀÉËÀ";
extern char *cFullFileName    = "ÏÎËÍÎÅ_ÈÌß_ÔÀÉËÀ";
extern char *cFileExt         = "ÐÀÑØÈÐÅÍÈÅ_ÔÀÉËÀ";
extern char *cFileDir         = "ÏÓÒÜ_ÔÀÉËÀ";
extern char *NullSingle       = "NULL_VALUE";
extern char *SHAG             = "ØÀÃ_ÄÈÑÊÐÅÒ_ÊÐÈÂÎÉ";
extern char *ED_IZM_S         = "ÅÄ_ÈÇÌ_ØÀÃÀ_ÄÈÑÊÐÅÒ";
extern char *MGIS             = "ÌÅÒÎÄ_ÃÈÑ";
extern char *cWELL            = "ÑÊÂÀÆÈÍÀ";
extern char *PARAMETR         = "ÇÍÀ×ÅÍÈÅ_ÏÀÐÀÌÅÒÐÀ";
extern char *ED_IZM           = "ÅÄ_ÈÇÌ_ÏÀÐÀÌ_ÃÈÑ";
extern char *KR_CFR           = "ÊÐÎÂËß_ÊÐÈÂÎÉ_ÃÈÑ";
extern char *PD_CFR           = "ÏÎÄÎØÂÀ_ÊÐÈÂÎÉ_ÃÈÑ";
extern char *cNVersion        = "ÍÎÌÅÐ_ÂÅÐÑÈÈ";
extern char *cHistory         = "ÈÑÒÎÐÈß";

extern char *ScaleFile  = "PRIME.SCL";
extern char *DicFile    = "DICTNS.WS";
extern char *DicTable   = "ÑËÎÂÀÐÈ";
extern char *ClsTable   = "ÑÏÈÑÊÈ";


/* Ðåàëèçàöèÿ */

const unsigned char abDosToWin[256] =
{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0xA4,
0x10,0x11,0x12,0x13,0xB6,0xA7,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
0x2D,0x2D,0x2D,0xA6,0x2B,0xA6,0xA6,0xAC,0xAC,0xA6,0xA6,0xAC,0x2D,0x2D,0x2D,0xAC,
0x4C,0x2B,0x54,0x2B,0x2D,0x2B,0xA6,0xA6,0x4C,0xE3,0xA6,0x54,0xA6,0x3D,0x2B,0xA6,
0xA6,0x54,0x54,0x4C,0x4C,0x2D,0xE3,0x2B,0x2B,0x2D,0x2D,0x2D,0x2D,0xA6,0xA6,0x2D,
0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF,
0xA8,0xB8,0xAA,0xBA,0xAF,0xBF,0xA1,0xA2,0xB0,0x95,0xB7,0x76,0xB9,0xA4,0xA6,0xA0};


const unsigned char abWinToDos[256] =
{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
0x3F,0x3F,0x27,0x3F,0x22,0x3A,0xC5,0xD8,0x3F,0x25,0x3F,0x3C,0x3F,0x3F,0x3F,0x3F,
0x3F,0x27,0x27,0x22,0x22,0x07,0x2D,0x2D,0x3F,0x54,0x3F,0x3E,0x3F,0x3F,0x3F,0x3F,
0xFF,0xF6,0xF7,0x3F,0xFD,0x3F,0xB3,0x15,0xF0,0x63,0xF2,0x3C,0xBF,0x2D,0x52,0xF4,
0xF8,0x2B,0x49,0x69,0x3F,0xE7,0x14,0xFA,0xF1,0xFC,0xF3,0x3E,0x3F,0x3F,0x3F,0xF5,
0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF};

typedef struct { char C[257]; } char255;

char255 RecodeCache[32];

int RecodeCacheIndex = 0;

char* DosToWin(const char *Src){
	//char *Result = new char[(strlen(Src)+1)];
	char *Result = RecodeCache[RecodeCacheIndex++].C;
	RecodeCacheIndex %= 32;
	int len = strlen(Src);
	if (len > 256) len = 256;
	for(int i = 0; i < len; i++){
		Result[i] = abDosToWin[(unsigned char)Src[i]];
	};
	Result[len] = 0x00;
	return Result;
}

char* WinToDos(const char *Src){
	//char *Result = new char[strlen(Src)+1];
	char *Result = RecodeCache[RecodeCacheIndex++].C;
	RecodeCacheIndex %= 32;
	int len = strlen(Src);
	if (len > 256) len = 256;
	for(int i = 0; i < (int) strlen(Src); i++){
		Result[i] = abWinToDos[(unsigned char)Src[i]];
	};
	Result[len] = 0x00;
	return Result;
}

void CDosToWin(char *Src){
	int str_len = strlen(Src);
	for(int i = 0; i < str_len; i++){
		Src[i] = abDosToWin[(unsigned char)Src[i]];
	};
	return;
}

void StrTrim(char *Src){
		int i,j,k = 0;
		for(i = strlen(Src); i && (Src[i] <= 32); i--) { k = i+1; };
		Src[k] = 0;
		for(i = 0; Src[i] && (Src[i] <= 32); i++) { j = i; };
		strcpy(Src,Src+j);
	return;
}

void CWinToDos(char *Src){
	for(int i = 0; i < (int) strlen(Src); i++){
		Src[i] = abWinToDos[(unsigned char)Src[i]];
	};
	return;
}

#ifndef DATSERVDLL
#define DATSERVDLL "DatServ1.dll"
#endif

HINSTANCE hDLL_DATSERV = NULL;

typedef void (__stdcall *PDll_DoneDSObj)(void*);
PDll_DoneDSObj Dll_DoneDSObj;
typedef void (__stdcall *PDll_DSFreeMem)(void*,unsigned short);
PDll_DSFreeMem Dll_DSFreeMem;
typedef short (__stdcall *PDll_DoneHandle)(OType*);
PDll_DoneHandle Dll_DoneHandle;
typedef short (__stdcall *PDll_CopyHandle)(OType,OType*);
PDll_CopyHandle Dll_CopyHandle;
typedef short (__stdcall *PDll_CopyNewHandle)(OType,OType*);
PDll_CopyNewHandle Dll_CopyNewHandle;
typedef short (__stdcall *PDll_HandleGetType)(OType,unsigned char*);
PDll_HandleGetType Dll_HandleGetType;
typedef void  (__stdcall *PDll_ClearDatServ)(void);
PDll_ClearDatServ Dll_ClearDatServ;

typedef short (__stdcall *PDll_InitTDesc)(const char*,OType*);
PDll_InitTDesc Dll_InitTDesc;
typedef short (__stdcall *PDll_GetTDesc)(OType,const char*,OType*);
PDll_GetTDesc Dll_GetTDesc;
typedef short (__stdcall *PDll_GetTDescF)(const char*,const char*,OType*);
PDll_GetTDescF Dll_GetTDescF;
typedef short (__stdcall *PDll_TDCheckDesc)(OType,OType,unsigned char*);
PDll_TDCheckDesc Dll_TDCheckDesc;
typedef short (__stdcall *PDll_TDGetArrayCounter)(OType);
PDll_TDGetArrayCounter Dll_TDGetArrayCounter;
typedef short (__stdcall *PDll_TDGetObjCounter)(OType);
PDll_TDGetObjCounter Dll_TDGetObjCounter;
typedef short (__stdcall *PDll_TDGetName)(OType,char*);
PDll_TDGetName Dll_TDGetName;
typedef short (__stdcall *PDll_TDGetLongName)(OType,char*);
PDll_TDGetLongName Dll_TDGetLongName;
typedef short (__stdcall *PDll_TDGetAnglName)(OType,char*);
PDll_TDGetAnglName Dll_TDGetAnglName;
typedef short (__stdcall *PDll_TDGetRusName)(OType,char*);
PDll_TDGetRusName Dll_TDGetRusName;
typedef short (__stdcall *PDll_TDSetName)(OType,const char*);
PDll_TDSetName Dll_TDSetName;
typedef short (__stdcall *PDll_TDSetLongName)(OType,const char*);
PDll_TDSetLongName Dll_TDSetLongName;
typedef short (__stdcall *PDll_TDSetAnglName)(OType,const char*);
PDll_TDSetAnglName Dll_TDSetAnglName;
typedef short (__stdcall *PDll_TDSetRusName)(OType,const char*);
PDll_TDSetRusName Dll_TDSetRusName;
typedef short (__stdcall *PDll_TDGetArrayIndexByNumber)(unsigned char,OType);
PDll_TDGetArrayIndexByNumber Dll_TDGetArrayIndexByNumber;
typedef short (__stdcall *PDll_TDGetArrayIndex)(const char*,OType);
PDll_TDGetArrayIndex Dll_TDGetArrayIndex;
typedef short (__stdcall *PDll_TDGetArrayNumber)(OType,const char*);
PDll_TDGetArrayNumber Dll_TDGetArrayNumber;
typedef short (__stdcall *PDll_TDGetObjIndexByNumber)(unsigned char,OType);
PDll_TDGetObjIndexByNumber Dll_TDGetObjIndexByNumber;
typedef short (__stdcall *PDll_TDGetObjIndex)(const char*,OType);
PDll_TDGetObjIndex Dll_TDGetObjIndex;
typedef short (__stdcall *PDll_TDGetObjNumber)(OType,const char*);
PDll_TDGetObjNumber Dll_TDGetObjNumber;
typedef short (__stdcall *PDll_TDGetFieldIndex)(const char*,OType);
PDll_TDGetFieldIndex Dll_TDGetFieldIndex;
typedef short (__stdcall *PDll_TDInsertFD)(OType,OType);
PDll_TDInsertFD Dll_TDInsertFD;
typedef short (__stdcall *PDll_TDAtInsertFD)(OType,short,OType);
PDll_TDAtInsertFD Dll_TDAtInsertFD;
typedef short (__stdcall *PDll_TDAtPutFD)(OType,short,OType);
PDll_TDAtPutFD Dll_TDAtPutFD;
typedef short (__stdcall *PDll_TDAtFreeFD)(OType,short);
PDll_TDAtFreeFD Dll_TDAtFreeFD;
typedef LongBoolean (__stdcall *PDll_TDCheckRepeating)(OType,char*);
PDll_TDCheckRepeating Dll_TDCheckRepeating;
typedef short (__stdcall *PDll_PutTDesc)(const char*,OType,LongBoolean);
PDll_PutTDesc Dll_PutTDesc;
typedef short (__stdcall *PDll_TDFreeAll)(OType);
PDll_TDFreeAll Dll_TDFreeAll;
typedef short (__stdcall *PDll_GetTDescName)(OType,char*);
PDll_GetTDescName Dll_GetTDescName;
typedef short (__stdcall *PDll_GetTDescFldsN)(OType,const char*,PCFDData);
PDll_GetTDescFldsN Dll_GetTDescFldsN;
typedef short (__stdcall *PDll_GetTDescFldsI)(OType,unsigned short,PCFDData);
PDll_GetTDescFldsI Dll_GetTDescFldsI;

typedef short (__stdcall *PDll_GetTDKeyStr)(OType,unsigned char,char*);
PDll_GetTDKeyStr Dll_GetTDKeyStr;
typedef short (__stdcall *PDll_MakeDKeyTablDesc)(OType,OType*);
PDll_MakeDKeyTablDesc Dll_MakeDKeyTablDesc;
typedef short (__stdcall *PDll_GetAnyKeyStr)(OType,OType,unsigned char,char*);
PDll_GetAnyKeyStr Dll_GetAnyKeyStr;
typedef short (__stdcall *PDll_GetTDDefinedValue)(OType,const char*,OType*);
PDll_GetTDDefinedValue Dll_GetTDDefinedValue;
typedef float (__stdcall *PDll_GetDefSingle)(OType,const char*);
PDll_GetDefSingle Dll_GetDefSingle;
typedef long (__stdcall *PDll_GetDefLong)(OType,const char*);
PDll_GetDefLong Dll_GetDefLong;
typedef short (__stdcall *PDll_GetDefStr)(OType,const char*,char*);
PDll_GetDefStr Dll_GetDefStr;
typedef short (__stdcall *PDll_TDGetAtomNameAt)(OType,short,char*);
PDll_TDGetAtomNameAt Dll_TDGetAtomNameAt;
typedef short (__stdcall *PDll_TDInsertNewAtom)(OType,const char*);
PDll_TDInsertNewAtom Dll_TDInsertNewAtom;
typedef short (__stdcall *PDll_InitFDesc)(const char*,const char*,unsigned char,short,OType*);
PDll_InitFDesc Dll_InitFDesc;
typedef short (__stdcall *PDll_GetFDescByName)(OType,const char*,OType*);
PDll_GetFDescByName Dll_GetFDescByName;
typedef short (__stdcall *PDll_GetTDescCounter)(OType,unsigned short*);
PDll_GetTDescCounter Dll_GetTDescCounter;
typedef short (__stdcall *PDll_SetFDescSlave)(OType,LongBoolean);
PDll_SetFDescSlave Dll_SetFDescSlave;
typedef LongBoolean  (__stdcall *PDll_IsFDescSlave)(OType);
PDll_IsFDescSlave Dll_IsFDescSlave;
typedef short (__stdcall *PDll_GetFDescByNumber)(OType,unsigned short,OType*);
PDll_GetFDescByNumber Dll_GetFDescByNumber;
typedef short (__stdcall *PDll_GetFDescFlds)(OType,PCFDData);
PDll_GetFDescFlds Dll_GetFDescFlds;
typedef short (__stdcall *PDll_SetFDescFlds)(OType,PCFDData);
PDll_SetFDescFlds Dll_SetFDescFlds;
typedef short (__stdcall *PDll_LFDescCompary)(OType,OType,unsigned char*);
PDll_LFDescCompary Dll_LFDescCompary;
typedef short (__stdcall *PDll_GetFDescAccess)(OType,unsigned char*);
PDll_GetFDescAccess Dll_GetFDescAccess;
typedef unsigned short (__stdcall *PDll_GetFDMask)(OType);
PDll_GetFDMask Dll_GetFDMask;
typedef short (__stdcall *PDll_SetFDMask)(OType,unsigned short);
PDll_SetFDMask Dll_SetFDMask;
typedef short (__stdcall *PDll_GetFDescRC)(OType,unsigned char*);
PDll_GetFDescRC Dll_GetFDescRC;
typedef short (__stdcall *PDll_GetFDescKey)(OType,unsigned char*);
PDll_GetFDescKey Dll_GetFDescKey;
typedef short (__stdcall *PDll_SetFDescKey)(OType);
PDll_SetFDescKey Dll_SetFDescKey;
typedef void (__stdcall *PDll_GetSystemDir)(char*);
PDll_GetSystemDir Dll_GetSystemDir;
typedef short (__stdcall *PDll_PutScale)(CScalLineType*);
PDll_PutScale Dll_PutScale;
typedef short (__stdcall *PDll_GetScale)(CScalLineType*);
PDll_GetScale Dll_GetScale;
typedef short (__stdcall *PDll_GetFDFactor)(OType,const char*,const char*,float*);
PDll_GetFDFactor Dll_GetFDFactor;
typedef short (__stdcall *PDll_GetFDNFactor)(OType,short,const char*,float*);
PDll_GetFDNFactor Dll_GetFDNFactor;
typedef short (__stdcall *PDll_GetFDFactorEx)(OType,const char*,const char*,char*,float*);
PDll_GetFDFactorEx Dll_GetFDFactorEx;
typedef short (__stdcall *PDll_GetFDNFactorEx)(OType,short,const char*,char*,float*);
PDll_GetFDNFactorEx Dll_GetFDNFactorEx;
typedef short (__stdcall *PDll_GetFDArrDesc)(OType,OType*);
PDll_GetFDArrDesc Dll_GetFDArrDesc;
typedef short (__stdcall *PDll_SetFDArrDesc)(OType,OType);
PDll_SetFDArrDesc Dll_SetFDArrDesc;
typedef short (__stdcall *PDll_SetFDClass)(OType,const char*);
PDll_SetFDClass Dll_SetFDClass;
typedef short (__stdcall *PDll_GetFDClass)(OType,char*);
PDll_GetFDClass Dll_GetFDClass;

typedef short (__stdcall *PDll_CreateSysData)(const char*,OType*);
PDll_CreateSysData Dll_CreateSysData;
typedef short (__stdcall *PDll_InitSysData)(const char*,OType*);
PDll_InitSysData Dll_InitSysData;
typedef short (__stdcall *PDll_GetLogFile)(const char *FileName,LongBoolean*,OType,OType*);
PDll_GetLogFile Dll_GetLogFile;
typedef short (__stdcall *PDll_RemoveLogFile)(OType,OType);
PDll_RemoveLogFile Dll_RemoveLogFile;
typedef short (__stdcall *PDll_GetResFileName)(OType,char*);
PDll_GetResFileName Dll_GetResFileName;
typedef unsigned short (__stdcall *PDll_ResStreamSt)(OType);
PDll_ResStreamSt Dll_ResStreamSt;
typedef LongBoolean (__stdcall *PDll_ResIsModified)(OType);
PDll_ResIsModified Dll_ResIsModified;
typedef short (__stdcall *PDll_PackRes)(OType);
PDll_PackRes Dll_PackRes;
typedef short (__stdcall *PDll_ResPutTD)(OType,OType,const char*);
PDll_ResPutTD Dll_ResPutTD;
typedef short (__stdcall *PDll_ResDeleteTD)(OType,const char*);
PDll_ResDeleteTD Dll_ResDeleteTD;
typedef short (__stdcall *PDll_ResRemoveMemTD)(OType,const char*);
PDll_ResRemoveMemTD Dll_ResRemoveMemTD;
typedef LongBoolean (__stdcall *PDll_ExistInRes)(const char*,OType);
PDll_ExistInRes Dll_ExistInRes;
typedef short (__stdcall *PDll_ResGetKeyCounter)(OType);
PDll_ResGetKeyCounter Dll_ResGetKeyCounter;
typedef short (__stdcall *PDll_ResGetKeyAt)(OType,short,char*);
PDll_ResGetKeyAt Dll_ResGetKeyAt;
typedef short (__stdcall *PDll_ResGetMemTD)(OType,short,OType*);
PDll_ResGetMemTD Dll_ResGetMemTD;
typedef short (__stdcall *PDll_ResAddMemTD)(OType,OType);
PDll_ResAddMemTD Dll_ResAddMemTD;

typedef short (__stdcall *PDll_SysLFInitOpen)(const char*,OType*);
PDll_SysLFInitOpen Dll_SysLFInitOpen;
typedef short (__stdcall *PDll_SysLFInitOpenEx)(const char *FileName, OType *LFHandle, int LROption, int ObjOption);
PDll_SysLFInitOpenEx Dll_SysLFInitOpenEx;
typedef short (__stdcall *PDll_SysLFCreate)(const char*,OType,OType*);
PDll_SysLFCreate Dll_SysLFCreate;
typedef short (__stdcall *PDll_SaveNewObj)(const char*,const char*,LongBoolean,LongBoolean,OType,OType);
PDll_SaveNewObj Dll_SaveNewObj;
typedef short (__stdcall *PDll_SaveNewObjEx)(const char*,const char*,LongBoolean,LongBoolean,OType,OType,OType*);
PDll_SaveNewObjEx Dll_SaveNewObjEx;
typedef short (__stdcall *PDll_LFAppend)(OType,OType,unsigned short);
PDll_LFAppend Dll_LFAppend;
typedef short (__stdcall *PDll_LFPackTo)(OType,const char*,long*);
PDll_LFPackTo Dll_LFPackTo;
typedef short (__stdcall *PDll_FindFirst)(OType,OType,OType*);
PDll_FindFirst Dll_FindFirst;
typedef short (__stdcall *PDll_FindFirstLocal)(OType,OType,const char*,OType*);
PDll_FindFirstLocal Dll_FindFirstLocal;
typedef short (__stdcall *PDll_FindNext)(OType,OType*);
PDll_FindNext Dll_FindNext;
typedef short (__stdcall *PDll_Goto_BeginTable)(OType);
PDll_Goto_BeginTable Dll_Goto_BeginTable;
typedef short (__stdcall *PDll_Goto_NextTable)(OType);
PDll_Goto_NextTable Dll_Goto_NextTable;
typedef long (__stdcall *PDll_GetIndexViewsList)(const char*,const char*,const char*,long,char*);
PDll_GetIndexViewsList Dll_GetIndexViewsList;
typedef long (__stdcall *PDll_GetWSViewsList)(const char*,const char*,const char*,long,char**);
PDll_GetWSViewsList Dll_GetWSViewsList;
typedef long (__stdcall *PDll_GetWSViewsListXml)(const char*, const char*, int, char **);
PDll_GetWSViewsListXml Dll_GetWSViewsListXml;
typedef long (__stdcall *PDll_FreeDSMem)(char *pointer, int Size, int Option);
PDll_FreeDSMem Dll_FreeDSMem;
typedef short (__stdcall *PDll_TableExist)(const char*,OType);
PDll_TableExist Dll_TableExist;
typedef short (__stdcall *PDll_GetCurTable)(OType,OType *);
PDll_GetCurTable Dll_GetCurTable;
typedef short (__stdcall *PDll_Get_Table)(const char*,OType,OType*);
PDll_Get_Table Dll_Get_Table;
typedef short (__stdcall *PDll_Get_TableNew)(const char*,OType,OType*);
PDll_Get_TableNew Dll_Get_TableNew;
typedef short (__stdcall *PDll_GetTableName)(OType,char*);
PDll_GetTableName Dll_GetTableName;
typedef short (__stdcall *PDll_GetWSHandle)(OType,OType*);
PDll_GetWSHandle Dll_GetWSHandle;
typedef short (__stdcall *PDll_LRChangeName)(OType,const char*);
PDll_LRChangeName Dll_LRChangeName;
typedef short (__stdcall *PDll_LRPutTDesc)(OType,OType);
PDll_LRPutTDesc Dll_LRPutTDesc;
typedef short (__stdcall *PDll_Goto_BeginObj)(OType);
PDll_Goto_BeginObj Dll_Goto_BeginObj;
typedef short (__stdcall *PDll_Goto_FastBeginObj)(OType);
PDll_Goto_FastBeginObj Dll_Goto_FastBeginObj;
typedef short (__stdcall *PDll_Goto_NextObj)(OType);
PDll_Goto_NextObj Dll_Goto_NextObj;
typedef short (__stdcall *PDll_Goto_FastNextObj)(OType);
PDll_Goto_FastNextObj Dll_Goto_FastNextObj;
typedef short (__stdcall *PDll_LRPutObj)(OType,OType,LongBoolean,LongBoolean);
PDll_LRPutObj Dll_LRPutObj;
typedef unsigned char (__stdcall *PDll_LRCheckKeyObj)(OType,OType,OType,unsigned short*,OType*);
PDll_LRCheckKeyObj Dll_LRCheckKeyObj;
typedef short (__stdcall *PDll_GetCurObj)(OType,OType*);
PDll_GetCurObj Dll_GetCurObj;
typedef short (__stdcall *PDll_GetFastCurObj)(OType,OType*);
PDll_GetFastCurObj Dll_GetFastCurObj;
typedef short (__stdcall *PDll_GetTrueCurObj)(OType,OType*);
PDll_GetTrueCurObj Dll_GetTrueCurObj;
typedef short (__stdcall *PDll_GetTrueFastCurObj)(OType,OType*);
PDll_GetTrueFastCurObj Dll_GetTrueFastCurObj;
typedef short (__stdcall *PDll_ObjTDCopy)(OType,OType,OType*);
PDll_ObjTDCopy Dll_ObjTDCopy;
typedef short (__stdcall *PDll_ObjCopyBlank)(OType,OType*);
PDll_ObjCopyBlank Dll_ObjCopyBlank;
typedef short (__stdcall *PDll_BlankObj)(OType);
PDll_BlankObj Dll_BlankObj;
typedef short (__stdcall *PDll_GetObjByIdN)(OType,unsigned short,OType*);
PDll_GetObjByIdN Dll_GetObjByIdN;
typedef short (__stdcall *PDll_GetObjByEIdN)(OType,unsigned short,unsigned short,OType*);
PDll_GetObjByEIdN Dll_GetObjByEIdN;
typedef short (__stdcall *PDll_ObjTDInit)(const char*,const char*,OType*);
PDll_ObjTDInit Dll_ObjTDInit;
typedef short (__stdcall *PDll_ObjTDInitH)(OType,OType*);
PDll_ObjTDInitH Dll_ObjTDInitH;
typedef short (__stdcall *PDll_ObjAtPut)(OType,short,OType);
PDll_ObjAtPut Dll_ObjAtPut;
typedef short (__stdcall *PDll_ObjWriteASCII)(OType,const char*,LongBoolean);
PDll_ObjWriteASCII Dll_ObjWriteASCII;
typedef short (__stdcall *PDll_GetWSObj)(OType,unsigned short,const char*,OType*);
PDll_GetWSObj Dll_GetWSObj;
typedef short (__stdcall *PDll_GetWSKeyObj)(OType,const char*,const char*,OType*);
PDll_GetWSKeyObj Dll_GetWSKeyObj;
typedef short (__stdcall *PDll_ImportObj)(OType,const char*,const char*,OType*);
PDll_ImportObj Dll_ImportObj;
typedef short (__stdcall *PDll_ExportObj)(const char*,OType);
PDll_ExportObj Dll_ExportObj;
typedef short (__stdcall *PDll_ObjInit)(OType*);
PDll_ObjInit Dll_ObjInit;
typedef short (__stdcall *PDll_GetKeyStr)(OType,unsigned short,unsigned char,char*);
PDll_GetKeyStr Dll_GetKeyStr;
typedef short (__stdcall *PDll_ObjGetAnyKeyStr)(OType,OType,unsigned short,unsigned char,char*);
PDll_ObjGetAnyKeyStr Dll_ObjGetAnyKeyStr;
typedef short (__stdcall *PDll_GetMetaKeyStr)(OType,unsigned char,char*);
PDll_GetMetaKeyStr Dll_GetMetaKeyStr;
typedef unsigned short (__stdcall *PDll_GetRowNumber)(OType,OType,const char*);
PDll_GetRowNumber Dll_GetRowNumber;
typedef short (__stdcall *PDll_GetTemplate)(OType,OType*);
PDll_GetTemplate Dll_GetTemplate;
typedef short (__stdcall *PDll_SetTemplate)(OType,OType);
PDll_SetTemplate Dll_SetTemplate;
typedef short (__stdcall *PDll_ObjAdd_ObVal)(OType,OType,OType);
PDll_ObjAdd_ObVal Dll_ObjAdd_ObVal;
typedef short (__stdcall *PDll_ObjAddAt_ObVal)(OType,OType,OType,short);
PDll_ObjAddAt_ObVal Dll_ObjAddAt_ObVal;
typedef short (__stdcall *PDll_ObjAdd_Arr)(OType,OType,OType);
PDll_ObjAdd_Arr Dll_ObjAdd_Arr;
typedef short (__stdcall *PDll_MoveToBuf)(OType,void*,long);
PDll_MoveToBuf Dll_MoveToBuf;
typedef short (__stdcall *PDll_MoveFromBuf)(OType,void*,long);
PDll_MoveFromBuf Dll_MoveFromBuf;
typedef long (__stdcall *PDll_GetObjBinarySize)(OType);
PDll_GetObjBinarySize Dll_GetObjBinarySize;
typedef LongBoolean (__stdcall *PDll_GetObjState)(OType,unsigned short);
PDll_GetObjState Dll_GetObjState;
typedef short (__stdcall *PDll_SetObjState)(OType,unsigned short,LongBoolean);
PDll_SetObjState Dll_SetObjState;
typedef short (__stdcall *PDll_GetObjByName)(OType,const char*,OType*);
PDll_GetObjByName Dll_GetObjByName;
typedef short (__stdcall *PDll_GetObjByNumber)(OType,short,OType*);
PDll_GetObjByNumber Dll_GetObjByNumber;
typedef LongBoolean (__stdcall *PDll_ChkGroup)(OType,OType);
PDll_ChkGroup Dll_ChkGroup;
typedef short (__stdcall *PDll_ReplaceArr)(OType,const char*,unsigned char,unsigned char,unsigned short);
PDll_ReplaceArr Dll_ReplaceArr;
typedef short (__stdcall *PDll_DeleteObj)(OType,OType);
PDll_DeleteObj Dll_DeleteObj;
typedef short (__stdcall *PDll_RestoreObj)(OType,OType);
PDll_RestoreObj Dll_RestoreObj;
typedef short (__stdcall *PDll_ObjTakeByTDesc)(OType,OType,unsigned short);
PDll_ObjTakeByTDesc Dll_ObjTakeByTDesc;
typedef short (__stdcall *PDll_ObjGetHandleIndex)(OType,OType);
PDll_ObjGetHandleIndex Dll_ObjGetHandleIndex;
typedef short (__stdcall *PDll_ImportStrObj)(OType,char*,OType*);
PDll_ImportStrObj Dll_ImportStrObj;
typedef short (__stdcall *PDll_AddHistory)(OType,const char*,const char*);
PDll_AddHistory Dll_AddHistory;
typedef short (__stdcall *PDll_IncVersion)(OType,const char*);
PDll_IncVersion Dll_IncVersion;

typedef short (__stdcall *PDll_InitCurve)(OType,unsigned short,OType*);
PDll_InitCurve Dll_InitCurve;
typedef unsigned short (__stdcall *PDll_CurveGetCount)(OType);
PDll_CurveGetCount Dll_CurveGetCount;
typedef short (__stdcall *PDll_CurveSetParams)(OType,float,float,float,const char*);
PDll_CurveSetParams Dll_CurveSetParams;
typedef short (__stdcall *PDll_CurveGetParams)(OType,float*,float*,float*,char*);
PDll_CurveGetParams Dll_CurveGetParams;
typedef short (__stdcall *PDll_CurveSetMinMaxVal)(OType,unsigned short,OType,OType);
PDll_CurveSetMinMaxVal Dll_CurveSetMinMaxVal;
typedef short (__stdcall *PDll_CurveGetMinMaxVal)(OType,unsigned short,OType*,OType*,long,long);
PDll_CurveGetMinMaxVal Dll_CurveGetMinMaxVal;
typedef short (__stdcall *PDll_CurveDoMinMaxVal)(OType,long,long);
PDll_CurveDoMinMaxVal Dll_CurveDoMinMaxVal;
typedef short (__stdcall *PDll_CurveGetArr)(OType,OType*);
PDll_CurveGetArr Dll_CurveGetArr;
typedef short (__stdcall *PDll_CurveGetColor)(OType,unsigned short,unsigned char*);
PDll_CurveGetColor Dll_CurveGetColor;
typedef short (__stdcall *PDll_CurveSetColor)(OType,unsigned short,unsigned char);
PDll_CurveSetColor Dll_CurveSetColor;
typedef short (__stdcall *PDll_CurveSetStatus)(OType,unsigned char);
PDll_CurveSetStatus Dll_CurveSetStatus;
typedef short (__stdcall *PDll_CurveGetStatus)(OType,unsigned char*);
PDll_CurveGetStatus Dll_CurveGetStatus;
typedef short (__stdcall *PDll_CurveGetDataHandle)(OType,OType*);
PDll_CurveGetDataHandle Dll_CurveGetDataHandle;

typedef short (__stdcall *PDll_ArrayFInit)(const char*,unsigned char,TSByteArray,long,OType*);
PDll_ArrayFInit Dll_ArrayFInit;
typedef short (__stdcall *PDll_GetArrayByName)(OType*,const char*,OType);
PDll_GetArrayByName Dll_GetArrayByName;
typedef short (__stdcall *PDll_GetArrayByNumber)(OType*,unsigned short,OType);
PDll_GetArrayByNumber Dll_GetArrayByNumber;
typedef short (__stdcall *PDll_CopyArrayByName)(OType*,const char*,OType);
PDll_CopyArrayByName Dll_CopyArrayByName;
typedef short (__stdcall *PDll_CopyArrayByIndex)(OType*,short,OType);
PDll_CopyArrayByIndex Dll_CopyArrayByIndex;
typedef short (__stdcall *PDll_ArrayGetName)(OType,char*);
PDll_ArrayGetName Dll_ArrayGetName;
typedef short (__stdcall *PDll_ArrayGetDesc)(OType,OType*);
PDll_ArrayGetDesc Dll_ArrayGetDesc;
typedef short (__stdcall *PDll_ArrayReplaceDesc)(OType,OType);
PDll_ArrayReplaceDesc Dll_ArrayReplaceDesc;
typedef short (__stdcall *PDll_ArrayInit)(long,const char*,OType,LongBoolean,OType*);
PDll_ArrayInit Dll_ArrayInit;
/*
typedef short (__stdcall *PDll_ArrayWriteBin)(OType,TXStream*);
PDll_ArrayWriteBin Dll_ArrayWriteBin;
*/
typedef short (__stdcall *PDll_ArrayGetState)(OType,unsigned short*);
PDll_ArrayGetState Dll_ArrayGetState;
typedef short (__stdcall *PDll_ArraySetState)(OType,unsigned short);
PDll_ArraySetState Dll_ArraySetState;
typedef short (__stdcall *PDll_ArrayTDInit)(OType*,const char*,const char*,const char*);
PDll_ArrayTDInit Dll_ArrayTDInit;
typedef short (__stdcall *PDll_ArrayFDInit)(OType*,OType);
PDll_ArrayFDInit Dll_ArrayFDInit;
typedef short (__stdcall *PDll_ArrayTDInitH)(OType*,OType,const char*);
PDll_ArrayTDInitH Dll_ArrayTDInitH;
typedef short (__stdcall *PDll_GetArrayByIndex)(OType*,short,OType);
PDll_GetArrayByIndex Dll_GetArrayByIndex;
typedef short (__stdcall *PDll_ArrayCopyBlank)(OType,OType*);
PDll_ArrayCopyBlank Dll_ArrayCopyBlank;
typedef short (__stdcall *PDll_ArrayGetObjData)(OType,long,OType*);
PDll_ArrayGetObjData Dll_ArrayGetObjData;
typedef short (__stdcall *PDll_ArrayGetColumnObj)(OType,unsigned char,long,OType*);
PDll_ArrayGetColumnObj Dll_ArrayGetColumnObj;
typedef short (__stdcall *PDll_ArrayPutObjData)(OType,long,OType);
PDll_ArrayPutObjData Dll_ArrayPutObjData;
typedef short (__stdcall *PDll_ArrayPutData)(OType,long,unsigned short,void*);
PDll_ArrayPutData Dll_ArrayPutData;
typedef short (__stdcall *PDll_ArrayPutHugeData)(OType,long,long,void*);
PDll_ArrayPutHugeData Dll_ArrayPutHugeData;
typedef short (__stdcall *PDll_ArrayGetData)(OType,long,unsigned short,void*);
PDll_ArrayGetData Dll_ArrayGetData;
typedef short (__stdcall *PDll_ArrayGetHugeData)(OType,long,long,void*);
PDll_ArrayGetHugeData Dll_ArrayGetHugeData;
typedef short (__stdcall *PDll_MoveSingleColumnData)(OType,unsigned char,long,long,void*);
PDll_MoveSingleColumnData Dll_MoveSingleColumnData;
typedef short (__stdcall *PDll_LoadSingleColumnData)(OType,unsigned char,long,long,void*);
PDll_LoadSingleColumnData Dll_LoadSingleColumnData;
typedef short (__stdcall *PDll_ArrayGetStrColumnData)(OType,unsigned char,long,char*);
PDll_ArrayGetStrColumnData Dll_ArrayGetStrColumnData;
typedef short (__stdcall *PDll_ArrayGetFStrColumnData)(OType,unsigned char,long,char*);
PDll_ArrayGetFStrColumnData Dll_ArrayGetFStrColumnData;
typedef float (__stdcall *PDll_ArrayGetSingleColumnData)(OType,unsigned char,long);
PDll_ArrayGetSingleColumnData Dll_ArrayGetSingleColumnData;
typedef short (__stdcall *PDll_ArrayGetSingleColData)(OType ArrHandle,unsigned char Column,long Index,unsigned short Count,float*,long);
PDll_ArrayGetSingleColData Dll_ArrayGetSingleColData;
typedef float (__stdcall *PDll_ArrayGetSingle)(unsigned char,long);
PDll_ArrayGetSingle Dll_ArrayGetSingle;
typedef int (__stdcall *PDll_GetArraySingle)(OType ArrHandle, long Index, const char *ColName, float *Value);
PDll_GetArraySingle Dll_GetArraySingle;
typedef long (__stdcall *PDll_GetArrayLong)(OType,long,const char*);
PDll_GetArrayLong Dll_GetArrayLong;
typedef long (__stdcall *PDll_GetArrayString)(OType,long,const char*,char*);
PDll_GetArrayString Dll_GetArrayString;
typedef long (__stdcall *PDll_GetArrayFString)(OType,long,const char*,char*);
PDll_GetArrayFString Dll_GetArrayFString;
typedef long (__stdcall *PDll_PutArraySingle)(OType,long,const char*,float);
PDll_PutArraySingle Dll_PutArraySingle;
typedef long (__stdcall *PDll_PutArrayLong)(OType,long,const char*,long);
PDll_PutArrayLong Dll_PutArrayLong;
typedef long (__stdcall *PDll_PutArrayString)(OType,long,const char*,const char*);
PDll_PutArrayString Dll_PutArrayString;
typedef long  (__stdcall *PDll_ArrayGetLongColumnData)(OType,unsigned char,long);
PDll_ArrayGetLongColumnData Dll_ArrayGetLongColumnData;
typedef short (__stdcall *PDll_ArrayPutStrColumnData)(OType,unsigned char,long,const char*);
PDll_ArrayPutStrColumnData Dll_ArrayPutStrColumnData;
typedef short (__stdcall *PDll_ArrayPutSingleColumnData)(OType,unsigned char,long,float);
PDll_ArrayPutSingleColumnData Dll_ArrayPutSingleColumnData;
typedef short (__stdcall *PDll_ArrayPutLongColumnData)(OType,unsigned char,long,long);
PDll_ArrayPutLongColumnData Dll_ArrayPutLongColumnData;
typedef long (__stdcall *PDll_ArrayGetLen)(OType);
PDll_ArrayGetLen Dll_ArrayGetLen;
typedef short (__stdcall *PDll_ArraySetLen)(OType,long);
PDll_ArraySetLen Dll_ArraySetLen;
typedef short (__stdcall *PDll_ArrayGetElementSize)(OType,unsigned short*);
PDll_ArrayGetElementSize Dll_ArrayGetElementSize;
typedef short (__stdcall *PDll_ArrayGetItemType)(OType,unsigned char,unsigned char*,unsigned short*);
PDll_ArrayGetItemType Dll_ArrayGetItemType;
typedef short (__stdcall *PDll_ArrayBlankValue)(OType,void*);
PDll_ArrayBlankValue Dll_ArrayBlankValue;
typedef short (__stdcall *PDll_ArrayValIsBlank)(OType,unsigned char,long,long,LongBoolean*);
PDll_ArrayValIsBlank Dll_ArrayValIsBlank;
typedef short (__stdcall *PDll_ArrayBlankIndex)(OType,long);
PDll_ArrayBlankIndex Dll_ArrayBlankIndex;
typedef LongBoolean (__stdcall *PDll_ArrayColumnIsBlank)(OType,unsigned char);
PDll_ArrayColumnIsBlank Dll_ArrayColumnIsBlank;
typedef short (__stdcall *PDll_ArrayDoBlankColumn)(OType,unsigned char,long,long);
PDll_ArrayDoBlankColumn Dll_ArrayDoBlankColumn;
typedef LongBoolean (__stdcall *PDll_ArrayColumnIndexIsBlank)(OType,unsigned char,long);
PDll_ArrayColumnIndexIsBlank Dll_ArrayColumnIndexIsBlank;
typedef short (__stdcall *PDll_ArrayGetColumns)(OType,unsigned char*);
PDll_ArrayGetColumns Dll_ArrayGetColumns;
typedef short (__stdcall *PDll_ArrayGetColNumByName)(OType,const char*,unsigned char*);
PDll_ArrayGetColNumByName Dll_ArrayGetColNumByName;
typedef short (__stdcall *PDll_ArrayDeleteLine)(OType,long);
PDll_ArrayDeleteLine Dll_ArrayDeleteLine;
typedef short (__stdcall *PDll_ArrayDeleteColumnLine)(OType,unsigned char,long);
PDll_ArrayDeleteColumnLine Dll_ArrayDeleteColumnLine;
typedef short (__stdcall *PDll_ArrayInsertLine)(OType,long);
PDll_ArrayInsertLine Dll_ArrayInsertLine;
typedef short (__stdcall *PDll_ArrayInsertLineN)(OType,long,long);
PDll_ArrayInsertLineN Dll_ArrayInsertLineN;
typedef short (__stdcall *PDll_ArrayInsertColumnLine)(OType,unsigned char,long);
PDll_ArrayInsertColumnLine Dll_ArrayInsertColumnLine;
typedef short (__stdcall *PDll_ArrayShiftColumnLine)(OType,unsigned char,long);
PDll_ArrayShiftColumnLine Dll_ArrayShiftColumnLine;
typedef short (__stdcall *PDll_ArrayAtShiftColumnLine)(OType,unsigned char,long,long);
PDll_ArrayAtShiftColumnLine Dll_ArrayAtShiftColumnLine;
typedef short (__stdcall *PDll_ArrayDelInter)(OType,long,long);
PDll_ArrayDelInter Dll_ArrayDelInter;
typedef short (__stdcall *PDll_ArrayCopyColumn)(OType,OType,unsigned char,unsigned char,unsigned char);
PDll_ArrayCopyColumn Dll_ArrayCopyColumn;
typedef short (__stdcall *PDll_GetNearstRigthNumber)(OType,unsigned char,float,long*);
PDll_GetNearstRigthNumber Dll_GetNearstRigthNumber;
typedef short (__stdcall *PDll_GetNumberByValue)(OType,unsigned char,float,long*);
PDll_GetNumberByValue Dll_GetNumberByValue;
typedef long  (__stdcall *PDll_GetFirstNumberByValue)(OType,unsigned char,float,long*);
PDll_GetFirstNumberByValue Dll_GetFirstNumberByValue;
typedef short (__stdcall *PDll_ArrayRevert)(OType);
PDll_ArrayRevert Dll_ArrayRevert;
typedef short (__stdcall *PDll_ArrayChangeNull)(OType,float,float,unsigned char,unsigned char,unsigned char);
PDll_ArrayChangeNull Dll_ArrayChangeNull;
typedef short (__stdcall *PDll_ArrayDoMinMax)(OType,long,long);
PDll_ArrayDoMinMax Dll_ArrayDoMinMax;
typedef short (__stdcall *PDll_ArrayGetMinMax)(OType,unsigned short,OType*,OType*);
PDll_ArrayGetMinMax Dll_ArrayGetMinMax;
typedef short (__stdcall *PDll_ArrayGetMinMaxH)(OType,unsigned short,long,long,float*,float*,float*,long*,long*);
PDll_ArrayGetMinMaxH Dll_ArrayGetMinMaxH;
typedef short (__stdcall *PDll_ArraySort)(OType,unsigned char,long,long);
PDll_ArraySort Dll_ArraySort;

typedef float (__stdcall *PDll_GetPal2Value)(OType,float,unsigned char,unsigned short,unsigned short,unsigned short,unsigned short);
PDll_GetPal2Value Dll_GetPal2Value;

typedef float (__stdcall *PDll_GetPal3Value)(OType,float,float,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short);
PDll_GetPal3Value Dll_GetPal3Value;

typedef short (__stdcall *PDll_DoPal2Value)(OType,OType,unsigned char,unsigned char,long,long,unsigned short,unsigned short,unsigned short,unsigned short);
PDll_DoPal2Value Dll_DoPal2Value;

typedef short (__stdcall *PDll_DoPal3Value)(OType,OType,unsigned char,long,long,float,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short);
PDll_DoPal3Value Dll_DoPal3Value;

typedef float (__stdcall *PDll_GetPalParam)(OType,unsigned char);
PDll_GetPalParam Dll_GetPalParam;
typedef unsigned char (__stdcall *PDll_GetPalColumn)(OType,float);
PDll_GetPalColumn Dll_GetPalColumn;
typedef short (__stdcall *PDll_ASqr)(OType,unsigned char,unsigned char,long,long);
PDll_ASqr Dll_ASqr;
typedef short (__stdcall *PDll_ASqrt)(OType,unsigned char,unsigned char,long,long);
PDll_ASqrt Dll_ASqrt;
typedef short (__stdcall *PDll_ArrayRevLin)(OType,OType,float,float,unsigned char,unsigned char,long,long);
PDll_ArrayRevLin Dll_ArrayRevLin;
typedef short (__stdcall *PDll_ArrayExponent)(OType,OType,unsigned char,unsigned char,long,long);
PDll_ArrayExponent Dll_ArrayExponent;
typedef short (__stdcall *PDll_ArrayExp10)(OType,OType,unsigned char,unsigned char,long,long);
PDll_ArrayExp10 Dll_ArrayExp10;
typedef short (__stdcall *PDll_ArrayPower)(OType,OType,float,unsigned char,unsigned char,long,long);
PDll_ArrayPower Dll_ArrayPower;
typedef short (__stdcall *PDll_ArrayLogarifm)(OType,OType,float,unsigned char,unsigned char,long,long);
PDll_ArrayLogarifm Dll_ArrayLogarifm;

typedef short (__stdcall *PDll_ArrayGradient)(OType,OType,unsigned short,float,unsigned char,unsigned char,unsigned char,long,long);
PDll_ArrayGradient Dll_ArrayGradient;

typedef short (__stdcall *PDll_ArrayFiltr)(OType,OType,unsigned short,unsigned char,unsigned char,long,long);
PDll_ArrayFiltr Dll_ArrayFiltr;

typedef short (__stdcall *PDll_ArrayKendal0)(OType,OType,unsigned short,unsigned char,unsigned char,long,long);
PDll_ArrayKendal0 Dll_ArrayKendal0;

typedef short (__stdcall *PDll_ArrayKendal1)(OType,OType,unsigned short,unsigned char,unsigned char,long,long);
PDll_ArrayKendal1 Dll_ArrayKendal1;

typedef short (__stdcall *PDll_ArrayKendal2)(OType,OType,unsigned short,unsigned char,unsigned char,long,long);
PDll_ArrayKendal2 Dll_ArrayKendal2;

typedef short (__stdcall *PDll_ArraySkin)(OType,OType,unsigned short,unsigned short,unsigned char,unsigned char,long,long);
PDll_ArraySkin Dll_ArraySkin;

typedef short (__stdcall *PDll_ArraySmooth)(OType,OType,unsigned short,unsigned char,unsigned char,unsigned char,long,long);
PDll_ArraySmooth Dll_ArraySmooth;

typedef short (__stdcall *PDll_ArrayMeanSmooth)(OType,OType,unsigned short,
  unsigned char,unsigned char,long,long);
PDll_ArrayMeanSmooth Dll_ArrayMeanSmooth;

typedef short (__stdcall *PDll_ArrayRubber)(OType,OType,unsigned char,unsigned char,unsigned char,long,long,long,unsigned short);
PDll_ArrayRubber Dll_ArrayRubber;

typedef short (__stdcall *PDll_ArrayLinModif)(OType,OType,float,float,unsigned char,unsigned char,long,long);
PDll_ArrayLinModif Dll_ArrayLinModif;

typedef short (__stdcall *PDll_ArrayScaling)(OType,OType,OType,unsigned char,unsigned char,unsigned char,unsigned char,long,long);
PDll_ArrayScaling Dll_ArrayScaling;

typedef short (__stdcall *PDll_ArrGetPolinom)(OType,OType,float,unsigned char,unsigned char,unsigned char,long,long,float*,float*,float*,ArrS10*);
PDll_ArrGetPolinom Dll_ArrGetPolinom;

typedef short (__stdcall *PDll_ArrayMean)(OType,unsigned char,unsigned char,unsigned char,long,long,float*,float*);
PDll_ArrayMean Dll_ArrayMean;

typedef long (__stdcall *PDll_ArrayGetInterIndex)(OType,unsigned char,float,float,long*,long*);
PDll_ArrayGetInterIndex Dll_ArrayGetInterIndex;
typedef short (__stdcall *PDll_ArrayExtract)(OType,unsigned char,unsigned char,unsigned short,OType*);
PDll_ArrayExtract Dll_ArrayExtract;
typedef short (__stdcall *PDll_ArrayAddColumn)(OType,OType,unsigned short,unsigned short,OType*);
PDll_ArrayAddColumn Dll_ArrayAddColumn;
typedef short (__stdcall *PDll_ArrayDelColumn)(OType,unsigned short,unsigned short,OType*);
PDll_ArrayDelColumn Dll_ArrayDelColumn;
typedef short (__stdcall *PDll_ArrayTakeData)(OType,OType);
PDll_ArrayTakeData Dll_ArrayTakeData;
typedef short (__stdcall *PDll_ArrayTakeDataEx)(OType,OType,unsigned short);
PDll_ArrayTakeDataEx Dll_ArrayTakeDataEx;
typedef long (__stdcall *PDll_GetBlobByIndex)(OType*,long,OType);
PDll_GetBlobByIndex Dll_GetBlobByIndex;
typedef long (__stdcall *PDll_GetBlobSize)(OType,long*);
PDll_GetBlobSize Dll_GetBlobSize;
typedef long (__stdcall *PDll_SetBlobLen)(OType,long);
PDll_SetBlobLen Dll_SetBlobLen;
typedef long (__stdcall *PDll_BlobReadBuf)(OType,long,long,void*);
PDll_BlobReadBuf Dll_BlobReadBuf;
typedef long (__stdcall *PDll_BlobWriteBuf)(OType,long,long,void*);
PDll_BlobWriteBuf Dll_BlobWriteBuf;

typedef short (__stdcall *PDll_GetFieldVal)(const char*,OType,OType*,unsigned char*);
PDll_GetFieldVal Dll_GetFieldVal;
typedef short (__stdcall *PDll_ObjGetFieldSingle)(const char*,OType,const char*,float*);
PDll_ObjGetFieldSingle Dll_ObjGetFieldSingle;
typedef short (__stdcall *PDll_ObjGetFieldSingleEx)(const char*,OType,const char*,char*,float*);
PDll_ObjGetFieldSingleEx Dll_ObjGetFieldSingleEx;
typedef short (__stdcall *PDll_ObjGetFieldLong)(const char*,OType,const char*,long*);
PDll_ObjGetFieldLong Dll_ObjGetFieldLong;
typedef short (__stdcall *PDll_ObjGetFieldLongEx)(const char*,OType,const char*,char*,long*);
PDll_ObjGetFieldLongEx Dll_ObjGetFieldLongEx;
typedef short (__stdcall *PDll_ObjPutFieldSingle)(const char*,OType,const char*,float);
PDll_ObjPutFieldSingle Dll_ObjPutFieldSingle;
typedef short (__stdcall *PDll_ObjPutFieldSingleEx)(const char*,OType,const char*,char*,float);
PDll_ObjPutFieldSingleEx Dll_ObjPutFieldSingleEx;
typedef short (__stdcall *PDll_ObjPutFieldLong)(const char*,OType,const char*,long);
PDll_ObjPutFieldLong Dll_ObjPutFieldLong;
typedef short (__stdcall *PDll_ObjPutFieldLongEx)(const char*,OType,const char*,char*,long);
PDll_ObjPutFieldLongEx Dll_ObjPutFieldLongEx;
typedef short (__stdcall *PDll_CopyFieldVal)(const char*,OType,OType*,unsigned char*);
PDll_CopyFieldVal Dll_CopyFieldVal;
typedef short (__stdcall *PDll_CopyObVal)(OType,OType*);
PDll_CopyObVal Dll_CopyObVal;
typedef short (__stdcall *PDll_GetObValByIndex)(short,OType,OType*);
PDll_GetObValByIndex Dll_GetObValByIndex;
typedef short (__stdcall *PDll_CopyObValByIndex)(short,OType,OType*);
PDll_CopyObValByIndex Dll_CopyObValByIndex;
typedef short (__stdcall *PDll_ReplaceObValByIndex)(short,OType,OType);
PDll_ReplaceObValByIndex Dll_ReplaceObValByIndex;
typedef short (__stdcall *PDll_ObValFDInit)(OType,const char*,OType*);
PDll_ObValFDInit Dll_ObValFDInit;
typedef short (__stdcall *PDll_MakeObValS)(unsigned char,const char*,unsigned short,OType*);
PDll_MakeObValS Dll_MakeObValS;
typedef short (__stdcall *PDll_ObValSingleInit)(float,OType*);
PDll_ObValSingleInit Dll_ObValSingleInit;
typedef short (__stdcall *PDll_ObValBoolInit)(unsigned char,OType*);
PDll_ObValBoolInit Dll_ObValBoolInit;
typedef short (__stdcall *PDll_ObValDoubleInit)(double,OType*);
PDll_ObValDoubleInit Dll_ObValDoubleInit;
typedef short (__stdcall *PDll_ObValIntInit)(short,OType*);
PDll_ObValIntInit Dll_ObValIntInit;
typedef short (__stdcall *PDll_ObValWordInit)(unsigned short,OType*);
PDll_ObValWordInit Dll_ObValWordInit;
typedef short (__stdcall *PDll_ObValByteInit)(unsigned char,OType*);
PDll_ObValByteInit Dll_ObValByteInit;
typedef short (__stdcall *PDll_ObValStrInit)(const char*,OType*);
PDll_ObValStrInit Dll_ObValStrInit;
typedef short (__stdcall *PDll_ObValStringInit)(const char*,unsigned short,OType*);
PDll_ObValStringInit Dll_ObValStringInit;
typedef short (__stdcall *PDll_ObValLongIntInit)(long,OType*);
PDll_ObValLongIntInit Dll_ObValLongIntInit;
typedef short (__stdcall *PDll_ObValIsBlank)(OType,LongBoolean*);
PDll_ObValIsBlank Dll_ObValIsBlank;
typedef short (__stdcall *PDll_ObValMoveVal)(OType,void*);
PDll_ObValMoveVal Dll_ObValMoveVal;
typedef short (__stdcall *PDll_ObValPutVal)(OType,void*);
PDll_ObValPutVal Dll_ObValPutVal;
typedef short (__stdcall *PDll_ObValGetStr)(OType,char*);
PDll_ObValGetStr Dll_ObValGetStr;
typedef short (__stdcall *PDll_ObValGetFStr)(OType,unsigned short,unsigned short,char*);
PDll_ObValGetFStr Dll_ObValGetFStr;
typedef short (__stdcall *PDll_ObValGetFPChar)(OType,unsigned short,unsigned short,char*,long);
PDll_ObValGetFPChar Dll_ObValGetFPChar;
typedef float (__stdcall *PDll_ObValGetSingle)(OType);
PDll_ObValGetSingle Dll_ObValGetSingle;
typedef long (__stdcall *PDll_ObValGetLongInt)(OType);
PDll_ObValGetLongInt Dll_ObValGetLongInt;
typedef short (__stdcall *PDll_ObValGetSize)(OType,unsigned short*);
PDll_ObValGetSize Dll_ObValGetSize;
typedef short (__stdcall *PDll_ObValGetLongSize)(OType,long*);
PDll_ObValGetLongSize Dll_ObValGetLongSize;
typedef short (__stdcall *PDll_ObValGetPointer)(OType,void*);
PDll_ObValGetPointer Dll_ObValGetPointer;
typedef short (__stdcall *PDll_ObValPutStr)(const char*,OType);
PDll_ObValPutStr Dll_ObValPutStr;
typedef short (__stdcall *PDll_ObValPutSingle)(float,OType);
PDll_ObValPutSingle Dll_ObValPutSingle;
typedef short (__stdcall *PDll_ObValPutLongInt)(long,OType);
PDll_ObValPutLongInt Dll_ObValPutLongInt;
typedef LongBoolean (__stdcall *PDll_ObValCompare)(OType,const char*);
PDll_ObValCompare Dll_ObValCompare;
typedef short (__stdcall *PDll_ObValGetType)(OType,unsigned char*);
PDll_ObValGetType Dll_ObValGetType;
typedef unsigned char (__stdcall *PDll_ObValEqual)(OType,OType);
PDll_ObValEqual Dll_ObValEqual;
typedef unsigned char (__stdcall *PDll_ObValLess)(OType,OType);
PDll_ObValLess Dll_ObValLess;
typedef unsigned char (__stdcall *PDll_ObValELess)(OType,OType);
PDll_ObValELess Dll_ObValELess;
typedef unsigned char (__stdcall *PDll_ObValGreater)(OType,OType);
PDll_ObValGreater Dll_ObValGreater;
typedef unsigned char (__stdcall *PDll_ObValEGreater)(OType,OType);
PDll_ObValEGreater Dll_ObValEGreater;
/*
typedef short (__stdcall *PDll_ObValLoad)(TXStream*,OType*);
PDll_ObValLoad Dll_ObValLoad;
typedef short (__stdcall *PDll_ObValStore)(TXStream*,OType);
PDll_ObValStore Dll_ObValStore;
typedef short (__stdcall *PDll_ObValReadStr)(Text*,OType);
PDll_ObValReadStr Dll_ObValReadStr;
typedef short (__stdcall *PDll_ObValWriteStr)(Text*,OType);
PDll_ObValWriteStr Dll_ObValWriteStr;
*/
typedef short (__stdcall *PDll_ObValIncDec)(OType,OType,unsigned char);
PDll_ObValIncDec Dll_ObValIncDec;
typedef short (__stdcall *PDll_PassObVal)(OType,OType);
PDll_PassObVal Dll_PassObVal;

typedef short (__stdcall *PDll_Load_WS)(const char*,const char*,const char*,const char*,unsigned short*,OType*);
PDll_Load_WS Dll_Load_WS;
typedef short (__stdcall *PDll_Load_WSEx)(const char*,const char*,const char*,const char*,unsigned short*,OType*);
PDll_Load_WSEx Dll_Load_WSEx;
typedef short (__stdcall *PDll_Save_WS)(const char*,const char*,const char*,LongBoolean,OType);
PDll_Save_WS Dll_Save_WS;
typedef short (__stdcall *PDll_Save_WSEx)(const char*,const char*,const char*,LongBoolean,LongBoolean,OType,OType*);
PDll_Save_WSEx Dll_Save_WSEx;
typedef short (__stdcall *PDll_Save_WSExRW)(const char *Selected_Aim, const char *TName, const char *SaveLogFileName, LongBoolean CheckThisCopy, OType ObjHandle);
PDll_Save_WSExRW Dll_Save_WSExRW;

typedef void (__stdcall *PDll_SetBlank)(unsigned char,const char*);
PDll_SetBlank Dll_SetBlank;
typedef float (__stdcall *PDll_GetBlankSingle)(void);
PDll_GetBlankSingle Dll_GetBlankSingle;

typedef short (__stdcall *PDll_MakeWhereData)(OType*,const char*,const char*);
PDll_MakeWhereData Dll_MakeWhereData;
typedef short (__stdcall *PDll_AddWhereData)(OType,const char*,const char*);
PDll_AddWhereData Dll_AddWhereData;
typedef short (__stdcall *PDll_SearchDataInit)(OType,OType,OType*);
PDll_SearchDataInit Dll_SearchDataInit;
typedef short (__stdcall *PDll_SSearchDataInit)(const char*,const char*,const char*,const char*,const char*,const char*,OType,OType*);
PDll_SSearchDataInit Dll_SSearchDataInit;
typedef short (__stdcall *PDll_PrepareCond)(OType,OType);
PDll_PrepareCond Dll_PrepareCond;
typedef short (__stdcall *PDll_GetSOData)(OType,CSODataType*);
PDll_GetSOData Dll_GetSOData;
typedef short (__stdcall *PDll_SetSOData)(OType,CSODataType);
PDll_SetSOData Dll_SetSOData;
typedef short (__stdcall *PDll_SetSOpers)(OType,short,const char*);
PDll_SetSOpers Dll_SetSOpers;
typedef short (__stdcall *PDll_AddSOper)(OType,const char*);
PDll_AddSOper Dll_AddSOper;
typedef short (__stdcall *PDll_SetSTable)(OType,const char*);
PDll_SetSTable Dll_SetSTable;
typedef short (__stdcall *PDll_CompCond)(OType,OType,LongBoolean*);
PDll_CompCond Dll_CompCond;
typedef short (__stdcall *PDll_LoadSO)(OType*,const char*);
PDll_LoadSO Dll_LoadSO;
typedef short (__stdcall *PDll_StoreSO)(OType,const char*);
PDll_StoreSO Dll_StoreSO;
typedef void  (__stdcall *PDll_DatServCounters)(void);
PDll_DatServCounters Dll_DatServCounters;
typedef void  (__stdcall *PDll_DoTxtMaket)(OType,OType,const char*,const char*);
PDll_DoTxtMaket Dll_DoTxtMaket;

typedef void * (__stdcall *PDll_DSGetTableCollection)(OType);
PDll_DSGetTableCollection Dll_DSGetTableCollection;

typedef short (__stdcall *PDll_GetSysDataCount)(void);
PDll_GetSysDataCount Dll_GetSysDataCount;
typedef short (__stdcall *PDll_GetSysLogFileCount)(void);
PDll_GetSysLogFileCount Dll_GetSysLogFileCount;
typedef short (__stdcall *PDll_GetSysLRCursorCount)(void);
PDll_GetSysLRCursorCount Dll_GetSysLRCursorCount;
typedef short (__stdcall *PDll_GetSysLogRecCount)(void);
PDll_GetSysLogRecCount Dll_GetSysLogRecCount;
typedef short (__stdcall *PDll_GetSysDataObjCount)(void);
PDll_GetSysDataObjCount Dll_GetSysDataObjCount;
typedef short (__stdcall *PDll_GetSysArrayCount)(void);
PDll_GetSysArrayCount Dll_GetSysArrayCount;
typedef short (__stdcall *PDll_GetSysObValCount)(void);
PDll_GetSysObValCount Dll_GetSysObValCount;
typedef short (__stdcall *PDll_GetSysTDescCount)(void);
PDll_GetSysTDescCount Dll_GetSysTDescCount;
typedef short (__stdcall *PDll_GetSysFDescCount)(void);
PDll_GetSysFDescCount Dll_GetSysFDescCount;
typedef short (__stdcall *PDll_CheckResVersion)(const char*,const char*,const char*);
PDll_CheckResVersion Dll_CheckResVersion;
typedef void (__stdcall *PDll_SetChangeBlankNotifyProc)(void*);
PDll_SetChangeBlankNotifyProc Dll_SetChangeBlankNotifyProc;
typedef long (__stdcall *PDll_GetLenLimit)(OType);
PDll_GetLenLimit Dll_GetLenLimit;
typedef long (__stdcall *PDll_MemoGetLineCount)(OType);
PDll_MemoGetLineCount Dll_MemoGetLineCount;
typedef long (__stdcall *PDll_MemoGetLine)(OType,long,char*,long);
PDll_MemoGetLine Dll_MemoGetLine;
typedef long (__stdcall *PDll_MemoSetLine)(OType,long,const char*);
PDll_MemoSetLine Dll_MemoSetLine;
typedef long (__stdcall *PDll_MemoInsertLine)(OType,long,const char*);
PDll_MemoInsertLine Dll_MemoInsertLine;
typedef long (__stdcall *PDll_MemoDeleteLine)(OType,long);
PDll_MemoDeleteLine Dll_MemoDeleteLine;
typedef long (__stdcall *PDll_MemoAddLine)(OType,const char*);
PDll_MemoAddLine Dll_MemoAddLine;
typedef void (__stdcall *PDll_GetDatservBlanks)(
  unsigned char*,short*,unsigned short*,long*,
  float*,double*,TimeRecType*,DateRecType*,char*);
PDll_GetDatservBlanks Dll_GetDatservBlanks;
typedef void (__stdcall *PDll_SetDatservBlanks)(
  unsigned char,short,unsigned short,long,
  float,double,TimeRecType,DateRecType,const char*);
PDll_SetDatservBlanks Dll_SetDatservBlanks;
typedef LongBoolean (__stdcall *PDll_GetDateByFormat)(const char*,const char*,DateRecType*);
PDll_GetDateByFormat Dll_GetDateByFormat;
typedef LongBoolean (__stdcall *PDll_GetTimeByFormat)(const char*,const char*,TimeRecType*);
PDll_GetTimeByFormat Dll_GetTimeByFormat;
typedef void (__stdcall *PDll_DSDoneObject)(void *P);
PDll_DSDoneObject Dll_DSDoneObject = 0;
typedef PPasString (__stdcall *PDll_DSNewPString)(const char*);
PDll_DSNewPString Dll_DSNewPString;
typedef void*  (__stdcall *PDll_DSInitList)(long,long);
PDll_DSInitList Dll_DSInitList;
typedef void*  (__stdcall *PDll_DSInitStringList)(long,long);
PDll_DSInitStringList Dll_DSInitStringList;
typedef void*  (__stdcall *PDll_DSInitEmptyList)(long,long);
PDll_DSInitEmptyList Dll_DSInitEmptyList;
typedef void*  (__stdcall *PDll_DSInitUnsortList)(long,long);
PDll_DSInitUnsortList Dll_DSInitUnsortList;
typedef long  (__stdcall *PDll_DSListCount)(void*);
PDll_DSListCount Dll_DSListCount;
typedef void*  (__stdcall *PDll_DSListAt)(void*,long);
PDll_DSListAt Dll_DSListAt;
typedef void (__stdcall *PDll_DSListAtDelete)(void*,long);
PDll_DSListAtDelete Dll_DSListAtDelete;
typedef void (__stdcall *PDll_DSListAtFree)(void*,long);
PDll_DSListAtFree Dll_DSListAtFree;
typedef void (__stdcall *PDll_DSListAtInsert)(void*,long,void*);
PDll_DSListAtInsert Dll_DSListAtInsert;
typedef void (__stdcall *PDll_DSListAtPut)(void*,long,void*);
PDll_DSListAtPut Dll_DSListAtPut;
typedef void (__stdcall *PDll_DSListDelete)(void*,void*);
PDll_DSListDelete Dll_DSListDelete;
typedef void (__stdcall *PDll_DSListDeleteAll)(void*);
PDll_DSListDeleteAll Dll_DSListDeleteAll;
typedef void (__stdcall *PDll_DSListFree)(void*,void*);
PDll_DSListFree Dll_DSListFree;
typedef void (__stdcall *PDll_DSListFreeAll)(void*);
PDll_DSListFreeAll Dll_DSListFreeAll;
typedef long (__stdcall *PDll_DSListIndexOf)(void*,void*);
PDll_DSListIndexOf Dll_DSListIndexOf;
typedef void (__stdcall *PDll_DSListInsert)(void*,void*);
PDll_DSListInsert Dll_DSListInsert;
typedef void (__stdcall *PDll_DSListPack)(void*);
PDll_DSListPack Dll_DSListPack;
typedef long (__stdcall *PDll_DSListSearch)(void*,const char*);
PDll_DSListSearch Dll_DSListSearch;

// Ïåðå÷èñëÿåì âñå ô-öèè â ALL_FUNCS
#define ALL_FUNCS \
DLL_FUNC(long,  CreateDSStream,    (int Option, TDSStream &Stream)) \
DLL_FUNC(long,  StoreBufTD,        (void** Buf, long Option, OType TDHandle)) \
DLL_FUNC(long,  LoadBufTD,         (void** Buf, int Count, long Option, OType &TDHandle)) \
DLL_FUNC(void,  SetOnSaveDataProc, (TOnSaveDataProc Proc)) \
DLL_FUNC(short, LFGetPackState,    (OType LFHandle)) \
DLL_FUNC(short, GetWSName,         (OType LRHandle, const char* WSName)) \
DLL_FUNC(short, TableExistX,       (const char* TableName, OType LFHandle, int Option)) \
DLL_FUNC(long,  DSGetTableNames,   (OType LFHandle, unsigned short LROption, char **Names))

// Îáúÿâëÿåì ôóíêöèè
#define DLL_FUNC(RET, NAME, PARAMS) typedef RET (__stdcall *PDll_##NAME) PARAMS; PDll_##NAME Dll_##NAME = NULL;
ALL_FUNCS
#undef DLL_FUNC


/*****************************************************************************\
*                                                                             *
*    ÎÏÐÅÄÅËÅÍÈß ÂÛÇÎÂÎÂ ÔÓÍÊÖÈÉ ÈÇ ÂÍÅØÍÅÃÎ ÌÎÄÓËß (DLL)                     *
*                                                                             *
\*****************************************************************************/

int DisableRetreiveBlanks = 0;

void __stdcall ChangeBlankNotifyProc()
{
  if (!DisableRetreiveBlanks)
  {
    GetBlanks();
  }
}

void ConnectDatservFunctions(void)
{
	if (hDLL_DATSERV != NULL)
	{
		/* Ïîëó÷åíèå àäðåñîâ âûçîâà ôóíêöèé âíåøíåãî ìîäóëÿ */
		Dll_AddHistory = (PDll_AddHistory)GetProcAddress(hDLL_DATSERV, "AddHistory");
		Dll_AddSOper = (PDll_AddSOper)GetProcAddress(hDLL_DATSERV, "AddSOper");
		Dll_AddWhereData = (PDll_AddWhereData)GetProcAddress(hDLL_DATSERV, "AddWhereData");
		Dll_ArrayAddColumn = (PDll_ArrayAddColumn)GetProcAddress(hDLL_DATSERV, "ArrayAddColumn");
		Dll_ArrayAtShiftColumnLine = (PDll_ArrayAtShiftColumnLine)GetProcAddress(hDLL_DATSERV, "ArrayAtShiftColumnLine");
		Dll_ArrayBlankIndex = (PDll_ArrayBlankIndex)GetProcAddress(hDLL_DATSERV, "ArrayBlankIndex");
		Dll_ArrayBlankValue = (PDll_ArrayBlankValue)GetProcAddress(hDLL_DATSERV, "ArrayBlankValue");
		Dll_ArrayChangeNull = (PDll_ArrayChangeNull)GetProcAddress(hDLL_DATSERV, "ArrayChangeNull");
		Dll_ArrayColumnIndexIsBlank = (PDll_ArrayColumnIndexIsBlank)GetProcAddress(hDLL_DATSERV, "ArrayColumnIndexIsBlank");
		Dll_ArrayColumnIsBlank = (PDll_ArrayColumnIsBlank)GetProcAddress(hDLL_DATSERV, "ArrayColumnIsBlank");
		Dll_ArrayCopyBlank = (PDll_ArrayCopyBlank)GetProcAddress(hDLL_DATSERV, "ArrayCopyBlank");
		Dll_ArrayCopyColumn = (PDll_ArrayCopyColumn)GetProcAddress(hDLL_DATSERV, "ArrayCopyColumn");
		Dll_ArrayDelColumn = (PDll_ArrayDelColumn)GetProcAddress(hDLL_DATSERV, "ArrayDelColumn");
		Dll_ArrayDeleteColumnLine = (PDll_ArrayDeleteColumnLine)GetProcAddress(hDLL_DATSERV, "ArrayDeleteColumnLine");
		Dll_ArrayDeleteLine = (PDll_ArrayDeleteLine)GetProcAddress(hDLL_DATSERV, "ArrayDeleteLine");
		Dll_ArrayDelInter = (PDll_ArrayDelInter)GetProcAddress(hDLL_DATSERV, "ArrayDelInter");
                Dll_ArrayDoBlankColumn = (PDll_ArrayDoBlankColumn)GetProcAddress(hDLL_DATSERV, "ArrayDoBlankColumn");
		Dll_ArrayDoMinMax = (PDll_ArrayDoMinMax)GetProcAddress(hDLL_DATSERV, "ArrayDoMinMax");
		Dll_ArrayExp10 = (PDll_ArrayExp10)GetProcAddress(hDLL_DATSERV, "ArrayExp10");
		Dll_ArrayExponent = (PDll_ArrayExponent)GetProcAddress(hDLL_DATSERV, "ArrayExponent");
		Dll_ArrayExtract = (PDll_ArrayExtract)GetProcAddress(hDLL_DATSERV, "ArrayExtract");
		Dll_ArrayFDInit = (PDll_ArrayFDInit)GetProcAddress(hDLL_DATSERV, "ArrayFDInit");
		Dll_ArrayFiltr = (PDll_ArrayFiltr)GetProcAddress(hDLL_DATSERV, "ArrayFiltr");
		Dll_ArrayFInit = (PDll_ArrayFInit)GetProcAddress(hDLL_DATSERV, "ArrayFInit");
		Dll_ArrayGetColNumByName = (PDll_ArrayGetColNumByName)GetProcAddress(hDLL_DATSERV, "ArrayGetColNumByName");
		Dll_ArrayGetColumnObj = (PDll_ArrayGetColumnObj)GetProcAddress(hDLL_DATSERV, "ArrayGetColumnObj");
		Dll_ArrayGetColumns = (PDll_ArrayGetColumns)GetProcAddress(hDLL_DATSERV, "ArrayGetColumns");
		Dll_ArrayGetData = (PDll_ArrayGetData)GetProcAddress(hDLL_DATSERV, "ArrayGetData");
		Dll_ArrayGetDesc = (PDll_ArrayGetDesc)GetProcAddress(hDLL_DATSERV, "ArrayGetDesc");
		Dll_ArrayGetElementSize = (PDll_ArrayGetElementSize)GetProcAddress(hDLL_DATSERV, "ArrayGetElementSize");
		Dll_ArrayGetFStrColumnData = (PDll_ArrayGetFStrColumnData)GetProcAddress(hDLL_DATSERV, "ArrayGetFStrColumnData");
                Dll_ArrayGetHugeData = (PDll_ArrayGetHugeData)GetProcAddress(hDLL_DATSERV, "ArrayGetHugeData");
		Dll_ArrayGetInterIndex = (PDll_ArrayGetInterIndex)GetProcAddress(hDLL_DATSERV, "ArrayGetInterIndex");
		Dll_ArrayGetItemType = (PDll_ArrayGetItemType)GetProcAddress(hDLL_DATSERV, "ArrayGetItemType");
		Dll_ArrayGetLen = (PDll_ArrayGetLen)GetProcAddress(hDLL_DATSERV, "ArrayGetLen");
		Dll_ArrayGetLongColumnData = (PDll_ArrayGetLongColumnData)GetProcAddress(hDLL_DATSERV, "ArrayGetLongColumnData");
		Dll_ArrayGetMinMax = (PDll_ArrayGetMinMax)GetProcAddress(hDLL_DATSERV, "ArrayGetMinMax");
		Dll_ArrayGetMinMaxH = (PDll_ArrayGetMinMaxH)GetProcAddress(hDLL_DATSERV, "ArrayGetMinMaxH");
		Dll_ArrayGetName = (PDll_ArrayGetName)GetProcAddress(hDLL_DATSERV, "ArrayGetName");
		Dll_ArrayGetObjData = (PDll_ArrayGetObjData)GetProcAddress(hDLL_DATSERV, "ArrayGetObjData");
		Dll_ArrayGetSingle = (PDll_ArrayGetSingle)GetProcAddress(hDLL_DATSERV, "ArrayGetSingle");
		Dll_ArrayGetSingleColData = (PDll_ArrayGetSingleColData)GetProcAddress(hDLL_DATSERV, "ArrayGetSingleColData");
		Dll_ArrayGetSingleColumnData = (PDll_ArrayGetSingleColumnData)GetProcAddress(hDLL_DATSERV, "ArrayGetSingleColumnData");
		Dll_ArrayGetState = (PDll_ArrayGetState)GetProcAddress(hDLL_DATSERV, "ArrayGetState");
		Dll_ArrayGetStrColumnData = (PDll_ArrayGetStrColumnData)GetProcAddress(hDLL_DATSERV, "ArrayGetStrColumnData");
		Dll_ArrayGradient = (PDll_ArrayGradient)GetProcAddress(hDLL_DATSERV, "ArrayGradient");
		Dll_ArrayInit = (PDll_ArrayInit)GetProcAddress(hDLL_DATSERV, "ArrayInit");
		Dll_ArrayInsertColumnLine = (PDll_ArrayInsertColumnLine)GetProcAddress(hDLL_DATSERV, "ArrayInsertColumnLine");
		Dll_ArrayInsertLine = (PDll_ArrayInsertLine)GetProcAddress(hDLL_DATSERV, "ArrayInsertLine");
		Dll_ArrayInsertLineN = (PDll_ArrayInsertLineN)GetProcAddress(hDLL_DATSERV, "ArrayInsertLineN");
		Dll_ArrayKendal0 = (PDll_ArrayKendal0)GetProcAddress(hDLL_DATSERV, "ArrayKendal0");
		Dll_ArrayKendal1 = (PDll_ArrayKendal1)GetProcAddress(hDLL_DATSERV, "ArrayKendal1");
		Dll_ArrayKendal2 = (PDll_ArrayKendal2)GetProcAddress(hDLL_DATSERV, "ArrayKendal2");
		Dll_ArrayLinModif = (PDll_ArrayLinModif)GetProcAddress(hDLL_DATSERV, "ArrayLinModif");
		Dll_ArrayLogarifm = (PDll_ArrayLogarifm)GetProcAddress(hDLL_DATSERV, "ArrayLogarifm");
		Dll_ArrayMean = (PDll_ArrayMean)GetProcAddress(hDLL_DATSERV, "ArrayMean");
		Dll_ArrayMeanSmooth = (PDll_ArrayMeanSmooth)GetProcAddress(hDLL_DATSERV, "ArrayMeanSmooth");
		Dll_ArrayPower = (PDll_ArrayPower)GetProcAddress(hDLL_DATSERV, "ArrayPower");
		Dll_ArrayPutData = (PDll_ArrayPutData)GetProcAddress(hDLL_DATSERV, "ArrayPutData");
                Dll_ArrayPutHugeData = (PDll_ArrayPutHugeData)GetProcAddress(hDLL_DATSERV, "ArrayPutHugeData");
		Dll_ArrayPutLongColumnData = (PDll_ArrayPutLongColumnData)GetProcAddress(hDLL_DATSERV, "ArrayPutLongColumnData");
		Dll_ArrayPutObjData = (PDll_ArrayPutObjData)GetProcAddress(hDLL_DATSERV, "ArrayPutObjData");
		Dll_ArrayPutSingleColumnData = (PDll_ArrayPutSingleColumnData)GetProcAddress(hDLL_DATSERV, "ArrayPutSingleColumnData");
		Dll_ArrayPutStrColumnData = (PDll_ArrayPutStrColumnData)GetProcAddress(hDLL_DATSERV, "ArrayPutStrColumnData");
		Dll_ArrayReplaceDesc = (PDll_ArrayReplaceDesc)GetProcAddress(hDLL_DATSERV, "ArrayReplaceDesc");
		Dll_ArrayRevert = (PDll_ArrayRevert)GetProcAddress(hDLL_DATSERV, "ArrayRevert");
		Dll_ArrayRevLin = (PDll_ArrayRevLin)GetProcAddress(hDLL_DATSERV, "ArrayRevLin");
		Dll_ArrayRubber = (PDll_ArrayRubber)GetProcAddress(hDLL_DATSERV, "ArrayRubber");
		Dll_ArrayScaling = (PDll_ArrayScaling)GetProcAddress(hDLL_DATSERV, "ArrayScaling");
		Dll_ArraySetLen = (PDll_ArraySetLen)GetProcAddress(hDLL_DATSERV, "ArraySetLen");
		Dll_ArraySetState = (PDll_ArraySetState)GetProcAddress(hDLL_DATSERV, "ArraySetState");
		Dll_ArrayShiftColumnLine = (PDll_ArrayShiftColumnLine)GetProcAddress(hDLL_DATSERV, "ArrayShiftColumnLine");
		Dll_ArraySkin = (PDll_ArraySkin)GetProcAddress(hDLL_DATSERV, "ArraySkin");
		Dll_ArraySmooth = (PDll_ArraySmooth)GetProcAddress(hDLL_DATSERV, "ArraySmooth");
		Dll_ArraySort = (PDll_ArraySort)GetProcAddress(hDLL_DATSERV, "ArraySort");
                Dll_ArrayTakeData = (PDll_ArrayTakeData)GetProcAddress(hDLL_DATSERV, "ArrayTakeData");
		Dll_ArrayTakeDataEx = (PDll_ArrayTakeDataEx)GetProcAddress(hDLL_DATSERV, "ArrayTakeDataEx");
		Dll_ArrayTDInit = (PDll_ArrayTDInit)GetProcAddress(hDLL_DATSERV, "ArrayTDInit");
		Dll_ArrayTDInitH = (PDll_ArrayTDInitH)GetProcAddress(hDLL_DATSERV, "ArrayTDInitH");
		Dll_ArrayValIsBlank = (PDll_ArrayValIsBlank)GetProcAddress(hDLL_DATSERV, "ArrayValIsBlank");
		Dll_ArrGetPolinom = (PDll_ArrGetPolinom)GetProcAddress(hDLL_DATSERV, "ArrGetPolinom");
		Dll_ASqr = (PDll_ASqr)GetProcAddress(hDLL_DATSERV, "ASqr");
		Dll_ASqrt = (PDll_ASqrt)GetProcAddress(hDLL_DATSERV, "ASqrt");
				Dll_BlankObj = (PDll_BlankObj)GetProcAddress(hDLL_DATSERV, "BlankObj");
		Dll_CheckResVersion = (PDll_CheckResVersion)GetProcAddress(hDLL_DATSERV, "CheckResVersion");
		Dll_ChkGroup = (PDll_ChkGroup)GetProcAddress(hDLL_DATSERV, "ChkGroup");
		Dll_ClearDatServ = (PDll_ClearDatServ)GetProcAddress(hDLL_DATSERV, "ClearDatServ");
		Dll_CompCond = (PDll_CompCond)GetProcAddress(hDLL_DATSERV, "CompCond");
		Dll_CopyArrayByIndex = (PDll_CopyArrayByIndex)GetProcAddress(hDLL_DATSERV, "CopyArrayByIndex");
		Dll_CopyArrayByName = (PDll_CopyArrayByName)GetProcAddress(hDLL_DATSERV, "CopyArrayByName");
		Dll_CopyFieldVal = (PDll_CopyFieldVal)GetProcAddress(hDLL_DATSERV, "CopyFieldVal");
		Dll_CopyHandle = (PDll_CopyHandle)GetProcAddress(hDLL_DATSERV, "CopyHandle");
		Dll_CopyNewHandle = (PDll_CopyNewHandle)GetProcAddress(hDLL_DATSERV, "CopyNewHandle");
		Dll_CopyObVal = (PDll_CopyObVal)GetProcAddress(hDLL_DATSERV, "CopyObVal");
		Dll_CopyObValByIndex = (PDll_CopyObValByIndex)GetProcAddress(hDLL_DATSERV, "CopyObValByIndex");
		Dll_CreateSysData = (PDll_CreateSysData)GetProcAddress(hDLL_DATSERV, "CreateSysData");
		Dll_CurveDoMinMaxVal = (PDll_CurveDoMinMaxVal)GetProcAddress(hDLL_DATSERV, "CurveDoMinMaxVal");
		Dll_CurveGetArr = (PDll_CurveGetArr)GetProcAddress(hDLL_DATSERV, "CurveGetArr");
		Dll_CurveGetColor = (PDll_CurveGetColor)GetProcAddress(hDLL_DATSERV, "CurveGetColor");
		Dll_CurveGetCount = (PDll_CurveGetCount)GetProcAddress(hDLL_DATSERV, "CurveGetCount");
		Dll_CurveGetDataHandle = (PDll_CurveGetDataHandle)GetProcAddress(hDLL_DATSERV, "CurveGetDataHandle");
		Dll_CurveGetMinMaxVal = (PDll_CurveGetMinMaxVal)GetProcAddress(hDLL_DATSERV, "CurveGetMinMaxVal");
		Dll_CurveGetParams = (PDll_CurveGetParams)GetProcAddress(hDLL_DATSERV, "CurveGetParams");
		Dll_CurveGetStatus = (PDll_CurveGetStatus)GetProcAddress(hDLL_DATSERV, "CurveGetStatus");
		Dll_CurveSetColor = (PDll_CurveSetColor)GetProcAddress(hDLL_DATSERV, "CurveSetColor");
		Dll_CurveSetMinMaxVal = (PDll_CurveSetMinMaxVal)GetProcAddress(hDLL_DATSERV, "CurveSetMinMaxVal");
		Dll_CurveSetParams = (PDll_CurveSetParams)GetProcAddress(hDLL_DATSERV, "CurveSetParams");
		Dll_CurveSetStatus = (PDll_CurveSetStatus)GetProcAddress(hDLL_DATSERV, "CurveSetStatus");
		Dll_DatServCounters = (PDll_DatServCounters)GetProcAddress(hDLL_DATSERV, "DatServCounters");
		Dll_DeleteObj = (PDll_DeleteObj)GetProcAddress(hDLL_DATSERV, "DeleteObj");
		Dll_DoneDSObj = (PDll_DoneDSObj)GetProcAddress(hDLL_DATSERV, "DoneDSObj");
		Dll_DoneHandle = (PDll_DoneHandle)GetProcAddress(hDLL_DATSERV, "DoneHandle");
		Dll_DoPal2Value = (PDll_DoPal2Value)GetProcAddress(hDLL_DATSERV, "DoPal2Value");
		Dll_DoPal3Value = (PDll_DoPal3Value)GetProcAddress(hDLL_DATSERV, "DoPal3Value");
		Dll_DSFreeMem = (PDll_DSFreeMem)GetProcAddress(hDLL_DATSERV, "DSFreeMem");
		Dll_DSGetTableCollection = (PDll_DSGetTableCollection)GetProcAddress(hDLL_DATSERV, "DSGetTableCollection");
		//Dll_DSLRGetEAnyKeyContent = (PDll_DSLRGetEAnyKeyContent)GetProcAddress(hDLL_DATSERV, "DSLRGetEAnyKeyContent");
		//Dll_DSLRGetEKeyContent = (PDll_DSLRGetEKeyContent)GetProcAddress(hDLL_DATSERV, "DSLRGetEKeyContent");
		Dll_DSInitEmptyList = (PDll_DSInitEmptyList)GetProcAddress(hDLL_DATSERV, "DSInitEmptyList");
		Dll_DSInitList = (PDll_DSInitList)GetProcAddress(hDLL_DATSERV, "DSInitList");
		Dll_DSInitStringList = (PDll_DSInitStringList)GetProcAddress(hDLL_DATSERV, "DSInitStringList");
		Dll_DSInitUnsortList = (PDll_DSInitUnsortList)GetProcAddress(hDLL_DATSERV, "DSInitUnsortList");
		Dll_DSListAt = (PDll_DSListAt)GetProcAddress(hDLL_DATSERV, "DSListAt");
		Dll_DSListAtDelete = (PDll_DSListAtDelete)GetProcAddress(hDLL_DATSERV, "DSListAtDelete");
		Dll_DSListAtFree = (PDll_DSListAtFree)GetProcAddress(hDLL_DATSERV, "DSListAtFree");
		Dll_DSListAtInsert = (PDll_DSListAtInsert)GetProcAddress(hDLL_DATSERV, "DSListAtInsert");
		Dll_DSListAtPut = (PDll_DSListAtPut)GetProcAddress(hDLL_DATSERV, "DSListAtPut");
		Dll_DSListCount = (PDll_DSListCount)GetProcAddress(hDLL_DATSERV, "DSListCount");
		Dll_DSListDelete = (PDll_DSListDelete)GetProcAddress(hDLL_DATSERV, "DSListDelete");
		Dll_DSListDeleteAll = (PDll_DSListDeleteAll)GetProcAddress(hDLL_DATSERV, "DSListDeleteAll");
		Dll_DSListFree = (PDll_DSListFree)GetProcAddress(hDLL_DATSERV, "DSListFree");
		Dll_DSListFreeAll = (PDll_DSListFreeAll)GetProcAddress(hDLL_DATSERV, "DSListFreeAll");
		Dll_DSListIndexOf = (PDll_DSListIndexOf)GetProcAddress(hDLL_DATSERV, "DSListIndexOf");
		Dll_DSListInsert = (PDll_DSListInsert)GetProcAddress(hDLL_DATSERV, "DSListInsert");
		Dll_DSListPack = (PDll_DSListPack)GetProcAddress(hDLL_DATSERV, "DSListPack");
		Dll_DSListSearch = (PDll_DSListSearch)GetProcAddress(hDLL_DATSERV, "DSListSearch");
		Dll_DSDoneObject = (PDll_DSDoneObject)GetProcAddress(hDLL_DATSERV, "DSDoneObject");
		Dll_DSNewPString = (PDll_DSNewPString)GetProcAddress(hDLL_DATSERV, "DSNewPString");
		Dll_ExistInRes = (PDll_ExistInRes)GetProcAddress(hDLL_DATSERV, "ExistInRes");
		Dll_ExportObj = (PDll_ExportObj)GetProcAddress(hDLL_DATSERV, "ExportObj");
		Dll_FindFirst = (PDll_FindFirst)GetProcAddress(hDLL_DATSERV, "FindFirst");
		Dll_FindFirstLocal = (PDll_FindFirstLocal)GetProcAddress(hDLL_DATSERV, "FindFirstLocal");
		Dll_FindNext = (PDll_FindNext)GetProcAddress(hDLL_DATSERV, "FindNext");
		Dll_Get_Table = (PDll_Get_Table)GetProcAddress(hDLL_DATSERV, "Get_Table");
		Dll_Get_TableNew = (PDll_Get_TableNew)GetProcAddress(hDLL_DATSERV, "Get_TableNew");
		Dll_GetAnyKeyStr = (PDll_GetAnyKeyStr)GetProcAddress(hDLL_DATSERV, "GetAnyKeyStr");
		Dll_GetArrayByIndex = (PDll_GetArrayByIndex)GetProcAddress(hDLL_DATSERV, "GetArrayByIndex");
		Dll_GetArrayByName = (PDll_GetArrayByName)GetProcAddress(hDLL_DATSERV, "GetArrayByName");
		Dll_GetArrayByNumber = (PDll_GetArrayByNumber)GetProcAddress(hDLL_DATSERV, "GetArrayByNumber");
		Dll_GetArrayFString = (PDll_GetArrayFString)GetProcAddress(hDLL_DATSERV, "GetArrayFString");
		Dll_GetArrayLong = (PDll_GetArrayLong)GetProcAddress(hDLL_DATSERV, "GetArrayLong");
		Dll_GetArraySingle = (PDll_GetArraySingle)GetProcAddress(hDLL_DATSERV, "GetArraySingle");
		Dll_GetArrayString = (PDll_GetArrayString)GetProcAddress(hDLL_DATSERV, "GetArrayString");
                Dll_GetBlankSingle = (PDll_GetBlankSingle)GetProcAddress(hDLL_DATSERV, "GetBlankSingle");
		Dll_GetCurObj = (PDll_GetCurObj)GetProcAddress(hDLL_DATSERV, "GetCurObj");
		Dll_GetCurTable = (PDll_GetCurTable)GetProcAddress(hDLL_DATSERV, "GetCurTable");
		Dll_GetDateByFormat = (PDll_GetDateByFormat)GetProcAddress(hDLL_DATSERV, "GetDateByFormat");
		Dll_GetDatservBlanks = (PDll_GetDatservBlanks)GetProcAddress(hDLL_DATSERV, "GetDatservBlanks");
		Dll_GetDefLong = (PDll_GetDefLong)GetProcAddress(hDLL_DATSERV, "GetDefLong");
		Dll_GetDefSingle = (PDll_GetDefSingle)GetProcAddress(hDLL_DATSERV, "GetDefSingle");
		Dll_GetDefStr = (PDll_GetDefStr)GetProcAddress(hDLL_DATSERV, "GetDefStr");
		Dll_GetFastCurObj = (PDll_GetFastCurObj)GetProcAddress(hDLL_DATSERV, "GetFastCurObj");
		Dll_GetFDArrDesc = (PDll_GetFDArrDesc)GetProcAddress(hDLL_DATSERV, "GetFDArrDesc");
		Dll_GetFDClass = (PDll_GetFDClass)GetProcAddress(hDLL_DATSERV, "GetFDClass");
		Dll_GetFDescAccess = (PDll_GetFDescAccess)GetProcAddress(hDLL_DATSERV, "GetFDescAccess");
		Dll_GetFDescByName = (PDll_GetFDescByName)GetProcAddress(hDLL_DATSERV, "GetFDescByName");
		Dll_GetFDescByNumber = (PDll_GetFDescByNumber)GetProcAddress(hDLL_DATSERV, "GetFDescByNumber");
		Dll_GetFDescFlds = (PDll_GetFDescFlds)GetProcAddress(hDLL_DATSERV, "GetFDescFlds");
		Dll_GetFDescKey = (PDll_GetFDescKey)GetProcAddress(hDLL_DATSERV, "GetFDescKey");
		Dll_GetFDescRC = (PDll_GetFDescRC)GetProcAddress(hDLL_DATSERV, "GetFDescRC");
		Dll_GetFDFactor = (PDll_GetFDFactor)GetProcAddress(hDLL_DATSERV, "GetFDFactor");
		Dll_GetFDFactorEx = (PDll_GetFDFactorEx)GetProcAddress(hDLL_DATSERV, "GetFDFactorEx");
		Dll_GetFDMask = (PDll_GetFDMask)GetProcAddress(hDLL_DATSERV, "GetFDMask");
		Dll_GetFDNFactor = (PDll_GetFDNFactor)GetProcAddress(hDLL_DATSERV, "GetFDNFactor");
		Dll_GetFDNFactorEx = (PDll_GetFDNFactorEx)GetProcAddress(hDLL_DATSERV, "GetFDNFactorEx");
		Dll_GetFieldVal = (PDll_GetFieldVal)GetProcAddress(hDLL_DATSERV, "GetFieldVal");
		Dll_GetFirstNumberByValue = (PDll_GetFirstNumberByValue)GetProcAddress(hDLL_DATSERV, "GetFirstNumberByValue");
		Dll_GetIndexViewsList = (PDll_GetIndexViewsList)GetProcAddress(hDLL_DATSERV, "GetIndexViewsList");
		Dll_GetKeyStr = (PDll_GetKeyStr)GetProcAddress(hDLL_DATSERV, "GetKeyStr");
                Dll_GetLenLimit = (PDll_GetLenLimit)GetProcAddress(hDLL_DATSERV, "GetLenLimit");
		Dll_GetLogFile = (PDll_GetLogFile)GetProcAddress(hDLL_DATSERV, "GetLogFile");
		Dll_GetMetaKeyStr = (PDll_GetMetaKeyStr)GetProcAddress(hDLL_DATSERV, "GetMetaKeyStr");
		Dll_GetNearstRigthNumber = (PDll_GetNearstRigthNumber)GetProcAddress(hDLL_DATSERV, "GetNearstRigthNumber");
		Dll_GetNumberByValue = (PDll_GetNumberByValue)GetProcAddress(hDLL_DATSERV, "GetNumberByValue");
		Dll_GetObjBinarySize = (PDll_GetObjBinarySize)GetProcAddress(hDLL_DATSERV, "GetObjBinarySize");
		Dll_GetObjByEIdN = (PDll_GetObjByEIdN)GetProcAddress(hDLL_DATSERV, "GetObjByEIdN");
		Dll_GetObjByIdN = (PDll_GetObjByIdN)GetProcAddress(hDLL_DATSERV, "GetObjByIdN");
		Dll_GetObjByName = (PDll_GetObjByName)GetProcAddress(hDLL_DATSERV, "GetObjByName");
		Dll_GetObjByNumber = (PDll_GetObjByNumber)GetProcAddress(hDLL_DATSERV, "GetObjByNumber");
		Dll_GetObjState = (PDll_GetObjState)GetProcAddress(hDLL_DATSERV, "GetObjState");
		Dll_GetObValByIndex = (PDll_GetObValByIndex)GetProcAddress(hDLL_DATSERV, "GetObValByIndex");
		Dll_GetPal2Value = (PDll_GetPal2Value)GetProcAddress(hDLL_DATSERV, "GetPal2Value");
		Dll_GetPal3Value = (PDll_GetPal3Value)GetProcAddress(hDLL_DATSERV, "GetPal3Value");
		Dll_GetPalColumn = (PDll_GetPalColumn)GetProcAddress(hDLL_DATSERV, "GetPalColumn");
		Dll_GetPalParam = (PDll_GetPalParam)GetProcAddress(hDLL_DATSERV, "GetPalParam");
		Dll_GetResFileName = (PDll_GetResFileName)GetProcAddress(hDLL_DATSERV, "GetResFileName");
		Dll_GetRowNumber = (PDll_GetRowNumber)GetProcAddress(hDLL_DATSERV, "GetRowNumber");
		Dll_GetScale = (PDll_GetScale)GetProcAddress(hDLL_DATSERV, "GetScale");
		Dll_GetSOData = (PDll_GetSOData)GetProcAddress(hDLL_DATSERV, "GetSOData");
		//Dll_GetSOper = (PDll_GetSOper)GetProcAddress(hDLL_DATSERV, "GetSOper");
		Dll_GetSysArrayCount = (PDll_GetSysArrayCount)GetProcAddress(hDLL_DATSERV, "GetSysArrayCount");
		Dll_GetSysDataCount = (PDll_GetSysDataCount)GetProcAddress(hDLL_DATSERV, "GetSysDataCount");
		Dll_GetSysDataObjCount = (PDll_GetSysDataObjCount)GetProcAddress(hDLL_DATSERV, "GetSysDataObjCount");
		Dll_GetSysFDescCount = (PDll_GetSysFDescCount)GetProcAddress(hDLL_DATSERV, "GetSysFDescCount");
		Dll_GetSysLogFileCount = (PDll_GetSysLogFileCount)GetProcAddress(hDLL_DATSERV, "GetSysLogFileCount");
		Dll_GetSysLogRecCount = (PDll_GetSysLogRecCount)GetProcAddress(hDLL_DATSERV, "GetSysLogRecCount");
		Dll_GetSysObValCount = (PDll_GetSysObValCount)GetProcAddress(hDLL_DATSERV, "GetSysObValCount");
		Dll_GetSysTDescCount = (PDll_GetSysTDescCount)GetProcAddress(hDLL_DATSERV, "GetSysTDescCount");
                Dll_GetSystemDir = (PDll_GetSystemDir)GetProcAddress(hDLL_DATSERV, "GetSystemDir");
		Dll_GetTableName = (PDll_GetTableName)GetProcAddress(hDLL_DATSERV, "GetTableName");
		Dll_GetTDDefinedValue = (PDll_GetTDDefinedValue)GetProcAddress(hDLL_DATSERV, "GetTDDefinedValue");
		Dll_GetTDesc = (PDll_GetTDesc)GetProcAddress(hDLL_DATSERV, "GetTDesc");
		Dll_GetTDescCounter = (PDll_GetTDescCounter)GetProcAddress(hDLL_DATSERV, "GetTDescCounter");
		Dll_GetTDescF = (PDll_GetTDescF)GetProcAddress(hDLL_DATSERV, "GetTDescF");
		Dll_GetTDescFldsI = (PDll_GetTDescFldsI)GetProcAddress(hDLL_DATSERV, "GetTDescFldsI");
		Dll_GetTDescFldsN = (PDll_GetTDescFldsN)GetProcAddress(hDLL_DATSERV, "GetTDescFldsN");
		Dll_GetTDescName = (PDll_GetTDescName)GetProcAddress(hDLL_DATSERV, "GetTDescName");
		Dll_GetTDKeyStr = (PDll_GetTDKeyStr)GetProcAddress(hDLL_DATSERV, "GetTDKeyStr");
		Dll_GetTemplate = (PDll_GetTemplate)GetProcAddress(hDLL_DATSERV, "GetTemplate");
		Dll_GetTimeByFormat = (PDll_GetTimeByFormat)GetProcAddress(hDLL_DATSERV, "GetTimeByFormat");
		Dll_GetTrueCurObj = (PDll_GetTrueCurObj)GetProcAddress(hDLL_DATSERV, "GetTrueCurObj");
		Dll_GetTrueFastCurObj = (PDll_GetTrueFastCurObj)GetProcAddress(hDLL_DATSERV, "GetTrueFastCurObj");
		Dll_GetWSHandle = (PDll_GetWSHandle)GetProcAddress(hDLL_DATSERV, "GetWSHandle");
		Dll_GetWSKeyObj = (PDll_GetWSKeyObj)GetProcAddress(hDLL_DATSERV, "GetWSKeyObj");
		Dll_GetWSObj = (PDll_GetWSObj)GetProcAddress(hDLL_DATSERV, "GetWSObj");
		Dll_GetWSViewsList = (PDll_GetWSViewsList)GetProcAddress(hDLL_DATSERV, "GetWSViewsList");
		Dll_GetWSViewsListXml = (PDll_GetWSViewsListXml)GetProcAddress(hDLL_DATSERV, "GetWSViewsListXml");
		Dll_FreeDSMem = (PDll_FreeDSMem)GetProcAddress(hDLL_DATSERV, "FreeDSMem");
		Dll_Goto_BeginObj = (PDll_Goto_BeginObj)GetProcAddress(hDLL_DATSERV, "Goto_BeginObj");
		Dll_Goto_BeginTable = (PDll_Goto_BeginTable)GetProcAddress(hDLL_DATSERV, "Goto_BeginTable");
		Dll_Goto_FastBeginObj = (PDll_Goto_FastBeginObj)GetProcAddress(hDLL_DATSERV, "Goto_FastBeginObj");
		Dll_Goto_FastNextObj = (PDll_Goto_FastNextObj)GetProcAddress(hDLL_DATSERV, "Goto_FastNextObj");
		Dll_Goto_NextObj = (PDll_Goto_NextObj)GetProcAddress(hDLL_DATSERV, "Goto_NextObj");
		Dll_Goto_NextTable = (PDll_Goto_NextTable)GetProcAddress(hDLL_DATSERV, "Goto_NextTable");
		Dll_HandleGetType = (PDll_HandleGetType)GetProcAddress(hDLL_DATSERV, "HandleGetType");
		Dll_ImportObj = (PDll_ImportObj)GetProcAddress(hDLL_DATSERV, "ImportObj");
		Dll_ImportStrObj = (PDll_ImportStrObj)GetProcAddress(hDLL_DATSERV, "ImportStrObj");
		Dll_IncVersion = (PDll_IncVersion)GetProcAddress(hDLL_DATSERV, "IncVersion");
		Dll_InitCurve = (PDll_InitCurve)GetProcAddress(hDLL_DATSERV, "InitCurve");
		Dll_InitFDesc = (PDll_InitFDesc)GetProcAddress(hDLL_DATSERV, "InitFDesc");
		Dll_InitSysData = (PDll_InitSysData)GetProcAddress(hDLL_DATSERV, "InitSysData");
		Dll_InitTDesc = (PDll_InitTDesc)GetProcAddress(hDLL_DATSERV, "InitTDesc");
		Dll_IsFDescSlave = (PDll_IsFDescSlave)GetProcAddress(hDLL_DATSERV, "IsFDescSlave");
		Dll_LFAppend = (PDll_LFAppend)GetProcAddress(hDLL_DATSERV, "LFAppend");
		Dll_LFDescCompary = (PDll_LFDescCompary)GetProcAddress(hDLL_DATSERV, "LFDescCompary");
		Dll_LFPackTo = (PDll_LFPackTo)GetProcAddress(hDLL_DATSERV, "LFPackTo");
		Dll_Load_WS = (PDll_Load_WS)GetProcAddress(hDLL_DATSERV, "Load_WS");
		Dll_Load_WSEx = (PDll_Load_WSEx)GetProcAddress(hDLL_DATSERV, "Load_WSEx");
		Dll_LoadSO = (PDll_LoadSO)GetProcAddress(hDLL_DATSERV, "LoadSO");
                Dll_LoadSingleColumnData = (PDll_LoadSingleColumnData)GetProcAddress(hDLL_DATSERV, "LoadSingleColumnData");
		Dll_LRChangeName = (PDll_LRChangeName)GetProcAddress(hDLL_DATSERV, "LRChangeName");
		Dll_LRCheckKeyObj = (PDll_LRCheckKeyObj)GetProcAddress(hDLL_DATSERV, "LRCheckKeyObj");
		Dll_LRPutObj = (PDll_LRPutObj)GetProcAddress(hDLL_DATSERV, "LRPutObj");
		Dll_LRPutTDesc = (PDll_LRPutTDesc)GetProcAddress(hDLL_DATSERV, "LRPutTDesc");
		Dll_MakeDKeyTablDesc = (PDll_MakeDKeyTablDesc)GetProcAddress(hDLL_DATSERV, "MakeDKeyTablDesc");
		Dll_MakeObValS = (PDll_MakeObValS)GetProcAddress(hDLL_DATSERV, "MakeObValS");
		Dll_MakeWhereData = (PDll_MakeWhereData)GetProcAddress(hDLL_DATSERV, "MakeWhereData");
                Dll_MemoGetLineCount = (PDll_MemoGetLineCount)GetProcAddress(hDLL_DATSERV, "MemoGetLineCount");
                Dll_MemoGetLine = (PDll_MemoGetLine)GetProcAddress(hDLL_DATSERV, "MemoGetLine");
                Dll_MemoSetLine = (PDll_MemoSetLine)GetProcAddress(hDLL_DATSERV, "MemoSetLine");
                Dll_MemoInsertLine = (PDll_MemoInsertLine)GetProcAddress(hDLL_DATSERV, "MemoInsertLine");
                Dll_MemoDeleteLine = (PDll_MemoDeleteLine)GetProcAddress(hDLL_DATSERV, "MemoDeleteLine");
                Dll_MemoAddLine = (PDll_MemoAddLine)GetProcAddress(hDLL_DATSERV, "MemoAddLine");
                Dll_MoveFromBuf = (PDll_MoveFromBuf)GetProcAddress(hDLL_DATSERV, "MoveFromBuf");
		Dll_MoveSingleColumnData = (PDll_MoveSingleColumnData)GetProcAddress(hDLL_DATSERV, "MoveSingleColumnData");
		Dll_MoveToBuf = (PDll_MoveToBuf)GetProcAddress(hDLL_DATSERV, "MoveToBuf");
		Dll_ObjAdd_Arr = (PDll_ObjAdd_Arr)GetProcAddress(hDLL_DATSERV, "ObjAdd_Arr");
		Dll_ObjAdd_ObVal = (PDll_ObjAdd_ObVal)GetProcAddress(hDLL_DATSERV, "ObjAdd_ObVal");
		Dll_ObjAddAt_ObVal = (PDll_ObjAddAt_ObVal)GetProcAddress(hDLL_DATSERV, "ObjAddAt_ObVal");
		Dll_ObjAtPut = (PDll_ObjAtPut)GetProcAddress(hDLL_DATSERV, "ObjAtPut");
		Dll_ObjCopyBlank = (PDll_ObjCopyBlank)GetProcAddress(hDLL_DATSERV, "ObjCopyBlank");
		Dll_ObjGetAnyKeyStr = (PDll_ObjGetAnyKeyStr)GetProcAddress(hDLL_DATSERV, "ObjGetAnyKeyStr");
		Dll_ObjGetFieldLong = (PDll_ObjGetFieldLong)GetProcAddress(hDLL_DATSERV, "ObjGetFieldLong");
		Dll_ObjGetFieldLongEx = (PDll_ObjGetFieldLongEx)GetProcAddress(hDLL_DATSERV, "ObjGetFieldLongEx");
		Dll_ObjGetFieldSingle = (PDll_ObjGetFieldSingle)GetProcAddress(hDLL_DATSERV, "ObjGetFieldSingle");
		Dll_ObjGetFieldSingleEx = (PDll_ObjGetFieldSingleEx)GetProcAddress(hDLL_DATSERV, "ObjGetFieldSingleEx");
		Dll_ObjGetHandleIndex = (PDll_ObjGetHandleIndex)GetProcAddress(hDLL_DATSERV, "ObjGetHandleIndex");
		Dll_ObjInit = (PDll_ObjInit)GetProcAddress(hDLL_DATSERV, "ObjInit");
		Dll_ObjPutFieldLong = (PDll_ObjPutFieldLong)GetProcAddress(hDLL_DATSERV, "ObjPutFieldLong");
		Dll_ObjPutFieldLongEx = (PDll_ObjPutFieldLongEx)GetProcAddress(hDLL_DATSERV, "ObjPutFieldLongEx");
		Dll_ObjPutFieldSingle = (PDll_ObjPutFieldSingle)GetProcAddress(hDLL_DATSERV, "ObjPutFieldSingle");
		Dll_ObjPutFieldSingleEx = (PDll_ObjPutFieldSingleEx)GetProcAddress(hDLL_DATSERV, "ObjPutFieldSingleEx");
		Dll_ObjTakeByTDesc = (PDll_ObjTakeByTDesc)GetProcAddress(hDLL_DATSERV, "ObjTakeByTDesc");
		Dll_ObjTDCopy = (PDll_ObjTDCopy)GetProcAddress(hDLL_DATSERV, "ObjTDCopy");
		Dll_ObjTDInit = (PDll_ObjTDInit)GetProcAddress(hDLL_DATSERV, "ObjTDInit");
		Dll_ObjTDInitH = (PDll_ObjTDInitH)GetProcAddress(hDLL_DATSERV, "ObjTDInitH");
		Dll_ObjWriteASCII = (PDll_ObjWriteASCII)GetProcAddress(hDLL_DATSERV, "ObjWriteASCII");
		//Dll_ObValAdd = (PDll_ObValAdd)GetProcAddress(hDLL_DATSERV, "ObValAdd");
		//Dll_ObValAnd = (PDll_ObValAnd)GetProcAddress(hDLL_DATSERV, "ObValAnd");
		Dll_ObValBoolInit = (PDll_ObValBoolInit)GetProcAddress(hDLL_DATSERV, "ObValBoolInit");
		Dll_ObValByteInit = (PDll_ObValByteInit)GetProcAddress(hDLL_DATSERV, "ObValByteInit");
		Dll_ObValCompare = (PDll_ObValCompare)GetProcAddress(hDLL_DATSERV, "ObValCompare");
		//Dll_ObValDiv = (PDll_ObValDiv)GetProcAddress(hDLL_DATSERV, "ObValDiv");
		Dll_ObValDoubleInit = (PDll_ObValDoubleInit)GetProcAddress(hDLL_DATSERV, "ObValDoubleInit");
		Dll_ObValEGreater = (PDll_ObValEGreater)GetProcAddress(hDLL_DATSERV, "ObValEGreater");
		Dll_ObValELess = (PDll_ObValELess)GetProcAddress(hDLL_DATSERV, "ObValELess");
		Dll_ObValEqual = (PDll_ObValEqual)GetProcAddress(hDLL_DATSERV, "ObValEqual");
		Dll_ObValFDInit = (PDll_ObValFDInit)GetProcAddress(hDLL_DATSERV, "ObValFDInit");
		Dll_ObValGetFPChar = (PDll_ObValGetFPChar)GetProcAddress(hDLL_DATSERV, "ObValGetFPChar");
		Dll_ObValGetFStr = (PDll_ObValGetFStr)GetProcAddress(hDLL_DATSERV, "ObValGetFStr");
		Dll_ObValGetLongInt = (PDll_ObValGetLongInt)GetProcAddress(hDLL_DATSERV, "ObValGetLongInt");
		Dll_ObValGetLongSize = (PDll_ObValGetLongSize)GetProcAddress(hDLL_DATSERV, "ObValGetLongSize");
		Dll_ObValGetPointer = (PDll_ObValGetPointer)GetProcAddress(hDLL_DATSERV, "ObValGetPointer");
		Dll_ObValGetSingle = (PDll_ObValGetSingle)GetProcAddress(hDLL_DATSERV, "ObValGetSingle");
		Dll_ObValGetSize = (PDll_ObValGetSize)GetProcAddress(hDLL_DATSERV, "ObValGetSize");
		Dll_ObValGetStr = (PDll_ObValGetStr)GetProcAddress(hDLL_DATSERV, "ObValGetStr");
		Dll_ObValGetType = (PDll_ObValGetType)GetProcAddress(hDLL_DATSERV, "ObValGetType");
		Dll_ObValGreater = (PDll_ObValGreater)GetProcAddress(hDLL_DATSERV, "ObValGreater");
		Dll_ObValIncDec = (PDll_ObValIncDec)GetProcAddress(hDLL_DATSERV, "ObValIncDec");
		Dll_ObValIntInit = (PDll_ObValIntInit)GetProcAddress(hDLL_DATSERV, "ObValIntInit");
		Dll_ObValIsBlank = (PDll_ObValIsBlank)GetProcAddress(hDLL_DATSERV, "ObValIsBlank");
		Dll_ObValLess = (PDll_ObValLess)GetProcAddress(hDLL_DATSERV, "ObValLess");
		Dll_ObValLongIntInit = (PDll_ObValLongIntInit)GetProcAddress(hDLL_DATSERV, "ObValLongIntInit");
		//Dll_ObValMinus = (PDll_ObValMinus)GetProcAddress(hDLL_DATSERV, "ObValMinus");
		Dll_ObValMoveVal = (PDll_ObValMoveVal)GetProcAddress(hDLL_DATSERV, "ObValMoveVal");
		//Dll_ObValMul = (PDll_ObValMul)GetProcAddress(hDLL_DATSERV, "ObValMul");
		//Dll_ObValNot = (PDll_ObValNot)GetProcAddress(hDLL_DATSERV, "ObValNot");
		//Dll_ObValOr = (PDll_ObValOr)GetProcAddress(hDLL_DATSERV, "ObValOr");
		//Dll_ObValPCharInit = (PDll_ObValPCharInit)GetProcAddress(hDLL_DATSERV, "ObValPCharInit");
		Dll_ObValPutLongInt = (PDll_ObValPutLongInt)GetProcAddress(hDLL_DATSERV, "ObValPutLongInt");
		Dll_ObValPutSingle = (PDll_ObValPutSingle)GetProcAddress(hDLL_DATSERV, "ObValPutSingle");
		Dll_ObValPutStr = (PDll_ObValPutStr)GetProcAddress(hDLL_DATSERV, "ObValPutStr");
		Dll_ObValPutVal = (PDll_ObValPutVal)GetProcAddress(hDLL_DATSERV, "ObValPutVal");
		Dll_ObValSingleInit = (PDll_ObValSingleInit)GetProcAddress(hDLL_DATSERV, "ObValSingleInit");
		Dll_ObValStrInit = (PDll_ObValStrInit)GetProcAddress(hDLL_DATSERV, "ObValStrInit");
		//Dll_ObValSub = (PDll_ObValSub)GetProcAddress(hDLL_DATSERV, "ObValSub");
		Dll_ObValWordInit = (PDll_ObValWordInit)GetProcAddress(hDLL_DATSERV, "ObValWordInit");
		Dll_PackRes = (PDll_PackRes)GetProcAddress(hDLL_DATSERV, "PackRes");
		Dll_PassObVal = (PDll_PassObVal)GetProcAddress(hDLL_DATSERV, "PassObVal");
		Dll_PrepareCond = (PDll_PrepareCond)GetProcAddress(hDLL_DATSERV, "PrepareCond");
		Dll_PutArrayLong = (PDll_PutArrayLong)GetProcAddress(hDLL_DATSERV, "PutArrayLong");
		Dll_PutArraySingle = (PDll_PutArraySingle)GetProcAddress(hDLL_DATSERV, "PutArraySingle");
		Dll_PutArrayString = (PDll_PutArrayString)GetProcAddress(hDLL_DATSERV, "PutArrayString");
		Dll_PutScale = (PDll_PutScale)GetProcAddress(hDLL_DATSERV, "PutScale");
		Dll_PutTDesc = (PDll_PutTDesc)GetProcAddress(hDLL_DATSERV, "PutTDesc");
		//Dll_RegisterObVals = (PDll_RegisterObVals)GetProcAddress(hDLL_DATSERV, "RegisterObVals");
		Dll_RemoveLogFile = (PDll_RemoveLogFile)GetProcAddress(hDLL_DATSERV, "RemoveLogFile");
		Dll_ReplaceArr = (PDll_ReplaceArr)GetProcAddress(hDLL_DATSERV, "ReplaceArr");
		Dll_ReplaceObValByIndex = (PDll_ReplaceObValByIndex)GetProcAddress(hDLL_DATSERV, "ReplaceObValByIndex");
		Dll_ResAddMemTD = (PDll_ResAddMemTD)GetProcAddress(hDLL_DATSERV, "ResAddMemTD");
		Dll_ResDeleteTD = (PDll_ResDeleteTD)GetProcAddress(hDLL_DATSERV, "ResDeleteTD");
		Dll_ResGetKeyAt = (PDll_ResGetKeyAt)GetProcAddress(hDLL_DATSERV, "ResGetKeyAt");
		Dll_ResGetKeyCounter = (PDll_ResGetKeyCounter)GetProcAddress(hDLL_DATSERV, "ResGetKeyCounter");
		Dll_ResGetMemTD = (PDll_ResGetMemTD)GetProcAddress(hDLL_DATSERV, "ResGetMemTD");
		Dll_ResIsModified = (PDll_ResIsModified)GetProcAddress(hDLL_DATSERV, "ResIsModified");
		Dll_ResPutTD = (PDll_ResPutTD)GetProcAddress(hDLL_DATSERV, "ResPutTD");
		Dll_ResRemoveMemTD = (PDll_ResRemoveMemTD)GetProcAddress(hDLL_DATSERV, "ResRemoveMemTD");
		Dll_ResStreamSt = (PDll_ResStreamSt)GetProcAddress(hDLL_DATSERV, "ResStreamSt");
		Dll_RestoreObj = (PDll_RestoreObj)GetProcAddress(hDLL_DATSERV, "RestoreObj");
		Dll_Save_WS = (PDll_Save_WS)GetProcAddress(hDLL_DATSERV, "Save_WS");
		Dll_Save_WSEx = (PDll_Save_WSEx)GetProcAddress(hDLL_DATSERV, "Save_WSEx");
		Dll_Save_WSExRW = (PDll_Save_WSExRW)GetProcAddress(hDLL_DATSERV, "Save_WSExRW");
		Dll_SaveNewObj = (PDll_SaveNewObj)GetProcAddress(hDLL_DATSERV, "SaveNewObj");
		Dll_SaveNewObjEx = (PDll_SaveNewObjEx)GetProcAddress(hDLL_DATSERV, "SaveNewObjEx");
		Dll_SearchDataInit = (PDll_SearchDataInit)GetProcAddress(hDLL_DATSERV, "SearchDataInit");
		Dll_SetBlank = (PDll_SetBlank)GetProcAddress(hDLL_DATSERV, "SetBlank");
                Dll_SetChangeBlankNotifyProc = (PDll_SetChangeBlankNotifyProc)GetProcAddress(hDLL_DATSERV, "SetChangeBlankNotifyProc");
                Dll_SetDatservBlanks = (PDll_SetDatservBlanks)GetProcAddress(hDLL_DATSERV, "SetDatservBlanks");
		Dll_SetFDArrDesc = (PDll_SetFDArrDesc)GetProcAddress(hDLL_DATSERV, "SetFDArrDesc");
		Dll_SetFDClass = (PDll_SetFDClass)GetProcAddress(hDLL_DATSERV, "SetFDClass");
		Dll_SetFDescFlds = (PDll_SetFDescFlds)GetProcAddress(hDLL_DATSERV, "SetFDescFlds");
		Dll_SetFDescKey = (PDll_SetFDescKey)GetProcAddress(hDLL_DATSERV, "SetFDescKey");
		Dll_SetFDescSlave = (PDll_SetFDescSlave)GetProcAddress(hDLL_DATSERV, "SetFDescSlave");
		Dll_SetFDMask = (PDll_SetFDMask)GetProcAddress(hDLL_DATSERV, "SetFDMask");
		Dll_SetObjState = (PDll_SetObjState)GetProcAddress(hDLL_DATSERV, "SetObjState");
		Dll_SetSOData = (PDll_SetSOData)GetProcAddress(hDLL_DATSERV, "SetSOData");
		Dll_SetSOpers = (PDll_SetSOpers)GetProcAddress(hDLL_DATSERV, "SetSOpers");
		Dll_SetSTable = (PDll_SetSTable)GetProcAddress(hDLL_DATSERV, "SetSTable");
		//Dll_SetTempDirName = (PDll_SetTempDirName)GetProcAddress(hDLL_DATSERV, "SetTempDirName");
		Dll_SetTemplate = (PDll_SetTemplate)GetProcAddress(hDLL_DATSERV, "SetTemplate");
		Dll_SSearchDataInit = (PDll_SSearchDataInit)GetProcAddress(hDLL_DATSERV, "SSearchDataInit");
		Dll_StoreSO = (PDll_StoreSO)GetProcAddress(hDLL_DATSERV, "StoreSO");
		Dll_SysLFCreate = (PDll_SysLFCreate)GetProcAddress(hDLL_DATSERV, "SysLFCreate");
		Dll_SysLFInitOpen = (PDll_SysLFInitOpen)GetProcAddress(hDLL_DATSERV, "SysLFInitOpen");
		Dll_SysLFInitOpenEx = (PDll_SysLFInitOpenEx)GetProcAddress(hDLL_DATSERV, "SysLFInitOpenEx");
		Dll_TableExist = (PDll_TableExist)GetProcAddress(hDLL_DATSERV, "TableExist");
		Dll_TDAtFreeFD = (PDll_TDAtFreeFD)GetProcAddress(hDLL_DATSERV, "TDAtFreeFD");
		Dll_TDAtInsertFD = (PDll_TDAtInsertFD)GetProcAddress(hDLL_DATSERV, "TDAtInsertFD");
		Dll_TDAtPutFD = (PDll_TDAtPutFD)GetProcAddress(hDLL_DATSERV, "TDAtPutFD");
		Dll_TDCheckDesc = (PDll_TDCheckDesc)GetProcAddress(hDLL_DATSERV, "TDCheckDesc");
		Dll_TDCheckRepeating = (PDll_TDCheckRepeating)GetProcAddress(hDLL_DATSERV, "TDCheckRepeating");
		Dll_TDFreeAll = (PDll_TDFreeAll)GetProcAddress(hDLL_DATSERV, "TDFreeAll");
		Dll_TDGetAnglName = (PDll_TDGetAnglName)GetProcAddress(hDLL_DATSERV, "TDGetAnglName");
		Dll_TDGetArrayCounter = (PDll_TDGetArrayCounter)GetProcAddress(hDLL_DATSERV, "TDGetArrayCounter");
		Dll_TDGetArrayIndex = (PDll_TDGetArrayIndex)GetProcAddress(hDLL_DATSERV, "TDGetArrayIndex");
		Dll_TDGetArrayIndexByNumber = (PDll_TDGetArrayIndexByNumber)GetProcAddress(hDLL_DATSERV, "TDGetArrayIndexByNumber");
		Dll_TDGetArrayNumber = (PDll_TDGetArrayNumber)GetProcAddress(hDLL_DATSERV, "TDGetArrayNumber");
		Dll_TDGetAtomNameAt = (PDll_TDGetAtomNameAt)GetProcAddress(hDLL_DATSERV, "TDGetAtomNameAt");
		Dll_TDGetFieldIndex = (PDll_TDGetFieldIndex)GetProcAddress(hDLL_DATSERV, "TDGetFieldIndex");
		Dll_TDGetLongName = (PDll_TDGetLongName)GetProcAddress(hDLL_DATSERV, "TDGetLongName");
		Dll_TDGetName = (PDll_TDGetName)GetProcAddress(hDLL_DATSERV, "TDGetName");
		Dll_TDGetObjCounter = (PDll_TDGetObjCounter)GetProcAddress(hDLL_DATSERV, "TDGetObjCounter");
		Dll_TDGetObjIndex = (PDll_TDGetObjIndex)GetProcAddress(hDLL_DATSERV, "TDGetObjIndex");
		Dll_TDGetObjIndexByNumber = (PDll_TDGetObjIndexByNumber)GetProcAddress(hDLL_DATSERV, "TDGetObjIndexByNumber");
		Dll_TDGetObjNumber = (PDll_TDGetObjNumber)GetProcAddress(hDLL_DATSERV, "TDGetObjNumber");
		Dll_TDGetRusName = (PDll_TDGetRusName)GetProcAddress(hDLL_DATSERV, "TDGetRusName");
		Dll_TDInsertFD = (PDll_TDInsertFD)GetProcAddress(hDLL_DATSERV, "TDInsertFD");
		Dll_TDInsertNewAtom = (PDll_TDInsertNewAtom)GetProcAddress(hDLL_DATSERV, "TDInsertNewAtom");
		Dll_TDSetAnglName = (PDll_TDSetAnglName)GetProcAddress(hDLL_DATSERV, "TDSetAnglName");
		Dll_TDSetLongName = (PDll_TDSetLongName)GetProcAddress(hDLL_DATSERV, "TDSetLongName");
		Dll_TDSetName = (PDll_TDSetName)GetProcAddress(hDLL_DATSERV, "TDSetName");
		Dll_TDSetRusName = (PDll_TDSetRusName)GetProcAddress(hDLL_DATSERV, "TDSetRusName");

		#define DLL_FUNC(RET, NAME, PARAMS) Dll_##NAME = (PDll_##NAME)GetProcAddress(hDLL_DATSERV, #NAME);
		ALL_FUNCS
		#undef DLL_FUNC

		GetBlanks();
		SetChangeBlankNotifyProc((void*)ChangeBlankNotifyProc);
	};
}

extern "C" void GetBlanks(void)
{
        GetDatservBlanks(
          &BlankByte,
          &BlankInt,
          &BlankWord,
          &BlankLongInt,
          &BlankSingle,
          &BlankDouble,
          &BlankTime,
          &BlankDate,
          BlankStr
        );
}

extern "C" void SetBlanks(void)
{
        SetDatservBlanks(
          BlankByte,
          BlankInt,
          BlankWord,
          BlankLongInt,
          BlankSingle,
          BlankDouble,
          BlankTime,
          BlankDate,
          BlankStr
        );
}

HINSTANCE DSAPI_GetThisModuleHandle(void){
  MEMORY_BASIC_INFORMATION MemInfo;
  VirtualQuery((void*)&DSAPI_GetThisModuleHandle, &MemInfo, sizeof(MemInfo));
  if (MemInfo.State == MEM_COMMIT)
  { return (HINSTANCE) MemInfo.AllocationBase; }
  else
  { return 0; }
}

long DSAPI_GetThisDirModuleName(const char* Name, char *PathAndName, long MaxLen){
	HINSTANCE H = DSAPI_GetThisModuleHandle();
	long Res = GetModuleFileName(H,PathAndName,MaxLen);
	if (!Res) { return 0; }
	for (int i = Res-1; (i >= 0) && (PathAndName[i] != '\\'); i-- ) { Res = i; }
	PathAndName[Res] = '\0';
	strncat(PathAndName,Name,MaxLen-Res);
	Res = strlen(PathAndName);
	return Res;
}


extern "C" LongBoolean DatservLoad(void){
	hDLL_DATSERV = LoadLibrary(DATSERVDLL);
	if (hDLL_DATSERV == NULL){
		char NewName[MAX_PATH];
		if (DSAPI_GetThisDirModuleName(DATSERVDLL,NewName,MAX_PATH))
		{
			hDLL_DATSERV = LoadLibrary(NewName);
		}
	}
	if (hDLL_DATSERV != NULL){
		ConnectDatservFunctions();
		return true;
	}
	else {
		return false;
	};
}

extern "C" void DatservFree(void) {
	if (hDLL_DATSERV != NULL) {
		FreeLibrary(hDLL_DATSERV);
	}
}

extern "C" LongBoolean DatservConnect(void){
	hDLL_DATSERV = GetModuleHandle(DATSERVDLL);
	if (hDLL_DATSERV != NULL){
		ConnectDatservFunctions();
		return true;
	}
	else {
		return false;
	};
}


/*****************************************************************************/


void  DoneDSObj(void *P){
	if ((hDLL_DATSERV == NULL)||(!Dll_DoneDSObj)) { return; }
	else { Dll_DoneDSObj(P); return; }
}

void  DSFreeMem(void *P,unsigned short Size){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSFreeMem)) { return; }
	else { Dll_DSFreeMem(P,Size); return; }
}

short DoneHandle(OType *Handle){
	if ((hDLL_DATSERV == NULL)||(!Dll_DoneHandle)) { return -1; }
	else { return Dll_DoneHandle(Handle); }
}

short CopyHandle(OType Handle,OType *NewHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CopyHandle)) { return -1; }
	else { return Dll_CopyHandle(Handle,NewHandle); }
}

short CopyNewHandle(OType Handle,OType *NewHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CopyNewHandle)) { return -1; }
	else { return Dll_CopyNewHandle(Handle,NewHandle); }
}

short HandleGetType(OType Handle,unsigned char *aType){
	if ((hDLL_DATSERV == NULL)||(!Dll_HandleGetType)) { return -1; }
	else { return Dll_HandleGetType(Handle,aType); }
}

void  ClearDatServ(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_ClearDatServ)) { return; }
	else { Dll_ClearDatServ(); return; }
}


short InitTDesc(const char *TablName,OType *TDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_InitTDesc)) { return -1; }
	else { return Dll_InitTDesc(WinToDos(TablName),TDescHandle); }
}

short GetTDesc(OType DataHandle,const char *TablName,OType *TDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDesc)) { return -1; }
	else { return Dll_GetTDesc(DataHandle,WinToDos(TablName),TDescHandle); }
}

short GetTDescF(const char *FileName,const char *TablName,OType *TDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDescF)) { return -1; }
	else { return Dll_GetTDescF(FileName,WinToDos(TablName),TDescHandle); }
}

short TDCheckDesc(OType TDescHandle,OType TDescHandle1,unsigned char *Result){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDCheckDesc)) { return -1; }
	else { return Dll_TDCheckDesc(TDescHandle,TDescHandle1,Result); }
}

short TDGetArrayCounter(OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetArrayCounter)) { return -1; }
	else { return Dll_TDGetArrayCounter(TDHandle); }
}

short TDGetObjCounter(OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetObjCounter)) { return -1; }
	else { return Dll_TDGetObjCounter(TDHandle); }
}

short TDGetName(OType TDHandle,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetName)) { return -1; }
	else {result = Dll_TDGetName(TDHandle,Res); CDosToWin(Res); return result; }
}

short TDGetLongName(OType TDHandle,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetLongName)) { return -1; }
	else {result = Dll_TDGetLongName(TDHandle,Res);  CDosToWin(Res); return result;}
}

short TDGetAnglName(OType TDHandle,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetAnglName)) { return -1; }
	else {result = Dll_TDGetAnglName(TDHandle,Res); CDosToWin(Res); return result; }
}

short TDGetRusName(OType TDHandle,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetRusName)) { return -1; }
	else { result = Dll_TDGetRusName(TDHandle,Res); CDosToWin(Res); return result; }
}

short TDSetName(OType TDHandle,const char *Name){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDSetName)) { return -1; }
	else { return Dll_TDSetName(TDHandle,WinToDos(Name)); }
}

short TDSetLongName(OType TDHandle,const char *Name){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDSetLongName)) { return -1; }
	else { return Dll_TDSetLongName(TDHandle,WinToDos(Name)); }
}

short TDSetAnglName(OType TDHandle,const char *Name){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDSetAnglName)) { return -1; }
	else { return Dll_TDSetAnglName(TDHandle,WinToDos(Name)); }
}

short TDSetRusName(OType TDHandle,const char *Name){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDSetRusName)) { return -1; }
	else { return Dll_TDSetRusName(TDHandle,WinToDos(Name)); }
}

short TDGetArrayIndexByNumber(unsigned char Number,OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetArrayIndexByNumber)) { return -1; }
	else { return Dll_TDGetArrayIndexByNumber(Number,TDHandle); }
}

short TDGetArrayIndex(const char *AName,OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetArrayIndex)) { return -1; }
	else { return Dll_TDGetArrayIndex(WinToDos(AName),TDHandle); }
}

short TDGetArrayNumber(OType TDHandle,const char *AName){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetArrayNumber)) { return -1; }
	else { return Dll_TDGetArrayNumber(TDHandle,WinToDos(AName)); }
}

short TDGetObjIndexByNumber(unsigned char Number,OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetObjIndexByNumber)) { return -1; }
	else { return Dll_TDGetObjIndexByNumber(Number,TDHandle); }
}

short TDGetObjIndex(const char *AName,OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetObjIndex)) { return -1; }
	else { return Dll_TDGetObjIndex(WinToDos(AName),TDHandle); }
}

short TDGetObjNumber(OType TDHandle,const char *AName){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetObjNumber)) { return -1; }
	else { return Dll_TDGetObjNumber(TDHandle,WinToDos(AName)); }
}

short TDGetFieldIndex(const char *AName,OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetFieldIndex)) { return -1; }
	else { return Dll_TDGetFieldIndex(WinToDos(AName),TDHandle); }
}

short TDInsertFD(OType TDHandle, OType FDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDInsertFD)) { return -1; }
	else { return Dll_TDInsertFD(TDHandle,FDHandle); }
}

short TDAtInsertFD(OType TDHandle,short i,OType FDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDAtInsertFD)) { return -1; }
	else { return Dll_TDAtInsertFD(TDHandle,i,FDHandle); }
}

short TDAtPutFD(OType TDHandle,short i,OType FDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDAtPutFD)) { return -1; }
	else { return Dll_TDAtPutFD(TDHandle,i,FDHandle); }
}

short TDAtFreeFD(OType TDHandle,short i){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDAtFreeFD)) { return -1; }
	else { return Dll_TDAtFreeFD(TDHandle,i); }
}

LongBoolean TDCheckRepeating(OType TDHandle,char *S1){
	LongBoolean result;
	if ((hDLL_DATSERV == NULL)||(!Dll_TDCheckRepeating)) { return false; }
	else {
		result = Dll_TDCheckRepeating(TDHandle,S1);
		CDosToWin(S1);
		return result;
	}
}

short PutTDesc(const char *ResFileName,OType TDHandle,LongBoolean ChkCopy){
	if ((hDLL_DATSERV == NULL)||(!Dll_PutTDesc)) { return -1; }
	else { return Dll_PutTDesc(ResFileName,TDHandle,ChkCopy); }
}

short TDFreeAll(OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDFreeAll)) { return -1; }
	else { return Dll_TDFreeAll(TDHandle); }
}

short GetTDescName(OType TDescHandle,char *Name){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDescName)) { return -1; }
	else { return Dll_GetTDescName(TDescHandle,Name); }
}

short GetTDescFldsN(OType TDescHandle,const char *FieldName,PCFDData PFDesc){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDescFldsN)) { return -1; }
	else {
		result =  Dll_GetTDescFldsN(TDescHandle,WinToDos(FieldName),PFDesc);
		if (PFDesc) {
			CDosToWin(PFDesc->afldName);
			CDosToWin(PFDesc->afldUnitName);
			CDosToWin(PFDesc->aMin);
			CDosToWin(PFDesc->aMax);
			CDosToWin(PFDesc->fldComment);
		};
		return result;
	}
}

short GetTDescFldsI(OType TDescHandle,unsigned short FieldNumber,PCFDData PFDesc){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDescFldsI)) { return -1; }
	else {
		result = Dll_GetTDescFldsI(TDescHandle,FieldNumber,PFDesc);
		if (PFDesc) {
			CDosToWin(PFDesc->afldName);
			CDosToWin(PFDesc->afldUnitName);
			CDosToWin(PFDesc->aMin);
			CDosToWin(PFDesc->aMax);
			CDosToWin(PFDesc->fldComment);
		};
		return result;
	}
}

short GetTDKeyStr(OType TDescHandle,unsigned char SLen,char *KeyStr){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDKeyStr)) { return -1; }
	else { result = Dll_GetTDKeyStr(TDescHandle,SLen,KeyStr); CDosToWin(KeyStr); return result; }
}

short MakeDKeyTablDesc(OType TDescHandle,OType *KeyTD){
	if ((hDLL_DATSERV == NULL)||(!Dll_MakeDKeyTablDesc)) { return -1; }
	else { return Dll_MakeDKeyTablDesc(TDescHandle,KeyTD); }
}

short GetAnyKeyStr(OType MasterDesc, OType SlaveDesc,unsigned char SLen,char *KeyStr){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetAnyKeyStr)) { return -1; }
	else { result=Dll_GetAnyKeyStr(MasterDesc,SlaveDesc,SLen,KeyStr); CDosToWin(KeyStr); return result;}
}

short GetTDDefinedValue(OType TDescHandle,const char *FieldName,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDDefinedValue)) { return -1; }
	else { return Dll_GetTDDefinedValue(TDescHandle,WinToDos(FieldName),ObValHandle); }
}

float GetDefSingle(OType TDescHandle, const char *FieldName){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetDefSingle)) { return BlankSingle; }
	else { return Dll_GetDefSingle(TDescHandle,WinToDos(FieldName)); }
}

long GetDefLong(OType TDescHandle, const char *FieldName){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetDefLong)) { return BlankLongInt; }
	else { return Dll_GetDefLong(TDescHandle,WinToDos(FieldName)); }
}

short GetDefStr(OType TDescHandle, const char *FieldName, char *Value){
        short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetDefStr)) { return -1; }
	else { result = Dll_GetDefStr(TDescHandle,WinToDos(FieldName),Value); CDosToWin(Value); StrTrim(Value); return result; }
}

short TDGetAtomNameAt(OType TDHandle, short i, char *AtomName){
        short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_TDGetAtomNameAt)) { return -1; }
	else { result = Dll_TDGetAtomNameAt(TDHandle,i,AtomName); CDosToWin(AtomName); return result; }
}

short TDInsertNewAtom(OType TDHandle, const char *Name){
	if ((hDLL_DATSERV == NULL)||(!Dll_TDInsertNewAtom)) { return -1; }
	else { return Dll_TDInsertNewAtom(TDHandle,WinToDos(Name)); }
}

short InitFDesc(const char *afldName,const char *afldUnitName,unsigned char afldType,short afldLen,OType *FDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_InitFDesc)) { return -1; }
	else { return Dll_InitFDesc(WinToDos(afldName),WinToDos(afldUnitName),afldType,afldLen,FDescHandle); }
}

short GetFDescByName(OType TDescHandle,const char *FieldName,OType *FDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDescByName)) { return -1; }
	else { return Dll_GetFDescByName(TDescHandle,WinToDos(FieldName),FDescHandle); }
}

short GetTDescCounter(OType TDescHandle,unsigned short *TDCounter){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTDescCounter)) { return -1; }
	else { return Dll_GetTDescCounter(TDescHandle,TDCounter); }
}

short SetFDescSlave(OType FDescHandle,LongBoolean M){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetFDescSlave)) { return -1; }
	else { return Dll_SetFDescSlave(FDescHandle,M); }
}

LongBoolean  IsFDescSlave(OType FDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_IsFDescSlave)) { return false; }
	else { return Dll_IsFDescSlave(FDescHandle); }
}

short GetFDescByNumber(OType TDescHandle,unsigned short FieldNumber,OType *FDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDescByNumber)) { return -1; }
	else { return Dll_GetFDescByNumber(TDescHandle,FieldNumber,FDescHandle); }
}

short GetFDescFlds(OType FDescHandle,PCFDData FDesc){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDescFlds)) { return -1; }
	else {
		result = Dll_GetFDescFlds(FDescHandle,FDesc);
		if (FDesc) {
			CDosToWin(FDesc->afldName);
			CDosToWin(FDesc->afldUnitName);
			CDosToWin(FDesc->aMin);
			CDosToWin(FDesc->aMax);
			CDosToWin(FDesc->fldComment);
		};
		return result;
	}
}

short SetFDescFlds(OType FDescHandle,PCFDData FDesc){
	short result;
	TCFDData TempFDesc;
	if ((hDLL_DATSERV == NULL)||(!Dll_SetFDescFlds)) { return -1; }
	else {
		result = 0;
		if (FDesc) {
			strcpy((TempFDesc.afldName),WinToDos(FDesc->afldName));
			strcpy((TempFDesc.afldUnitName), WinToDos(FDesc->afldUnitName));
			strcpy((TempFDesc.aMin), WinToDos(FDesc->aMin));
			strcpy((TempFDesc.aMax), WinToDos(FDesc->aMax));
			strcpy((TempFDesc.fldComment), WinToDos(FDesc->fldComment));
			return Dll_SetFDescFlds(FDescHandle,FDesc);
		};
		return result;
	}
}

short LFDescCompary(OType FDescHandle,OType FDescHandle1,unsigned char *Result){
	if ((hDLL_DATSERV == NULL)||(!Dll_LFDescCompary)) { return -1; }
	else { return Dll_LFDescCompary(FDescHandle,FDescHandle1,Result); }
}

short GetFDescAccess(OType FDescHandle,unsigned char *Access){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDescAccess)) { return -1; }
	else { return Dll_GetFDescAccess(FDescHandle,Access); }
}

unsigned short GetFDMask(OType FDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDMask)) { return 0; }
	else { return Dll_GetFDMask(FDescHandle); }
}

short SetFDMask(OType FDescHandle,unsigned short Mask){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetFDMask)) { return -1; }
	else { return Dll_SetFDMask(FDescHandle,Mask); }
}

short GetFDescRC(OType FDescHandle,unsigned char *RC){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDescRC)) { return -1; }
	else { return Dll_GetFDescRC(FDescHandle,RC); }
}

short GetFDescKey(OType FDescHandle,unsigned char *Key){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDescKey)) { return -1; }
	else { return Dll_GetFDescKey(FDescHandle,Key); }
}

short SetFDescKey(OType FDescHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetFDescKey)) { return -1; }
	else { return Dll_SetFDescKey(FDescHandle); }
}

void GetSystemDir(char *Dir){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSystemDir)) { }
	else { Dll_GetSystemDir(Dir); }
}

short PutScale(CScalLineType *SL){
	CScalLineType SL1;
	if ((hDLL_DATSERV == NULL)||(!Dll_PutScale)) { return -1; }
	else {
		strcpy((SL1.Name1), WinToDos(SL->Name1));
		strcpy((SL1.Name2), WinToDos(SL->Name2));
		return Dll_PutScale(&SL1);
	}
}

short GetScale(CScalLineType *SL){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetScale)) { return -1; }
	else {
                CWinToDos(SL->Name1);
                CWinToDos(SL->Name1);
		result = Dll_GetScale(SL);
		CDosToWin(SL->Name1);
		CDosToWin(SL->Name2);
		return result;
	}
}

short GetFDFactor(OType TDescHandle,const char *FDName,const char *FDUnit,float *Factor){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDFactor)) { return -1; }
	else { return Dll_GetFDFactor(TDescHandle,WinToDos(FDName),WinToDos(FDUnit),Factor); }
}

short GetFDNFactor(OType TDescHandle,short Index,const char *FDUnit,float *Factor){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDNFactor)) { return -1; }
	else { return Dll_GetFDNFactor(TDescHandle,Index,WinToDos(FDUnit),Factor); }
}

short GetFDFactorEx(OType TDescHandle,const char *FDName,const char *FDUnit,char *Unit1,float *Factor){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDFactorEx)) { return -1; }
	else {
		result = Dll_GetFDFactorEx(TDescHandle,WinToDos(FDName),WinToDos(FDUnit),Unit1,Factor);
		CDosToWin(Unit1);
		return result;
	}
}

short GetFDNFactorEx(OType TDescHandle,short Index,const char *FDUnit,char *Unit1,float *Factor){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDNFactorEx)) { return -1; }
	else {
		result = Dll_GetFDNFactorEx(TDescHandle,Index,FDUnit,Unit1,Factor);
		CDosToWin(Unit1);
		return result;
	}
}

short GetFDArrDesc(OType FDescHandle,OType *TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDArrDesc)) { return -1; }
	else { return Dll_GetFDArrDesc(FDescHandle,TDHandle); }
}

short SetFDArrDesc(OType FDescHandle,OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetFDArrDesc)) { return -1; }
	else { return Dll_SetFDArrDesc(FDescHandle,TDHandle); }
}

short SetFDClass(OType FDescHandle,const char *ClsName){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetFDClass)) { return -1; }
	else { return Dll_SetFDClass(FDescHandle,WinToDos(ClsName)); }
}

short GetFDClass(OType FDescHandle,char *ClsName){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFDClass)) { return -1; }
	else {
		result = Dll_GetFDClass(FDescHandle,ClsName);
		CDosToWin(ClsName);
		return result;
	}
}

short CreateSysData(const char *ResFileName,OType *DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CreateSysData)) { return -1; }
	else { return Dll_CreateSysData(ResFileName,DataHandle); }
}

short InitSysData(const char *ResFileName,OType *DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_InitSysData)) { return -1; }
	else { return Dll_InitSysData(ResFileName,DataHandle); }
}

short GetLogFile(const char *FileName,LongBoolean *Status,OType DataHandle,OType *LFHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetLogFile)) { return -1; }
	else { return Dll_GetLogFile(FileName,Status,DataHandle,LFHandle); }
}

short RemoveLogFile(OType DataHandle,OType LFHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_RemoveLogFile)) { return -1; }
	else { return Dll_RemoveLogFile(DataHandle,LFHandle); }
}

short GetResFileName(OType DataHandle,char *Res){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetResFileName)) { return -1; }
	else { return Dll_GetResFileName(DataHandle,Res); }
}

unsigned short ResStreamSt(OType DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResStreamSt)) { return 0; }
	else { return Dll_ResStreamSt(DataHandle); }
}

LongBoolean ResIsModified(OType DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResIsModified)) { return false; }
	else { return Dll_ResIsModified(DataHandle); }
}

short PackRes(OType DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_PackRes)) { return -1; }
	else { return Dll_PackRes(DataHandle); }
}

short ResPutTD(OType DataHandle,OType TDesc,const char *Key){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResPutTD)) { return -1; }
	else { return Dll_ResPutTD(DataHandle,TDesc,WinToDos(Key)); }
}

short ResDeleteTD(OType DataHandle,const char *Key){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResDeleteTD)) { return -1; }
	else { return Dll_ResDeleteTD(DataHandle,WinToDos(Key)); }
}

short ResRemoveMemTD(OType DataHandle,const char *TablName){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResRemoveMemTD)) { return -1; }
	else { return Dll_ResRemoveMemTD(DataHandle,WinToDos(TablName)); }
}

LongBoolean ExistInRes(const char *Key,OType DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ExistInRes)) { return false; }
	else { return Dll_ExistInRes(WinToDos(Key),DataHandle); }
}

short ResGetKeyCounter(OType DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResGetKeyCounter)) { return -1; }
	else { return Dll_ResGetKeyCounter(DataHandle); }
}

short ResGetKeyAt(OType DataHandle,short i,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ResGetKeyAt)) { return -1; }
	else {
		result = Dll_ResGetKeyAt(DataHandle,i,Res);
		CDosToWin(Res);
		return result;
	}
}

short ResGetMemTD(OType DataHandle,short Index,OType *TDesc){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResGetMemTD)) { return -1; }
	else { return Dll_ResGetMemTD(DataHandle,Index,TDesc); }
}

short ResAddMemTD(OType DataHandle,OType TDesc){
	if ((hDLL_DATSERV == NULL)||(!Dll_ResAddMemTD)) { return -1; }
	else { return Dll_ResAddMemTD(DataHandle,TDesc); }
}

short SysLFInitOpen(const char *FileName,OType *LFHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_SysLFInitOpen)) { return -1; }
	else { return Dll_SysLFInitOpen(FileName,LFHandle); }
}

short SysLFInitOpenEx(const char *FileName, OType *LFHandle, int LROption, int ObjOption) {
	if ((hDLL_DATSERV == NULL)||(!Dll_SysLFInitOpenEx)) { return -1; }
	else { return Dll_SysLFInitOpenEx(FileName,LFHandle, LROption, ObjOption); }
}

short SysLFCreate(const char *FileName,OType DataHandle,OType *LFHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_SysLFCreate)) { return -1; }
	else { return Dll_SysLFCreate(FileName,DataHandle,LFHandle); }
}

short SaveNewObj(const char *SelectedAim,const char *aTablName,LongBoolean CheckCopy,LongBoolean CheckIntent,OType LFHandle,OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_SaveNewObj)) { return -1; }
	else { return Dll_SaveNewObj(WinToDos(SelectedAim),WinToDos(aTablName),CheckCopy,CheckIntent,LFHandle,ObjHandle); }
}

short SaveNewObjEx(const char *SelectedAim,const char *aTablName,LongBoolean CheckCopy,LongBoolean CheckIntent,OType LFHandle,OType ObjHandle,OType *NewObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_SaveNewObjEx)) { return -1; }
	else { return Dll_SaveNewObjEx(WinToDos(SelectedAim),WinToDos(aTablName),CheckCopy,CheckIntent,LFHandle,ObjHandle,NewObjHandle); }
}

short LFAppend(OType MainLF,OType OtherLF,unsigned short Option){
	if ((hDLL_DATSERV == NULL)||(!Dll_LFAppend)) { return -1; }
	else { return Dll_LFAppend(MainLF,OtherLF,Option); }
}

short LFPackTo(OType LFHandle,const char *bName,long *Delta){
	if ((hDLL_DATSERV == NULL)||(!Dll_LFPackTo)) { return -1; }
	else { return Dll_LFPackTo(LFHandle,bName,Delta); }
}

short FindFirst(OType LFHandle,OType SOHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_FindFirst)) { return -1; }
	else { return Dll_FindFirst(LFHandle,SOHandle,ObjHandle); }
}

short FindFirstLocal(OType LFHandle,OType SOHandle,const char *TablName,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_FindFirstLocal)) { return -1; }
	else { return Dll_FindFirstLocal(LFHandle,SOHandle,WinToDos(TablName),ObjHandle); }
}

short FindNext(OType LFHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_FindNext)) { return -1; }
	else { return Dll_FindNext(LFHandle,ObjHandle); }
}

short Goto_BeginTable(OType LFHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Goto_BeginTable)) { return -1; }
	else { return Dll_Goto_BeginTable(LFHandle); }
}

short Goto_NextTable(OType LFHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Goto_NextTable)) { return -1; }
	else { return Dll_Goto_NextTable(LFHandle); }
}

long GetIndexViewsList(const char *WSName, const char *TablName, const char *Delim, long Option, char *Res){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetIndexViewsList)) { return -1; }
	else { return Dll_GetIndexViewsList(WSName,TablName,Delim,Option,Res); }
}

long GetWSViewsList(const char *WSName, const char *TablName, const char *Delim, long Option, char **Res){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetWSViewsList)) { return -1; }
	else { return Dll_GetWSViewsList(WSName,TablName,Delim,Option,Res); }
}

long GetWSViewsListXml(const char *WSName, const char *TablName, int Option, char **Res) {
	if ((hDLL_DATSERV == NULL)||(!Dll_GetWSViewsListXml)) { return -1; }
	else { return Dll_GetWSViewsListXml(WSName,TablName,Option,Res); }
}

long FreeDSMem(char *pointer, int Size, int Option) {
	if ((hDLL_DATSERV == NULL)||(!Dll_FreeDSMem)) { return -1; }
	else { return Dll_FreeDSMem(pointer, Size, Option); }
}

short TableExist(const char *TableName,OType LFHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_TableExist)) { return -1; }
	else { return Dll_TableExist(WinToDos(TableName),LFHandle); }
}

short GetCurTable(OType LFHandle,OType *LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetCurTable)) { return -1; }
	else { return Dll_GetCurTable(LFHandle,LRHandle); }
}

short Get_Table(const char *TableName,OType LF,OType *LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Get_Table)) { return -1; }
	else { return Dll_Get_Table(WinToDos(TableName),LF,LRHandle); }
}

short Get_TableNew(const char *TableName,OType LFHandle,OType *LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Get_TableNew)) { return -1; }
	else { return Dll_Get_TableNew(WinToDos(TableName),LFHandle,LRHandle); }
}

short GetTableName(OType LRHandle,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTableName)) { return -1; }
	else {
		result = Dll_GetTableName(LRHandle,Res);
		CDosToWin(Res);
		return result;
	}
}

short GetWSHandle(OType LRHandle, OType *WSHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetWSHandle)) { return -1; }
	else { return Dll_GetWSHandle(LRHandle, WSHandle); }
}

short LRChangeName(OType LRHandle,const char *NewName){
	if ((hDLL_DATSERV == NULL)||(!Dll_LRChangeName)) { return -1; }
	else { return Dll_LRChangeName(LRHandle,WinToDos(NewName)); }
}

short LRPutTDesc(OType LRHandle,OType TDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_LRPutTDesc)) { return -1; }
	else { return Dll_LRPutTDesc(LRHandle,TDHandle); }
}


short Goto_BeginObj(OType LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Goto_BeginObj)) { return -1; }
	else { return Dll_Goto_BeginObj(LRHandle); }
}

short Goto_FastBeginObj(OType LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Goto_FastBeginObj)) { return -1; }
	else { return Dll_Goto_FastBeginObj(LRHandle); }
}

short Goto_NextObj(OType LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Goto_NextObj)) { return -1; }
	else { return Dll_Goto_NextObj(LRHandle); }
}

short Goto_FastNextObj(OType LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Goto_FastNextObj)) { return -1; }
	else { return Dll_Goto_FastNextObj(LRHandle); }
}

short LRPutObj(OType LRHandle,OType aDataObj,LongBoolean CheckCopy,LongBoolean aNewTable){
	if ((hDLL_DATSERV == NULL)||(!Dll_LRPutObj)) { return -1; }
	else { return Dll_LRPutObj(LRHandle,aDataObj,CheckCopy,aNewTable); }
}

unsigned char LRCheckKeyObj(OType LRHandle,OType aDataObj,OType TDescHandle,unsigned short *IdN,OType *FindedObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_LRCheckKeyObj)) { return 0; }
	else { return Dll_LRCheckKeyObj(LRHandle,aDataObj,TDescHandle,IdN,FindedObjHandle); }
}


short GetCurObj(OType LRHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetCurObj)) { return -1; }
	else { return Dll_GetCurObj(LRHandle,ObjHandle); }
}

short GetFastCurObj(OType LRHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFastCurObj)) { return -1; }
	else { return Dll_GetFastCurObj(LRHandle,ObjHandle); }
}

short GetTrueCurObj(OType LRHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTrueCurObj)) { return -1; }
	else { return Dll_GetTrueCurObj(LRHandle,ObjHandle); }
}

short GetTrueFastCurObj(OType LRHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTrueFastCurObj)) { return -1; }
	else { return Dll_GetTrueFastCurObj(LRHandle,ObjHandle); }
}

short ObjTDCopy(OType TableHandle,OType ObjHandle,OType *NewObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjTDCopy)) { return -1; }
	else { return Dll_ObjTDCopy(TableHandle,ObjHandle,NewObjHandle); }
}

short ObjCopyBlank(OType ObjHandle,OType *NewObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjCopyBlank)) { return -1; }
	else { return Dll_ObjCopyBlank(ObjHandle,NewObjHandle); }
}

short BlankObj(OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_BlankObj)) { return -1; }
	else { return Dll_BlankObj(ObjHandle); }
}

short GetObjByIdN(OType LRHandle,unsigned short Idn,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetObjByIdN)) { return -1; }
	else { return Dll_GetObjByIdN(LRHandle,Idn,ObjHandle); }
}

short GetObjByEIdN(OType LRHandle,unsigned short ObjType,unsigned short Idn,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetObjByEIdN)) { return -1; }
	else { return Dll_GetObjByEIdN(LRHandle,ObjType,Idn,ObjHandle); }
}

short ObjTDInit(const char *ResFileName,const char *TablName,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjTDInit)) { return -1; }
	else { return Dll_ObjTDInit(ResFileName,WinToDos(TablName),ObjHandle); }
}

short ObjTDInitH(OType TableHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjTDInitH)) { return -1; }
	else { return Dll_ObjTDInitH(TableHandle,ObjHandle); }
}

short ObjAtPut(OType ObjHandle,short I,OType Handle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjAtPut)) { return -1; }
	else { return Dll_ObjAtPut(ObjHandle,I,Handle); }
}

short ObjWriteASCII(OType ObjHandle,const char *FileName,LongBoolean Owrw){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjWriteASCII)) { return -1; }
	else { return Dll_ObjWriteASCII(ObjHandle,FileName,Owrw); }
}

short GetWSObj(OType LFHandle,unsigned short IdN,const char *TablName,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetWSObj)) { return -1; }
	else { return Dll_GetWSObj(LFHandle,IdN,WinToDos(TablName),ObjHandle); }
}

short GetWSKeyObj(OType LFHandle,const char *TablName,const char *KeyStr,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetWSKeyObj)) { return -1; }
	else { return Dll_GetWSKeyObj(LFHandle,WinToDos(TablName),WinToDos(KeyStr),ObjHandle); }
}

short ImportObj(OType TDescHandle,const char *ImportFile,const char *TablName,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ImportObj)) { return -1; }
	else { return Dll_ImportObj(TDescHandle,ImportFile,WinToDos(TablName),ObjHandle); }
}

short ExportObj (const char *ExportFile,OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ExportObj)) { return -1; }
	else { return Dll_ExportObj (ExportFile,ObjHandle); }
}

short ObjInit(OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjInit)) { return -1; }
	else { return Dll_ObjInit(ObjHandle); }
}

short GetKeyStr(OType ObjHandle,unsigned short ID,unsigned char SLen,char *S){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetKeyStr)) { return -1; }
	else {
		result = Dll_GetKeyStr(ObjHandle,ID,SLen,S);
		CDosToWin(S);
		return result;
	}
}

short ObjGetAnyKeyStr(OType ObjHandle,OType SlaveDesc,unsigned short ID,unsigned char SLen,char *S){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjGetAnyKeyStr)) { return -1; }
	else {
		result = Dll_ObjGetAnyKeyStr(ObjHandle,SlaveDesc,ID,SLen,S);
		CDosToWin(S);
		return result;
	}
}

short GetMetaKeyStr(OType ObjHandle,unsigned char SLen,char *S){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetMetaKeyStr)) { return -1; }
	else {
		result = Dll_GetMetaKeyStr(ObjHandle,SLen,S);
		CDosToWin(S);
		return result;
	}
}

unsigned short GetRowNumber(OType ObjHandle,OType LFHandle,const char *TableName){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetRowNumber)) { return 0; }
	else { return Dll_GetRowNumber(ObjHandle,LFHandle,WinToDos(TableName)); }
}

short GetTemplate(OType ObjHandle,OType *THandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTemplate)) { return -1; }
	else { return Dll_GetTemplate(ObjHandle,THandle); }
}

short SetTemplate(OType ObjHandle,OType THandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetTemplate)) { return -1; }
	else { return Dll_SetTemplate(ObjHandle,THandle); }
}

short ObjAdd_ObVal(OType ObjHandle,OType  ObValHandle,OType FDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjAdd_ObVal)) { return -1; }
	else { return Dll_ObjAdd_ObVal(ObjHandle,ObValHandle,FDHandle); }
}

short ObjAddAt_ObVal(OType ObjHandle,OType ObValHandle,OType FDHandle,short Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjAddAt_ObVal)) { return -1; }
	else { return Dll_ObjAddAt_ObVal(ObjHandle,ObValHandle,FDHandle,Index); }
}

short ObjAdd_Arr(OType ObjHandle,OType ArrHandle,OType FDHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjAdd_Arr)) { return -1; }
	else { return Dll_ObjAdd_Arr(ObjHandle,ArrHandle,FDHandle); }
}

short MoveToBuf(OType ObjHandle,void *Buf, long bufsize){
	if ((hDLL_DATSERV == NULL)||(!Dll_MoveToBuf)) { return -1; }
	else { return Dll_MoveToBuf(ObjHandle,Buf,bufsize); }
}

short MoveFromBuf(OType ObjHandle,void *Buf, long bufsize){
	if ((hDLL_DATSERV == NULL)||(!Dll_MoveFromBuf)) { return -1; }
	else { return Dll_MoveFromBuf(ObjHandle,Buf,bufsize); }
}

long GetObjBinarySize(OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetObjBinarySize)) { return -1; }
	else { return Dll_GetObjBinarySize(ObjHandle); }
}

LongBoolean GetObjState(OType ObjHandle,unsigned short Mask){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetObjState)) { return false; }
	else { return Dll_GetObjState(ObjHandle,Mask); }
}

short SetObjState(OType ObjHandle,unsigned short Mask,LongBoolean Enable){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetObjState)) { return -1; }
	else { return Dll_SetObjState(ObjHandle,Mask,Enable); }
}

short GetObjByName(OType MainObjHandle,const char *AName,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetObjByName)) { return -1; }
	else { return Dll_GetObjByName(MainObjHandle,WinToDos(AName),ObjHandle); }
}

short GetObjByNumber(OType MainObjHandle,short ObjNumber,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetObjByNumber)) { return -1; }
	else { return Dll_GetObjByNumber(MainObjHandle,ObjNumber,ObjHandle); }
}

LongBoolean ChkGroup(OType ObjHandle1,OType ObjHandle2){
	if ((hDLL_DATSERV == NULL)||(!Dll_ChkGroup)) { return false; }
	else { return Dll_ChkGroup(ObjHandle1,ObjHandle2); }
}

short ReplaceArr(OType ObjHandle,const char *ArrName,unsigned char Column1,unsigned char Column2,unsigned short Option){
	if ((hDLL_DATSERV == NULL)||(!Dll_ReplaceArr)) { return -1; }
	else { return Dll_ReplaceArr(ObjHandle,WinToDos(ArrName),Column1,Column2,Option); }
}

short DeleteObj(OType ObjHandle,OType LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_DeleteObj)) { return -1; }
	else { return Dll_DeleteObj(ObjHandle,LRHandle); }
}

short RestoreObj(OType ObjHandle,OType LRHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_RestoreObj)) { return -1; }
	else { return Dll_RestoreObj(ObjHandle,LRHandle); }
}

short ObjTakeByTDesc(OType ToObjHandle,OType FromObjHandle,unsigned short Option){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjTakeByTDesc)) { return -1; }
	else { return Dll_ObjTakeByTDesc(ToObjHandle,FromObjHandle,Option); }
}

short ObjGetHandleIndex(OType ObjHandle,OType Handle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjGetHandleIndex)) { return -1; }
	else { return Dll_ObjGetHandleIndex(ObjHandle,Handle); }
}

short ImportStrObj(OType TDescHandle,char *Str,OType *ObjHandle){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ImportStrObj)) { return -1; }
	else { result = Dll_ImportStrObj(TDescHandle,Str,ObjHandle); CDosToWin(Str); return result;}
}

short AddHistory(OType ObjHandle,const char *FieldName,const char *HistStr){
	if ((hDLL_DATSERV == NULL)||(!Dll_AddHistory)) { return -1; }
	else { return Dll_AddHistory(ObjHandle,WinToDos(FieldName),WinToDos(HistStr)); }
}

short IncVersion(OType ObjHandle,const char *FieldName){
	if ((hDLL_DATSERV == NULL)||(!Dll_IncVersion)) { return -1; }
	else { return Dll_IncVersion(ObjHandle,WinToDos(FieldName)); }
}

short InitCurve(OType DataHandle,unsigned short ArrayNumber,OType *CurveHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_InitCurve)) { return -1; }
	else { return Dll_InitCurve(DataHandle,ArrayNumber,CurveHandle); }
}

unsigned short CurveGetCount(OType CurveHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveGetCount)) { return 0; }
	else { return Dll_CurveGetCount(CurveHandle); }
}

short CurveSetParams(OType CurveHandle,float aRoof,float aSole,float aStep,const char *fldUnit){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveSetParams)) { return -1; }
	else { return Dll_CurveSetParams(CurveHandle,aRoof,aSole,aStep,WinToDos(fldUnit)); }
}

short CurveGetParams(OType CurveHandle,float *aRoof,float *aSole,float *aStep,char *fldUnit){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveGetParams)) { return -1; }
	else { return Dll_CurveGetParams(CurveHandle,aRoof,aSole,aStep,WinToDos(fldUnit)); }
}

short CurveSetMinMaxVal(OType CurveHandle,unsigned short index,OType MinVal,OType MaxVal){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveSetMinMaxVal)) { return -1; }
	else { return Dll_CurveSetMinMaxVal(CurveHandle,index,MinVal,MaxVal); }
}

short CurveGetMinMaxVal(OType CurveHandle,unsigned short index,OType *MinVal,OType *MaxVal,long B,long E){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveGetMinMaxVal)) { return -1; }
	else { return Dll_CurveGetMinMaxVal(CurveHandle,index,MinVal,MaxVal,B,E); }
}

short CurveDoMinMaxVal(OType CurveHandle,long StartN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveDoMinMaxVal)) { return -1; }
	else { return Dll_CurveDoMinMaxVal(CurveHandle,StartN,EndN); }
}

short CurveGetArr(OType CurveHandle,OType *ArrHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveGetArr)) { return -1; }
	else { return Dll_CurveGetArr(CurveHandle,ArrHandle); }
}

short CurveGetColor(OType CurveHandle,unsigned short index,unsigned char *Color){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveGetColor)) { return -1; }
	else { return Dll_CurveGetColor(CurveHandle,index,Color); }
}

short CurveSetColor(OType CurveHandle,unsigned short index,unsigned char Color){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveSetColor)) { return -1; }
	else { return Dll_CurveSetColor(CurveHandle,index,Color); }
}

short CurveSetStatus(OType CurveHandle,unsigned char Status){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveSetStatus)) { return -1; }
	else { return Dll_CurveSetStatus(CurveHandle,Status); }
}

short CurveGetStatus(OType CurveHandle,unsigned char *Status){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveGetStatus)) { return -1; }
	else { return Dll_CurveGetStatus(CurveHandle,Status); }
}

short CurveGetDataHandle(OType CurveHandle,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CurveGetDataHandle)) { return -1; }
	else { return Dll_CurveGetDataHandle(CurveHandle,ObjHandle); }
}

short ArrayFInit(const char *ArrayName,unsigned char Colums,TSByteArray Ty,long MaxLen,OType *ArrHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayFInit)) { return -1; }
	else { return Dll_ArrayFInit(WinToDos(ArrayName),Colums,Ty,MaxLen,ArrHandle); }
}

short GetArrayByName(OType *ArrHandle,const char *AName,OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetArrayByName)) { return -1; }
	else { return Dll_GetArrayByName(ArrHandle,WinToDos(AName),ObjHandle); }
}

short GetArrayByNumber(OType *ArrHandle,unsigned short Number,OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetArrayByNumber)) { return -1; }
	else { return Dll_GetArrayByNumber(ArrHandle,Number,ObjHandle); }
}

short CopyArrayByName(OType *ArrHandle,const char *AName, OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CopyArrayByName)) { return -1; }
	else { return Dll_CopyArrayByName(ArrHandle,AName,ObjHandle); }
}

short CopyArrayByIndex(OType *ArrHandle, short Index, OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CopyArrayByIndex)) { return -1; }
	else { return Dll_CopyArrayByIndex(ArrHandle,Index,ObjHandle); }
}

short ArrayGetName(OType ArrHandle,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetName)) { return -1; }
	else { result = Dll_ArrayGetName(ArrHandle,Res); CDosToWin(Res); return result; }
}

short ArrayGetDesc(OType ArrHandle,OType *TDesc){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetDesc)) { return -1; }
	else { return Dll_ArrayGetDesc(ArrHandle,TDesc); }
}

short ArrayReplaceDesc(OType ArrHandle,OType TDesc){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayReplaceDesc)) { return -1; }
	else { return Dll_ArrayReplaceDesc(ArrHandle,TDesc); }
}

short ArrayInit(long APosition,const char *AFileName,OType TDHandle,LongBoolean aEraseFlag,OType *ArrHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayInit)) { return -1; }
	else { return Dll_ArrayInit(APosition,AFileName,TDHandle,aEraseFlag,ArrHandle); }
}

/*
short ArrayWriteBin(OType ArrHandle,TXStream *S){
if ((hDLL_DATSERV == NULL)||(!Dll_ArrayWriteBin)) { return -1; }
else { return Dll_ArrayWriteBin(ArrHandle,S); }
}
*/

short ArrayGetState(OType ArrHandle,unsigned short *State){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetState)) { return -1; }
	else { return Dll_ArrayGetState(ArrHandle,State); }
}

short ArraySetState(OType ArrHandle,unsigned short State){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArraySetState)) { return -1; }
	else { return Dll_ArraySetState(ArrHandle,State); }
}

short ArrayTDInit(OType *ArrHandle,const char *ResFileName,const char *TablName,const char *ArrayName){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayTDInit)) { return -1; }
	else { return Dll_ArrayTDInit(ArrHandle,ResFileName,WinToDos(TablName),WinToDos(ArrayName)); }
}

short ArrayFDInit(OType *ArrHandle,OType FieldHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayFDInit)) { return -1; }
	else { return Dll_ArrayFDInit(ArrHandle,FieldHandle); }
}

short ArrayTDInitH(OType *ArrHandle,OType TDescHandle,const char *ArrayName){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayTDInitH)) { return -1; }
	else { return Dll_ArrayTDInitH(ArrHandle,TDescHandle,WinToDos(ArrayName)); }
}

short GetArrayByIndex(OType *ArrHandle,short Index,OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetArrayByIndex)) { return -1; }
	else { return Dll_GetArrayByIndex(ArrHandle,Index,ObjHandle); }
}

short ArrayCopyBlank(OType ArrHandle,OType *O){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayCopyBlank)) { return -1; }
	else { return Dll_ArrayCopyBlank(ArrHandle,O); }
}

short ArrayGetObjData(OType ArrHandle,long Index,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetObjData)) { return -1; }
	else { return Dll_ArrayGetObjData(ArrHandle,Index,ObjHandle); }
}

short ArrayGetColumnObj(OType ArrHandle,unsigned char Column,long Index,OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetColumnObj)) { return -1; }
	else { return Dll_ArrayGetColumnObj(ArrHandle,Column,Index,ObjHandle); }
}

short ArrayPutObjData(OType ArrHandle,long Index,OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayPutObjData)) { return -1; }
	else { return Dll_ArrayPutObjData(ArrHandle,Index,ObjHandle); }
}

short ArrayPutData(OType ArrHandle,long Index,unsigned short Count,void *PBuf){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayPutData)) { return -1; }
	else { return Dll_ArrayPutData(ArrHandle,Index,Count,PBuf); }
}

short ArrayGetData(OType ArrHandle,long Index,unsigned short Count,void *PBuf){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetData)) { return -1; }
	else { return Dll_ArrayGetData(ArrHandle,Index,Count,PBuf); }
}

short MoveSingleColumnData(OType ArrHandle,unsigned char Column,long B,long E,void *P){
	if ((hDLL_DATSERV == NULL)||(!Dll_MoveSingleColumnData)) { return -1; }
	else { return Dll_MoveSingleColumnData(ArrHandle,Column,B,E,P); }
}

short LoadSingleColumnData(OType ArrHandle, unsigned char Column, long B, long E, void *P){
	if ((hDLL_DATSERV == NULL)||(!Dll_LoadSingleColumnData)) { return -1; }
	else { return Dll_LoadSingleColumnData(ArrHandle,Column,B,E,P); }
}

short ArrayGetStrColumnData(OType ArrHandle,unsigned char Column,long Index,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetStrColumnData)) { return -1; }
	else { result = Dll_ArrayGetStrColumnData(ArrHandle,Column,Index,Res); CDosToWin(Res); return result;}
}

short ArrayGetFStrColumnData(OType ArrHandle,unsigned char Column,long Index,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetFStrColumnData)) { return -1; }
	else { result = Dll_ArrayGetFStrColumnData(ArrHandle,Column,Index,Res); CDosToWin(Res); return result;}
}

float ArrayGetSingleColumnData(OType ArrHandle,unsigned char Column,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetSingleColumnData)) { return -1; }
	else { return Dll_ArrayGetSingleColumnData(ArrHandle,Column,Index); }
}

short ArrayGetSingleColData(OType ArrHandle,unsigned char Column,long Index,unsigned short Count,float *Buf, long BufLastIndex){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetSingleColData)) { return -1; }
	else { return Dll_ArrayGetSingleColData(ArrHandle,Column,Index,Count,Buf, BufLastIndex); }
}

float ArrayGetSingle(unsigned char Column,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetSingle)) { return -1; }
	else { return Dll_ArrayGetSingle(Column,Index); }
}

int GetArraySingle(OType ArrHandle, long Index, const char *ColName, float *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetArraySingle)) { return -1; }
	else { return Dll_GetArraySingle(ArrHandle, Index, WinToDos(ColName), Value); }
}

long GetArrayLong(OType ArrHandle, long Index, const char *ColName){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetArrayLong)) { return -1; }
	else { return Dll_GetArrayLong(ArrHandle,Index,ColName); }
}

long GetArrayString(OType ArrHandle, long Index, const char *ColName, char *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetArrayString)) { return -1; }
	else { return Dll_GetArrayString(ArrHandle,Index,ColName,Value); }
}

long GetArrayFString(OType ArrHandle, long Index, const char *ColName, char *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetArrayFString)) { return -1; }
	else {
		long RetVal=Dll_GetArrayFString(ArrHandle,Index,WinToDos(ColName),Value);
		if (!RetVal) CDosToWin(Value);
		return RetVal;
	}
}

long PutArraySingle(OType ArrHandle, long Index, const char *ColName, float Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_PutArraySingle)) { return -1; }
	else { return Dll_PutArraySingle(ArrHandle,Index,ColName,Value); }
}

long PutArrayLong(OType ArrHandle, long Index, const char *ColName, long Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_PutArrayLong)) { return -1; }
	else { return Dll_PutArrayLong(ArrHandle,Index,ColName,Value); }
}

long PutArrayString(OType ArrHandle, long Index, const char *ColName, const char *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_PutArrayString)) { return -1; }
	else { return Dll_PutArrayString(ArrHandle,Index,ColName,Value); }
}

long  ArrayGetLongColumnData(OType ArrHandle,unsigned char Column,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetLongColumnData)) { return -1; }
	else { return Dll_ArrayGetLongColumnData(ArrHandle,Column,Index); }
}

short ArrayPutStrColumnData(OType ArrHandle,unsigned char Column,long Index,const char *S){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayPutStrColumnData)) { return -1; }
	else { return Dll_ArrayPutStrColumnData(ArrHandle,Column,Index,WinToDos(S)); }
}

short ArrayPutSingleColumnData(OType ArrHandle,unsigned char Column,long Index,float S){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayPutSingleColumnData)) { return -1; }
	else { return Dll_ArrayPutSingleColumnData(ArrHandle,Column,Index,S); }
}

short ArrayPutLongColumnData(OType ArrHandle,unsigned char Column,long Index,long L){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayPutLongColumnData)) { return -1; }
	else { return Dll_ArrayPutLongColumnData(ArrHandle,Column,Index,L); }
}

long ArrayGetLen(OType ArrHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetLen)) { return -1; }
	else { return Dll_ArrayGetLen(ArrHandle); }
}

short ArraySetLen(OType ArrHandle,long Len){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArraySetLen)) { return -1; }
	else { return Dll_ArraySetLen(ArrHandle,Len); }
}

short ArrayGetElementSize(OType ArrHandle,unsigned short *ElementSize){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetElementSize)) { return -1; }
	else { return Dll_ArrayGetElementSize(ArrHandle,ElementSize); }
}

short ArrayGetItemType(OType ArrHandle,unsigned char Column,unsigned char *ItemType,unsigned short *ItemSize){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetItemType)) { return -1; }
	else { return Dll_ArrayGetItemType(ArrHandle,Column,ItemType,ItemSize); }
}

short ArrayBlankValue(OType ArrHandle,void *BP){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayBlankValue)) { return -1; }
	else { return Dll_ArrayBlankValue(ArrHandle,BP); }
}

short ArrayValIsBlank(OType ArrHandle,unsigned char Column,long StartIndex,long EndIndex,LongBoolean *Res){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayValIsBlank)) { return -1; }
	else { return Dll_ArrayValIsBlank(ArrHandle,Column,StartIndex,EndIndex,Res); }
}

short ArrayBlankIndex(OType ArrHandle,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayBlankIndex)) { return -1; }
	else { return Dll_ArrayBlankIndex(ArrHandle,Index); }
}

LongBoolean ArrayColumnIsBlank(OType ArrHandle,unsigned char Column){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayColumnIsBlank)) { return true; }
	else { return Dll_ArrayColumnIsBlank(ArrHandle,Column); }
}

short ArrayDoBlankColumn(OType ArrHandle, unsigned char Column, long Start, long Stop){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayDoBlankColumn)) { return -1; }
	else { return Dll_ArrayDoBlankColumn(ArrHandle,Column,Start,Stop); }
}

LongBoolean ArrayColumnIndexIsBlank(OType ArrHandle,unsigned char Column,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayColumnIndexIsBlank)) { return true; }
	else { return Dll_ArrayColumnIndexIsBlank(ArrHandle,Column,Index); }
}

short ArrayGetColumns(OType ArrHandle,unsigned char *Colums){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetColumns)) { return -1; }
	else { return Dll_ArrayGetColumns(ArrHandle,Colums); }
}

short ArrayGetColNumByName(OType ArrHandle,const char *ColName,unsigned char *Column){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetColNumByName)) { return -1; }
	else { return Dll_ArrayGetColNumByName(ArrHandle,WinToDos(ColName),Column); }
}

short ArrayDeleteLine(OType ArrHandle,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayDeleteLine)) { return -1; }
	else { return Dll_ArrayDeleteLine(ArrHandle,Index); }
}

short ArrayDeleteColumnLine(OType ArrHandle,unsigned char Column,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayDeleteColumnLine)) { return -1; }
	else { return Dll_ArrayDeleteColumnLine(ArrHandle,Column,Index); }
}

short ArrayInsertLine(OType ArrHandle,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayInsertLine)) { return -1; }
	else { return Dll_ArrayInsertLine(ArrHandle,Index); }
}

short ArrayInsertLineN(OType ArrHandle,long Index,long LCount){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayInsertLineN)) { return -1; }
	else { return Dll_ArrayInsertLineN(ArrHandle,Index,LCount); }
}

short ArrayInsertColumnLine(OType ArrHandle,unsigned char Column,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayInsertColumnLine)) { return -1; }
	else { return Dll_ArrayInsertColumnLine(ArrHandle,Column,Index); }
}

short ArrayShiftColumnLine(OType ArrHandle,unsigned char Column,long Delta){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayShiftColumnLine)) { return -1; }
	else { return Dll_ArrayShiftColumnLine(ArrHandle,Column,Delta); }
}

short ArrayAtShiftColumnLine(OType ArrHandle,unsigned char Column,long BegN,long Delta){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayAtShiftColumnLine)) { return -1; }
	else { return Dll_ArrayAtShiftColumnLine(ArrHandle,Column,BegN,Delta); }
}

short ArrayDelInter(OType ArrHandle,long Start,long Stop){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayDelInter)) { return -1; }
	else { return Dll_ArrayDelInter(ArrHandle,Start,Stop); }
}

short ArrayCopyColumn(OType FromArrHandle,OType ToArrHandle,unsigned char FromColumn,unsigned char ToColumn,unsigned char Option){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayCopyColumn)) { return -1; }
	else { return Dll_ArrayCopyColumn(FromArrHandle,ToArrHandle,FromColumn,ToColumn,Option); }
}

short GetNearstRigthNumber(OType ArrHandle,unsigned char Column,float Value,long *Number){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetNearstRigthNumber)) { return -1; }
	else { return Dll_GetNearstRigthNumber(ArrHandle,Column,Value,Number); }
}

short GetNumberByValue(OType ArrHandle,unsigned char Column,float Value,long *Number){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetNumberByValue)) { return -1; }
	else { return Dll_GetNumberByValue(ArrHandle,Column,Value,Number); }
}

long GetFirstNumberByValue(OType ArrayHandle,unsigned char Column,float Value,long *Number){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFirstNumberByValue)) { return -1; }
	else { return Dll_GetFirstNumberByValue(ArrayHandle,Column,Value,Number); }
}

short ArrayRevert(OType ArrHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayRevert)) { return -1; }
	else { return Dll_ArrayRevert(ArrHandle); }
}

short ArrayChangeNull(OType ArrHandle,float NewNull,float OldNull,unsigned char BegCol,unsigned char EndCol,unsigned char ArgCol){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayChangeNull)) { return -1; }
	else { return Dll_ArrayChangeNull(ArrHandle,NewNull,OldNull,BegCol,EndCol,ArgCol); }
}

short ArrayDoMinMax(OType ArrHandle,long StartN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayDoMinMax)) { return -1; }
	else { return Dll_ArrayDoMinMax(ArrHandle,StartN,EndN); }
}

short ArrayGetMinMax(OType ArrHandle,unsigned short Column,OType *MinVal,OType *MaxVal){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetMinMax)) { return -1; }
	else { return Dll_ArrayGetMinMax(ArrHandle,Column,MinVal,MaxVal); }
}

short ArrayGetMinMaxH(OType ArrHandle,unsigned short Column,long BegN,long EndN,float *MinVal,float *MaxVal,float *MidVal,long *MinN,long *MaxN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetMinMaxH)) { return -1; }
	else { return Dll_ArrayGetMinMaxH(ArrHandle,Column,BegN,EndN,MinVal,MaxVal,MidVal,MinN,MaxN); }
}

short ArraySort(OType ArrHandle,unsigned char Column,long StartN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArraySort)) { return -1; }
	else { return Dll_ArraySort(ArrHandle,Column,StartN,EndN); }
}


float GetPal2Value(OType ArrHandle,float ArgValue,unsigned char FuncColumn,unsigned short DMask,unsigned short PMode,unsigned short Amode,unsigned short FMode){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetPal2Value)) { return -1; }
	else { return Dll_GetPal2Value(ArrHandle,ArgValue,FuncColumn,DMask,PMode,Amode,FMode); }
}

float GetPal3Value(OType ArrHandle,float ArgValue,float QValue,unsigned short QMode,unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetPal3Value)) { return -1; }
	else { return Dll_GetPal3Value(ArrHandle,ArgValue,QValue,QMode,DMask,PMode,AMode,FMode); }
}

short DoPal2Value(OType ArrHandle,OType PalArrHandle,unsigned char Column,unsigned char PalFuncCol,long BegN,long EndN,unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode){
	if ((hDLL_DATSERV == NULL)||(!Dll_DoPal2Value)) { return -1; }
	else { return Dll_DoPal2Value(ArrHandle,PalArrHandle,Column,PalFuncCol,BegN,EndN,DMask,PMode,AMode,FMode); }
}

short DoPal3Value(OType ArrHandle,OType PalArrHandle,unsigned char Column,long BegN,long EndN,float QValue,unsigned short QMode,unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode){
	if ((hDLL_DATSERV == NULL)||(!Dll_DoPal3Value)) { return -1; }
	else { return Dll_DoPal3Value(ArrHandle,PalArrHandle,Column,BegN,EndN,QValue,QMode,DMask,PMode,AMode,FMode); }
}

float GetPalParam(OType ArrHandle,unsigned char Col){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetPalParam)) { return -1; }
	else { return Dll_GetPalParam(ArrHandle,Col); }
}

unsigned char GetPalColumn(OType ArrHandle,float Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetPalColumn)) { return 0; }
	else { return Dll_GetPalColumn(ArrHandle,Value); }
}

short ASqr(OType FromArr,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ASqr)) { return -1; }
	else { return Dll_ASqr(FromArr,FirstCol,LastCol,BegN,EndN); }
}

short ASqrt(OType FromArr,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ASqrt)) { return -1; }
	else { return Dll_ASqrt(FromArr,FirstCol,LastCol,BegN,EndN); }
}

short ArrayRevLin(OType ArrHandle,OType FromArrHandle,float A,float B,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayRevLin)) { return -1; }
	else { return Dll_ArrayRevLin(ArrHandle,FromArrHandle,A,B,FirstCol,LastCol,BegN,EndN); }
}

short ArrayExponent(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayExponent)) { return -1; }
	else { return Dll_ArrayExponent(ArrHandle,FromArrHandle,FirstCol,LastCol,BegN,EndN); }
}

short ArrayExp10(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayExp10)) { return -1; }
	else { return Dll_ArrayExp10(ArrHandle,FromArrHandle,FirstCol,LastCol,BegN,EndN); }
}

short ArrayPower(OType ArrHandle,OType FromArrHandle,float Delta,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayPower)) { return -1; }
	else { return Dll_ArrayPower(ArrHandle,FromArrHandle,Delta,FirstCol,LastCol,BegN,EndN); }
}

short ArrayLogarifm(OType ArrHandle,OType FromArrHandle,float Modul,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayLogarifm)) { return -1; }
	else { return Dll_ArrayLogarifm(ArrHandle,FromArrHandle,Modul,FirstCol,LastCol,BegN,EndN); }
}

short ArrayGradient(OType ArrHandle,OType FromArrHandle,unsigned short FN,float Delta,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGradient)) { return -1; }
	else { return Dll_ArrayGradient(ArrHandle,FromArrHandle,FN,Delta,FirstCol,LastCol,ArgCol,BegN,EndN); }
}

short ArrayFiltr(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayFiltr)) { return -1; }
	else { return Dll_ArrayFiltr(ArrHandle,FromArrHandle,FN,FirstCol,LastCol,BegN,EndN); }
}

short ArrayKendal0(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayKendal0)) { return -1; }
	else { return Dll_ArrayKendal0(ArrHandle,FromArrHandle,FN,FirstCol,LastCol,BegN,EndN); }
}

short ArrayKendal1(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayKendal1)) { return -1; }
	else { return Dll_ArrayKendal1(ArrHandle,FromArrHandle,FN,FirstCol,LastCol,BegN,EndN); }
}

short ArrayKendal2(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayKendal2)) { return -1; }
	else { return Dll_ArrayKendal2(ArrHandle,FromArrHandle,FN,FirstCol,LastCol,BegN,EndN); }
}

short ArraySkin(OType ArrHandle,OType FromArrHandle,unsigned short Kind,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArraySkin)) { return -1; }
	else { return Dll_ArraySkin(ArrHandle,FromArrHandle,Kind,FN,FirstCol,LastCol,BegN,EndN); }
}

short ArraySmooth(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArraySmooth)) { return -1; }
	else { return Dll_ArraySmooth(ArrHandle,FromArrHandle,FN,FirstCol,LastCol,ArgCol,BegN,EndN); }
}

short ArrayMeanSmooth(OType ArrHandle, OType FromArrHandle, unsigned short FN,
  unsigned char FirstCol, unsigned char LastCol,
  long BegN, long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayMeanSmooth)) { return -1; }
	else { return Dll_ArrayMeanSmooth(ArrHandle,FromArrHandle,FN,FirstCol,LastCol,BegN,EndN); }
}

short ArrayRubber(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN,long NewN,unsigned short Option){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayRubber)) { return -1; }
	else { return Dll_ArrayRubber(ArrHandle,FromArrHandle,FirstCol,LastCol,ArgCol,BegN,EndN,NewN,Option); }
}

short ArrayLinModif(OType ArrHandle,OType FromArrHandle,float A,float B,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayLinModif)) { return -1; }
	else { return Dll_ArrayLinModif(ArrHandle,FromArrHandle,A,B,FirstCol,LastCol,BegN,EndN); }
}

short ArrayScaling(OType ArrHandle,OType FromArrHandle,OType TarArrHandle,unsigned char XTarCol,unsigned char YTarCol,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayScaling)) { return -1; }
	else { return Dll_ArrayScaling(ArrHandle,FromArrHandle,TarArrHandle,XTarCol,YTarCol,FirstCol,LastCol,BegN,EndN); }
}

short ArrGetPolinom(OType ArrHandle,OType From,float Step,unsigned char n,unsigned char ArgColumn,unsigned char Column,long startN,long endN,float *aMdlSqDiv,float *aMaxAbsDiv,float *aMaxRelDiv,ArrS10 *bb){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrGetPolinom)) { return -1; }
	else { return Dll_ArrGetPolinom(ArrHandle,From,Step,n,ArgColumn,Column,startN,endN,aMdlSqDiv,aMaxAbsDiv,aMaxRelDiv,bb); }
}

short ArrayMean(OType ArrHandle,unsigned char BegCol,unsigned char EndCol,unsigned char ArgCol,long BegN,long EndN,float *MeanVal,float *Disp){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayMean)) { return -1; }
	else { return Dll_ArrayMean(ArrHandle,BegCol,EndCol,ArgCol,BegN,EndN,MeanVal,Disp); }
}

long ArrayGetInterIndex(OType ArrHandle,unsigned char Column,float Roof,float Sole,long *RoofIndex,long *SoleIndex){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayGetInterIndex)) { return -1; }
	else { return Dll_ArrayGetInterIndex(ArrHandle,Column,Roof,Sole,RoofIndex,SoleIndex); }
}

short ArrayExtract(OType ArrHandle,unsigned char Column1,unsigned char Column2,unsigned short Option,OType *NewArr){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayExtract)) { return -1; }
	else { return Dll_ArrayExtract(ArrHandle,Column1,Column2,Option,NewArr); }
}

short ArrayAddColumn(OType ArrHandle, OType FDesc, unsigned short AtIndex, unsigned short Option, OType *NewArr){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayAddColumn)) { return -1; }
	else { return Dll_ArrayAddColumn(ArrHandle,FDesc,AtIndex,Option,NewArr); }
}

short ArrayDelColumn(OType ArrHandle, unsigned short Column, unsigned short Option, OType *NewArr){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayDelColumn)) { return -1; }
	else { return Dll_ArrayDelColumn(ArrHandle,Column,Option,NewArr); }
}

short ArrayTakeData(OType MainArrHandle, OType FromArrHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayTakeData)) { return -1; }
	else { return Dll_ArrayTakeData(MainArrHandle, FromArrHandle); }
}

short ArrayTakeDataEx(OType MainArrHandle, OType FromArrHandle, unsigned short Option){
	if ((hDLL_DATSERV == NULL)||(!Dll_ArrayTakeDataEx)) { return -1; }
	else { return Dll_ArrayTakeDataEx(MainArrHandle, FromArrHandle, Option); }
}

long GetBlobByIndex(OType *BlobHandle, long Index, OType DataHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetBlobByIndex)) { return -1; }
	else { return Dll_GetBlobByIndex(BlobHandle, Index, DataHandle); }
}

long GetBlobSize(OType BlobHandle, long *Size){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetBlobSize)) { return -1; }
	else { return Dll_GetBlobSize(BlobHandle, Size); }
}

long SetBlobLen(OType BlobHandle, long Len){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetBlobLen)) { return -1; }
	else { return Dll_SetBlobLen(BlobHandle, Len); }
}

long BlobReadBuf(OType BlobHandle, long Position, long Size, void *Buf){
	if ((hDLL_DATSERV == NULL)||(!Dll_BlobReadBuf)) { return -1; }
	else { return Dll_BlobReadBuf(BlobHandle, Position, Size, Buf); }
}

long BlobWriteBuf(OType BlobHandle, long Position, long Size, void *Buf){
	if ((hDLL_DATSERV == NULL)||(!Dll_BlobWriteBuf)) { return -1; }
	else { return Dll_BlobWriteBuf(BlobHandle, Position, Size, Buf); }
}


short GetFieldVal(const char *AName,OType ObjHandle,OType *ObValHandle,unsigned char *T){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetFieldVal)) { return -1; }
	else { return Dll_GetFieldVal(WinToDos(AName),ObjHandle,ObValHandle,T); }
}

short ObjGetFieldSingle(const char *AName,OType ObjHandle,const char *aUnit,float *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjGetFieldSingle)) { return -1; }
	else { return Dll_ObjGetFieldSingle(WinToDos(AName),ObjHandle,WinToDos(aUnit),Value); }
}

short ObjGetFieldSingleEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,float *Value){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjGetFieldSingleEx)) { return -1; }
	else { result = Dll_ObjGetFieldSingleEx(WinToDos(AName),ObjHandle,WinToDos(aUnit),Unit1,Value); CDosToWin(Unit1); return result;}
}

short ObjGetFieldLong(const char *AName,OType ObjHandle,const char *aUnit,long *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjGetFieldLong)) { return -1; }
	else { return Dll_ObjGetFieldLong(WinToDos(AName),ObjHandle, WinToDos(aUnit),Value); }
}

short ObjGetFieldLongEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,long *Value){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjGetFieldLongEx)) { return -1; }
	else { result=Dll_ObjGetFieldLongEx(WinToDos(AName),ObjHandle,WinToDos(aUnit),Unit1,Value);  CDosToWin(Unit1); return result;}
}

short ObjPutFieldSingle(const char *AName,OType ObjHandle,const char *aUnit,float Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjPutFieldSingle)) { return -1; }
	else { return Dll_ObjPutFieldSingle(WinToDos(AName),ObjHandle,WinToDos(aUnit),Value); }
}

short ObjPutFieldSingleEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,float Value){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjPutFieldSingleEx)) { return -1; }
	else { result = Dll_ObjPutFieldSingleEx(WinToDos(AName),ObjHandle,WinToDos(aUnit),Unit1,Value); CDosToWin(Unit1); return result;}
}

short ObjPutFieldLong(const char *AName,OType ObjHandle,const char *aUnit,long Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjPutFieldLong)) { return -1; }
	else { return Dll_ObjPutFieldLong(WinToDos(AName),ObjHandle,WinToDos(aUnit),Value); }
}

short ObjPutFieldLongEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1, long Value){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObjPutFieldLongEx)) { return -1; }
	else { result = Dll_ObjPutFieldLongEx(WinToDos(AName),ObjHandle,WinToDos(aUnit),Unit1,Value); CDosToWin(Unit1); return result; }
}

short CopyFieldVal(const char *AName, OType ObjHandle, OType *ObValHandle, unsigned char *T){
	if ((hDLL_DATSERV == NULL)||(!Dll_CopyFieldVal)) { return -1; }
	else { return Dll_CopyFieldVal(WinToDos(AName),ObjHandle,ObValHandle,T); }
}

short CopyObVal(OType ObValHandle, OType *NewObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CopyObVal)) { return -1; }
	else { return Dll_CopyObVal(ObValHandle,NewObValHandle); }
}

short GetObValByIndex( short Index,OType ObjHandle,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetObValByIndex)) { return -1; }
	else { return Dll_GetObValByIndex(Index,ObjHandle,ObValHandle); }
}

short CopyObValByIndex( short Index,OType ObjHandle,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_CopyObValByIndex)) { return -1; }
	else { return Dll_CopyObValByIndex(Index,ObjHandle,ObValHandle); }
}

short ReplaceObValByIndex( short Index,OType ObjHandle,OType ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ReplaceObValByIndex)) { return -1; }
	else { return Dll_ReplaceObValByIndex(Index,ObjHandle,ObValHandle); }
}

short ObValFDInit(OType FDescHandle,const char *Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValFDInit)) { return -1; }
	else { return Dll_ObValFDInit(FDescHandle,WinToDos(Value),ObValHandle); }
}

short MakeObValS(unsigned char aType,const char *Value,unsigned short aLen,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_MakeObValS)) { return -1; }
	else { return Dll_MakeObValS(aType,WinToDos(Value),aLen,ObValHandle); }
}

short ObValSingleInit( float Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValSingleInit)) { return -1; }
	else { return Dll_ObValSingleInit(Value,ObValHandle); }
}

short ObValBoolInit(unsigned char Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValBoolInit)) { return -1; }
	else { return Dll_ObValBoolInit(Value,ObValHandle); }
}

short ObValDoubleInit(double Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValDoubleInit)) { return -1; }
	else { return Dll_ObValDoubleInit(Value,ObValHandle); }
}

short ObValIntInit(short Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValIntInit)) { return -1; }
	else { return Dll_ObValIntInit(Value,ObValHandle); }
}

short ObValWordInit(unsigned short Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValWordInit)) { return -1; }
	else { return Dll_ObValWordInit(Value,ObValHandle); }
}

short ObValByteInit(unsigned char Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValByteInit)) { return -1; }
	else { return Dll_ObValByteInit(Value,ObValHandle); }
}

short ObValStrInit(const char *Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValStrInit)) { return -1; }
	else { return Dll_ObValStrInit(WinToDos(Value),ObValHandle); }
}

short ObValStringInit(const char *Value,unsigned short Len,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValStringInit)) { return -1; }
	else { return Dll_ObValStringInit(WinToDos(Value),Len,ObValHandle); }
}

short ObValLongIntInit(long Value,OType *ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValLongIntInit)) { return -1; }
	else { return Dll_ObValLongIntInit(Value,ObValHandle); }
}

short ObValIsBlank(OType ObValHandle,LongBoolean *IsBlank){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValIsBlank)) { return -1; }
	else { return Dll_ObValIsBlank(ObValHandle,IsBlank); }
}

short ObValMoveVal(OType ObValHandle,void *Buf){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValMoveVal)) { return -1; }
	else { return Dll_ObValMoveVal(ObValHandle,Buf); }
}

short ObValPutVal(OType ObValHandle,void *Buf){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValPutVal)) { return -1; }
	else { return Dll_ObValPutVal(ObValHandle,Buf); }
}

short ObValGetStr(OType ObValHandle,char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetStr)) { return -1; }
	else { result = Dll_ObValGetStr(ObValHandle,Res); CDosToWin(Res); return result; }
}

short ObValGetFStr(OType ObValHandle,unsigned short L,unsigned short D, char *Res){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetFStr)) { return -1; }
	else { result = Dll_ObValGetFStr(ObValHandle,L,D,Res); CDosToWin(Res); return result; }
}

short ObValGetFPChar(OType ObValHandle, unsigned short L, unsigned short D, char *FStr, long SizeIncludingEOL){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetFPChar)) { return -1; }
	else { result = Dll_ObValGetFPChar(ObValHandle,L,D,FStr,SizeIncludingEOL); CDosToWin(FStr); return result; }
}

float ObValGetSingle(OType ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetSingle)) { return -1; }
	else { return Dll_ObValGetSingle(ObValHandle); }
}

long ObValGetLongInt(OType ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetLongInt)) { return -1; }
	else { return Dll_ObValGetLongInt(ObValHandle); }
}

short ObValGetSize(OType ObValHandle,unsigned short *Size){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetSize)) { return -1; }
	else { return Dll_ObValGetSize(ObValHandle,Size); }
}

short ObValGetLongSize(OType ObValHandle, long *Size){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetLongSize)) { return -1; }
	else { return Dll_ObValGetLongSize(ObValHandle,Size); }
}

short ObValGetPointer(OType ObValHandle,void *P){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetPointer)) { return -1; }
	else { return Dll_ObValGetPointer(ObValHandle,P); }
}

short ObValPutStr(const char *S,OType ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValPutStr)) { return -1; }
	else { return Dll_ObValPutStr(WinToDos(S),ObValHandle); }
}

short ObValPutSingle( float S,OType ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValPutSingle)) { return -1; }
	else { return Dll_ObValPutSingle(S,ObValHandle); }
}

short ObValPutLongInt(long Li,OType ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValPutLongInt)) { return -1; }
	else { return Dll_ObValPutLongInt(Li,ObValHandle); }
}

LongBoolean ObValCompare(OType ObValHandle,const char *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValCompare)) { return false; }
	else { return Dll_ObValCompare(ObValHandle,WinToDos(Value)); }
}

short ObValGetType(OType ObValHandle,unsigned char *aType){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGetType)) { return -1; }
	else { return Dll_ObValGetType(ObValHandle,aType); }
}

unsigned char ObValEqual(OType V1,OType V2){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValEqual)) { return 0; }
	else { return Dll_ObValEqual(V1,V2); }
}

unsigned char ObValLess(OType V1,OType V2){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValLess)) { return 0; }
	else { return Dll_ObValLess(V1,V2); }
}

unsigned char ObValELess(OType V1,OType V2){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValELess)) { return 0; }
	else { return Dll_ObValELess(V1,V2); }
}

unsigned char ObValGreater(OType V1,OType V2){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValGreater)) { return 0; }
	else { return Dll_ObValGreater(V1,V2); }
}

unsigned char ObValEGreater(OType V1,OType V2){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValEGreater)) { return 0; }
	else { return Dll_ObValEGreater(V1,V2); }
}

/*
short ObValLoad( TXStream *S,OType *ObValHandle){
if ((hDLL_DATSERV == NULL)||(!Dll_ObValLoad)) { return -1; }
else { return Dll_ObValLoad(S,ObValHandle); }
}

  short ObValStore( TXStream *S,OType ObValHandle){
  if ((hDLL_DATSERV == NULL)||(!Dll_ObValStore)) { return -1; }
  else { return Dll_ObValStore(S,ObValHandle); }
  }

	short ObValReadStr( Text *S,OType ObValHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValReadStr)) { return -1; }
	else { return Dll_ObValReadStr(S,ObValHandle); }
	}

	  short ObValWriteStr( Text *S,OType ObValHandle){
	  if ((hDLL_DATSERV == NULL)||(!Dll_ObValWriteStr)) { return -1; }
	  else { return Dll_ObValWriteStr(S,ObValHandle); }
	  }
*/

short ObValIncDec (OType V1,OType V2,unsigned char OP){
	if ((hDLL_DATSERV == NULL)||(!Dll_ObValIncDec)) { return -1; }
	else { return Dll_ObValIncDec (V1,V2,OP); }
}

short PassObVal(OType V1,OType V2){
	if ((hDLL_DATSERV == NULL)||(!Dll_PassObVal)) { return -1; }
	else { return Dll_PassObVal(V1,V2); }
}

short Load_WS(const char *ResFName,const char *LoadFName,
  const char *Selected_Aim,const char *TName,unsigned short *RowNumber,
  OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Load_WS)) { return -1; }
	else { return Dll_Load_WS(ResFName,LoadFName,WinToDos(Selected_Aim),WinToDos(TName),RowNumber,ObjHandle); }
}

short Load_WSEx(const char *ResFName,const char *LoadFName,
  const char *Selected_Aim,const char *TName,unsigned short *RowNumber,
  OType *ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Load_WSEx)) { return -1; }
	else { return Dll_Load_WSEx(ResFName,LoadFName,WinToDos(Selected_Aim),WinToDos(TName),RowNumber,ObjHandle); }
}

short Save_WS(const char *Selected_Aim,const char *TName,const char *SaveFName,LongBoolean CheckCopy,OType ObjHandle){
	if ((hDLL_DATSERV == NULL)||(!Dll_Save_WS)) { return -1; }
	else { return Dll_Save_WS(WinToDos(Selected_Aim),WinToDos(TName),SaveFName,CheckCopy,ObjHandle); }
}

short Save_WSEx(const char *Selected_Aim,const char *TName,const char *SaveFName,
                LongBoolean CheckCopy, LongBoolean CheckIntent,
                OType ObjHandle, OType *NewObjHandle)
{
	if ((hDLL_DATSERV == NULL)||(!Dll_Save_WSEx)) { return -1; }
	else { return Dll_Save_WSEx(WinToDos(Selected_Aim),WinToDos(TName),SaveFName,CheckCopy,CheckIntent,ObjHandle,NewObjHandle); }
};

short Save_WSExRW(const char *Selected_Aim, const char *TName, const char *SaveLogFileName,
	LongBoolean CheckThisCopy, OType ObjHandle)
{
	if ((hDLL_DATSERV == NULL)||(!Dll_Save_WSExRW)) { return -1; }
	else return Dll_Save_WSExRW(Selected_Aim, TName, SaveLogFileName, CheckThisCopy, ObjHandle);
}

void SetBlank(unsigned char vType,const char *Value){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetBlank)) { return; }
	else {
          DisableRetreiveBlanks = 1;
          Dll_SetBlank(vType,WinToDos(Value));
          DisableRetreiveBlanks = 0;
          return;
        }
}

float GetBlankSingle(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetBlankSingle)) { return -1; }
	else { return Dll_GetBlankSingle(); }
}


short MakeWhereData(OType *WhereDataH,const char *fldName,const char *fldValue){
	if ((hDLL_DATSERV == NULL)||(!Dll_MakeWhereData)) { return -1; }
	else { return Dll_MakeWhereData(WhereDataH,WinToDos(fldName),WinToDos(fldValue)); }
}

short AddWhereData(OType WhereDataH,const char *fldName,const char *fldValue){
	if ((hDLL_DATSERV == NULL)||(!Dll_AddWhereData)) { return -1; }
	else { return Dll_AddWhereData(WhereDataH,fldName,fldValue); }
}

short SearchDataInit(OType WhereDataH,OType SelectTD,OType *SearchDataH){
	if ((hDLL_DATSERV == NULL)||(!Dll_SearchDataInit)) { return -1; }
	else { return Dll_SearchDataInit(WhereDataH,SelectTD,SearchDataH); }
}

short SSearchDataInit(const char *Name1,const char *Val1,const char *Name2,const char *Val2,const char *Name3,const char *Val3,OType TableHandle,OType *SearchDataH){
	if ((hDLL_DATSERV == NULL)||(!Dll_SSearchDataInit)) { return -1; }
	else { return Dll_SSearchDataInit(WinToDos(Name1),WinToDos(Val1),WinToDos(Name2),WinToDos(Val2),WinToDos(Name3),WinToDos(Val3),TableHandle,SearchDataH); }
}

short PrepareCond(OType SearchDataH,OType TDescH){
	if ((hDLL_DATSERV == NULL)||(!Dll_PrepareCond)) { return -1; }
	else { return Dll_PrepareCond(SearchDataH,TDescH); }
}

short GetSOData(OType SOHandle,CSODataType *SOData){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSOData)) { return -1; }
	else {
		result = Dll_GetSOData(SOHandle,SOData);
		CDosToWin(SOData->TablName);
		CDosToWin(SOData->BaseName);
		return result;
	}
}

short SetSOData(OType SOHandle,CSODataType SOData){
	short result;
	if ((hDLL_DATSERV == NULL)||(!Dll_SetSOData)) { return -1; }
	else {
		result = Dll_SetSOData(SOHandle,SOData);
		WinToDos(SOData.TablName);
		WinToDos(SOData.BaseName);
		return result;
	}
}

short SetSOpers(OType SOHandle,short Index,const char *SOPer){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetSOpers)) { return -1; }
	else { return Dll_SetSOpers(SOHandle,Index,WinToDos(SOPer)); }
}


short AddSOper(OType SOHandle,const char *Oper){
	if ((hDLL_DATSERV == NULL)||(!Dll_AddSOper)) { return -1; }
	else { return Dll_AddSOper(SOHandle,WinToDos(Oper)); }
}

short SetSTable(OType SOHandle,const char *TablName){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetSTable)) { return -1; }
	else { return Dll_SetSTable(SOHandle,WinToDos(TablName)); }
}

short CompCond(OType SearchDataH,OType DataObjH,LongBoolean *Result){
	if ((hDLL_DATSERV == NULL)||(!Dll_CompCond)) { return -1; }
	else { return Dll_CompCond(SearchDataH,DataObjH,Result); }
}

short LoadSO(OType *SearchDataH,const char *FName){
	if ((hDLL_DATSERV == NULL)||(!Dll_LoadSO)) { return -1; }
	else { return Dll_LoadSO(SearchDataH,FName); }
}

short StoreSO(OType SearchDataH,const char *FName){
	if ((hDLL_DATSERV == NULL)||(!Dll_StoreSO)) { return -1; }
	else { return Dll_StoreSO(SearchDataH,FName); }
}

void  DatServCounters(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_DatServCounters)) { return; }
	else { Dll_DatServCounters(); return; }
}

void DoTxtMaket(OType RedObjHandle,OType RezObjHandle,const char *MetName,const char *FName){
	if ((hDLL_DATSERV == NULL)||(!Dll_DoTxtMaket)) { return; }
	else { Dll_DoTxtMaket(RedObjHandle,RezObjHandle,MetName,FName); return; }
}

void * DSGetTableCollection(OType LFHandle){
if ((hDLL_DATSERV == NULL)||(!Dll_DSGetTableCollection)) { return NULL; }
else { return Dll_DSGetTableCollection(LFHandle); }
}

short GetSysDataCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysDataCount)) { return -1; }
	else { return Dll_GetSysDataCount(); }
}

short GetSysLogFileCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysLogFileCount)) { return -1; }
	else { return Dll_GetSysLogFileCount(); }
}

short GetSysLRCursorCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysLRCursorCount)) { return -1; }
	else { return Dll_GetSysLRCursorCount(); }
}

short GetSysLogRecCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysLogRecCount)) { return -1; }
	else { return Dll_GetSysLogRecCount(); }
}

short GetSysDataObjCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysDataObjCount)) { return -1; }
	else { return Dll_GetSysDataObjCount(); }
}

short GetSysArrayCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysArrayCount)) { return -1; }
	else { return Dll_GetSysArrayCount(); }
}

short GetSysObValCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysObValCount)) { return -1; }
	else { return Dll_GetSysObValCount(); }
}

short GetSysTDescCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysTDescCount)) { return -1; }
	else { return Dll_GetSysTDescCount(); }
}

short GetSysFDescCount(void){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetSysFDescCount)) { return -1; }
	else { return Dll_GetSysFDescCount(); }
}

short CheckResVersion(const char *ResFileName, const char *TableName, const char *CurrentResVersion){
	if ((hDLL_DATSERV == NULL)||(!Dll_CheckResVersion)) { return -1; }
	else { return Dll_CheckResVersion(ResFileName, WinToDos(TableName), CurrentResVersion); }
}


long GetLenLimit(OType O){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetLenLimit)) { return -1; }
	else { return Dll_GetLenLimit(O); }
}

long MemoGetLineCount(OType hMemo){
	if ((hDLL_DATSERV == NULL)||(!Dll_MemoGetLineCount)) { return -1; }
	else { return Dll_MemoGetLineCount(hMemo); }
}

long MemoGetLine(OType hMemo, long Index, char *Str, long StrMaxLen){
	if ((hDLL_DATSERV == NULL)||(!Dll_MemoGetLine)) { return -1; }
	else { return Dll_MemoGetLine(hMemo,Index,Str,StrMaxLen); }
}

long MemoSetLine(OType hMemo, long Index, const char *Str){
	if ((hDLL_DATSERV == NULL)||(!Dll_MemoSetLine)) { return -1; }
	else { return Dll_MemoSetLine(hMemo,Index,Str); }
}

long MemoInsertLine(OType hMemo, long Index, const char *Str){
	if ((hDLL_DATSERV == NULL)||(!Dll_MemoInsertLine)) { return -1; }
	else { return Dll_MemoInsertLine(hMemo,Index,Str); }
}

long MemoDeleteLine(OType hMemo, long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_MemoDeleteLine)) { return -1; }
	else { return Dll_MemoDeleteLine(hMemo,Index); }
}

long MemoAddLine(OType hMemo, const char *Str){
	if ((hDLL_DATSERV == NULL)||(!Dll_MemoAddLine)) { return -1; }
	else { return Dll_MemoAddLine(hMemo,Str); }
}

void SetChangeBlankNotifyProc(void *Proc){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetChangeBlankNotifyProc)) { }
	else { Dll_SetChangeBlankNotifyProc(Proc); }
}

void GetDatservBlanks(
  unsigned char *_BlankByte,
  short *_BlankInt,
  unsigned short *_BlankWord,
  long *_BlankLongInt,
  float *_BlankSingle,
  double *_BlankDouble,
  TimeRecType *_BlankTime,
  DateRecType *_BlankDate,
  char *_BlankStr){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetDatservBlanks)) { }
	else { Dll_GetDatservBlanks(
                 _BlankByte,
                 _BlankInt,
                 _BlankWord,
                 _BlankLongInt,
                 _BlankSingle,
                 _BlankDouble,
                 _BlankTime,
                 _BlankDate,
                 _BlankStr); }
}

void SetDatservBlanks(
  unsigned char _BlankByte,
  short _BlankInt,
  unsigned short _BlankWord,
  long _BlankLongInt,
  float _BlankSingle,
  double _BlankDouble,
  TimeRecType _BlankTime,
  DateRecType _BlankDate,
  const char *_BlankStr){
	if ((hDLL_DATSERV == NULL)||(!Dll_SetDatservBlanks)) { }
	else { Dll_SetDatservBlanks(
                 _BlankByte,
                 _BlankInt,
                 _BlankWord,
                 _BlankLongInt,
                 _BlankSingle,
                 _BlankDouble,
                 _BlankTime,
                 _BlankDate,
                 _BlankStr); }
}

LongBoolean GetDateByFormat(const char *Value, const char *Format, DateRecType *DSDateRec){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetDateByFormat)) { return false; }
	else { return Dll_GetDateByFormat(Value,Format,DSDateRec); }
}

LongBoolean GetTimeByFormat(const char *Value, const char *Format, TimeRecType *DSTimeRec){
	if ((hDLL_DATSERV == NULL)||(!Dll_GetTimeByFormat)) { return false; }
	else { return Dll_GetTimeByFormat(Value,Format,DSTimeRec); }
}

void DSDoneObject(void *P) {
	if ((hDLL_DATSERV == NULL)||(!Dll_DSDoneObject)) return;
	Dll_DSDoneObject(P);
}

PPasString DSNewPString(const char *S){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSNewPString)) { return NULL; }
	else { return Dll_DSNewPString(S); }
}

void*  DSInitList(long Limit,long Delta){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSInitList)) { return NULL; }
	else { return Dll_DSInitList(Limit,Delta); }
}

void*  DSInitStringList(long Limit,long Delta){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSInitStringList)) { return NULL; }
	else { return Dll_DSInitStringList(Limit,Delta); }
}

void*  DSInitEmptyList(long Limit,long Delta){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSInitEmptyList)) { return NULL; }
	else { return Dll_DSInitEmptyList(Limit,Delta); }
}

void*  DSInitUnsortList(long Limit,long Delta){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSInitUnsortList)) { return NULL; }
	else { return Dll_DSInitUnsortList(Limit,Delta); }
}

long  DSListCount(void *List){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListCount)) { return -1; }
	else { return Dll_DSListCount(List); }
}

void* DSListAt(void *List,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListAt)) { return NULL; }
	else { return Dll_DSListAt(List,Index); }
}

void DSListAtDelete(void *List,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListAtDelete)) {  }
	else { Dll_DSListAtDelete(List,Index); }
}

void DSListAtFree(void *List,long Index){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListAtFree)) {  }
	else { Dll_DSListAtFree(List,Index); }
}

void DSListAtInsert(void *List,long Index,void* Item){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListAtInsert)) {  }
	else { Dll_DSListAtInsert(List,Index,Item); }
}

void DSListAtPut(void *List,long Index,void *Item){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListAtPut)) {  }
	else { Dll_DSListAtPut(List,Index,Item); }
}

void DSListDelete(void *List,void *Item){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListDelete)) {  }
	else { Dll_DSListDelete(List,Item); }
}

void DSListDeleteAll(void *List){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListDeleteAll)) {  }
	else { Dll_DSListDeleteAll(List); }
}

void DSListFree(void *List,void *Item){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListFree)) {  }
	else { Dll_DSListFree(List,Item); }
}

void DSListFreeAll(void *List){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListFreeAll)) {  }
	else { Dll_DSListFreeAll(List); }
}

long DSListIndexOf(void *List,void *Item){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListIndexOf)) { return -1; }
	else { return Dll_DSListIndexOf(List,Item); }
}

void DSListInsert(void *List,void *Item){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListInsert)) {  }
	else { Dll_DSListInsert(List,Item); }
}

void DSListPack(void *List){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListPack)) {  }
	else { Dll_DSListPack(List); }
}

long DSListSearch(void *List,const char *Key){
	if ((hDLL_DATSERV == NULL)||(!Dll_DSListSearch)) { return -1; }
	else { return Dll_DSListSearch(List,Key); }
}

long CreateDSStream(int Option, TDSStream &Stream) {
	if ((hDLL_DATSERV == NULL)||(!Dll_CreateDSStream)) { return -1; }
	else return Dll_CreateDSStream(Option, Stream);
}

long StoreBufTD(void** Buf, long Option, OType TDHandle) {
	if ((hDLL_DATSERV == NULL)||(!Dll_StoreBufTD)) { return -1; }
	else return Dll_StoreBufTD(Buf, Option, TDHandle);
}

long LoadBufTD(void** Buf, int Count, long Option, OType &TDHandle) {
	if ((hDLL_DATSERV == NULL)||(!Dll_LoadBufTD)) { return -1; }
	else return Dll_LoadBufTD(Buf, Count, Option, TDHandle);
}

void SetOnSaveDataProc(TOnSaveDataProc Proc) {
	if ((hDLL_DATSERV == NULL)||(!Dll_SetOnSaveDataProc)) { return; }
	else Dll_SetOnSaveDataProc(Proc);
}

short LFGetPackState(OType LFHandle) {
	if ((hDLL_DATSERV == NULL)||(!Dll_LFGetPackState)) { return -1; }
	return Dll_LFGetPackState(LFHandle);
}

short GetWSName(OType LRHandle, const char* WSName) {
	if ((hDLL_DATSERV == NULL)||(!Dll_GetWSName)) { return -1; }
	return Dll_GetWSName(LRHandle, WSName);
}

short TableExistX(const char* TableName, OType LFHandle, int Option) {
	if ((hDLL_DATSERV == NULL)||(!Dll_TableExistX)) { return -1; }
	return Dll_TableExistX(WinToDos(TableName), LFHandle, Option);
}

int DSGetTableNames(OType LFHandle, unsigned short LROption, char **Names) {
	if ((hDLL_DATSERV == NULL)||(!Dll_DSGetTableNames)) { return -1; }
	int res = Dll_DSGetTableNames(LFHandle, LROption, Names);
	if ((res > 0) && (*Names != NULL)) CDosToWin(*Names);
	return res;
}

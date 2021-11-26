/***************************************************************************\
*                                                                           *
* Ñèñòåìà èíôîðìàöèîííîãî îáåñïå÷åíèÿ ãåîôèçè÷åñêèõ èññëåäîâàíèé ñêâàæèí    *
*   "ÏÐÀÉÌ" äëÿ Windows 95/98/NT                                            *
* Áèáëèîòåêà ðàñøèðåíèé ôóíêöèé ñåðâåðà äàííûõ                              *
* ßçûê: C++                                                                 *
* Âåðñèÿ: 1.12                                                              *
* (C) ÍÏÔ ÃåîÒÝÊ, 1999 - 2006                                               *
*                                                                           *
\***************************************************************************/

#if _MSC_VER > 1000
  #pragma once
#else
#endif // _MSC_VER > 1000
#include <windows.h>
#include "DSAPI.h"
#include "DSExt.h"

/* Èìÿ ôàéëà âíåøíåãî ìîäóëÿ */
#define DSEXTDLL "DSExt32.dll"
HINSTANCE hDLL_DSEXT = NULL;

extern char *DepthString = (char*)"ÃËÓÁÈÍÀ";
extern char *DepthUnit = (char*)"ÑÌ";
extern char *DepthShift = (char*)"ÑÓÌÌÀÐÍÛÉ_ÑÄÂÈÃ";

/*****************************************************************************\
*                                                                             *
*    ÄÅÊËÀÐÀÖÈÈ ÂÛÇÎÂÎÂ ÔÓÍÊÖÈÉ ÈÇ ÂÍÅØÍÅÃÎ ÌÎÄÓËß (DLL)                      *
*                                                                             *
\*****************************************************************************/

typedef HINSTANCE (__stdcall *PDll_GetAlgHandle)();
PDll_GetAlgHandle Dll_GetAlgHandle;
typedef long (__stdcall *PDll_GetAlgPath)(char*,long);
PDll_GetAlgPath Dll_GetAlgPath;
typedef long (__stdcall *PDll_GetSystemPath)(char*,long);
PDll_GetSystemPath Dll_GetSystemPath;
typedef void (__stdcall *PDll_SetMainWndHandle)(HWND);
PDll_SetMainWndHandle Dll_SetMainWndHandle;
typedef LongBoolean (__stdcall *PDll_GetNBALongInt)(OType,long,const char*,long*);
PDll_GetNBALongInt Dll_GetNBALongInt;
typedef LongBoolean (__stdcall *PDll_GetNBASingle)(OType,long,const char*,float*);
PDll_GetNBASingle Dll_GetNBASingle;
typedef LongBoolean (__stdcall *PDll_GetNBAString)(OType,long,const char*,char*);
PDll_GetNBAString Dll_GetNBAString;
typedef LongBoolean (__stdcall *PDll_GetNBFLongInt)(OType,const char*,long*);
PDll_GetNBFLongInt Dll_GetNBFLongInt;
typedef LongBoolean (__stdcall *PDll_GetNBFSingle)(OType,const char*,float*);
PDll_GetNBFSingle Dll_GetNBFSingle;
typedef LongBoolean (__stdcall *PDll_GetNBFString)(OType,const char*,char*);
PDll_GetNBFString Dll_GetNBFString;
typedef LongBoolean (__stdcall *PDll_GetNBFStringLong)(OType,const char*,char*,long);
PDll_GetNBFStringLong Dll_GetNBFStringLong;
typedef void (__stdcall *PDll_PutArrayLongInt)(OType,long,const char*,long);
PDll_PutArrayLongInt Dll_PutArrayLongInt;
typedef void (__stdcall *PDll_xPutArraySingle)(OType,long,const char*,float);
PDll_xPutArraySingle Dll_xPutArraySingle;
typedef void (__stdcall *PDll_xPutArrayString)(OType,long,const char*,const char*);
PDll_xPutArrayString Dll_xPutArrayString;
typedef void (__stdcall *PDll_PutFieldLongInt)(OType,const char*,long);
PDll_PutFieldLongInt Dll_PutFieldLongInt;
typedef void (__stdcall *PDll_PutFieldSingle)(OType,const char*,float);
PDll_PutFieldSingle Dll_PutFieldSingle;
typedef void (__stdcall *PDll_PutFieldString)(OType,const char*,const char*);
PDll_PutFieldString Dll_PutFieldString;
typedef void (__stdcall *PDll_PutFieldLongIntI)(OType,long,long);
PDll_PutFieldLongIntI Dll_PutFieldLongIntI;
typedef void (__stdcall *PDll_PutFieldSingleI)(OType,long,float);
PDll_PutFieldSingleI Dll_PutFieldSingleI;
typedef void (__stdcall *PDll_PutFieldStringI)(OType,long,const char*);
PDll_PutFieldStringI Dll_PutFieldStringI;
typedef long (__stdcall *PDll_GetCurveInformation)(OType,OType,unsigned char*,long*,long*,long*);
PDll_GetCurveInformation Dll_GetCurveInformation;
typedef void (__stdcall *PDll_DataKeyStrLong)(const char*,OType,unsigned short,char*);
PDll_DataKeyStrLong Dll_DataKeyStrLong;
//typedef long (__stdcall *PDll_GetValueIndex)(OType,unsigned char,float);
//PDll_GetValueIndex Dll_GetValueIndex;
//typedef long (__stdcall *PDll_GetMonValueIndex)(OType,unsigned char,float);
//PDll_GetMonValueIndex Dll_GetMonValueIndex;
//typedef long (__stdcall *PDll_GetInterIndex)(OType,unsigned char,float,float,long*,long*);
//PDll_GetInterIndex Dll_GetInterIndex;
//typedef long (__stdcall *PDll_GetArrayIndex)(OType,unsigned char,long,float*,long,long*,long);
//PDll_GetArrayIndex Dll_GetArrayIndex;
typedef long (__stdcall *PDll_GetField)(OType,OType,long*,long*,long*);
PDll_GetField Dll_GetField;
typedef long (__stdcall *PDll_SetField)(OType,OType,long,long,long);
PDll_SetField Dll_SetField;
typedef long (__stdcall *PDll_GetIndex)(OType,OType,long);
PDll_GetIndex Dll_GetIndex;
typedef long (__stdcall *PDll_ShiftDepth)(OType,OType,unsigned char,long,unsigned short);
PDll_ShiftDepth Dll_ShiftDepth;
typedef long (__stdcall *PDll_Transform)(OType,OType,unsigned char,long,long,TTransform,PProcess);
PDll_Transform Dll_Transform;
typedef long (__stdcall *PDll_ArgTransform)(OType,OType,unsigned char,long,long,TArgTransform,PProcess);
PDll_ArgTransform Dll_ArgTransform;
typedef long (__stdcall *PDll_WinTransform)(OType,OType,unsigned char,long,long,unsigned char,TWinTransform,float*,float*,PProcess);
PDll_WinTransform Dll_WinTransform;
typedef unsigned short (__stdcall *PDll_ObjDialogDLL)(const char*,OType);
PDll_ObjDialogDLL Dll_ObjDialogDLL;
typedef unsigned short (__stdcall *PDll_ObjDlgDLL)(const char*,OType,OType);
PDll_ObjDlgDLL Dll_ObjDlgDLL;
typedef unsigned short (__stdcall *PDll_Tbl_Dlg)(const char*,OType*,OType);
PDll_Tbl_Dlg Dll_Tbl_Dlg;
typedef unsigned short (__stdcall *PDll_ArrDialog)(const char*,OType,OType,unsigned char,unsigned char,float,float);
PDll_ArrDialog Dll_ArrDialog;
typedef unsigned short (__stdcall *PDll_ArrDialogNew)(const char*,OType,OType,unsigned char,unsigned char,float,float,long,unsigned char);
PDll_ArrDialogNew Dll_ArrDialogNew;
typedef unsigned short (__stdcall *PDll_SArrDialog)(const char*,OType);
PDll_SArrDialog Dll_SArrDialog;
typedef unsigned short (__stdcall *PDll_SArrDialogNew)(const char*,OType,long,unsigned short);
PDll_SArrDialogNew Dll_SArrDialogNew;
typedef unsigned short (__stdcall *PDll_ArrDialogD)(const char*,OType,OType,OType,unsigned char,unsigned char,float,float);
PDll_ArrDialogD Dll_ArrDialogD;
typedef unsigned short (__stdcall *PDll_ChoiceObjByKey)(OType,unsigned char,unsigned short*,LongBoolean,OType*);
PDll_ChoiceObjByKey Dll_ChoiceObjByKey;
typedef void (__stdcall *PDll_SelectString)(const char*,const char*,void*,unsigned short*,LongBoolean,LongBoolean,char*);
PDll_SelectString Dll_SelectString;
typedef void* (__stdcall *PDll_SelectSetOfString)(const char*,void*,void*);
PDll_SelectSetOfString Dll_SelectSetOfString;
typedef short (__stdcall *PDll_ChoiceLogRec)(const char*,long,OType,OType*,LongBoolean,LongBoolean);
PDll_ChoiceLogRec Dll_ChoiceLogRec;
typedef void* (__stdcall *PDll_GetSetObjIdn)(OType,unsigned short,void*,LongBoolean);
PDll_GetSetObjIdn Dll_GetSetObjIdn;
typedef void* (__stdcall *PDll_LogRecGetKeyContent)(OType,unsigned char);
PDll_LogRecGetKeyContent Dll_LogRecGetKeyContent;
typedef short (__stdcall *PDll_ChoiceArrayByName)(OType,OType*,char*,unsigned short*);
PDll_ChoiceArrayByName Dll_ChoiceArrayByName;
typedef short (__stdcall *PDll_ChoiceColumnName)(OType,char*,unsigned char*,unsigned short*);
PDll_ChoiceColumnName Dll_ChoiceColumnName;
typedef void* (__stdcall *PDll_GetColumnList)(OType);
PDll_GetColumnList Dll_GetColumnList;
/*typedef void* (__stdcall *PDll_GetInputLine)(RECT,unsigned char,char*,char*,unsigned char,unsigned char);
PDll_GetInputLine Dll_GetInputLine;*/
typedef short (__stdcall *PDll_ChoiceTDesc)(const char*,OType*);
PDll_ChoiceTDesc Dll_ChoiceTDesc;
typedef void (__stdcall *PDll_ShowH)(RECT,OType*,const char*,const char*,const char*,unsigned short);
PDll_ShowH Dll_ShowH;
typedef void (__stdcall *PDll_ShowHEx)(RECT,OType*,const char*,const char*,const char*,unsigned short,unsigned short,unsigned short,unsigned char);
PDll_ShowHEx Dll_ShowHEx;
typedef void (__stdcall *PDll_GetFilename)(const char*,const char*,char*);
PDll_GetFilename Dll_GetFilename;
typedef void (__stdcall *PDll_GetColumnName)(OType,unsigned char,char*);
PDll_GetColumnName Dll_GetColumnName;
typedef long (__stdcall *PDll_D_GetFDFactor)(const char*,OType,const char*,const char*,float*);
PDll_D_GetFDFactor Dll_D_GetFDFactor;
typedef long (__stdcall *PDll_D_GetFDNFactor)(const char*,OType,long,const char*,float*);
PDll_D_GetFDNFactor Dll_D_GetFDNFactor;
typedef LongBoolean (__stdcall *PDll_GetFULongInt)(OType,const char*,const char*,long*);
PDll_GetFULongInt Dll_GetFULongInt;
typedef LongBoolean (__stdcall *PDll_GetFUSingle)(OType,const char*,const char*,float*);
PDll_GetFUSingle Dll_GetFUSingle;
typedef LongBoolean (__stdcall *PDll_GetFUString)(OType,const char*,const char*,char*);
PDll_GetFUString Dll_GetFUString;
typedef LongBoolean (__stdcall *PDll_PutFULongInt)(OType,const char*,const char*,long);
PDll_PutFULongInt Dll_PutFULongInt;
typedef LongBoolean (__stdcall *PDll_PutFUSingle)(OType,const char*,const char*,float);
PDll_PutFUSingle Dll_PutFUSingle;
typedef LongBoolean (__stdcall *PDll_PutFUString)(OType,const char*,const char*,const char*);
PDll_PutFUString Dll_PutFUString;
typedef void (__stdcall *PDll_SelectDir)(char*);
PDll_SelectDir Dll_SelectDir;
typedef void (__stdcall *PDll_ShowVertObj)(OType*,const char*);
PDll_ShowVertObj Dll_ShowVertObj;
typedef unsigned short (__stdcall *PDll_InputString)(const char*,const char*,unsigned short,char*);
PDll_InputString Dll_InputString;
typedef unsigned short (__stdcall *PDll_InputSingle)(const char*,const char*,float,float,float*);
PDll_InputSingle Dll_InputSingle;
typedef unsigned short (__stdcall *PDll_InputWord)(const char*,const char*,unsigned short,unsigned short,unsigned short*);
PDll_InputWord Dll_InputWord;
typedef unsigned short (__stdcall *PDll_SelectTwo)(const char*,const char*,const char*,unsigned short*);
PDll_SelectTwo Dll_SelectTwo;
typedef unsigned short (__stdcall *PDll_InputJoint)(const char*,const char*,const char*,const char*,unsigned short,unsigned short,float,float,unsigned short*,unsigned short*,float*);
PDll_InputJoint Dll_InputJoint;
typedef unsigned short (__stdcall *PDll_OperateDataObj)(OType*,char*,char*,char*,unsigned short*,LongBoolean,void**,void**,unsigned short,unsigned short,OType*);
PDll_OperateDataObj Dll_OperateDataObj;
typedef unsigned short (__stdcall *PDll_TempOperateDataObj)(OType*,char*,char*,char*,unsigned short*,LongBoolean,void**,void**,unsigned short,unsigned short,OType*);
PDll_TempOperateDataObj Dll_TempOperateDataObj;
typedef void (__stdcall *PDll_StartLongProcess)(const char*,long,long);
PDll_StartLongProcess Dll_StartLongProcess;
typedef void (__stdcall *PDll_LongProcessBack)(long);
PDll_LongProcessBack Dll_LongProcessBack;
typedef void (__stdcall *PDll_StopLongProcess)(void);
PDll_StopLongProcess Dll_StopLongProcess;
typedef LongBoolean (__stdcall *PDll_LongProcessCancelled)(void);
PDll_LongProcessCancelled Dll_LongProcessCancelled;
typedef short (__stdcall *PDll_Save_WSExR)(const char*,const char*,const char*,LongBoolean,OType);
PDll_Save_WSExR Dll_Save_WSExR;
typedef long (__stdcall *PDll_CreateLayerCurve)(OType,OType,unsigned char,
           OType,const char*,OType,OType,unsigned char,long);
PDll_CreateLayerCurve Dll_CreateLayerCurve;
typedef void (__stdcall *PDll_ResDialog)(const char*,const char*);
PDll_ResDialog Dll_ResDialog;
typedef void* (__stdcall *PDll_GetNewClsList)(const char*);
PDll_GetNewClsList Dll_GetNewClsList;
typedef long (__stdcall *PDll_DoFuncDic)(const char*,const char*,const char*,
  OType,OType,char*,long);
PDll_DoFuncDic Dll_DoFuncDic;
typedef short (__stdcall *PDll_GetDicObj)(const char*,const char*,const char*,
  OType*);
PDll_GetDicObj Dll_GetDicObj;
typedef long (__stdcall *PDll_GetNewName)(const char*,OType,unsigned char,
  unsigned char,char*,long);
PDll_GetNewName Dll_GetNewName;
typedef unsigned short (__stdcall *PDll_Tbl)(const char*,OType*,OType,OType,
  const char*,short);
PDll_Tbl Dll_Tbl;

typedef long (__stdcall *PDll_GetKDataObj)(const char*,const char*,const char*,const char*,const char*,const char*,OType*);
PDll_GetKDataObj Dll_GetKDataObj;
typedef long (__stdcall *PDll_GetKDataS)(const char*,const char*,const char*,const char*,const char*,const char*,char*);
PDll_GetKDataS Dll_GetKDataS;
typedef long (__stdcall *PDll_GetKDataR)(const char*,const char*,const char*,const char*,const char*,const char*,float*);
PDll_GetKDataR Dll_GetKDataR;
typedef long (__stdcall *PDll_PutKDataS)(const char*,const char*,const char*,const char*,const char*,const char*,const char*);
PDll_PutKDataS Dll_PutKDataS;
typedef long (__stdcall *PDll_PutKDataR)(const char*,const char*,const char*,const char*,const char*,const char*,float);
PDll_PutKDataR Dll_PutKDataR;

typedef TTwoDWindow (__stdcall *PDll_TwoDWndCreate)(const char*,float,
  float,long,long,float,float,long,float,float,long,const char*,const char*,
  const char*,long);
PDll_TwoDWndCreate Dll_TwoDWndCreate;
typedef TTwoDWindow (__stdcall *PDll_TwoDWndCreateByDataHandle)(OType,OType,
  const char*,long);
PDll_TwoDWndCreateByDataHandle Dll_TwoDWndCreateByDataHandle;
typedef HWND (__stdcall *PDll_TwoDWndGetHandle)(TTwoDWindow);
PDll_TwoDWndGetHandle Dll_TwoDWndGetHandle;
typedef LongBoolean (__stdcall *PDll_TwoDWndShow)(TTwoDWindow,LongBoolean);
PDll_TwoDWndShow Dll_TwoDWndShow;
typedef LongBoolean (__stdcall *PDll_TwoDWndShowModal)(TTwoDWindow);
PDll_TwoDWndShowModal Dll_TwoDWndShowModal;
typedef LongBoolean (__stdcall *PDll_TwoDWndSetRect)(TTwoDWindow,const RECT*);
PDll_TwoDWndSetRect Dll_TwoDWndSetRect;
typedef LongBoolean (__stdcall *PDll_TwoDWndSetCallback_CloseWindow)(TTwoDWindow,
  long,TTwoDCloseWindowCallback);
PDll_TwoDWndSetCallback_CloseWindow Dll_TwoDWndSetCallback_CloseWindow;
typedef LongBoolean (__stdcall *PDll_TwoDWndSetData)(TTwoDWindow,float*,
  long,long);
PDll_TwoDWndSetData Dll_TwoDWndSetData;
typedef LongBoolean (__stdcall *PDll_TwoDWndGetData)(TTwoDWindow,float*,
  long,long);
PDll_TwoDWndGetData Dll_TwoDWndGetData;
typedef LongBoolean (__stdcall *PDll_TwoDWndGetAreaDisplayParams)(TTwoDWindow,
  long,THGraphAreaRec*);
PDll_TwoDWndGetAreaDisplayParams Dll_TwoDWndGetAreaDisplayParams;
typedef LongBoolean (__stdcall *PDll_TwoDWndSetAreaDisplayParams)(TTwoDWindow,
  long,const THGraphAreaRec*);
PDll_TwoDWndSetAreaDisplayParams Dll_TwoDWndSetAreaDisplayParams;
typedef LongBoolean (__stdcall *PDll_TwoDWndDestroy)(TTwoDWindow);
PDll_TwoDWndDestroy Dll_TwoDWndDestroy;

typedef LongBoolean (__stdcall *PDll_TwoDControlWndShow)(LongBoolean);
PDll_TwoDControlWndShow Dll_TwoDControlWndShow;
typedef LongBoolean (__stdcall *PDll_AddWin2dToControlWindow)(TTwoDWindow);
PDll_AddWin2dToControlWindow Dll_AddWin2dToControlWindow;
typedef LongBoolean (__stdcall *PDll_TwoDControlWndSetCallback_CloseWindow)(
  long,TTwoDCloseControlWindowCallback);
PDll_TwoDControlWndSetCallback_CloseWindow Dll_TwoDControlWndSetCallback_CloseWindow;

typedef long (__stdcall *PDll_AnsiLasLineNew)(const char *,const char*,char*,long,long*,OType,OType,long,long,long,char*,long);
PDll_AnsiLasLineNew Dll_AnsiLasLineNew;
typedef long (__stdcall *PDll_AnsiGetFuncStr)(char*,long,unsigned short*,char*,long);
PDll_AnsiGetFuncStr Dll_AnsiGetFuncStr;
typedef long (__stdcall *PDll_AnsiGetWord)(char*,long,unsigned short*,char*,long);
PDll_AnsiGetWord Dll_AnsiGetWord;
typedef long (__stdcall *PDll_AnsiRemovePar)(const char*,char,unsigned short,char*,long);
PDll_AnsiRemovePar Dll_AnsiRemovePar;
typedef long (__stdcall *PDll_AnsiGetWSValue)(const char*,short*,char*,long);
PDll_AnsiGetWSValue Dll_AnsiGetWSValue;
typedef long (__stdcall *PDll_AnsiGetTableValue)(const char*,OType,short*,char*,long);
PDll_AnsiGetTableValue Dll_AnsiGetTableValue;
typedef long (__stdcall *PDll_AnsiGetObjValue)(const char*,OType,short*,char*,long);
PDll_AnsiGetObjValue Dll_AnsiGetObjValue;
typedef long (__stdcall *PDll_AnsiUpdateStrC)(const char*,OType,char*,long,const char*);
PDll_AnsiUpdateStrC Dll_AnsiUpdateStrC;
typedef long (__stdcall *PDll_AnsiUpdateStrCData)(const char*,OType,OType,char*,long,const char*);
PDll_AnsiUpdateStrCData Dll_AnsiUpdateStrCData;
typedef long (__stdcall *PDll_AnsiDoFuncDic)(const char*,const char*,const char*,OType,OType,char*,long);
PDll_AnsiDoFuncDic Dll_AnsiDoFuncDic;
typedef short (__stdcall *PDll_AnsiGetDicObj)(const char*,const char*,const char*,OType*);
PDll_AnsiGetDicObj Dll_AnsiGetDicObj;
typedef long (__stdcall *PDll_AnsiGetNewName)(const char*,OType,unsigned char,unsigned char,char*,long);
PDll_AnsiGetNewName Dll_AnsiGetNewName;
typedef long (__stdcall *PDll_AnsiGetToken)(const char*,long*,char*,long);
PDll_AnsiGetToken Dll_AnsiGetToken;
typedef long (__stdcall *PDll_AnsiGetFuncDicName)(const char*,const char*,const char*,OType,char*,long);
PDll_AnsiGetFuncDicName Dll_AnsiGetFuncDicName;
typedef void (__stdcall *PDll_AnsiSetCurrWSName)(const char*);
PDll_AnsiSetCurrWSName Dll_AnsiSetCurrWSName;
typedef void (__stdcall *PDll_AnsiSetCurrTablName)(const char*);
PDll_AnsiSetCurrTablName Dll_AnsiSetCurrTablName;
typedef void (__stdcall *PDll_AnsiSetCurrObjName)(const char*);
PDll_AnsiSetCurrObjName Dll_AnsiSetCurrObjName;
typedef void (__stdcall *PDll_AnsiSetCurrRecName)(const char*);
PDll_AnsiSetCurrRecName Dll_AnsiSetCurrRecName;
typedef void (__stdcall *PDll_AnsiSetCurrArrName)(const char*);
PDll_AnsiSetCurrArrName Dll_AnsiSetCurrArrName;
typedef void (__stdcall *PDll_AnsiSetCurrArrColName)(const char*);
PDll_AnsiSetCurrArrColName Dll_AnsiSetCurrArrColName;
typedef void (__stdcall *PDll_AnsiSetCurrObValName)(const char*);
PDll_AnsiSetCurrObValName Dll_AnsiSetCurrObValName;
typedef void (__stdcall *PDll_AnsiSetCurrArrColNumber)(unsigned char);
PDll_AnsiSetCurrArrColNumber Dll_AnsiSetCurrArrColNumber;
typedef void (__stdcall *PDll_AnsiSetCurrBaseHandle)(OType);
PDll_AnsiSetCurrBaseHandle Dll_AnsiSetCurrBaseHandle;
typedef void (__stdcall *PDll_AnsiSetCurrTablHandle)(OType);
PDll_AnsiSetCurrTablHandle Dll_AnsiSetCurrTablHandle;
typedef void (__stdcall *PDll_AnsiSetCurrObjHandle)(OType);
PDll_AnsiSetCurrObjHandle Dll_AnsiSetCurrObjHandle;
typedef void (__stdcall *PDll_AnsiSetCurrArrHandle)(OType);
PDll_AnsiSetCurrArrHandle Dll_AnsiSetCurrArrHandle;
typedef void (__stdcall *PDll_AnsiSetCurrObValHandle)(OType);
PDll_AnsiSetCurrObValHandle Dll_AnsiSetCurrObValHandle;
typedef OType (__stdcall *PDll_AnsiGetCurrBaseHandle)(void);
PDll_AnsiGetCurrBaseHandle Dll_AnsiGetCurrBaseHandle;
typedef OType (__stdcall *PDll_AnsiGetCurrTablHandle)(void);
PDll_AnsiGetCurrTablHandle Dll_AnsiGetCurrTablHandle;
typedef OType (__stdcall *PDll_AnsiGetCurrObjHandle)(void);
PDll_AnsiGetCurrObjHandle Dll_AnsiGetCurrObjHandle;
typedef OType (__stdcall *PDll_AnsiGetCurrArrHandle)(void);
PDll_AnsiGetCurrArrHandle Dll_AnsiGetCurrArrHandle;
typedef unsigned char (__stdcall *PDll_AnsiGetCurrArrColNumber)(void);
PDll_AnsiGetCurrArrColNumber Dll_AnsiGetCurrArrColNumber;
typedef OType (__stdcall *PDll_AnsiGetCurrObValHandle)(void);
PDll_AnsiGetCurrObValHandle Dll_AnsiGetCurrObValHandle;
typedef long (__stdcall *PDll_AnsiGetCurrWSName)(char*,long);
PDll_AnsiGetCurrWSName Dll_AnsiGetCurrWSName;
typedef long (__stdcall *PDll_AnsiGetCurrTablName)(char*,long);
PDll_AnsiGetCurrTablName Dll_AnsiGetCurrTablName;
typedef long (__stdcall *PDll_AnsiGetCurrObjName)(char*,long);
PDll_AnsiGetCurrObjName Dll_AnsiGetCurrObjName;
typedef long (__stdcall *PDll_AnsiGetCurrRecName)(char*,long);
PDll_AnsiGetCurrRecName Dll_AnsiGetCurrRecName;
typedef long (__stdcall *PDll_AnsiGetCurrArrName)(char*,long);
PDll_AnsiGetCurrArrName Dll_AnsiGetCurrArrName;
typedef long (__stdcall *PDll_AnsiGetCurrObValName)(char*,long);
PDll_AnsiGetCurrObValName Dll_AnsiGetCurrObValName;
typedef LongBoolean (__stdcall *PDll_AnsiSetRowDelimiter)(const char*);
PDll_AnsiSetRowDelimiter Dll_AnsiSetRowDelimiter;
typedef long (__stdcall *PDll_AnsiGetRowDelimiter)(char*,long);
PDll_AnsiGetRowDelimiter Dll_AnsiGetRowDelimiter;
typedef LongBoolean (__stdcall *PDll_AnsiSetColDelimiter)(const char*);
PDll_AnsiSetColDelimiter Dll_AnsiSetColDelimiter;
typedef long (__stdcall *PDll_AnsiGetColDelimiter)(char*,long);
PDll_AnsiGetColDelimiter Dll_AnsiGetColDelimiter;
typedef void (__stdcall *PDll_InitTableObjCache)(OType);
PDll_InitTableObjCache Dll_InitTableObjCache;
typedef void (__stdcall *PDll_DestroyTableObjCache)(void);
PDll_DestroyTableObjCache Dll_DestroyTableObjCache;
typedef short (__stdcall *PDll_GetCachedTableHandle)(const char*,OType,long*);
PDll_GetCachedTableHandle Dll_GetCachedTableHandle;
typedef short (__stdcall *PDll_GetCachedTableObjByIdN)(long*,unsigned short,OType*);
PDll_GetCachedTableObjByIdN Dll_GetCachedTableObjByIdN;
typedef void (__stdcall *PDll_DisableTableObjCache)(void);
PDll_DisableTableObjCache Dll_DisableTableObjCache;
typedef void (__stdcall *PDll_EnableTableObjCache)(void);
PDll_EnableTableObjCache Dll_EnableTableObjCache;
typedef LongBoolean (__stdcall *PDll_IsTableObjCacheEnabled)(void);
PDll_IsTableObjCacheEnabled Dll_IsTableObjCacheEnabled;
typedef char* (__stdcall *PDll_StdDepthUnit)(void);
PDll_StdDepthUnit Dll_StdDepthUnit;
typedef TMinimalDepthUnit (__stdcall *PDll_StdDepthUnitOfInstance)(HINSTANCE);
PDll_StdDepthUnitOfInstance Dll_StdDepthUnitOfInstance;
typedef void (__stdcall *PDll_TemporarySetNewDepthUnit)(const char*,void*);
PDll_TemporarySetNewDepthUnit Dll_TemporarySetNewDepthUnit;
typedef char* (__stdcall *PDll_StdUserDepthUnit)(void);
PDll_StdUserDepthUnit Dll_StdUserDepthUnit;
typedef TUserDepthUnit (__stdcall *PDll_UserDepthUnitOfInstance)(HINSTANCE);
PDll_UserDepthUnitOfInstance Dll_UserDepthUnitOfInstance;
typedef void (__stdcall *PDll_TemporarySetNewUserDepthUnit)(const char*,void*);
PDll_TemporarySetNewUserDepthUnit Dll_TemporarySetNewUserDepthUnit;
typedef void (__stdcall *PDll_DSExtUpdateInstanceData)(HINSTANCE,void*);
PDll_DSExtUpdateInstanceData Dll_DSExtUpdateInstanceData;

/*****************************************************************************\
*                                                                             *
*    ÎÏÐÅÄÅËÅÍÈß ÂÛÇÎÂÎÂ ÔÓÍÊÖÈÉ ÈÇ ÂÍÅØÍÅÃÎ ÌÎÄÓËß (DLL)                     *
*                                                                             *
\*****************************************************************************/

void ConnectDSExtFunctions(void){
	if (hDLL_DSEXT != NULL)
	{
		/* Ïîëó÷åíèå àäðåñîâ âûçîâà ôóíêöèé âíåøíåãî ìîäóëÿ */
		Dll_AddWin2dToControlWindow = (PDll_AddWin2dToControlWindow)GetProcAddress(hDLL_DSEXT, "AddWin2dToControlWindow");
		Dll_AnsiDoFuncDic = (PDll_AnsiDoFuncDic)GetProcAddress(hDLL_DSEXT, "AnsiDoFuncDic");
		Dll_AnsiGetColDelimiter = (PDll_AnsiGetColDelimiter)GetProcAddress(hDLL_DSEXT, "AnsiGetColDelimiter");
		Dll_AnsiGetCurrArrColNumber = (PDll_AnsiGetCurrArrColNumber)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrArrColNumber");
		Dll_AnsiGetCurrArrHandle = (PDll_AnsiGetCurrArrHandle)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrArrHandle");
		Dll_AnsiGetCurrArrName = (PDll_AnsiGetCurrArrName)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrArrName");
		Dll_AnsiGetCurrBaseHandle = (PDll_AnsiGetCurrBaseHandle)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrBaseHandle");
		Dll_AnsiGetCurrObjHandle = (PDll_AnsiGetCurrObjHandle)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrObjHandle");
		Dll_AnsiGetCurrObjName = (PDll_AnsiGetCurrObjName)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrObjName");
		Dll_AnsiGetCurrObValHandle = (PDll_AnsiGetCurrObValHandle)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrObValHandle");
		Dll_AnsiGetCurrObValName = (PDll_AnsiGetCurrObValName)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrObValName");
		Dll_AnsiGetCurrRecName = (PDll_AnsiGetCurrRecName)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrRecName");
		Dll_AnsiGetCurrTablHandle = (PDll_AnsiGetCurrTablHandle)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrTablHandle");
		Dll_AnsiGetCurrTablName = (PDll_AnsiGetCurrTablName)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrTablName");
		Dll_AnsiGetCurrWSName = (PDll_AnsiGetCurrWSName)GetProcAddress(hDLL_DSEXT, "AnsiGetCurrWSName");
		Dll_AnsiGetDicObj = (PDll_AnsiGetDicObj)GetProcAddress(hDLL_DSEXT, "AnsiGetDicObj");
		Dll_AnsiGetFuncDicName = (PDll_AnsiGetFuncDicName)GetProcAddress(hDLL_DSEXT, "AnsiGetFuncDicName");
		Dll_AnsiGetFuncStr = (PDll_AnsiGetFuncStr)GetProcAddress(hDLL_DSEXT, "AnsiGetFuncStr");
		Dll_AnsiGetNewName = (PDll_AnsiGetNewName)GetProcAddress(hDLL_DSEXT, "AnsiGetNewName");
		Dll_AnsiGetObjValue = (PDll_AnsiGetObjValue)GetProcAddress(hDLL_DSEXT, "AnsiGetObjValue");
		Dll_AnsiGetRowDelimiter = (PDll_AnsiGetRowDelimiter)GetProcAddress(hDLL_DSEXT, "AnsiGetRowDelimiter");
		Dll_AnsiGetTableValue = (PDll_AnsiGetTableValue)GetProcAddress(hDLL_DSEXT, "AnsiGetTableValue");
		Dll_AnsiGetToken = (PDll_AnsiGetToken)GetProcAddress(hDLL_DSEXT, "AnsiGetToken");
		Dll_AnsiGetWord = (PDll_AnsiGetWord)GetProcAddress(hDLL_DSEXT, "AnsiGetWord");
		Dll_AnsiGetWSValue = (PDll_AnsiGetWSValue)GetProcAddress(hDLL_DSEXT, "AnsiGetWSValue");
		Dll_AnsiLasLineNew = (PDll_AnsiLasLineNew)GetProcAddress(hDLL_DSEXT, "AnsiLasLineNew");
		Dll_AnsiRemovePar = (PDll_AnsiRemovePar)GetProcAddress(hDLL_DSEXT, "AnsiRemovePar");
		Dll_AnsiSetColDelimiter = (PDll_AnsiSetColDelimiter)GetProcAddress(hDLL_DSEXT, "AnsiSetColDelimiter");
		Dll_AnsiSetCurrArrColName = (PDll_AnsiSetCurrArrColName)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrArrColName");
		Dll_AnsiSetCurrArrColNumber = (PDll_AnsiSetCurrArrColNumber)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrArrColNumber");
		Dll_AnsiSetCurrArrHandle = (PDll_AnsiSetCurrArrHandle)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrArrHandle");
		Dll_AnsiSetCurrArrName = (PDll_AnsiSetCurrArrName)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrArrName");
		Dll_AnsiSetCurrBaseHandle = (PDll_AnsiSetCurrBaseHandle)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrBaseHandle");
		Dll_AnsiSetCurrObjHandle = (PDll_AnsiSetCurrObjHandle)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrObjHandle");
		Dll_AnsiSetCurrObjName = (PDll_AnsiSetCurrObjName)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrObjName");
		Dll_AnsiSetCurrObValHandle = (PDll_AnsiSetCurrObValHandle)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrObValHandle");
		Dll_AnsiSetCurrObValName = (PDll_AnsiSetCurrObValName)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrObValName");
		Dll_AnsiSetCurrRecName = (PDll_AnsiSetCurrRecName)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrRecName");
		Dll_AnsiSetCurrTablHandle = (PDll_AnsiSetCurrTablHandle)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrTablHandle");
		Dll_AnsiSetCurrTablName = (PDll_AnsiSetCurrTablName)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrTablName");
		Dll_AnsiSetCurrWSName = (PDll_AnsiSetCurrWSName)GetProcAddress(hDLL_DSEXT, "AnsiSetCurrWSName");
		Dll_AnsiSetRowDelimiter = (PDll_AnsiSetRowDelimiter)GetProcAddress(hDLL_DSEXT, "AnsiSetRowDelimiter");
		Dll_AnsiUpdateStrC = (PDll_AnsiUpdateStrC)GetProcAddress(hDLL_DSEXT, "AnsiUpdateStrC");
		Dll_AnsiUpdateStrCData = (PDll_AnsiUpdateStrCData)GetProcAddress(hDLL_DSEXT, "AnsiUpdateStrCData");
		Dll_ArgTransform = (PDll_ArgTransform)GetProcAddress(hDLL_DSEXT, "ArgTransform");
		Dll_ArrDialog = (PDll_ArrDialog)GetProcAddress(hDLL_DSEXT, "ArrDialog");
		Dll_ArrDialogD = (PDll_ArrDialogD)GetProcAddress(hDLL_DSEXT, "ArrDialogD");
		Dll_ArrDialogNew = (PDll_ArrDialogNew)GetProcAddress(hDLL_DSEXT, "ArrDialogNew");
		Dll_ChoiceArrayByName = (PDll_ChoiceArrayByName)GetProcAddress(hDLL_DSEXT, "ChoiceArrayByName");
		Dll_ChoiceColumnName = (PDll_ChoiceColumnName)GetProcAddress(hDLL_DSEXT, "ChoiceColumnName");
		Dll_ChoiceLogRec = (PDll_ChoiceLogRec)GetProcAddress(hDLL_DSEXT, "ChoiceLogRec");
		Dll_ChoiceObjByKey = (PDll_ChoiceObjByKey)GetProcAddress(hDLL_DSEXT, "ChoiceObjByKey");
		Dll_ChoiceTDesc = (PDll_ChoiceTDesc)GetProcAddress(hDLL_DSEXT, "ChoiceTDesc");
		Dll_CreateLayerCurve = (PDll_CreateLayerCurve)GetProcAddress(hDLL_DSEXT, "CreateLayerCurve");
		Dll_D_GetFDFactor = (PDll_D_GetFDFactor)GetProcAddress(hDLL_DSEXT, "D_GetFDFactor");
		Dll_D_GetFDNFactor = (PDll_D_GetFDNFactor)GetProcAddress(hDLL_DSEXT, "D_GetFDNFactor");
		Dll_DSExtUpdateInstanceData = (PDll_DSExtUpdateInstanceData)GetProcAddress(hDLL_DSEXT, "DSExtUpdateInstanceData");
		Dll_DataKeyStrLong = (PDll_DataKeyStrLong)GetProcAddress(hDLL_DSEXT, "DataKeyStrLong");
		Dll_DestroyTableObjCache = (PDll_DestroyTableObjCache)GetProcAddress(hDLL_DSEXT, "DestroyTableObjCache");
		Dll_DisableTableObjCache = (PDll_DisableTableObjCache)GetProcAddress(hDLL_DSEXT, "DisableTableObjCache");
		Dll_DoFuncDic = (PDll_DoFuncDic)GetProcAddress(hDLL_DSEXT, "DoFuncDic");
		Dll_EnableTableObjCache = (PDll_EnableTableObjCache)GetProcAddress(hDLL_DSEXT, "EnableTableObjCache");
		//Dll_GetArrayIndex = (PDll_GetArrayIndex)GetProcAddress(hDLL_DSEXT, "GetArrayIndex");
		Dll_GetAlgHandle = (PDll_GetAlgHandle)GetProcAddress(hDLL_DSEXT, "GetAlgHandle");
		Dll_GetAlgPath = (PDll_GetAlgPath)GetProcAddress(hDLL_DSEXT, "GetAlgPath");
		Dll_GetCachedTableHandle = (PDll_GetCachedTableHandle)GetProcAddress(hDLL_DSEXT, "GetCachedTableHandle");
		Dll_GetCachedTableObjByIdN = (PDll_GetCachedTableObjByIdN)GetProcAddress(hDLL_DSEXT, "GetCachedTableObjByIdN");
		Dll_GetColumnList = (PDll_GetColumnList)GetProcAddress(hDLL_DSEXT, "GetColumnList");
		Dll_GetColumnName = (PDll_GetColumnName)GetProcAddress(hDLL_DSEXT, "GetColumnName");
		Dll_GetCurveInformation = (PDll_GetCurveInformation)GetProcAddress(hDLL_DSEXT, "GetCurveInformation");
		Dll_GetDicObj = (PDll_GetDicObj)GetProcAddress(hDLL_DSEXT, "GetDicObj");
		Dll_GetFULongInt = (PDll_GetFULongInt)GetProcAddress(hDLL_DSEXT, "GetFULongInt");
		Dll_GetFUSingle = (PDll_GetFUSingle)GetProcAddress(hDLL_DSEXT, "GetFUSingle");
		Dll_GetFUString = (PDll_GetFUString)GetProcAddress(hDLL_DSEXT, "GetFUString");
		Dll_GetField = (PDll_GetField)GetProcAddress(hDLL_DSEXT, "GetField");
		Dll_GetFilename = (PDll_GetFilename)GetProcAddress(hDLL_DSEXT, "GetFilename");
		//Dll_GetInputLine = (PDll_GetInputLine)GetProcAddress(hDLL_DSEXT, "GetInputLine");
		Dll_GetIndex = (PDll_GetIndex)GetProcAddress(hDLL_DSEXT, "GetIndex");
		//Dll_GetInterIndex = (PDll_GetInterIndex)GetProcAddress(hDLL_DSEXT, "GetInterIndex");
		Dll_GetKDataS = (PDll_GetKDataS)GetProcAddress(hDLL_DSEXT, "GetKDataS");
		Dll_GetKDataObj = (PDll_GetKDataObj)GetProcAddress(hDLL_DSEXT, "GetKDataObj");
//      Dll_GetKDataObj = (PDll_GetKDataObj)GetProcAddress(hDLL_DSEXT, "GetKDataObj");
		Dll_GetKDataR = (PDll_GetKDataR)GetProcAddress(hDLL_DSEXT, "GetKDataR");
		//Dll_GetMonValueIndex = (PDll_GetMonValueIndex)GetProcAddress(hDLL_DSEXT, "GetMonValueIndex");
		Dll_GetNBALongInt = (PDll_GetNBALongInt)GetProcAddress(hDLL_DSEXT, "GetNBALongInt");
		Dll_GetNBASingle = (PDll_GetNBASingle)GetProcAddress(hDLL_DSEXT, "GetNBASingle");
		Dll_GetNBAString = (PDll_GetNBAString)GetProcAddress(hDLL_DSEXT, "GetNBAString");
		Dll_GetNBFLongInt = (PDll_GetNBFLongInt)GetProcAddress(hDLL_DSEXT, "GetNBFLongInt");
		Dll_GetNBFSingle = (PDll_GetNBFSingle)GetProcAddress(hDLL_DSEXT, "GetNBFSingle");
		Dll_GetNBFString = (PDll_GetNBFString)GetProcAddress(hDLL_DSEXT, "GetNBFString");
		Dll_GetNBFStringLong = (PDll_GetNBFStringLong)GetProcAddress(hDLL_DSEXT, "GetNBFStringLong");
		Dll_GetNewClsList = (PDll_GetNewClsList)GetProcAddress(hDLL_DSEXT, "GetNewClsList");
		Dll_GetNewName = (PDll_GetNewName)GetProcAddress(hDLL_DSEXT, "GetNewName");
		Dll_GetSetObjIdn = (PDll_GetSetObjIdn)GetProcAddress(hDLL_DSEXT, "GetSetObjIdn");
		Dll_GetSystemPath = (PDll_GetSystemPath)GetProcAddress(hDLL_DSEXT, "GetSystemPath");
		//Dll_GetValueIndex = (PDll_GetValueIndex)GetProcAddress(hDLL_DSEXT, "GetValueIndex");
		Dll_InitTableObjCache = (PDll_InitTableObjCache)GetProcAddress(hDLL_DSEXT, "InitTableObjCache");
		Dll_InputJoint = (PDll_InputJoint)GetProcAddress(hDLL_DSEXT, "InputJoint");
		Dll_InputSingle = (PDll_InputSingle)GetProcAddress(hDLL_DSEXT, "InputSingle");
		Dll_InputString = (PDll_InputString)GetProcAddress(hDLL_DSEXT, "InputString");
		Dll_InputWord = (PDll_InputWord)GetProcAddress(hDLL_DSEXT, "InputWord");
		Dll_IsTableObjCacheEnabled = (PDll_IsTableObjCacheEnabled)GetProcAddress(hDLL_DSEXT, "IsTableObjCacheEnabled");
		Dll_LogRecGetKeyContent = (PDll_LogRecGetKeyContent)GetProcAddress(hDLL_DSEXT, "LogRecGetKeyContent");
		Dll_LongProcessBack = (PDll_LongProcessBack)GetProcAddress(hDLL_DSEXT, "LongProcessBack");
		Dll_LongProcessCancelled = (PDll_LongProcessCancelled)GetProcAddress(hDLL_DSEXT, "LongProcessCancelled");
		Dll_ObjDialogDLL = (PDll_ObjDialogDLL)GetProcAddress(hDLL_DSEXT, "ObjDialogDLL");
		Dll_ObjDlgDLL = (PDll_ObjDlgDLL)GetProcAddress(hDLL_DSEXT, "ObjDlgDLL");
		Dll_OperateDataObj = (PDll_OperateDataObj)GetProcAddress(hDLL_DSEXT, "OperateDataObj");
		Dll_PutArrayLongInt = (PDll_PutArrayLongInt)GetProcAddress(hDLL_DSEXT, "PutArrayLongInt");
		Dll_xPutArraySingle = (PDll_xPutArraySingle)GetProcAddress(hDLL_DSEXT, "PutArraySingle");
		Dll_xPutArrayString = (PDll_xPutArrayString)GetProcAddress(hDLL_DSEXT, "PutArrayString");
		Dll_PutFULongInt = (PDll_PutFULongInt)GetProcAddress(hDLL_DSEXT, "PutFULongInt");
		Dll_PutFUSingle = (PDll_PutFUSingle)GetProcAddress(hDLL_DSEXT, "PutFUSingle");
		Dll_PutFUString = (PDll_PutFUString)GetProcAddress(hDLL_DSEXT, "PutFUString");
		Dll_PutFieldLongInt = (PDll_PutFieldLongInt)GetProcAddress(hDLL_DSEXT, "PutFieldLongInt");
		Dll_PutFieldLongIntI = (PDll_PutFieldLongIntI)GetProcAddress(hDLL_DSEXT, "PutFieldLongIntI");
		Dll_PutFieldSingle = (PDll_PutFieldSingle)GetProcAddress(hDLL_DSEXT, "PutFieldSingle");
		Dll_PutFieldSingleI = (PDll_PutFieldSingleI)GetProcAddress(hDLL_DSEXT, "PutFieldSingleI");
		Dll_PutFieldString = (PDll_PutFieldString)GetProcAddress(hDLL_DSEXT, "PutFieldString");
		Dll_PutFieldStringI = (PDll_PutFieldStringI)GetProcAddress(hDLL_DSEXT, "PutFieldStringI");
		Dll_PutKDataS = (PDll_PutKDataS)GetProcAddress(hDLL_DSEXT, "PutKDataS");
		Dll_PutKDataR = (PDll_PutKDataR)GetProcAddress(hDLL_DSEXT, "PutKDataR");
		Dll_ResDialog = (PDll_ResDialog)GetProcAddress(hDLL_DSEXT, "ResDialog");
		Dll_SArrDialog = (PDll_SArrDialog)GetProcAddress(hDLL_DSEXT, "SArrDialog");
		Dll_SArrDialogNew = (PDll_SArrDialogNew)GetProcAddress(hDLL_DSEXT, "SArrDialogNew");
		Dll_Save_WSExR = (PDll_Save_WSExR)GetProcAddress(hDLL_DSEXT, "Save_WSExR");
		Dll_SelectDir = (PDll_SelectDir)GetProcAddress(hDLL_DSEXT, "SelectDir");
		Dll_SelectSetOfString = (PDll_SelectSetOfString)GetProcAddress(hDLL_DSEXT, "SelectSetOfString");
		Dll_SelectString = (PDll_SelectString)GetProcAddress(hDLL_DSEXT, "SelectString");
		Dll_SelectTwo = (PDll_SelectTwo)GetProcAddress(hDLL_DSEXT, "SelectTwo");
		Dll_SetField = (PDll_SetField)GetProcAddress(hDLL_DSEXT, "SetField");
		Dll_SetMainWndHandle = (PDll_SetMainWndHandle)GetProcAddress(hDLL_DSEXT, "SetMainWndHandle");
		Dll_ShiftDepth = (PDll_ShiftDepth)GetProcAddress(hDLL_DSEXT, "ShiftDepth");
		Dll_ShowH = (PDll_ShowH)GetProcAddress(hDLL_DSEXT, "ShowH");
		Dll_ShowHEx = (PDll_ShowHEx)GetProcAddress(hDLL_DSEXT, "ShowHEx");
		Dll_ShowVertObj = (PDll_ShowVertObj)GetProcAddress(hDLL_DSEXT, "ShowVertObj");
		Dll_StartLongProcess = (PDll_StartLongProcess)GetProcAddress(hDLL_DSEXT, "StartLongProcess");
		Dll_StdDepthUnit = (PDll_StdDepthUnit)GetProcAddress(hDLL_DSEXT, "StdDepthUnit");
		Dll_StdDepthUnitOfInstance = (PDll_StdDepthUnitOfInstance)GetProcAddress(hDLL_DSEXT, "StdDepthUnitOfInstance");
		Dll_StdUserDepthUnit = (PDll_StdUserDepthUnit)GetProcAddress(hDLL_DSEXT, "StdUserDepthUnit");
		Dll_StopLongProcess = (PDll_StopLongProcess)GetProcAddress(hDLL_DSEXT, "StopLongProcess");
		Dll_Tbl = (PDll_Tbl)GetProcAddress(hDLL_DSEXT, "Tbl");
		Dll_Tbl_Dlg = (PDll_Tbl_Dlg)GetProcAddress(hDLL_DSEXT, "Tbl_Dlg");
		Dll_TempOperateDataObj = (PDll_TempOperateDataObj)GetProcAddress(hDLL_DSEXT, "TempOperateDataObj");
		Dll_TemporarySetNewDepthUnit = (PDll_TemporarySetNewDepthUnit)GetProcAddress(hDLL_DSEXT, "TemporarySetNewDepthUnit");
		Dll_TemporarySetNewUserDepthUnit = (PDll_TemporarySetNewUserDepthUnit)GetProcAddress(hDLL_DSEXT, "TemporarySetNewUserDepthUnit");
		Dll_Transform = (PDll_Transform)GetProcAddress(hDLL_DSEXT, "Transform");
		Dll_TwoDControlWndShow = (PDll_TwoDControlWndShow)GetProcAddress(hDLL_DSEXT, "TwoDControlWndShow");
		Dll_TwoDControlWndSetCallback_CloseWindow = (PDll_TwoDControlWndSetCallback_CloseWindow)GetProcAddress(hDLL_DSEXT, "TwoDControlWndSetCallback_CloseWindow");
		Dll_TwoDWndCreate = (PDll_TwoDWndCreate)GetProcAddress(hDLL_DSEXT, "TwoDWndCreate");
		Dll_TwoDWndCreateByDataHandle = (PDll_TwoDWndCreateByDataHandle)GetProcAddress(hDLL_DSEXT, "TwoDWndCreateByDataHandle");
		Dll_TwoDWndDestroy = (PDll_TwoDWndDestroy)GetProcAddress(hDLL_DSEXT, "TwoDWndDestroy");
		Dll_TwoDWndGetAreaDisplayParams = (PDll_TwoDWndGetAreaDisplayParams)GetProcAddress(hDLL_DSEXT, "TwoDWndGetAreaDisplayParams");
		Dll_TwoDWndGetData = (PDll_TwoDWndGetData)GetProcAddress(hDLL_DSEXT, "TwoDWndGetData");
		Dll_TwoDWndGetHandle = (PDll_TwoDWndGetHandle)GetProcAddress(hDLL_DSEXT, "TwoDWndGetHandle");
		Dll_TwoDWndShow = (PDll_TwoDWndShow)GetProcAddress(hDLL_DSEXT, "TwoDWndShow");
		Dll_TwoDWndShowModal = (PDll_TwoDWndShowModal)GetProcAddress(hDLL_DSEXT, "TwoDWndShowModal");
		Dll_TwoDWndSetAreaDisplayParams = (PDll_TwoDWndSetAreaDisplayParams)GetProcAddress(hDLL_DSEXT, "TwoDWndSetAreaDisplayParams");
		Dll_TwoDWndSetCallback_CloseWindow = (PDll_TwoDWndSetCallback_CloseWindow)GetProcAddress(hDLL_DSEXT, "TwoDWndSetCallback_CloseWindow");
		Dll_TwoDWndSetData = (PDll_TwoDWndSetData)GetProcAddress(hDLL_DSEXT, "TwoDWndSetData");
		Dll_TwoDWndSetRect = (PDll_TwoDWndSetRect)GetProcAddress(hDLL_DSEXT, "TwoDWndSetRect");
		Dll_UserDepthUnitOfInstance = (PDll_UserDepthUnitOfInstance)GetProcAddress(hDLL_DSEXT, "UserDepthUnitOfInstance");
		Dll_WinTransform = (PDll_WinTransform)GetProcAddress(hDLL_DSEXT, "WinTransform");
	};
}

HINSTANCE DSEXT_GetThisModuleHandle(void){
  MEMORY_BASIC_INFORMATION MemInfo;
  VirtualQuery((void*)&DSEXT_GetThisModuleHandle, &MemInfo, sizeof(MemInfo));
  if (MemInfo.State == MEM_COMMIT)
  { return (HINSTANCE) MemInfo.AllocationBase; }
  else
  { return 0; }
}

long DSEXT_GetThisDirModuleName(const char* Name, char *PathAndName, long MaxLen){
	HINSTANCE H = DSEXT_GetThisModuleHandle();
	long Res = GetModuleFileName(H,PathAndName,MaxLen);
	if (!Res) { return 0; }
	for (int i = Res-1; (i >= 0) && (PathAndName[i] != '\\'); i-- ) { Res = i; }
	PathAndName[Res] = '\0';
	strncat(PathAndName,Name,MaxLen-Res);
	Res = strlen(PathAndName);
	return Res;
}

extern "C" LongBoolean DSExtLoad(void){
	hDLL_DSEXT = LoadLibrary(DSEXTDLL);
	if (hDLL_DSEXT == NULL){
		char NewName[MAX_PATH];
		if (DSEXT_GetThisDirModuleName(DSEXTDLL,NewName,MAX_PATH))
		{
			hDLL_DSEXT = LoadLibrary(NewName);
		}
	}
	if (hDLL_DSEXT != NULL){
		ConnectDSExtFunctions();
		DatservConnect();
		return true;
	}
	else {
		return false;
	};
}


extern "C" void DSExtFree(void) {
	if (hDLL_DSEXT != NULL) {
		FreeLibrary(hDLL_DSEXT);
	}
}


extern "C" LongBoolean DSExtConnect(void){
	hDLL_DSEXT = GetModuleHandle(DSEXTDLL);
	if (hDLL_DSEXT != NULL){
		ConnectDSExtFunctions();
		DatservConnect();
		return true;
	}
	else {
		return false;
	};
}


/*****************************************************************************/

HINSTANCE GetAlgHandle(){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetAlgHandle)) { return NULL; }
	else { return Dll_GetAlgHandle(); }
}

long GetAlgPath(char *Path, long MaxLen){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetAlgPath)) { return 0; }
	else { return Dll_GetAlgPath(Path, MaxLen); }
}

long GetSystemPath(char *Path, long MaxLen){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetSystemPath)) { return 0; }
	else { return Dll_GetSystemPath(Path, MaxLen); }
}

void SetMainWndHandle(HWND WndHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_SetMainWndHandle)) {  }
	else { Dll_SetMainWndHandle(WndHandle); }
}

LongBoolean GetNBALongInt(OType A, long Index, const char *ColName, long *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNBALongInt)) { return false; }
	else { return Dll_GetNBALongInt(A, Index, ColName, R); }
}

LongBoolean GetNBASingle(OType A, long Index, const char *ColName, float *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNBASingle)) { return false; }
	else { return Dll_GetNBASingle(A, Index, ColName, R); }
}

LongBoolean GetNBAString(OType A, long Index, const char *ColName, char *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNBAString)) { return false; }
	else { return Dll_GetNBAString(A, Index, ColName, R); }
}

LongBoolean GetNBFLongInt(OType A, const char *Name, long *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNBFLongInt)) { return false; }
	else { return Dll_GetNBFLongInt(A, Name, R); }
}

LongBoolean GetNBFSingle(OType A, const char *Name, float *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNBFSingle)) { return false; }
	else { return Dll_GetNBFSingle(A, Name, R); }
}

LongBoolean GetNBFString(OType A, const char *Name, char *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNBFString)) { return false; }
	else { return Dll_GetNBFString(A, Name, R); }
}

LongBoolean GetNBFStringLong(OType A, const char *Name, char *R, long RSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNBFStringLong)) { return false; }
	else { return Dll_GetNBFStringLong(A, Name, R, RSize); }
}

void PutArrayLongInt(OType A, long Index, const char *ColName, long V){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutArrayLongInt)) { return; }
	else { Dll_PutArrayLongInt(A, Index, ColName, V); return; }
}

void xPutArraySingle(OType A, long Index, const char *ColName, float V){
	if ((hDLL_DSEXT == NULL)||(!Dll_xPutArraySingle)) { return; }
	else { Dll_xPutArraySingle(A, Index, ColName, V); return; }
}

void xPutArrayString(OType A, long Index, const char *ColName, const char *V){
	if ((hDLL_DSEXT == NULL)||(!Dll_xPutArrayString)) { return; }
	else { Dll_xPutArrayString(A, Index, ColName, V); return; }
}

void PutFieldLongInt(OType A, const char *Name, long V){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFieldLongInt)) { return; }
	else { Dll_PutFieldLongInt(A, Name, V); return; }
}

void PutFieldSingle(OType A, const char *Name, float V){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFieldSingle)) { return; }
	else { Dll_PutFieldSingle(A, Name, V); return; }
}

void PutFieldString(OType A, const char *Name, const char* V){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFieldString)) { return; }
	else { Dll_PutFieldString(A, Name, V); return; }
}

void PutFieldLongIntI(OType A, long Index, long V){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFieldLongIntI)) { return; }
	else { Dll_PutFieldLongIntI(A, Index, V); return; }
}

void PutFieldSingleI(OType A, long Index, float V){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFieldSingleI)) { return; }
	else { Dll_PutFieldSingleI(A, Index, V); return; }
}

void PutFieldStringI(OType A, long Index, const char *V){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFieldStringI)) { return; }
	else { Dll_PutFieldStringI(A, Index, V); return; }
}

long GetCurveInformation(OType DataHandle, OType ArrayHandle, unsigned char *Column, long *Step, long *Roof, long *Sole){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetCurveInformation)) { return -1; }
	else { return Dll_GetCurveInformation(DataHandle, ArrayHandle, Column, Step, Roof, Sole); }
}

void DataKeyStrLong(const char *EmptyStr, OType DataHandle, unsigned short RowNumber, char *KeyStrLong){
	if ((hDLL_DSEXT == NULL)||(!Dll_DataKeyStrLong)) { return; }
	else { Dll_DataKeyStrLong(EmptyStr, DataHandle, RowNumber, KeyStrLong); return; }
}

//long GetValueIndex(OType ArrayHandle, unsigned char Column, float Value){
//	if ((hDLL_DSEXT == NULL)||(!Dll_GetValueIndex)) { return -1; }
//	else { return Dll_GetValueIndex(ArrayHandle, Column, Value); }
//}

//long GetMonValueIndex(OType ArrayHandle, unsigned char Column, float Value){
//	if ((hDLL_DSEXT == NULL)||(!Dll_GetMonValueIndex)) { return -1; }
//	else { return Dll_GetMonValueIndex(ArrayHandle, Column, Value); }
//}

//long GetInterIndex(OType ArrayHandle, unsigned char Column, float Roof, float Sole, long *RoofIndex, long *RoofSole){
//	if ((hDLL_DSEXT == NULL)||(!Dll_GetInterIndex)) { return -1; }
//	else { return Dll_GetInterIndex(ArrayHandle, Column, Roof, Sole, RoofIndex, RoofSole); }
//}

//long GetArrayIndex(OType ArrayHandle, unsigned char Column, long Count, float *Values, long ValuesLastIndex, long *Indices, long IndicesLastIndex){
//	if ((hDLL_DSEXT == NULL)||(!Dll_GetArrayIndex)) { return -1; }
//	else { return Dll_GetArrayIndex(ArrayHandle, Column, Count, Values, ValuesLastIndex, Indices, IndicesLastIndex); }
//}

long GetField(OType DataHandle, OType ArrHandle, long *Roof, long *Sole, long *Step){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetField)) { return -1; }
	else { return Dll_GetField(DataHandle, ArrHandle, Roof, Sole, Step); }
}

long SetField(OType DataHandle, OType ArrHandle, long Roof, long Sole, long Step){
	if ((hDLL_DSEXT == NULL)||(!Dll_SetField)) { return -1; }
	else { return Dll_SetField(DataHandle, ArrHandle, Roof, Sole, Step); }
}

long GetIndex(OType DataHandle, OType ArrayHandle, long Depth){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetIndex)) { return -1; }
	else { return Dll_GetIndex(DataHandle, ArrayHandle, Depth); }
}

long ShiftDepth(OType DataHandle, OType ArrHandle, unsigned char ColNumber, long Delta, unsigned short Option){
	if ((hDLL_DSEXT == NULL)||(!Dll_ShiftDepth)) { return -1; }
	else { return Dll_ShiftDepth(DataHandle, ArrHandle, ColNumber, Delta, Option); }
}

long Transform(OType DataHandle, OType ArrHandle, unsigned char Column, long Roof, long Sole, TTransform P, PProcess Ind){
	if ((hDLL_DSEXT == NULL)||(!Dll_Transform)) { return -1; }
	else { return Dll_Transform(DataHandle, ArrHandle, Column, Roof, Sole, P, Ind); }
}

long ArgTransform(OType DataHandle, OType ArrHandle, unsigned char Column, long Roof, long Sole, TArgTransform P, PProcess Ind){
	if ((hDLL_DSEXT == NULL)||(!Dll_ArgTransform)) { return -1; }
	else { return Dll_ArgTransform(DataHandle, ArrHandle, Column, Roof, Sole, P, Ind); }
}

long WinTransform(OType DataHandle, OType ArrHandle, unsigned char Column, long Roof, long Sole, unsigned char WinSize, TWinTransform P, float *MinV, float *MaxV, PProcess Ind){
	if ((hDLL_DSEXT == NULL)||(!Dll_WinTransform)) { return -1; }
	else { return Dll_WinTransform(DataHandle, ArrHandle, Column, Roof, Sole, WinSize, P, MinV, MaxV, Ind); }
}

unsigned short ObjDialogDLL(const char *Title,OType ObjHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_ObjDialogDLL)) { return 0; }
	else { return Dll_ObjDialogDLL(Title,ObjHandle); }
};

unsigned short ObjDlgDLL(const char *Title,OType DataHandle,OType ObjHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_ObjDlgDLL)) { return 0; }
	else { return Dll_ObjDlgDLL(Title,DataHandle,ObjHandle); }
};

unsigned short Tbl_Dlg(const char *aTitle,OType *PDObj,OType TDPtr){
	if ((hDLL_DSEXT == NULL)||(!Dll_Tbl_Dlg)) { return 0; }
	else { return Dll_Tbl_Dlg(aTitle,PDObj,TDPtr); }
}

unsigned short ArrDialog(const char *ATitle,OType ArrD,OType ANewArr,unsigned char WinSize,unsigned char FieldWidth,float Start,float Step){
	if ((hDLL_DSEXT == NULL)||(!Dll_ArrDialog)) { return 0; }
	else { return Dll_ArrDialog(ATitle,ArrD,ANewArr,WinSize,FieldWidth,Start,Step); }
}

unsigned short ArrDialogNew(const char *ATitle,OType ArrD,OType ANewArr,unsigned char WinSize,unsigned char FieldWidth,float Start,float Step,long StartNumber,unsigned char StartColumn){
	if ((hDLL_DSEXT == NULL)||(!Dll_ArrDialogNew)) { return 0; }
	else { return Dll_ArrDialogNew(ATitle,ArrD,ANewArr,WinSize,FieldWidth,Start,Step,StartNumber,StartColumn); }
}

unsigned short SArrDialog(const char *ATitle,OType ArrHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_SArrDialog)) { return 0; }
	else { return Dll_SArrDialog(ATitle,ArrHandle); }
}

unsigned short SArrDialogNew(const char *ATitle,OType ArrHandle,long StartNumber,unsigned char StartColumn){
	if ((hDLL_DSEXT == NULL)||(!Dll_SArrDialogNew)) { return 0; }
	else { return Dll_SArrDialogNew(ATitle,ArrHandle,StartNumber,StartColumn); }
}

unsigned short ArrDialogD(const char *ATitle, OType ArrD, OType ANewArr, OType SysData,
           unsigned char WinSize, unsigned char FieldWidth, float aStartValue, float aStepValue)
{
	if ((hDLL_DSEXT == NULL)||(!Dll_ArrDialogD)) { return 0; }
	else { return Dll_ArrDialogD(ATitle,ArrD,ANewArr,SysData,WinSize,FieldWidth,aStartValue,aStepValue); }
}

unsigned short ChoiceObjByKey(OType LF,unsigned char Width,unsigned short *RowNumber,LongBoolean Force,OType *O){
	if ((hDLL_DSEXT == NULL)||(!Dll_ChoiceObjByKey)) { return 0; }
	else { return Dll_ChoiceObjByKey( LF,Width,RowNumber,Force,O); }
}

void SelectString(const char *Title,const char *Prompt,void *List,unsigned short *RowNumber,LongBoolean Selectable,LongBoolean ForceSelect,char *Res){
	if ((hDLL_DSEXT == NULL)||(!Dll_SelectString)) {  }
	else { Dll_SelectString(Title,Prompt,List,RowNumber,Selectable,ForceSelect,Res); }
}

void* SelectSetOfString(const char *Title,void *AimList,void *SelList){
	if ((hDLL_DSEXT == NULL)||(!Dll_SelectSetOfString)) { return NULL; }
	else { return Dll_SelectSetOfString(Title,AimList,SelList); }
};

short ChoiceLogRec(const char *TableList,long Mode,OType LFileHandle,OType *LRHandle,LongBoolean NewTable,LongBoolean ForceSelect){
	if ((hDLL_DSEXT == NULL)||(!Dll_ChoiceLogRec)) { return -1; }
	else { return Dll_ChoiceLogRec(TableList,Mode,LFileHandle,LRHandle,NewTable,ForceSelect); }
};

void* GetSetObjIdn(OType LF,unsigned short Width,void *OldList,LongBoolean MultiSel){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetSetObjIdn)) { return NULL; }
	else { return Dll_GetSetObjIdn( LF,Width,OldList,MultiSel); }
};

void* LogRecGetKeyContent(OType LRHandle,unsigned char AWidth){
	if ((hDLL_DSEXT == NULL)||(!Dll_LogRecGetKeyContent)) { return NULL; }
	else { return Dll_LogRecGetKeyContent( LRHandle,AWidth); }
};

short ChoiceArrayByName(OType ObjHandle,OType *ArrHandle,char *ArrayName,unsigned short *BegLine){
	if ((hDLL_DSEXT == NULL)||(!Dll_ChoiceArrayByName)) { return -1; }
	else { return Dll_ChoiceArrayByName( ObjHandle,ArrHandle,ArrayName,BegLine); }
};

short ChoiceColumnName(OType ArrHandle,char *ColumnName,unsigned char *ColumnNumber,unsigned short *BegLine){
	if ((hDLL_DSEXT == NULL)||(!Dll_ChoiceColumnName)) { return -1; }
	else { return Dll_ChoiceColumnName( ArrHandle,ColumnName,ColumnNumber,BegLine); }
};

void* GetColumnList(OType ArrayHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetColumnList)) { return NULL; }
	else { return Dll_GetColumnList( ArrayHandle); }
};

/*
void* GetInputLine(RECT R,unsigned char RC,char *Min,char *Max,unsigned char ALen,unsigned char Dec){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetInputLine)) { return NULL; }
	else { return Dll_GetInputLine( R,RC,Min,Max,ALen,Dec); }
};
*/

short ChoiceTDesc(const char *ResFileName,OType *TDescHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_ChoiceTDesc)) { return -1; }
	else { return Dll_ChoiceTDesc(ResFileName,TDescHandle); }
};

void ShowH(RECT R,OType *aDataObj,const char *Title,const char *ArrayName,const char *UnitName,unsigned short Option){
	if ((hDLL_DSEXT == NULL)||(!Dll_ShowH)) {  }
	else { Dll_ShowH( R,aDataObj,Title,ArrayName,UnitName,Option); }
};

void ShowHEx(RECT R,OType *aDataObj,const char *Title,const char *ArrayName,const char *UnitName,unsigned short Option,unsigned short XOption,unsigned short YOption,unsigned char Column){
	if ((hDLL_DSEXT == NULL)||(!Dll_ShowHEx)) {  }
	else { Dll_ShowHEx( R,aDataObj,Title,ArrayName,UnitName,Option,XOption,YOption,Column); }
};

void ShowVertObj(OType* aDataObj, const char* ArrayName){
	if ((hDLL_DSEXT == NULL)||(!Dll_ShowVertObj)) {  }
	else { Dll_ShowVertObj(aDataObj,ArrayName); }
}

void SelectDir(char* Dir){
	if ((hDLL_DSEXT == NULL)||(!Dll_SelectDir)) {  }
	else { Dll_SelectDir(Dir); }
};

unsigned short InputString(const char* Title, const char* aLabel, unsigned short Len, char* Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_InputString)) { return 0; }
	else { return Dll_InputString(Title,aLabel,Len,Value); }
};

unsigned short InputSingle(const char* Title, const char* aLabel, float Min, float Max, float* Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_InputSingle)) { return 0; }
	else { return Dll_InputSingle(Title,aLabel,Min,Max,Value); }
}

unsigned short InputWord(const char* Title, const char* aLabel, unsigned short Min, unsigned short Max, unsigned short* Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_InputWord)) { return 0; }
	else { return Dll_InputWord(Title,aLabel,Min,Max,Value); }
}

unsigned short SelectTwo(const char* Title, const char* aLabel1, const char* aLabel2, unsigned short* Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_SelectTwo)) { return 0; }
	else { return Dll_SelectTwo(Title,aLabel1,aLabel2,Value); }
}

unsigned short InputJoint(const char* Title, const char* LabelW1, const char* LabelW2, const char* LabelS,
  unsigned short MinW, unsigned short MaxW, float MinS, float MaxS,
  unsigned short* ValueW1, unsigned short* ValueW2, float* ValueS){
	if ((hDLL_DSEXT == NULL)||(!Dll_InputJoint)) { return 0; }
	else { return Dll_InputJoint(Title,LabelW1,LabelW2,LabelS,MinW,MaxW,MinS,MaxS,ValueW1,ValueW2,ValueS); }
}

unsigned short OperateDataObj(OType* Data, char* ResFName, char* LoadFName, char* Selected_Aim,
  unsigned short* RowNumber, LongBoolean Selectable, void** ObjColl, void** IdnColl,
  unsigned short LROption, unsigned short ObjOption, OType* O){
	if ((hDLL_DSEXT == NULL)||(!Dll_OperateDataObj)) { return 0; }
	else { return Dll_OperateDataObj(Data,ResFName,LoadFName,Selected_Aim,RowNumber,Selectable,ObjColl,IdnColl,LROption,ObjOption,O); }
}

unsigned short TempOperateDataObj(OType* Data, char* ResFName, char* LoadFName, char* Selected_Aim,
  unsigned short* RowNumber, LongBoolean Selectable, void** ObjColl, void** IdnColl,
  unsigned short LROption, unsigned short ObjOption, OType* O){
	if ((hDLL_DSEXT == NULL)||(!Dll_TempOperateDataObj)) { return 0; }
	else { return Dll_TempOperateDataObj(Data,ResFName,LoadFName,Selected_Aim,RowNumber,Selectable,ObjColl,IdnColl,LROption,ObjOption,O); }
}

void StartLongProcess(const char* Msg, long AMin, long AMax){
	if ((hDLL_DSEXT == NULL)||(!Dll_StartLongProcess)) {  }
	else { Dll_StartLongProcess(Msg,AMin,AMax); }
}

void LongProcessBack(long Pos){
	if ((hDLL_DSEXT == NULL)||(!Dll_LongProcessBack)) {  }
	else { Dll_LongProcessBack(Pos); }
}

void StopLongProcess(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_StopLongProcess)) {  }
	else { Dll_StopLongProcess(); }
}

LongBoolean LongProcessCancelled(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_LongProcessCancelled)) { return false; }
	else { return Dll_LongProcessCancelled(); }
}

void GetFilename(const char *AWildCard,const char *ATitle,char *FileName){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetFilename)) {  }
	else { Dll_GetFilename(AWildCard,ATitle,FileName); }
}

void GetColumnName(OType ArrHandle,unsigned char Column,char *ColName){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetColumnName)) {  }
	else { Dll_GetColumnName(ArrHandle,Column,ColName); }
}

long D_GetFDFactor(const char *ModuleName,OType TDescHandle,const char *FDName,const char *FDUnit,float *Factor){
	if ((hDLL_DSEXT == NULL)||(!Dll_D_GetFDFactor)) { return -1; }
	else { return Dll_D_GetFDFactor(ModuleName,TDescHandle,FDName,FDUnit,Factor); }
}

long D_GetFDNFactor(const char *ModuleName,OType TDescHandle,long Index,const char *FDUnit,float *Factor){
	if ((hDLL_DSEXT == NULL)||(!Dll_D_GetFDNFactor)) { return -1; }
	else { return Dll_D_GetFDNFactor(ModuleName,TDescHandle,Index,FDUnit,Factor); }
}

LongBoolean GetFULongInt(OType A,const char *Name,const char *UnitName,long *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetFULongInt)) { return false; }
	else { return Dll_GetFULongInt(A,Name,UnitName,R); }
}

LongBoolean GetFUSingle(OType A,const char *Name,const char *UnitName,float *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetFUSingle)) { return false; }
	else { return Dll_GetFUSingle(A,Name,UnitName,R); }
}

LongBoolean GetFUString(OType A,const char *Name,const char *UnitName,char *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetFUString)) { return false; }
	else { return Dll_GetFUString(A,Name,UnitName,R); }
}

LongBoolean PutFULongInt(OType A,const char *Name,const char *UnitName,long R){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFULongInt)) { return false; }
	else { return Dll_PutFULongInt(A,Name,UnitName,R); }
}

LongBoolean PutFUSingle(OType A,const char *Name,const char *UnitName,float R){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFUSingle)) { return false; }
	else { return Dll_PutFUSingle(A,Name,UnitName,R); }
}

LongBoolean PutFUString(OType A,const char *Name,const char *UnitName,const char *R){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutFUString)) { return false; }
	else { return Dll_PutFUString(A,Name,UnitName,R); }
}

short Save_WSExR(const char *Selected_Aim, const char *TName, const char *SaveFName,
  LongBoolean CheckThisCopy, OType ObjHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_Save_WSExR)) { return -1; }
	else { return Dll_Save_WSExR(Selected_Aim,TName,SaveFName,CheckThisCopy,ObjHandle); }
}

long CreateLayerCurve(OType hSrcObj,OType hSrcArr,unsigned char ucSrcCol,
  OType hInterArr,const char *lpTranslateStr,OType hDestObj,OType hDestArr,
  unsigned char ucDestCol,long Flags){
	if ((hDLL_DSEXT == NULL)||(!Dll_CreateLayerCurve)) { return -1; }
	else { return Dll_CreateLayerCurve(hSrcObj,hSrcArr,ucSrcCol,hInterArr,
          lpTranslateStr,hDestObj,hDestArr,ucDestCol,Flags); }
}

void ResDialog(const char *lpResFileName, const char *lpTablName){
	if ((hDLL_DSEXT == NULL)||(!Dll_ResDialog)) {  }
	else { Dll_ResDialog(lpResFileName,lpTablName); }
}

void *GetNewClsList(const char *lpClsName){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNewClsList)) { return NULL; }
	else { return Dll_GetNewClsList(lpClsName); }
}

long DoFuncDic(const char *InputStr, const char *FlName, const char *DicWSName,
           OType WSBase, OType DataObj, char *OutStr,
           long OutStrLen){
	if ((hDLL_DSEXT == NULL)||(!Dll_DoFuncDic)) { return -1; }
	else { return Dll_DoFuncDic(InputStr,FlName,DicWSName,WSBase,DataObj,
          OutStr,OutStrLen); }
}

short GetDicObj(const char *DicWSName, const char *TablName, const char *DicName,
           OType *DicObj){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetDicObj)) { return -1; }
	else { return Dll_GetDicObj(DicWSName,TablName,DicName,DicObj); }
}

long GetNewName(const char *OldName, OType DicObj, unsigned char Col1, unsigned char Col2,
           char *OutStr, long OutStrLen){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetNewName)) { return -1; }
	else { return Dll_GetNewName(OldName,DicObj,Col1,Col2,OutStr,OutStrLen); }
}

unsigned short Tbl(const char *lpszTitle, OType *lphObj, OType hSysData, OType hTD,
           const char *lpszTableName, short wReserved){
	if ((hDLL_DSEXT == NULL)||(!Dll_Tbl)) { return -1; }
	else { return Dll_Tbl(lpszTitle,lphObj,hSysData,hTD,lpszTableName,wReserved); }
}

long GetKDataObj(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, OType *Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetKDataObj)) { return -1; }
	else { return Dll_GetKDataObj(K_BaseName,TableName,Region,Field,Plast,Name,Value); }
}

long GetKDataS(const char *K_BaseName, const char* TableName,const char *Region, const char *Field,
           const char *Plast, const char *Name, char *Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetKDataS)) { return -1; }
	else { return Dll_GetKDataS(K_BaseName,TableName,Region,Field,Plast,Name,Value); }
}

long GetKDataR(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, float *Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetKDataR)) { return -1; }
	else { return Dll_GetKDataR(K_BaseName,TableName,Region,Field,Plast,Name,Value); }
}

long PutKDataS(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, const char *Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutKDataS)) { return -1; }
	else { return Dll_PutKDataS(K_BaseName,TableName,Region,Field,Plast,Name,Value); }
}

long PutKDataR(const char *K_BaseName, const char* TableName, const char *Region, const char *Field,
           const char *Plast, const char *Name, float Value){
	if ((hDLL_DSEXT == NULL)||(!Dll_PutKDataR)) { return -1; }
	else { return Dll_PutKDataR(K_BaseName,TableName,Region,Field,Plast,Name,Value); }
}

TTwoDWindow TwoDWndCreate(const char* lpWindowName, float fArgMin, float fStep,
  long dwPointCount, long dwFuncCount, float fArgStart, float fArgStop,
  long dwArgLineCount, float fFuncMin, float fFuncMax,
  long dwFuncLineCount, const char* lpFuncPrefix, const char* lpArgUnitName,
  const char* lpFuncUnitName, long dwFlags){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndCreate)) { return NULL; }
	else { return Dll_TwoDWndCreate(lpWindowName, fArgMin, fStep, dwPointCount,
                 dwFuncCount, fArgStart, fArgStop, dwArgLineCount,
                 fFuncMin, fFuncMax, dwFuncLineCount, lpFuncPrefix,
                 lpArgUnitName, lpFuncUnitName, dwFlags); }
}

TTwoDWindow TwoDWndCreateByDataHandle(OType hObj, OType hArr,
  const char* lpWindowName, long dwFlags){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndCreateByDataHandle)) { return NULL; }
	else { return Dll_TwoDWndCreateByDataHandle(hObj, hArr,
                 lpWindowName, dwFlags); }
}

HWND TwoDWndGetHandle(TTwoDWindow TwoDWindow){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndGetHandle)) { return NULL; }
	else { return Dll_TwoDWndGetHandle(TwoDWindow); }
}

LongBoolean TwoDWndShow(TTwoDWindow TwoDWindow, LongBoolean bShow){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndShow)) { return false; }
	else { return Dll_TwoDWndShow(TwoDWindow, bShow); }
}

long TwoDWndShowModal(TTwoDWindow TwoDWindow){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndShowModal)) { return -1; }
	else { return Dll_TwoDWndShowModal(TwoDWindow); }
}

LongBoolean TwoDWndSetRect(TTwoDWindow TwoDWindow, const RECT* lprcBounds){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndSetRect)) { return false; }
	else { return Dll_TwoDWndSetRect(TwoDWindow, lprcBounds); }
}

LongBoolean TwoDWndSetCallback_CloseWindow(TTwoDWindow TwoDWindow,
  long dwCookie, TTwoDCloseWindowCallback lpFunc){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndSetCallback_CloseWindow)) { return false; }
	else { return Dll_TwoDWndSetCallback_CloseWindow(TwoDWindow, dwCookie, lpFunc); }
}

LongBoolean TwoDWndSetData(TTwoDWindow TwoDWindow, float *lpfData,
  long dwDataCount, long dwFuncIndex){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndSetData)) { return false; }
	else { return Dll_TwoDWndSetData(TwoDWindow, lpfData, dwDataCount, dwFuncIndex); }
}

LongBoolean TwoDWndGetData(TTwoDWindow TwoDWindow, float *lpfData,
  long dwDataCount, long dwFuncIndex){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndGetData)) { return false; }
	else { return Dll_TwoDWndGetData(TwoDWindow, lpfData, dwDataCount, dwFuncIndex); }
}

LongBoolean TwoDWndGetAreaDisplayParams(TTwoDWindow TwoDWindow,
  long dwReserved, THGraphAreaRec *dp){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndGetAreaDisplayParams)) { return false; }
	else { return Dll_TwoDWndGetAreaDisplayParams(TwoDWindow, dwReserved, dp); }
}

LongBoolean TwoDWndSetAreaDisplayParams(TTwoDWindow TwoDWindow,
  long dwReserved, const THGraphAreaRec *dp){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndSetAreaDisplayParams)) { return false; }
	else { return Dll_TwoDWndSetAreaDisplayParams(TwoDWindow, dwReserved, dp); }
}

LongBoolean TwoDWndDestroy(TTwoDWindow TwoDWindow){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDWndDestroy)) { return false; }
	else { return Dll_TwoDWndDestroy(TwoDWindow); }
}

LongBoolean TwoDControlWndShow(LongBoolean bShow){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDControlWndShow)) { return false; }
	else { return Dll_TwoDControlWndShow(bShow); }
}

LongBoolean AddWin2dToControlWindow(TTwoDWindow TwoDWindow){
	if ((hDLL_DSEXT == NULL)||(!Dll_AddWin2dToControlWindow)) { return false; }
	else { return Dll_AddWin2dToControlWindow(TwoDWindow); }
}

LongBoolean TwoDControlWndSetCallback_CloseWindow(long dwCookie,
  TTwoDCloseControlWindowCallback lpFunc){
	if ((hDLL_DSEXT == NULL)||(!Dll_TwoDControlWndSetCallback_CloseWindow)) { return false; }
	else { return Dll_TwoDControlWndSetCallback_CloseWindow(dwCookie, lpFunc); }
}

long AnsiLasLineNew(const char *lpOriginStr, const char *lpDicWSName, char *lpBlankValue, long nBlankValueSize,
  long *lpdwPosM, OType hDataObj, OType hLogFile, long dwRoof, long dwSole, long dwStep,
  char *lpLasLine, long nLasLineSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiLasLineNew)) { return -1; }
	else { return Dll_AnsiLasLineNew(lpOriginStr, lpDicWSName, lpBlankValue, nBlankValueSize,
                    lpdwPosM, hDataObj, hLogFile, dwRoof, dwSole, dwStep, lpLasLine, nLasLineSize); }
}

long AnsiGetFuncStr(char *lpInputStr, long nInputStrSize, unsigned short *lpwErrCode, char *lpFuncStr, long nFuncStrSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetFuncStr)) { return -1; }
	else { return Dll_AnsiGetFuncStr(lpInputStr, nInputStrSize, lpwErrCode, lpFuncStr, nFuncStrSize); }
}

long AnsiGetWord(char *lpInputStr, long nInputStrSize, unsigned short *lpwErrCode, char *lpWord, long nWordSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetWord)) { return -1; }
	else { return Dll_AnsiGetWord(lpInputStr, nInputStrSize, lpwErrCode, lpWord, nWordSize); }
}

long AnsiRemovePar(const char *lpInStr, char cMark, unsigned short wOption, char *lpResultStr, long nResultStrSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiRemovePar)) { return -1; }
	else { return Dll_AnsiRemovePar(lpInStr, cMark, wOption, lpResultStr, nResultStrSize); }
}

long AnsiGetWSValue(const char *lpReference, short *lpsError, char *lpWSValue, long nWSValueSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetWSValue)) { return -1; }
	else { return Dll_AnsiGetWSValue(lpReference, lpsError, lpWSValue, nWSValueSize); }
}

long AnsiGetTableValue(const char *lpReference, OType hWSBase, short *lpsError, char *lpTableValue, long nTableValueSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetTableValue)) { return -1; }
	else { return Dll_AnsiGetTableValue(lpReference, hWSBase, lpsError, lpTableValue, nTableValueSize); }
}

long AnsiGetObjValue(const char *lpReference, OType hDataHandle, short *lpsError, char *lpObjValue, long nObjValueSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetObjValue)) { return -1; }
	else { return Dll_AnsiGetObjValue(lpReference, hDataHandle, lpsError, lpObjValue, nObjValueSize); }
}

long AnsiUpdateStrC(const char *lpInStr, OType hLogFile, char *lpOut, long nOutSize, const char *lpDicWSName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiUpdateStrC)) { return -1; }
	else { return Dll_AnsiUpdateStrC(lpInStr, hLogFile, lpOut, nOutSize, lpDicWSName); }
}

long AnsiUpdateStrCData(const char *lpInStr, OType hLogFile, OType hDataHandle, char *lpOut, long nOutSize, const char *lpDicWSName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiUpdateStrCData)) { return -1; }
	else { return Dll_AnsiUpdateStrCData(lpInStr, hLogFile, hDataHandle, lpOut, nOutSize, lpDicWSName); }
}

long AnsiDoFuncDic(const char *lpInputStr, const char *lpFlName, const char *lpDicWSName, OType hWSBase, OType hDataObj, char *lpFuncRes, long nFuncResSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiDoFuncDic)) { return -1; }
	else { return Dll_AnsiDoFuncDic(lpInputStr, lpFlName, lpDicWSName, hWSBase, hDataObj, lpFuncRes, nFuncResSize); }
}

short AnsiGetDicObj(const char *lpDicWSName, const char *lpTablName, const char *lpDicName, OType *lphDicObj){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetDicObj)) { return -1; }
	else { return Dll_AnsiGetDicObj(lpDicWSName, lpTablName, lpDicName, lphDicObj); }
}

long AnsiGetNewName(const char *lpOldName, OType hDicObj, unsigned char nCol1, unsigned char nCol2, char *lpNewName, long nNewNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetNewName)) { return -1; }
	else { return Dll_AnsiGetNewName(lpOldName, hDicObj, nCol1, nCol2, lpNewName, nNewNameSize); }
}

long AnsiGetToken(const char *lpP, long *lpdwI, char *lpToken, long nTokenSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetToken)) { return -1; }
	else { return Dll_AnsiGetToken(lpP, lpdwI, lpToken, nTokenSize); }
}

long AnsiGetFuncDicName(const char *lpInputStr, const char *lpFlName, const char *lpDicWSName, OType hDataObj, char *lpFuncDicName, long nFuncDicNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetFuncDicName)) { return -1; }
	else { return Dll_AnsiGetFuncDicName(lpInputStr, lpFlName, lpDicWSName, hDataObj, lpFuncDicName, nFuncDicNameSize); }
}

void AnsiSetCurrWSName(const char *lpWSName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrWSName)) { return; }
	else { Dll_AnsiSetCurrWSName(lpWSName); }
}

void AnsiSetCurrTablName(const char *lpTablName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrTablName)) { return; }
	else { Dll_AnsiSetCurrTablName(lpTablName); }
}

void AnsiSetCurrObjName(const char *lpObjName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrObjName)) { return; }
	else { Dll_AnsiSetCurrObjName(lpObjName); }
}

void AnsiSetCurrRecName(const char *lpRecName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrRecName)) { return; }
	else { Dll_AnsiSetCurrRecName(lpRecName); }
}

void AnsiSetCurrArrName(const char *lpArrName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrArrName)) { return; }
	else { Dll_AnsiSetCurrArrName(lpArrName); }
}

void AnsiSetCurrArrColName(const char *lpArrColumn){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrArrColName)) { return; }
	else { Dll_AnsiSetCurrArrColName(lpArrColumn); }
}

void AnsiSetCurrObValName(const char *lpObValName){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrObValName)) { return; }
	else { Dll_AnsiSetCurrObValName(lpObValName); }
}

void AnsiSetCurrArrColNumber(unsigned char nColumn){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrArrColNumber)) { return; }
	else { Dll_AnsiSetCurrArrColNumber(nColumn); }
}

void AnsiSetCurrBaseHandle(OType hBaseHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrBaseHandle)) { return; }
	else { Dll_AnsiSetCurrBaseHandle(hBaseHandle); }
}

void AnsiSetCurrTablHandle(OType hTablHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrTablHandle)) { return; }
	else { Dll_AnsiSetCurrTablHandle(hTablHandle); }
}

void AnsiSetCurrObjHandle(OType hObjHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrObjHandle)) { return; }
	else { Dll_AnsiSetCurrObjHandle(hObjHandle); }
}

void AnsiSetCurrArrHandle(OType hArrHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrArrHandle)) { return; }
	else { Dll_AnsiSetCurrArrHandle(hArrHandle); }
}

void AnsiSetCurrObValHandle(OType hObValHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetCurrObValHandle)) { return; }
	else { Dll_AnsiSetCurrObValHandle(hObValHandle); }
}

OType AnsiGetCurrBaseHandle(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrBaseHandle)) { return hNil; }
	else { return Dll_AnsiGetCurrBaseHandle(); }
}

OType AnsiGetCurrTablHandle(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrTablHandle)) { return hNil; }
	else { return Dll_AnsiGetCurrTablHandle(); }
}

OType AnsiGetCurrObjHandle(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrObjHandle)) { return hNil; }
	else { return Dll_AnsiGetCurrObjHandle(); }
}

OType AnsiGetCurrArrHandle(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrArrHandle)) { return hNil; }
	else { return Dll_AnsiGetCurrArrHandle(); }
}

unsigned char AnsiGetCurrArrColNumber(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrArrColNumber)) { return 0; }
	else { return Dll_AnsiGetCurrArrColNumber(); }
}

OType AnsiGetCurrObValHandle(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrObValHandle)) { return hNil; }
	else { return Dll_AnsiGetCurrObValHandle(); }
}

long AnsiGetCurrWSName(char *lpCurrWSName, long nCurrWSNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrWSName)) { return -1; }
	else { return Dll_AnsiGetCurrWSName(lpCurrWSName, nCurrWSNameSize); }
}

long AnsiGetCurrTablName(char *lpTableName, long nTableNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrTablName)) { return -1; }
	else { return Dll_AnsiGetCurrTablName(lpTableName, nTableNameSize); }
}

long AnsiGetCurrObjName(char *lpObjName, long nObjNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrObjName)) { return -1; }
	else { return Dll_AnsiGetCurrObjName(lpObjName, nObjNameSize); }
}

long AnsiGetCurrRecName(char *lpRecName, long nRecNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrRecName)) { return -1; }
	else { return Dll_AnsiGetCurrRecName(lpRecName, nRecNameSize); }
}

long AnsiGetCurrArrName(char *lpArrName, long nArrNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrArrName)) { return -1; }
	else { return Dll_AnsiGetCurrArrName(lpArrName, nArrNameSize); }
}

long AnsiGetCurrObValName(char *lpObValName, long nObValNameSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetCurrObValName)) { return -1; }
	else { return Dll_AnsiGetCurrObValName(lpObValName, nObValNameSize); }
}

LongBoolean AnsiSetRowDelimiter(const char *lpValue){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetRowDelimiter)) { return false; }
	else { return Dll_AnsiSetRowDelimiter(lpValue); }
}

long AnsiGetRowDelimiter(char *lpValue, long nValueSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetRowDelimiter)) { return -1; }
	else { return Dll_AnsiGetRowDelimiter(lpValue, nValueSize); }
}

LongBoolean AnsiSetColDelimiter(const char *lpValue){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiSetColDelimiter)) { return false; }
	else { return Dll_AnsiSetColDelimiter(lpValue); }
}

long AnsiGetColDelimiter(char *lpValue, long nValueSize){
	if ((hDLL_DSEXT == NULL)||(!Dll_AnsiGetColDelimiter)) { return -1; }
	else { return Dll_AnsiGetColDelimiter(lpValue, nValueSize); }
}

void InitTableObjCache(OType hWSFile){
	if ((hDLL_DSEXT == NULL)||(!Dll_InitTableObjCache)) { return; }
	else { Dll_InitTableObjCache(hWSFile); }
}

void DestroyTableObjCache(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_DestroyTableObjCache)) { return; }
	else { Dll_DestroyTableObjCache(); }
}

short GetCachedTableHandle(const char *lpName, OType hWSFile, long *lpdwCachedHandle){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetCachedTableHandle)) { return -1; }
	else { return Dll_GetCachedTableHandle(lpName, hWSFile, lpdwCachedHandle); }
}

short GetCachedTableObjByIdN(long *dwCachedHandle, unsigned short wIdN, OType *lphObj){
	if ((hDLL_DSEXT == NULL)||(!Dll_GetCachedTableObjByIdN)) { return -1; }
	else { return Dll_GetCachedTableObjByIdN(dwCachedHandle, wIdN, lphObj); }
}

void DisableTableObjCache(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_DisableTableObjCache)) { return; }
	else { Dll_DisableTableObjCache(); }
}

void EnableTableObjCache(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_EnableTableObjCache)) { return; }
	else { Dll_EnableTableObjCache(); }
}

LongBoolean IsTableObjCacheEnabled(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_IsTableObjCacheEnabled)) { return false; }
	else { return Dll_IsTableObjCacheEnabled(); }
}

char *StdDepthUnit(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_StdDepthUnit)) { return NULL; }
	else { return Dll_StdDepthUnit(); }
}

TMinimalDepthUnit StdDepthUnitOfInstance(HINSTANCE hInstDLL){
	if ((hDLL_DSEXT == NULL)||(!Dll_StdDepthUnitOfInstance)) { return mduUnknown; }
	else { return Dll_StdDepthUnitOfInstance(hInstDLL); }
}

void TemporarySetNewDepthUnit(const char *lpszUnitName, void *lpReserved){
	if ((hDLL_DSEXT == NULL)||(!Dll_TemporarySetNewDepthUnit)) { return; }
	else { Dll_TemporarySetNewDepthUnit(lpszUnitName, lpReserved); }
}

char *StdUserDepthUnit(void){
	if ((hDLL_DSEXT == NULL)||(!Dll_StdUserDepthUnit)) { return NULL; }
	else { return Dll_StdUserDepthUnit(); }
}

TUserDepthUnit UserDepthUnitOfInstance(HINSTANCE hInstDLL){
	if ((hDLL_DSEXT == NULL)||(!Dll_UserDepthUnitOfInstance)) { return uduUnknown; }
	else { return Dll_UserDepthUnitOfInstance(hInstDLL); }
}

void TemporarySetNewUserDepthUnit(const char *lpszUnitName, void *lpReserved){
	if ((hDLL_DSEXT == NULL)||(!Dll_TemporarySetNewUserDepthUnit)) { return; }
	else { Dll_TemporarySetNewUserDepthUnit(lpszUnitName, lpReserved); }
}

void DSExtUpdateInstanceData(HINSTANCE hInstDLL, void *lpReserved){
	if ((hDLL_DSEXT == NULL)||(!Dll_DSExtUpdateInstanceData)) { return; }
	else { Dll_DSExtUpdateInstanceData(hInstDLL, lpReserved); }
}

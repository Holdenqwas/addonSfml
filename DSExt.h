/***************************************************************************\
*                                                                           *
* Система информационного обеспечения геофизических исследований скважин    *
*   "ПРАЙМ" для Windows                                                     *
* Библиотека расширений функций сервера данных                              *
* Язык: C++                                                                 *
* Версия: 1.12                                                              *
* (C) НПФ ГеоТЭК, 1999 - 2009                                               *
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
*    ИНТЕРФЕЙС ПРОГРАММИСТА                                                   *
*                                                                             *
\*****************************************************************************/

/*****************************************************************************\
* КОНСТАНТЫ                                                                   *
\*****************************************************************************/

extern char *DepthString; /* Название колонки глубин в массиве */
extern char *DepthUnit;   /* Единица измерения глубин в Системе */
extern char *DepthShift;  /* Название поля для суммарного сдвига по глубине */

/* Флаги для CreateLayerCurve */
const long clcSrcBed         = 0x00000001; /* Исходные данные - попластовые */
const long clcTranslateFirst = 0x00000002; /* Сначала перекодировать */
const long clcUniteEqual     = 0x00000004; /* Объединять пласты с одинаковыми кодами */


/* Константы и типы для горизонтальной графики */

typedef void* TTwoDWindow; /* Окно горизонтальной графики */

const int hgMaxArrCols = 32; /* Макс. количество колонок массива,
                                которые могут быть отображены */
const int hgMaxFontNameLen = 64; /* Размер строки, отводимой под название шрифта */
const long hgAllCols = 0xFFFFFFFF; /* Маска для отображения всех колонок */

/* Флаги отображения области в горизонтальном графике */
const long hgafCommonNet        = 0x00000001; /* Общая сетка для всех кривых */
const long hgafDrawAxes         = 0x00000002; /* Рисовать линии сеток */
const long hgafDrawLabels       = 0x00000004; /* Рисовать риски */
const long hgafDisableArgLabels = 0x00000008; /* Не рисовать риски аргумента */
const long hgafUseArgParams     = 0x00000010; /* Задать параметры дискретизации
                                                 аргумента вручную */
const long hgafUseFuncParams    = 0x00000020; /* Задать параметры дискретизации
                                                 функций вручную */

typedef long TCols; /* Маска разрешения колонок массива */

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
* CALLBACK - ФУНКЦИИ                                                          *
\*****************************************************************************/

/* Для горизонтальной графики */

typedef LongBoolean (__stdcall *TTwoDCloseWindowCallback)(TTwoDWindow Window, long dwCookie);
typedef LongBoolean (__stdcall *TTwoDCloseControlWindowCallback)(long dwCookie);

/* Другие */

typedef void (__stdcall *PProcess)(long Min, long Val, long Max);
typedef float (__stdcall *TTransform)(float Y);
typedef float(__stdcall *TArgTransform)(float X, float Y);
typedef float (__stdcall *TWinTransform)(float *X, long XLastIndex, float *Y, long YLastIndex, unsigned short Count, unsigned short Index);
typedef void (__stdcall *TStartTransform)();
typedef void (__stdcall *TCrvTransform)(float X);
typedef float (__stdcall *TGetTransform)();

// Минимальная единица измерения глубины, с которой работает библиотека
typedef unsigned char TMinimalDepthUnit;

const TMinimalDepthUnit mduUnknown  = 0; // Неизвестно
const TMinimalDepthUnit mduCm       = 1; // Сантиметры (по умолчанию)
const TMinimalDepthUnit mduPU       = 2; // Десятые доли миллиметра
const TMinimalDepthUnit mduInch     = 3; // Дюймы
const TMinimalDepthUnit mduHalfInch = 4; // Полудюймы

// Пользовательская единица измерения глубины
typedef unsigned char TUserDepthUnit;

const TUserDepthUnit uduUnknown = 0; // Неизвестно
const TUserDepthUnit uduMeter   = 1; // Метры (по умолчанию)
const TUserDepthUnit uduFoot    = 2; // Футы
const TUserDepthUnit uduInch    = 3; // Дюймы
const TUserDepthUnit uduYard    = 4; // Ярды

/*****************************************************************************\
* ОПЕРАЦИИ С ВНЕШНИМ МОДУЛЕМ                                                  *
\*****************************************************************************/

/* Загрузить модуль*/
extern "C" LongBoolean DSExtLoad(void);

/* Подключиться к модулю уже загруженному в адресное пространство процесса */
extern "C" LongBoolean DSExtConnect(void);

/* Выгрузить модуль. Не нужно вызывать, если DSExt загружен вызовом DSExtConnect */
extern "C" void DSExtFree(void);

/*****************************************************************************\
* ДРУГИЕ ОПЕРАЦИИ                                                             *
\*****************************************************************************/

/* Системно-зависимая - получить HINSTANCE алгоритма */
HINSTANCE GetAlgHandle();
/* Системно-зависимая - получить каталог алгоритма (DLL) */
long GetAlgPath(char *Path, long MaxLen);
/* Системно-зависимая - получить каталог системы (EXE) */
long GetSystemPath(char *Path, long MaxLen);
/* Системно-зависимая - задать предка всех окон модуля */
void SetMainWndHandle(HWND WndHandle);

/* Получить значение элемента массива как long в переменную R
   по Handl'у массива A, индексу Index и имени колонки ColName
   Возвращает true, если нет ошибки и значение элемента массива не пусто */
LongBoolean GetNBALongInt(OType A, long Index, const char *ColName, long *R);

/* То же, но значение берётся как float */
LongBoolean GetNBASingle(OType A, long Index, const char *ColName, float *R);

/* То же, но значение берётся как строка (под R должно быть выделено 256 байт) */
LongBoolean GetNBAString(OType A, long Index, const char *ColName, char *R);

/* Та же группа функций, но значения берутся из поля Name строки с Handl'ом A */
LongBoolean GetNBFLongInt(OType A, const char *Name, long *R);
LongBoolean GetNBFSingle(OType A, const char *Name, float *R);
LongBoolean GetNBFString(OType A, const char *Name, char *R);
LongBoolean GetNBFStringLong(OType A, const char *Name, char *R, long RSize);

/* Те же 6 функций, но значения записываются в объект */
void PutArrayLongInt(OType A, long Index, const char *ColName, long V);
void xPutArraySingle(OType A, long Index, const char *ColName, float V);
void xPutArrayString(OType A, long Index, const char *ColName, const char *V);
void PutFieldLongInt(OType A, const char *Name, long V);
void PutFieldSingle(OType A, const char *Name, float V);
void PutFieldString(OType A, const char *Name, const char *V);

/* Запись значения поля по его индексу в строке (а не по имени) */
void PutFieldLongIntI(OType A, long Index, long V);
void PutFieldSingleI(OType A, long Index, float V);
void PutFieldStringI(OType A, long Index, const char *V);

/* Получить информацию о кривой по Handl'ам строки и массива в этой строке:
   (имеется в виду кривая DatServ, а не кривая планшета!)
   Column - номер (от 1) колонки глубин (если есть, иначе 0)
   Step - шаг дискретизации в см (если есть и ненулевой)
   (По крайней мере один из этих параметров должен вернуться
   с нетривиальным значением, чтобы кривая существовала)
   Roof, Sole - кровля и подошва в см */
long GetCurveInformation(OType DataHandle, OType ArrayHandle,
                             unsigned char *Column,
                             long *Step, long *Roof, long *Sole);

/* Возвращает в KeyStrLong (буфер должен иметь не менее 256 байт) строку
   ключевых полей строки, задаваемой Handl'ом DataHandle. В случае неудачи
   (или отсутствия ключевых полей) возвращается EmptyStr */
void DataKeyStrLong(const char *EmptyStr, OType DataHandle,
                    unsigned short RowNumber, char *KeyStrLong);

/* Возвращает номер точки в колонке массива, предшествующей указанному значению */
//long GetValueIndex(OType ArrayHandle, unsigned char Column, float Value);

/* То же самое - существенно быстрее, но только для монотонных значений */
//long GetMonValueIndex(OType ArrayHandle, unsigned char Column, float Value);

/* То же самое, но для двух точек */
//long GetInterIndex(OType ArrayHandle, unsigned char Column, float Roof, float Sole,
//                   long *RoofIndex, long *RoofSole);

/* То же самое, но для нескольких точек */
/* ValuesLastIndex = количество элементов в массиве Values минус 1 */
/* IndicesLastIndex = количество элементов в массиве Indices минус 1 */
/* Count - сколько точек надо */
//long GetArrayIndex(OType ArrayHandle, unsigned char Column, long Count,
//                   float *Values, long ValuesLastIndex,
//                   long *Indices, long IndicesLastIndex);

/* Получить/записать параметры дискретизации кривой - кровлю, подошву и шаг
   (если есть). В случае отсутствия только кровли либо только подошвы
   они вычисляются */
long GetField(OType DataHandle, OType ArrHandle, long *Roof, long *Sole, long *Step);
long SetField(OType DataHandle, OType ArrHandle, long Roof, long Sole, long Step);

/* Получить индекс в массиве по глубине (в см) */
long GetIndex(OType DataHandle, OType ArrayHandle, long Depth);

/* Сдвинуть массив вниз на глубину Delta (в см) (если Delta < 0, то, ясен перец,
   массив сдвигается вверх :) */
long ShiftDepth(OType DataHandle, OType ArrHandle, unsigned char ColNumber, long Delta, unsigned short Option);

/* Преобразовать значения в массиве (для кажд. элемента вызывается функция P
   и её результат запихивается в этот же элемент, опосля чего вызывается
   Ind, чтобы вызывающая функция знала, сколько ещё осталось считать) */
long Transform(OType DataHandle, OType ArrHandle, unsigned char Column,
               long Roof, long Sole, TTransform P, PProcess Ind);

/* То же, что и Transform (см.), только в P передаётся ещё аргумент */
long ArgTransform(OType DataHandle, OType ArrHandle, unsigned char Column,
                  long Roof, long Sole, TArgTransform P, PProcess Ind);

/* Это ваще крутая функция, её и задокументировать-то сложно :) */
long WinTransform(OType DataHandle, OType ArrHandle, unsigned char Column,
                  long Roof, long Sole, unsigned char WinSize, TWinTransform P,
                  float *MinV, float *MaxV, PProcess Ind);

/*Универсальное диалоговое окно для строки данных ObjHandle*/
unsigned short ObjDialogDLL(const char *Title,OType ObjHandle);
/*То же, с системой данных DataHandle*/
unsigned short ObjDlgDLL(const char *Title,OType DataHandle,OType ObjHandle);
/* Диалог для части или пустых данных */
unsigned short Tbl_Dlg(const char *aTitle,OType *PDObj,OType TDPtr);

/*Универсальное диалоговое окно для массива ANewArr, ArrD - описатель массива*/
/* Start-начальная глубина, Step-шаг кантования для показа глубины для каждой точки*/
unsigned short ArrDialog(const char *ATitle,OType ArrD,OType ANewArr,
  unsigned char WinSize,unsigned char FieldWidth,float Start,float Step);
/* То же самое, что ArrDialog, но встаёт на заданную ячейку */
unsigned short ArrDialogNew(const char* ATitle,OType ArrD,OType ANewArr,
  unsigned char WinSize,unsigned char FieldWidth,float Start,float Step,	// шаг для заполнения
  long StartNumber,unsigned char StartColumn);
/*Универсальное диалоговое окно для массива ArrHandle*/
unsigned short SArrDialog(const char* ATitle,OType ArrHandle);
/* То же самое, что SArrDialog, но встаёт на заданную ячейку */
unsigned short SArrDialogNew(const char* ATitle,OType ArrHandle,
  long StartNumber, unsigned short StartColumn);
/* Диалог массива с поддержкой частных списков. SysData - описатель ресурса со списками */
unsigned short ArrDialogD(const char *ATitle, OType ArrD, OType ANewArr, OType SysData,
  unsigned char WinSize, unsigned char FieldWidth, float aStartValue, float aStepValue);
/* Диалог для выбора строки O в таблице LF               */
/* Если RowNumber > 0, то строка возвращается без диалога*/
unsigned short ChoiceObjByKey(OType LF,unsigned char Width,unsigned short *RowNumber,LongBoolean Force,OType *O);
/*Диалог для выбора строки из списка List                 */
/*Если Selectable=true, то возможен быбор нескольких строк*/
void SelectString(const char *Title,const char *Prompt,void *List,
 unsigned short *RowNumber,LongBoolean Selectable,LongBoolean ForceSelect,char *Res);
void* SelectSetOfString(const char *Title,void *AimList,void *SelList);
/* Диалог для выбора таблицы LRHandle в базе LFile Handle */
short ChoiceLogRec(const char *TableList,long Mode,OType LFileHandle,OType *LRHandle,
 LongBoolean NewTable,LongBoolean ForceSelect);
void* GetSetObjIdn(OType LF,unsigned short Width,void *OldList,LongBoolean MultiSel);
void* LogRecGetKeyContent(OType LRHandle,unsigned char AWidth);
/* Диалог для выбора массива ArrHandle в строке ObjHandle*/
short ChoiceArrayByName(OType ObjHandle,OType *ArrHandle,char *ArrayName,unsigned short *BegLine);
/* Диалог для выбора колонки массива ArrHandle*/
short ChoiceColumnName(OType ArrHandle,char *ColumnName,unsigned char *ColumnNumber,unsigned short *BegLine);
void* GetColumnList(OType ArrayHandle);
//void* GetInputLine(RECT R,unsigned char RC,char *Min,char *Max,unsigned char ALen,unsigned char Dec);
/* Диалог для выбора описателя таблицы TDescHandle в файлке ресурсов ResFileName*/
short ChoiceTDesc(const char *ResFileName,OType *TDescHandle);
/* Универсальное окно для горизонтальной графики для строки aDataObj*/
void ShowH(RECT R,OType *aDataObj,const char *Title,const char *ArrayName,const char *UnitName,unsigned short Option);
/* То же, для одной колонки массива Column*/
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
/* Выбор файла */
void GetFilename(const char *AWildCard,const char *ATitle,char *FileName);
void GetColumnName(OType ArrHandle,unsigned char Column,char *ColName);

/* FROM SclTools.pas */

/* Получение множителя Factor для перевода в FDUnit по имени поля FDName   */
/* В случае отсутствия множителя в базе делается запрос на внесение в базу */
/* ModuleName - необязательная информация для локализации запроса          */
/* Рекомендуется вместо GetFDFactor в модулях для GUI                      */
long D_GetFDFactor(const char *ModuleName,OType TDescHandle,const char *FDName,const char *FDUnit,float *Factor);

/* То же по номеру поля  */
long D_GetFDNFactor(const char *ModuleName,OType TDescHandle,long Index,const char *FDUnit,float *Factor);

/* Получение значения поля Name строки A в заданных единицах UnitName */
/* В случае отсутствия множителя в базе делается запрос на внесение в базу */
LongBoolean GetFULongInt(OType A,const char *Name,const char *UnitName,long *R);
LongBoolean GetFUSingle (OType A,const char *Name,const char *UnitName,float *R);
LongBoolean GetFUString (OType A,const char *Name,const char *UnitName,char *R);

/* Занесение значения поля Name строки A в заданных единицах UnitName */
/* В случае отсутствия множителя в базе делается запрос на внесение в базу */
LongBoolean PutFULongInt(OType A,const char *Name,const char *UnitName,long R);
LongBoolean PutFUSingle (OType A,const char *Name,const char *UnitName,float R);
LongBoolean PutFUString (OType A,const char *Name,const char *UnitName,const char *R);

/* Сохранить строку в базу с преобразованием структуры базы */
short Save_WSExR(const char *Selected_Aim, const char *TName, const char *SaveFName,
        LongBoolean CheckThisCopy, OType ObjHandle);

/* Создать попластовые данные с помощью разбиения и перекодировки по словарю */
/* hInterArr = hNil      : не разбивать                 */
/* lpTranslateStr = NULL : не перекодировать по словарю */
/* Flags                 : см. константы clcXXXX        */
long CreateLayerCurve(OType hSrcObj,OType hSrcArr,unsigned char ucSrcCol,
           OType hInterArr,const char *lpTranslateStr,OType hDestObj,OType hDestArr,
           unsigned char ucDestCol,long Flags);

void ResDialog(const char *lpResFileName, const char *lpTablName);
void *GetNewClsList(const char *lpClsName);

/* Универсальная ссылка на базу с вложенными словарями типа
  !МЕТОДЫ!(!МЕТОДЫ!@e:\prime98\00.LAS.1.КОММЕНТАРИЙ) */
long DoFuncDic(const char *InputStr, const char *FlName, const char *DicWSName,
           OType WSBase, OType DataObj, char *OutStr,
           long OutStrLen);
/* Получение строки словаря DicObj по имени базы DicWSName и таблицы TablName и
  по имени словаря DicName */
short GetDicObj(const char *DicWSName, const char *TablName, const char *DicName,
           OType *DicObj);
/* Получение преобразованного имени по словарю */
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

/* Функции для горизонтальной графики */
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

/* Обработка строки макета LAS */
long AnsiLasLineNew(const char *lpOriginStr, const char *lpDicWSName, char *lpBlankValue, long nBlankValueSize,
  long *lpdwPosM, OType hDataObj, OType hLogFile, long dwRoof, long dwSole, long dwStep,
  char *lpLasLine, long nLasLineSize);
long AnsiGetFuncStr(char *lpInputStr, long nInputStrSize, unsigned short *lpwErrCode, char *lpFuncStr, long nFuncStrSize);
long AnsiGetWord(char *lpInputStr, long nInputStrSize, unsigned short *lpwErrCode, char *lpWord, long nWordSize);
long AnsiRemovePar(const char *lpInStr, char cMark, unsigned short wOption, char *lpResultStr, long nResultStrSize);
/*----------- Обработка ссылок ------------------------------------------*/
long AnsiGetWSValue(const char *lpReference, short *lpsError, char *lpWSValue, long nWSValueSize);
/* Ссылка на базу */
long AnsiGetTableValue(const char *lpReference, OType hWSBase, short *lpsError, char *lpTableValue, long nTableValueSize);
/* Ссылка на строку */
long AnsiGetObjValue(const char *lpReference, OType hDataHandle, short *lpsError, char *lpObjValue, long nObjValueSize);
/* Составная строка с ссылками или без */
/* LogFile - если ссылка на таблицу    */
/* Например, Площадь @LAS.1.ПЛОШАДЬ  */
long AnsiUpdateStrC(const char *lpInStr, OType hLogFile, char *lpOut, long nOutSize, const char *lpDicWSName);
long AnsiUpdateStrCData(const char *lpInStr, OType hLogFile, OType hDataHandle, char *lpOut, long nOutSize, const char *lpDicWSName);
/*----------- Обработка словарей ------------------------------------------*/
/* универсальная ссылка на базу с вложенными словарями типа
  !МЕТОДЫ!(!МЕТОДЫ!@e:\prime98\00.LAS.1.КОММЕНТАРИЙ) */
long AnsiDoFuncDic(const char *lpInputStr, const char *lpFlName, const char *lpDicWSName, OType hWSBase, OType hDataObj, char *lpFuncRes, long nFuncResSize);
/* Получение строки словаря DicObj по имени базы DicWSName и таблицы TablName и
  по имени словаря DicName*/
short AnsiGetDicObj(const char *lpDicWSName, const char *lpTablName, const char *lpDicName, OType *lphDicObj);
/* Получение преобразованного имени по словарю*/
long AnsiGetNewName(const char *lpOldName, OType hDicObj, unsigned char nCol1, unsigned char nCol2, char *lpNewName, long nNewNameSize);
/* Выделение подстроки */
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

/* Получить/прочитать строку-разделитель строк массива
   для строк, возвращаемых функциями AnsiGetObjValue и т.п. */
LongBoolean AnsiSetRowDelimiter(const char *lpValue);
long AnsiGetRowDelimiter(char *lpValue, long nValueSize);
/* Получить/прочитать строку-разделитель столбцов массива
  для строк, возвращаемых функциями AnsiGetObjValue и т.п. */
LongBoolean AnsiSetColDelimiter(const char *lpValue);
long AnsiGetColDelimiter(char *lpValue, long nValueSize);

/* Управление кэшем ссылок */
void InitTableObjCache(OType hWSFile);
void DestroyTableObjCache(void);
short GetCachedTableHandle(const char *lpName, OType hWSFile, long *lpdwCachedHandle);
short GetCachedTableObjByIdN(long *dwCachedHandle, unsigned short wIdN, OType *lphObj);
void DisableTableObjCache(void);
void EnableTableObjCache(void);
LongBoolean IsTableObjCacheEnabled(void);

/* Получить название минимальной единицы измерения глубины для вызывающего алгоритма */
char *StdDepthUnit(void);
/* Получить название минимальной единицы измерения глубины для алгоритма по HINSTANCE его DLL */
TMinimalDepthUnit StdDepthUnitOfInstance(HINSTANCE hInstDLL);
/* Переопределить минимальную единицу измерения глубины на 1 вызов следующей функции DSExt API */
void TemporarySetNewDepthUnit(const char *lpszUnitName, void *lpReserved);
/* Получить название стандартной пользовательской единицы измерения глубины для вызывающего алгоритма */
char *StdUserDepthUnit(void);
/* Получить название стандартной пользовательской единицы измерения глубины для алгоритма по HINSTANCE его DLL */
TUserDepthUnit UserDepthUnitOfInstance(HINSTANCE hInstDLL);
/* Переопределить стандартную пользовательскую единицу измерения глубины на 1 вызов следующей функции DSExt API */
void TemporarySetNewUserDepthUnit(const char *lpszUnitName, void *lpReserved);
/* Сбросить внутренний буфер библиотеки DSExt информации о загруженном модуле (модулях)
  Этот буфер, в частности, содержит информацию об используемых единицах измерения глубин */
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


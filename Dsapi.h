/***************************************************************************\
*                                                                           *
* Система информационного обеспечения геофизических исследований скважин    *
*   "ПРАЙМ" для Windows                                                     *
* Интерфейс к серверу данных                                                *
* Язык: C++                                                                 *
* Версия: 1.06.07                                                           *
* (C) НПФ ГеоТЭК, 1999 - 2009                                               *
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

/* Константы версии формата данных !!! */
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

/* Структура ссылки для работы с данными */

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

extern char *DTSkip; // начало кривой
extern char *ArrLen; // количество точек
extern char *FType; // тип файла данных
extern char *DataType; // системный тип данных
extern char *DataDirection; // направление данных
extern char *cDevider; // разделитель
extern char *cStrDeviderR; // правый разделитель
extern char *cStrDeviderL; // левый разделитель
extern char *cTerminatorCode; // терминатор строки

extern char *cFileName; // имя файла
extern char *cFullFileName; // полное имя файла
extern char *cFileExt; // расширение файла
extern char *cFileDir; // путь файла
extern char *NullSingle; // пустое значение
extern char *SHAG; // шаг дискретизации кривой
extern char *ED_IZM_S; // единица измерения шага дискретизации
extern char *MGIS; // метод ГИС
extern char *cWELL; // скважина
extern char *PARAMETR; // значение параметра
extern char *ED_IZM; // единица измерения параметра ГИС
extern char *KR_CFR; // кровля кривой ГИС
extern char *PD_CFR; // подошва кривой ГИС
extern char *cNVersion; // номер версии
extern char *cHistory; // история

/* Системные имена файлов и таблиц */
extern char *ScaleFile; // файл переводных коэффициентов
extern char *DicFile; // файл словарей
extern char *DicTable; // таблица словарей
extern char *ClsTable; // таблица списков

#define SUCCESS            0
#define NoDefData          1
#define ArrayExpected      2
#define UnrecogRCodePtr    3
#define NotObj             4
#define NoTempateToDataObj 5
#define NoObjDescriptor    6

/* Результаты функций Goto_BeginTable, Goto_NextTable, GetCurTable */
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

#define MaxColumns 132 /* Максимальное число колонок в массиве */
/* Маски для предопределенных значений */
#define fxFixed 0x20      /* Без записи и чтения */
#define fxRead  0x40      /* Для чтения          */
#define fxWrite 0x80      /* Для записи          */
#define fxReadWrite 0xC0  /* Для записи и чтения */

/* Константы для чтения строки из WS */
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

/* Константы для чтения таблиц из WS */
#define cNoLR         0
#define cLR_Normal    1
#define cLR_Deleted   2
#define cLR_All       cLR_Normal + cLR_Deleted
#define cLRTemplate   4
#define cLRCurDataObj 8
#define cLRFull       cLRTemplate + cLRCurDataObj
#define cLR           cLRFull + cLR_Normal

/* Битовые маски для слова статуса DataObj */
#define sBlank    0x0000
#define sModified 0x0001
#define sCreated  0x0002

/* Коды ошибок PutScale, GetScale */
#define serr_INVSCALE -2 /* неверный масштаб (=0) */
#define serr_STREAM   -1 /* ошибка потока         */
#define serr_REPEAT    1 /* повтор масштаба       */

/*****************************************************************************\
* ОПЕРАЦИИ С ВНЕШНИМ МОДУЛЕМ                                                  *
\*****************************************************************************/

/* Загрузить модуль*/
extern "C" long DatservLoad(void);

/* Подключиться к модулю уже загруженному в адресное пространство процесса */
extern "C" LongBoolean DatservConnect(void);

/* Выгрузить модуль. Не нужно вызывать, если DatServ загружен вызовом DatservConnect */
extern "C" void DatservFree(void);


/*****************************************************************************\
* ДРУГИЕ ОПЕРАЦИИ                                                             *
\*****************************************************************************/

/* Уничтожить объект, созданный в сервере данных по его указателю */
void  DoneDSObj(void *P);
/* Освободить память, выделенный в сервере данных */
void  DSFreeMem(void *P,unsigned short Size);
/* Уничтожить объект по дескриптору */
short DoneHandle(OType *Handle);
/* Создать копию объекта */
short CopyHandle(OType Handle,OType *NewHandle);
/* Создать копию объекта с новым дескриптором */
short CopyNewHandle(OType Handle,OType *NewHandle);
/* Получить тип объекта */
short HandleGetType(OType Handle,unsigned char *aType);
/* Очистить счетчики сервера данных */
void  ClearDatServ(void);

/*=================================================================================*/
/* ОПИСАТЕЛЬ ТАБЛИЦЫ */

/* Создать пустой описатель таблицы */
short InitTDesc(const char *TablName,OType *TDescHandle);
/* Получить описатель таблицы по имени*/
short GetTDesc(OType DataHandle,const char *TablName,OType *TDescHandle);
/* То же, из файла ресурсов */
short GetTDescF(const char *FileName,const char *TablName,OType *TDescHandle);
/* Сравнить два описателя таблицы. Result = 32 - полное совпадение всех полей */
short TDCheckDesc(OType TDescHandle,OType TDescHandle1,unsigned char *Result);
/* Получить число массивов в описателе */
short TDGetArrayCounter(OType TDHandle);
/* Получить число объектов в описателе */
short TDGetObjCounter(OType TDHandle);
/* Получить имя описателя */
short TDGetName(OType TDHandle,char *Res);
/* Получить длинное имя описателя */
short TDGetLongName(OType TDHandle,char *Res);
/* Получить английское имя описателя */
short TDGetAnglName(OType TDHandle,char *Res);
/* Получить русское имя описателя */
short TDGetRusName(OType TDHandle,char *Res);
/* Те же, но функции для присвоения */
short TDSetName(OType TDHandle,const char *Name);
short TDSetLongName(OType TDHandle,const char *Name);
short TDSetAnglName(OType TDHandle,const char *Name);
short TDSetRusName(OType TDHandle,const char *Name);
/* Получить индекс массива по порядковому номеру массива */
short TDGetArrayIndexByNumber(unsigned char Number,OType TDHandle);
/* Получить индекс массива по имени массива */
short TDGetArrayIndex(const char *AName,OType TDHandle);
/* Получить число массивов в описателе */
short TDGetArrayNumber(OType TDHandle,const char *AName);
/* Получить индекс объекта по порядковому номеру объекта */
short TDGetObjIndexByNumber(unsigned char Number,OType TDHandle);
/* Получить индекс объекта по его имени */
short TDGetObjIndex(const char *AName,OType TDHandle);
/* Получить число объектов в описателе */
short TDGetObjNumber(OType TDHandle,const char *AName);
/* Получить индекс поля по его имени */
short TDGetFieldIndex(const char *AName,OType TDHandle);
/* Добавить описатель поля FDHandle в описатель строки TDHandle*/
short TDInsertFD(OType TDHandle, OType FDHandle);
/* Добавить описатель поля FDHandle в описатель строки TDHandle в позиции индекса i*/
short TDAtInsertFD(OType TDHandle,short i,OType FDHandle);
/* Вставить описатель поля FDHandle в описатель строки TDHandle в позиции индекса i*/
short TDAtPutFD(OType TDHandle,short i,OType FDHandle);
/* Удалить описатель поля FDHandle в описателе строки TDHandle в позиции индекса i*/
short TDAtFreeFD(OType TDHandle,short i);
/* Проверить повтор поля S1 в описателе строки TDHandle */
LongBoolean TDCheckRepeating(OType TDHandle, char *S1);
/* Записать описатель строки TDHandle в файл ресурсов */
short PutTDesc(const char *ResFileName,OType TDHandle,LongBoolean ChkCopy);
/* Удалить все описатели полей в описателе строки */
short TDFreeAll(OType TDHandle);
/* Weren't in DOS !*/
short GetTDescName(OType TDescHandle,char *Name);
/* Прямое получение описания поля по имени поля */
short GetTDescFldsN(OType TDescHandle,const char *FieldName,PCFDData PFDesc);
/* Прямое получение описания поля по индексу поля */
short GetTDescFldsI(OType TDescHandle,unsigned short FieldNumber,PCFDData PFDesc);

/* Получить строку из имен ключевых полей. ELen - длина на каждое имя */
short GetTDKeyStr(OType TDescHandle,unsigned char SLen,char *KeyStr);
short MakeDKeyTablDesc(OType TDescHandle,OType *KeyTD);
/* Получить строку из значений MasterDesc полей */
short GetAnyKeyStr(OType MasterDesc, OType SlaveDesc,unsigned char SLen,char *KeyStr);
/* Получить предопреленное значение по имени из описателя таблицы */
short GetTDDefinedValue(OType TDescHandle,const char *FieldName,OType *ObValHandle);
float GetDefSingle(OType TDescHandle, const char *FieldName);
long GetDefLong(OType TDescHandle, const char *FieldName);
short GetDefStr(OType TDescHandle, const char *FieldName, char *Value);
/* Получить элемент классификатора */
short TDGetAtomNameAt(OType TDHandle, short i, char *AtomName);
/* Изменить элемент классификатора */
short TDInsertNewAtom(OType TDHandle, const char *Name);

/*=================================================================================*/
/* ОПИСАТЕЛЬ ПОЛЯ */

/* Создать описатель поля */
/* afldType  = ( 0-Nodef, 1- _Byte, 2- _Short, 3- _Word, 4-_LongInt, 5-_Single,
6-_Double, 7-_String,8- _Date, 9- _Time,10- _Array,11-_Object,
12-_StringC, 13-_Table,14-_User1,15- _User2,16- _User3,17- _Blob,
18-_Boolean, 19-_Memo); */
short InitFDesc(const char *afldName,const char *afldUnitName,unsigned char afldType,
				short afldLen,OType *FDescHandle);
/* Получить описатель поля по имени */
short GetFDescByName(OType TDescHandle,const char *FieldName,OType *FDescHandle);
/* Получить число описателей полей в описателе таблицы*/
short GetTDescCounter(OType TDescHandle,unsigned short *TDCounter);
/* Установить/отменить свойство Slave у поля */
short SetFDescSlave(OType FDescHandle,LongBoolean M);
/* Поверить свойство Slave у поля */
LongBoolean  IsFDescSlave(OType FDescHandle);
/* Получить описатель поля по номеру */
short GetFDescByNumber(OType TDescHandle,unsigned short FieldNumber,OType *FDescHandle);
/* Получить значения описателя поля */
short GetFDescFlds(OType FDescHandle,PCFDData FDesc);
/* Установить значения описателя поля */
short SetFDescFlds(OType FDescHandle,PCFDData FDesc);

/* Сравнить два описателя поля. Биты результата Result
0 - нет второго описателя,
+8 - совпадение имен,
+4 - совпадение типов;
+2 - совпадение единиц измерений;
+1 - совпадение длин */
short LFDescCompary(OType FDescHandle,OType FDescHandle1,unsigned char *Result);

/* Получить доступ к полю */
short GetFDescAccess(OType FDescHandle,unsigned char *Access);
/* Получить маску поля */
/* unsigned short Mask;       F E D C B A 9 8 7 6 5 4 3 2 1 */
/*                            ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/*                        ----- ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/*                        ------- ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/*                        --------- ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/* только со списка       ----------- ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/* признак группы         ------------- ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/* обязательное значение  --------------- ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/* пометка ЗАНЯТО/ВЫБРАНО (temp)----------- ¦ ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/* 1 заданное значение write ---------------- ¦ ¦ ¦ ¦ ¦ ¦ ¦ */
/* 1 заданное значение read ------------------- ¦ ¦ ¦ ¦ ¦ ¦ */
/* 1 заданное значение      --------------------- ¦ ¦ ¦ ¦ ¦ */
/* 1 доступ с системн. приор. --------------------- ¦ ¦ ¦ ¦ */
/* 1 доступ с выс. приоритетом ---------------------- ¦ ¦ ¦ */
/* 0/1 доступ с (низк/обычн)   ------------------------ ¦ ¦ */
/* 0/1 K1/K2 (если ключевое поле)------------------------ ¦ */
/* 0/1 неключ/ключ поле     ------------------------------- */
unsigned short GetFDMask(OType FDescHandle);
/* Установить маску поля */
short SetFDMask(OType FDescHandle,unsigned short Mask);
/* Получить код типа поля */
short GetFDescRC(OType FDescHandle,unsigned char *RC);
/* Получить ключ поля */
short GetFDescKey(OType FDescHandle,unsigned char *Key);
/* Сделать поле ключевым */
short SetFDescKey(OType FDescHandle);
/* Возвращает каталог сервера данных */
void GetSystemDir(char *Dir);
/* Добавить в базу переводных коэффициентов новый коэфф. */
short PutScale(CScalLineType *SL);
/* Запросить базу переводных коэффициентов */
short GetScale(CScalLineType *SL);
/* Получить множитель для перевода значения поля к ед. FDUnit по имени поля*/
short GetFDFactor(OType TDescHandle,const char *FDName,const char *FDUnit,float *Factor);
/* Получить множитель для перевода значения поля к ед. FDUnit по индексу поля*/
short GetFDNFactor(OType TDescHandle,short Index,const char *FDUnit,float *Factor);
/* То же, с расширенными возможностями */
/* Unit1 - ед.изм поля, для которого не найден коэфф. Unit1->FDUnit */
short GetFDFactorEx(OType TDescHandle,const char *FDName,const char *FDUnit,char *Unit1,float *Factor);
short GetFDNFactorEx(OType TDescHandle,short Index,const char *FDUnit,char *Unit1,float *Factor);
/* Получить у поля описатель массива */
short GetFDArrDesc(OType FDescHandle,OType *TDHandle);
/* Присвоить полю описатель массива */
short SetFDArrDesc(OType FDescHandle,OType TDHandle);
/* Подключить к полю классификатор (список) */
short SetFDClass(OType FDescHandle,const char *ClsName);
/* Получить у поля имя классфикатора */
short GetFDClass(OType FDescHandle,char *ClsName);

/*=================================================================================*/
/* СИСТЕМА ДАННЫХ */
/* Создание экземпляра системы данных по описателю ResFileName*/
short CreateSysData(const char *ResFileName,OType *DataHandle);
/* Открытие экземпляра системы данных по описателю ResFileName*/
short InitSysData(const char *ResFileName,OType *DataHandle);
/* Запросить базу FileName у системы данных */
short GetLogFile(const char *FileName,LongBoolean *Status,OType DataHandle,OType *LFHandle);
/* Удалить базу LFHandle из системы данных */
short RemoveLogFile(OType DataHandle,OType LFHandle);
/* Получить имя файла ресурсов у системы данных */
short GetResFileName(OType DataHandle,char *Res);
/* Получить статус файла ресурсов для проверки ошибок */
unsigned short ResStreamSt(OType DataHandle);
/* Проверка на изменение системы данных */
LongBoolean ResIsModified(OType DataHandle);
/* Упаковка файла ресурсов */
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
/* БАЗА ДАННЫХ НА WS */
/* Прямое открытие базы данных без системы данных */
short SysLFInitOpen(const char *FileName,OType *LFHandle);

short SysLFInitOpenEx(const char *FileName, OType *LFHandle, int LROption, int ObjOption);

/* Создание экземпляра пустой базы данных */
short SysLFCreate(const char *FileName,OType DataHandle,OType *LFHandle);
/* Запись новой строки с проверкой дублирования строки в таблицу базы */
/* CheckIntent (24 - разные структуры), CheckCopy (28 - повтор ключевых полей) */
short SaveNewObj(const char *SelectedAim,const char *aTablName,LongBoolean CheckCopy,LongBoolean CheckIntent,OType LFHandle,OType ObjHandle);
/* То же, что и SaveNewObj, но возвращает Handle изменённого объекта */
/* (соответствующего структуре базы) */
short SaveNewObjEx(const char *SelectedAim,const char *aTablName,LongBoolean CheckCopy,LongBoolean CheckIntent,OType LFHandle,OType ObjHandle,OType *NewObjHandle);
/* Соединить две базы данных */
short LFAppend (OType MainLF,OType OtherLF,unsigned short Option);
/* Упаковать базу в другую базу bName. Delta - разница размеров */
short LFPackTo(OType LFHandle,const char *bName,long *Delta);
/* Поиск первой строки в базе по условию */
short FindFirst(OType LFHandle,OType SOHandle,OType *ObjHandle);
/* Поиск первой строки в таблице базы по условию */
short FindFirstLocal(OType LFHandle,OType SOHandle,const char *TablName,OType *ObjHandle);
/* Поиск следующей строки в базе по условию */
short FindNext(OType LFHandle,OType *ObjHandle);
/* Переход к первой таблице в базе */
short Goto_BeginTable(OType LFHandle);
/* Переход к следуюжей таблице в базе */
short Goto_NextTable(OType LFHandle);

/*============================================================================*/
/* ИНДЕКСЫ */

// Константы Option для ф-ии GetIndexViewsList
const long civlName          = 0;      // только имя
const long civlTablName      = 1;      // +имя_таблицы ;
const long civlVerNumber     = 2;      // +номер версии;
const long civlPackKeyStr    = 4;      // + Ключевые поля;
const long civlDataClass     = 8;      // + опции данных;
const long civlTopBottomStep = 16;     //+кровля, подошва, шаг
const long civlIndexNumber   = 32;     //+порядковый номер индекса в таблице
const long civlCurves        = 256 ;   // возвращать обычные кривые
const long civlBedCurves     = 512 ;   // возвращать попластовые кривые
const long civlLitol         = 1024;   // возвращать колонки литологии
const long civlStrat         = 2048;   // возвращать колонки стратиграфии
const long civlSlaveOnly     = 0x1000; // возвращать только гибкие массивы
const long civlNameOnly      = 0x2000; // возвращать только имя (без добавления имени планшета)
const long civlNoFirstSymbol = 0x4000; // не ставить первый символ в имя (#,!)
const long civlIncludeParams = 0x8000;

long GetIndexViewsList(const char *WSName, const char *TablName, const char *Delim, long Option, char *Res);
long GetWSViewsList(const char *WSName, const char *TablName, const char *Delim, long Option, char **Res);
long GetWSViewsListXml(const char *WSName,const char *TablName, int Option, char **Res);
long FreeDSMem(char *pointer, int Size, int Option);

/*============================================================================*/
/* ТАБЛИЦА WS */

/* Проверка наличия таблицы. 0-нет ошибки */
short TableExist(const char *TableName,OType LFHandle);
/* Открытие текущей таблицы базы */
short GetCurTable(OType LFHandle,OType *LRHandle);
/* Открытие таблицы по имени в базе */
short Get_Table(const char *TableName,OType LF,OType *LRHandle);
short Get_TableNew(const char *TableName,OType LFHandle,OType *LRHandle);
/* Возвращает свое имя */
short GetTableName(OType LRHandle,char *Res);
/**/
short GetWSHandle(OType LRHandle, OType *WSHandle);
short LRChangeName(OType LRHandle,const char *NewName);
/* Записать описатель */
short LRPutTDesc(OType LRHandle,OType TDHandle);

/* Переход к первой строке таблицы */
short Goto_BeginObj(OType LRHandle);
/* Быстрый переход к первой строке таблицы */
short Goto_FastBeginObj(OType LRHandle);
/* Переход к следующей строке таблицы */
short Goto_NextObj(OType LRHandle);
/* Бытрый переход к следующей строке таблицы */
short Goto_FastNextObj(OType LRHandle);
/* Записать строку aDataObj.*/
short LRPutObj (OType LRHandle,OType aDataObj,LongBoolean CheckCopy,LongBoolean aNewTable);
/* Проверка наличия строки в таблице */
unsigned char LRCheckKeyObj (OType LRHandle,OType aDataObj,OType TDescHandle,unsigned short *IdN,OType *FindedObjHandle);
/*============================================================================*/
/* СТРОКА ТАБЛИЦЫ WS */

/* Открыть текущую строку таблицы */
short GetCurObj(OType LRHandle,OType *ObjHandle);
short GetFastCurObj(OType LRHandle,OType *ObjHandle);
/* Всегда возвращают новые дескрипторы, если даже строка загружена */
short GetTrueCurObj(OType LRHandle,OType *ObjHandle);
short GetTrueFastCurObj(OType LRHandle,OType *ObjHandle);
/* Создает копию объекта по его новому описателю */
short ObjTDCopy(OType TableHandle,OType ObjHandle,OType *NewObjHandle);
/* Создает пустую копию объекта */
short ObjCopyBlank(OType ObjHandle,OType *NewObjHandle);
/* Опустошает объект */
short BlankObj(OType ObjHandle);
/* Возвращает строку по его номеру IdN ( нумерация начинается с 1) */
short GetObjByIdN(OType LRHandle,unsigned short Idn,OType *ObjHandle);
short GetObjByEIdN(OType LRHandle,unsigned short ObjType,unsigned short Idn,OType *ObjHandle);
/* Создать строку таблицы с пустыми полями по описателю из файла ресурсов*/
short ObjTDInit(const char *ResFileName,const char *TablName,OType *ObjHandle);
/* Создать строку таблицы с пустыми полями по описателю*/
short ObjTDInitH(OType TableHandle,OType *ObjHandle);
/* Вставляет с строку объект (ObVal, Arr, Obj) в позиции i */
short ObjAtPut(OType ObjHandle,short I,OType Handle);
/* Записывает в текстовый файл содержание строки */
short ObjWriteASCII(OType ObjHandle,const char *FileName,LongBoolean Owrw);
/* Возвращает строку по его идентификационному номеру из базы */
short GetWSObj(OType LFHandle,unsigned short IdN,const char *TablName,OType *ObjHandle);
/* Возвращает строку по его ключевой строке KeyStr из базы */
short GetWSKeyObj(OType LFHandle,const char *TablName,const char *KeyStr,OType *ObjHandle);
/* Импортирует из внешнего файла ImportFile согласно описателю в TDescHandle*/
short ImportObj (OType TDescHandle,const char *ImportFile,const char *TablName,OType *ObjHandle);
/* Экспортирует во внешний файл ExporFile */
short ExportObj (const char *ExportFile,OType ObjHandle);
/* Создает пустую строку */
short ObjInit(OType *ObjHandle);
/* Получить ключевые поля строки. SLen - длина на каждое поле */
short GetKeyStr(OType ObjHandle,unsigned short ID,unsigned char SLen,char *S);
short ObjGetAnyKeyStr(OType ObjHandle,OType SlaveDesc,unsigned short ID,unsigned char SLen,char *S);
/* Получить имена ключевых полей строки. SLen - длина на каждое поле */
short GetMetaKeyStr(OType ObjHandle,unsigned char SLen,char *S);
/* Получить номер данной строки в таблице */
unsigned short GetRowNumber(OType ObjHandle,OType LFHandle,const char *TableName);
/* Получить описатель у объекта-строки */
short GetTemplate(OType ObjHandle,OType *THandle);
/**/
short SetTemplate(OType ObjHandle,OType THandle);
/* Добавить в строку поле с описателем */
short ObjAdd_ObVal(OType ObjHandle,OType  ObValHandle,OType FDHandle);
short ObjAddAt_ObVal(OType ObjHandle,OType ObValHandle,OType FDHandle,short Index);
/* Добавить в строку массив с описателем */
short ObjAdd_Arr(OType ObjHandle,OType ArrHandle,OType FDHandle);
/* Послать в буфер все значения строки */
short MoveToBuf(OType ObjHandle,void *Buf, long bufsize);
/* Получить из буфера все значения строки */
short MoveFromBuf(OType ObjHandle,void *Buf, long bufsize);
/* Получить размер строки данных для буфера */
long GetObjBinarySize(OType ObjHandle);
/* Получить информацию об изменения строки */
LongBoolean GetObjState(OType ObjHandle,unsigned short Mask);
/* Присвоить информацию об изменения строки */
short SetObjState(OType ObjHandle,unsigned short Mask,LongBoolean Enable);
/* Возвращает объект (строку данных) по имени из состава строки */
short GetObjByName (OType MainObjHandle,const char *AName,OType *ObjHandle);
/* Возвращает объект строку данных по номеру из состава строки */
short GetObjByNumber(OType MainObjHandle,short ObjNumber,OType *ObjHandle);
/* Проверяет принадлежность одной группе двух строк */
LongBoolean ChkGroup(OType ObjHandle1,OType ObjHandle2);
/* Изменяет массив, оставляя в нем одну или две колонки */
/* Option and 1 = 1 - копирование значений TakeData */
short ReplaceArr(OType ObjHandle,const char *ArrName,unsigned char Column1,unsigned char Column2,unsigned short Option);
/* Удаяет логически строку из таблицы */
short DeleteObj(OType ObjHandle,OType LRHandle);
/* Восстанавливает строку после логического удаления */
short RestoreObj(OType ObjHandle,OType LRHandle);
/* Получить значения полей из другой строки */
/* Option 0-только пустые непустыми, 1-пустые всеми, 2-все всеми*/
short ObjTakeByTDesc(OType ToObjHandle,OType FromObjHandle,unsigned short Option);
short ObjGetHandleIndex(OType ObjHandle,OType Handle);
/* Импорт из текстовой строки по описателю */
short ImportStrObj(OType TDescHandle,char *Str,OType *ObjHandle);
/* Для поддержки истории и версий строк */
short AddHistory(OType ObjHandle,const char *FieldName,const char *HistStr);
short IncVersion(OType ObjHandle,const char *FieldName);

/*============================================================================*/
/* ОБЪЕКТ КРИВАЯ */

/* Для специального использования в горизонтальной графике */
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
/* МАССИВ СТРОКИ WS */

short ArrayFInit(const char *ArrayName,unsigned char Colums,TSByteArray Ty,long MaxLen,OType *ArrHandle);
/* Открыть массив по имени в строке */
short GetArrayByName(OType *ArrHandle,const char *AName,OType ObjHandle);
/* Открыть массив по номеру */
short GetArrayByNumber(OType *ArrHandle,unsigned short Number,OType ObjHandle);
/* Открыть копию массива по имени в строке */
short CopyArrayByName(OType *ArrHandle, const char *AName, OType ObjHandle);
/* Открыть копию массива по номеру */
short CopyArrayByIndex(OType *ArrHandle, short Index, OType ObjHandle);
/* Получить имя массива */
short ArrayGetName(OType ArrHandle,char *Res);
/* Получить описатель массива */
short ArrayGetDesc(OType ArrHandle,OType *TDesc);
/* Заменить описатель массива */
short ArrayReplaceDesc(OType ArrHandle,OType TDesc);
/* Инициализация массива на основе двочного файла AFileName*/
/* APosition позиция в байтах начала массива в файле*/
short ArrayInit(long APosition,const char *AFileName,OType TDHandle,LongBoolean aEraseFlag,OType *ArrHandle);
/* short ArrayWriteBin(OType ArrHandle,TXStream *S); */
short ArrayGetState(OType ArrHandle,unsigned short *State);
short ArraySetState(OType ArrHandle,unsigned short State);
/* Саздать пустой массив по описателю */
short ArrayTDInit(OType *ArrHandle,const char *ResFileName,const char *TablName,const char *ArrayName);
/* Создать пустой массив по описателю поля */
short ArrayFDInit(OType *ArrHandle,OType FieldHandle);
/* Создать пустой массив по описателю строки по имени */
short ArrayTDInitH(OType *ArrHandle,OType TDescHandle,const char *ArrayName);
/* Получить массив по индексу */
short GetArrayByIndex(OType *ArrHandle,short Index,OType ObjHandle);
/* Создать пустую копию массива */
short ArrayCopyBlank(OType ArrHandle,OType *O);
/* Создать строку данных из строки массива */
short ArrayGetObjData(OType ArrHandle,long Index,OType *ObjHandle);
/* Выделяет строку данных из колонки массива */
short ArrayGetColumnObj(OType ArrHandle,unsigned char Column,long Index,OType *ObjHandle);
/* Вставить строку данных в строку массива */
/* Вставляются только совпадающие поля, типы преобразовываются */
/* Строки массива не раздвигаются */
short ArrayPutObjData(OType ArrHandle,long Index,OType ObjHandle);
/* Вставить данные из буфера */
short ArrayPutData(OType ArrHandle,long Index,unsigned short Count,void *PBuf);
/* То же, но нет ограничения на 64K записей */
short ArrayPutHugeData(OType ArrHandle,long Index,long Count,void *PBuf);
/* Получить данные в буфер */
short ArrayGetData(OType ArrHandle,long Index,unsigned short Count,void *PBuf);
/* То же, но нет ограничения на 64K записей */
short ArrayGetHugeData(OType ArrHandle,long Index,long Count,void *PBuf);
/* Заполнить значениями массива от индекса B до E буфер P*/
short MoveSingleColumnData(OType ArrHandle,unsigned char Column,long B,long E,void *P);
/* Заполнить значения массива от индекса B до E из буфера P */
short LoadSingleColumnData(OType ArrHandle, unsigned char Column, long B, long E, void *P);
/* Получить значение элемента массива в виде строки */
short ArrayGetStrColumnData(OType ArrHandle,unsigned char Column,long Index,char *Res);
/* Получить значение элемента массива в виде форматированной строки */
short ArrayGetFStrColumnData(OType ArrHandle,unsigned char Column,long Index,char *Res);
/* Получить значение элемента массива в виде float */
float ArrayGetSingleColumnData(OType ArrHandle,unsigned char Column,long Index);

/* Получить значения Count элементов массива в виде массив float */
short ArrayGetSingleColData(OType ArrHandle,unsigned char Column,long Index,unsigned short Count,float *Buf, long BufLastIndex);

/* Быстрое получение элемента текущего массива в виде float */
/* Необходимо вначале вызвать любую ф-ю с одним ArrHandle */
float ArrayGetSingle(unsigned char Column,long Index);
/* Доступ к массиву по именам колонок */
int GetArraySingle(OType ArrHandle, long Index, const char *ColName, float *Value);
long GetArrayLong(OType ArrHandle, long Index, const char *ColName);
long GetArrayString(OType ArrHandle, long Index, const char *ColName, char *Value);
long GetArrayFString(OType ArrHandle, long Index, const char *ColName, char *Value);
long PutArraySingle(OType ArrHandle, long Index, const char *ColName, float Value);
long PutArrayLong(OType ArrHandle, long Index, const char *ColName, long Value);
long PutArrayString(OType ArrHandle, long Index, const char *ColName, const char *Value);
long  ArrayGetLongColumnData(OType ArrHandle,unsigned char Column,long Index);
/* Присвоить значение элементу массива в виде строки */
short ArrayPutStrColumnData(OType ArrHandle,unsigned char Column,long Index,const char *S);
/* Присвоить значение элементу массива в виде float */
short ArrayPutSingleColumnData(OType ArrHandle,unsigned char Column,long Index,float S);
/* Присвоить значение элементу массива в виде long */
short ArrayPutLongColumnData(OType ArrHandle,unsigned char Column,long Index,long L);
/* Получить число элементов массива */
long ArrayGetLen(OType ArrHandle);
/* Установить число элементов массива */
short ArraySetLen(OType ArrHandle,long Len);
/* Получить размер строки массива */
short ArrayGetElementSize(OType ArrHandle,unsigned short *ElementSize);
short ArrayGetItemType(OType ArrHandle,unsigned char Column,unsigned char *ItemType,unsigned short *ItemSize);
/* Получить пустую строку */
short ArrayBlankValue(OType ArrHandle,void *BP);
/* Проверяет строку на пустоту */
short ArrayValIsBlank(OType ArrHandle,unsigned char Column,long StartIndex,long EndIndex,LongBoolean *Res);
/* Опустошает строку */
short ArrayBlankIndex(OType ArrHandle,long Index);
/* Проверяет на пустоту колонку массива */
LongBoolean ArrayColumnIsBlank(OType ArrHandle,unsigned char Column);
/* Опустошает колонку массива */
short ArrayDoBlankColumn(OType ArrHandle, unsigned char Column, long Start, long Stop);
/* Проверяет на пустоту элемент массива */
LongBoolean ArrayColumnIndexIsBlank(OType ArrHandle,unsigned char Column,long Index);
/* Получить число колонок массива */
short ArrayGetColumns(OType ArrHandle,unsigned char *Colums);
/* Получить номер колонки по имени колонки */
short ArrayGetColNumByName(OType ArrHandle,const char *ColName,unsigned char *Column);
/* Удалить в элемент и подтянуть остальные вверх на один индекс */
/* Длина массива автоматически уменьшается на 1 */
short ArrayDeleteLine(OType ArrHandle,long Index);
/* Удалить в заданой колонке элемент и подтянуть остальные вверх на один индекс*/
/* Длина массива не уменьшается !*/
short ArrayDeleteColumnLine(OType ArrHandle,unsigned char Column,long Index);
/* Вставляет пустую строку. Следующие строки сдвигаются вниз */
short ArrayInsertLine(OType ArrHandle,long Index);
short ArrayInsertLineN(OType ArrHandle,long Index,long LCount);
/* Вставляет пустой элемент в строку. Следующие элементы сдвигаются вниз */
short ArrayInsertColumnLine(OType ArrHandle,unsigned char Column,long Index);
/* Сдвигает колонку на Delta элементов в зависимости от знака */
short ArrayShiftColumnLine(OType ArrHandle,unsigned char Column,long Delta);
/* Сдвигает колонку с номера BegN на Delta элементов в зависимости от знака */
short ArrayAtShiftColumnLine(OType ArrHandle,unsigned char Column,long BegN,long Delta);
/* Удаляет из массива указанный интервал элементов */
short ArrayDelInter(OType ArrHandle,long Start,long Stop);
/* Option = 0 - замена колонки; 1-добавление с конца */
short ArrayCopyColumn(OType FromArrHandle,OType ToArrHandle,unsigned char FromColumn,unsigned char ToColumn,unsigned char Option);
/* Получить индекс элемента по значению */
short GetNearstRigthNumber(OType ArrHandle,unsigned char Column,float Value,long *Number);
/* Получить номер наиболее близкого значения к Value */
short GetNumberByValue(OType ArrHandle,unsigned char Column,float Value,long *Number);
/* Получить индекс элемента по значению */
long GetFirstNumberByValue(OType ArrayHandle,unsigned char Column,float Value,long *Number);
/* Перевернуть массив вверх ногами */
short ArrayRevert(OType ArrHandle);
/* Изменить отсутствующие значения */
short ArrayChangeNull(OType ArrHandle,float NewNull,float OldNull,unsigned char BegCol,unsigned char EndCol,unsigned char ArgCol);
/* Вычислить минимальные и максимальные элементы массива */
short ArrayDoMinMax(OType ArrHandle,long StartN,long EndN);
/* Получить минимальные и максимальные элементы массива */
short ArrayGetMinMax(OType ArrHandle,unsigned short Column,OType *MinVal,OType *MaxVal);
/* То же, возвращает еще соответствующие индексы точек */
short ArrayGetMinMaxH(OType ArrHandle,unsigned short Column,long BegN,long EndN, float *MinVal,float *MaxVal,float *MidVal,long *MinN,long *MaxN);
/* Сортировка строк массива по заданной колонке */
short ArraySort(OType ArrHandle,unsigned char Column,long StartN,long EndN);

/*=================================================================================*/
/*  ПАЛЕТКИ */

/* Возвращает значение 2-мерной палетки по            */
/* PMode: интерполяция 1-линейная, 2-квадратичная, 3-кубическая */
/* DMask: направление преобразования 0-прямое, 1-обратное    */
/* AMode: способ линеаризации оси Х
0 - без преобразования значений Х,
1 - кварат,     2 - корень,
4 - ln натуральный, 8 - exp натуральная,
16- lg десятичный, 32 - exp десятичная.
FMode - то же для оси Y             */
/* Номер колонки аргумента = 1 всегда */
/* Для 2-мерной палетки FuncColumn (>1) - номер колонки ф-ии */
float GetPal2Value(OType ArrHandle,float ArgValue,unsigned char FuncColumn, unsigned short DMask,unsigned short PMode,unsigned short Amode,unsigned short FMode);

/* Возвращает значение 3-мерной палетки по линейной аппроксимации */
/* QValue-значение параметра */
float GetPal3Value(OType ArrHandle,float ArgValue,float QValue,unsigned short QMode, unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode);

/* Преобразование массива по двумерной палетке */
short DoPal2Value(OType ArrHandle,OType PalArrHandle,unsigned char Column,unsigned char PalFuncCol,long BegN,long EndN,unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode);

/* Преобразование массива по трехмерной палетке */
short DoPal3Value(OType ArrHandle,OType PalArrHandle,unsigned char Column,long BegN,long EndN,float QValue,unsigned short QMode,unsigned short DMask,unsigned short PMode,unsigned short AMode,unsigned short FMode);

/* Функция для палеточного массива возвращает параметр колонки палетки */
float GetPalParam(OType ArrHandle,unsigned char Col);

/* Возвращает колонку 3-мерной палетки по параметру палетки Value*/
unsigned char GetPalColumn(OType ArrHandle,float Value);

/* Возведение в квадрат */
short ASqr(OType FromArr,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Извлечение квадратного корня */
short ASqrt(OType FromArr,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

short ArrayRevLin(OType ArrHandle,OType FromArrHandle,float A,float B,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Вычисляет экспоненту */
short ArrayExponent(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);
/* Вычисляет экспоненту по основанию 10 */
short ArrayExp10(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Возводит в степень */
short ArrayPower(OType ArrHandle,OType FromArrHandle,float Delta,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);
/* Логарифмирует */
short ArrayLogarifm(OType ArrHandle,OType FromArrHandle,float Modul,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);
/* Вычисление градиента */
short ArrayGradient(OType ArrHandle,OType FromArrHandle,unsigned short FN,float Delta,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN);

/* Мажоритарный фильтр */
short ArrayFiltr(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Анализ монотонности 0*/
short ArrayKendal0(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Анализ монотонности 1*/
short ArrayKendal1(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Анализ монотонности 2*/
short ArrayKendal2(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Огибающая. Кind= 1-мин., 2-макс. */
short ArraySkin(OType ArrHandle,OType FromArrHandle,unsigned short Kind,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Сглаживание методом наименьших квадратов */
short ArraySmooth(OType ArrHandle,OType FromArrHandle,unsigned short FN,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN);

/* Сглаживание методом среднего арифметического */
short ArrayMeanSmooth(OType ArrHandle, OType FromArrHandle, unsigned short FN,
  unsigned char FirstCol, unsigned char LastCol,
  long BegN, long EndN);

/* Растяжение/сжатие */
short ArrayRubber(OType ArrHandle,OType FromArrHandle,unsigned char FirstCol,unsigned char LastCol,unsigned char ArgCol,long BegN,long EndN,long NewN,unsigned short Option);

/* Линейное преобразование Ax+B */
short ArrayLinModif(OType ArrHandle,OType FromArrHandle,float A,float B,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Преобразование по табличной зависимости, заданной массивом TarArrHandle
XTarCol, YTarCol - номера колонок аргумента и функции в массиве TarArrHandle */
short ArrayScaling(OType ArrHandle,OType FromArrHandle,OType TarArrHandle,unsigned char XTarCol,unsigned char YTarCol,unsigned char FirstCol,unsigned char LastCol,long BegN,long EndN);

/* Получить коэфф. полинома и отклонения от аппроксимации */
short ArrGetPolinom(OType ArrHandle,OType From,float Step,unsigned char n,unsigned char ArgColumn,unsigned char Column,long startN,long endN,float *aMdlSqDiv,float *aMaxAbsDiv,float *aMaxRelDiv,ArrS10 *bb);

/* Получить среднее и дисперсию */
short ArrayMean(OType ArrHandle,unsigned char BegCol,unsigned char EndCol,unsigned char ArgCol,long BegN,long EndN,float *MeanVal,float *Disp);

/* Получить индексы для интервала значений Roof, Sole */
long ArrayGetInterIndex(OType ArrHandle,unsigned char Column,float Roof,float Sole,long *RoofIndex,long *SoleIndex);

/* Выделение одной или двух колонок массива.
Если Option = 0, то колонки пустые
Option = 1, то колонки копируются */
short ArrayExtract(OType ArrHandle,unsigned char Column1,unsigned char Column2,unsigned short Option,OType *NewArr);
/* Добавить колонку в массив
  AtIndex- индекс колонки от 0
  Option - как выше +
  Option and 4 = 4, то изменения на месте
  Проверка колонки с таким именем, если (Option and 8) = 8 */
short ArrayAddColumn(OType ArrHandle, OType FDesc, unsigned short AtIndex, unsigned short Option, OType *NewArr);
/* Удалить колонку
  Option - как выше +
  Option and 4 = 4, то изменения на месте */
short ArrayDelColumn(OType ArrHandle, unsigned short Column, unsigned short Option, OType *NewArr);

/* Взять данные из массива с учётом преобразования структуры, ед. изм и т.п. */
short ArrayTakeData(OType MainArrHandle, OType FromArrHandle);
short ArrayTakeDataEx(OType MainArrHandle, OType FromArrHandle, unsigned short Option);


/* Работа с BLOB-полями */
long GetBlobByIndex(OType *BlobHandle, long Index, OType DataHandle);
long GetBlobSize(OType BlobHandle, long *Size);
long SetBlobLen(OType BlobHandle, long Len);
long BlobReadBuf(OType BlobHandle, long Position, long Size, void *Buf);
long BlobWriteBuf(OType BlobHandle, long Position, long Size, void *Buf);

/*============================================================================*/
/* ПРОСТОЕ ПОЛЕ СТРОКИ WS */

/* Открыть поле строки по имени */
short GetFieldVal(const char *AName,OType ObjHandle,OType *ObValHandle,unsigned char *T);
/* Получение значеий с преобразованием ед. измерения */
/* Unit - единица измерения для результата Value  */
short ObjGetFieldSingle(const char *AName,OType ObjHandle,const char *aUnit,float *Value);
/* Unit1 - единица измерения в таблице AName, если коэфф. Unit1->Unit не найден */
short ObjGetFieldSingleEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,float *Value);
short ObjGetFieldLong(const char *AName,OType ObjHandle,const char *aUnit,long *Value);
short ObjGetFieldLongEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,long *Value);
/* Присвоение значений с преобразованием единицы измерения */
/* Unit - исходная единица измерения для Value  */
short ObjPutFieldSingle(const char *AName,OType ObjHandle,const char *aUnit,float Value);
/* Unit1 - единица измерения в таблице AName, если коэфф. Unit->Unit1 не найден */
short ObjPutFieldSingleEx(const char *AName,OType ObjHandle,const char *aUnit,char *Unit1,float Value);
short ObjPutFieldLong(const char *AName,OType ObjHandle,const char *aUnit,long Value);
short ObjPutFieldLongEx(const char *AName,OType ObjHandle, const char *aUnit,char *Unit1, long Value);
short CopyFieldVal(const char *AName, OType ObjHandle, OType *ObValHandle, unsigned char *T);
short CopyObVal(OType ObValHandle, OType *NewObValHandle);
/* Открыть поле строки по номеру */
short GetObValByIndex( short Index,OType ObjHandle,OType *ObValHandle);
/* Открыть поле строки по номеру */
short CopyObValByIndex( short Index,OType ObjHandle,OType *ObValHandle);
/* Заменить поле строки по номеру */
short ReplaceObValByIndex( short Index,OType ObjHandle,OType ObValHandle);
/* Создать поле в соответствие с описателем и значением Value */
short ObValFDInit(OType FDescHandle,const char *Value,OType *ObValHandle);
/* Аналог MakeValueS */
short MakeObValS(unsigned char aType,const char *Value,unsigned short aLen,OType *ObValHandle);
/* Создать поле типа float */
short ObValSingleInit( float Value,OType *ObValHandle);
/* Создать поле заданного типа */
short ObValBoolInit(unsigned char Value,OType *ObValHandle);
short ObValDoubleInit(double Value,OType *ObValHandle);
short ObValIntInit( short Value,OType *ObValHandle);
short ObValWordInit(unsigned short Value,OType *ObValHandle);
short ObValByteInit(unsigned char Value,OType *ObValHandle);
short ObValStrInit(const char *Value,OType *ObValHandle);
/* Создать поле типа StringC */
short ObValStringInit(const char *Value,unsigned short Len,OType *ObValHandle);
/* Создать поле типа long */
short ObValLongIntInit(long Value,OType *ObValHandle);
/* Проверяет поле на отсутствующее значение */
short ObValIsBlank(OType ObValHandle,LongBoolean *IsBlank);
/* Пересылает значение в память */
short ObValMoveVal(OType ObValHandle,void *Buf);
/* Пересылает значение в поле */
short ObValPutVal(OType ObValHandle,void *Buf);
/* Получает значение поля типом String */
short ObValGetStr(OType ObValHandle,char *Res);
/* Получает форматированное значение поля типом String */
short ObValGetFStr(OType ObValHandle,unsigned short L,unsigned short D, char *Res);
/* То же, но работает для длинных (> 255) строк */
short ObValGetFPChar(OType ObValHandle, unsigned short L, unsigned short D, char *FStr, long SizeIncludingEOL);
/* Получает значение поля типом float */
float ObValGetSingle(OType ObValHandle);
/* Получает значение поля типом long */
long ObValGetLongInt(OType ObValHandle);
/* Получает длину поля в байтах */
short ObValGetSize(OType ObValHandle,unsigned short *Size);
/* То же, но работает для больших размеров (> 64K) */
short ObValGetLongSize(OType ObValHandle, long *Size);
/* Возвращает указатель на значение поля */
short ObValGetPointer(OType ObValHandle,void *P);
/* Присваивает значение полю типом String */
short ObValPutStr(const char *S,OType ObValHandle);
/* Присваивает значение полю типом float */
short ObValPutSingle(float S,OType ObValHandle);
/* Присваивает значение полю типом long */
short ObValPutLongInt(long Li,OType ObValHandle);
/* Сравнивает значение со значением в строке */
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
/* ОПЕРАЦИИ С ФАЙЛОМ WS */

/* Открывает строку из базы */
short Load_WS(const char *ResFName,const char *LoadFName,
  const char *Selected_Aim,const char *TName,unsigned short *RowNumber,
  OType *ObjHandle);
/* Открывает строку из базы, если даже она уже загружена */
short Load_WSEx(const char *ResFName,const char *LoadFName,
  const char *Selected_Aim,const char *TName,unsigned short *RowNumber,
  OType *ObjHandle);

/* Сохраняет строку в базе */
short Save_WS(const char *Selected_Aim,const char *TName,const char *SaveFName,LongBoolean CheckCopy,OType ObjHandle);

/* Сохраняет строку, если задано CheckIntent=True и результат=24, то возвращает измененную строку
   иначе NewObjHandle = hNil. NewObjHandle необходимо уничтожать самостоятельно */
short Save_WSEx(const char *Selected_Aim, const char *TName, const char *SaveFName,
				LongBoolean CheckCopy, LongBoolean CheckIntent,
				OType ObjHandle, OType *NewObjHandle);

short Save_WSExRW(const char *Selected_Aim, const char *TName, const char *SaveLogFileName,
	LongBoolean CheckThisCopy, OType ObjHandle);

/* ============================================================================*/
/* Изменяет отсутствующее значение по умолчанию */
void SetBlank(unsigned char vType,const char *Value);
float GetBlankSingle(void);

/* Создает с одним условием */
short MakeWhereData(OType *WhereDataH,const char *fldName,const char *fldValue);
/* Добавляет одно условие */
short AddWhereData(OType WhereDataH,const char *fldName,const char *fldValue);
/* Создает объект для поиска для функций FindFirst, FindNext */
short SearchDataInit(OType WhereDataH,OType SelectTD,OType *SearchDataH);
/* Быстро создает объект для поиска для функций FindFirst, FindNext */
/* Name1 = Val1, Name2=Val2, Name3=Val3 - условия поиска      */
short SSearchDataInit(const char *Name1,const char *Val1,const char *Name2,const char *Val2,const char *Name3,const char *Val3,OType TableHandle,OType *SearchDataH);
/* Подготовка для сравнения. Эффективно для поиска в таблице TDescH */
short PrepareCond(OType SearchDataH,OType TDescH);
short GetSOData(OType SOHandle,CSODataType *SOData);
short SetSOData(OType SOHandle,CSODataType SOData);
short SetSOpers(OType SOHandle,short Index,const char *SOPer);
short AddSOper(OType SOHandle,const char *Oper);
short SetSTable(OType SOHandle,const char *TablName);
/* Сравнение условий SearchDataH со строкой DataObjH */
short CompCond(OType SearchDataH,OType DataObjH,LongBoolean *Result);
short LoadSO(OType *SearchDataH,const char *FName);
short StoreSO(OType SearchDataH,const char *FName);
void  DatServCounters(void);
void  DoTxtMaket(OType RedObjHandle,OType RezObjHandle,const char *MetName,const char *FName);

void *DSGetTableCollection(OType LFHandle);

/* Функции для получения счетчиков сервера данных в отладочных целях*/
short GetSysDataCount(void);
short GetSysLogFileCount(void);
short GetSysLRCursorCount(void);
short GetSysLogRecCount(void);
short GetSysDataObjCount(void);
short GetSysArrayCount(void);
short GetSysObValCount(void);
short GetSysTDescCount(void);
short GetSysFDescCount(void);

/* Проверка версии ресурса. 0 - OK, -1 - устаревшая версия */
short CheckResVersion(const char *ResFileName, const char *TableName, const char *CurrentResVersion);

/* Получение максимальной длины массива (или другого объекта) */
long GetLenLimit(OType O);

/* Получить количество строк в поле типа Memo */
long MemoGetLineCount(OType hMemo);
/* Получить строку из поля типа Memo по её индексу */
long MemoGetLine(OType hMemo, long Index, char *Str, long StrMaxLen);
/* Заменить строку с заданным индексом в поле типа Memo новым значением */
long MemoSetLine(OType hMemo, long Index, const char *Str);
/* Вставить новую строку перед строкой с заданным индексом в поле типа Memo */
long MemoInsertLine(OType hMemo, long Index, const char *Str);
/* Удалить строку с заданным индексом из поля типа Memo */
long MemoDeleteLine(OType hMemo, long Index);
/* Добавить строку в конец поля типа Memo */
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
// Форматирование значений типа Дата/Время
LongBoolean GetDateByFormat(const char *Value, const char *Format, DateRecType *DSDateRec);
LongBoolean GetTimeByFormat(const char *Value, const char *Format, TimeRecType *DSTimeRec);
//
//// Работа с буфером данных
//// Очистка буфера от всех данных
//long ClearAllBuf(void);
//long ClearSubBuf(const char *SubName);
//// Передача данных в буфер
//long SetBufData(const char *Name, const char *SubName, const char *StrValue, double RValue,
//          void *PValue, long DType, long Option, void *Reserved);
//// Получение данных из буфера
//long GetBufData(const char *Name, const char *SubName, char *StrValue,
//          double *RValue, void **PValue, long *DType,
//          long Option, void *Reserved);
//
//// Ф-я для получения информации о кривой на планшете
//long GetPlanCurveInfo(const char *WSName, const char *CurveKeyStr, const char *Tmp, long Option,
//                      char *ValueName, char *IndexStr, char *Reserv,
//                      long *ArrayIndex, long *RowIndex, long *Count, long *TmpInt);
//// Получение списка ключ. строк, удовлетворяющих условию IfStr
//// Необходимо выделить предварительно память для KeyDataStrList и указать этот размер в MaxListLen
//// Для ErrStr длостаточно будет выделять длину в 255 символов.
//short LRGetKeyStrListByCond(OType LRHandle,
//                  const char *IfStr, const char *KeyDataStrList, const char *ErrStr,
//                  long MaxListLen, long  Option);
//
void DSDoneObject(void *P);
///* ========================================================================= */
///* Функции для работы с динамическими строками */
///* Создать строку */
//
PPasString DSNewPString(const char *S);
///* Зарезирвировать место под строку */
//PPasString DSMemPString(unsigned char Len);
///* Получить значение строки */
//PPasString DSGetPString(PPasString P);
///* Получить длину строки */
//function DSLenPString(PPasString P): Byte;
//void DSPutPString(PPasString P, const char *S, unsigned char I, unsigned char N);
//void DSFillPString(PPasString P, char Ch, unsigned char I, unsigned char N);
///* Уничтожить строку */
//void DSFreePString(PPasString P);
///* ========================================================================= */
//void *DSGetMemLib(long ASize);
//void *DSFreeMemLib(void *P, long ASize);
//void *DSAllocMemLib(long ASize);
//void DSReallocMemLib(void **P, long NewSize);
//void DSPCharDispose(char *P);
///* ========================================================================= */


/* Создать новую коллекцию объектов */
void* DSInitList(long Limit = 8, long Delta = 8);
/* Создать новую коллекцию строк */
void* DSInitStringList(long Limit = 8, long Delta = 8);
/* Создать новую коллекцию указателей */
void* DSInitEmptyList(long Limit = 8, long Delta = 8);
/* Создать новую коллекцию несортированных строк */
void* DSInitUnsortList(long Limit = 8, long Delta = 8);
/* Возвращает число элементов коллекции */
long DSListCount(void *List);
/* Возвращает элемент по его индексу */
void* DSListAt(void *List,long Index);
/* Удаляет элемент из коллекции */
void DSListAtDelete(void *List,long Index);
/* Уничтожает элемент коллекции */
void DSListAtFree(void *List,long Index);
/* Вставить элемент в коллекцию */
void DSListAtInsert(void *List,long Index,void* Item);
/* Изменить элемент коллекции */
void DSListAtPut(void *List,long Index,void *Item);
/* Удалить элемент коллекции */
void DSListDelete(void *List,void *Item);
/* Удаляет из коллекции все его элементы */
void DSListDeleteAll(void *List);
/* Уничтожает элемент коллекции */
void DSListFree(void *List,void *Item);
/* Уничтожает все элементы коллекции */
void DSListFreeAll(void *List);
/* Возвращает индекс данного элемента в коллекции */
long DSListIndexOf(void *List,void *Item);
/* Добавляет элемент в коллекцию */
void DSListInsert(void *List,void *Item);
/* Удаляет из коллекции пустые элементы */
void DSListPack(void *List);
/* Поиск строки в коллекции (только для коллекций строк) */
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

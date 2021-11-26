/***************************************************************************\
*                                                                           *
* Система информационного обеспечения геофизических исследований скважин    *
*   "ПРАЙМ" для Windows                                                     *
* Интерфейс к визуальному интерпретатору: константы и структуры             *
* Язык: C++                                                                 *
* Версия: 4.06.12                                                           *
* (C) НПФ ГеоТЭК, 1999, 2007                                                *
*                                                                           *
\***************************************************************************/

#ifndef _PRIMEAPI_
#define _PRIMEAPI_
#include <windows.h>
#include "dsapi.h"

#ifdef _MSC_VER
  /* Microsoft Visual C++ */
  #pragma pack( push, ENTER_PRIMEAPI, 1 )
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

/* Типы объектов на планшете возвращаемые функцией WSType */
const long wsUnknown       = 0;   /* Тип не принадлежит ни одному из перечисленных */
const long wsViewCurve     = 1;   /* Кривая */
const long wsViewPoint     = 2;   /* Примитив */
const long wsViewInter     = 3;   /* Интервал */
const long wsViewNotes     = 4;   /* Надпись */
const long wsViewTower     = 5;   /* Пустая колонка */
const long wsTowerDepth    = 6;   /* Колонка глубин */
const long wsTowerInter    = 7;   /* Попластовая колонка */
const long wsTowerLnGrid   = 8;   /* Линейная сетка */
const long wsTowerLgGrid   = 9;   /* Логарифимическая сетка */
const long wsTowerRvGrid   = 10;  /* Обратная сетка */
const long wsViewScale     = 11;  /* Шкала */
const long wsViewPicture   = 12;  /* Рисунок на планшете */
const long wsViewTwoDCurve = 14;  /* 2-мерная кривая */
const long wsInterReper    = 100; /* Репер */

#define NormalPut  0    /* Обычный способ вывода  */
#define ANDPut     1    /* Наложение              */
#define ORPut      2    /*       логических       */
#define XORPut     3    /*               операций */
#define TransPut   4    /* Просвечивающимся фоном */


/* Список констант для интерактивного взимодействия с планшетом */
/* Для строки форматирования вывода информации в строке статуса */

/*  0 - Глубина;
1 - Начало;
2 - Значение;
3 - Ширина;
4 - Высота;
5 - Дельта;
6 - Интервал; */

#define tmDepthLine  0x0001 /* Использовать горизонтальную линию */
#define tmStartLine  0x0002 /* Использовать вертикальную линию */
#define tmDepthLimit 0x0004 /* Запретить перемещение по глубине */
#define tmStartLimit 0x0008 /* Запретить перемещение по горизонтали */
#define tmDrawCross  0x0010 /* Рисовать в точке отслеживания крестик */
#define tmDrawLine   0x0020 /* Рисовать линию  от начальной точки до текущей */
#define tmDrawBox    0x0040 /* Рисовать прямоугольник от начальной точки до текущей */
#define tmShowInfo   0x0080 /* Выводить в строке статуса информацию о данной точке */
#define tmStartPoint 0x0100 /* Начать отслеживание с начальной точки */
#define tmWidthLimit 0x0200 /* Обязательно ненулевое значение ширины */
#define tmDeltaLimit 0x0400 /* Обязательно ненулевое значение интервала по глубине */
#define tmDepthRange 0x0800 /* Глубина не должна выходить за указанный интервал */
#define tmKeepMouse  0x1000 /* Не изменять позицию мыши */

/* Маски флагов элемента легенды */
#define lfShowLegend   0x00000001
#define lfShowName     0x00000002
#define lfEqualWidths  0x00000004

/* Маски и количество битов для сдвига флагов общих параметров легенды */
#define lfcShowName    0x00000003
#define lfiShowName    0
#define lfcEqualWidths 0x0000000C
#define lfiEqualWidths 2

extern char *tnPlansheet;
extern char *tnPointTable;
extern char *tnInterTable;
extern char *tnCurveTable;
extern char *tnLitolTable;
extern char *fnMinValue;
extern char *fnMaxValue;
extern char *fnStrValue;
extern char *fnBMPIndex;
extern char *fnBMPName;
extern char *fnBMPWidth;
extern char *fnBMPHeigth;
extern char *fnBMPInvers;
extern char *fnBMPColor;

/* Названия массивов с интервалы в таблице ПРИМИТИВЫ_ИНТЕРВАЛА */
extern char *inPerfProekt;  /* 00 - Интервалы перфорации проектные   */
extern char *inPerfFact;    /* 01 - Интервалы перфорации фактические */
extern char *inIntSostPrit; /* 02 - Интервалы и составы притоков     */
extern char *inPrinInter;   /* 03 - Принимающие интервалы            */
extern char *inMoveFluid;   /* 04 - Интервалы движения жидкости по неперфорированным пластам */
extern char *inMPlPDown;    /* 05 - Интервалы межпластовых перетоков сверху */
extern char *inMPlPUp;      /* 06 - Интервалы межпластовых перетоков снизу */
extern char *inPeretDown;   /* 07 - Интервалы перетоков в остановленной скважине сверху */
extern char *inPeretUp;     /* 08 - Интервалы перетоков в остановленной скважине снизу */
extern char *inZKCDown;     /* 09 - Интервалы заколонной циркуляции сверху */
extern char *inZKCUp;       /* 10 - Интервалы заколонной циркуляции снизу */
extern char *inPatrubok;    /* 11 - Местонахождение патрубка в обсадной колонне */
extern char *inFilterPaker; /* 12 - Местонахождение фильтра пакера */

extern char *pnNegermCol;   /* 00 - */
extern char *pnNegermNKT;   /* 01 - */
extern char *pnIskustZab;   /* 02 - */
extern char *pnMoveFluid;   /* 03 - */
extern char *pnPakerPlace;  /* 04 - */
extern char *pnBaschmExpl;  /* 05 - */
extern char *pnBaschmTech;  /* 06 - */
extern char *pnBaschmStop;  /* 07 - */
extern char *pnBaschmObsd;  /* 08 - */
extern char *pnBaschmNapr;  /* 09 - */
extern char *pnBaschmCond;  /* 10 - */
extern char *pnBaschmNKT;   /* 11 - */

extern char *pnUstDoubleC;  /* 12 - */
extern char *pnStopRound;   /* 13 - */

extern char *pnCementLev;   /* 14 - */
extern char *pnNKTKlapan;   /* 15 - */
extern char *pnRNKTKlapan;  /* 16 - */
extern char *pnDynamycLev;  /* 17 - */
extern char *pnGVR;         /* 18 - */
extern char *pnGNR;         /* 19 - */
extern char *pnNVR;         /* 20 - */
extern char *pnGAS;         /* 21 - */
extern char *pnNAS;         /* 22 - */
extern char *pnNASKlapan;   /* 23 - */
extern char *pnCentrFonar;  /* 24 - */

extern char *fnPointDepth;
extern char *fnGerm;
extern char *fnGermOk;
extern char *fnGermDown;
extern char *fnGermUp;
extern char *fnOilDirect;
extern char *fnOilOut;
extern char *fnOilIn;
extern char *fnOilDown;
extern char *fnOilUp;
extern char *fnOilDownIn;
extern char *fnOilUpIn;
extern char *fnOilOutDown;
extern char *fnOilOutUp;
extern char *fnInterRoof;
extern char *fnInterSole;
extern char *fnWaterCont;
extern char *fnGasContent;
extern char *fnTimeStamp;

extern char *fnMethodName;
extern char *fnMethodUnit;
extern char *fnCurveRoof;
extern char *fnCurveSole;
extern char *fnCurveStep;
extern char *fnCurveValue;
extern char *fnBlankValue;
extern char *fnVersion;
extern char *fnDepthShift;
extern char *fnDepthValue;

extern char *tnProject;
extern char *fnProjectShortName;
extern char *fnProjectDesc;
extern char *anVPTs;

/* Режимы отработки планшетом */
const long hmCurve         = 0;  /* Отрабатываются кривые */
const long hmPoint         = 1;  /* Отрабатываются примитивы */
const long hmInter         = 2;  /* Отрабатываются интервалы */
const long hmTower         = 3;  /* Отрабатываются колонки */
const long hmNotes         = 4;  /* Отрабатываются замечания */
const long hmFills         = 5;  /* Отрабатываются заливки */
const long hmReper         = 6;  /* Отрабатываются хорды */
const long hmScale         = 7;  /* Отрабатываются шкалы */
const long hmPlanPicture   = 8;  /* Отрабатываются рисунки планшета */
const long hmPlanTwoDCurve = 10; /* Отрабатываются 2-мерные кривые */

/* Режимы отработки отчетом */
const long hmFrame  = 0; /* */
const long hmText   = 1; /* */
const long hmTable  = 2; /* */
const long hmBitmap = 3; /* */
const long hmLine   = 4; /* */

/* Флажки состояний объектов планшета */
#define psActivated 0x0001 /* Объект активизирован */
#define psHideTrace 0x0002 /* Объект непрозрачен для трассировочных лучей */
#define psAltMouse  0x0004 /* Объект особым образом обрабатывает мышь внутри него */
#define psBackColor 0x0008 /* Объект рисуется цветом фона планшета */
#define fsActivated 0x0001 /* Фрейм активизирован  */

/* Флажки для вывода кривой */
#define cfBedDraw    0x0001 /* Рисовать кривую как попластовый массив     */
#define cfGridDraw   0x0002 /* Разграфка масштабной линейки               */
#define cfFloatDraw  0x0004 /* Плавающее значение на нуле ("умный" ноль ) */
#define cfDrawLines  0x0008 /* Соединять точки дискретизации линиями      */
#define cfDrawPixel  0x0010 /* Отображать точки дискретизации             */
#define cfDrawHidden 0x0020 /* Отображать скрытые линии                   */
#define cfDrawHeader 0x0040 /* Отобразить масштабную линейку для кривой   */
#define cfDrawBreakA 0x0080 /* Отображать значения на разрывах до разрыва */
#define cfDrawBreakP 0x0100 /* Отображать значения на разрывах после      */
#define cfSmartBreak 0x0200 /* "Разумное" поведение значений на сносах    */
#define cfLogScale   0x0400 /* Рисовать кривую в логарифмическом масштабе */
#define cfDrawTicks  0x0800 /* Отображать значения на рисках */
#define cfHideMax    0x1000 /* Отключать вывод значения максимума */
#define cfAddUnit    0x8000 /* Добавлять к значениям название единицы изм.*/
#define cfKeepZero   0x4000 /* Оставлять незначащие нули */
#define cfHMirror    0x2000 /* Отразить по горизонтали */

/* Режимы отработки отрицательных значений */
#define svSignNot 0 /* Отрабатывать как отрицательные значения */
#define svSignNul 1 /* Отрабатывать как нулевые значения       */
#define svSignAbs 2 /* Отрабатывать как положительные значения */
#define svSignExl 3 /* Отрабатывать как отсутствующие значения */

/* Вывод различных ипостасей попластовых колонок */
const unsigned short itShowDepth        = 0x0001; /* Значений глубин */
const unsigned short itShowValue        = 0x0002; /* Значений параметра */
const unsigned short itShowStrat        = 0x0004; /* Названий стратиграфий */
const unsigned short itShowLitol        = 0x0008; /* Рисунков литологий */
const unsigned short itShowTrace        = 0x0010; /* Трассировочных лучей */
const unsigned short itHideHeader       = 0x0020; /* Не выводить название в шапке */
const unsigned short itPlastData        = 0x0040; /* Данные колонки - попластовые */
const unsigned short itFullSheetFiller  = 0x0080; /* Рисовать заливки по всей ширине планшета */
const unsigned short itUniteEqualPlasts = 0x0100; /* Объединять одинаковые пласты */
const unsigned short itSourceTower      = 0x0200; /* Исходная колонка (иначе - результирующая) */

/* Отработка выхода значений за область представления */
#define mvNothing     0 /* Не отрабатывать                     */
#define mvExclude     1 /* Исключить из кривой                 */
#define mvStrip       2 /* Ограничивать пределом               */
#define mvShift       3 /* Перенос 1:1                         */
#define mvRescale2    4 /* Снос 1:2                            */
#define mvRescale5    5 /* Снос 1:5                            */
#define mvRescale10   6 /* Снос 1:10                           */
#define mvRescale100  7 /* Снос 1:100                          */
#define mvRescaleFree 8 /* Снос кратности пользователя         */

/* Тип ограничителя на концах масштабной линейки */
#define avNothing   0  /* Нет ничего */
#define avTickUp    1  /* Риска вверх */
#define avTickDown  2  /* Риска вниз */
#define avTickFull  3  /* Поперечная риска */
#define avArrowOut  4  /* Стрелка наружу */
#define avArrowIn   5  /* Стрелка внутрь */
#define avArrowFull 6  /* Стрелки с ограничителями */

#define CurveLevelsNum 10
#define CurveDepthsNum 10

/* Расширенные флажки кривой */
const long cfeDrawNewPoints = 0x00000001;         /* Отображать значки на кривой */
const long cfeDisablePointsInHeader = 0x00000002; /* Не рисовать значки на линейке */
const long cfeDrawNewDepthValues = 0x00000004;    /* Отображать значения на глубинах с шагом */
const long cfeNewDepthOnRoofAndSole = 0x00000008; /* Отображать значения на кровле и подошве кривой */
const long cfeNewDepthStepInQuants = 0x00000010;  /* Шаг значений задаётся в точках дискретизации (иначе - в cм. планшета) */
const long cfeBreakNumber = 0x00000020;           /* Отображать номер сноса вместо значения */
const long cfeValuesOnAllTicks = 0x00000040;      /* Отображать значения на всех рисках */
const long cfeResultCurve = 0x00000080;           /* Результирующая кривая (не для WSGetData!) */
const long cfeResultCurve_Get = 0x00000100;       /* Результирующая кривая (только для WSGetData!) */
const long cfeAutoMin = 0x00000200;               /* Автоматический подбор значения на "0" */
const long cfeAutoScale = 0x00000400;             /* Автоматический подбор масштаба */
const long cfeDepthValuesNoArrow = 0x00000800;    /* Не рисовать стрелку для значений на глубинах */
const long cfeDepthValuesCenterBed = 0x00001000;  /* Для попластовых кривых значения выводить посередине пласта */
const long cfeNewLineStyle = 0x00002000;          /* Стиль линии кривой определяется новыми параметрами */
const long cfeRValueDeterminesScale = 0x00004000; /* Масштаб определяется правым значением */
const long cfeDisableGridWarning = 0x00008000;    /* Не ругаться при несоответствии с сеткой */
const long cfeMinimalHeaderHeight = 0x00010000;   /* По возможности уменьшить размер линейки по высоте */
const long cfeSumMode = 0x00020000;               /* Режим суммирования при отрисовке */
const long cfeUnitOnLineWithMethod = 0x00040000;  /* Выводить единицу измерения на одной строке с методом */
const long cfeDrawNailsOnPoints = 0x00080000;     /* Отображать "гвоздики" от значков до нулевой линии */
const long cfeBreakColors = 0x00100000;           /* Выделять разные номера сносов цветами */

/* Типы значков на кривой */
const unsigned char cptNone          = 0; /* Нет значка */
const unsigned char cptPixel         = 1; /* 1 пиксел */
const unsigned char cptEmptyCircle   = 2; /* Окружность */
const unsigned char cptEmptySquare   = 3; /* Граница квадрата */
const unsigned char cptEmptyTriangle = 4; /* Остов треугольника */
const unsigned char cptCircle        = 5; /* Круг */
const unsigned char cptSquare        = 6; /* Квадрат */
const unsigned char cptTriangle      = 7; /* Треугольник */
const unsigned char cptStar          = 8; /* Звёздочка */
const unsigned char cptRect2x1       = 9; /* Прямоугольник с пропорциями 2x1 */
const unsigned char cptRect4x1       = 10; /* Прямоугольник с пропорциями 4x1 */
const unsigned char cptRect8x1       = 11; /* Прямоугольник с пропорциями 8x1 */

typedef unsigned char TNailWidthMode; /* Режим ширины "гвоздя" (или вектора) */

const TNailWidthMode nwmQuarterPointSize = 0;
const TNailWidthMode nwmLineWidth = 0;
const TNailWidthMode nwmArbitrary = 0;

typedef unsigned char TVectorLengthMode; /* Режим длины вектора */

const TVectorLengthMode vlmPointSize = 0;
const TVectorLengthMode vlmFiveTimesLineWidth = 1;
const TVectorLengthMode vlmArbitrary = 2;

typedef unsigned char TVectorAngleUnit; /* Единица измерения угла вектора */
const TVectorAngleUnit vauUnknown = 0;  // Неизвестна
const TVectorAngleUnit vauDegrees = 1;  // Градусы
const TVectorAngleUnit vauRadians = 2;  // Радианы
const TVectorAngleUnit vauGrads   = 3;  // Грады (360 градусов = 400 град)
const TVectorAngleUnit vauParts   = 4;  // Части окружности (1 часть = 360 градусов)

typedef unsigned char TVectorStartAngle; /* Место отсчёта углов (относительно стандартной - 0 градусов справа, против часовой стрелки) */
const TVectorStartAngle vsa0   = 0;
const TVectorStartAngle vsa90  = 1;
const TVectorStartAngle vsa180 = 2;
const TVectorStartAngle vsa270 = 3;

/* Флаги вектор-кривой (поле VectorFlags записи TViewCurveRec) */
const long vcfInvertAngle       = 0x00000001; // Отсчёт углов производить по часовой стрелке
const long vcfIndividualColor   = 0x00000002; // Имеется колонка цвета векторов
const long vcfIndividualBGColor = 0x00000004; // Имеется колонка цвета заливки

/* Типы масштабной линейки */
const unsigned short htStandard      = 0; /* Обычная */
const unsigned short htAmplitude     = 1; /* Размах амплитуды */

/* Расположение значений относительно кривой */
const unsigned char dvpAuto  = 0;
const unsigned char dvpRight = 1;
const unsigned char dvpLeft  = 2;

typedef unsigned char TCurveLineStyleIndex;
const TCurveLineStyleIndex clsiDisplay = 0;
const TCurveLineStyleIndex clsiMono    = 1;
const TCurveLineStyleIndex clsiColor   = 2;

/* Флаги нового стиля линий кривой */
const unsigned char lsfUseMonoStyle  = 0x01; /* Задан стиль для монохромных устройств */
const unsigned char lsfUseColorStyle = 0x02; /* Задан стиль для цветных устройств */

const long nfOpaque = 0x00000001; /* Непрозрачный фон надписи */

/* Флаги планшета */
const long psfAutoRoof              = 0x00000001; /* Автоматический расчёт кровли */
const long psfAutoSole              = 0x00000002; /* Автоматический расчёт подошвы */
const long psfAutoWidth             = 0x00000004; /* Автоматический расчёт ширины */
const long psfUseDepth              = 0x00000008; /* Использовать текущую глубину */
const long psfNoHeaderFrame         = 0x00000010; /* Не рисовать рамку вокруг шапки/подвала */
const long psfAutoDistributeLegends = 0x00000020; /* При загрузке автоматически распределять элементы легенды по классам */
const long psfAutoPlaceLegends      = 0x00000040; /* При загрузке автоматически размещать элементы легенды */
const long psfAutoReloadOnCreate    = 0x00000080; /* При создании из шаблона автоматически загружать данные кривых/колонок */
const long psfArchiveMode           = 0x00000100; /* Архивный планшет */
const long psfAutoScaleWidth        = 0x00000200; /* При просмотре планшет всегда масштабируется по ширине окна */

/* Флаги SetStandardLayerCodeByIndex, GetStandardLayerCodeByIndex */
const long slcMarkMissing = 0x00000001; /* При отсутствии кодировки добавлять спереди знак "+" */

/* ==== Далее идут записи для работы через WSGetData и WSSetData ========= */
/* ==== Все значения размеров в 0.1мм                                 ==== */
/* ==== Все значения глубин в сантиметрах                             ==== */
/* ======================================================================= */

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

typedef struct {
    short SampleLength;
    unsigned char BitLength;
    unsigned char Bits[13];
} TCurveLinePattern;

typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char Width;
    TCurveLinePattern Pattern;
} TCurveLineStyle;

/* Запись для кривых */
typedef struct {
	//unsigned char CurveInfoLength;
	PasString CurveInfo; /* Ключевая информация о кривой (не изменяется) */
    /* Параметры отображения данной кривой */
	unsigned short Curve;       /* Номер кривой (см.файл WSIGF.CRV) */
	long Start;    /* Начало области размещения кривой */
	long Width;    /* Ширина области размещения кривой */
	float Minimum;   /* Значение кривой на левой границе */
	float Scale;     /* Масштаб кривой (физ.ед.на 1 см.) */
	long Modul;    /* Модуль логарифмического масштаба */
	float Power;     /* Основание логарифм.масштаба      */
	unsigned short Flags;       /* Флажки отрисовки кривой (cfXXXX) */
	unsigned short MHIndex;     /* Обработка сносов (mvXXXX)        */
	unsigned short MHValue;     /* Значение нестанд.коэфф.перемасш. */
	unsigned short SHIndex;     /* Обработка отрицательных (svXXXX) */
	//unsigned char ValueNameLength;
	PasString ValueName; /* Название метода данной кривой    */
	//unsigned char ValueUnitLength;
	PasString ValueUnit; /* Название единицы измерения       */
    /* Параметры отображения масштабной линейки */
	unsigned short HeaderType;  /* Тип масштабной линейки: 0 - обычная, 1-размах (htXXXX) */
	unsigned short ValueJust;     /* Выравнивание значений на масштабной линейке */
	long ValueIndent;      /* Отступ значений на масштабной линейке */
	//unsigned char ValueFontLength;
	PasString ValueFont;                     /* Шрифт для вывода значений */
	long ValueSize;            /* Высота шрифта для вывода значений */
	unsigned char ValueZero;  /* Число знаков после запятой для вывода значений */
	//unsigned char Length;
	PasString NameFont;               /* Шрифт для вывода названия метода */
	long NameSize;      /* Высота шрифта для вывода названия метода */
	unsigned short ValueKeep;                       /* Оставлять незначащие нули */
	//unsigned char Length;
	PasString UnitFont;             /* Шрифт для вывода единицы измерения */
	long UnitSize;    /* Высота шрифта для вывода единицы измерения */
	long ValueAdds;     /* Число дополнительных значений на линейке */
    /* Типы и размеры значков на концах масштабной линейки */
	unsigned short LeftArrow;                /* ...тип значка слева */
	unsigned short RightArrow;              /* ...тип значка справа */
	long ArrowSize;              /* ...размеры значков */
    /* Размеры пропусков */
	long InterLine;  /* между строками в названии метода или ед.изм.*/
	long SkipBefore;                   /* перед масштабной линейкой */
	long SkipAfter;                     /* после масштабной линейки */

    /* Параметры вывода значений на разрывах */
	string64 BreakFont; /* Название шрифта для вывода */
    /* Параметры вывода значений на глубинах */
	string64 DepthFont;      /* Шрифт вывода значений на глубинах */
	long DepthSize;          /* Размеры шрифта для вывода */
	unsigned char DepthZero; /* Число знаков после запятой */
	char Reserved3[108]; /* Вот так приходится извращаться */
    /* Параметры вывода значений на разрывах - продолжение */
        unsigned char BreakColorCount; /* Число различных цветов для сносов разного порядка */
        struct { unsigned char R; unsigned char G; unsigned char B; } BreakColors[4]; /* Цвета для сносов разного порядка */
    /* Параметры вывода значений на разрывах - продолжение */
	long BreakSize; /* Размеры шрифта для вывода */
	unsigned char BreakZero;    /* Число знаков после запятой */
    /* ...параметры по вертикали */
	unsigned short BreakVertAfter;     /* выравнивание после разрыва */
	unsigned short BreakVertBelow;     /* выравнивание до разрыва */
	long BreakVertIndent; /* отступ от точки разрыва */
    /* ...параметры по горизонтали */
	unsigned short BreakHorizAfter;  /* ---- ||| ---- */
	unsigned short BreakHorizBelow;  /* ---- ||| ---- */
	short BreakHorizIndent; /* ---- ||| ---- */
    /* Вывод значений на шапке кривой */
	unsigned short HeaderManual;     /* Значения устанавливаются вручную */
	float HeaderLeftVal;  /* Значение слева */
	float HeaderRightVal; /* Значение справа */

    /* Данные относящиеся к линиям уровня */
	short LevelMask; /* Какие линии уровня выводить, а какие нет */
	float Level[CurveLevelsNum];
    /* Данные относящиеся к значениям на глубине */
	long DepthMask; /* Какие значения на глубине, а какие нет */
	long Depth[CurveDepthsNum];
	unsigned short AddUnit; /* Добавлять к значению название единицы */

    /* Данные, позволяющие получить доступ к объекту из WS файла */
	OType DataHandle; /* Описатель строки таблицы */
	unsigned short RowNumber;  /* Номер этой строки в таблице */
	OType ArrayHandle; /* Описатель массива с данными кривой */
	unsigned short ColNumber;  /* Номер колонки в массиве */
	//unsigned char Length;
	PasString ArrayName;  /* Название массива */
	//unsigned char Length;
	PasString TableName;  /* Название таблицы */
        /* Данные о том, откуда была создана кривая */
        string64 ResFile;
        string64 ResName;
        PasString ValueCode; /* Код метода ГИС */
        string64 UnitCode; /* Код единицы измерения */
        unsigned char NewLineStyleFlags; /* lsfXXXX */
        TCurveLineStyle NewLineStyles[3];
        long EFlags; /* см. cfeXXXX */
        unsigned char PointType; /* Тип значка на кривой (см. cptXXXX) */
        long PointSize; /* Размер значка в 0.1 мм */
        short PointFreq; /* Частота. Если > 0, то в мм/значок, иначе - в точках дискр./значок */
        long NewDepthValuesAnchor; /* Начальная глубина, см (либо начальная точка дискретизации) */
        long NewDepthValuesStep; /* Шаг, см (либо точек дискр.) */
        unsigned char NewDepthsValuesPos;
        float RightValue; /* Значение кривой на правой границе (если в EFlags задан флаг cfeRValueDeterminesScale) */
        void *PrevSumCurve; /* Предыдущая суммируемая кривая (если в EFlags задан флаг cfeSumMode) */
        TNailWidthMode NailWidthMode; /* Режим толщины "гвоздей" */
        unsigned char NailWidth; /* Толщина "гвоздей", 0.1 мм */
        void *LeadDepthColObject; /* Объект с ведущей колонокй глубин */
        /* ТОЛЬКО ДЛЯ ВЕКТОР-КРИВОЙ - НАЧАЛО */
        TNailWidthMode VectorWidthMode; /* Режим толщины вектора */
        unsigned char VectorWidth; /* Толщина вектора, 0.1 мм */
        TVectorLengthMode VectorLengthMode; /* Режим длины вектора */
        unsigned short VectorLength; /* Длина вектора, 0.1 мм */
        TVectorAngleUnit VectorAngleUnit; /* Ед. изм. угла вектора */
        long VectorColNumber; /* Номер колонки данных угла вектора */
        long CurvePointAnotherColor; /* Другой цвет контура векторов или 0x1FFFFFFF */
        long InnerCurvePointColor; /* Цвет заливки внутри векторов или 0x1FFFFFFF */
        long CurvePointEdgeWidth; /* Толщина контура векторов в 0.1 мм или 0 */

        long VectorFlags; /* Флаги векторов, vcfXXXX */
        long VectorColorColNumber; /* Номер колонки данных с цветом вектора */
        long VectorBGColorColNumber; /* Номер колонки данных с цветом заливки */
        TVectorStartAngle VectorStartAngle; /* Начало отсчёта углов */
        /* ТОЛЬКО ДЛЯ ВЕКТОР-КРИВОЙ - КОНЕЦ */
        char Reserved[64];
} TViewCurveRec, *PViewCurveRec;

/* Запись для примитивов */
typedef struct {
    long Start;    /* Позиция для установки примитива */
    long Width;    /* Размеры примитива */
    long Color;    /* Цвет примитива */
    long Depth;    /* Глубина примитива */
    OType ArrHandle;  /* Описатель массива с данным примитивом */
	//unsigned char Length;
    PasString ArrayName; /* Название массива с данным примитивом */
    long ArrayRow; /* Номер строки для данного примитива в массиве */
    char Reserved[32];
} TViewPointRec, *PViewPointRec;

/* Запись для интервалов */
typedef struct {
    long Start;      /* Позиция для установки интервала */
    long Width;      /* Размеры интервала */
    long Color;      /* Цвет интервала */
    long Roof, Sole; /* Кровля и подошва интервала */
    OType ArrHandle;    /* Описатель массива с данным интервалом */
	//unsigned char Length;
    PasString ArrayName;   /* Название массива с данным интервалом */
    long ArrayRow;   /* Номер строки для данного интервала в массиве */
    char Reserved[32];
} TViewInterRec, *PViewInterRec;

typedef struct {
    long Start;
    long Width;
    unsigned short Color;
    long ArrayRow;
    OType ArrayHandle;
	//unsigned char Length;
    PasString ArrayName;
    char Reserved[32];
} TWSPrimatRec;

/* Запись для надписей */
typedef struct {
    long Start;  /* Позиция размещения надписи */
    long Depth;  /* Глубина размещения надписи */
    unsigned short Color;     /* Цвет вывода надписи */
    long Length; /* Длина подчеркивания */
	//unsigned char Length;
    PasString Font;   /* Шрифт для вывода надписи */
    long Size;  /* Высота шрифта для вывода надписи */
    long Line;  /* Расстояние между строками надписи */
    unsigned short HJust; /* Тип выравнивания по горизонтали (0-влево, 1-по центру, 2-вправо)*/
    unsigned short VJust; /* Тип выравнивания по вертикали (0-поверху, 1-по центру, 2-понизу*/
    unsigned short Under;  /* Подчеркивание текста линией */
    unsigned short Direct; /* Направление вывода надписи
      (0-слева направо, 1-снизу вверх, 2-справа налево, 3-сверху вниз)*/
    char *Text; /* ТЕКСТ НАДПИСИ */
    long Flags; /* nfXXXX */
    long BackColor; /* Цвет фона */
    void *Parent; /* Контейнер надписи */
    char Reserved[24];
} TViewNotesRec, *PViewNotesRec;

/* Запись для пустых колонок */
typedef struct {
    long Start; /* Начало колонки */
    long Width; /* Ширина колонки */
    unsigned short Color;    /* Цвет колонки */
	//unsigned char Length;
    PasString TowerName;   /* Название колонки */
    /* Следующие поля одинаковы для всех типов колонок */
    //unsigned char Length;
    PasString NameFont;   /* Шрифт для вывода названия колонки */
    long NameSize;  /* Высота шрифта для вывода названия колонки */
    long NameJust;  /* Тип выравнивания названия колонки (см.TViewNotesRec.HJust) */
    long NameDirect; /* Направление вывода названия колонки (см.TViewNotesRec.Direct) */
    long NameBefore; /* Пропуск до названия колонки */
    long NameAfter; /* Пропуск после названия колонки */
    long NameInter; /* Пропуск между строками в названии колонки */
    char Reserved[32];
} TViewTowerRec, *PViewTowerRec;

/* Запись для колонки глубин */
typedef struct {
    long Start;     /* см.TViewTowerRec */
    long Width;     /* см.TViewTowerRec */
    unsigned short Color;        /* см.TViewTowerRec */
    //unsigned char Length;
    PasString TowerName;  /* см.TViewTowerRec */
    long TickStep;  /* Шаг вывода рисок со значениями глубин */
    unsigned short TextPlace;    /* Положение значений глубин относительно рисок */
    unsigned short AbsDepth;     /* Выводить абсолютные глубины */
	//unsigned char Length;
    PasString FontName;   /* Шрифт для вывода значений глубин */
    long FontSize;  /* Высота шрифта для вывода значений глубин */
    unsigned short TextJust;     /* Выравнивание значений глубин */
	//unsigned char Length;
    PasString AbsFont;    /* Шрифт для вывода значений абсолютных глубин */
    unsigned char AbsZero;      /* Точность вывода абсолютных глубин */
    long AbsSize;   /* Высота шрифта для вывода значений абсолютных глубин */
    unsigned short AbsJust;      /* Выравнивание значений абсолютных глубин */
	//unsigned char Length;
    PasString AbsInfo;    /**/
    /* см.TViewTowerRec */
	//unsigned char Length;
    PasString NameFont;
    long NameSize;
    long NameJust;
    long NameDirect;
    long NameBefore;
    long NameAfter;
    long NameInter;
    /* см.TViewCurveRec */
    unsigned short RowNumber;
    unsigned char ColNumber;
	//unsigned char Length;
    PasString TableName;
	//unsigned char Length;
    PasString ArrayName;
    OType DataHandle;
    OType ArrayHandle;
    /* Данные о том, откуда брались данные абс. глубин */
    string64 ResFile;
    string32 ResName;

    unsigned short RowNumberX;
    unsigned char ColNumberX;
    string32 TableNameX;
    string32 ArrayNameX;
    OType DataHandleX;
    OType ArrayHandleX;
    string64 ResFileX;
    string32 ResNameX;
    unsigned short RowNumberY;
    unsigned char ColNumberY;
    string32 TableNameY;
    string32 ArrayNameY;
    OType DataHandleY;
    OType ArrayHandleY;
    string64 ResFileY;
    string32 ResNameY;

    unsigned char HorVisMode;
    unsigned short HorVisAngle;

    char Reserved2[61];
    /* Доп. настройки для разных масштабов по глубине */
    unsigned char Scale1Div50;
    unsigned short Scale1TickStep;
    unsigned char Scale1Reserved;
    unsigned char Scale2Div50;
    unsigned short Scale2TickStep;
    unsigned char Scale2Reserved;
    unsigned char Scale3Div50;
    unsigned short Scale3TickStep;
    unsigned char Scale3Reserved;
    char Reserved[52];
} TTowerDepthRec, *PTowerDepthRec;

/* Позиция легенды */
#define wslpDefault 0
#define wslpLegend  1
#define wslpHeader  2

/* Запись для попластовых колонок */
typedef struct {
    long Start;
    long Width;
    unsigned short Color;
	//unsigned char Length;
    PasString TowerName;
    unsigned char ZeroPlace;
	//unsigned char Length;
    PasString TraceColor;
    unsigned short Mode;
	//unsigned char Length;
    PasString CurveInfo;
    //unsigned char Length;
    PasString TableInfo;

	//unsigned char Length;
    PasString NameFont;
    long NameSize;
    long NameJust;
    long NameDirect;
    long NameBefore;
    long NameAfter;
    long NameInter;

    //unsigned char Length;
    PasString StratFont;
    long StratSize;
    unsigned short StratDirect;
    unsigned short StratJust;
	//unsigned char Length;
    PasString ValueFont;
    long ValueSize;
    unsigned short ValuePlace;
    unsigned short ValueJust;
	//unsigned char Length;
    PasString DepthFont;
    long DepthSize;
    unsigned short DepthPlace;
    unsigned short DepthJust;

    OType DataHandle;
	//unsigned char Length;
    PasString DataName;
    long DataRow;
    unsigned char DataCol;
    OType DataArray;
	//unsigned char Length;
    PasString DataArrayName;

    OType InterTable;
	//unsigned char Length;
    PasString InterName;
    long InterRow;
    OType InterArray;
	//unsigned char Length;
    PasString InterArrayName;
    /* Сведения о том, откуда брались данные колонки */
    PasString ResFile;
    PasString ResName;
    string32 DictStr;
    unsigned char LegendPlace; /* wslpXXX */
    long EFlags;
    void *LeftCurve;
    void *RightCurve;
    char Reserved[18];
} TTowerInterRec, *PTowerInterRec;

typedef struct {
    long Start;
    long Width;
    unsigned short Color;
    //unsigned char Length;
    PasString Title;
	//unsigned char Length;
    PasString TitleFont;
    long TitleSize;
    unsigned short TitleJust;
    unsigned short TitleDirect;
    long TitleBefore;
    long TitleAfter;
    long TitleInter;
    char Reserved[32];
} TBHoleTowerRec;

typedef struct {
    long Start;     /* см.TViewTowerRec */
    long Width;     /* см.TViewTowerRec */
    unsigned short Color;        /* см.TViewTowerRec */
	//unsigned char Length;
    PasString TowerName;      /* см.TViewTowerRec */
    long TickStep;     /* Шаг мелкой сетки по глубине */
    unsigned short TickFreq;        /* Частота крупной сетки по глубине */
    unsigned char TickPattern;      /* Рисунок мелкой сетки по глубине */
    /* Тоже самое для сетки по горизонтали */
    long GridStep;
    unsigned short GridFreq;
    unsigned char GridPattern;
    /* см.TViewTowerRec */
	//unsigned char Length;
    PasString NameFont;
    long NameSize;
    long NameJust;
    long NameDirect;
    long NameBefore;
    long NameAfter;
    long NameInter;
    long Flags;
    /* Доп. настройки для разных масштабов по глубине */
    unsigned char Scale1Div50;
    unsigned short Scale1TickStep;
    unsigned char Scale1TickFreq;
    unsigned char Scale2Div50;
    unsigned short Scale2TickStep;
    unsigned char Scale2TickFreq;
    unsigned char Scale3Div50;
    unsigned short Scale3TickStep;
    unsigned char Scale3TickFreq;
    char Reserved[16];
} TTowerLnGridRec, *PTowerLnGridRec;

typedef struct {
    long Start;     /* см.TViewTowerRec */
    long Width;     /* см.TViewTowerRec */
    unsigned short Color;        /* см.TViewTowerRec */
	//unsigned char Length;
    PasString TowerName;      /* см.TViewTowerRec */
    long TickStep;     /* Шаг мелкой сетки по глубине */
    unsigned short TickFreq;        /* Частота крупной сетки по глубине */
    unsigned char TickPattern;      /* Рисунок мелкой сетки по глубине */
    long GridModul;     /* Модуль логарифмической сетки */
    float GridStart;      /* Начальное значение логарифмической сетки */
    float GridPower;      /* Основание логарифмической сетки */
    unsigned char GridPattern;      /* Рисунок логарифмической сетки */
    /* см.TViewTowerRec */
	//unsigned char Length;
    PasString NameFont;
    long NameSize;
    long NameJust;
    long NameDirect;
    long NameBefore;
    long NameAfter;
    long NameInter;
    long Flags;
    /* Доп. настройки для разных масштабов по глубине */
    unsigned char Scale1Div50;
    unsigned short Scale1TickStep;
    unsigned char Scale1TickFreq;
    unsigned char Scale2Div50;
    unsigned short Scale2TickStep;
    unsigned char Scale2TickFreq;
    unsigned char Scale3Div50;
    unsigned short Scale3TickStep;
    unsigned char Scale3TickFreq;
    char Reserved[20];
} TTowerLgGridRec, *PTowerLgGridRec;

/* Флаги отображения заливок */
const int fcLeftStrip     = 1; /* Граница слева */
const int fcRightStrip    = 2; /* Граница справа */
const int fcInterStrip    = 4; /* Границы сверху и снизу */
const int fcDisableHeader = 8; /* Не отображать легенду */

typedef struct {
	//unsigned char Length;
    PasString LeftCurveInfo;
	//unsigned char Length;
    PasString RightCurveInfo;
    unsigned short Filler;
    unsigned short RevFill;
    unsigned short LeftFill;
    unsigned short RightFill;
    long Start;
    long Width;
    float ConstValue;
    long Roof;
    long Sole;
    unsigned short Flags; // см. константы fcXXXX

	//unsigned char Length;
    PasString FontName;
    long FontSize;
    long FontJust;
    long SpaceText;
    long SpaceBefore;
    long SpaceAfter;
    long SpaceIndent;
    unsigned short Color;

    void* LeftCurve;
    void* RightCurve;
    unsigned char FillerColor;
    unsigned char RevFillColor;
    unsigned char LeftFillColor;
    unsigned char RightFillColor;
    char Reserved[60];
} TViewFillerRec, *PViewFillerRec;

/* Флаги вывода шкал */
const int vsValueTicks = 1; /* Единицы */
const int vsCurveTicks = 2; /* По кривой */
const int vsSmallTicks = 4; /* Значения */

typedef struct {
    long Start;
    long Width;
    long Depth;
    long Color;
    unsigned short Flags;
    PasString Title;

    float TickMin;
    float TickScl;
    long TickStep;
    float TickUnit;
    unsigned char TickFreq;
    long TickSize;

    PasString TitleFont;
    long TitleSize;
    unsigned short TitleJust;

    PasString ValueFont;
    long ValueSize;
    unsigned short ValueJust;
    unsigned char ValueZero;
    char Reserved[64];
} TViewScaleRec, *PViewScaleRec;

typedef struct {
    long Start;
    long Width;
    unsigned short Color;
    long Heigth;
    unsigned short Frames;
    long SLeft;
    long SRight;
    long STop;
    long SBottom;
    long FLeft;
    long FRight;
    long FTop;
    long FBottom;
    long BackgroundColor;
    char Reserved[28];
} TWSFrameRec, *PWSFrameRec;

typedef struct {
	//unsigned char Length;
    PasString Font;
    long Size;
    unsigned short RMul;
    unsigned short RDiv;
    unsigned short Direct;
    unsigned short Just;
    long Start;
    long Width;
    long Heigth;
    unsigned short Color;
    long Inter;
    unsigned short Frames;
    long SLeft;
    long SRight;
    long STop;
    long SBottom;
    long FLeft;
    long FRight;
    long FTop;
    long FBottom;
    char *Text;
    long BackgroundColor;
    char Reserved[28];
} TFrameTextRec, *PFrameTextRec;

typedef struct {
	//unsigned char Length;
    PasString Source;
    PasString Text;
    PasString Empty;
    PasString Font;
    long Size;
    unsigned short RMul;
    unsigned short RDiv;
    long Heigth;
    unsigned short Just;
    long Start;
    long Width;
    unsigned short Color;
    long Inter;
    unsigned short Frames;
    long SLeft;
    long SRight;
    long STop;
    long SBottom;
    long FLeft;
    long FRight;
    long FTop;
    long FBottom;
    long BackgroundColor;
    char Reserved[28];
} TFrameTableRec, *PFrameTableRec;

/* Типы графических данных */
typedef unsigned char TBitmapDataType;
const TBitmapDataType bdtUnknown = 0; /* Неизвестный */
const TBitmapDataType bdtBMP     = 1; /* Windows Bitmap */
const TBitmapDataType bdtPCX     = 2; /* PCX */
const TBitmapDataType bdtWMF     = 3; /* Windows Metafile */

typedef struct {
    long Start;
    long Width;
    unsigned short Color;
    long Heigth;
    unsigned short Frames;
    long SLeft;
    long SRight;
    long STop;
    long SBottom;
    long FLeft;
    long FRight;
    long FTop;
    long FBottom;
    unsigned short BMPFlags;
    unsigned short BMPWidth;
    unsigned short BMPHeigth;
    unsigned short BMPByte;
    long BMPSize;
    void *BMPData;
	//unsigned char Length;
    string64 BMPName;
    unsigned short BMPDraw;
    long BackgroundColor;
    TBitmapDataType DataType;
    char Reserved[25];
} TFrameBitmapRec, *PFrameBitmapRec;

typedef struct {
    long Start;
    long Width;
    unsigned short Color;
    long Heigth;
    unsigned short Frames;
    long SLeft;
    long SRight;
    long STop;
    long SBottom;
    long FLeft;
    long FRight;
    long FTop;
    long FBottom;
    long Line;
    long LineLen;
    long LineSpace;
	//unsigned char Length;
    PasString Text;
	//unsigned char Length;
    PasString TextFont;
    long TextSize;
    long TextRMul;
    long TextRDiv;
    long BackgroundColor;
    char Reserved[28];
} TFrameLineRec, *PFrameLineRec;

/* Маски флагов к CreateWSChord */
const unsigned short icShowTrace = 1; /* Отображать линии трассировки */
const unsigned short icShowChord = 2; /* Отображать линию соединяющую точки */
const unsigned short icConstInter = 4; /* При изменении глубины мышью параллельно переносятся обе глубины */
const unsigned short icShowFiller = 8; /* Отображать заливку */
const unsigned short icIsTraceColor = 16; /* Рисовать лучи цветом, указанным в PEN-файле */
extern char *SUserCreatedReper; /* Репер, созданный вручную */
/* Типы реперов (поле ReperType записи TWSInterReperRec) */
const unsigned short rtChord = 0; /* Реперный интервал */
const unsigned short rtHandleInter = 1; /* Интервал обработки */

typedef struct TWSInterReperRec {
    long Start;
    long Width;
    long Color;
    long LeftDepth;
    long RightDepth;
    unsigned short Flags; /* icXXXX */
    void *LeftCurve;
    void *RightCurve;
    string32 IdentStr;
    long IdentLong;
    unsigned short FillerIndex;
    long FillerColor;
    unsigned char TraceIndex;
    unsigned short ReperType;
    char Reserved[18];
} TWSInterReperRec, *PWSInterReperRec;

/* Маски флагов отображения рисунка планшета  */
const long plpOpaque     = 0x00000001; /* непрозрачный */
const long plpLinkDepths = 0x00000002; /* привязан к глубинам */

typedef struct {
    long Start;
    long Width;
    long Color;
    long Heigth;
    unsigned short Frames;
    long SLeft;
    long SRight;
    long STop;
    long SBottom;
    long FLeft;
    long FRight;
    long FTop;
    long FBottom;
    unsigned short BMPFlags;
    unsigned short BMPWidth;
    unsigned short BMPHeigth;
    unsigned short BMPByte;
    long BMPSize;
    void *BMPData;
	//unsigned char Length;
    string64 BMPName;
    long Flags;
    long Roof;
    long Sole;
    long BackgroundColor;
    TBitmapDataType DataType;
    unsigned short BMPDraw;
    char Reserved[57];
} TViewPictureRec, *PViewPictureRec;

/* ДВУМЕРНЫЕ КРИВЫЕ */

const long MaxChannels = 16384; /* Макс. кол-во каналов в строке */
const long MaxColorTransformEntries = 16384; /* Макс. кол-во элементов таблицы цветов */
const long CurrentTwoDHdrVersion = 0; /* Текущая версия описателя формата данных */
const long CurrentTwoDTransVersion = 0; /* Текущая версия заголовка таблицы преобразования в цвет */

/* Флаги формата */
const long tdhfDataPresent    = 0x00000001; /* lpData ссылается на реальные данные */
const long tdhfAddInfoPresent = 0x00000002; /* lpAddInfo ссылается на реальные данные */
const long tdhfSignedData     = 0x00000004; /* Данные - со знаком */
const long tdhfDepthsPresent  = 0x00000008; /* В каждой строке имеется глубина */
const long tdhfRevByteOrder   = 0x00000010; /* Байты идут в обратном порядке */
const long tdhfRevBitOrder    = 0x00000020; /* Биты идут в обратном порядке */
const long tdhfRevRowOrder    = 0x00000040; /* Строки идут от подошвы к кровле */

/* Формат значений */
typedef unsigned char TTwoDValueFormat;
const TTwoDValueFormat tdvfUnknown = 0; /* Неизвестный */
const TTwoDValueFormat tdvfDefault = 1; /* По умолчанию (целые числа) */

/* Формат глубин в строке */
typedef unsigned char TTwoDDepthFormat;
const TTwoDDepthFormat tddfUnknown = 0; /* Неизвестный */
const TTwoDDepthFormat tddfFloatM  = 1; /* 4-байтовый вещ., в метрах */
const TTwoDDepthFormat tddfLongCm  = 2; /* 4-байтовый целый со знаком, в сантиметрах */

/* Описатель формата данных */
typedef struct {
    long dwSize;                        /* 000 Размер этой структуры               */
    long dwVersion;                     /* 004 Версия этой структуры               */
    long dwFlags1;                      /* 008 см. tdhfXXXX                        */
    unsigned long dwDataSize;           /* 012 Размер данных                       */
    long dwDataSizeHigh;                /* 016 Пока не используется                */
    TTwoDValueFormat bDataFormat;       /* 020 Формат данных                       */
    TTwoDDepthFormat bDepthFormat;      /* 021 Формат данных глубины (если есть)   */
    unsigned char cbitDataLength;       /* 022 Число бит в элементе данных         */
    unsigned char cbitDataGap;          /* 023 Число бит между данными             */
    unsigned short cbitChannelHeader;   /* 024 Число бит в заголовке канала        */
    unsigned short cbitChannelGap;      /* 026 Число бит между каналами            */
    unsigned long cbitRowHeader;        /* 028 Число бит в заголовке строки        */
                                        /*     (включая, возможно, глубину)        */
    unsigned long cbitRowGap;           /* 032 Число бит между строками            */
    unsigned long nDataInChannel;       /* 036 Число элементов данных в канале     */
    unsigned long nChannels;            /* 040 Число каналов в строке              */
    unsigned long nDataRows;            /* 044 Число строк данных                  */
    unsigned long dwAddInfoSize;        /* 048 Размер доп. блока информации        */
    void *lpData;                       /* 052 Ссылка на данные (может не быть)    */
    void *lpAddInfo;                    /* 056 Ссылка на доп. информацию           */
    unsigned long cbitDepthOffsetInRow; /* 060 Смещение в битах данных глубины     */

    unsigned char acReserved[192];    /* Зарезервировано */
} TTwoDCurveDataHeader, *PTwoDCurveDataHeader; // 256 байт

/* Элемент таблицы "Значение => цвет" */
typedef struct {
    unsigned long dwDataValue;  /* Значение */
    unsigned long dwColorValue; /* Цвет */
} TPointToColorItem;

/* Элемент таблицы "Интервал значений => цвет" */
typedef struct {
    unsigned long dwDataMinValue; /* Минимальное значение */
    unsigned long dwDataMaxValue; /* Максимальное значение */
    unsigned long dwColorValue;   /* Цвет */
} TInterToColorItem;

/* Таблица "Значение => цвет" */
typedef struct {
    long dwSize; /* Размер таблицы */
    long Count;  /* Кол-во элементов */
    TPointToColorItem Items[0x7FFFFFFF / sizeof(TPointToColorItem) - 2 * sizeof(long)];
                 /* Элементы */
} *PPointToColorArray;

/* Таблица "Интервал значений => цвет" */
typedef struct {
    long dwSize; /* Размер таблицы */
    long Count;  /* Кол-во элементов */
    TInterToColorItem Items[0x7FFFFFFF / sizeof(TInterToColorItem) - 2 * sizeof(long)];
                 /* Элементы */
} *PInterToColorArray;

/* Таблица "Палитра" */
typedef struct {
    long dwSize;              /* Размер таблицы */
    unsigned long StartValue; /* Начальное значение */
    unsigned long EndValue;   /* Конечное значение */
    unsigned long StepValue;  /* Шаг значений */
    unsigned long Items[0x7FFFFFFF / sizeof(unsigned long) - 4 * sizeof(long)];
                              /* Элементы (цвета палитры) */
} *PColorPaletteArray;

/* Формат цвета */
typedef unsigned char TTwoDColorFormat;
const TTwoDColorFormat tdcfUnknown    =  0; /* Неизвестный */
const TTwoDColorFormat tdcf1bit       =  1; /* Монохромный */
const TTwoDColorFormat tdcf4bit       =  2; /* 16 цветов */
const TTwoDColorFormat tdcf8bit       =  3; /* 256 цветов (палитра ПРАЙМ) */
const TTwoDColorFormat tdcf16bit      =  4; /* High Color */
const TTwoDColorFormat tdcf24bit      =  5; /* True Color */
const TTwoDColorFormat tdcf32bit      =  6; /* True Color (32 бита) */
const TTwoDColorFormat tdcf4bitNoRev  =  7; /* 16 цветов, прямой порядок бит */
const TTwoDColorFormat tdcf16bitNoRev =  8; /* High Color, прямой порядок байт */
const TTwoDColorFormat tdcf24bitNoRev =  9; /* True Color, прямой порядок байт */
const TTwoDColorFormat tdcf32bitNoRev = 10; /* True Color (32 бита, прямой порядок байт) */

/* Тип таблицы преобразования в цвет */
typedef unsigned char TTwoDColorTransformMode;
const TTwoDColorTransformMode tdctUnknown       = 0; /* Неизвестный */
const TTwoDColorTransformMode tdctOneToOne      = 1; /* Нет преобразования */
const TTwoDColorTransformMode tdctPointToColor  = 2; /* "Значение => цвет" */
const TTwoDColorTransformMode tdctInterToColor  = 3; /* "Интервал значений => цвет" */
const TTwoDColorTransformMode tdctColorPalette  = 4; /* "Палитра" */

/* Режим интерполяции цвета */
typedef unsigned char TTwoDColorInterpolationMode;
const TTwoDColorInterpolationMode tdciUnknown  = 0; /* Неизвестный */
const TTwoDColorInterpolationMode tdciConstant = 1; /* Кусочно-постоянный (цвет для меньшего значения) */
const TTwoDColorInterpolationMode tdciLinear   = 2; /* Линейный (плавный переход) */

/* Заголовок таблицы преобразования в цвет */
typedef struct {
    long dwSize;                             /* Размер этой структуры */
    long dwVersion;                          /* Версия этой структуры */
    long dwFlags1;                           /* Флаги (пока не используются) */
    TTwoDColorFormat bColorFormat;           /* Формат цвета (tdcfXXXX) */
    TTwoDColorTransformMode bMode;           /* Тип таблицы преобразования в цвет (tdctXXXX) */
    TTwoDColorInterpolationMode bInterpMode; /* Режим интерполяции цвета (tdciXXXX) */
    unsigned char bReserved1;                /* Зарезервировано */
    unsigned long dwEmptyColor;              /* Цвет по умолчанию (в формате bColorFormat, */
                                             /* но всегда с прямым порядком бит и байт) */
    void *lpTransformArray;                  /* Указатель на таблицу преобразования в цвет */
    unsigned char acReserved[40];            /* Зарезервировано */
} TTwoDColorTransform, *PTwoDColorTransform;


typedef struct {
    long Depth1;
    long Depth2;
} TDepthTieRec, *PDepthTieRec;

typedef struct {
    long Roof;
    long Sole;
    long Count;
    TDepthTieRec Items[(0x7FFFFFFF / sizeof (TDepthTieRec)) - 2];
} TDepthTieArray, *PDepthTieArray;

typedef struct {
    long Count;
    long Items[(0x7FFFFFFF / sizeof (long)) - 2];
} TDepthShiftArray, *PDepthShiftArray;

/* Маски флагов отображения двумерной кривой */
const long p2dfInverseColor     = 0x00000001; /* Инвертировать цвет монохромного изображения */
const long p2dfDrawColorMap     = 0x00000002; /* Рисовать цветовую карту */
const long p2dfDrawHeader       = 0x00000004; /* Рисовать масштабную линейку */
const long p2dfDrawHeaderName   = 0x00000008; /* Выводить название в линейке */
const long p2dfDrawHeaderValues = 0x00000010; /* Выводить риски и значения в линейке */
const long p2dfDrawHorizCurves  = 0x00000020; /* Рисовать гориз. кривые */
const long p2dfPointStepInRows  = 0x00000040; /* Ед. изм. шага - строка данных (иначе - см. планшета) */
const long p2dfFormatOverride   = 0x00000080; /* Только для WSSetData - поле DataFormat
                                                 определяет не только формат данных, но и
                                                 параметры визуализации, предусмотренные
                                                 данным форматом */
const long p2dfReserved1        = 0x00000100;
const long p2dfStretchArgRange  = 0x00000200; /* Растягивать область представления аргумента
                                                 на всю ширину объекта */
const long p2dfAutoLegend       = 0x00000400; /* Изменять легенду автоматически исходя
                                                 из таблицы цветов */
const long p2dfNoAutoSetFormat  = 0x00000800; /* Запрет установки автоматически определённого формата */
const long p2dfUseSondeFormula  = 0x00001000; /* Использовать формулу зонда */

/* Константы поддерживаемых форматов для двумерных кривых */
const unsigned short p2dbfNone          =     0;
const unsigned short p2dbfARMG50        = 0x0001; /* АРМГ 5.0 */
const unsigned short p2dbfWPI           = 0x0002; /* WPI (Д. Батырова, НПФ "Геофизика") */
const unsigned short p2dbfUSBA          = 0x0003; /* УЗБА */
const unsigned short p2dbfVAK_NTU       = 0x0004; /* ВАКЦ НТУ ТНГФ */
const unsigned short p2dbfTAP           = 0x0005; /* TAP (исп-тся в КНГФ) */
const unsigned short p2dbfGEKTOR        = 0x0006; /* Регистратор ГЕКТОР */
const unsigned short p2dbfWAC           = 0x0007; /* WAC (НТУ ТГ АМИС ТНГФ) - пока не поддерживается */
const unsigned short p2dbfSEG_D         = 0x0008; /* Сейсмика - SEG_D (СЦС-3, SDS) */
const unsigned short p2dbfCST           = 0x0009; /* Сейсмика - CST (используется в системе GEOVECTEUR) - пока не поддерживается */
const unsigned short p2dbfSEG_Y         = 0x000A; /* Сейсмика - SEG_Y - пока не поддерживается */
const unsigned short p2dbfGEKTORWAT     = 0x000B; /* Скважинный акустический телевизор (ГЕКТОР) */
const unsigned short p2dbfUMN           = 0x000C; /* Волновые сигналы в формате *.umn */
const unsigned short p2dbfWSBLOB        = 0x000D; /* Данные из WS-файла в BLOBах */
const unsigned short p2dbfOGFFKDWS      = 0x000E; /* Упакованная ФКД ОГФ (из WS-файла) */
const unsigned short p2dbdWSRange1First = p2dbfWSBLOB; /* С этого номера идут форматы, хранящиеся в WS */
const unsigned short p2dbdWSRange1Last  = 0x001C; /* До этого номера зарезервировано за форматами, хранящимися в WS */
const unsigned short p2dbfWinLOG        = 0x001D; /* WinLOG (акустика и САТ) */

/* Флаги Flags записи TPrimeDepthIndex */
const long pdifAnalysed        = 0x00000001;
const long pdifAnalysisSuccess = 0x00000002;

/* Типы индекса глубин двумерной кривой, поле IndexType записи TPrimeDepthIndex */
const long pditUnknown        = 0x00000001; /* Неизвестный */
const long pditFixedStepArray = 0x00000002; /* Массив индексов, идущий с фиксированным шагом по глубине */
const long pditDepthList      = 0x00000003; /* Список глубин */

/* Массив индексов, идущий с фиксированным шагом по глубине */
typedef struct {
  long Top_PU;
  long Bottom_PU;
  long Step_PU;
  long Count;
  long SourceIndexes[(0x7FFFFFFF / sizeof (long)) - 4];
} TPrimeDepthIndex_FixedStep, *PPrimeDepthIndex_FixedStep;

/* Список глубин */
typedef struct {
  long Count;
  long Depths_PU[(0x7FFFFFFF / sizeof (long)) - 1];
} TPrimeDepthIndex_List, *PPrimeDepthIndex_List;

/* Индекс глубин двумерной кривой */
typedef struct {
  long Flags; /* pdifXXXX */
  long IndexType; /* pditXXXX */
  PPrimeDepthIndex_FixedStep FixedStepIndex_DepthShifted;
    /* Индекс типа "массив индексов" для первоначального файла, но сдвинутый по глубине */
  PPrimeDepthIndex_FixedStep FixedStepIndex_Final;
    /* Индекс типа "массив индексов" для окончательного вывода (полностью увязанной кривой) */
  PPrimeDepthIndex_List ListIndex_Initial;
    /* Индекс типа "список глубин" для первоначального файла */
  unsigned char Reserved[44]; /* Зарезервировано */
} TPrimeDepthIndex;


/* Запись для двумерной кривой планшета */
typedef struct {
    long dwStart;                         /* Левая граница, 0.1 мм */
    long dwWidth;                         /* Ширина, 0.1 мм */
    long dwColor;                         /* Цвет */
    long dwFlags;                         /* Флаги (p2dfXXXX) */
    long dwRoof;                          /* Кровля, см (ограничение) */
    long dwSole;                          /* Подошва, см (ограничение) */
    PasString psDisplayName;                 /* Название */
    long dwDataRoofOrSole;                /* Кровля или подошва данных, см */
                                          /* Подошва, если задан флаг tdhfRevRowOrder */
                                          /* Не исп., если задан флаг tdhfDepthsPresent */
    long dwDataStep;                      /* Шаг данных, см */
                                          /* Не исп., если задан флаг tdhfDepthsPresent */
    long iChannelIndex;                   /* Индекс отображаемого канала */
    long cbitFileHeaderSize;              /* Размер заголовка файла данных в битах */
    TTwoDColorFormat bFinalColorFormat;   /* Формат цвета при отображении (tdcfXXXX) */
    PTwoDCurveDataHeader lpRowsFormat;    /* Указатель на описатель формата данных строк
                                             (если wDataFormat == p2dbfNone) */
    PTwoDColorTransform lpColorTransform; /* Указатель на заголовок таблицы преобразования в цвет */
    long dwStorageFlags;                  /* Флаги источника данных (пока не используются) */
    string32 psStorageTable;              /* Пока не используется */
    PasString psStorageName;                 /* Имя файла данных (в текущей версии) */
    float fArgMin;                        /* Начальное знаение аргумента */
    float fArgStep;                       /* Шаг аргумента */
    /* Следующие 4 поля задают соответствие (линейное) между данными из файла
      и физическими величинами */
    long dwDataMin;                       /* Мин. значение данных */
    long dwDataMax;                       /* Макс. значение данных */
    float fValMin;                        /* Мин. значение физ. величины */
    float fValMax;                        /* Макс. значение физ. величины */
    unsigned char bLegendValueDigits;     /* Число знаков после запятой в легенде */
    string64 psHeaderTitleFontName;       /* Шрифт названия в линейке */
    unsigned short usHeaderTitleFontSize; /* Размер шрифта названия в линейке, 0.1 мм */
    unsigned short usHeaderTitleJust;     /* Выравнивание названия в линейке */
    string64 psHeaderValFontName;         /* Шрифт значений в линейке */
    unsigned short usHeaderValFontSize;   /* Размер шрифта значений в линейке, 0.1 мм */
    unsigned short usHeaderValJust;       /* Выравнивание значений в линейке */
    unsigned char bHeaderValueDigits;     /* Число знаков после запятой в линейке */
    unsigned short usHeaderTickSize;      /* Размер рисок в линейке, 0.1 мм */
    long dwHeaderColor;                   /* Цвет линейки */
    void *lpLeftCurve;                    /* Левая ограничивающая кривая */
    void *lpRightCurve;                   /* Правая ограничивающая кривая */
    float fHCMin;                         /* Нижняя граница значений гориз. кривых, физ.ед. */
    float fHCMax;                         /* Верхняя граница значений гориз. кривых, физ.ед. */
    float fHCVal0;                        /* Значение на "0", физ.ед. */
    float fHCScale;                       /* Масштаб гориз. кривых, физ.ед/см. */
    unsigned short usHCLineIndex;         /* Номер типа кривой (см. WSIGF.CRV) */
    long dwHCStep;                        /* Шаг между гориз. кривыми, см. p2dfPointStepInRows */
    long dwHCRoof;                        /* Кровля гориз. кривых (ограничение) */
    long dwHCSole;                        /* Подошва гориз. кривых (ограничение) */
    long dwDepthShift;                    /* Смещение всего объекта по глубине, см */
    long dwArgLevelMask;                  /* Маска отображения уровней аргумента */
    float afArgLevels[10];                /* Уровни аргумента */
    long dwFuncLevelMask;                 /* Маска отображения уровней функции */
    float afFuncLevels[10];               /* Уровни функции */
    float fArgRangeMin;                   /* Минимум аргумента (ограничение) */
    float fArgRangeMax;                   /* Максимум аргумента (ограничение) */
    unsigned short wDataFormat;           /* Формат данных (p2dbfXXXX) */
    PDepthTieArray lpDepthTieArray;       /* Массив увязки двумерной кривой по глубине */
    float fPhaseShift;                    /* Сдвиг по фазе (циклический) для рисования, канал */
    OType hWSData;                        /* Handle данных (если они - WS-овские) */
    PDepthShiftArray lpChlDptShifts;      /* Массив сдвигов каналов по глубине относительно точки записи */
    unsigned char acReserved[10];         /* Зарезервировано */
} TView2dCurveRec, *PView2dCurveRec;

/* Интервалы печати планшета */
const int MaxPrintIntervals = 100; /* Максимальное количество интервалов печати планшета */

/* Флажки вывода интервала */
const unsigned short pifUpperHeader  = 0x0001; // 0 бит - выводить шапку сверху
const unsigned short pifUpperLegend  = 0x0002; // 1 бит - выводить легенду сверху
const unsigned short pifUHeaderFirst = 0x0004; // 2 бит - перевернуть (Ш, потом Л)
const unsigned short pifLowerHeader  = 0x0010; // 4 бит - выводить шапку снизу
const unsigned short pifLowerLegend  = 0x0020; // 5 бит - выводить легенду снизу
const unsigned short pifLLegendFirst = 0x0040; // 6 бит - перевернуть (Л, потом Ш)
                                               // биты 3, 7-15 зарезервированы

typedef struct TPrintInterval {
    long Sole;            // Кровля интервала печати (в см)
    long Roof;            // Подошва интервала (в см)
    long Scale;           // Масштаб интервала (1 : Scale)
    long Indent;          // Пропуск снизу (в 0.1 мм)
    unsigned short Flags; // Битовые флажки интервала - см. константы pifXXXX
    char Reserved[16];
} TPrintInterval, *PPrintInterval;

/* Типы файлов конфигурации (ReloadConfig) */
const long cfgAllConfig = -1; // Все файлы конфигурации
const long cfgNoConfig  = 0;  // Нет операции
const long cfgCRV       = 1;  // WSIGF.CRV
const long cfgFIL       = 2;  // WSIGF.FIL
const long cfgWST       = 3;  // WSIGF.WST
const long cfgPEN       = 4;  // WSIGF.PEN
const long cfgPNT       = 5;  // WSIGF.PNT
const long cfgINT       = 6;  // WSIGF.INT

const long cfgmskMethod = 0x0000000F; // Маска метода загрузки
const long cfgmtdFile   = 0; // Загрузка из указанного файла (либо каталога,
                             // тогда имя файла берётся по умолчанию)

/* Результаты функции GetBuildType */
const long pbtUnknown  = 0; // Неизвестный тип
const long pbtStandard = 1; // Стандартный ПРАЙМ/БАШГИС
const long pbtViewer   = 2; // Программа просмотра и печати (не может быть возвращено)
const long pbtIngis    = 3; // Работа только с форматом ИНГИС

/* Возвращаемое значение BuildSubType в GetBuildType */
const long pbstPRIME   = 0; // ПРАЙМ
const long pbstBASHGIS = 1; // БАШГИС

const unsigned short HASPInfoSignature = 0x4850; // Сигнатура информации для алгоритмов внутри HASPа

typedef struct {
    long dwSize;
    unsigned short hiSignature;
    long hiSoftSerialNumber;
    char hiReserved1[10];
    long hiHardSerialNumber;
    char hiReserved2[40];
} THaspInfo, *PHaspInfo; // 64 байта

typedef unsigned char TConflictFieldsAction;
const unsigned char cfaAskUser   = 0;
const unsigned char cfaOverwrite = 1;
const unsigned char cfaSkip      = 2;
const unsigned char cfaCancel    = 3;

/* Индексы битов для параметра Flags1 (GetSheetSelectMode, SetSheetSelectMode) */
const long wssi1Unknown       =  0;
const long wssi1ViewCurve     =  1;
const long wssi1ViewPoint     =  2;
const long wssi1ViewInter     =  3;
const long wssi1ViewNotes     =  4;
const long wssi1ViewTower     =  5;
const long wssi1TowerDepth    =  6;
const long wssi1TowerInter    =  7;
const long wssi1TowerLnGrid   =  8;
const long wssi1TowerLgGrid   =  9;
const long wssi1TowerRvGrid   = 10;
const long wssi1ViewScale     = 11;
const long wssi1ViewFiller    = 12;
const long wssi1ViewPicture   = 13;
const long wssi1InterReper    = 14;
const long wssi1ViewTwoDCurve = 15;

typedef struct { /* Множество номеров колонок */
  unsigned long BitFields[4];
} TColumnsSet, *PColumnsSet;

typedef struct {
    /* Запись для функций AddCurveDataToList, GetCurveDataFromList, SelectCurves_1 */
    char acTableName[33];
    long nObjRow;
    char acArrayName[33];
    unsigned char nArrayCol;
    char abReserved[57];
} TTableCurveDataRec, *PTableCurveDataRec;

/* CALLBACKS */

/* Типы событий для CALLBACK */
const long pevNone = 0x00000000;

const long pevSystemLoaded          = 0x00010001;
const long pevSystemExiting         = 0x00010002;
const long pevSystemExitQuery       = 0x00010003;
    /* Return value > 0: не выходить */
const long pevSystemSettingsChanged = 0x00010004;
    /*  */

const long pevUserActionQuery     = 0x00020002;
    /* lpObject: имя DLL
       lpInput: имя функции
       Return value > 0: не выполнять */
const long pevUserActionExecuting = 0x00020002;
    /* lpObject: имя DLL
       lpInput: имя функции */
const long pevUserActionExecuted  = 0x00020002;
    /* lpObject: имя DLL
       lpInput: имя функции */

const long pevPlansheetCreated    = 0x00030001;
    /* lpObject: новый планшет */
const long pevPlansheetOpened     = 0x00030002;
    /* lpObject: планшет */
const long pevPlansheetClosing    = 0x00030003;
    /* lpObject: планшет */
const long pevPlansheetCloseQuery = 0x00030004;
    /* lpObject: планшет
       Return value > 0: не закрывать */
const long pevPlansheetModified   = 0x00030005;
    /* lpObject: планшет */

const long pevObjectCreated      = 0x00040001;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX */
const long pevObjectInsertQuery  = 0x00040002;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX
       lpInput: планшет
       Return value > 0: не вставлять */
const long pevObjectInserted     = 0x00040003;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX
       lpInput: планшет */
const long pevObjectDeleteQuery  = 0x00040004;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX
       lpInput: планшет
       Return value > 0: не удалять */
const long pevObjectDeleted      = 0x00040005;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX
       lpInput: планшет */
const long pevObjectDestroyQuery = 0x00040006;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX
       Return value > 0: не уничтожать */
const long pevObjectDestroying   = 0x00040007;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX */
const long pevObjectModified     = 0x00040008;
    /* lpObject: объект
       dwObjectType: 1 - объект диаграмм, 2 - объект шапки, 3 - объект подвала
       dwObjectSubType: для 1 - wsXXXX
                        для 2, 3 - hmXXXX */

/* Флаги типа объекта для CALLBACK */
const long pcboDiagramsObject = 0x00000001;
const long pcboHeaderObject   = 0x00000002;
const long pcboFooterObject   = 0x00000003;

/* Флаги установки CALLBACK */
const long pcbfIncludeProgramEvents    = 0x00000001;
const long pcbfExcludeThisModuleEvents = 0x00000002;
const long pcbfLoadLibraryOnEvent      = 0x00000004;
const long pcbfIgnoreFuncPointer       = 0x00000008;
const long pcbfSeparateInstances       = 0x00000010;
const long pcbfIgnoreExceptions        = 0x00000020;

/* Флаги удаления CALLBACK */
const long dpcbAll        = 0x00000000;
const long dpcbLocalOnly  = 0x00000001;
const long dpcbGlobalOnly = 0x00000002;

typedef long (__stdcall *TPrimeCommonCallbackFunc)(
    void* dwCookie,
    long dwEventType,
    long dwEventFlags,
    void *lpObject,
    long dwObjectType,
    long dwObjectSubType,
    void *lpInput,
    void *lpOutput,
    HINSTANCE dwCallerInstance
  );

/* Флаги Flags функции PlanObjDragDrop */

const long ddfCopyCurveColor        = 0x00000001;
const long ddfCopyCurveResultStatus = 0x00000002;

/* PrimeExecuteFunction */

extern const char *pefBuiltInPrime; // Выполнить встроенную функцию
const long WM_PRIMECOMMAND = 0x8008;
const long PCM_NONE = 0;

/* Названия и коды встроенных функций */
extern const char *pbfSystemExit; /* Выход из системы */                         const long PCM_SYSTEMEXIT                = 0x00010001;
extern const char *pbfEditToolbars; /* Настройка панелей */                      const long PCM_EDITTOOLBARS              = 0x00010002;
extern const char *pbfEditMenu; /* Настройка меню */                             const long PCM_EDITMENU                  = 0x00010003;
extern const char *pbfEditDefaults; /* Настройка умолчаний */                    const long PCM_EDITDEFAULTS              = 0x00010004;
extern const char *pbfEditPrintDevices; /* Настройка устройств печати */         const long PCM_EDITPRINTDEVICES          = 0x00010005;
extern const char *pbfPrimeHelp; /* Вызов справки */                             const long PCM_PRIMEHELP                 = 0x00010006;
extern const char *pbfPrimeHelpSearch; /* Поиск в справочной системе */          const long PCM_PRIMEHELPSEARCH           = 0x00010007;
extern const char *pbfPrimeAbout; /* Справка о программе */                      const long PCM_PRIMEABOUT                = 0x00010008;
extern const char *pbfTableDialog; /* Диалог таблицы */                          const long PCM_TABLEDIALOG               = 0x00010009;
extern const char *pbfTableDialogOld; /* Диалог строки */                        const long PCM_TABLEDIALOGOLD            = 0x0001000A;
extern const char *pbfResDialog; /* Диалог RES */                                const long PCM_RESDIALOG                 = 0x0001000B;
extern const char *pbfCreateDataFromRes; /* Создание данных из ресурса */        const long PCM_CREATEDATAFROMRES         = 0x0001000C;
extern const char *pbfSelectNextWindow; /* Следующее */                          const long PCM_SELECTNEXTWINDOW          = 0x0001000D;
extern const char *pbfSelectPrevWindow; /* Предыдущее */                         const long PCM_SELECTPREVWINDOW          = 0x0001000E;
extern const char *pbfWindowsTileVertical; /* Окна сверху вниз */                const long PCM_WINDOWSTILEVERTICAL       = 0x0001000F;
extern const char *pbfWindowsTileHorizontal; /* Окна слева направо */            const long PCM_WINDOWSTILEHORIZONTAL     = 0x00010010;
extern const char *pbfWindowsCascade; /* Окна каскадом */                        const long PCM_WINDOWSCASCADE            = 0x00010011;
extern const char *pbfEditGraph; /* Граф обработки */                            const long PCM_EDITGRAPH                 = 0x00010012;
extern const char *pbfShowSaxBasic; /* Открыть SBasic */                         const long PCM_SHOWSAXBASIC              = 0x00010013;
extern const char *pbfRunSaxBasicMacro; /* Выполнить макрос */                   const long PCM_RUNSAXBASICMACRO          = 0x00010014;

extern const char *pbfCreatePlansheet; /* Создать планшет */                     const long PCM_CREATEPLANSHEET           = 0x00020001;
extern const char *pbfOpenPlansheet; /* Открыть планшет */                       const long PCM_OPENPLANSHEET             = 0x00020002;
extern const char *pbfSavePlansheet; /* Сохранить планшет */                     const long PCM_SAVEPLANSHEET             = 0x00020003;
extern const char *pbfSavePlansheetAs; /* Сохранить планшет как... */            const long PCM_SAVEPLANSHEETAS           = 0x00020004;
extern const char *pbfSavePlansheetAsTemplate; /* Сохранить как шаблон */        const long PCM_SAVEPLANSHEETASTEMPLATE   = 0x00020005;
extern const char *pbfPrintPlansheet; /* Печать планшета */                      const long PCM_PRINTPLANSHEET            = 0x00020006;
extern const char *pbfEditPlansheetParams; /* Параметры планшета */              const long PCM_EDITPLANSHEETPARAMS       = 0x00020007;
extern const char *pbfEditLegendParams; /* Параметры легенды */                  const long PCM_EDITLEGENDPARAMS          = 0x00020008;
extern const char *pbfChangePlansheetScale; /* Масштаб просмотра планшета */     const long PCM_CHANGEPLANSHEETSCALE      = 0x00020009;
extern const char *pbfSetPlansheetAutoScale; /* Масштаб просмотра - по ширине */ const long PCM_SETPLANSHEETAUTOSCALE     = 0x0002000A;
extern const char *pbfSetPlansheetNoScale; /* Масштаб просмотра - 1:1 */         const long PCM_SETPLANSHEETNOSCALE       = 0x0002000B;
extern const char *pbfClosePlansheet; /* Закрыть планшет */                      const long PCM_CLOSEPLANSHEET            = 0x0002000C;
extern const char *pbfEditPlansheetHeaderOrder; /* Порядок элементов линейки */  const long PCM_EDITPLANSHEETHEADERORDER  = 0x0002000D;
extern const char *pbfSavePlansheetAsArchive; /* Сохранить в архив... */         const long PCM_SAVEPLANSHEETASARCHIVE    = 0x0002000E;

extern const char *pbfInsertObject; /* Вставка объекта в планшет */              const long PCM_INSERTOBJECT              = 0x00030001;
extern const char *pbfInsertCurvesFromAnotherWS; /* Вставка кривых из WS */      const long PCM_INSERTCURVESFROMANOTHERWS = 0x00030002;
extern const char *pbfInsertPoint; /* Примитив точки */                          const long PCM_INSERTPOINT               = 0x00030003;
extern const char *pbfInsertInter; /* Примитив интервала */                      const long PCM_INSERTINTER               = 0x00030004;
extern const char *pbfInsertEmptyFrame; /* Пустая рамка */                       const long PCM_INSERTEMPTYFRAME          = 0x00030005;
extern const char *pbfInsertTextFrame; /* Рамка с текстом */                     const long PCM_INSERTTEXTFRAME           = 0x00030006;
extern const char *pbfInsertTableFrame; /* Рамка с таблицей */                   const long PCM_INSERTTABLEFRAME          = 0x00030007;
extern const char *pbfInsertPictureFrame; /* Рамка с рисунком */                 const long PCM_INSERTPICTUREFRAME        = 0x00030008;
extern const char *pbfInsertSampleLineFrame; /* Образец линии кривой */          const long PCM_INSERTSAMPLELINEFRAME     = 0x00030009;
extern const char *pbfPlansheetObjectsList; /* Список объектов планшета */       const long PCM_PLANSHEETOBJECTSLIST      = 0x0003000A;
extern const char *pbfDeleteActivatedObjects; /* Удалить выделенные объекты */   const long PCM_DELETEACTIVATEDOBJECTS    = 0x0003000B;
extern const char *pbfInsertEmptyTower; /* Вставка пустой колонки */             const long PCM_INSERTEMPTYTOWER          = 0x0003000C;
extern const char *pbfInsertDepthTower; /* Вставка колонки глубин */             const long PCM_INSERTDEPTHTOWER          = 0x0003000D;
extern const char *pbfInsertPlastTower; /* Вставка попластовой колонки */        const long PCM_INSERTPLASTTOWER          = 0x0003000E;
extern const char *pbfInsertLitholTower; /* Вставка литологической колонки */    const long PCM_INSERTLITHOLTOWER         = 0x0003000F;
extern const char *pbfInsertStratTower; /* Вставка стратиграфической колонки */  const long PCM_INSERTSTRATTOWER          = 0x00030010;
extern const char *pbfInsertLineGridTower; /* Вставка линейной сетки */          const long PCM_INSERTLINEGRIDTOWER       = 0x00030011;
extern const char *pbfInsertLogGridTower; /* Вставка логарифмической сетки */    const long PCM_INSERTLOGGRIDTOWER        = 0x00030012;
extern const char *pbfInsetCurves; /* Вставка кривых */                          const long PCM_INSERTCURVES              = 0x00030013;
extern const char *pbfInsertNote; /* Вставка надписи */                          const long PCM_INSERTNOTE                = 0x00030014;
extern const char *pbfInsertChord; /* Вставка репера */                          const long PCM_INSERTCHORD               = 0x00030015;
extern const char *pbfInsertFiller; /* Вставка заливки */                        const long PCM_INSERTFILLER              = 0x00030016;
extern const char *pbfInsertPicture; /* Вставка рисунка */                       const long PCM_INSERTPICTURE             = 0x00030017;
extern const char *pbfInsertScale; /* Вставка шкалы */                           const long PCM_INSERTSCALE               = 0x00030018;
extern const char *pbfInsertTwoDCurve; /* Вставка двумерной кривой */            const long PCM_INSERTTWODCURVE           = 0x00030019;
extern const char *pbfInsertHandleInter; /* Вставка интервала обработки */       const long PCM_INSERTHANDLEINTER         = 0x0003001A;
extern const char *pbfPlansheetCurvesList; /* Список кривых */                   const long PCM_PLANSHEETCURVESLIST       = 0x0003001B;

extern const char *pbfExitExecuteWindow; /* Возврат */                           const long PCM_EXITEXECUTEWINDOW         = 0x00040001;
extern const char *pbfInsertPlasts; /* Вставка пропластков */                    const long PCM_INSERTPLASTS              = 0x00040002;
extern const char *pbfDeletePlasts; /* Удаление пропластков */                   const long PCM_DELETEPLASTS              = 0x00040003;
extern const char *pbfDeletePlastsByOne; /* Удаление пропластков по одному */    const long PCM_DELETEPLASTSBYONE         = 0x00040004;
extern const char *pbfSelectWellV4; /* Выбор скважины */                         const long PCM_SELECTWELLV4              = 0x00040005;
extern const char *pbfEditLoadConditionFilter; /* Фильтр загрузки кривых */      const long PCM_EDITLOADCONDITIONFILTER   = 0x00040006;
extern const char *pbfInsertPlastsWithClass; /* Вставка пропластков 2 */         const long PCM_INSERTPLASTSWITHCLASS     = 0x00040007;
extern const char *pbfCut; /* Вырезать */                                        const long PCM_CUT                       = 0x00040008;
extern const char *pbfCopy; /* Копировать */                                     const long PCM_COPY                      = 0x00040009;
extern const char *pbfPaste; /* Вставить */                                      const long PCM_PASTE                     = 0x0004000A;
extern const char *pbfSelectAll; /* Выделить все */                              const long PCM_SELECTALL                 = 0x0004000B;
extern const char *pbfCorrectPlasts; /* Корректировка */                         const long PCM_CORRECTPLASTS             = 0x0004000C;


/* Возвращаемое значение для функции PrimeExecuteFunction */
const long paExecuted    =  0; // Функция выполнена
const long paNotExecuted = -1; // Функция не выполнена
const long paExecError   = -2; // Ошибка выполнения (возвращено функцией)
const long paException   = -3; // Исключение при выполнении
const long paUserCancel  = -4; // Прервано пользователем

/* Флаги FindFlags функции FindPlanObject */
const long fpofUseTestObject      = 0x00000001;
const long fpofAllowWithoutData   = 0x00000002;
const long fpofForceWithoutData   = 0x00000004;
const long fpofSourceOnly         = 0x00000008;
const long fpofResultOnly         = 0x00000010;
const long fpofLayerDataOnly      = 0x00000020; /* Только попластовые данные */
const long fpofContinuousDataOnly = 0x00000040; /* Только непрерывные данные */

/* Флаги ObjMask функции FindPlanObject */
const long fpomAll         = -1;
const long fpomCurves      = 0x00000001;
const long fpomLayerTowers = 0x00000002;
const long fpomDepthTowers = 0x00000004;

/* Флаги Flags функции InsertOrReplaceObject */
const long irofAlwaysInsertNew       = 0x00000001;
const long irofInsertNewIfUserCancel = 0x00000002;
const long irofDontMake              = 0x00000004;
const long irofSourceTemplateOnly    = 0x00000008;
const long irofResultTemplateOnly    = 0x00000010;
const long irofSelectFirstIfMany     = 0x00000020;
const long irofSelectNewestIfMany    = 0x00000040;
const long irofSelectOldestIfMany    = 0x00000080;
const long irofUserSelectIfMany      = 0x00000100;

/* Флаги открытия планшета */
const long cmdofCreateFromTemplate        = 0x00000001;
const long cmdofChangeAutoReloadFlag      = 0x00000002;
const long cmdofAutoReload                = 0x00000004;
const long cmdofChangeReloadAllCurvesFlag = 0x00000008;
const long cmdofReloadAllCurves           = 0x00000010;
const long cmdofQuietMode                 = 0x00000020;
const long cmdofReloadQuietIfSuccess      = 0x00000040;
const long cmdofAddToExistingWindow       = 0x00000080;
const long cmdofAlwaysReopen              = 0x00000100;
const long cmdofNoRedraw                  = 0x00000200;
const long cmdofTargetIsExistingPlansheet = 0x00000400;
const long cmdofDisableSelectSheetName    = 0x00000800;
const long cmdofDisableViewChange         = 0x00001000;
const long cmdofDontAddToRecent           = 0x00002000;
const long cmdofInsertAfterTarget         = 0x00004000;
const long cmdofOpenHidden                = 0x00008000;

/* Флаги сохранения планшета */
const long cmdsfSaveToTemplate     = 0x00000001;
const long cmdsfSlaveTablesDlg     = 0x00000002;
const long cmdsfQueryPack          = 0x00000004;
const long cmdsfPack               = 0x00000008;
const long cmdsfQueryName          = 0x00000010;
const long cmdsfOverwritePlanTable = 0x00000020;
const long cmdsfForceSave          = 0x00000040;
const long cmdsfDontAddToRecent    = 0x00000080;
const long cmdsfNoProgressBar      = 0x00000100;

/* Флаги разрешения/запрета сохранения объектов в шаблон планшета */
const long sptofCurves  = 0x00000001;
const long sptofPoints  = 0x00000002;
const long sptofInters  = 0x00000004;
const long sptofTowers  = 0x00000008;
const long sptofNotes   = 0x00000010;
const long sptofFillers = 0x00000020;
const long sptofScales  = 0x00000040;
const long sptofRepers  = 0x00000080;

/* Флаги Flags функции ShowPlanWindow */
const long cmdshVisible = 0x00000001; /* Показать окно (иначе - спрятать) */

/* ==== Далее идут строчные константы для сохранения планшета ============ */
/* ======================================================================= */
extern char *fnPlanName;      /* Название планшета */
extern char *fnPlanColor;     /* Цвет рамки планшета */
extern char *fnPlanWidth;     /* Ширина планшета */
extern char *fnPlanRoof;      /* Значение кровли планшета */
extern char *fnPlanSole;      /* Значение подошвы планшета */
extern char *fnScaleIndex;    /* Номер стандартного масштаба */
extern char *fnScaleValue;    /* Значение нестандартного масштаба */
extern char *fnViewScaleMul;  /* Масштаб просмотра - числитель */
extern char *fnViewScaleDiv;  /* Масштаб просмотра - знаменатель */
extern char *fnLitolTable;    /* Название таблицы литологий */
extern char *fnTableFont;     /* Шрифт названия таблицы литологий */
extern char *fnTableSize;     /* Размер названия таблицы литологий */
extern char *fnTableJust;     /* Выравнивание названия таблицы литологий */
extern char *fnTableSpace;    /* Отступ снизу после легенды */
extern char *fnLitolFont;     /* Шрифт названия литологии */
extern char *fnLitolSize;     /* Размер названия литологии */
extern char *fnLitolJust;     /* Выравнивание названия литологии */
extern char *fnLitolSpace;    /* Отступ названия литологии */
extern char *fnLitolWidth;    /* Ширина названия литологии */
extern char *fnLitolHeigth;   /* Высота названия литологии */
extern char *fnTemplateName;  /* Название шаблона планшета */
extern char *fnTemplateHelp;  /* Краткое описание планшета */
extern char *fnTemplateInfo;  /* Полное описание планшета */
extern char *fnNameDict;      /* Словарь имён кривых */
extern char *fnUnitDict;      /* Словарь единиц измерения */
extern char *fnName2UnitDict; /* Словарь перевода имён в единицы измерения */
extern char *fnPlanFlags;     /* Флаги планшета */
extern char *fnCurDepth;      /* Текущая глубина планшета */

extern char *anPrintIntervals; /* Массив интервалов печати планшета */
extern char *fnPrintIntervalRoof;   /* Кровля интервала */
extern char *fnPrintIntervalSole;   /* Подошва интервала */
extern char *fnPrintIntervalScale;  /* Масштаб вывода интервала */
extern char *fnPrintIntervalIndent; /* Пропуск снизу */
extern char *fnPrintIntervalFlags;  /* Флажки печати интервала (см. константы pifXXXX) */

/* Строка общая для всех объектов */
extern char *fnState; /* Флаги состояния объекта */
extern char *fnIdentifier;
extern char *fnOwnerIdentifier;
extern char *fnLegendPlace; /* Позиция легенды: в поле линеек или в поле легенд */
/* Строки для кривых */
extern char *anViewCurve;
extern char *fnCurveInfo; /* Ключевая информация о кривой (не изменяется) */
/* Параметры отображения данной кривой */
extern char *anCurveStyle;
extern char *fnCurveStart;     /* Начало области размещения кривой */
extern char *fnCurveWidth;     /* Ширина области размещения кривой */
extern char *fnCurveColor;     /* Номер кривой (см.файл WSIGF.CRV) */
extern char *fnCurveMinimum;   /* Значение кривой на левой границе */
extern char *fnCurveScale;     /* Масштаб кривой (физ.ед.на 1 см.) */
extern char *fnCurveModul;     /* Модуль логарифмического масштаба */
extern char *fnCurvePower;     /* Основание логарифм.масштаба      */
extern char *fnCurveFlags;     /* Флажки отрисовки кривой (cfXXXX) */
extern char *fnCurveMHIndex;   /* Обработка сносов (mvXXXX)        */
extern char *fnCurveMHValue;   /* Значение нестанд.коэфф.перемасш. */
extern char *fnCurveSHIndex;   /* Обработка отрицательных (svXXXX) */
extern char *fnValueName; /* Название метода данной кривой    */
extern char *fnValueUnit; /* Название единицы измерения       */
/* Параметры отображения масштабной линейки */
extern char *anCurveHeader;
extern char *fnHeaderType;  /* Тип масштабной линейки: 0 - обычная, 1-размах */
extern char *fnValueJust;   /* Выравнивание значений на масштабной линейке */
extern char *fnValueIndent; /* Отступ значений на масштабной линейке */
extern char *fnValueFont;   /* Шрифт для вывода значений */
extern char *fnValueSize;   /* Высота шрифта для вывода значений */
extern char *fnValueZero;   /* Точность для вывода значений */
extern char *fnValueAdds;   /* Число дополнительных значений */
extern char *fnNameFont;    /* Шрифт для вывода названия метода */
extern char *fnNameSize;    /* Высота шрифта для вывода названия метода */
extern char *fnUnitFont;    /* Шрифт для вывода единицы измерения */
extern char *fnUnitSize;    /* Высота шрифта для вывода единицы измерения */
/* Типы и размеры значков на концах масштабной линейки */
extern char *fnLeftArrow;  /* ...тип значка слева */
extern char *fnRightArrow; /* ...тип значка справа */
extern char *fnArrowSize;  /* ...размеры значков */
/* Размеры пропусков */
extern char *fnInterLine;  /* между строками в названии метода или ед.изм.*/
extern char *fnSkipBefore; /* перед масштабной линейкой */
extern char *fnSkipAfter;  /* после масштабной линейки  */
/* Значения на сносах */
extern char *anCurveBreaks;
extern char *fnBreakFont;        /* Название шрифта для вывода значений */
extern char *fnBreakSize;        /* Размер шрифта для вывода значений */
extern char *fnBreakZero;        /* Точность вывода значений на сносах */
extern char *fnBreakVertIndent;  /* Отступ значений по вертикали */
extern char *fnBreakVertBelow;   /* Выравн.по верт.до сноса */
extern char *fnBreakVertAfter;   /* Выравн.по верт.после сноса */
extern char *fnBreakHorizIndent; /* Отступ значений по горизонт.*/
extern char *fnBreakHorizBelow;  /* Выравн.по гориз.до сноса */
extern char *fnBreakHorizAfter;  /* Выравн.по гориз.после сноса */
extern char *fnHeaderManual;     /* Ручное задание значений шапки */
extern char *fnHeaderLeft;       /* Значение шапки слева */
extern char *fnHeaderRight;      /* Значение шапки справа */
/* Отметки уровней на кривой */
extern char *anCurveLevels;
extern char *fnLevelMask;        /*  */
extern char *fnLevel;            /*  */
/* Отметки глубин на кривой */
extern char *anCurveDepths;
extern char *fnDepthMask;        /*  */
extern char *fnDepth;            /*  */
/* Данные, позволяющие получить доступ к объекты из WS файла */
extern char *anWSAccess;
extern char *fnCurveRow;         /* Номер этой строки в таблице */
extern char *fnCurveColumn;      /* Номер колонки в массиве */
extern char *fnCurveArrayName;   /* Название массива */
extern char *fnCurveTableName;   /* Название таблицы */

/* Строки для примитивов и интервалов */
extern char *anViewInter;
extern char *anViewPoint;
extern char *fnWSHStart;  /* Позиция для установки примитива */
extern char *fnWSHWidth;  /* Размеры примитива */
extern char *fnWSHColor;  /* Цвет примитива */
extern char *fnWSHRow;    /* Номер строки для данного примитива в массиве */
extern char *fnWSHArray;  /* Название массива с данным примитивом */

/* Строки для надписей */
extern char *anViewNotes;
extern char *fnNotesStart;  /* Позиция размещения надписи */
extern char *fnNotesDepth;  /* Глубина размещения надписи */
extern char *fnNotesColor;  /* Цвет вывода надписи */
extern char *fnNotesText;   /* ТЕКСТ НАДПИСИ */
extern char *fnNotesLen;    /* Длина подчеркивания */
extern char *fnNotesFont;   /* Шрифт для вывода надписи */
extern char *fnNotesSize;   /* Высота шрифта для вывода надписи */
extern char *fnNotesLine;   /* Расстояние между строками надписи */
extern char *fnNotesHJust;  /* Тип выравнивания по горизонтали (0-влево, 1-по центру, 2-вправо)*/
extern char *fnNotesVJust;  /* Тип выравнивания по вертикали (0-поверху, 1-по центру, 2-понизу*/
extern char *fnNotesUnder;  /* Подчеркивание */
extern char *fnNotesDirect; /* Направление вывода надписи ("0" - слева направо,
                                                           "1" - снизу вверх,
                                                           "2" - справа налево,
                                                           "3" - сверху вниз)*/
extern char *fnNotesFlags;   /* Флаги */
extern char *fnNotesBGColor; /* Цвет фона */

/* Строки для пустых колонок */
extern char *anEmptyTower;
/* Следующие поля одинаковы для всех типов колонок */
extern char *fnTowerStart;  /* Начало колонки */
extern char *fnTowerWidth;  /* Ширина колонки */
extern char *fnTowerColor;  /* Цвет колонки */
extern char *fnTowerName;   /* Название колонки */
extern char *fnTowerFont;   /* Шрифт для вывода названия колонки */
extern char *fnTowerSize;   /* Высота шрифта для вывода названия колонки */
extern char *fnTowerJust;   /* Тип выравнивания названия колонки (см.TViewNotesRec.HJust) */
extern char *fnTowerDirect; /* Направление вывода названия колонки (см.TViewNotesRec.Direct) */
extern char *fnTowerBefore; /* Пропуск до названия колонки */
extern char *fnTowerAfter;  /* Пропуск после названия колонки */
extern char *fnTowerInter;  /* Пропуск между строками в названии колонки */

/* Строки для колонки глубин */
extern char *anDepthTower;
extern char *fnDepthTickStep;  /* Шаг вывода рисок со значениями глубин */
extern char *fnDepthTextPlace; /* Положение значений глубин относительно рисок */
extern char *fnDepthTextJust;  /* Выравнивание значений глубин */
extern char *fnDepthFontName;  /* Шрифт для вывода значений глубин*/
extern char *fnDepthFontSize;  /* Высота шрифта для вывода значений глубин */
extern char *fnDepthAbsDepth;  /* Выводить абсолютные глубины */
extern char *fnDepthAbsFont;
extern char *fnDepthAbsZero;
extern char *fnDepthAbsSize;
extern char *fnDepthAbsJust;
extern char *fnDepthAbsInfo;
extern char *fnDepthAbsRow;
extern char *fnDepthAbsCol;
extern char *fnDepthAbsTable;
extern char *fnDepthAbsArray;
extern char *fnDepthLoadCondition; /* Условие загрузки данных */

/* Поддержка нескольких параметров для разных масштабов по глубине */
extern char *fnScale1;
extern char *fnScale2;
extern char *fnScale3;
extern char *fnScaleTickStep1;
extern char *fnScaleTickStep2;
extern char *fnScaleTickStep3;
extern char *fnScaleTickFreq1;
extern char *fnScaleTickFreq2;
extern char *fnScaleTickFreq3;
extern char *fnScaleReserved1;
extern char *fnScaleReserved2;
extern char *fnScaleReserved3;

/* Строки общие для попластовых колонок */
extern char *anInterTower;
extern char *fnInterDataName;   /* Название таблицы с данными */
extern char *fnInterDataRow;    /* Номер строки в таблице */
extern char *fnInterDataColumn; /* Номер колонки в таблице */
extern char *fnInterDataKey;    /* Ключевая строка для сверки строки */
extern char *fnInterDataArray;  /* Название поля с массивом данных */
extern char *fnInterTableName;  /* Название таблицы с интервалами */
extern char *fnInterTableRow;   /* */
extern char *fnInterTableKey;   /* */
extern char *fnInterTableArray; /* */
extern char *fnInterResFile;    /* */
extern char *fnInterResName;    /* */
extern char *fnInterDictStr;    /* Строка для словаря */
extern char *fnInterEFlags;     /* Дополнительные флаги */
extern char *fnInterLIdent;     /* Идентификатор левой кривой */
extern char *fnInterRIdent;     /* Идентификатор правой кривой */

extern char *fnInterMode;  /* Какие части выводить */
extern char *fnInterZero;  /* Точность вывода значений */
extern char *fnInterTrace; /* Параметры вывода трассировочных лучей */

/* Параметры шрифта для отображения названий стратиграфии */
extern char *fnInterStratFont;
extern char *fnInterStratSize;
extern char *fnInterStratJust;
extern char *fnInterStratDirect;
/* Параметры шрифта для отображения значений данных */
extern char *fnInterValueFont;
extern char *fnInterValueSize;
extern char *fnInterValueJust;
extern char *fnInterValuePlace;
/* Параметры шрифта для отображения значений глубин */
extern char *fnInterDepthFont;
extern char *fnInterDepthSize;
extern char *fnInterDepthJust;
extern char *fnInterDepthPlace;
extern char *fnInterLoadCondition; /* Условие загрузки данных */

/* Строки для сеток */
extern char *anLnGridTower;
extern char *anLgGridTower;
extern char *fnTickPattern; /* Рисунок мелкой сетки по глубине */
extern char *fnGridPattern; /* Рисунок мелкой сетки по ширине */
extern char *fnTickStep;    /* Шаг мелкой сетки по глубине */
extern char *fnTickFreq;    /* Частота крупной сетки по глубине */
/* Тоже самое для линейной сетки по горизонтали */
extern char *fnGridStep;
extern char *fnGridFreq;
/* Тоже самое для логарифмической сетки по горизонтали */
extern char *fnGridModul;
extern char *fnGridStart;
extern char *fnGridPower;

extern char *anViewFiller;
extern char *fnFillerStart;   /* Начало */
extern char *fnFillerWidth;   /* Ширина */
extern char *fnFillerState;   /* Состояние */
extern char *fnFillerFlags;   /* Различные флажки */
extern char *fnFiller;        /* Значение константы */
extern char *fnFillerRoof;    /* Кровля области вывода */
extern char *fnFillerSole;    /* Подошва области вывода */
extern char *fnFillerNormal;  /* Образец нормальной заливки */
extern char *fnFillerReverse; /* Образец заливки "задом наперед"*/
extern char *fnFillerLeft;    /* Образец заливки до начала */
extern char *fnFillerRight;   /* Образец заливки до конца */

extern char *fnFillerCNormal;  /*  */
extern char *fnFillerCReverse; /*  */
extern char *fnFillerCLeft;    /*  */
extern char *fnFillerCRight;   /*  */

extern char *fnFillerFont;
extern char *fnFillerSize;
extern char *fnFillerJust;
extern char *fnFillerColor;
extern char *fnFillerSpace;
extern char *fnFillerBefore;
extern char *fnFillerAfter;
extern char *fnFillerIndent;

extern char *fnFillerLInfo;  /* Ключевая информация о левой кривой */
extern char *fnFillerLRow;   /*  параметрам кривой */
extern char *fnFillerLCol;   /*  - */
extern char *fnFillerLArray; /*  - */
extern char *fnFillerLTable; /*  - */

extern char *fnFillerRInfo;  /* Ключевая информация о правой кривой */
extern char *fnFillerRRow;   /*  параметрам кривой */
extern char *fnFillerRCol;   /*  - */
extern char *fnFillerRArray; /*  - */
extern char *fnFillerRTable; /*  - */

/* Строки для рисунков в планшете */
extern char *anViewPicture;
extern char *fnPictureStart;
extern char *fnPictureWidth;
extern char *fnPictureHeigth;
extern char *fnPictureColor;
extern char *fnPictureFrames;
extern char *fnPictureSLeft;
extern char *fnPictureSRight;
extern char *fnPictureSTop;
extern char *fnPictureSBottom;
extern char *fnPictureFLeft;
extern char *fnPictureFRight;
extern char *fnPictureFTop;
extern char *fnPictureFBottom;
extern char *fnPictureFlags;
extern char *fnPictureRoof;
extern char *fnPictureSole;
extern char *fnPictureBMPDraw;
extern char *fnPictureBMPName;
extern char *fnPictureBMPTable;
extern char *fnPictureBackgroundColor;

/* Строки для реперов */
extern char *anViewReper;
extern char *fnReperStart;
extern char *fnReperWidth;
extern char *fnReperFlags;
extern char *fnReperColor;
extern char *fnReperLeftDepth;
extern char *fnReperRightDepth;
extern char *fnReperLeftCurveIdent;
extern char *fnReperRightCurveIdent;
extern char *fnReperFillerIndex;
extern char *fnReperFillColor;
extern char *fnReperIdentStr;
extern char *fnReperIdentLong;
extern char *fnReperTraceIndex;
extern char *fnReperType;

/* Строки для двумерных кривых */
extern char *anTwoDCurve;
extern char *fnTwoDStart;
extern char *fnTwoDWidth;
extern char *fnTwoDColor;
extern char *fnTwoDFlags;
extern char *fnTwoDRoof;
extern char *fnTwoDSole;
extern char *fnTwoDColorFormat;
extern char *fnTwoDDisplayName;
extern char *anTwoDFileStructure;
extern char *fnTwoDFSName;
extern char *fnTwoDFSVersion;
extern char *fnTwoDFSFlags1;
extern char *fnTwoDFSDataFormat;
extern char *fnTwoDFSDepthFormat;
extern char *fnTwoDFSRoofOrSole;
extern char *fnTwoDFSStep;
extern char *fnTwoDFSHeaderBitCount;
extern char *fnTwoDFSDataBitCount;
extern char *fnTwoDFSDataGapBitCount;
extern char *fnTwoDFSRowHeaderBitCount;
extern char *fnTwoDFSRowGapBitCount;
extern char *fnTwoDFSChanHeaderBitCount;
extern char *fnTwoDFSChanGapBitCount;
extern char *fnTwoDFSChannelDataCount;
extern char *fnTwoDFSRowChannelsCount;
extern char *fnTwoDFSDepthOffsetInBits;
extern char *fnTwoDColorTransformId;
extern char *fnTwoDStorageFlags;
extern char *fnTwoDStorageTable;
extern char *fnTwoDStorageName;
extern char *fnTwoDLegendValueDigits;
extern char *fnTwoDArgMin;
extern char *fnTwoDArgStep;
extern char *fnTwoDDataMin;
extern char *fnTwoDDataMax;
extern char *fnTwoDValMin;
extern char *fnTwoDValMax;
extern char *fnTwoDLCurveIdent;
extern char *fnTwoDRCurveIdent;
extern char *fnTwoDHdrTitleFont;
extern char *fnTwoDHdrTitleSize;
extern char *fnTwoDHdrTitleJust;
extern char *fnTwoDHdrValFont;
extern char *fnTwoDHdrValSize;
extern char *fnTwoDHdrValJust;
extern char *fnTwoDHdrValDigits;
extern char *fnTwoDHdrTickSize;
extern char *fnTwoDHdrColor;
extern char *fnTwoDHCMin;
extern char *fnTwoDHCMax;
extern char *fnTwoDHCVal0;
extern char *fnTwoDHCScale;
extern char *fnTwoDHCLineIndex;
extern char *fnTwoDHCStep;
extern char *fnTwoDHCRoof;
extern char *fnTwoDHCSole;
extern char *fnTwoDDepthShift;
extern char *fnTwoDDataFormat;
extern char *anTwoDLevels;
extern char *fnArgLevelMask;
extern char *fnFuncLevelMask;
extern char *fnArgLevel;
extern char *fnFuncLevel;

/* Дополнительные параметры легенды для двумерных кривых */
extern char *fnLegendStartValue;
extern char *fnLegendEndValue;
extern char *fnLegendStepValue;

/* Таблица преобразования значения в цвет */
extern char *tnColorTransform;
extern char *fnColorTransform;
extern char *fnCTIdent;
extern char *fnCTFlags1;
extern char *fnCTColorFormat;
extern char *fnCTTransformMode;
extern char *fnCTInterpMode;
extern char *fnCTEmptyColor;
extern char *anCTTransformArray;

/* Строки для пустых рамок (заключение) */
extern char *anFrameEmpty;
extern char *fnFrameNumber;
extern char *fnFrameStart;
extern char *fnFrameWidth;
extern char *fnFrameHeigth;
extern char *fnFrameColor;
extern char *fnFrameFlags;
extern char *fnFrameSLeft;
extern char *fnFrameSRight;
extern char *fnFrameSTop;
extern char *fnFrameSBottom;
extern char *fnFrameFLeft;
extern char *fnFrameFRight;
extern char *fnFrameFTop;
extern char *fnFrameFBottom;
extern char *fnFrameBackgroundColor;

/* Строки для рамок с таблицей (заключение) */
extern char *anFrameTable;
extern char *fnFrameSource;
extern char *fnFrameEmpty;

/* Строки для рамок с текстом (заключение) */
extern char *anFrameText;
extern char *fnFrameText;
extern char *fnFrameFont;
extern char *fnFrameSize;
extern char *fnFrameRMul;
extern char *fnFrameRDiv;
extern char *fnFrameJust;
extern char *fnFrameDir;
extern char *fnFrameInter;

/* Строки для рамок с рисунком (заключение) */
extern char *anFrameBitmap;
extern char *fnFrameBMPDraw;
extern char *fnFrameBMPName;
extern char *fnFrameBMPTable;

/* Строки для образца линии (заключение) */
extern char *anFrameLine;
extern char *fnFrameLine;
extern char *fnFrameLineLen;
extern char *fnFrameLineSpace;
extern char *fnFrameLineText;
extern char *fnFrameLineTextFont;
extern char *fnFrameLineTextSize;
extern char *fnFrameLineTextRMul;
extern char *fnFrameLineTextRDiv;

/* Таблица с растровыми рисунками */
extern char *tnBitmapBMP;
extern char *tnBitmapWMF;
extern char *tnBitmapPCX;
extern char *fnBitmapName;
extern char *fnBitmapFlag;
extern char *fnBitmapWidth;
extern char *fnBitmapHeigth;
extern char *fnBitmapByte;
extern char *fnBitmapData;

extern char *tnPlainText;
extern char *fnTextName;
extern char *fnTextData;

extern char *tnBLOBTable;
extern char *fnBLOBCode;
extern char *fnBLOBData;

extern char *anInterReper;

/* Массив параметров легенд */
extern char *anLegendItems;
extern char *fnLegendOwner;
extern char *fnLegendIndex;
extern char *fnLegendName;
extern char *fnLegendStart;
extern char *fnLegendWidth;
extern char *fnLegendFlags;  /* lfXXXX */
extern char *fnLegendState;
extern char *fnLegendFontName;
extern char *fnLegendFontSize;
extern char *fnLegendFontColor;
extern char *fnLegendIndent;
extern char *fnLegendHeight;
extern char *fnLegendHMode;
extern char *fnLegendTextPos;
extern char *fnLegendTextAlign;

/* Строка общих параметров легенд */
extern char *fnLegendCommonValues;
extern char *fnLegendCommonChanges;
extern char *fnLegendDefPlace;
extern char *anLegendHeaders;
extern char *fnLegendHeaderTitle;
extern char *fnLegendHeaderFontName;
extern char *fnLegendHeaderFontSize;
extern char *fnLegendHeaderFontColor;
extern char *fnLegendHeaderFlags;
extern char *fnLegendHeaderWidth;
extern char *fnLegendHeaderBottomIndent;

extern char *anHeaderItems;
extern char *fnHeaderItemOwnerId;
extern char *fnHeaderItemIndex;
extern char *fnHeaderItemFlags;
extern char *fnHeaderItemSeqNumber;

extern char *CBLOBText;

extern char *anViewCustom;
extern char *fnCVStart;
extern char *fnCVWidth;
extern char *fnCVData;
extern char *fnCVLibrary;
extern char *fnCVMake;
extern char *fnCVDraw;
extern char *fnCVDrawMarker;
extern char *fnCVHandleDepth;
extern char *fnCVStatusStr;
extern char *fnCVGlobalStr;
extern char *fnCVExposed;
extern char *fnCVRadius;
extern char *fnCVViewRoof;
extern char *fnCVViewSole;
extern char *fnCVActualClass;
extern char *fnCVGetData;
extern char *fnCVSetData;
extern char *fnCVDataSize;
extern char *fnCVHaveHandle;
extern char *fnCVReset;
extern char *fnCVWSName;
extern char *fnCVEditDialog;
extern char *fnCVDrawHeader;
extern char *fnCVHeaderStart;
extern char *fnCVHeaderWidth;
extern char *fnCVHeaderHeigth;
extern char *fnCVDone;

typedef void (__stdcall *TCVDraw)(void *Custom, void *Device, long DrawScale,
 long StartDepth, long StartPos, long SheetWidth,
 void *HideList);
typedef void (__stdcall *TCVDrawMarker)(void *Custom, void *Device, long DrawScale,
 long StartDepth, long StartPos,
 long MarkerDepth);
typedef void (__stdcall *TCVStatusStr)(void *Custom, long Depth, char *StatusStr);
typedef void (__stdcall *TCVGlobalStr)(void *Custom, char *GlobalStr);
typedef LongBoolean (__stdcall *TCVExposed)(void *Custom, long RoofDepth, long SoleDepth,
 long DrawScale, long StartPos, long StopPos);
typedef long (__stdcall *TCVRadius)(void *Custom, long PointDepth,
 long PointStart, long DrawScale);
typedef long (__stdcall *TCVViewRoof)(void *Custom);
typedef long (__stdcall *TCVViewSole)(void *Custom);
typedef LongBoolean (__stdcall *TCVActualClass)(void *Custom, unsigned short Mode);

typedef LongBoolean (__stdcall *TCVMake)(void *Custom);
typedef void (__stdcall *TCVHandleDepth)(void *Custom,
 long *Depth, long DrawScale, long Direct);
typedef void (__stdcall *TCVGetData)(void *Custom, void *Rec);
typedef void (__stdcall *TCVSetData)(void *Custom, void *Rec);
typedef unsigned short (__stdcall *TCVDataSize)(void *Custom);
typedef LongBoolean (__stdcall *TCVHaveHandle)(void *Custom, long Handle);
typedef void (__stdcall *TCVReset)(void *Custom);
typedef void (__stdcall *TCVWSName)(void *Custom, char *WSName);
typedef void* (__stdcall *TCVEditDialog)(void *Custom);
typedef void (__stdcall *TCVDrawHeader)(void *Custom, void *Device, long AStartDepth,
 long Length, long StartX, long StartY, long ShiftY);
typedef long (__stdcall *TCVHeaderStart)(void *Custom, void *Device, long AStartDepth);
typedef void (__stdcall *TCVHeaderWidth)(void *Custom, void *Device, long AStartDepth);
typedef void (__stdcall *TCVHeaderHeigth)(void *Custom, void *Device, long AStartDepth);
typedef void (__stdcall *TCVDone)(void *Custom);

extern char *mnCVDraw;
extern char *mnCVDrawMarker;
extern char *mnCVStatusStr;
extern char *mnCVGlobalStr;
extern char *mnCVExposed;
extern char *mnCVRadius;
extern char *mnCVViewRoof;
extern char *mnCVViewSole;
extern char *mnCVActualClass;
extern char *mnCVMake;
extern char *mnCVHandleDepth;
extern char *mnCVGetData;
extern char *mnCVSetData;
extern char *mnCVDataSize;
extern char *mnCVHaveHandle;
extern char *mnCVReset;
extern char *mnCVWSName;
extern char *mnCVEditDialog;
extern char *mnCVDrawHeader;
extern char *mnCVHeaderStart;
extern char *mnCVHeaderWidth;
extern char *mnCVHeaderHeigth;
extern char *mnCVDone;

extern char *anFrameCustom;
extern char *fnCFData;
extern char *fnCFLibrary;
extern char *fnCFMake;
extern char *fnCFReset;
extern char *fnCFUpDate;
extern char *fnCFDraw;
extern char *fnCFSetData;
extern char *fnCFGetData;
extern char *fnCFDataSize;
extern char *fnCFEditDialog;
extern char *fnCFFrameWidth;
extern char *fnCFFrameHeigth;
extern char *fnCFFrameClass;
extern char *fnCFGlobalStr;
extern char *fnCFDone;

typedef void (__stdcall *TCFMake)(void *Frame);
typedef void (__stdcall *TCFReset)(void *Frame);
typedef void (__stdcall *TCFUpdate)(void *Frame, OType LogFile, OType PointTable, OType InterTable, void *ViewsList);
typedef void (__stdcall *TCFDraw)(void *Frame, void *Device, long Y, long StartX, long StartY);
typedef void (__stdcall *TCFGetData)(void *Frame, void *Rec);
typedef void (__stdcall *TCFSetData)(void *Frame, void *Rec);
typedef unsigned short (__stdcall *TCFDataSize)(void *Frame);
typedef void* (__stdcall *TCFEditDialog)(void *Frame);
typedef long (__stdcall *TCFFrameWidth)(void *Frame, void *Device);
typedef long (__stdcall *TCFFrameHeigth)(void *Frame, void *Device);
typedef LongBoolean (__stdcall *TCFActualClass)(void *Frame, unsigned short Mode);
typedef void (__stdcall *TCFGlobalStr)(void *Frame, char *GlobalStr);
typedef void (__stdcall *TCFDone)(void *Frame);

extern char *mnCFMake;
extern char *mnCFReset;
extern char *mnCFUpDate;
extern char *mnCFDraw;
extern char *mnCFSetData;
extern char *mnCFGetData;
extern char *mnCFDataSize;
extern char *mnCFEditDialog;
extern char *mnCFFrameWidth;
extern char *mnCFFrameHeigth;
extern char *mnCFFrameClass;
extern char *mnCFGlobalStr;
extern char *mnCFDone;

/* Имена параметров ПРАЙМа */
/* Точность установки глубин (long): 0 = 1 см; 1 = 1 дм; 2 = 1 м */
extern char *ppnDepthPrecIndex;
/* Точность установки позиции (long): 0 = 0.1 мм; 1 = 1 мм; 2 = 1 см */
extern char *ppnPosPrecIndex;
/* Параметры по умолчанию для попластовых колонок */
extern char *ppnDefTowerInterRec;

/*==================================================*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*=      ФУНКЦИИ                                   =*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*==================================================*/

/* Подключить функции Prime32.exe */
extern "C" LongBoolean Prime32Connect(void);
/* То же, но предварительно проверить, если уже подключены */
extern "C" LongBoolean Prime32CheckConnect(void);

/* Возвращает флажок приложений */
unsigned char GetHASPFlag(void) ;
long WSIGFExec(const char *ExeName, const char *CmdLine, LongBoolean TextMode);
/* Системно-зависимая - получить дескриптор главного окна Prime32 */
HWND Prime32Handle(void);
/* Системно-зависимая - активизировать Prime32 */
void PrimeBringToFront(void);
/* Получить рабочий каталог ПРАЙМа */
long GetPrimeWorkDir(char *lpDirName,long nSize);
/* Получить каталог рабочей базы */
long GetPrimeWorkBaseDir(char *lpDirName,long nSize);
/* Установить каталог рабочей базы */
LongBoolean SetPrimeWorkBaseDir(const char *NewValue);
/* Получить каталог настроек ПРАЙМа */
long GetPrimeSettingsDir(char *lpDirName,long nSize);
/* Получить строку текущей версии */
long GetPrimeVersion(char *lpVersion,long nSize);

/* Системно-зависимая - запретить выгрузку после выполнения */
void PrimeDisableUnload(HINSTANCE LibHandle);
/* Системно-зависимая - выгрузить при первой возможности */
void PrimeEnableUnload(HINSTANCE LibHandle);
/* Системно-зависимая - разрешена ли выгрузка? */
LongBoolean PrimeUnloadEnabled(HINSTANCE LibHandle);
/* Системно-зависимая - заканчивает ли система работу? */
LongBoolean PrimeTerminating(void);

/* ========================================================================= */
/* Уничтожение любого объекта */
void DoneObject(void* P);
/* ========================================================================= */
/* Создать в динамической памяти Паскаль-строку */
PPasString NewPString(const char* S);
/* Длина Паскаль-строки */
unsigned char LenPString(PPasString P);
/* Уничтожить Паскаль-строку и освободить память */
void FreePString(PPasString P);
/* ========================================================================= */
void* GetMemLib(long ASize);
void FreeMemLib(void *P,long ASize);
void* AllocMemLib(long ASize);
void ReallocMemLib(void **P, long NewSize);
void PCharDispose(char *P);
/* ========================================================================= */
/* Создать новую коллекцию объектов */
void* InitList(long Limit = 8, long Delta = 8);
/* Создать новую коллекцию строк */
void* InitStringList(long Limit = 8, long Delta = 8);
/* Создать новую коллекцию указателей */
void* InitEmptyList(long Limit = 8, long Delta = 8);
/* Создать новую коллекцию несортированных строк */
void* InitUnsortList(long Limit = 8, long Delta = 8);
/* Возвращает число элементов коллекции */
long ListCount(void *List);
/* Возвращает элемент по его индексу */
void* ListAt(void *List,long Index);
/* Удаляет элемент из коллекции */
void ListAtDelete(void *List,long Index);
/* Уничтожает элемент коллекции */
void ListAtFree(void *List,long Index);
/* Вставить элемент в коллекцию */
void ListAtInsert(void *List,long Index,void* Item);
/* Изменить элемент коллекции */
void ListAtPut(void *List,long Index,void *Item);
/* Удалить элемент коллекции */
void ListDelete(void *List,void *Item);
/* Удаляет из коллекции все его элементы */
void ListDeleteAll(void *List);
/* Уничтожает элемент коллекции */
void ListFree(void *List,void *Item);
/* Уничтожает все элементы коллекции */
void ListFreeAll(void *List);
/* Возвращает индекс данного элемента в коллекции */
long ListIndexOf(void *List,void *Item);
/* Добавляет элемент в коллекцию */
void ListInsert(void *List,void *Item);
/* Удаляет из коллекции пустые элементы */
void ListPack(void *List);
/* Поиск строки в коллекции (только для коллекций строк) */
long ListSearch(void *List,const char *Key);
/* ========================================================================= */

/* ========================================================================= */
/*Работа с объектами планшета */
/* Создать кривую */
void* CreateWSCurve(OType DataHandle,long RowNumber,OType ArrayHandle,unsigned char ColNumber);
/* Создать вектор-кривую */
void* CreateWSRotCurve(OType DataHandle,long RowNumber,OType ArrayHandle,unsigned char ColNumber,unsigned char RotColNumber);
/* Создать примитив */
void* CreateWSPoint(OType ArrayHandle,long ArrayRow);
/* Создать интервал */
void* CreateWSInter(OType ArrayHandle,long ArrayRow);
/* Создать пустую колонку */
void* CreateWSTower(long Color,long Start,long Width,const char *Name);
/* Создать колонку глубин */
void* CreateWSDepth(long Color,long Start,long Width,const char *Name);
/* Создать линейную сетку */
void* CreateWSLnGrid(long Color,long Start,long Width,const char *Name);
/* Создать логарифмическую сетку */
void* CreateWSLgGrid(long Color,long Start,long Width,const char *Name);
/* Создать попластовую колонку */
void* CreateWSPlast(long Color,long Start,long Width,const char *Name,
  OType DataHandle,OType ArrayHandle,long RowNumber,unsigned char ColNumber,
  OType DataInter,OType ArrayInter,long RowInter);

/* Создать комментарий */
void* CreateWSNotes(long ADepth,const char *P);
/* Создать заливку */
void* CreateWSFills(long AStart,long AWidth,long AFlags,long ARoof,long ASole,
 long Filler,long RevFill,long LeftFill,long RightFill,
 void *ALeftCurve,void *ARightCurve,float AConst);
/* Создать рисунок планшета */
void* CreateWSPicture(void);
/* Создать двумерную кривую */
void* CreateWSTwoDCurve(void);
/* Создать пустую рамку */
void* CreateWSFrame(void);
/* Создать рамку с текстом */
void* CreateWSText(void);
/* Создать рамку с таблицей */
void* CreateWSTable(void);
/* Создать рамку с рисунком */
void* CreateWSBitmap(void);
/* Создать репер */
void* CreateWSChord(long Start,long Width,long Color,long Flags,
  void *LeftCurve,void *RightCurve,long LeftDepth,long RightDepth);
/* Создать шкалу */
void* CreateWSScale(long Start, long Width, long Color, long Flags,
  float AMinim, float AScale, void *Curve, long Depth,
  const char *Title);
/* Взять с планшета интервал обработки (объект типа wsInterReper) */
void* GetHandleInter(void *lpPlansheet, long dwReserved, long *dwRoof, long *dwSole);
/* Создать новый интервал обработки (объект типа wsInterReper) */
void* CreateHandleInter(long dwReserved, long dwColor, long dwFlags, long dwRoof, long dwSole);

/* Функции для отображения информации о ходе долгого процесса */
void StartProcess(const char *S);
void StepProcess(long Min,long Val,long Max);
void StopProcess(void);

/* Получить начало объекта */
long WSStart(void *P);
/* Получить ширину объекта */
long WSWidth(void *P);
/* Получить статус объекта */
long WSState(void *P);
/* Получить тип объекта */
long WSType(void *P);
/* Инициализировать объект (должен вызываться перед вставкой объекта
в планшет). Возвращает ИСТИНА если объект можно вставлять, ЛОЖЬ
если нельзя */
LongBoolean WSMake(void *P);
/* Принадлежит ли объект указанному классу */
LongBoolean WSActual(void *P,unsigned short Mode);
/* Получить данные объекта */
void WSGetData(void *P, void *Rec);
/* Передать данные объекту */
void WSSetData(void *P, void *Rec);
/* Размер данных объекта */
unsigned short WSDataSize(void *P);
/* Сбросить внутренние буфера объекта */
void WSReset(void *P);
/* Установить флажки состояний объекта */
void WSSetState(void *P,unsigned short Mask,LongBoolean Enable);
/* Получить флажки состояний объекта */
LongBoolean WSGetState(void *P,unsigned short Mask);
/* Получить кровлю объекта */
long WSRoof(void *P);
/* Получить подошву объекта */
long WSSole(void *P);
/* Получить глубину первого непустого значения */
long WSNBRoof(void *P);
/* Получить глубину последнего непустого значения */
long WSNBSole(void *P);
/* Получить название объекта */
void WSName(void *P,char *Name);
/* Функции для чтения/записи в/из диалогового окна */
LongBoolean WSSetDialog(void *P);
LongBoolean WSGetDialog(void *P);
/* Установить начало объекта */
void WSSetStart(void *P,long Start);
/* Установить ширину объекта */
void WSSetWidth(void *P,long Width);
/* Получить данные рамки */
void FrameGetData(void *Frame, void *Rec);
/* Передать данные рамке */
void FrameSetData(void *Frame, void *Rec);
/* Размер данных рамки */
unsigned short FrameDataSize(void *Frame);
/* Возвращает начало рамки */
long FrameGetStart(void *P);
/* Возвращает ширину рамки */
long FrameGetWidth(void *P);
/* Возвращает флажки рамки */
long FrameGetState(void *P);
/* Устанавливает начало рамки */
void FrameSetStart(void *P,long Value);
/* Устанавливает ширину рамки */
void FrameSetWidth(void *P,long Value);
/* Устанавливает состояние рамки */
void FrameSetState(void *P,long Value);

/* Работа с кривыми */
/* Обновить внутренние данные кривой */
long WSCurveActual(void *P);
/* Количество точек кривой */
long WSCurveCount(void *P);
/* Возвращает значение глубины в точке с указанным номером */
long WSCurveDepth(void *P,long Index);
/* Возвращает номер точки с указанной глубиной */
long WSCurveIndex(void *P,long Depth);
/* Возвращает значение кривой/колонки в указанной точке */
float WSCurveValue(void *P,long Depth);
/* Возвращает значение кривой/колонки в указанной точке как строку */
long WSCurveValueStr(void *P,long Depth,char *Value,long ValueSize);
/* Возвращает код литологии для попластовой колонки на указанной глубине */
long GetLitholByDepth(void *P, long Depth);
/* Возвращает стратиграфию для попластовой колонки на указанной глубине */
long GetStratByDepth(void *P, long Depth, char *Strat, long StratSize);
/* Возвращает легенду попластовой колонки на указанной глубине */
long GetLegendByDepth(void *P, long Depth, char *Legend, long LegendSize);
/* Получить массив пластов из попластовой колонки */
OType GetTowerPlastArray(void *Tower);

/* Найти минимальное, максимальное и среднее значение кривой в указанном
интервале (если кровля и подошва интервала равны, то по всей кривой) */
long WSCurveMinMidMax(void *P,long Roof,long Sole,float *Min,float *Mid,float *Max);
/* Аналогично предыдущему, но еще возвращаются значения глубин для минимума и максимума */
long WSCurveMinMidMaxH(void *P,long Roof,long Sole,float *Min,float *Mid,float *Max,float *MinH,float *MaxH);
/* Параметры линейной апроксимации кривой для указанного интервала */
long WSCurveLinear(void *P,long Roof,long Sole,float *A,float *B);
/* Выбрать шаблон для кривой */
long WSCurveSetTemplate(void *P,const char *ATemplateName,char *Res);
/* Установить шаблон для объекта. TemplateObj должен быть на планшете, Obj - не обязательно */
LongBoolean SetTemplateObject(void *Obj, void *TemplateObj, long dwFlags, void *lpReserved);
/* Получить шаблон для объекта на планшете */
void *GetTemplateObject(void *Obj, void *Plansheet);
/* Получить шаблон данных объекта планшета */
OType CreateTemplateDataObject(void *Obj, void *Plansheet, const char *ID, void *Reserved);
/* Получить идентификатор объекта на планшете */
long GetViewID(void *View);
/* Найти объект планшета по идентификатору */
void *FindViewByID(void *Plansheet, long ID);
/* Чтение/запись условия загрузки */
long CurveGetLoadCondition(void *Curve, char *lpCondition, long nConditionSize);
LongBoolean CurveSetLoadCondition(void *Curve, const char *lpCondition);

/* Вывести сообщение в строке статуса */
void PutMessage(const char *S);
/* Вывести сообщение в строке статуса и ждать события от пользователя */
void WaitMessage(const char *S);

/* Очистить сообщение в строке статуса */
void ClrMessage(void);

/* Получить указатель на текущее окно */
void* CurrentWindow(void);
/* Получить название файла текущего окна */
void WindowFileName(char *FileName);
/* Получить тип текущего окна */
void WindowTypeName(char *TypeName);

/* Получить указатель на текущее окно с планшетом */
void* CurrentPlansheet(void);
/* Получить название шаблона из которого был создан планшет */
long GetPlanTemplate(void *Plansheet,char *PlanTemplate);
/* Получить заголовок окна планшета */
long GetPlanTitle(void *Plansheet,char *PlanTitle);

/* Получить/записать кровлю/подошву планшета */
long GetPlanRoof(void *Plansheet);
long GetPlanSole(void *Plansheet);
void SetPlanRoof(void *Plansheet,long Roof);
void SetPlanSole(void *Plansheet,long Sole);

/* Получить текущий режим планшета */
long GetPlanHandle(void *Plansheet);
/* Установить текущий режим планшета */
void SetPlanHandle(void *Plansheet,long Handle);
/* Получить число объектов в планшете */
long GetPlanCount(void *Plansheet);
/* Получить список всех объектов планшета */
void* GetPlanList(void *Plansheet);
void* GetPlanListX(void *Plansheet);
/* Получить число выделенных объектов в планшете */
long GetPlanActiveCount(void *Plansheet);
/* Получить список выделенных объектов планшета */
void* GetPlanActiveList(void *Plansheet);
/* Получить текущую глубину на планшете */
long GetPlanDepth(void *Plansheet);
/* Установить текущую глубину на планшете */
void SetPlanDepth(void *Plansheet, long Depth);
/* Получить текущий масштаб по глубине */
long GetPlanScale(void *Plansheet);
/* Установить масштаб по глубине */
void SetPlanScale(void *Plansheet,long Scale);
/* Получить ширину планшета */
long GetPlanWidth(void *Plansheet);
/* Установить ширину планшета */
void SetPlanWidth(void *Plansheet,long Width);
/* Получить цвета оформления планшета. Значения параметра Index.
0 - Цвет фона планшета
1 - Цвет служебных линий на планшете
2 - Цвет выделенных объектов
3 - Цвет точек дискретизации на кривой
4 - Цвет маркера на объекте
*/
unsigned char GetPlanColor(long Index);
/*  Установить цвета оформления планшета. Значения параметра Index такие же. */
void SetPlanColor(long Index,unsigned char Color);
/* Получить название рабочей области */
void GetWorkSpace(void *Plansheet,char *WorkSpace);
/* Видна ли шапка планшета */
LongBoolean HeaderState(void *Plansheet);

/* Показать/спрятать шапку планшета */
void ShowHeader(void *Plansheet);
void HideHeader(void *Plansheet);

/* Перерисовать планшет */
void DrawPlansheet(void *Plansheet);
/* Получить число объектов указанного типа */
long ObjectCount(void *Plansheet,long Mode);
/* Получить список объектов указанного типа */
void* ObjectList(void *Plansheet,long Mode);
/* Получить число активных объектов указааного типа */
long ActiveCount(void *Plansheet,long Mode);
/* Получить список активных объектов указааного типа */
void* ActiveList(void *Plansheet,long Mode);

/* Получить количество объектов планшета заданного типа */
long StrictObjectCount(void *Plansheet, long AWSType);
/* Получить список объектов планшета заданного типа */
void* StrictObjectList(void *Plansheet, long AWSType);
/* Получить количество выделенных объектов планшета заданного типа */
long StrictActiveCount(void *Plansheet, long AWSType);
/* Получить список выделенных объектов планшета заданного типа */
void* StrictActiveList(void *Plansheet, long AWSType);

/* Добавить объект в планшет */
void InsertObject(void *Plansheet,void *View);
/* Перерисовать объект */
void RedrawObject(void *Plansheet,void *View);
/* Перерисовать объект в режиме XOR */
void RedrawObjectXor(void *Plansheet,void *View);
/* Удалить объект из планшета */
void DeleteObject(void *Plansheet,void *View);
/* Сохранить состояния объектов */
void SaveState(void *Plansheet);
/* Восстановить состояния объектов */
void RestoreState(void *Plansheet);
/* Очистить флажки состояния согласно маске */
void ClearState(void *Plansheet,long Mask);
/* Установить флажки состояния согласно маске */
void SetupState(void *Plansheet,long Mask);
/* Запустить окно в модальном режиме */
LongBoolean ExecuteWindow(void *Plansheet);
/* Получить описатель объекта с примитивами */
void PointTable(void *Plansheet,OType *Handle);
/* Получить описатель объекта с интервалами */
void InterTable(void *Plansheet,OType *Handle);
/* Перерисовать объекты */
void RedrawObjects(void *Plansheet);
/* Запретить перерисовывать шапку диаграмм (линейку и легенду) по RedrawObject */
void DisableHeaderRedraw(void);
/* Разрешить перерисовывать шапку диаграмм (линейку и легенду) по RedrawObject */
void EnableHeaderRedraw(void);

/* Регистрация окна (можно будет выбрать из списка) */
long RegisterPrimeWindow(HWND H, const char* PrimeName);
/* То же, но с вставкой в определённую позицию списка */
long RegisterPrimeWindowAt(HWND H, const char* PrimeName, long Number);
/* Отмена регистрации окна */
long UnregisterPrimeWindow(HWND H);

/* Получить ссылку на текущую обрабатываемую колонку */
void* CurrentTower(void *Plansheet);
/* Получить ссылку на текущую обрабатываемую кривую */
void* CurrentCurve(void *Plansheet);
/* Получить текущий режим обработки кривых */
long CurveMode(void *Plansheet);

/* Получить режим отчета */
long GetReportHandle(void *Plansheet);
/* Установить режим отчета */
void SetReportHandle(void *Plansheet,long Handle);
/* Получить число объектов в отчете */
long GetReportCount(void *Plansheet);
/* Получить число объектов отчета указанного типа */
long FrameCount(void *Plansheet,long Mode);
/* Получить список объектов отчета указанного типа */
void* FrameList(void *Plansheet,long Mode);
/* Получить число активных объектов отчета указанного типа */
long ActiveFramesCount(void *Plansheet,long Mode);
/* Получить список активных объектов отчета указанного типа */
void* ActiveFramesList(void *Plansheet,long Mode);
/* Получить число объектов подвала указанного типа */
long FooterFrameCount(void *Plansheet, long Mode);
/* Получить список объектов подвала указанного типа */
void* FooterFrameList(void *Plansheet, long Mode);
/* Получить число активных объектов подвала указанного типа */
long ActiveFooterFramesCount(void *Plansheet, long Mode);
/* Получить список активных объектов подвала указанного типа */
void* ActiveFooterFramesList(void *Plansheet, long Mode);
/* Добавить новый объект в отчет */
void InsertFrames(void *Plansheet,void *Frame);
/* Удалить объект из отчета */
void DeleteFrames(void *Plansheet,void *Frame);
/* Установить кривые для реперов */
void SetLeftCurve(void *Plansheet,void *Curve);
void SetRightCurve(void *Plansheet,void *Curve);

/* Отслеживание на экране */
LongBoolean TrackData(void *Plansheet,long Mode);
/* Установить формат отображения информации при отслеживании */
void SetTrackFormat(void *Plansheet,const char *S);
/* Установить интервала отслеживания */
void SetTrackRoof(void *Plansheet,long Roof);
void SetTrackSole(void *Plansheet,long Sole);
/* Установить начальные параметры отслеживания */
void SetTrackDepth(void *Plansheet,long Depth);
void SetTrackStart(void *Plansheet,long Start);
void SetTrackShift(void *Plansheet,long Shift);
void SetTrackMinim(void *Plansheet,float Minim);
void SetTrackScale(void *Plansheet,float Scale);
void SetTrackValue(void *Plansheet,float Value);
void SetTrackCurve(void *Plansheet,void *Curve);

typedef long (__stdcall *TTrackUserStringFunc)(void *dwCookie, long dwStart,
  long dwDepth, char *lpBuffer, long dwBufferSize);
typedef double (__stdcall *TTrackUserValueFunc)(void *dwCookie, long dwStart,
  long dwDepth);

/* Установить Callback-функцию для получения одного из значений отслеживания */
long SetTrackUserValueCallback(void *lpPlansheet, long dwIndex,
  TTrackUserValueFunc lpfnTrackUserValueCallback, void *dwCookie);
/* Установить Callback-функцию для получения одной из строк отслеживания */
long SetTrackUserStrCallback(void *lpPlansheet, long dwIndex,
  TTrackUserStringFunc lpfnTrackUserStrCallback, void *dwCookie);
/* Получить результирующие параметры отслеживания */
long GetTrackDepth(void *Plansheet);
long GetTrackStart(void *Plansheet);
/* Получить значение отслеживания */
float GetTrackValue(void *Plansheet);
/* Получить пользовательское значение отслеживания */
double GetTrackUserValue(void *lpPlansheet, long dwIndex);
/* Получить пользовательскую строку отслеживания */
long GetTrackUserString(void *lpPlansheet, long dwIndex,
  void *lpBuffer, long dwBufferSize);

/* Работа с интервалами печати планшета */
/* Получить количество интервалов печати планшета */
long GetPrintIntervalsCount(void* Plansheet);
/* Получить интервал печати с номером Index, 0 <= Index < GetPrintIntervalsCount */
LongBoolean GetPrintInterval(void* Plansheet, long Index, TPrintInterval* Interval);
/* Установить интервал печати с номером Index, 0 <= Index < GetPrintIntervalsCount */
LongBoolean SetPrintInterval(void* Plansheet, long Index, const TPrintInterval* Interval);
/* Добавить (в конец списка) новый интервал печати */
LongBoolean AddPrintInterval(void* Plansheet, const TPrintInterval* Interval);
/* Добавить новый интервал печати с номером Index */
LongBoolean AddPrintIntervalAt(void* Plansheet, long Index, const TPrintInterval* Interval);
/* Удалить интервал печати с номером Index */
LongBoolean DeletePrintInterval(void* Plansheet, long Index);
/* Удалить все интервалы печати планшета */
LongBoolean DeleteAllPrintIntervals(void* Plansheet);

/* По колонке глубин и глубине возвращает абсолютную глубину */
float AbsDepthValue(void* Tower, long Depth);
/* По колонке глубин и абсолютной глубине возвращает глубину */
long GetDepthByAbsDepth(void *Tower, float AbsDepth);

/* Возвращает список активизированных кривых не менее Min и не более Max
если нет активизированных кривых, то запрашивается у пользователя */
void* ActiveCurves(long Min,long Max,const char *Title);
void* ActiveDViews(long Min,long Max,const char *Title);
void* ActivePlastTowers(long Min,long Max,const char *Title);
void* ActiveTowers(long Min,long Max,const char *Title);
void* ActiveText(long Min,long Max,const char *Title);

/* Получить кривую по имени поля, если в планшете единственная такая кривая */
void* GetOneCurve(const char *Name,const char *Value);
/* Получить кривую по имени на планшете, если в есть единственная такая кривая */
void* GetOneCurveByName(const char *Value);

/* Получить попластовую колонку по имени */
void* GetPlastTower(const char *Name);

/* Поиск объекта по даным или по условиям загрузки */
long FindPlanObject(void *lpPlansheet, const char *lpszConditions,
  void *lpTestObject, long dwFindFlags, long dwObjMask, void **lplpFound,
  void *lpFoundObjs, void *lpReserved);
/* Поиск условий загрузки кривой по заданному методу в заданном файле шаблона */
long FindCurveLoadCondition(const char *lpSheetTemplateFileName,
  const char *lpCurveMethodName, long FindFlags,
  char *lpLoadCondition, long dwLoadConditionSize,
  void *lpReserved);
/* Вставить объект, возможно, с заменой данных существующего объекта */
LongBoolean InsertOrReplaceObject(void *Plansheet, void **lplpObj,
  long Flags, long *lpErrCode, void *Reserved);
/* Возвращает одну выделенную пользователем кривую */
void* SelectCurve(const char *Title);
/* Возвращает кривую или попластовую колонку, выделенную пользователем */
void* SelectDView(const char *Title);
void* SelectPlastTower(const char *Title);
void* SelectTower(const char *Title);
void* SelectText(const char *Title);
/* Возвращает одну выделенную пользователем двумерную кривую */
void* SelectTwoDCurve(const char *Prompt);
long GetCurveH(void *P,OType *ObjHandle,OType *ArrHandle,unsigned short *Column);
void GetCurveName(void *Curve, char *CurveName);
/* Интерактивный выбор одной кривой */
void* SelectOneCurve(const char *Prompt);
/* Возвращает один выделенный пользователем объект планшета */
void* SelectObject(const char *Prompt);
/* Возвращает один выделенный пользователем объект планшета указанного типа */
void* SelectObjectByType(const char *Prompt, long AWSType);

/* Проверка наличия кривых в планшете */
LongBoolean CheckCurves(void);

LongBoolean SelectDepth(long *Depth,const char *Title,void *Curve = NULL);
LongBoolean SelectInter(long *Roof,long *Sole,const char *Title,void *Curve);
LongBoolean SelectShift(long *Delta,const char *Title);
LongBoolean SelectValue(long Start,float Minimum,float Scale,float *Value,const char *Title);
LongBoolean SelectStart(long *Start,const char *Title);
LongBoolean SelectStartWidth(long *Start,long *Width,const char *Title);

/* Возвращает минимальный интервал для списка кривых */
void MinInter(void *List,long *Roof,long *Sole);

/* Возвращает максимальный интервал для списка кривых */
void MaxInter(void *List,long *Roof,long *Sole);
/* Возвращает существенное значение кривой в интервале около min/мах
с усреднением по Num точкам. Option = 0-min, 1-max  */
float GetMainVal(void *Curve,long Roof,long Sole,long Num,long HC,long DH,long Option);

typedef void (__stdcall *PProcess)(long Min, long Val, long Max);
typedef float (__stdcall *TTransform)(float Y);
typedef float (__stdcall *TArgTransform)(float X, float Y);
typedef float (__stdcall *TWinTransform)(float *X, long XLastIndex, float *Y, long YLastIndex, unsigned short Count, unsigned short Index);
typedef void (__stdcall *TStartTransform)();
typedef void (__stdcall *TCrvTransform)(float X);
typedef float (__stdcall *TGetTransform)();

void* DuplicateCurve(void *View,long Roof,long Sole);
void *DuplicateCurveEx(void *View, long Roof, long Sole, const char *MethodName, const char *UnitName);

/* Получить список группы в базе для заданной кривой */
void* GetWSGroup(void *Curve);
/* Получить список группы в планшете для заданной кривой */
void* GetPlanGroup(void *Curve);

long CrvTransform(OType DataHandle,OType ArrHandle,unsigned char Column, void *List,
 TStartTransform StartP,TCrvTransform DoP,TGetTransform GetP,PProcess Ind);

/* Получить данные стиля кривой по умолчанию */
LongBoolean GetDefaultTemplate(TViewCurveRec *Rec);
/* Выбор кода заливки по классу. "" = Все заливки, " " = Заливки без класса */
/* Выбор кода заливки по классу.
   FilClass:
     "" = Все заливки;
     " " = Заливки без класса
   lpFilName (результат):
     "" = Заливка не выбрана;
     Иначе - имя заливки */
long SelectFilName(const char *lpTitle, const char *lpPrompt, const char *lpFilClass, char *lpFilName, long nFilNameSize, long *lpnCode);
/* Выбор класса заливки.
   Результат:
     '' = Класс не выбран
     ' ' = Выбран пустой класс
     '*' = Выбраны все классы */
long SelectFilClassName(const char *lpTitle, const char *lpPrompt, char *lpClassName, long nClassNameSize);

long GetFillStyleCount(void *Plansheet);
LongBoolean GetFillStyleBitmap(void *Plansheet, const char *DeviceName,
  long DeviceDPIX, long DeviceDPIY, long RotateAngle, long DeviceFlags,
  long Number, COLORREF *Color, HBITMAP *Bmp, HPALETTE *Palette);
long GetFillStyleName(void *Plansheet, long Number,
  char *StyleName, long StyleNameLen);
long GetFillStyleClass(void *Plansheet, long Number,
  char *StyleClass, long StyleClassLen);
LongBoolean FindFillStyle(void *Plansheet, const char *StyleName, const char *StyleClass,
  long *Number);

/* Создание планшета по шаблону (.VPT иди .ST) и WS-файлу.
  Если lpTemplateFileName == "", то запрос у пользователя.
  Если lpTemplateFileName == " ", то из пустого шаблона.
  lpWSFileName не обязан существовать
 */
void* CreateNewPlansheet(const char *lpTemplateFileName, const char *lpWSFileName);

/* Перезагрузка конфигурационного(ых) файла(ов)
  ConfigType == cfgXXXX
  Flags && cfgmskMethod:
    cfgmtdFile - загрузка из файла (каталога), указанного параметром FileName
    с другими параметрами - пока не реализовано
  Результат:
    0 - нормальное завершение
    1 - хотя бы один из файлов не перезагружен */
long ReloadConfig(long ConfigType, long Flags, const char *lpFileName, OType hData);

/* Получить список открытых планшетов. Первый эл-т в списке - активный планшет */
void* GetSheetsList(void);
/* Получить список открытых окон. Первый эл-т в списке - активное окно */
void* GetSheetWindowsList(void);
/* Получить список планшетов, находящихся в окне Window */
void* GetSheetsByWindow(void *Window);
/* Получить окно по планшету, который в нём содержится */
void* GetWindowBySheet(void *Sheet);
/* Активизировать планшет */
LongBoolean ActivatePlansheet(void *Plansheet);

/* Получить тип и подтип поставки системы */
long GetBuildType(long *lpBuildSubType);
/* Получить информацию из ключа HASP */
LongBoolean GetHASPInfo(THaspInfo *lpInfo);

/* Функции для работы с условиями загрузки */

/* Применение фильтра к условиям загрузки */
LongBoolean ApplyConds(char *lpDestCondStr, long nDestCondStrSize,
  const char *lpSrcCondStr, const char *lpCurveName,
  TConflictFieldsAction *lpConflictAction);
/* Проверка, удовлетворяет ли данная кривая условиям загрузки и фильтру */
LongBoolean TestData(OType hObj, const char *lpAValueName, const char *lpAUnitName,
  const char *lpAnArrayName, const char *lpTestConds, const char *lpFilter,
  LongBoolean EmptyValid, OType *lphArr, long *lpColumn);
/* Возвращает множество номеров колонок, отфильтрованных последним вызовом TestData  */
LongBoolean GetLastTestDataColumns(TColumnsSet *lpColumns);

/* Выбор данных для кривой (возможно, интерактивный) по заданным
  условиям загрузки и фильтру */
long SelectCurveDataByFilter(void *lpTablesList, const char *lpCurveName,
  const char *lpFilter, char *lpAddFilter, long nAddFilterSize,
  OType *lphObj, OType *lphArr, long *lpColNumber, long *lpRowNumber, long Flags);

/* Получить режим выбора объектов. Пока используется только параметр
  lpdwFlags1, в него записываются биты, определяющие, разрешён ли выбор
  того или иного типа объектов мышью на планшете. Номер бита для каждого типа
  определяется константой wssi1XXXX, см. выше. Например,
  если ((*lpdwFlags1) & (1 << wssi1TowerLnGrid)) != 0, то можно выбирать
  логарифмические сетки, иначе - нет */
long GetSheetSelectMode(void *lpPlansheet,
       long *lpdwFlags0, long *lpdwFlags1, long *lpdwFlags2, long *lpdwFlags3,
       long *lpdwFlags4, long *lpdwFlags5, long *lpdwFlags6, long *lpdwFlags7,
       long *lpdwFlags8);
/* Установить режим выбора объетов. См. описание функции GetSheetSelectMode */
long SetSheetSelectMode(void *lpPlansheet,
       long dwFlags0, long dwFlags1, long dwFlags2, long dwFlags3,
       long dwFlags4, long dwFlags5, long dwFlags6, long dwFlags7,
       long dwFlags8);
void SetTopCaption(const char *lpCaption);

/* Получение/установка параметра ПРАЙМа по имени (список имён - см. константы ppnXXXX) */
long GetPrimeParam(const char *ParamName, void *lpBuffer, long cbBufSize);
long SetPrimeParam(const char *ParamName, void *lpBuffer, long cbBufSize);

/* Получение значений двумерной кривой по глубине и каналу (в физ.ед.)
  Если lpfBuffer == NULL, то возвращается число элементов в канале */
long GetTwoDValuesByDepth(void *TwoDCurve, long dwDepth,
       long nChannelIndex, float *lpfBuffer,
       long dwBufLenInFloats, LongBoolean *lplbValidRow);

/* Получение заголовка строки данных для последних данных, загруженных функцией
  GetTwoDValuesByDepth. Если lpBuffer == NULL, возвращается размер буфера */
long GetTwoDLastRowHeader(void *TwoDCurve, void *lpBuffer,
       long dwBufSize, long *lpdwBitIndex);
/* Получение заголовка канала данных для последних данных, загруженных функцией
  GetTwoDValuesByDepth. Если lpBuffer == NULL, возвращается размер буфера */
long GetTwoDLastChannelHeader(void *TwoDCurve, void *lpBuffer,
       long dwBufSize, long *lpdwBitIndex);

/* Получение заголовка файла данных.
  Если lpBuffer == NULL, возвращается размер буфера */
long GetTwoDHeader(void *TwoDCurve, void *lpBuffer, long dwBufSize);
/* Получение индекса глубин двумерной кривой */
LongBoolean GetTwoDDepthIndex(void *TwoDCrv, TPrimeDepthIndex *Index);

/* Добавление записи в список для функции SelectCurves_1 */
long AddCurveDataToList(void *CurvesList,
       const PTableCurveDataRec Data);
/* Получение записи из списка для функции SelectCurves_1 */
LongBoolean GetCurveDataFromList(void *CurvesList, long Index,
       PTableCurveDataRec Data);
/* Выбор кривых. Flags = 2: Вначале выбрать все кривые.
  CurvesList должен быть создан функцией InitUnsortList */
long SelectCurves_1(OType hWS, const char *TableName, long Flags,
       void *CurvesList);
/* Интерактивное указание значения кривой */
LongBoolean SelectCurveValue(void *Curve, float *Value, const char *Title);
/* Возвращает значение кривой по координатам: слева в 0.1 мм и глубина, см.
  Глубина нужна, т.к. по текущему значению кривой на этой глубине
  берётся номер сноса! */
double __stdcall TrackCurveValueFunc(void *Curve, long AStart, long ADepth);

/* Установить CALLBACK */
long SetPrimeCommonCallback(long dwEventType, // pevXXXX
       TPrimeCommonCallbackFunc lpFunc, void *dwCookie, long dwCallbackFlags,
       long dwPriority, void *lpObject, long dwObjectType,
       long dwObjectSubType, void *lpInput, long dwInputSize,
       const char *LibraryName, const char *FuncName);
/* Удалить CALLBACK */
LongBoolean DeletePrimeCallback(long dwHandle);
/* Проверка Handl'а CALLBACK'а */
LongBoolean IsPrimeCallback(long dwHandle);
/* Удалить все CALLBACKи или их подмножество */
LongBoolean DeletePrimeCallbacks(HINSTANCE H, long dwFlags);
/* Перетащить-и-бросить объект планшета на другой объект планшета */
LongBoolean PlanObjDragDrop(void *lpObjectToDrop, void *lpDropTemplate, long dwFlags, void *lpReserved);
/* Выполнить функцию из библиотеки, PRM, PRD, PRW, PRG или BAS-файла или
   встроенную функцию */
long PrimeExecuteFunction(const char *lpLibraryName, const char *lpFuncName,
       void *lpPlansheet, void *lpUser, void *lpReserved);

/* Получить стандартный код пласта колонки Tower с индексом Index.
  Flags = slcXXXX */
long GetStandardLayerCodeByIndex(void *Tower, long Index,
           char *Code, long CodeMaxLen, long Flags);
/* Установить стандартный код пласта колонки Tower с индексом Index.
  Flags = slcXXXX */
long SetStandardLayerCodeByIndex(void *Tower, long Index,
           const char *Code, long Flags);
/* Получить индекс пласта по глубине */
long GetLayerIndex(void *Tower, long Depth);

/* Получение текущих региона, площади и скважины */
long GetTarget(char *lpRegion, long nRegionLen, char *lpField, long nFieldLen,
           char *lpWell, long nWellLen, void *lpOtherData, long nOtherDataLen);
/* Изменение текущих региона, площади и скважины */
long SetTarget(const char *lpRegion, const char *lpField, const char *lpWell,
           LongBoolean lbCanCreate, void *lpOtherData, long nOtherDataLen);

char * __cdecl Prime_C_Translate(long Magic1, long Magic2, long Magic3, long Magic4, char *Str, char *StrID);

#define TRANSLATE(str) (Prime_C_Translate(0x524F5441, 0x4C534E41, 0x52545F45, 0x4D495250, (str), ""))
#define TRANSLATE2(str,strid) (Prime_C_Translate(0x524F5441, 0x4C534E41, 0x52545F45, 0x4D495250, (str), (strid)))

#ifdef _MSC_VER
  // Microsoft Visual C++
  #pragma pack( pop, ENTER_PRIMEAPI )
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

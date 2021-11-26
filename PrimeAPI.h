/***************************************************************************\
*                                                                           *
* ������� ��������������� ����������� ������������� ������������ �������    *
*   "�����" ��� Windows                                                     *
* ��������� � ����������� ��������������: ��������� � ���������             *
* ����: C++                                                                 *
* ������: 4.06.12                                                           *
* (C) ��� ������, 1999, 2007                                                *
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

/* ���� �������� �� �������� ������������ �������� WSType */
const long wsUnknown       = 0;   /* ��� �� ����������� �� ������ �� ������������� */
const long wsViewCurve     = 1;   /* ������ */
const long wsViewPoint     = 2;   /* �������� */
const long wsViewInter     = 3;   /* �������� */
const long wsViewNotes     = 4;   /* ������� */
const long wsViewTower     = 5;   /* ������ ������� */
const long wsTowerDepth    = 6;   /* ������� ������ */
const long wsTowerInter    = 7;   /* ����������� ������� */
const long wsTowerLnGrid   = 8;   /* �������� ����� */
const long wsTowerLgGrid   = 9;   /* ���������������� ����� */
const long wsTowerRvGrid   = 10;  /* �������� ����� */
const long wsViewScale     = 11;  /* ����� */
const long wsViewPicture   = 12;  /* ������� �� �������� */
const long wsViewTwoDCurve = 14;  /* 2-������ ������ */
const long wsInterReper    = 100; /* ����� */

#define NormalPut  0    /* ������� ������ ������  */
#define ANDPut     1    /* ���������              */
#define ORPut      2    /*       ����������       */
#define XORPut     3    /*               �������� */
#define TransPut   4    /* ���������������� ����� */


/* ������ �������� ��� �������������� ������������� � ��������� */
/* ��� ������ �������������� ������ ���������� � ������ ������� */

/*  0 - �������;
1 - ������;
2 - ��������;
3 - ������;
4 - ������;
5 - ������;
6 - ��������; */

#define tmDepthLine  0x0001 /* ������������ �������������� ����� */
#define tmStartLine  0x0002 /* ������������ ������������ ����� */
#define tmDepthLimit 0x0004 /* ��������� ����������� �� ������� */
#define tmStartLimit 0x0008 /* ��������� ����������� �� ����������� */
#define tmDrawCross  0x0010 /* �������� � ����� ������������ ������� */
#define tmDrawLine   0x0020 /* �������� �����  �� ��������� ����� �� ������� */
#define tmDrawBox    0x0040 /* �������� ������������� �� ��������� ����� �� ������� */
#define tmShowInfo   0x0080 /* �������� � ������ ������� ���������� � ������ ����� */
#define tmStartPoint 0x0100 /* ������ ������������ � ��������� ����� */
#define tmWidthLimit 0x0200 /* ����������� ��������� �������� ������ */
#define tmDeltaLimit 0x0400 /* ����������� ��������� �������� ��������� �� ������� */
#define tmDepthRange 0x0800 /* ������� �� ������ �������� �� ��������� �������� */
#define tmKeepMouse  0x1000 /* �� �������� ������� ���� */

/* ����� ������ �������� ������� */
#define lfShowLegend   0x00000001
#define lfShowName     0x00000002
#define lfEqualWidths  0x00000004

/* ����� � ���������� ����� ��� ������ ������ ����� ���������� ������� */
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

/* �������� �������� � ��������� � ������� ���������_��������� */
extern char *inPerfProekt;  /* 00 - ��������� ���������� ���������   */
extern char *inPerfFact;    /* 01 - ��������� ���������� ����������� */
extern char *inIntSostPrit; /* 02 - ��������� � ������� ��������     */
extern char *inPrinInter;   /* 03 - ����������� ���������            */
extern char *inMoveFluid;   /* 04 - ��������� �������� �������� �� ����������������� ������� */
extern char *inMPlPDown;    /* 05 - ��������� ������������ ��������� ������ */
extern char *inMPlPUp;      /* 06 - ��������� ������������ ��������� ����� */
extern char *inPeretDown;   /* 07 - ��������� ��������� � ������������� �������� ������ */
extern char *inPeretUp;     /* 08 - ��������� ��������� � ������������� �������� ����� */
extern char *inZKCDown;     /* 09 - ��������� ���������� ���������� ������ */
extern char *inZKCUp;       /* 10 - ��������� ���������� ���������� ����� */
extern char *inPatrubok;    /* 11 - ��������������� �������� � �������� ������� */
extern char *inFilterPaker; /* 12 - ��������������� ������� ������ */

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

/* ������ ��������� ��������� */
const long hmCurve         = 0;  /* �������������� ������ */
const long hmPoint         = 1;  /* �������������� ��������� */
const long hmInter         = 2;  /* �������������� ��������� */
const long hmTower         = 3;  /* �������������� ������� */
const long hmNotes         = 4;  /* �������������� ��������� */
const long hmFills         = 5;  /* �������������� ������� */
const long hmReper         = 6;  /* �������������� ����� */
const long hmScale         = 7;  /* �������������� ����� */
const long hmPlanPicture   = 8;  /* �������������� ������� �������� */
const long hmPlanTwoDCurve = 10; /* �������������� 2-������ ������ */

/* ������ ��������� ������� */
const long hmFrame  = 0; /* */
const long hmText   = 1; /* */
const long hmTable  = 2; /* */
const long hmBitmap = 3; /* */
const long hmLine   = 4; /* */

/* ������ ��������� �������� �������� */
#define psActivated 0x0001 /* ������ ������������� */
#define psHideTrace 0x0002 /* ������ ����������� ��� �������������� ����� */
#define psAltMouse  0x0004 /* ������ ������ ������� ������������ ���� ������ ���� */
#define psBackColor 0x0008 /* ������ �������� ������ ���� �������� */
#define fsActivated 0x0001 /* ����� �������������  */

/* ������ ��� ������ ������ */
#define cfBedDraw    0x0001 /* �������� ������ ��� ����������� ������     */
#define cfGridDraw   0x0002 /* ��������� ���������� �������               */
#define cfFloatDraw  0x0004 /* ��������� �������� �� ���� ("�����" ���� ) */
#define cfDrawLines  0x0008 /* ��������� ����� ������������� �������      */
#define cfDrawPixel  0x0010 /* ���������� ����� �������������             */
#define cfDrawHidden 0x0020 /* ���������� ������� �����                   */
#define cfDrawHeader 0x0040 /* ���������� ���������� ������� ��� ������   */
#define cfDrawBreakA 0x0080 /* ���������� �������� �� �������� �� ������� */
#define cfDrawBreakP 0x0100 /* ���������� �������� �� �������� �����      */
#define cfSmartBreak 0x0200 /* "��������" ��������� �������� �� ������    */
#define cfLogScale   0x0400 /* �������� ������ � ��������������� �������� */
#define cfDrawTicks  0x0800 /* ���������� �������� �� ������ */
#define cfHideMax    0x1000 /* ��������� ����� �������� ��������� */
#define cfAddUnit    0x8000 /* ��������� � ��������� �������� ������� ���.*/
#define cfKeepZero   0x4000 /* ��������� ���������� ���� */
#define cfHMirror    0x2000 /* �������� �� ����������� */

/* ������ ��������� ������������� �������� */
#define svSignNot 0 /* ������������ ��� ������������� �������� */
#define svSignNul 1 /* ������������ ��� ������� ��������       */
#define svSignAbs 2 /* ������������ ��� ������������� �������� */
#define svSignExl 3 /* ������������ ��� ������������� �������� */

/* ����� ��������� ��������� ����������� ������� */
const unsigned short itShowDepth        = 0x0001; /* �������� ������ */
const unsigned short itShowValue        = 0x0002; /* �������� ��������� */
const unsigned short itShowStrat        = 0x0004; /* �������� ������������ */
const unsigned short itShowLitol        = 0x0008; /* �������� ��������� */
const unsigned short itShowTrace        = 0x0010; /* �������������� ����� */
const unsigned short itHideHeader       = 0x0020; /* �� �������� �������� � ����� */
const unsigned short itPlastData        = 0x0040; /* ������ ������� - ����������� */
const unsigned short itFullSheetFiller  = 0x0080; /* �������� ������� �� ���� ������ �������� */
const unsigned short itUniteEqualPlasts = 0x0100; /* ���������� ���������� ������ */
const unsigned short itSourceTower      = 0x0200; /* �������� ������� (����� - ��������������) */

/* ��������� ������ �������� �� ������� ������������� */
#define mvNothing     0 /* �� ������������                     */
#define mvExclude     1 /* ��������� �� ������                 */
#define mvStrip       2 /* ������������ ��������               */
#define mvShift       3 /* ������� 1:1                         */
#define mvRescale2    4 /* ���� 1:2                            */
#define mvRescale5    5 /* ���� 1:5                            */
#define mvRescale10   6 /* ���� 1:10                           */
#define mvRescale100  7 /* ���� 1:100                          */
#define mvRescaleFree 8 /* ���� ��������� ������������         */

/* ��� ������������ �� ������ ���������� ������� */
#define avNothing   0  /* ��� ������ */
#define avTickUp    1  /* ����� ����� */
#define avTickDown  2  /* ����� ���� */
#define avTickFull  3  /* ���������� ����� */
#define avArrowOut  4  /* ������� ������ */
#define avArrowIn   5  /* ������� ������ */
#define avArrowFull 6  /* ������� � �������������� */

#define CurveLevelsNum 10
#define CurveDepthsNum 10

/* ����������� ������ ������ */
const long cfeDrawNewPoints = 0x00000001;         /* ���������� ������ �� ������ */
const long cfeDisablePointsInHeader = 0x00000002; /* �� �������� ������ �� ������� */
const long cfeDrawNewDepthValues = 0x00000004;    /* ���������� �������� �� �������� � ����� */
const long cfeNewDepthOnRoofAndSole = 0x00000008; /* ���������� �������� �� ������ � ������� ������ */
const long cfeNewDepthStepInQuants = 0x00000010;  /* ��� �������� ������� � ������ ������������� (����� - � c�. ��������) */
const long cfeBreakNumber = 0x00000020;           /* ���������� ����� ����� ������ �������� */
const long cfeValuesOnAllTicks = 0x00000040;      /* ���������� �������� �� ���� ������ */
const long cfeResultCurve = 0x00000080;           /* �������������� ������ (�� ��� WSGetData!) */
const long cfeResultCurve_Get = 0x00000100;       /* �������������� ������ (������ ��� WSGetData!) */
const long cfeAutoMin = 0x00000200;               /* �������������� ������ �������� �� "0" */
const long cfeAutoScale = 0x00000400;             /* �������������� ������ �������� */
const long cfeDepthValuesNoArrow = 0x00000800;    /* �� �������� ������� ��� �������� �� �������� */
const long cfeDepthValuesCenterBed = 0x00001000;  /* ��� ����������� ������ �������� �������� ���������� ������ */
const long cfeNewLineStyle = 0x00002000;          /* ����� ����� ������ ������������ ������ ����������� */
const long cfeRValueDeterminesScale = 0x00004000; /* ������� ������������ ������ ��������� */
const long cfeDisableGridWarning = 0x00008000;    /* �� �������� ��� �������������� � ������ */
const long cfeMinimalHeaderHeight = 0x00010000;   /* �� ����������� ��������� ������ ������� �� ������ */
const long cfeSumMode = 0x00020000;               /* ����� ������������ ��� ��������� */
const long cfeUnitOnLineWithMethod = 0x00040000;  /* �������� ������� ��������� �� ����� ������ � ������� */
const long cfeDrawNailsOnPoints = 0x00080000;     /* ���������� "��������" �� ������� �� ������� ����� */
const long cfeBreakColors = 0x00100000;           /* �������� ������ ������ ������ ������� */

/* ���� ������� �� ������ */
const unsigned char cptNone          = 0; /* ��� ������ */
const unsigned char cptPixel         = 1; /* 1 ������ */
const unsigned char cptEmptyCircle   = 2; /* ���������� */
const unsigned char cptEmptySquare   = 3; /* ������� �������� */
const unsigned char cptEmptyTriangle = 4; /* ����� ������������ */
const unsigned char cptCircle        = 5; /* ���� */
const unsigned char cptSquare        = 6; /* ������� */
const unsigned char cptTriangle      = 7; /* ����������� */
const unsigned char cptStar          = 8; /* �������� */
const unsigned char cptRect2x1       = 9; /* ������������� � ����������� 2x1 */
const unsigned char cptRect4x1       = 10; /* ������������� � ����������� 4x1 */
const unsigned char cptRect8x1       = 11; /* ������������� � ����������� 8x1 */

typedef unsigned char TNailWidthMode; /* ����� ������ "������" (��� �������) */

const TNailWidthMode nwmQuarterPointSize = 0;
const TNailWidthMode nwmLineWidth = 0;
const TNailWidthMode nwmArbitrary = 0;

typedef unsigned char TVectorLengthMode; /* ����� ����� ������� */

const TVectorLengthMode vlmPointSize = 0;
const TVectorLengthMode vlmFiveTimesLineWidth = 1;
const TVectorLengthMode vlmArbitrary = 2;

typedef unsigned char TVectorAngleUnit; /* ������� ��������� ���� ������� */
const TVectorAngleUnit vauUnknown = 0;  // ����������
const TVectorAngleUnit vauDegrees = 1;  // �������
const TVectorAngleUnit vauRadians = 2;  // �������
const TVectorAngleUnit vauGrads   = 3;  // ����� (360 �������� = 400 ����)
const TVectorAngleUnit vauParts   = 4;  // ����� ���������� (1 ����� = 360 ��������)

typedef unsigned char TVectorStartAngle; /* ����� ������� ����� (������������ ����������� - 0 �������� ������, ������ ������� �������) */
const TVectorStartAngle vsa0   = 0;
const TVectorStartAngle vsa90  = 1;
const TVectorStartAngle vsa180 = 2;
const TVectorStartAngle vsa270 = 3;

/* ����� ������-������ (���� VectorFlags ������ TViewCurveRec) */
const long vcfInvertAngle       = 0x00000001; // ������ ����� ����������� �� ������� �������
const long vcfIndividualColor   = 0x00000002; // ������� ������� ����� ��������
const long vcfIndividualBGColor = 0x00000004; // ������� ������� ����� �������

/* ���� ���������� ������� */
const unsigned short htStandard      = 0; /* ������� */
const unsigned short htAmplitude     = 1; /* ������ ��������� */

/* ������������ �������� ������������ ������ */
const unsigned char dvpAuto  = 0;
const unsigned char dvpRight = 1;
const unsigned char dvpLeft  = 2;

typedef unsigned char TCurveLineStyleIndex;
const TCurveLineStyleIndex clsiDisplay = 0;
const TCurveLineStyleIndex clsiMono    = 1;
const TCurveLineStyleIndex clsiColor   = 2;

/* ����� ������ ����� ����� ������ */
const unsigned char lsfUseMonoStyle  = 0x01; /* ����� ����� ��� ����������� ��������� */
const unsigned char lsfUseColorStyle = 0x02; /* ����� ����� ��� ������� ��������� */

const long nfOpaque = 0x00000001; /* ������������ ��� ������� */

/* ����� �������� */
const long psfAutoRoof              = 0x00000001; /* �������������� ������ ������ */
const long psfAutoSole              = 0x00000002; /* �������������� ������ ������� */
const long psfAutoWidth             = 0x00000004; /* �������������� ������ ������ */
const long psfUseDepth              = 0x00000008; /* ������������ ������� ������� */
const long psfNoHeaderFrame         = 0x00000010; /* �� �������� ����� ������ �����/������� */
const long psfAutoDistributeLegends = 0x00000020; /* ��� �������� ������������� ������������ �������� ������� �� ������� */
const long psfAutoPlaceLegends      = 0x00000040; /* ��� �������� ������������� ��������� �������� ������� */
const long psfAutoReloadOnCreate    = 0x00000080; /* ��� �������� �� ������� ������������� ��������� ������ ������/������� */
const long psfArchiveMode           = 0x00000100; /* �������� ������� */
const long psfAutoScaleWidth        = 0x00000200; /* ��� ��������� ������� ������ �������������� �� ������ ���� */

/* ����� SetStandardLayerCodeByIndex, GetStandardLayerCodeByIndex */
const long slcMarkMissing = 0x00000001; /* ��� ���������� ��������� ��������� ������� ���� "+" */

/* ==== ����� ���� ������ ��� ������ ����� WSGetData � WSSetData ========= */
/* ==== ��� �������� �������� � 0.1��                                 ==== */
/* ==== ��� �������� ������ � �����������                             ==== */
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

/* ������ ��� ������ */
typedef struct {
	//unsigned char CurveInfoLength;
	PasString CurveInfo; /* �������� ���������� � ������ (�� ����������) */
    /* ��������� ����������� ������ ������ */
	unsigned short Curve;       /* ����� ������ (��.���� WSIGF.CRV) */
	long Start;    /* ������ ������� ���������� ������ */
	long Width;    /* ������ ������� ���������� ������ */
	float Minimum;   /* �������� ������ �� ����� ������� */
	float Scale;     /* ������� ������ (���.��.�� 1 ��.) */
	long Modul;    /* ������ ���������������� �������� */
	float Power;     /* ��������� ��������.��������      */
	unsigned short Flags;       /* ������ ��������� ������ (cfXXXX) */
	unsigned short MHIndex;     /* ��������� ������ (mvXXXX)        */
	unsigned short MHValue;     /* �������� �������.�����.��������. */
	unsigned short SHIndex;     /* ��������� ������������� (svXXXX) */
	//unsigned char ValueNameLength;
	PasString ValueName; /* �������� ������ ������ ������    */
	//unsigned char ValueUnitLength;
	PasString ValueUnit; /* �������� ������� ���������       */
    /* ��������� ����������� ���������� ������� */
	unsigned short HeaderType;  /* ��� ���������� �������: 0 - �������, 1-������ (htXXXX) */
	unsigned short ValueJust;     /* ������������ �������� �� ���������� ������� */
	long ValueIndent;      /* ������ �������� �� ���������� ������� */
	//unsigned char ValueFontLength;
	PasString ValueFont;                     /* ����� ��� ������ �������� */
	long ValueSize;            /* ������ ������ ��� ������ �������� */
	unsigned char ValueZero;  /* ����� ������ ����� ������� ��� ������ �������� */
	//unsigned char Length;
	PasString NameFont;               /* ����� ��� ������ �������� ������ */
	long NameSize;      /* ������ ������ ��� ������ �������� ������ */
	unsigned short ValueKeep;                       /* ��������� ���������� ���� */
	//unsigned char Length;
	PasString UnitFont;             /* ����� ��� ������ ������� ��������� */
	long UnitSize;    /* ������ ������ ��� ������ ������� ��������� */
	long ValueAdds;     /* ����� �������������� �������� �� ������� */
    /* ���� � ������� ������� �� ������ ���������� ������� */
	unsigned short LeftArrow;                /* ...��� ������ ����� */
	unsigned short RightArrow;              /* ...��� ������ ������ */
	long ArrowSize;              /* ...������� ������� */
    /* ������� ��������� */
	long InterLine;  /* ����� �������� � �������� ������ ��� ��.���.*/
	long SkipBefore;                   /* ����� ���������� �������� */
	long SkipAfter;                     /* ����� ���������� ������� */

    /* ��������� ������ �������� �� �������� */
	string64 BreakFont; /* �������� ������ ��� ������ */
    /* ��������� ������ �������� �� �������� */
	string64 DepthFont;      /* ����� ������ �������� �� �������� */
	long DepthSize;          /* ������� ������ ��� ������ */
	unsigned char DepthZero; /* ����� ������ ����� ������� */
	char Reserved3[108]; /* ��� ��� ���������� ����������� */
    /* ��������� ������ �������� �� �������� - ����������� */
        unsigned char BreakColorCount; /* ����� ��������� ������ ��� ������ ������� ������� */
        struct { unsigned char R; unsigned char G; unsigned char B; } BreakColors[4]; /* ����� ��� ������ ������� ������� */
    /* ��������� ������ �������� �� �������� - ����������� */
	long BreakSize; /* ������� ������ ��� ������ */
	unsigned char BreakZero;    /* ����� ������ ����� ������� */
    /* ...��������� �� ��������� */
	unsigned short BreakVertAfter;     /* ������������ ����� ������� */
	unsigned short BreakVertBelow;     /* ������������ �� ������� */
	long BreakVertIndent; /* ������ �� ����� ������� */
    /* ...��������� �� ����������� */
	unsigned short BreakHorizAfter;  /* ---- ||| ---- */
	unsigned short BreakHorizBelow;  /* ---- ||| ---- */
	short BreakHorizIndent; /* ---- ||| ---- */
    /* ����� �������� �� ����� ������ */
	unsigned short HeaderManual;     /* �������� ��������������� ������� */
	float HeaderLeftVal;  /* �������� ����� */
	float HeaderRightVal; /* �������� ������ */

    /* ������ ����������� � ������ ������ */
	short LevelMask; /* ����� ����� ������ ��������, � ����� ��� */
	float Level[CurveLevelsNum];
    /* ������ ����������� � ��������� �� ������� */
	long DepthMask; /* ����� �������� �� �������, � ����� ��� */
	long Depth[CurveDepthsNum];
	unsigned short AddUnit; /* ��������� � �������� �������� ������� */

    /* ������, ����������� �������� ������ � ������� �� WS ����� */
	OType DataHandle; /* ��������� ������ ������� */
	unsigned short RowNumber;  /* ����� ���� ������ � ������� */
	OType ArrayHandle; /* ��������� ������� � ������� ������ */
	unsigned short ColNumber;  /* ����� ������� � ������� */
	//unsigned char Length;
	PasString ArrayName;  /* �������� ������� */
	//unsigned char Length;
	PasString TableName;  /* �������� ������� */
        /* ������ � ���, ������ ���� ������� ������ */
        string64 ResFile;
        string64 ResName;
        PasString ValueCode; /* ��� ������ ��� */
        string64 UnitCode; /* ��� ������� ��������� */
        unsigned char NewLineStyleFlags; /* lsfXXXX */
        TCurveLineStyle NewLineStyles[3];
        long EFlags; /* ��. cfeXXXX */
        unsigned char PointType; /* ��� ������ �� ������ (��. cptXXXX) */
        long PointSize; /* ������ ������ � 0.1 �� */
        short PointFreq; /* �������. ���� > 0, �� � ��/������, ����� - � ������ �����./������ */
        long NewDepthValuesAnchor; /* ��������� �������, �� (���� ��������� ����� �������������) */
        long NewDepthValuesStep; /* ���, �� (���� ����� �����.) */
        unsigned char NewDepthsValuesPos;
        float RightValue; /* �������� ������ �� ������ ������� (���� � EFlags ����� ���� cfeRValueDeterminesScale) */
        void *PrevSumCurve; /* ���������� ����������� ������ (���� � EFlags ����� ���� cfeSumMode) */
        TNailWidthMode NailWidthMode; /* ����� ������� "�������" */
        unsigned char NailWidth; /* ������� "�������", 0.1 �� */
        void *LeadDepthColObject; /* ������ � ������� �������� ������ */
        /* ������ ��� ������-������ - ������ */
        TNailWidthMode VectorWidthMode; /* ����� ������� ������� */
        unsigned char VectorWidth; /* ������� �������, 0.1 �� */
        TVectorLengthMode VectorLengthMode; /* ����� ����� ������� */
        unsigned short VectorLength; /* ����� �������, 0.1 �� */
        TVectorAngleUnit VectorAngleUnit; /* ��. ���. ���� ������� */
        long VectorColNumber; /* ����� ������� ������ ���� ������� */
        long CurvePointAnotherColor; /* ������ ���� ������� �������� ��� 0x1FFFFFFF */
        long InnerCurvePointColor; /* ���� ������� ������ �������� ��� 0x1FFFFFFF */
        long CurvePointEdgeWidth; /* ������� ������� �������� � 0.1 �� ��� 0 */

        long VectorFlags; /* ����� ��������, vcfXXXX */
        long VectorColorColNumber; /* ����� ������� ������ � ������ ������� */
        long VectorBGColorColNumber; /* ����� ������� ������ � ������ ������� */
        TVectorStartAngle VectorStartAngle; /* ������ ������� ����� */
        /* ������ ��� ������-������ - ����� */
        char Reserved[64];
} TViewCurveRec, *PViewCurveRec;

/* ������ ��� ���������� */
typedef struct {
    long Start;    /* ������� ��� ��������� ��������� */
    long Width;    /* ������� ��������� */
    long Color;    /* ���� ��������� */
    long Depth;    /* ������� ��������� */
    OType ArrHandle;  /* ��������� ������� � ������ ���������� */
	//unsigned char Length;
    PasString ArrayName; /* �������� ������� � ������ ���������� */
    long ArrayRow; /* ����� ������ ��� ������� ��������� � ������� */
    char Reserved[32];
} TViewPointRec, *PViewPointRec;

/* ������ ��� ���������� */
typedef struct {
    long Start;      /* ������� ��� ��������� ��������� */
    long Width;      /* ������� ��������� */
    long Color;      /* ���� ��������� */
    long Roof, Sole; /* ������ � ������� ��������� */
    OType ArrHandle;    /* ��������� ������� � ������ ���������� */
	//unsigned char Length;
    PasString ArrayName;   /* �������� ������� � ������ ���������� */
    long ArrayRow;   /* ����� ������ ��� ������� ��������� � ������� */
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

/* ������ ��� �������� */
typedef struct {
    long Start;  /* ������� ���������� ������� */
    long Depth;  /* ������� ���������� ������� */
    unsigned short Color;     /* ���� ������ ������� */
    long Length; /* ����� ������������� */
	//unsigned char Length;
    PasString Font;   /* ����� ��� ������ ������� */
    long Size;  /* ������ ������ ��� ������ ������� */
    long Line;  /* ���������� ����� �������� ������� */
    unsigned short HJust; /* ��� ������������ �� ����������� (0-�����, 1-�� ������, 2-������)*/
    unsigned short VJust; /* ��� ������������ �� ��������� (0-�������, 1-�� ������, 2-������*/
    unsigned short Under;  /* ������������� ������ ������ */
    unsigned short Direct; /* ����������� ������ �������
      (0-����� �������, 1-����� �����, 2-������ ������, 3-������ ����)*/
    char *Text; /* ����� ������� */
    long Flags; /* nfXXXX */
    long BackColor; /* ���� ���� */
    void *Parent; /* ��������� ������� */
    char Reserved[24];
} TViewNotesRec, *PViewNotesRec;

/* ������ ��� ������ ������� */
typedef struct {
    long Start; /* ������ ������� */
    long Width; /* ������ ������� */
    unsigned short Color;    /* ���� ������� */
	//unsigned char Length;
    PasString TowerName;   /* �������� ������� */
    /* ��������� ���� ��������� ��� ���� ����� ������� */
    //unsigned char Length;
    PasString NameFont;   /* ����� ��� ������ �������� ������� */
    long NameSize;  /* ������ ������ ��� ������ �������� ������� */
    long NameJust;  /* ��� ������������ �������� ������� (��.TViewNotesRec.HJust) */
    long NameDirect; /* ����������� ������ �������� ������� (��.TViewNotesRec.Direct) */
    long NameBefore; /* ������� �� �������� ������� */
    long NameAfter; /* ������� ����� �������� ������� */
    long NameInter; /* ������� ����� �������� � �������� ������� */
    char Reserved[32];
} TViewTowerRec, *PViewTowerRec;

/* ������ ��� ������� ������ */
typedef struct {
    long Start;     /* ��.TViewTowerRec */
    long Width;     /* ��.TViewTowerRec */
    unsigned short Color;        /* ��.TViewTowerRec */
    //unsigned char Length;
    PasString TowerName;  /* ��.TViewTowerRec */
    long TickStep;  /* ��� ������ ����� �� ���������� ������ */
    unsigned short TextPlace;    /* ��������� �������� ������ ������������ ����� */
    unsigned short AbsDepth;     /* �������� ���������� ������� */
	//unsigned char Length;
    PasString FontName;   /* ����� ��� ������ �������� ������ */
    long FontSize;  /* ������ ������ ��� ������ �������� ������ */
    unsigned short TextJust;     /* ������������ �������� ������ */
	//unsigned char Length;
    PasString AbsFont;    /* ����� ��� ������ �������� ���������� ������ */
    unsigned char AbsZero;      /* �������� ������ ���������� ������ */
    long AbsSize;   /* ������ ������ ��� ������ �������� ���������� ������ */
    unsigned short AbsJust;      /* ������������ �������� ���������� ������ */
	//unsigned char Length;
    PasString AbsInfo;    /**/
    /* ��.TViewTowerRec */
	//unsigned char Length;
    PasString NameFont;
    long NameSize;
    long NameJust;
    long NameDirect;
    long NameBefore;
    long NameAfter;
    long NameInter;
    /* ��.TViewCurveRec */
    unsigned short RowNumber;
    unsigned char ColNumber;
	//unsigned char Length;
    PasString TableName;
	//unsigned char Length;
    PasString ArrayName;
    OType DataHandle;
    OType ArrayHandle;
    /* ������ � ���, ������ ������� ������ ���. ������ */
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
    /* ���. ��������� ��� ������ ��������� �� ������� */
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

/* ������� ������� */
#define wslpDefault 0
#define wslpLegend  1
#define wslpHeader  2

/* ������ ��� ����������� ������� */
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
    /* �������� � ���, ������ ������� ������ ������� */
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
    long Start;     /* ��.TViewTowerRec */
    long Width;     /* ��.TViewTowerRec */
    unsigned short Color;        /* ��.TViewTowerRec */
	//unsigned char Length;
    PasString TowerName;      /* ��.TViewTowerRec */
    long TickStep;     /* ��� ������ ����� �� ������� */
    unsigned short TickFreq;        /* ������� ������� ����� �� ������� */
    unsigned char TickPattern;      /* ������� ������ ����� �� ������� */
    /* ���� ����� ��� ����� �� ����������� */
    long GridStep;
    unsigned short GridFreq;
    unsigned char GridPattern;
    /* ��.TViewTowerRec */
	//unsigned char Length;
    PasString NameFont;
    long NameSize;
    long NameJust;
    long NameDirect;
    long NameBefore;
    long NameAfter;
    long NameInter;
    long Flags;
    /* ���. ��������� ��� ������ ��������� �� ������� */
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
    long Start;     /* ��.TViewTowerRec */
    long Width;     /* ��.TViewTowerRec */
    unsigned short Color;        /* ��.TViewTowerRec */
	//unsigned char Length;
    PasString TowerName;      /* ��.TViewTowerRec */
    long TickStep;     /* ��� ������ ����� �� ������� */
    unsigned short TickFreq;        /* ������� ������� ����� �� ������� */
    unsigned char TickPattern;      /* ������� ������ ����� �� ������� */
    long GridModul;     /* ������ ��������������� ����� */
    float GridStart;      /* ��������� �������� ��������������� ����� */
    float GridPower;      /* ��������� ��������������� ����� */
    unsigned char GridPattern;      /* ������� ��������������� ����� */
    /* ��.TViewTowerRec */
	//unsigned char Length;
    PasString NameFont;
    long NameSize;
    long NameJust;
    long NameDirect;
    long NameBefore;
    long NameAfter;
    long NameInter;
    long Flags;
    /* ���. ��������� ��� ������ ��������� �� ������� */
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

/* ����� ����������� ������� */
const int fcLeftStrip     = 1; /* ������� ����� */
const int fcRightStrip    = 2; /* ������� ������ */
const int fcInterStrip    = 4; /* ������� ������ � ����� */
const int fcDisableHeader = 8; /* �� ���������� ������� */

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
    unsigned short Flags; // ��. ��������� fcXXXX

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

/* ����� ������ ���� */
const int vsValueTicks = 1; /* ������� */
const int vsCurveTicks = 2; /* �� ������ */
const int vsSmallTicks = 4; /* �������� */

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

/* ���� ����������� ������ */
typedef unsigned char TBitmapDataType;
const TBitmapDataType bdtUnknown = 0; /* ����������� */
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

/* ����� ������ � CreateWSChord */
const unsigned short icShowTrace = 1; /* ���������� ����� ����������� */
const unsigned short icShowChord = 2; /* ���������� ����� ����������� ����� */
const unsigned short icConstInter = 4; /* ��� ��������� ������� ����� ����������� ����������� ��� ������� */
const unsigned short icShowFiller = 8; /* ���������� ������� */
const unsigned short icIsTraceColor = 16; /* �������� ���� ������, ��������� � PEN-����� */
extern char *SUserCreatedReper; /* �����, ��������� ������� */
/* ���� ������� (���� ReperType ������ TWSInterReperRec) */
const unsigned short rtChord = 0; /* �������� �������� */
const unsigned short rtHandleInter = 1; /* �������� ��������� */

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

/* ����� ������ ����������� ������� ��������  */
const long plpOpaque     = 0x00000001; /* ������������ */
const long plpLinkDepths = 0x00000002; /* �������� � �������� */

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

/* ��������� ������ */

const long MaxChannels = 16384; /* ����. ���-�� ������� � ������ */
const long MaxColorTransformEntries = 16384; /* ����. ���-�� ��������� ������� ������ */
const long CurrentTwoDHdrVersion = 0; /* ������� ������ ��������� ������� ������ */
const long CurrentTwoDTransVersion = 0; /* ������� ������ ��������� ������� �������������� � ���� */

/* ����� ������� */
const long tdhfDataPresent    = 0x00000001; /* lpData ��������� �� �������� ������ */
const long tdhfAddInfoPresent = 0x00000002; /* lpAddInfo ��������� �� �������� ������ */
const long tdhfSignedData     = 0x00000004; /* ������ - �� ������ */
const long tdhfDepthsPresent  = 0x00000008; /* � ������ ������ ������� ������� */
const long tdhfRevByteOrder   = 0x00000010; /* ����� ���� � �������� ������� */
const long tdhfRevBitOrder    = 0x00000020; /* ���� ���� � �������� ������� */
const long tdhfRevRowOrder    = 0x00000040; /* ������ ���� �� ������� � ������ */

/* ������ �������� */
typedef unsigned char TTwoDValueFormat;
const TTwoDValueFormat tdvfUnknown = 0; /* ����������� */
const TTwoDValueFormat tdvfDefault = 1; /* �� ��������� (����� �����) */

/* ������ ������ � ������ */
typedef unsigned char TTwoDDepthFormat;
const TTwoDDepthFormat tddfUnknown = 0; /* ����������� */
const TTwoDDepthFormat tddfFloatM  = 1; /* 4-�������� ���., � ������ */
const TTwoDDepthFormat tddfLongCm  = 2; /* 4-�������� ����� �� ������, � ����������� */

/* ��������� ������� ������ */
typedef struct {
    long dwSize;                        /* 000 ������ ���� ���������               */
    long dwVersion;                     /* 004 ������ ���� ���������               */
    long dwFlags1;                      /* 008 ��. tdhfXXXX                        */
    unsigned long dwDataSize;           /* 012 ������ ������                       */
    long dwDataSizeHigh;                /* 016 ���� �� ������������                */
    TTwoDValueFormat bDataFormat;       /* 020 ������ ������                       */
    TTwoDDepthFormat bDepthFormat;      /* 021 ������ ������ ������� (���� ����)   */
    unsigned char cbitDataLength;       /* 022 ����� ��� � �������� ������         */
    unsigned char cbitDataGap;          /* 023 ����� ��� ����� �������             */
    unsigned short cbitChannelHeader;   /* 024 ����� ��� � ��������� ������        */
    unsigned short cbitChannelGap;      /* 026 ����� ��� ����� ��������            */
    unsigned long cbitRowHeader;        /* 028 ����� ��� � ��������� ������        */
                                        /*     (�������, ��������, �������)        */
    unsigned long cbitRowGap;           /* 032 ����� ��� ����� ��������            */
    unsigned long nDataInChannel;       /* 036 ����� ��������� ������ � ������     */
    unsigned long nChannels;            /* 040 ����� ������� � ������              */
    unsigned long nDataRows;            /* 044 ����� ����� ������                  */
    unsigned long dwAddInfoSize;        /* 048 ������ ���. ����� ����������        */
    void *lpData;                       /* 052 ������ �� ������ (����� �� ����)    */
    void *lpAddInfo;                    /* 056 ������ �� ���. ����������           */
    unsigned long cbitDepthOffsetInRow; /* 060 �������� � ����� ������ �������     */

    unsigned char acReserved[192];    /* ��������������� */
} TTwoDCurveDataHeader, *PTwoDCurveDataHeader; // 256 ����

/* ������� ������� "�������� => ����" */
typedef struct {
    unsigned long dwDataValue;  /* �������� */
    unsigned long dwColorValue; /* ���� */
} TPointToColorItem;

/* ������� ������� "�������� �������� => ����" */
typedef struct {
    unsigned long dwDataMinValue; /* ����������� �������� */
    unsigned long dwDataMaxValue; /* ������������ �������� */
    unsigned long dwColorValue;   /* ���� */
} TInterToColorItem;

/* ������� "�������� => ����" */
typedef struct {
    long dwSize; /* ������ ������� */
    long Count;  /* ���-�� ��������� */
    TPointToColorItem Items[0x7FFFFFFF / sizeof(TPointToColorItem) - 2 * sizeof(long)];
                 /* �������� */
} *PPointToColorArray;

/* ������� "�������� �������� => ����" */
typedef struct {
    long dwSize; /* ������ ������� */
    long Count;  /* ���-�� ��������� */
    TInterToColorItem Items[0x7FFFFFFF / sizeof(TInterToColorItem) - 2 * sizeof(long)];
                 /* �������� */
} *PInterToColorArray;

/* ������� "�������" */
typedef struct {
    long dwSize;              /* ������ ������� */
    unsigned long StartValue; /* ��������� �������� */
    unsigned long EndValue;   /* �������� �������� */
    unsigned long StepValue;  /* ��� �������� */
    unsigned long Items[0x7FFFFFFF / sizeof(unsigned long) - 4 * sizeof(long)];
                              /* �������� (����� �������) */
} *PColorPaletteArray;

/* ������ ����� */
typedef unsigned char TTwoDColorFormat;
const TTwoDColorFormat tdcfUnknown    =  0; /* ����������� */
const TTwoDColorFormat tdcf1bit       =  1; /* ����������� */
const TTwoDColorFormat tdcf4bit       =  2; /* 16 ������ */
const TTwoDColorFormat tdcf8bit       =  3; /* 256 ������ (������� �����) */
const TTwoDColorFormat tdcf16bit      =  4; /* High Color */
const TTwoDColorFormat tdcf24bit      =  5; /* True Color */
const TTwoDColorFormat tdcf32bit      =  6; /* True Color (32 ����) */
const TTwoDColorFormat tdcf4bitNoRev  =  7; /* 16 ������, ������ ������� ��� */
const TTwoDColorFormat tdcf16bitNoRev =  8; /* High Color, ������ ������� ���� */
const TTwoDColorFormat tdcf24bitNoRev =  9; /* True Color, ������ ������� ���� */
const TTwoDColorFormat tdcf32bitNoRev = 10; /* True Color (32 ����, ������ ������� ����) */

/* ��� ������� �������������� � ���� */
typedef unsigned char TTwoDColorTransformMode;
const TTwoDColorTransformMode tdctUnknown       = 0; /* ����������� */
const TTwoDColorTransformMode tdctOneToOne      = 1; /* ��� �������������� */
const TTwoDColorTransformMode tdctPointToColor  = 2; /* "�������� => ����" */
const TTwoDColorTransformMode tdctInterToColor  = 3; /* "�������� �������� => ����" */
const TTwoDColorTransformMode tdctColorPalette  = 4; /* "�������" */

/* ����� ������������ ����� */
typedef unsigned char TTwoDColorInterpolationMode;
const TTwoDColorInterpolationMode tdciUnknown  = 0; /* ����������� */
const TTwoDColorInterpolationMode tdciConstant = 1; /* �������-���������� (���� ��� �������� ��������) */
const TTwoDColorInterpolationMode tdciLinear   = 2; /* �������� (������� �������) */

/* ��������� ������� �������������� � ���� */
typedef struct {
    long dwSize;                             /* ������ ���� ��������� */
    long dwVersion;                          /* ������ ���� ��������� */
    long dwFlags1;                           /* ����� (���� �� ������������) */
    TTwoDColorFormat bColorFormat;           /* ������ ����� (tdcfXXXX) */
    TTwoDColorTransformMode bMode;           /* ��� ������� �������������� � ���� (tdctXXXX) */
    TTwoDColorInterpolationMode bInterpMode; /* ����� ������������ ����� (tdciXXXX) */
    unsigned char bReserved1;                /* ��������������� */
    unsigned long dwEmptyColor;              /* ���� �� ��������� (� ������� bColorFormat, */
                                             /* �� ������ � ������ �������� ��� � ����) */
    void *lpTransformArray;                  /* ��������� �� ������� �������������� � ���� */
    unsigned char acReserved[40];            /* ��������������� */
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

/* ����� ������ ����������� ��������� ������ */
const long p2dfInverseColor     = 0x00000001; /* ������������� ���� ������������ ����������� */
const long p2dfDrawColorMap     = 0x00000002; /* �������� �������� ����� */
const long p2dfDrawHeader       = 0x00000004; /* �������� ���������� ������� */
const long p2dfDrawHeaderName   = 0x00000008; /* �������� �������� � ������� */
const long p2dfDrawHeaderValues = 0x00000010; /* �������� ����� � �������� � ������� */
const long p2dfDrawHorizCurves  = 0x00000020; /* �������� �����. ������ */
const long p2dfPointStepInRows  = 0x00000040; /* ��. ���. ���� - ������ ������ (����� - ��. ��������) */
const long p2dfFormatOverride   = 0x00000080; /* ������ ��� WSSetData - ���� DataFormat
                                                 ���������� �� ������ ������ ������, �� �
                                                 ��������� ������������, ���������������
                                                 ������ �������� */
const long p2dfReserved1        = 0x00000100;
const long p2dfStretchArgRange  = 0x00000200; /* ����������� ������� ������������� ���������
                                                 �� ��� ������ ������� */
const long p2dfAutoLegend       = 0x00000400; /* �������� ������� ������������� ������
                                                 �� ������� ������ */
const long p2dfNoAutoSetFormat  = 0x00000800; /* ������ ��������� ������������� ������������ ������� */
const long p2dfUseSondeFormula  = 0x00001000; /* ������������ ������� ����� */

/* ��������� �������������� �������� ��� ��������� ������ */
const unsigned short p2dbfNone          =     0;
const unsigned short p2dbfARMG50        = 0x0001; /* ���� 5.0 */
const unsigned short p2dbfWPI           = 0x0002; /* WPI (�. ��������, ��� "���������") */
const unsigned short p2dbfUSBA          = 0x0003; /* ���� */
const unsigned short p2dbfVAK_NTU       = 0x0004; /* ���� ��� ���� */
const unsigned short p2dbfTAP           = 0x0005; /* TAP (���-��� � ����) */
const unsigned short p2dbfGEKTOR        = 0x0006; /* ����������� ������ */
const unsigned short p2dbfWAC           = 0x0007; /* WAC (��� �� ���� ����) - ���� �� �������������� */
const unsigned short p2dbfSEG_D         = 0x0008; /* �������� - SEG_D (���-3, SDS) */
const unsigned short p2dbfCST           = 0x0009; /* �������� - CST (������������ � ������� GEOVECTEUR) - ���� �� �������������� */
const unsigned short p2dbfSEG_Y         = 0x000A; /* �������� - SEG_Y - ���� �� �������������� */
const unsigned short p2dbfGEKTORWAT     = 0x000B; /* ���������� ������������ ��������� (������) */
const unsigned short p2dbfUMN           = 0x000C; /* �������� ������� � ������� *.umn */
const unsigned short p2dbfWSBLOB        = 0x000D; /* ������ �� WS-����� � BLOB�� */
const unsigned short p2dbfOGFFKDWS      = 0x000E; /* ����������� ��� ��� (�� WS-�����) */
const unsigned short p2dbdWSRange1First = p2dbfWSBLOB; /* � ����� ������ ���� �������, ���������� � WS */
const unsigned short p2dbdWSRange1Last  = 0x001C; /* �� ����� ������ ��������������� �� ���������, ����������� � WS */
const unsigned short p2dbfWinLOG        = 0x001D; /* WinLOG (�������� � ���) */

/* ����� Flags ������ TPrimeDepthIndex */
const long pdifAnalysed        = 0x00000001;
const long pdifAnalysisSuccess = 0x00000002;

/* ���� ������� ������ ��������� ������, ���� IndexType ������ TPrimeDepthIndex */
const long pditUnknown        = 0x00000001; /* ����������� */
const long pditFixedStepArray = 0x00000002; /* ������ ��������, ������ � ������������� ����� �� ������� */
const long pditDepthList      = 0x00000003; /* ������ ������ */

/* ������ ��������, ������ � ������������� ����� �� ������� */
typedef struct {
  long Top_PU;
  long Bottom_PU;
  long Step_PU;
  long Count;
  long SourceIndexes[(0x7FFFFFFF / sizeof (long)) - 4];
} TPrimeDepthIndex_FixedStep, *PPrimeDepthIndex_FixedStep;

/* ������ ������ */
typedef struct {
  long Count;
  long Depths_PU[(0x7FFFFFFF / sizeof (long)) - 1];
} TPrimeDepthIndex_List, *PPrimeDepthIndex_List;

/* ������ ������ ��������� ������ */
typedef struct {
  long Flags; /* pdifXXXX */
  long IndexType; /* pditXXXX */
  PPrimeDepthIndex_FixedStep FixedStepIndex_DepthShifted;
    /* ������ ���� "������ ��������" ��� ��������������� �����, �� ��������� �� ������� */
  PPrimeDepthIndex_FixedStep FixedStepIndex_Final;
    /* ������ ���� "������ ��������" ��� �������������� ������ (��������� ��������� ������) */
  PPrimeDepthIndex_List ListIndex_Initial;
    /* ������ ���� "������ ������" ��� ��������������� ����� */
  unsigned char Reserved[44]; /* ��������������� */
} TPrimeDepthIndex;


/* ������ ��� ��������� ������ �������� */
typedef struct {
    long dwStart;                         /* ����� �������, 0.1 �� */
    long dwWidth;                         /* ������, 0.1 �� */
    long dwColor;                         /* ���� */
    long dwFlags;                         /* ����� (p2dfXXXX) */
    long dwRoof;                          /* ������, �� (�����������) */
    long dwSole;                          /* �������, �� (�����������) */
    PasString psDisplayName;                 /* �������� */
    long dwDataRoofOrSole;                /* ������ ��� ������� ������, �� */
                                          /* �������, ���� ����� ���� tdhfRevRowOrder */
                                          /* �� ���., ���� ����� ���� tdhfDepthsPresent */
    long dwDataStep;                      /* ��� ������, �� */
                                          /* �� ���., ���� ����� ���� tdhfDepthsPresent */
    long iChannelIndex;                   /* ������ ������������� ������ */
    long cbitFileHeaderSize;              /* ������ ��������� ����� ������ � ����� */
    TTwoDColorFormat bFinalColorFormat;   /* ������ ����� ��� ����������� (tdcfXXXX) */
    PTwoDCurveDataHeader lpRowsFormat;    /* ��������� �� ��������� ������� ������ �����
                                             (���� wDataFormat == p2dbfNone) */
    PTwoDColorTransform lpColorTransform; /* ��������� �� ��������� ������� �������������� � ���� */
    long dwStorageFlags;                  /* ����� ��������� ������ (���� �� ������������) */
    string32 psStorageTable;              /* ���� �� ������������ */
    PasString psStorageName;                 /* ��� ����� ������ (� ������� ������) */
    float fArgMin;                        /* ��������� ������� ��������� */
    float fArgStep;                       /* ��� ��������� */
    /* ��������� 4 ���� ������ ������������ (��������) ����� ������� �� �����
      � ����������� ���������� */
    long dwDataMin;                       /* ���. �������� ������ */
    long dwDataMax;                       /* ����. �������� ������ */
    float fValMin;                        /* ���. �������� ���. �������� */
    float fValMax;                        /* ����. �������� ���. �������� */
    unsigned char bLegendValueDigits;     /* ����� ������ ����� ������� � ������� */
    string64 psHeaderTitleFontName;       /* ����� �������� � ������� */
    unsigned short usHeaderTitleFontSize; /* ������ ������ �������� � �������, 0.1 �� */
    unsigned short usHeaderTitleJust;     /* ������������ �������� � ������� */
    string64 psHeaderValFontName;         /* ����� �������� � ������� */
    unsigned short usHeaderValFontSize;   /* ������ ������ �������� � �������, 0.1 �� */
    unsigned short usHeaderValJust;       /* ������������ �������� � ������� */
    unsigned char bHeaderValueDigits;     /* ����� ������ ����� ������� � ������� */
    unsigned short usHeaderTickSize;      /* ������ ����� � �������, 0.1 �� */
    long dwHeaderColor;                   /* ���� ������� */
    void *lpLeftCurve;                    /* ����� �������������� ������ */
    void *lpRightCurve;                   /* ������ �������������� ������ */
    float fHCMin;                         /* ������ ������� �������� �����. ������, ���.��. */
    float fHCMax;                         /* ������� ������� �������� �����. ������, ���.��. */
    float fHCVal0;                        /* �������� �� "0", ���.��. */
    float fHCScale;                       /* ������� �����. ������, ���.��/��. */
    unsigned short usHCLineIndex;         /* ����� ���� ������ (��. WSIGF.CRV) */
    long dwHCStep;                        /* ��� ����� �����. �������, ��. p2dfPointStepInRows */
    long dwHCRoof;                        /* ������ �����. ������ (�����������) */
    long dwHCSole;                        /* ������� �����. ������ (�����������) */
    long dwDepthShift;                    /* �������� ����� ������� �� �������, �� */
    long dwArgLevelMask;                  /* ����� ����������� ������� ��������� */
    float afArgLevels[10];                /* ������ ��������� */
    long dwFuncLevelMask;                 /* ����� ����������� ������� ������� */
    float afFuncLevels[10];               /* ������ ������� */
    float fArgRangeMin;                   /* ������� ��������� (�����������) */
    float fArgRangeMax;                   /* �������� ��������� (�����������) */
    unsigned short wDataFormat;           /* ������ ������ (p2dbfXXXX) */
    PDepthTieArray lpDepthTieArray;       /* ������ ������ ��������� ������ �� ������� */
    float fPhaseShift;                    /* ����� �� ���� (�����������) ��� ���������, ����� */
    OType hWSData;                        /* Handle ������ (���� ��� - WS-������) */
    PDepthShiftArray lpChlDptShifts;      /* ������ ������� ������� �� ������� ������������ ����� ������ */
    unsigned char acReserved[10];         /* ��������������� */
} TView2dCurveRec, *PView2dCurveRec;

/* ��������� ������ �������� */
const int MaxPrintIntervals = 100; /* ������������ ���������� ���������� ������ �������� */

/* ������ ������ ��������� */
const unsigned short pifUpperHeader  = 0x0001; // 0 ��� - �������� ����� ������
const unsigned short pifUpperLegend  = 0x0002; // 1 ��� - �������� ������� ������
const unsigned short pifUHeaderFirst = 0x0004; // 2 ��� - ����������� (�, ����� �)
const unsigned short pifLowerHeader  = 0x0010; // 4 ��� - �������� ����� �����
const unsigned short pifLowerLegend  = 0x0020; // 5 ��� - �������� ������� �����
const unsigned short pifLLegendFirst = 0x0040; // 6 ��� - ����������� (�, ����� �)
                                               // ���� 3, 7-15 ���������������

typedef struct TPrintInterval {
    long Sole;            // ������ ��������� ������ (� ��)
    long Roof;            // ������� ��������� (� ��)
    long Scale;           // ������� ��������� (1 : Scale)
    long Indent;          // ������� ����� (� 0.1 ��)
    unsigned short Flags; // ������� ������ ��������� - ��. ��������� pifXXXX
    char Reserved[16];
} TPrintInterval, *PPrintInterval;

/* ���� ������ ������������ (ReloadConfig) */
const long cfgAllConfig = -1; // ��� ����� ������������
const long cfgNoConfig  = 0;  // ��� ��������
const long cfgCRV       = 1;  // WSIGF.CRV
const long cfgFIL       = 2;  // WSIGF.FIL
const long cfgWST       = 3;  // WSIGF.WST
const long cfgPEN       = 4;  // WSIGF.PEN
const long cfgPNT       = 5;  // WSIGF.PNT
const long cfgINT       = 6;  // WSIGF.INT

const long cfgmskMethod = 0x0000000F; // ����� ������ ��������
const long cfgmtdFile   = 0; // �������� �� ���������� ����� (���� ��������,
                             // ����� ��� ����� ������ �� ���������)

/* ���������� ������� GetBuildType */
const long pbtUnknown  = 0; // ����������� ���
const long pbtStandard = 1; // ����������� �����/������
const long pbtViewer   = 2; // ��������� ��������� � ������ (�� ����� ���� ����������)
const long pbtIngis    = 3; // ������ ������ � �������� �����

/* ������������ �������� BuildSubType � GetBuildType */
const long pbstPRIME   = 0; // �����
const long pbstBASHGIS = 1; // ������

const unsigned short HASPInfoSignature = 0x4850; // ��������� ���������� ��� ���������� ������ HASP�

typedef struct {
    long dwSize;
    unsigned short hiSignature;
    long hiSoftSerialNumber;
    char hiReserved1[10];
    long hiHardSerialNumber;
    char hiReserved2[40];
} THaspInfo, *PHaspInfo; // 64 �����

typedef unsigned char TConflictFieldsAction;
const unsigned char cfaAskUser   = 0;
const unsigned char cfaOverwrite = 1;
const unsigned char cfaSkip      = 2;
const unsigned char cfaCancel    = 3;

/* ������� ����� ��� ��������� Flags1 (GetSheetSelectMode, SetSheetSelectMode) */
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

typedef struct { /* ��������� ������� ������� */
  unsigned long BitFields[4];
} TColumnsSet, *PColumnsSet;

typedef struct {
    /* ������ ��� ������� AddCurveDataToList, GetCurveDataFromList, SelectCurves_1 */
    char acTableName[33];
    long nObjRow;
    char acArrayName[33];
    unsigned char nArrayCol;
    char abReserved[57];
} TTableCurveDataRec, *PTableCurveDataRec;

/* CALLBACKS */

/* ���� ������� ��� CALLBACK */
const long pevNone = 0x00000000;

const long pevSystemLoaded          = 0x00010001;
const long pevSystemExiting         = 0x00010002;
const long pevSystemExitQuery       = 0x00010003;
    /* Return value > 0: �� �������� */
const long pevSystemSettingsChanged = 0x00010004;
    /*  */

const long pevUserActionQuery     = 0x00020002;
    /* lpObject: ��� DLL
       lpInput: ��� �������
       Return value > 0: �� ��������� */
const long pevUserActionExecuting = 0x00020002;
    /* lpObject: ��� DLL
       lpInput: ��� ������� */
const long pevUserActionExecuted  = 0x00020002;
    /* lpObject: ��� DLL
       lpInput: ��� ������� */

const long pevPlansheetCreated    = 0x00030001;
    /* lpObject: ����� ������� */
const long pevPlansheetOpened     = 0x00030002;
    /* lpObject: ������� */
const long pevPlansheetClosing    = 0x00030003;
    /* lpObject: ������� */
const long pevPlansheetCloseQuery = 0x00030004;
    /* lpObject: �������
       Return value > 0: �� ��������� */
const long pevPlansheetModified   = 0x00030005;
    /* lpObject: ������� */

const long pevObjectCreated      = 0x00040001;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX */
const long pevObjectInsertQuery  = 0x00040002;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX
       lpInput: �������
       Return value > 0: �� ��������� */
const long pevObjectInserted     = 0x00040003;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX
       lpInput: ������� */
const long pevObjectDeleteQuery  = 0x00040004;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX
       lpInput: �������
       Return value > 0: �� ������� */
const long pevObjectDeleted      = 0x00040005;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX
       lpInput: ������� */
const long pevObjectDestroyQuery = 0x00040006;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX
       Return value > 0: �� ���������� */
const long pevObjectDestroying   = 0x00040007;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX */
const long pevObjectModified     = 0x00040008;
    /* lpObject: ������
       dwObjectType: 1 - ������ ��������, 2 - ������ �����, 3 - ������ �������
       dwObjectSubType: ��� 1 - wsXXXX
                        ��� 2, 3 - hmXXXX */

/* ����� ���� ������� ��� CALLBACK */
const long pcboDiagramsObject = 0x00000001;
const long pcboHeaderObject   = 0x00000002;
const long pcboFooterObject   = 0x00000003;

/* ����� ��������� CALLBACK */
const long pcbfIncludeProgramEvents    = 0x00000001;
const long pcbfExcludeThisModuleEvents = 0x00000002;
const long pcbfLoadLibraryOnEvent      = 0x00000004;
const long pcbfIgnoreFuncPointer       = 0x00000008;
const long pcbfSeparateInstances       = 0x00000010;
const long pcbfIgnoreExceptions        = 0x00000020;

/* ����� �������� CALLBACK */
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

/* ����� Flags ������� PlanObjDragDrop */

const long ddfCopyCurveColor        = 0x00000001;
const long ddfCopyCurveResultStatus = 0x00000002;

/* PrimeExecuteFunction */

extern const char *pefBuiltInPrime; // ��������� ���������� �������
const long WM_PRIMECOMMAND = 0x8008;
const long PCM_NONE = 0;

/* �������� � ���� ���������� ������� */
extern const char *pbfSystemExit; /* ����� �� ������� */                         const long PCM_SYSTEMEXIT                = 0x00010001;
extern const char *pbfEditToolbars; /* ��������� ������� */                      const long PCM_EDITTOOLBARS              = 0x00010002;
extern const char *pbfEditMenu; /* ��������� ���� */                             const long PCM_EDITMENU                  = 0x00010003;
extern const char *pbfEditDefaults; /* ��������� ��������� */                    const long PCM_EDITDEFAULTS              = 0x00010004;
extern const char *pbfEditPrintDevices; /* ��������� ��������� ������ */         const long PCM_EDITPRINTDEVICES          = 0x00010005;
extern const char *pbfPrimeHelp; /* ����� ������� */                             const long PCM_PRIMEHELP                 = 0x00010006;
extern const char *pbfPrimeHelpSearch; /* ����� � ���������� ������� */          const long PCM_PRIMEHELPSEARCH           = 0x00010007;
extern const char *pbfPrimeAbout; /* ������� � ��������� */                      const long PCM_PRIMEABOUT                = 0x00010008;
extern const char *pbfTableDialog; /* ������ ������� */                          const long PCM_TABLEDIALOG               = 0x00010009;
extern const char *pbfTableDialogOld; /* ������ ������ */                        const long PCM_TABLEDIALOGOLD            = 0x0001000A;
extern const char *pbfResDialog; /* ������ RES */                                const long PCM_RESDIALOG                 = 0x0001000B;
extern const char *pbfCreateDataFromRes; /* �������� ������ �� ������� */        const long PCM_CREATEDATAFROMRES         = 0x0001000C;
extern const char *pbfSelectNextWindow; /* ��������� */                          const long PCM_SELECTNEXTWINDOW          = 0x0001000D;
extern const char *pbfSelectPrevWindow; /* ���������� */                         const long PCM_SELECTPREVWINDOW          = 0x0001000E;
extern const char *pbfWindowsTileVertical; /* ���� ������ ���� */                const long PCM_WINDOWSTILEVERTICAL       = 0x0001000F;
extern const char *pbfWindowsTileHorizontal; /* ���� ����� ������� */            const long PCM_WINDOWSTILEHORIZONTAL     = 0x00010010;
extern const char *pbfWindowsCascade; /* ���� �������� */                        const long PCM_WINDOWSCASCADE            = 0x00010011;
extern const char *pbfEditGraph; /* ���� ��������� */                            const long PCM_EDITGRAPH                 = 0x00010012;
extern const char *pbfShowSaxBasic; /* ������� SBasic */                         const long PCM_SHOWSAXBASIC              = 0x00010013;
extern const char *pbfRunSaxBasicMacro; /* ��������� ������ */                   const long PCM_RUNSAXBASICMACRO          = 0x00010014;

extern const char *pbfCreatePlansheet; /* ������� ������� */                     const long PCM_CREATEPLANSHEET           = 0x00020001;
extern const char *pbfOpenPlansheet; /* ������� ������� */                       const long PCM_OPENPLANSHEET             = 0x00020002;
extern const char *pbfSavePlansheet; /* ��������� ������� */                     const long PCM_SAVEPLANSHEET             = 0x00020003;
extern const char *pbfSavePlansheetAs; /* ��������� ������� ���... */            const long PCM_SAVEPLANSHEETAS           = 0x00020004;
extern const char *pbfSavePlansheetAsTemplate; /* ��������� ��� ������ */        const long PCM_SAVEPLANSHEETASTEMPLATE   = 0x00020005;
extern const char *pbfPrintPlansheet; /* ������ �������� */                      const long PCM_PRINTPLANSHEET            = 0x00020006;
extern const char *pbfEditPlansheetParams; /* ��������� �������� */              const long PCM_EDITPLANSHEETPARAMS       = 0x00020007;
extern const char *pbfEditLegendParams; /* ��������� ������� */                  const long PCM_EDITLEGENDPARAMS          = 0x00020008;
extern const char *pbfChangePlansheetScale; /* ������� ��������� �������� */     const long PCM_CHANGEPLANSHEETSCALE      = 0x00020009;
extern const char *pbfSetPlansheetAutoScale; /* ������� ��������� - �� ������ */ const long PCM_SETPLANSHEETAUTOSCALE     = 0x0002000A;
extern const char *pbfSetPlansheetNoScale; /* ������� ��������� - 1:1 */         const long PCM_SETPLANSHEETNOSCALE       = 0x0002000B;
extern const char *pbfClosePlansheet; /* ������� ������� */                      const long PCM_CLOSEPLANSHEET            = 0x0002000C;
extern const char *pbfEditPlansheetHeaderOrder; /* ������� ��������� ������� */  const long PCM_EDITPLANSHEETHEADERORDER  = 0x0002000D;
extern const char *pbfSavePlansheetAsArchive; /* ��������� � �����... */         const long PCM_SAVEPLANSHEETASARCHIVE    = 0x0002000E;

extern const char *pbfInsertObject; /* ������� ������� � ������� */              const long PCM_INSERTOBJECT              = 0x00030001;
extern const char *pbfInsertCurvesFromAnotherWS; /* ������� ������ �� WS */      const long PCM_INSERTCURVESFROMANOTHERWS = 0x00030002;
extern const char *pbfInsertPoint; /* �������� ����� */                          const long PCM_INSERTPOINT               = 0x00030003;
extern const char *pbfInsertInter; /* �������� ��������� */                      const long PCM_INSERTINTER               = 0x00030004;
extern const char *pbfInsertEmptyFrame; /* ������ ����� */                       const long PCM_INSERTEMPTYFRAME          = 0x00030005;
extern const char *pbfInsertTextFrame; /* ����� � ������� */                     const long PCM_INSERTTEXTFRAME           = 0x00030006;
extern const char *pbfInsertTableFrame; /* ����� � �������� */                   const long PCM_INSERTTABLEFRAME          = 0x00030007;
extern const char *pbfInsertPictureFrame; /* ����� � �������� */                 const long PCM_INSERTPICTUREFRAME        = 0x00030008;
extern const char *pbfInsertSampleLineFrame; /* ������� ����� ������ */          const long PCM_INSERTSAMPLELINEFRAME     = 0x00030009;
extern const char *pbfPlansheetObjectsList; /* ������ �������� �������� */       const long PCM_PLANSHEETOBJECTSLIST      = 0x0003000A;
extern const char *pbfDeleteActivatedObjects; /* ������� ���������� ������� */   const long PCM_DELETEACTIVATEDOBJECTS    = 0x0003000B;
extern const char *pbfInsertEmptyTower; /* ������� ������ ������� */             const long PCM_INSERTEMPTYTOWER          = 0x0003000C;
extern const char *pbfInsertDepthTower; /* ������� ������� ������ */             const long PCM_INSERTDEPTHTOWER          = 0x0003000D;
extern const char *pbfInsertPlastTower; /* ������� ����������� ������� */        const long PCM_INSERTPLASTTOWER          = 0x0003000E;
extern const char *pbfInsertLitholTower; /* ������� �������������� ������� */    const long PCM_INSERTLITHOLTOWER         = 0x0003000F;
extern const char *pbfInsertStratTower; /* ������� ����������������� ������� */  const long PCM_INSERTSTRATTOWER          = 0x00030010;
extern const char *pbfInsertLineGridTower; /* ������� �������� ����� */          const long PCM_INSERTLINEGRIDTOWER       = 0x00030011;
extern const char *pbfInsertLogGridTower; /* ������� ��������������� ����� */    const long PCM_INSERTLOGGRIDTOWER        = 0x00030012;
extern const char *pbfInsetCurves; /* ������� ������ */                          const long PCM_INSERTCURVES              = 0x00030013;
extern const char *pbfInsertNote; /* ������� ������� */                          const long PCM_INSERTNOTE                = 0x00030014;
extern const char *pbfInsertChord; /* ������� ������ */                          const long PCM_INSERTCHORD               = 0x00030015;
extern const char *pbfInsertFiller; /* ������� ������� */                        const long PCM_INSERTFILLER              = 0x00030016;
extern const char *pbfInsertPicture; /* ������� ������� */                       const long PCM_INSERTPICTURE             = 0x00030017;
extern const char *pbfInsertScale; /* ������� ����� */                           const long PCM_INSERTSCALE               = 0x00030018;
extern const char *pbfInsertTwoDCurve; /* ������� ��������� ������ */            const long PCM_INSERTTWODCURVE           = 0x00030019;
extern const char *pbfInsertHandleInter; /* ������� ��������� ��������� */       const long PCM_INSERTHANDLEINTER         = 0x0003001A;
extern const char *pbfPlansheetCurvesList; /* ������ ������ */                   const long PCM_PLANSHEETCURVESLIST       = 0x0003001B;

extern const char *pbfExitExecuteWindow; /* ������� */                           const long PCM_EXITEXECUTEWINDOW         = 0x00040001;
extern const char *pbfInsertPlasts; /* ������� ����������� */                    const long PCM_INSERTPLASTS              = 0x00040002;
extern const char *pbfDeletePlasts; /* �������� ����������� */                   const long PCM_DELETEPLASTS              = 0x00040003;
extern const char *pbfDeletePlastsByOne; /* �������� ����������� �� ������ */    const long PCM_DELETEPLASTSBYONE         = 0x00040004;
extern const char *pbfSelectWellV4; /* ����� �������� */                         const long PCM_SELECTWELLV4              = 0x00040005;
extern const char *pbfEditLoadConditionFilter; /* ������ �������� ������ */      const long PCM_EDITLOADCONDITIONFILTER   = 0x00040006;
extern const char *pbfInsertPlastsWithClass; /* ������� ����������� 2 */         const long PCM_INSERTPLASTSWITHCLASS     = 0x00040007;
extern const char *pbfCut; /* �������� */                                        const long PCM_CUT                       = 0x00040008;
extern const char *pbfCopy; /* ���������� */                                     const long PCM_COPY                      = 0x00040009;
extern const char *pbfPaste; /* �������� */                                      const long PCM_PASTE                     = 0x0004000A;
extern const char *pbfSelectAll; /* �������� ��� */                              const long PCM_SELECTALL                 = 0x0004000B;
extern const char *pbfCorrectPlasts; /* ������������� */                         const long PCM_CORRECTPLASTS             = 0x0004000C;


/* ������������ �������� ��� ������� PrimeExecuteFunction */
const long paExecuted    =  0; // ������� ���������
const long paNotExecuted = -1; // ������� �� ���������
const long paExecError   = -2; // ������ ���������� (���������� ��������)
const long paException   = -3; // ���������� ��� ����������
const long paUserCancel  = -4; // �������� �������������

/* ����� FindFlags ������� FindPlanObject */
const long fpofUseTestObject      = 0x00000001;
const long fpofAllowWithoutData   = 0x00000002;
const long fpofForceWithoutData   = 0x00000004;
const long fpofSourceOnly         = 0x00000008;
const long fpofResultOnly         = 0x00000010;
const long fpofLayerDataOnly      = 0x00000020; /* ������ ����������� ������ */
const long fpofContinuousDataOnly = 0x00000040; /* ������ ����������� ������ */

/* ����� ObjMask ������� FindPlanObject */
const long fpomAll         = -1;
const long fpomCurves      = 0x00000001;
const long fpomLayerTowers = 0x00000002;
const long fpomDepthTowers = 0x00000004;

/* ����� Flags ������� InsertOrReplaceObject */
const long irofAlwaysInsertNew       = 0x00000001;
const long irofInsertNewIfUserCancel = 0x00000002;
const long irofDontMake              = 0x00000004;
const long irofSourceTemplateOnly    = 0x00000008;
const long irofResultTemplateOnly    = 0x00000010;
const long irofSelectFirstIfMany     = 0x00000020;
const long irofSelectNewestIfMany    = 0x00000040;
const long irofSelectOldestIfMany    = 0x00000080;
const long irofUserSelectIfMany      = 0x00000100;

/* ����� �������� �������� */
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

/* ����� ���������� �������� */
const long cmdsfSaveToTemplate     = 0x00000001;
const long cmdsfSlaveTablesDlg     = 0x00000002;
const long cmdsfQueryPack          = 0x00000004;
const long cmdsfPack               = 0x00000008;
const long cmdsfQueryName          = 0x00000010;
const long cmdsfOverwritePlanTable = 0x00000020;
const long cmdsfForceSave          = 0x00000040;
const long cmdsfDontAddToRecent    = 0x00000080;
const long cmdsfNoProgressBar      = 0x00000100;

/* ����� ����������/������� ���������� �������� � ������ �������� */
const long sptofCurves  = 0x00000001;
const long sptofPoints  = 0x00000002;
const long sptofInters  = 0x00000004;
const long sptofTowers  = 0x00000008;
const long sptofNotes   = 0x00000010;
const long sptofFillers = 0x00000020;
const long sptofScales  = 0x00000040;
const long sptofRepers  = 0x00000080;

/* ����� Flags ������� ShowPlanWindow */
const long cmdshVisible = 0x00000001; /* �������� ���� (����� - ��������) */

/* ==== ����� ���� �������� ��������� ��� ���������� �������� ============ */
/* ======================================================================= */
extern char *fnPlanName;      /* �������� �������� */
extern char *fnPlanColor;     /* ���� ����� �������� */
extern char *fnPlanWidth;     /* ������ �������� */
extern char *fnPlanRoof;      /* �������� ������ �������� */
extern char *fnPlanSole;      /* �������� ������� �������� */
extern char *fnScaleIndex;    /* ����� ������������ �������� */
extern char *fnScaleValue;    /* �������� �������������� �������� */
extern char *fnViewScaleMul;  /* ������� ��������� - ��������� */
extern char *fnViewScaleDiv;  /* ������� ��������� - ����������� */
extern char *fnLitolTable;    /* �������� ������� ��������� */
extern char *fnTableFont;     /* ����� �������� ������� ��������� */
extern char *fnTableSize;     /* ������ �������� ������� ��������� */
extern char *fnTableJust;     /* ������������ �������� ������� ��������� */
extern char *fnTableSpace;    /* ������ ����� ����� ������� */
extern char *fnLitolFont;     /* ����� �������� ��������� */
extern char *fnLitolSize;     /* ������ �������� ��������� */
extern char *fnLitolJust;     /* ������������ �������� ��������� */
extern char *fnLitolSpace;    /* ������ �������� ��������� */
extern char *fnLitolWidth;    /* ������ �������� ��������� */
extern char *fnLitolHeigth;   /* ������ �������� ��������� */
extern char *fnTemplateName;  /* �������� ������� �������� */
extern char *fnTemplateHelp;  /* ������� �������� �������� */
extern char *fnTemplateInfo;  /* ������ �������� �������� */
extern char *fnNameDict;      /* ������� ��� ������ */
extern char *fnUnitDict;      /* ������� ������ ��������� */
extern char *fnName2UnitDict; /* ������� �������� ��� � ������� ��������� */
extern char *fnPlanFlags;     /* ����� �������� */
extern char *fnCurDepth;      /* ������� ������� �������� */

extern char *anPrintIntervals; /* ������ ���������� ������ �������� */
extern char *fnPrintIntervalRoof;   /* ������ ��������� */
extern char *fnPrintIntervalSole;   /* ������� ��������� */
extern char *fnPrintIntervalScale;  /* ������� ������ ��������� */
extern char *fnPrintIntervalIndent; /* ������� ����� */
extern char *fnPrintIntervalFlags;  /* ������ ������ ��������� (��. ��������� pifXXXX) */

/* ������ ����� ��� ���� �������� */
extern char *fnState; /* ����� ��������� ������� */
extern char *fnIdentifier;
extern char *fnOwnerIdentifier;
extern char *fnLegendPlace; /* ������� �������: � ���� ������ ��� � ���� ������ */
/* ������ ��� ������ */
extern char *anViewCurve;
extern char *fnCurveInfo; /* �������� ���������� � ������ (�� ����������) */
/* ��������� ����������� ������ ������ */
extern char *anCurveStyle;
extern char *fnCurveStart;     /* ������ ������� ���������� ������ */
extern char *fnCurveWidth;     /* ������ ������� ���������� ������ */
extern char *fnCurveColor;     /* ����� ������ (��.���� WSIGF.CRV) */
extern char *fnCurveMinimum;   /* �������� ������ �� ����� ������� */
extern char *fnCurveScale;     /* ������� ������ (���.��.�� 1 ��.) */
extern char *fnCurveModul;     /* ������ ���������������� �������� */
extern char *fnCurvePower;     /* ��������� ��������.��������      */
extern char *fnCurveFlags;     /* ������ ��������� ������ (cfXXXX) */
extern char *fnCurveMHIndex;   /* ��������� ������ (mvXXXX)        */
extern char *fnCurveMHValue;   /* �������� �������.�����.��������. */
extern char *fnCurveSHIndex;   /* ��������� ������������� (svXXXX) */
extern char *fnValueName; /* �������� ������ ������ ������    */
extern char *fnValueUnit; /* �������� ������� ���������       */
/* ��������� ����������� ���������� ������� */
extern char *anCurveHeader;
extern char *fnHeaderType;  /* ��� ���������� �������: 0 - �������, 1-������ */
extern char *fnValueJust;   /* ������������ �������� �� ���������� ������� */
extern char *fnValueIndent; /* ������ �������� �� ���������� ������� */
extern char *fnValueFont;   /* ����� ��� ������ �������� */
extern char *fnValueSize;   /* ������ ������ ��� ������ �������� */
extern char *fnValueZero;   /* �������� ��� ������ �������� */
extern char *fnValueAdds;   /* ����� �������������� �������� */
extern char *fnNameFont;    /* ����� ��� ������ �������� ������ */
extern char *fnNameSize;    /* ������ ������ ��� ������ �������� ������ */
extern char *fnUnitFont;    /* ����� ��� ������ ������� ��������� */
extern char *fnUnitSize;    /* ������ ������ ��� ������ ������� ��������� */
/* ���� � ������� ������� �� ������ ���������� ������� */
extern char *fnLeftArrow;  /* ...��� ������ ����� */
extern char *fnRightArrow; /* ...��� ������ ������ */
extern char *fnArrowSize;  /* ...������� ������� */
/* ������� ��������� */
extern char *fnInterLine;  /* ����� �������� � �������� ������ ��� ��.���.*/
extern char *fnSkipBefore; /* ����� ���������� �������� */
extern char *fnSkipAfter;  /* ����� ���������� �������  */
/* �������� �� ������ */
extern char *anCurveBreaks;
extern char *fnBreakFont;        /* �������� ������ ��� ������ �������� */
extern char *fnBreakSize;        /* ������ ������ ��� ������ �������� */
extern char *fnBreakZero;        /* �������� ������ �������� �� ������ */
extern char *fnBreakVertIndent;  /* ������ �������� �� ��������� */
extern char *fnBreakVertBelow;   /* ������.�� ����.�� ����� */
extern char *fnBreakVertAfter;   /* ������.�� ����.����� ����� */
extern char *fnBreakHorizIndent; /* ������ �������� �� ��������.*/
extern char *fnBreakHorizBelow;  /* ������.�� �����.�� ����� */
extern char *fnBreakHorizAfter;  /* ������.�� �����.����� ����� */
extern char *fnHeaderManual;     /* ������ ������� �������� ����� */
extern char *fnHeaderLeft;       /* �������� ����� ����� */
extern char *fnHeaderRight;      /* �������� ����� ������ */
/* ������� ������� �� ������ */
extern char *anCurveLevels;
extern char *fnLevelMask;        /*  */
extern char *fnLevel;            /*  */
/* ������� ������ �� ������ */
extern char *anCurveDepths;
extern char *fnDepthMask;        /*  */
extern char *fnDepth;            /*  */
/* ������, ����������� �������� ������ � ������� �� WS ����� */
extern char *anWSAccess;
extern char *fnCurveRow;         /* ����� ���� ������ � ������� */
extern char *fnCurveColumn;      /* ����� ������� � ������� */
extern char *fnCurveArrayName;   /* �������� ������� */
extern char *fnCurveTableName;   /* �������� ������� */

/* ������ ��� ���������� � ���������� */
extern char *anViewInter;
extern char *anViewPoint;
extern char *fnWSHStart;  /* ������� ��� ��������� ��������� */
extern char *fnWSHWidth;  /* ������� ��������� */
extern char *fnWSHColor;  /* ���� ��������� */
extern char *fnWSHRow;    /* ����� ������ ��� ������� ��������� � ������� */
extern char *fnWSHArray;  /* �������� ������� � ������ ���������� */

/* ������ ��� �������� */
extern char *anViewNotes;
extern char *fnNotesStart;  /* ������� ���������� ������� */
extern char *fnNotesDepth;  /* ������� ���������� ������� */
extern char *fnNotesColor;  /* ���� ������ ������� */
extern char *fnNotesText;   /* ����� ������� */
extern char *fnNotesLen;    /* ����� ������������� */
extern char *fnNotesFont;   /* ����� ��� ������ ������� */
extern char *fnNotesSize;   /* ������ ������ ��� ������ ������� */
extern char *fnNotesLine;   /* ���������� ����� �������� ������� */
extern char *fnNotesHJust;  /* ��� ������������ �� ����������� (0-�����, 1-�� ������, 2-������)*/
extern char *fnNotesVJust;  /* ��� ������������ �� ��������� (0-�������, 1-�� ������, 2-������*/
extern char *fnNotesUnder;  /* ������������� */
extern char *fnNotesDirect; /* ����������� ������ ������� ("0" - ����� �������,
                                                           "1" - ����� �����,
                                                           "2" - ������ ������,
                                                           "3" - ������ ����)*/
extern char *fnNotesFlags;   /* ����� */
extern char *fnNotesBGColor; /* ���� ���� */

/* ������ ��� ������ ������� */
extern char *anEmptyTower;
/* ��������� ���� ��������� ��� ���� ����� ������� */
extern char *fnTowerStart;  /* ������ ������� */
extern char *fnTowerWidth;  /* ������ ������� */
extern char *fnTowerColor;  /* ���� ������� */
extern char *fnTowerName;   /* �������� ������� */
extern char *fnTowerFont;   /* ����� ��� ������ �������� ������� */
extern char *fnTowerSize;   /* ������ ������ ��� ������ �������� ������� */
extern char *fnTowerJust;   /* ��� ������������ �������� ������� (��.TViewNotesRec.HJust) */
extern char *fnTowerDirect; /* ����������� ������ �������� ������� (��.TViewNotesRec.Direct) */
extern char *fnTowerBefore; /* ������� �� �������� ������� */
extern char *fnTowerAfter;  /* ������� ����� �������� ������� */
extern char *fnTowerInter;  /* ������� ����� �������� � �������� ������� */

/* ������ ��� ������� ������ */
extern char *anDepthTower;
extern char *fnDepthTickStep;  /* ��� ������ ����� �� ���������� ������ */
extern char *fnDepthTextPlace; /* ��������� �������� ������ ������������ ����� */
extern char *fnDepthTextJust;  /* ������������ �������� ������ */
extern char *fnDepthFontName;  /* ����� ��� ������ �������� ������*/
extern char *fnDepthFontSize;  /* ������ ������ ��� ������ �������� ������ */
extern char *fnDepthAbsDepth;  /* �������� ���������� ������� */
extern char *fnDepthAbsFont;
extern char *fnDepthAbsZero;
extern char *fnDepthAbsSize;
extern char *fnDepthAbsJust;
extern char *fnDepthAbsInfo;
extern char *fnDepthAbsRow;
extern char *fnDepthAbsCol;
extern char *fnDepthAbsTable;
extern char *fnDepthAbsArray;
extern char *fnDepthLoadCondition; /* ������� �������� ������ */

/* ��������� ���������� ���������� ��� ������ ��������� �� ������� */
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

/* ������ ����� ��� ����������� ������� */
extern char *anInterTower;
extern char *fnInterDataName;   /* �������� ������� � ������� */
extern char *fnInterDataRow;    /* ����� ������ � ������� */
extern char *fnInterDataColumn; /* ����� ������� � ������� */
extern char *fnInterDataKey;    /* �������� ������ ��� ������ ������ */
extern char *fnInterDataArray;  /* �������� ���� � �������� ������ */
extern char *fnInterTableName;  /* �������� ������� � ����������� */
extern char *fnInterTableRow;   /* */
extern char *fnInterTableKey;   /* */
extern char *fnInterTableArray; /* */
extern char *fnInterResFile;    /* */
extern char *fnInterResName;    /* */
extern char *fnInterDictStr;    /* ������ ��� ������� */
extern char *fnInterEFlags;     /* �������������� ����� */
extern char *fnInterLIdent;     /* ������������� ����� ������ */
extern char *fnInterRIdent;     /* ������������� ������ ������ */

extern char *fnInterMode;  /* ����� ����� �������� */
extern char *fnInterZero;  /* �������� ������ �������� */
extern char *fnInterTrace; /* ��������� ������ �������������� ����� */

/* ��������� ������ ��� ����������� �������� ������������ */
extern char *fnInterStratFont;
extern char *fnInterStratSize;
extern char *fnInterStratJust;
extern char *fnInterStratDirect;
/* ��������� ������ ��� ����������� �������� ������ */
extern char *fnInterValueFont;
extern char *fnInterValueSize;
extern char *fnInterValueJust;
extern char *fnInterValuePlace;
/* ��������� ������ ��� ����������� �������� ������ */
extern char *fnInterDepthFont;
extern char *fnInterDepthSize;
extern char *fnInterDepthJust;
extern char *fnInterDepthPlace;
extern char *fnInterLoadCondition; /* ������� �������� ������ */

/* ������ ��� ����� */
extern char *anLnGridTower;
extern char *anLgGridTower;
extern char *fnTickPattern; /* ������� ������ ����� �� ������� */
extern char *fnGridPattern; /* ������� ������ ����� �� ������ */
extern char *fnTickStep;    /* ��� ������ ����� �� ������� */
extern char *fnTickFreq;    /* ������� ������� ����� �� ������� */
/* ���� ����� ��� �������� ����� �� ����������� */
extern char *fnGridStep;
extern char *fnGridFreq;
/* ���� ����� ��� ��������������� ����� �� ����������� */
extern char *fnGridModul;
extern char *fnGridStart;
extern char *fnGridPower;

extern char *anViewFiller;
extern char *fnFillerStart;   /* ������ */
extern char *fnFillerWidth;   /* ������ */
extern char *fnFillerState;   /* ��������� */
extern char *fnFillerFlags;   /* ��������� ������ */
extern char *fnFiller;        /* �������� ��������� */
extern char *fnFillerRoof;    /* ������ ������� ������ */
extern char *fnFillerSole;    /* ������� ������� ������ */
extern char *fnFillerNormal;  /* ������� ���������� ������� */
extern char *fnFillerReverse; /* ������� ������� "����� �������"*/
extern char *fnFillerLeft;    /* ������� ������� �� ������ */
extern char *fnFillerRight;   /* ������� ������� �� ����� */

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

extern char *fnFillerLInfo;  /* �������� ���������� � ����� ������ */
extern char *fnFillerLRow;   /*  ���������� ������ */
extern char *fnFillerLCol;   /*  - */
extern char *fnFillerLArray; /*  - */
extern char *fnFillerLTable; /*  - */

extern char *fnFillerRInfo;  /* �������� ���������� � ������ ������ */
extern char *fnFillerRRow;   /*  ���������� ������ */
extern char *fnFillerRCol;   /*  - */
extern char *fnFillerRArray; /*  - */
extern char *fnFillerRTable; /*  - */

/* ������ ��� �������� � �������� */
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

/* ������ ��� ������� */
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

/* ������ ��� ��������� ������ */
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

/* �������������� ��������� ������� ��� ��������� ������ */
extern char *fnLegendStartValue;
extern char *fnLegendEndValue;
extern char *fnLegendStepValue;

/* ������� �������������� �������� � ���� */
extern char *tnColorTransform;
extern char *fnColorTransform;
extern char *fnCTIdent;
extern char *fnCTFlags1;
extern char *fnCTColorFormat;
extern char *fnCTTransformMode;
extern char *fnCTInterpMode;
extern char *fnCTEmptyColor;
extern char *anCTTransformArray;

/* ������ ��� ������ ����� (����������) */
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

/* ������ ��� ����� � �������� (����������) */
extern char *anFrameTable;
extern char *fnFrameSource;
extern char *fnFrameEmpty;

/* ������ ��� ����� � ������� (����������) */
extern char *anFrameText;
extern char *fnFrameText;
extern char *fnFrameFont;
extern char *fnFrameSize;
extern char *fnFrameRMul;
extern char *fnFrameRDiv;
extern char *fnFrameJust;
extern char *fnFrameDir;
extern char *fnFrameInter;

/* ������ ��� ����� � �������� (����������) */
extern char *anFrameBitmap;
extern char *fnFrameBMPDraw;
extern char *fnFrameBMPName;
extern char *fnFrameBMPTable;

/* ������ ��� ������� ����� (����������) */
extern char *anFrameLine;
extern char *fnFrameLine;
extern char *fnFrameLineLen;
extern char *fnFrameLineSpace;
extern char *fnFrameLineText;
extern char *fnFrameLineTextFont;
extern char *fnFrameLineTextSize;
extern char *fnFrameLineTextRMul;
extern char *fnFrameLineTextRDiv;

/* ������� � ���������� ��������� */
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

/* ������ ���������� ������ */
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

/* ������ ����� ���������� ������ */
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

/* ����� ���������� ������ */
/* �������� ��������� ������ (long): 0 = 1 ��; 1 = 1 ��; 2 = 1 � */
extern char *ppnDepthPrecIndex;
/* �������� ��������� ������� (long): 0 = 0.1 ��; 1 = 1 ��; 2 = 1 �� */
extern char *ppnPosPrecIndex;
/* ��������� �� ��������� ��� ����������� ������� */
extern char *ppnDefTowerInterRec;

/*==================================================*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*=      �������                                   =*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*==================================================*/

/* ���������� ������� Prime32.exe */
extern "C" LongBoolean Prime32Connect(void);
/* �� ��, �� �������������� ���������, ���� ��� ���������� */
extern "C" LongBoolean Prime32CheckConnect(void);

/* ���������� ������ ���������� */
unsigned char GetHASPFlag(void) ;
long WSIGFExec(const char *ExeName, const char *CmdLine, LongBoolean TextMode);
/* ��������-��������� - �������� ���������� �������� ���� Prime32 */
HWND Prime32Handle(void);
/* ��������-��������� - �������������� Prime32 */
void PrimeBringToFront(void);
/* �������� ������� ������� ������ */
long GetPrimeWorkDir(char *lpDirName,long nSize);
/* �������� ������� ������� ���� */
long GetPrimeWorkBaseDir(char *lpDirName,long nSize);
/* ���������� ������� ������� ���� */
LongBoolean SetPrimeWorkBaseDir(const char *NewValue);
/* �������� ������� �������� ������ */
long GetPrimeSettingsDir(char *lpDirName,long nSize);
/* �������� ������ ������� ������ */
long GetPrimeVersion(char *lpVersion,long nSize);

/* ��������-��������� - ��������� �������� ����� ���������� */
void PrimeDisableUnload(HINSTANCE LibHandle);
/* ��������-��������� - ��������� ��� ������ ����������� */
void PrimeEnableUnload(HINSTANCE LibHandle);
/* ��������-��������� - ��������� �� ��������? */
LongBoolean PrimeUnloadEnabled(HINSTANCE LibHandle);
/* ��������-��������� - ����������� �� ������� ������? */
LongBoolean PrimeTerminating(void);

/* ========================================================================= */
/* ����������� ������ ������� */
void DoneObject(void* P);
/* ========================================================================= */
/* ������� � ������������ ������ �������-������ */
PPasString NewPString(const char* S);
/* ����� �������-������ */
unsigned char LenPString(PPasString P);
/* ���������� �������-������ � ���������� ������ */
void FreePString(PPasString P);
/* ========================================================================= */
void* GetMemLib(long ASize);
void FreeMemLib(void *P,long ASize);
void* AllocMemLib(long ASize);
void ReallocMemLib(void **P, long NewSize);
void PCharDispose(char *P);
/* ========================================================================= */
/* ������� ����� ��������� �������� */
void* InitList(long Limit = 8, long Delta = 8);
/* ������� ����� ��������� ����� */
void* InitStringList(long Limit = 8, long Delta = 8);
/* ������� ����� ��������� ���������� */
void* InitEmptyList(long Limit = 8, long Delta = 8);
/* ������� ����� ��������� ��������������� ����� */
void* InitUnsortList(long Limit = 8, long Delta = 8);
/* ���������� ����� ��������� ��������� */
long ListCount(void *List);
/* ���������� ������� �� ��� ������� */
void* ListAt(void *List,long Index);
/* ������� ������� �� ��������� */
void ListAtDelete(void *List,long Index);
/* ���������� ������� ��������� */
void ListAtFree(void *List,long Index);
/* �������� ������� � ��������� */
void ListAtInsert(void *List,long Index,void* Item);
/* �������� ������� ��������� */
void ListAtPut(void *List,long Index,void *Item);
/* ������� ������� ��������� */
void ListDelete(void *List,void *Item);
/* ������� �� ��������� ��� ��� �������� */
void ListDeleteAll(void *List);
/* ���������� ������� ��������� */
void ListFree(void *List,void *Item);
/* ���������� ��� �������� ��������� */
void ListFreeAll(void *List);
/* ���������� ������ ������� �������� � ��������� */
long ListIndexOf(void *List,void *Item);
/* ��������� ������� � ��������� */
void ListInsert(void *List,void *Item);
/* ������� �� ��������� ������ �������� */
void ListPack(void *List);
/* ����� ������ � ��������� (������ ��� ��������� �����) */
long ListSearch(void *List,const char *Key);
/* ========================================================================= */

/* ========================================================================= */
/*������ � ��������� �������� */
/* ������� ������ */
void* CreateWSCurve(OType DataHandle,long RowNumber,OType ArrayHandle,unsigned char ColNumber);
/* ������� ������-������ */
void* CreateWSRotCurve(OType DataHandle,long RowNumber,OType ArrayHandle,unsigned char ColNumber,unsigned char RotColNumber);
/* ������� �������� */
void* CreateWSPoint(OType ArrayHandle,long ArrayRow);
/* ������� �������� */
void* CreateWSInter(OType ArrayHandle,long ArrayRow);
/* ������� ������ ������� */
void* CreateWSTower(long Color,long Start,long Width,const char *Name);
/* ������� ������� ������ */
void* CreateWSDepth(long Color,long Start,long Width,const char *Name);
/* ������� �������� ����� */
void* CreateWSLnGrid(long Color,long Start,long Width,const char *Name);
/* ������� ��������������� ����� */
void* CreateWSLgGrid(long Color,long Start,long Width,const char *Name);
/* ������� ����������� ������� */
void* CreateWSPlast(long Color,long Start,long Width,const char *Name,
  OType DataHandle,OType ArrayHandle,long RowNumber,unsigned char ColNumber,
  OType DataInter,OType ArrayInter,long RowInter);

/* ������� ����������� */
void* CreateWSNotes(long ADepth,const char *P);
/* ������� ������� */
void* CreateWSFills(long AStart,long AWidth,long AFlags,long ARoof,long ASole,
 long Filler,long RevFill,long LeftFill,long RightFill,
 void *ALeftCurve,void *ARightCurve,float AConst);
/* ������� ������� �������� */
void* CreateWSPicture(void);
/* ������� ��������� ������ */
void* CreateWSTwoDCurve(void);
/* ������� ������ ����� */
void* CreateWSFrame(void);
/* ������� ����� � ������� */
void* CreateWSText(void);
/* ������� ����� � �������� */
void* CreateWSTable(void);
/* ������� ����� � �������� */
void* CreateWSBitmap(void);
/* ������� ����� */
void* CreateWSChord(long Start,long Width,long Color,long Flags,
  void *LeftCurve,void *RightCurve,long LeftDepth,long RightDepth);
/* ������� ����� */
void* CreateWSScale(long Start, long Width, long Color, long Flags,
  float AMinim, float AScale, void *Curve, long Depth,
  const char *Title);
/* ����� � �������� �������� ��������� (������ ���� wsInterReper) */
void* GetHandleInter(void *lpPlansheet, long dwReserved, long *dwRoof, long *dwSole);
/* ������� ����� �������� ��������� (������ ���� wsInterReper) */
void* CreateHandleInter(long dwReserved, long dwColor, long dwFlags, long dwRoof, long dwSole);

/* ������� ��� ����������� ���������� � ���� ������� �������� */
void StartProcess(const char *S);
void StepProcess(long Min,long Val,long Max);
void StopProcess(void);

/* �������� ������ ������� */
long WSStart(void *P);
/* �������� ������ ������� */
long WSWidth(void *P);
/* �������� ������ ������� */
long WSState(void *P);
/* �������� ��� ������� */
long WSType(void *P);
/* ���������������� ������ (������ ���������� ����� �������� �������
� �������). ���������� ������ ���� ������ ����� ���������, ����
���� ������ */
LongBoolean WSMake(void *P);
/* ����������� �� ������ ���������� ������ */
LongBoolean WSActual(void *P,unsigned short Mode);
/* �������� ������ ������� */
void WSGetData(void *P, void *Rec);
/* �������� ������ ������� */
void WSSetData(void *P, void *Rec);
/* ������ ������ ������� */
unsigned short WSDataSize(void *P);
/* �������� ���������� ������ ������� */
void WSReset(void *P);
/* ���������� ������ ��������� ������� */
void WSSetState(void *P,unsigned short Mask,LongBoolean Enable);
/* �������� ������ ��������� ������� */
LongBoolean WSGetState(void *P,unsigned short Mask);
/* �������� ������ ������� */
long WSRoof(void *P);
/* �������� ������� ������� */
long WSSole(void *P);
/* �������� ������� ������� ��������� �������� */
long WSNBRoof(void *P);
/* �������� ������� ���������� ��������� �������� */
long WSNBSole(void *P);
/* �������� �������� ������� */
void WSName(void *P,char *Name);
/* ������� ��� ������/������ �/�� ����������� ���� */
LongBoolean WSSetDialog(void *P);
LongBoolean WSGetDialog(void *P);
/* ���������� ������ ������� */
void WSSetStart(void *P,long Start);
/* ���������� ������ ������� */
void WSSetWidth(void *P,long Width);
/* �������� ������ ����� */
void FrameGetData(void *Frame, void *Rec);
/* �������� ������ ����� */
void FrameSetData(void *Frame, void *Rec);
/* ������ ������ ����� */
unsigned short FrameDataSize(void *Frame);
/* ���������� ������ ����� */
long FrameGetStart(void *P);
/* ���������� ������ ����� */
long FrameGetWidth(void *P);
/* ���������� ������ ����� */
long FrameGetState(void *P);
/* ������������� ������ ����� */
void FrameSetStart(void *P,long Value);
/* ������������� ������ ����� */
void FrameSetWidth(void *P,long Value);
/* ������������� ��������� ����� */
void FrameSetState(void *P,long Value);

/* ������ � ������� */
/* �������� ���������� ������ ������ */
long WSCurveActual(void *P);
/* ���������� ����� ������ */
long WSCurveCount(void *P);
/* ���������� �������� ������� � ����� � ��������� ������� */
long WSCurveDepth(void *P,long Index);
/* ���������� ����� ����� � ��������� �������� */
long WSCurveIndex(void *P,long Depth);
/* ���������� �������� ������/������� � ��������� ����� */
float WSCurveValue(void *P,long Depth);
/* ���������� �������� ������/������� � ��������� ����� ��� ������ */
long WSCurveValueStr(void *P,long Depth,char *Value,long ValueSize);
/* ���������� ��� ��������� ��� ����������� ������� �� ��������� ������� */
long GetLitholByDepth(void *P, long Depth);
/* ���������� ������������ ��� ����������� ������� �� ��������� ������� */
long GetStratByDepth(void *P, long Depth, char *Strat, long StratSize);
/* ���������� ������� ����������� ������� �� ��������� ������� */
long GetLegendByDepth(void *P, long Depth, char *Legend, long LegendSize);
/* �������� ������ ������� �� ����������� ������� */
OType GetTowerPlastArray(void *Tower);

/* ����� �����������, ������������ � ������� �������� ������ � ���������
��������� (���� ������ � ������� ��������� �����, �� �� ���� ������) */
long WSCurveMinMidMax(void *P,long Roof,long Sole,float *Min,float *Mid,float *Max);
/* ���������� �����������, �� ��� ������������ �������� ������ ��� �������� � ��������� */
long WSCurveMinMidMaxH(void *P,long Roof,long Sole,float *Min,float *Mid,float *Max,float *MinH,float *MaxH);
/* ��������� �������� ������������ ������ ��� ���������� ��������� */
long WSCurveLinear(void *P,long Roof,long Sole,float *A,float *B);
/* ������� ������ ��� ������ */
long WSCurveSetTemplate(void *P,const char *ATemplateName,char *Res);
/* ���������� ������ ��� �������. TemplateObj ������ ���� �� ��������, Obj - �� ����������� */
LongBoolean SetTemplateObject(void *Obj, void *TemplateObj, long dwFlags, void *lpReserved);
/* �������� ������ ��� ������� �� �������� */
void *GetTemplateObject(void *Obj, void *Plansheet);
/* �������� ������ ������ ������� �������� */
OType CreateTemplateDataObject(void *Obj, void *Plansheet, const char *ID, void *Reserved);
/* �������� ������������� ������� �� �������� */
long GetViewID(void *View);
/* ����� ������ �������� �� �������������� */
void *FindViewByID(void *Plansheet, long ID);
/* ������/������ ������� �������� */
long CurveGetLoadCondition(void *Curve, char *lpCondition, long nConditionSize);
LongBoolean CurveSetLoadCondition(void *Curve, const char *lpCondition);

/* ������� ��������� � ������ ������� */
void PutMessage(const char *S);
/* ������� ��������� � ������ ������� � ����� ������� �� ������������ */
void WaitMessage(const char *S);

/* �������� ��������� � ������ ������� */
void ClrMessage(void);

/* �������� ��������� �� ������� ���� */
void* CurrentWindow(void);
/* �������� �������� ����� �������� ���� */
void WindowFileName(char *FileName);
/* �������� ��� �������� ���� */
void WindowTypeName(char *TypeName);

/* �������� ��������� �� ������� ���� � ��������� */
void* CurrentPlansheet(void);
/* �������� �������� ������� �� �������� ��� ������ ������� */
long GetPlanTemplate(void *Plansheet,char *PlanTemplate);
/* �������� ��������� ���� �������� */
long GetPlanTitle(void *Plansheet,char *PlanTitle);

/* ��������/�������� ������/������� �������� */
long GetPlanRoof(void *Plansheet);
long GetPlanSole(void *Plansheet);
void SetPlanRoof(void *Plansheet,long Roof);
void SetPlanSole(void *Plansheet,long Sole);

/* �������� ������� ����� �������� */
long GetPlanHandle(void *Plansheet);
/* ���������� ������� ����� �������� */
void SetPlanHandle(void *Plansheet,long Handle);
/* �������� ����� �������� � �������� */
long GetPlanCount(void *Plansheet);
/* �������� ������ ���� �������� �������� */
void* GetPlanList(void *Plansheet);
void* GetPlanListX(void *Plansheet);
/* �������� ����� ���������� �������� � �������� */
long GetPlanActiveCount(void *Plansheet);
/* �������� ������ ���������� �������� �������� */
void* GetPlanActiveList(void *Plansheet);
/* �������� ������� ������� �� �������� */
long GetPlanDepth(void *Plansheet);
/* ���������� ������� ������� �� �������� */
void SetPlanDepth(void *Plansheet, long Depth);
/* �������� ������� ������� �� ������� */
long GetPlanScale(void *Plansheet);
/* ���������� ������� �� ������� */
void SetPlanScale(void *Plansheet,long Scale);
/* �������� ������ �������� */
long GetPlanWidth(void *Plansheet);
/* ���������� ������ �������� */
void SetPlanWidth(void *Plansheet,long Width);
/* �������� ����� ���������� ��������. �������� ��������� Index.
0 - ���� ���� ��������
1 - ���� ��������� ����� �� ��������
2 - ���� ���������� ��������
3 - ���� ����� ������������� �� ������
4 - ���� ������� �� �������
*/
unsigned char GetPlanColor(long Index);
/*  ���������� ����� ���������� ��������. �������� ��������� Index ����� ��. */
void SetPlanColor(long Index,unsigned char Color);
/* �������� �������� ������� ������� */
void GetWorkSpace(void *Plansheet,char *WorkSpace);
/* ����� �� ����� �������� */
LongBoolean HeaderState(void *Plansheet);

/* ��������/�������� ����� �������� */
void ShowHeader(void *Plansheet);
void HideHeader(void *Plansheet);

/* ������������ ������� */
void DrawPlansheet(void *Plansheet);
/* �������� ����� �������� ���������� ���� */
long ObjectCount(void *Plansheet,long Mode);
/* �������� ������ �������� ���������� ���� */
void* ObjectList(void *Plansheet,long Mode);
/* �������� ����� �������� �������� ���������� ���� */
long ActiveCount(void *Plansheet,long Mode);
/* �������� ������ �������� �������� ���������� ���� */
void* ActiveList(void *Plansheet,long Mode);

/* �������� ���������� �������� �������� ��������� ���� */
long StrictObjectCount(void *Plansheet, long AWSType);
/* �������� ������ �������� �������� ��������� ���� */
void* StrictObjectList(void *Plansheet, long AWSType);
/* �������� ���������� ���������� �������� �������� ��������� ���� */
long StrictActiveCount(void *Plansheet, long AWSType);
/* �������� ������ ���������� �������� �������� ��������� ���� */
void* StrictActiveList(void *Plansheet, long AWSType);

/* �������� ������ � ������� */
void InsertObject(void *Plansheet,void *View);
/* ������������ ������ */
void RedrawObject(void *Plansheet,void *View);
/* ������������ ������ � ������ XOR */
void RedrawObjectXor(void *Plansheet,void *View);
/* ������� ������ �� �������� */
void DeleteObject(void *Plansheet,void *View);
/* ��������� ��������� �������� */
void SaveState(void *Plansheet);
/* ������������ ��������� �������� */
void RestoreState(void *Plansheet);
/* �������� ������ ��������� �������� ����� */
void ClearState(void *Plansheet,long Mask);
/* ���������� ������ ��������� �������� ����� */
void SetupState(void *Plansheet,long Mask);
/* ��������� ���� � ��������� ������ */
LongBoolean ExecuteWindow(void *Plansheet);
/* �������� ��������� ������� � ����������� */
void PointTable(void *Plansheet,OType *Handle);
/* �������� ��������� ������� � ����������� */
void InterTable(void *Plansheet,OType *Handle);
/* ������������ ������� */
void RedrawObjects(void *Plansheet);
/* ��������� �������������� ����� �������� (������� � �������) �� RedrawObject */
void DisableHeaderRedraw(void);
/* ��������� �������������� ����� �������� (������� � �������) �� RedrawObject */
void EnableHeaderRedraw(void);

/* ����������� ���� (����� ����� ������� �� ������) */
long RegisterPrimeWindow(HWND H, const char* PrimeName);
/* �� ��, �� � �������� � ����������� ������� ������ */
long RegisterPrimeWindowAt(HWND H, const char* PrimeName, long Number);
/* ������ ����������� ���� */
long UnregisterPrimeWindow(HWND H);

/* �������� ������ �� ������� �������������� ������� */
void* CurrentTower(void *Plansheet);
/* �������� ������ �� ������� �������������� ������ */
void* CurrentCurve(void *Plansheet);
/* �������� ������� ����� ��������� ������ */
long CurveMode(void *Plansheet);

/* �������� ����� ������ */
long GetReportHandle(void *Plansheet);
/* ���������� ����� ������ */
void SetReportHandle(void *Plansheet,long Handle);
/* �������� ����� �������� � ������ */
long GetReportCount(void *Plansheet);
/* �������� ����� �������� ������ ���������� ���� */
long FrameCount(void *Plansheet,long Mode);
/* �������� ������ �������� ������ ���������� ���� */
void* FrameList(void *Plansheet,long Mode);
/* �������� ����� �������� �������� ������ ���������� ���� */
long ActiveFramesCount(void *Plansheet,long Mode);
/* �������� ������ �������� �������� ������ ���������� ���� */
void* ActiveFramesList(void *Plansheet,long Mode);
/* �������� ����� �������� ������� ���������� ���� */
long FooterFrameCount(void *Plansheet, long Mode);
/* �������� ������ �������� ������� ���������� ���� */
void* FooterFrameList(void *Plansheet, long Mode);
/* �������� ����� �������� �������� ������� ���������� ���� */
long ActiveFooterFramesCount(void *Plansheet, long Mode);
/* �������� ������ �������� �������� ������� ���������� ���� */
void* ActiveFooterFramesList(void *Plansheet, long Mode);
/* �������� ����� ������ � ����� */
void InsertFrames(void *Plansheet,void *Frame);
/* ������� ������ �� ������ */
void DeleteFrames(void *Plansheet,void *Frame);
/* ���������� ������ ��� ������� */
void SetLeftCurve(void *Plansheet,void *Curve);
void SetRightCurve(void *Plansheet,void *Curve);

/* ������������ �� ������ */
LongBoolean TrackData(void *Plansheet,long Mode);
/* ���������� ������ ����������� ���������� ��� ������������ */
void SetTrackFormat(void *Plansheet,const char *S);
/* ���������� ��������� ������������ */
void SetTrackRoof(void *Plansheet,long Roof);
void SetTrackSole(void *Plansheet,long Sole);
/* ���������� ��������� ��������� ������������ */
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

/* ���������� Callback-������� ��� ��������� ������ �� �������� ������������ */
long SetTrackUserValueCallback(void *lpPlansheet, long dwIndex,
  TTrackUserValueFunc lpfnTrackUserValueCallback, void *dwCookie);
/* ���������� Callback-������� ��� ��������� ����� �� ����� ������������ */
long SetTrackUserStrCallback(void *lpPlansheet, long dwIndex,
  TTrackUserStringFunc lpfnTrackUserStrCallback, void *dwCookie);
/* �������� �������������� ��������� ������������ */
long GetTrackDepth(void *Plansheet);
long GetTrackStart(void *Plansheet);
/* �������� �������� ������������ */
float GetTrackValue(void *Plansheet);
/* �������� ���������������� �������� ������������ */
double GetTrackUserValue(void *lpPlansheet, long dwIndex);
/* �������� ���������������� ������ ������������ */
long GetTrackUserString(void *lpPlansheet, long dwIndex,
  void *lpBuffer, long dwBufferSize);

/* ������ � ����������� ������ �������� */
/* �������� ���������� ���������� ������ �������� */
long GetPrintIntervalsCount(void* Plansheet);
/* �������� �������� ������ � ������� Index, 0 <= Index < GetPrintIntervalsCount */
LongBoolean GetPrintInterval(void* Plansheet, long Index, TPrintInterval* Interval);
/* ���������� �������� ������ � ������� Index, 0 <= Index < GetPrintIntervalsCount */
LongBoolean SetPrintInterval(void* Plansheet, long Index, const TPrintInterval* Interval);
/* �������� (� ����� ������) ����� �������� ������ */
LongBoolean AddPrintInterval(void* Plansheet, const TPrintInterval* Interval);
/* �������� ����� �������� ������ � ������� Index */
LongBoolean AddPrintIntervalAt(void* Plansheet, long Index, const TPrintInterval* Interval);
/* ������� �������� ������ � ������� Index */
LongBoolean DeletePrintInterval(void* Plansheet, long Index);
/* ������� ��� ��������� ������ �������� */
LongBoolean DeleteAllPrintIntervals(void* Plansheet);

/* �� ������� ������ � ������� ���������� ���������� ������� */
float AbsDepthValue(void* Tower, long Depth);
/* �� ������� ������ � ���������� ������� ���������� ������� */
long GetDepthByAbsDepth(void *Tower, float AbsDepth);

/* ���������� ������ ���������������� ������ �� ����� Min � �� ����� Max
���� ��� ���������������� ������, �� ������������� � ������������ */
void* ActiveCurves(long Min,long Max,const char *Title);
void* ActiveDViews(long Min,long Max,const char *Title);
void* ActivePlastTowers(long Min,long Max,const char *Title);
void* ActiveTowers(long Min,long Max,const char *Title);
void* ActiveText(long Min,long Max,const char *Title);

/* �������� ������ �� ����� ����, ���� � �������� ������������ ����� ������ */
void* GetOneCurve(const char *Name,const char *Value);
/* �������� ������ �� ����� �� ��������, ���� � ���� ������������ ����� ������ */
void* GetOneCurveByName(const char *Value);

/* �������� ����������� ������� �� ����� */
void* GetPlastTower(const char *Name);

/* ����� ������� �� ����� ��� �� �������� �������� */
long FindPlanObject(void *lpPlansheet, const char *lpszConditions,
  void *lpTestObject, long dwFindFlags, long dwObjMask, void **lplpFound,
  void *lpFoundObjs, void *lpReserved);
/* ����� ������� �������� ������ �� ��������� ������ � �������� ����� ������� */
long FindCurveLoadCondition(const char *lpSheetTemplateFileName,
  const char *lpCurveMethodName, long FindFlags,
  char *lpLoadCondition, long dwLoadConditionSize,
  void *lpReserved);
/* �������� ������, ��������, � ������� ������ ������������� ������� */
LongBoolean InsertOrReplaceObject(void *Plansheet, void **lplpObj,
  long Flags, long *lpErrCode, void *Reserved);
/* ���������� ���� ���������� ������������� ������ */
void* SelectCurve(const char *Title);
/* ���������� ������ ��� ����������� �������, ���������� ������������� */
void* SelectDView(const char *Title);
void* SelectPlastTower(const char *Title);
void* SelectTower(const char *Title);
void* SelectText(const char *Title);
/* ���������� ���� ���������� ������������� ��������� ������ */
void* SelectTwoDCurve(const char *Prompt);
long GetCurveH(void *P,OType *ObjHandle,OType *ArrHandle,unsigned short *Column);
void GetCurveName(void *Curve, char *CurveName);
/* ������������� ����� ����� ������ */
void* SelectOneCurve(const char *Prompt);
/* ���������� ���� ���������� ������������� ������ �������� */
void* SelectObject(const char *Prompt);
/* ���������� ���� ���������� ������������� ������ �������� ���������� ���� */
void* SelectObjectByType(const char *Prompt, long AWSType);

/* �������� ������� ������ � �������� */
LongBoolean CheckCurves(void);

LongBoolean SelectDepth(long *Depth,const char *Title,void *Curve = NULL);
LongBoolean SelectInter(long *Roof,long *Sole,const char *Title,void *Curve);
LongBoolean SelectShift(long *Delta,const char *Title);
LongBoolean SelectValue(long Start,float Minimum,float Scale,float *Value,const char *Title);
LongBoolean SelectStart(long *Start,const char *Title);
LongBoolean SelectStartWidth(long *Start,long *Width,const char *Title);

/* ���������� ����������� �������� ��� ������ ������ */
void MinInter(void *List,long *Roof,long *Sole);

/* ���������� ������������ �������� ��� ������ ������ */
void MaxInter(void *List,long *Roof,long *Sole);
/* ���������� ������������ �������� ������ � ��������� ����� min/���
� ����������� �� Num ������. Option = 0-min, 1-max  */
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

/* �������� ������ ������ � ���� ��� �������� ������ */
void* GetWSGroup(void *Curve);
/* �������� ������ ������ � �������� ��� �������� ������ */
void* GetPlanGroup(void *Curve);

long CrvTransform(OType DataHandle,OType ArrHandle,unsigned char Column, void *List,
 TStartTransform StartP,TCrvTransform DoP,TGetTransform GetP,PProcess Ind);

/* �������� ������ ����� ������ �� ��������� */
LongBoolean GetDefaultTemplate(TViewCurveRec *Rec);
/* ����� ���� ������� �� ������. "" = ��� �������, " " = ������� ��� ������ */
/* ����� ���� ������� �� ������.
   FilClass:
     "" = ��� �������;
     " " = ������� ��� ������
   lpFilName (���������):
     "" = ������� �� �������;
     ����� - ��� ������� */
long SelectFilName(const char *lpTitle, const char *lpPrompt, const char *lpFilClass, char *lpFilName, long nFilNameSize, long *lpnCode);
/* ����� ������ �������.
   ���������:
     '' = ����� �� ������
     ' ' = ������ ������ �����
     '*' = ������� ��� ������ */
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

/* �������� �������� �� ������� (.VPT ��� .ST) � WS-�����.
  ���� lpTemplateFileName == "", �� ������ � ������������.
  ���� lpTemplateFileName == " ", �� �� ������� �������.
  lpWSFileName �� ������ ������������
 */
void* CreateNewPlansheet(const char *lpTemplateFileName, const char *lpWSFileName);

/* ������������ �����������������(��) �����(��)
  ConfigType == cfgXXXX
  Flags && cfgmskMethod:
    cfgmtdFile - �������� �� ����� (��������), ���������� ���������� FileName
    � ������� ����������� - ���� �� �����������
  ���������:
    0 - ���������� ����������
    1 - ���� �� ���� �� ������ �� ������������ */
long ReloadConfig(long ConfigType, long Flags, const char *lpFileName, OType hData);

/* �������� ������ �������� ���������. ������ ��-� � ������ - �������� ������� */
void* GetSheetsList(void);
/* �������� ������ �������� ����. ������ ��-� � ������ - �������� ���� */
void* GetSheetWindowsList(void);
/* �������� ������ ���������, ����������� � ���� Window */
void* GetSheetsByWindow(void *Window);
/* �������� ���� �� ��������, ������� � �� ���������� */
void* GetWindowBySheet(void *Sheet);
/* �������������� ������� */
LongBoolean ActivatePlansheet(void *Plansheet);

/* �������� ��� � ������ �������� ������� */
long GetBuildType(long *lpBuildSubType);
/* �������� ���������� �� ����� HASP */
LongBoolean GetHASPInfo(THaspInfo *lpInfo);

/* ������� ��� ������ � ��������� �������� */

/* ���������� ������� � �������� �������� */
LongBoolean ApplyConds(char *lpDestCondStr, long nDestCondStrSize,
  const char *lpSrcCondStr, const char *lpCurveName,
  TConflictFieldsAction *lpConflictAction);
/* ��������, ������������� �� ������ ������ �������� �������� � ������� */
LongBoolean TestData(OType hObj, const char *lpAValueName, const char *lpAUnitName,
  const char *lpAnArrayName, const char *lpTestConds, const char *lpFilter,
  LongBoolean EmptyValid, OType *lphArr, long *lpColumn);
/* ���������� ��������� ������� �������, ��������������� ��������� ������� TestData  */
LongBoolean GetLastTestDataColumns(TColumnsSet *lpColumns);

/* ����� ������ ��� ������ (��������, �������������) �� ��������
  �������� �������� � ������� */
long SelectCurveDataByFilter(void *lpTablesList, const char *lpCurveName,
  const char *lpFilter, char *lpAddFilter, long nAddFilterSize,
  OType *lphObj, OType *lphArr, long *lpColNumber, long *lpRowNumber, long Flags);

/* �������� ����� ������ ��������. ���� ������������ ������ ��������
  lpdwFlags1, � ���� ������������ ����, ������������, �������� �� �����
  ���� ��� ����� ���� �������� ����� �� ��������. ����� ���� ��� ������� ����
  ������������ ���������� wssi1XXXX, ��. ����. ��������,
  ���� ((*lpdwFlags1) & (1 << wssi1TowerLnGrid)) != 0, �� ����� ��������
  ��������������� �����, ����� - ��� */
long GetSheetSelectMode(void *lpPlansheet,
       long *lpdwFlags0, long *lpdwFlags1, long *lpdwFlags2, long *lpdwFlags3,
       long *lpdwFlags4, long *lpdwFlags5, long *lpdwFlags6, long *lpdwFlags7,
       long *lpdwFlags8);
/* ���������� ����� ������ �������. ��. �������� ������� GetSheetSelectMode */
long SetSheetSelectMode(void *lpPlansheet,
       long dwFlags0, long dwFlags1, long dwFlags2, long dwFlags3,
       long dwFlags4, long dwFlags5, long dwFlags6, long dwFlags7,
       long dwFlags8);
void SetTopCaption(const char *lpCaption);

/* ���������/��������� ��������� ������ �� ����� (������ ��� - ��. ��������� ppnXXXX) */
long GetPrimeParam(const char *ParamName, void *lpBuffer, long cbBufSize);
long SetPrimeParam(const char *ParamName, void *lpBuffer, long cbBufSize);

/* ��������� �������� ��������� ������ �� ������� � ������ (� ���.��.)
  ���� lpfBuffer == NULL, �� ������������ ����� ��������� � ������ */
long GetTwoDValuesByDepth(void *TwoDCurve, long dwDepth,
       long nChannelIndex, float *lpfBuffer,
       long dwBufLenInFloats, LongBoolean *lplbValidRow);

/* ��������� ��������� ������ ������ ��� ��������� ������, ����������� ��������
  GetTwoDValuesByDepth. ���� lpBuffer == NULL, ������������ ������ ������ */
long GetTwoDLastRowHeader(void *TwoDCurve, void *lpBuffer,
       long dwBufSize, long *lpdwBitIndex);
/* ��������� ��������� ������ ������ ��� ��������� ������, ����������� ��������
  GetTwoDValuesByDepth. ���� lpBuffer == NULL, ������������ ������ ������ */
long GetTwoDLastChannelHeader(void *TwoDCurve, void *lpBuffer,
       long dwBufSize, long *lpdwBitIndex);

/* ��������� ��������� ����� ������.
  ���� lpBuffer == NULL, ������������ ������ ������ */
long GetTwoDHeader(void *TwoDCurve, void *lpBuffer, long dwBufSize);
/* ��������� ������� ������ ��������� ������ */
LongBoolean GetTwoDDepthIndex(void *TwoDCrv, TPrimeDepthIndex *Index);

/* ���������� ������ � ������ ��� ������� SelectCurves_1 */
long AddCurveDataToList(void *CurvesList,
       const PTableCurveDataRec Data);
/* ��������� ������ �� ������ ��� ������� SelectCurves_1 */
LongBoolean GetCurveDataFromList(void *CurvesList, long Index,
       PTableCurveDataRec Data);
/* ����� ������. Flags = 2: ������� ������� ��� ������.
  CurvesList ������ ���� ������ �������� InitUnsortList */
long SelectCurves_1(OType hWS, const char *TableName, long Flags,
       void *CurvesList);
/* ������������� �������� �������� ������ */
LongBoolean SelectCurveValue(void *Curve, float *Value, const char *Title);
/* ���������� �������� ������ �� �����������: ����� � 0.1 �� � �������, ��.
  ������� �����, �.�. �� �������� �������� ������ �� ���� �������
  ������ ����� �����! */
double __stdcall TrackCurveValueFunc(void *Curve, long AStart, long ADepth);

/* ���������� CALLBACK */
long SetPrimeCommonCallback(long dwEventType, // pevXXXX
       TPrimeCommonCallbackFunc lpFunc, void *dwCookie, long dwCallbackFlags,
       long dwPriority, void *lpObject, long dwObjectType,
       long dwObjectSubType, void *lpInput, long dwInputSize,
       const char *LibraryName, const char *FuncName);
/* ������� CALLBACK */
LongBoolean DeletePrimeCallback(long dwHandle);
/* �������� Handl'� CALLBACK'� */
LongBoolean IsPrimeCallback(long dwHandle);
/* ������� ��� CALLBACK� ��� �� ������������ */
LongBoolean DeletePrimeCallbacks(HINSTANCE H, long dwFlags);
/* ����������-�-������� ������ �������� �� ������ ������ �������� */
LongBoolean PlanObjDragDrop(void *lpObjectToDrop, void *lpDropTemplate, long dwFlags, void *lpReserved);
/* ��������� ������� �� ����������, PRM, PRD, PRW, PRG ��� BAS-����� ���
   ���������� ������� */
long PrimeExecuteFunction(const char *lpLibraryName, const char *lpFuncName,
       void *lpPlansheet, void *lpUser, void *lpReserved);

/* �������� ����������� ��� ������ ������� Tower � �������� Index.
  Flags = slcXXXX */
long GetStandardLayerCodeByIndex(void *Tower, long Index,
           char *Code, long CodeMaxLen, long Flags);
/* ���������� ����������� ��� ������ ������� Tower � �������� Index.
  Flags = slcXXXX */
long SetStandardLayerCodeByIndex(void *Tower, long Index,
           const char *Code, long Flags);
/* �������� ������ ������ �� ������� */
long GetLayerIndex(void *Tower, long Depth);

/* ��������� ������� �������, ������� � �������� */
long GetTarget(char *lpRegion, long nRegionLen, char *lpField, long nFieldLen,
           char *lpWell, long nWellLen, void *lpOtherData, long nOtherDataLen);
/* ��������� ������� �������, ������� � �������� */
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

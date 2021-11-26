/***************************************************************************\
*                                                                           *
* Ñèñòåìà èíôîðìàöèîííîãî îáåñïå÷åíèÿ ãåîôèçè÷åñêèõ èññëåäîâàíèé ñêâàæèí    *
*   "ÏÐÀÉÌ" äëÿ Windows                                                     *
* Èíòåðôåéñ ê âèçóàëüíîìó èíòåðïðåòàòîðó                                    *
* ßçûê: C++                                                                 *
* Âåðñèÿ: 4.06.12                                                           *
* (C) ÍÏÔ ÃåîÒÝÊ, 1999, 2007                                                *
*                                                                           *
\***************************************************************************/

#if _MSC_VER > 1000
  #pragma once
#else
#endif // _MSC_VER > 1000

#ifndef NOVCL
#ifdef __BORLANDC__
  // Borland C++ or Builder
  #if __BCPLUSPLUS__ > 0x520
	  // Builder
	  #include <vcl.h>
  #endif
#endif
#endif // NOVCL

#include <windows.h>
#include "dsapi.h"
#include "dsext.h"
#include "primeapi.h"

/* Èìÿ ôàéëà âíåøíåãî ìîäóëÿ */
#define PRIME32DLL "Prime32.exe"
HINSTANCE hDLL_PRIME32 = NULL;

extern char *SUserCreatedReper = "User-ñreated";

extern char *tnPlansheet  = "ÏËÀÍØÅÒ";
extern char *tnPointTable = "ÏÐÈÌÈÒÈÂÛ_ÒÎ×ÊÈ";
extern char *tnInterTable = "ÏÐÈÌÈÒÈÂÛ_ÈÍÒÅÐÂÀËÀ";
extern char *tnCurveTable = "ÔÎÐÌÀÒÛ_ÊÐÈÂÛÕ";
extern char *tnLitolTable = "ÒÀÁËÈÖÀ_ÈÍÒÅÐÂÀËÎÂ";
extern char *fnMinValue = "ÌÈÍÈÌÓÌ";
extern char *fnMaxValue = "ÌÀÊÑÈÌÓÌ";
extern char *fnStrValue = "ÍÀÇÂÀÍÈÅ";
extern char *fnBMPIndex = "ÊÎÄ_ÐÀÑÒÐÀ";
extern char *fnBMPName   = "ÈÌß_ÐÀÑÒÐÀ";
extern char *fnBMPWidth  = "ØÈÐÈÍÀ";
extern char *fnBMPHeigth = "ÂÛÑÎÒÀ";
extern char *fnBMPInvers = "ÈÍÂÅÐÑÍÎ";
extern char *fnBMPColor  = "ÖÂÅÒ";

extern char *inPerfProekt  = "ÏÅÐÔÎÐÀÖÈß_ÏÐÎÅÊÒÍÀß";
extern char *inPerfFact    = "ÏÅÐÔÎÐÀÖÈß_ÔÀÊÒÈ×ÅÑÊ";
extern char *inIntSostPrit = "ÈÍÒÅÐÂ_È_ÑÎÑÒ_ÏÐÈÒ";
extern char *inPrinInter   = "ÏÐÈÍÈÌÀÞÙÈÉ_ÈÍÒÅÐÂÀË";
extern char *inMoveFluid   = "ÄÂ_ÆÈÄÊ_ÏÎ_ÍÅÏÅÐÔ_ÏË";
extern char *inMPlPDown    = "ÌÅÆÏË_ÏÅÐÅÒÎÊ_ÑÂÅÐÕÓ";
extern char *inMPlPUp      = "ÌÅÆÏË_ÏÅÐÅÒÎÊ_ÑÍÈÇÓ";
extern char *inPeretDown   = "ÏÅÐÅÒ_ÎÑÒ_ÑÊÂ_ÑÂÅÐÕÓ";
extern char *inPeretUp     = "ÏÅÐÅÒ_ÎÑÒ_ÑÊÂ_ÑÍÈÇÓ";
extern char *inZKCDown     = "ÇÊÖ_ÑÂÅÐÕÓ";
extern char *inZKCUp       = "ÇÊÖ_ÑÍÈÇÓ";
extern char *inPatrubok    = "ÏÀÒÐÓÁÎÊ_Â_ÎÁÑ_ÊÎË";
extern char *inFilterPaker = "ÔÈËÜÒÐ_ÏÀÊÅÐÀ";

extern char *pnNegermCol  = "ÍÅÃÅÐÌÅÒÈ×_ÊÎËÎÍÍÛ";
extern char *pnNegermNKT  = "ÍÅÃÅÐÌÅÒÈ×ÍÎÑÒÜ_ÍÊÒ";
extern char *pnIskustZab  = "ÈÑÊÓÑÑÒÂÅÍÍÛÉ_ÇÀÁÎÉ";
extern char *pnMoveFluid  = "ÄÂÈÆÅÍÈÅ_ÆÈÄÊÎÑÒÈ";
extern char *pnPakerPlace = "ÌÅÑÒÎÏÎËÎÆ_ÏÀÊÅÐÀ";
extern char *pnBaschmExpl = "ÁÀØÌÀÊ_ÝÊÑÏ_ÊÎËÎÍÍÛ";
extern char *pnBaschmTech = "ÁÀØÌÀÊ_ÒÅÕÍ_ÊÎËÎÍÍÛ";
extern char *pnBaschmStop = "ÁÀØÌÀÊ_ÑÒÎÏ_ÊÎËÎÍÍÛ";
extern char *pnBaschmObsd = "ÁÀØÌÀÊ_ÎÁÑÀÄ_ÊÎËÎÍÍÛ";
extern char *pnBaschmNapr = "ÁÀØÌÀÊ_ÍÀÏÐ_ÊÎËÎÍÍÛ";
extern char *pnBaschmCond = "ÁÀØÌÀÊ_ÊÎÍÄÓÊÒÎÐÀ";
extern char *pnBaschmNKT  = "ÁÀØÌÀÊ_ÍÊÒ";

extern char *pnUstDoubleC = "ÓÑÒ_ÄÂÓÑÒ_ÖÅÌÅÍÒ";
extern char *pnStopRound  = "ÑÒÎÏ_ÊÎËÜÖÎ";

extern char *pnCementLev  = "ÂÛÑÎÒÀ_ÏÎÄÚÅÌÀ_ÖÅÌÅÍ";
extern char *pnNKTKlapan  = "ÊËÀÏÀÍ_Â_ÍÊÒ";
extern char *pnRNKTKlapan = "ÐÀÁÎÒ_ÊËÀÏÀÍ_Â_ÍÊÒ";
extern char *pnDynamycLev = "ÄÈÍÀÌÈ×ÅÑÊÈÉ_ÓÐÎÂÅÍÜ";
extern char *pnGVR        = "ÃÀÇÎÂÎÄÎÐÀÇÄÅË";
extern char *pnGNR        = "ÃÀÇÎÍÅÔÒÅÐÀÇÄÅË";
extern char *pnNVR        = "ÍÅÔÒÅÂÎÄÎÐÀÇÄÅË";
extern char *pnGAS        = "ÍÀ×ÀËÎ_ÐÀÇÃÀÇÈÐÎÂÀÍ";
extern char *pnNAS        = "ÌÅÑÒÎÏÎËÎÆ_ÍÀÑÎÑÀ";
extern char *pnNASKlapan  = "ÊËÀÏÀÍ_ÍÀÑÎÑÀ";
extern char *pnCentrFonar = "ÖÅÍÒÐÈÐÓÞÙÈÉ_ÔÎÍÀÐÜ";

extern char *fnPointDepth = "ÃËÓÁÈÍÀ";
extern char *fnGerm       = "ÍÅÃÅÐÌÅÒÈ×ÍÎÑÒÜ";
extern char *fnGermOk     = "ÍÅÃÅÐÌ_ÍÅÒ";
extern char *fnGermDown   = "ÍÅÃÅÐÌ_ÑÂÅÐÕÓ";
extern char *fnGermUp     = "ÍÅÃÅÐÌ_ÑÍÈÇÓ";
extern char *fnOilDirect  = "ÍÀÏÐÀÂËÅÍÈÅ_ÄÂÈÆÅÍÈß";
extern char *fnOilOut     = "ÈÇ_ÊÎËÎÍÍÛ";
extern char *fnOilIn      = "Â_ÊÎËÎÍÍÓ";
extern char *fnOilDown    = "ÂÍÈÇ";
extern char *fnOilUp      = "ÂÂÅÐÕ";
extern char *fnOilDownIn  = "ÂÍÈÇ_È_Â_ÊÎËÎÍÍÓ";
extern char *fnOilUpIn    = "ÂÂÅÐÕ_È_Â_ÊÎËÎÍÍÓ";
extern char *fnOilOutDown = "ÈÇ_ÊÎËÎÍÍÛ_È_ÂÍÈÇ";
extern char *fnOilOutUp   = "ÈÇ_ÊÎËÎÍÍÛ_È_ÂÂÅÐÕ";
extern char *fnInterRoof  = "ÊÐÎÂËß";
extern char *fnInterSole  = "ÏÎÄÎØÂÀ";
extern char *fnWaterCont  = "ÎÁÂÎÄÍÅÍÍÎÑÒÜ";
extern char *fnGasContent = "ÃÀÇÎÂÛÉ_ÔÀÊÒÎÐ";
extern char *fnTimeStamp  = "ÂÐÅÌß";

extern char *fnMethodName = "ÌÅÒÎÄ_ÃÈÑ";
extern char *fnMethodUnit = "ÅÄÈÍÈÖÀ_ÈÇÌÅÐÅÍÈß";
extern char *fnCurveRoof  = "ÊÐÎÂËß_ÊÐÈÂÎÉ_ÃÈÑ";
extern char *fnCurveSole  = "ÏÎÄÎØÂÀ_ÊÐÈÂÎÉ_ÃÈÑ";
extern char *fnCurveStep  = "ØÀÃ_ÄÈÑÊÐÅÒ_ÊÐÈÂÎÉ";
extern char *fnCurveValue = "ÄÀÍÍÛÅ_ÊÐÈÂÎÉ";
extern char *fnBlankValue = "ÎÒÑÓÒÑÒÂÈÅ_ÄÀÍÍÛÕ";
extern char *fnVersion    = "ÍÎÌÅÐ_ÂÅÐÑÈÈ";
extern char *fnDepthShift = "ÑÓÌÌÀÐÍÛÉ_ÑÄÂÈÃ";
extern char *fnDepthValue = "ÃËÓÁÈÍÀ";

extern char *tnProject = "PROJECT";
extern char *fnProjectShortName = "ÊÎÐÎÒÊÎÅ_ÈÌß";
extern char *fnProjectDesc = "ÎÏÈÑÀÍÈÅ";
extern char *anVPTs = "ØÀÁËÎÍÛ_ÏËÀÍØÅÒÎÂ";

/* ======================================================================= */
extern const char *pefBuiltInPrime = ""; /* Âûïîëíèòü âñòðîåííóþ ôóíêöèþ */

/* Íàçâàíèÿ âñòðîåííûõ ôóíêöèé */
extern const char *pbfSystemExit = "Âûõîä èç ñèñòåìû";
extern const char *pbfEditToolbars = "Íàñòðîéêà ïàíåëåé";
extern const char *pbfEditMenu = "Íàñòðîéêà ìåíþ";
extern const char *pbfCreatePlansheet = "Ñîçäàòü ïëàíøåò";
extern const char *pbfOpenPlansheet = "Îòêðûòü ïëàíøåò";
extern const char *pbfSavePlansheet = "Ñîõðàíèòü ïëàíøåò";
extern const char *pbfSavePlansheetAs = "Ñîõðàíèòü ïëàíøåò êàê...";
extern const char *pbfSavePlansheetAsTemplate = "Ñîõðàíèòü êàê øàáëîí";
extern const char *pbfPrintPlansheet = "Ïå÷àòü ïëàíøåòà";
extern const char *pbfEditDefaults = "Íàñòðîéêà óìîë÷àíèé";
extern const char *pbfEditPrintDevices = "Íàñòðîéêà óñòðîéñòâ ïå÷àòè";
extern const char *pbfEditPlansheetParams = "Ïàðàìåòðû ïëàíøåòà";
extern const char *pbfEditLegendParams = "Ïàðàìåòðû ëåãåíäû";
extern const char *pbfInsertObject = "Âñòàâêà îáúåêòà â ïëàíøåò";
extern const char *pbfInsertCurvesFromAnotherWS = "Âñòàâêà êðèâûõ èç WS";
extern const char *pbfInsertPoint = "Ïðèìèòèâ òî÷êè";
extern const char *pbfInsertInter = "Ïðèìèòèâ èíòåðâàëà";
extern const char *pbfInsertEmptyFrame = "Ïóñòàÿ ðàìêà";
extern const char *pbfInsertTextFrame = "Ðàìêà ñ òåêñòîì";
extern const char *pbfInsertTableFrame = "Ðàìêà ñ òàáëèöåé";
extern const char *pbfInsertPictureFrame = "Ðàìêà ñ ðèñóíêîì";
extern const char *pbfInsertSampleLineFrame = "Îáðàçåö ëèíèè êðèâîé";
extern const char *pbfPlansheetObjectsList = "Ñïèñîê îáúåêòîâ ïëàíøåòà";
extern const char *pbfDeleteActivatedObjects = "Óäàëèòü âûäåëåííûå îáúåêòû";
extern const char *pbfExitExecuteWindow = "Âîçâðàò";
extern const char *pbfPrimeHelp = "Âûçîâ ñïðàâêè";
extern const char *pbfPrimeHelpSearch = "Ïîèñê â ñïðàâî÷íîé ñèñòåìå";
extern const char *pbfPrimeAbout = "Ñïðàâêà î ïðîãðàììå";
extern const char *pbfChangePlansheetScale = "Ìàñøòàá ïðîñìîòðà ïëàíøåòà";
extern const char *pbfSetPlansheetAutoScale = "Ìàñøòàá ïðîñìîòðà - ïî øèðèíå";
extern const char *pbfSetPlansheetNoScale = "Ìàñøòàá ïðîñìîòðà - 1:1";
extern const char *pbfClosePlansheet = "Çàêðûòü ïëàíøåò";
extern const char *pbfTableDialog = "Äèàëîã òàáëèöû";
extern const char *pbfTableDialogOld = "Äèàëîã ñòðîêè";
extern const char *pbfResDialog = "Äèàëîã RES";
extern const char *pbfCreateDataFromRes = "Ñîçäàíèå äàííûõ èç ðåñóðñà";
extern const char *pbfSelectNextWindow = "Ñëåäóþùåå";
extern const char *pbfSelectPrevWindow = "Ïðåäûäóùåå";
extern const char *pbfInsertPlasts = "Âñòàâêà ïðîïëàñòêîâ";
extern const char *pbfDeletePlasts = "Óäàëåíèå ïðîïëàñòêîâ";
extern const char *pbfDeletePlastsByOne = "Óäàëåíèå ïðîïëàñòêîâ ïî îäíîìó";
extern const char *pbfSelectWellV4 = "Âûáîð ñêâàæèíû";
extern const char *pbfEditLoadConditionFilter = "Ôèëüòð çàãðóçêè êðèâûõ";
extern const char *pbfInsertPlastsWithClass = "Âñòàâêà ïðîïëàñòêîâ 2";
extern const char *pbfInsertEmptyTower = "Âñòàâêà ïóñòîé êîëîíêè";
extern const char *pbfInsertDepthTower = "Âñòàâêà êîëîíêè ãëóáèí";
extern const char *pbfInsertPlastTower = "Âñòàâêà ïîïëàñòîâîé êîëîíêè";
extern const char *pbfInsertLitholTower = "Âñòàâêà ëèòîëîãè÷åñêîé êîëîíêè";
extern const char *pbfInsertStratTower = "Âñòàâêà ñòðàòèãðàôè÷åñêîé êîëîíêè";
extern const char *pbfInsertLineGridTower = "Âñòàâêà ëèíåéíîé ñåòêè";
extern const char *pbfInsertLogGridTower = "Âñòàâêà ëîãàðèôìè÷åñêîé ñåòêè";
extern const char *pbfInsetCurves = "Âñòàâêà êðèâûõ";
extern const char *pbfInsertNote = "Âñòàâêà íàäïèñè";
extern const char *pbfInsertChord = "Âñòàâêà ðåïåðà";
extern const char *pbfInsertFiller = "Âñòàâêà çàëèâêè";
extern const char *pbfInsertPicture = "Âñòàâêà ðèñóíêà";
extern const char *pbfInsertScale = "Âñòàâêà øêàëû";
extern const char *pbfInsertTwoDCurve = "Âñòàâêà äâóìåðíîé êðèâîé";
extern const char *pbfInsertHandleInter = "Âñòàâêà èíòåðâàëà îáðàáîòêè";
extern const char *pbfCut = "Âûðåçàòü";
extern const char *pbfCopy = "Êîïèðîâàòü";
extern const char *pbfPaste = "Âñòàâèòü";
extern const char *pbfSelectAll = "Âûäåëèòü âñå";
extern const char *pbfEditGraph = "Ãðàô îáðàáîòêè";
extern const char *pbfShowSaxBasic = "Îòêðûòü SBasic";
extern const char *pbfRunSaxBasicMacro = "Âûïîëíèòü ìàêðîñ";
extern const char *pbfCorrectPlasts = "Êîððåêòèðîâêà";
extern const char *pbfEditPlansheetHeaderOrder = "Ïîðÿäîê ýëåìåíòîâ ëèíåéêè";
extern const char *pbfWindowsTileVertical = "Îêíà ñâåðõó âíèç";
extern const char *pbfWindowsTileHorizontal = "Îêíà ñëåâà íàïðàâî";
extern const char *pbfWindowsCascade = "Îêíà êàñêàäîì";
extern const char *pbfPlansheetCurvesList = "Ñïèñîê êðèâûõ";
extern const char *pbfSavePlansheetAsArchive = "Ñîõðàíèòü â àðõèâ...";

/* ======================================================================= */
extern char *fnPlanName    = "Name";
extern char *fnPlanColor   = "FrameColor";
extern char *fnPlanWidth   = "SheetWidth";
extern char *fnPlanRoof    = "Roof";
extern char *fnPlanSole    = "Sole";
extern char *fnScaleIndex  = "ScaleIndex";
extern char *fnScaleValue  = "ScaleValue";
extern char *fnViewScaleMul= "ViewScaleMul";
extern char *fnViewScaleDiv= "ViewScaleDiv";
extern char *fnLitolTable  = "LitolTable";
extern char *fnTableFont   = "TableFont";
extern char *fnTableSize   = "TableSize";
extern char *fnTableJust   = "TableJust";
extern char *fnTableSpace  = "TableSpace";
extern char *fnLitolFont   = "LitolFont";
extern char *fnLitolSize   = "LitolSize";
extern char *fnLitolJust   = "LitolJust";
extern char *fnLitolSpace  = "LitolSpace";
extern char *fnLitolWidth  = "LitolWidth";
extern char *fnLitolHeigth = "LitolHeigth";
extern char *fnTemplateName= "Template";
extern char *fnTemplateHelp= "ShortDesc";
extern char *fnTemplateInfo= "FullDesc";
extern char *fnNameDict = "NameDict";
extern char *fnUnitDict = "UnitDict";
extern char *fnName2UnitDict = "Name2UnitDict";
extern char *fnPlanFlags = "Flags";
extern char *fnCurDepth = "CurDepth";

extern char *anPrintIntervals      = "PrintIntervals";
extern char *fnPrintIntervalRoof   = "Roof";
extern char *fnPrintIntervalSole   = "Sole";
extern char *fnPrintIntervalScale  = "Scale";
extern char *fnPrintIntervalIndent = "Indent";
extern char *fnPrintIntervalFlags  = "Flags";


extern char *fnState = "State";
extern char *fnIdentifier = "Ident";
extern char *fnOwnerIdentifier = "Owner";
extern char *fnLegendPlace = "LegendPlace";

extern char *anViewCurve = "ViewCurves";
extern char *fnCurveInfo = "CurveInfo";

extern char *anCurveStyle = "Style";
extern char *fnCurveStart   = "Start";
extern char *fnCurveWidth   = "Width";
extern char *fnCurveColor   = "Curve";
extern char *fnCurveMinimum = "Minimum";
extern char *fnCurveScale   = "Scale";
extern char *fnCurveModul   = "Modul";
extern char *fnCurvePower   = "Power";
extern char *fnCurveFlags   = "Flags";
extern char *fnCurveMHIndex = "MHIndex";
extern char *fnCurveMHValue = "MHValue";
extern char *fnCurveSHIndex = "SHIndex";
extern char *fnValueName    = "ValueName";
extern char *fnValueUnit    = "ValueUnit";

extern char *anCurveHeader = "UpLine";
extern char *fnHeaderType  = "HeaderType";
extern char *fnValueJust   = "ValueJust";
extern char *fnValueIndent = "ValueIndent";
extern char *fnValueFont   = "ValueFont";
extern char *fnValueSize   = "ValueSize";
extern char *fnValueZero   = "ValueZero";
extern char *fnValueAdds   = "ValueAdds";
extern char *fnNameFont    = "NameFont";
extern char *fnNameSize    = "NameSize";
extern char *fnUnitFont    = "UnitFont";
extern char *fnUnitSize    = "UnitSize";

extern char *fnLeftArrow  = "LeftArrow";
extern char *fnRightArrow = "RightArrow";
extern char *fnArrowSize  = "ArrowSize";

extern char *fnInterLine  = "InterLine";
extern char *fnSkipBefore = "SkipBefore";
extern char *fnSkipAfter  = "SkipAfter";

extern char *anCurveBreaks = "Reserv";
extern char *fnBreakFont        = "BreakFont";
extern char *fnBreakSize        = "BreakSize";
extern char *fnBreakZero        = "BreakZero";
extern char *fnBreakVertIndent  = "BreakVertIndent";
extern char *fnBreakVertBelow   = "BreakVertBelow";
extern char *fnBreakVertAfter   = "BreakVertAfter";
extern char *fnBreakHorizIndent = "BreakHorizIndent";
extern char *fnBreakHorizBelow  = "BreakHorizBelow";
extern char *fnBreakHorizAfter  = "BreakHorizAfter";
extern char *fnHeaderManual     = "HeaderManual";
extern char *fnHeaderLeft       = "HeaderLeft";
extern char *fnHeaderRight      = "HeaderRight";

extern char *anCurveLevels = "Levels";
extern char *fnLevelMask = "LevelMask";
extern char *fnLevel = "Level";

extern char *anCurveDepths = "Depths";
extern char *fnDepthMask = "DepthMask";
extern char *fnDepth = "Depth";

extern char *anWSAccess = "WSAccess";
extern char *fnCurveRow       = "RowNumber";
extern char *fnCurveColumn    = "ColNumber";
extern char *fnCurveArrayName = "ArrayName";
extern char *fnCurveTableName = "TablName";

extern char *anViewInter = "ViewIntervals";
extern char *anViewPoint = "ViewPoints";
extern char *fnWSHStart = "Start";
extern char *fnWSHWidth = "Width";
extern char *fnWSHColor = "Color";
extern char *fnWSHRow   = "ArrayRow";
extern char *fnWSHArray = "ArrayName";

extern char *anViewNotes = "ViewNotes";
extern char *fnNotesStart  = "Start";
extern char *fnNotesDepth  = "Depth";
extern char *fnNotesColor  = "Color";
extern char *fnNotesText   = "Text";
extern char *fnNotesLen    = "Length";
extern char *fnNotesFont   = "Font";
extern char *fnNotesSize   = "Size";
extern char *fnNotesLine   = "Line";
extern char *fnNotesHJust  = "HJust";
extern char *fnNotesVJust  = "VJust";
extern char *fnNotesUnder  = "UnderLine";
extern char *fnNotesDirect = "Direct";
extern char *fnNotesFlags   = "Flags";
extern char *fnNotesBGColor = "BGColor";

extern char *anEmptyTower = "ViewTowers";

extern char *fnTowerStart  = "Start";
extern char *fnTowerWidth  = "Width";
extern char *fnTowerColor  = "Color";
extern char *fnTowerName   = "TowerName";
extern char *fnTowerFont   = "NameFont";
extern char *fnTowerSize   = "NameSize";
extern char *fnTowerJust   = "NameJust";
extern char *fnTowerDirect = "NameDirect";
extern char *fnTowerBefore = "NameBefore";
extern char *fnTowerAfter  = "NameAfter";
extern char *fnTowerInter  = "NameInter";

extern char *anDepthTower = "ViewDepthTowers";
extern char *fnDepthTickStep  = "TickStep";
extern char *fnDepthTextPlace = "TextPlace";
extern char *fnDepthTextJust  = "TextJust";
extern char *fnDepthFontName  = "FontName";
extern char *fnDepthFontSize  = "FontSize";
extern char *fnDepthAbsDepth  = "AbsDepth";
extern char *fnDepthAbsFont   = "AbsFont";
extern char *fnDepthAbsZero   = "AbsZero";
extern char *fnDepthAbsSize   = "AbsSize";
extern char *fnDepthAbsJust   = "AbsJust";
extern char *fnDepthAbsInfo   = "AbsInfo";
extern char *fnDepthAbsRow    = "AbsRow";
extern char *fnDepthAbsCol    = "AbsCol";
extern char *fnDepthAbsTable  = "AbsTable";
extern char *fnDepthAbsArray  = "AbsArray";
extern char *fnDepthLoadCondition = "LoadCondition";

extern char *fnScale1 = "Scale1";
extern char *fnScale2 = "Scale2";
extern char *fnScale3 = "Scale3";
extern char *fnScaleTickStep1 = "Scale1DepthStep";
extern char *fnScaleTickStep2 = "Scale2DepthStep";
extern char *fnScaleTickStep3 = "Scale3DepthStep";
extern char *fnScaleTickFreq1 = "Scale1DepthFreq";
extern char *fnScaleTickFreq2 = "Scale2DepthFreq";
extern char *fnScaleTickFreq3 = "Scale3DepthFreq";
extern char *fnScaleReserved1 = "Scale1Reserved";
extern char *fnScaleReserved2 = "Scale2Reserved";
extern char *fnScaleReserved3 = "Scale3Reserved";

extern char *anInterTower = "ViewInterTowers";
extern char *fnInterDataName   = "DataName";
extern char *fnInterDataRow    = "DataRow";
extern char *fnInterDataColumn = "DataColumn";
extern char *fnInterDataKey    = "DataKey";
extern char *fnInterDataArray  = "DataArray";
extern char *fnInterTableName  = "TableName";
extern char *fnInterTableRow   = "TableRow";
extern char *fnInterTableKey   = "TableKey";
extern char *fnInterTableArray = "TableArray";
extern char *fnInterResFile    = "ResFile";
extern char *fnInterResName    = "ResName";
extern char *fnInterDictStr    = "DictStr";
extern char *fnInterEFlags     = "EFlags";
extern char *fnInterLIdent     = "LIdent";
extern char *fnInterRIdent     = "RIdent";

extern char *fnInterMode = "Mode";
extern char *fnInterZero = "ZeroPlace";
extern char *fnInterTrace = "TraceColor";

extern char *fnInterStratFont = "StratFont";
extern char *fnInterStratSize = "StratSize";
extern char *fnInterStratJust = "StratJust";
extern char *fnInterStratDirect = "StratDirect";

extern char *fnInterValueFont = "ValueFont";
extern char *fnInterValueSize = "ValueSize";
extern char *fnInterValueJust = "ValueJust";
extern char *fnInterValuePlace = "ValuePlace";

extern char *fnInterDepthFont = "DepthFont";
extern char *fnInterDepthSize = "DepthSize";
extern char *fnInterDepthJust = "DepthJust";
extern char *fnInterDepthPlace = "DepthPlace";
extern char *fnInterLoadCondition = "LoadCondition";

extern char *anLnGridTower = "ViewLnGridTowers";
extern char *anLgGridTower = "ViewLgGridTowers";
extern char *fnTickPattern = "TickPattern";
extern char *fnGridPattern = "GridPattern";
extern char *fnTickStep    = "TickStep";
extern char *fnTickFreq    = "TickFreq";

extern char *fnGridStep    = "GridStep";
extern char *fnGridFreq    = "GridFreq";

extern char *fnGridModul   = "GridModul";
extern char *fnGridStart   = "GridStart";
extern char *fnGridPower   = "GridPower";

extern char *anViewFiller = "ViewFillers";
extern char *fnFillerStart   = "Start";
extern char *fnFillerWidth   = "Width";
extern char *fnFillerState   = "State";
extern char *fnFillerFlags   = "Flags";
extern char *fnFiller  = "Const";
extern char *fnFillerRoof    = "Roof";
extern char *fnFillerSole    = "Sole";
extern char *fnFillerNormal  = "Normal";
extern char *fnFillerReverse = "Reverse";
extern char *fnFillerLeft    = "Left";
extern char *fnFillerRight   = "Right";

extern char *fnFillerCNormal  = "NormalColor";
extern char *fnFillerCReverse = "ReverseColor";
extern char *fnFillerCLeft    = "LeftColor";
extern char *fnFillerCRight   = "RightColor";

extern char *fnFillerFont    = "FontName";
extern char *fnFillerSize    = "FontSize";
extern char *fnFillerJust    = "FontJust";
extern char *fnFillerColor   = "FontColor";
extern char *fnFillerSpace   = "SpaceText";
extern char *fnFillerBefore  = "SpaceBefore";
extern char *fnFillerAfter   = "SpaceAfter";
extern char *fnFillerIndent  = "SpaceIndent";

extern char *fnFillerLInfo  = "LCurveInfo";
extern char *fnFillerLRow   = "LRowNumber";
extern char *fnFillerLCol   = "LColNumber";
extern char *fnFillerLArray = "LArrayName";
extern char *fnFillerLTable = "LTableName";

extern char *fnFillerRInfo  = "RCurveInfo";
extern char *fnFillerRRow   = "RRowNumber";
extern char *fnFillerRCol   = "RColNumber";
extern char *fnFillerRArray = "RArrayName";
extern char *fnFillerRTable = "RTableName";


extern char *anViewPicture     = "ViewPicture";
extern char *fnPictureStart    = "Start";
extern char *fnPictureWidth    = "Width";
extern char *fnPictureHeigth   = "Heigth";
extern char *fnPictureColor    = "Color";
extern char *fnPictureFrames   = "Frames";
extern char *fnPictureSLeft    = "SLeft";
extern char *fnPictureSRight   = "SRight";
extern char *fnPictureSTop     = "STop";
extern char *fnPictureSBottom  = "SBottom";
extern char *fnPictureFLeft    = "FLeft";
extern char *fnPictureFRight   = "FRight";
extern char *fnPictureFTop     = "FTop";
extern char *fnPictureFBottom  = "FBottom";
extern char *fnPictureFlags    = "Flags";
extern char *fnPictureRoof     = "Roof";
extern char *fnPictureSole     = "Sole";
extern char *fnPictureBMPDraw  = "BMPDraw";
extern char *fnPictureBMPName  = "BMPName";
extern char *fnPictureBMPTable = "BMPTable";
extern char *fnPictureBackgroundColor = "Background";

extern char *anViewReper = "ViewChords";
extern char *fnReperStart = "Start";
extern char *fnReperWidth = "Width";
extern char *fnReperFlags = "Flags";
extern char *fnReperColor = "Color";
extern char *fnReperLeftDepth = "LeftDepth";
extern char *fnReperRightDepth = "RightDepth";
extern char *fnReperLeftCurveIdent = "LeftCurveIdent";
extern char *fnReperRightCurveIdent = "RightCurveIdent";
extern char *fnReperFillerIndex = "FillerIndex";
extern char *fnReperFillColor = "FillColor";
extern char *fnReperIdentStr = "IdentStr";
extern char *fnReperIdentLong = "IdentLong";
extern char *fnReperTraceIndex = "TraceIndex";
extern char *fnReperType = "ReperType";

extern char *anTwoDCurve = "View2dCurves";
extern char *fnTwoDStart = "Start";
extern char *fnTwoDWidth = "Width";
extern char *fnTwoDColor = "Color";
extern char *fnTwoDFlags = "Flags";
extern char *fnTwoDRoof = "Roof";
extern char *fnTwoDSole = "Sole";
extern char *fnTwoDColorFormat = "ColorFormat";
extern char *fnTwoDDisplayName = "DisplayName";
extern char *anTwoDFileStructure = "FileStructure";
extern char *fnTwoDFSName = "Name";
extern char *fnTwoDFSVersion = "Version";
extern char *fnTwoDFSFlags1 = "Flags1";
extern char *fnTwoDFSDataFormat = "DataFormat";
extern char *fnTwoDFSDepthFormat = "DepthFormat";
extern char *fnTwoDFSRoofOrSole = "DepthRoof";
extern char *fnTwoDFSStep = "DepthStep";
extern char *fnTwoDFSHeaderBitCount = "HeaderBitCount";
extern char *fnTwoDFSDataBitCount = "DataBitCount";
extern char *fnTwoDFSDataGapBitCount = "DataGapBitCount";
extern char *fnTwoDFSRowHeaderBitCount = "RowHeaderBitCount";
extern char *fnTwoDFSRowGapBitCount = "RowGapBitCount";
extern char *fnTwoDFSChanHeaderBitCount = "ChanHeaderBitCount";
extern char *fnTwoDFSChanGapBitCount = "ChanGapBitCount";
extern char *fnTwoDFSChannelDataCount = "ChannelDataCount";
extern char *fnTwoDFSRowChannelsCount = "RowChannelsCount";
extern char *fnTwoDFSDepthOffsetInBits = "Reserved";
extern char *fnTwoDColorTransformId = "ColorTransformId";
extern char *fnTwoDStorageFlags = "StorageFlags";
extern char *fnTwoDStorageTable = "StorageTable";
extern char *fnTwoDStorageName = "StorageName";
extern char *fnTwoDLegendValueDigits = "LegendValDigits";
extern char *fnTwoDArgMin = "ArgMin";
extern char *fnTwoDArgStep = "ArgStep";
extern char *fnTwoDDataMin = "DataMin";
extern char *fnTwoDDataMax = "DataMax";
extern char *fnTwoDValMin = "ValMin";
extern char *fnTwoDValMax = "ValMax";
extern char *fnTwoDLCurveIdent = "LCurveIdent";
extern char *fnTwoDRCurveIdent = "RCurveIdent";
extern char *fnTwoDHdrTitleFont = "HeaderTitleFont";
extern char *fnTwoDHdrTitleSize = "HeaderTitleSize";
extern char *fnTwoDHdrTitleJust = "HeaderTitleJust";
extern char *fnTwoDHdrValFont = "HeaderValFont";
extern char *fnTwoDHdrValSize = "HeaderValSize";
extern char *fnTwoDHdrValJust = "HeaderValJust";
extern char *fnTwoDHdrValDigits = "HeaderValDigits";
extern char *fnTwoDHdrTickSize = "HeaderTickSize";
extern char *fnTwoDHdrColor = "HeaderColor";
extern char *fnTwoDHCMin = "HCMin";
extern char *fnTwoDHCMax = "HCMax";
extern char *fnTwoDHCVal0 = "HCVal0";
extern char *fnTwoDHCScale = "HCScale";
extern char *fnTwoDHCLineIndex = "HCLineIndex";
extern char *fnTwoDHCStep = "HCStep";
extern char *fnTwoDHCRoof = "HCRoof";
extern char *fnTwoDHCSole = "HCSole";
extern char *fnTwoDDepthShift = "DepthShift";
extern char *fnTwoDDataFormat = "DataFormat";

extern char *anTwoDLevels = "Levels";
extern char *fnArgLevelMask = "VertLevelMask";
extern char *fnFuncLevelMask = "HorzLevelMask";
extern char *fnArgLevel = "VertLevel";
extern char *fnFuncLevel = "HorzLevel";

extern char *fnLegendStartValue = "StartValue";
extern char *fnLegendEndValue = "EndValue";
extern char *fnLegendStepValue = "StepValue";

extern char *tnColorTransform = "COLORTRANSFORM";
extern char *fnColorTransform = "COLORTRANSFORM"; /* ? */
extern char *fnCTIdent = "Ident";
extern char *fnCTFlags1 = "Flags1";
extern char *fnCTColorFormat = "ColorFormat";
extern char *fnCTTransformMode = "TransformMode";
extern char *fnCTInterpMode = "InterpMode";
extern char *fnCTEmptyColor = "EmptyColor";
extern char *anCTTransformArray = "TransformArray";

extern char *anFrameEmpty = "FrameEmpty";
extern char *fnFrameNumber  = "Number";
extern char *fnFrameStart   = "Start";
extern char *fnFrameWidth   = "Width";
extern char *fnFrameHeigth  = "Heigth";
extern char *fnFrameColor   = "Color";
extern char *fnFrameFlags   = "Frames";
extern char *fnFrameSLeft   = "SLeft";
extern char *fnFrameSRight  = "SRight";
extern char *fnFrameSTop    = "STop";
extern char *fnFrameSBottom = "SBottom";
extern char *fnFrameFLeft   = "FLeft";
extern char *fnFrameFRight  = "FRight";
extern char *fnFrameFTop    = "FTop";
extern char *fnFrameFBottom = "FBottom";
extern char *fnFrameBackgroundColor = "Background";

extern char *anFrameTable = "FrameTable";
extern char *fnFrameSource  = "Source";
extern char *fnFrameEmpty   = "Empty";

extern char *anFrameText = "FrameText";
extern char *fnFrameText    = "Text";
extern char *fnFrameFont    = "Font";
extern char *fnFrameSize    = "Size";
extern char *fnFrameRMul    = "RMul";
extern char *fnFrameRDiv    = "RDiv";
extern char *fnFrameJust    = "Just";
extern char *fnFrameDir     = "Direct";
extern char *fnFrameInter   = "Inter";

extern char *anFrameBitmap = "FrameBitmap";
extern char *fnFrameBMPDraw = "BMPDraw";
extern char *fnFrameBMPName = "BMPName";
extern char *fnFrameBMPTable = "BMPTable";

extern char *anFrameLine = "FrameLine";
extern char *fnFrameLine = "Line";
extern char *fnFrameLineLen = "LineLen";
extern char *fnFrameLineSpace = "LineSpace";
extern char *fnFrameLineText = "Text";
extern char *fnFrameLineTextFont = "Font";
extern char *fnFrameLineTextSize = "Size";
extern char *fnFrameLineTextRMul = "RMul";
extern char *fnFrameLineTextRDiv = "RDiv";

extern char *tnBitmapBMP = "BitmapBMP";
extern char *tnBitmapWMF = "BitmapWMF";
extern char *tnBitmapPCX = "BitmapPCX";
extern char *fnBitmapName   = "Name";
extern char *fnBitmapFlag   = "Flag";
extern char *fnBitmapWidth  = "Width";
extern char *fnBitmapHeigth = "Heigth";
extern char *fnBitmapByte   = "Byte";
extern char *fnBitmapData   = "Data";

extern char *tnPlainText = "PlainText";
extern char *fnTextName = "Name";
extern char *fnTextData = "Data";

extern char *tnBLOBTable = "BLOB";
extern char *fnBLOBCode = "CODE";
extern char *fnBLOBData = "DATA";

extern char *anInterReper = "InterReper";

extern char *anLegendItems = "LegendItems";
extern char *fnLegendOwner     = "Owner";
extern char *fnLegendIndex     = "Index";
extern char *fnLegendName      = "Name";
extern char *fnLegendStart     = "Start";
extern char *fnLegendWidth     = "Width";
extern char *fnLegendFlags     = "Flags";
extern char *fnLegendState     = "State";
extern char *fnLegendFontName  = "FontName";
extern char *fnLegendFontSize  = "FontSize";
extern char *fnLegendFontColor = "FontColor";
extern char *fnLegendIndent    = "Indent";
extern char *fnLegendHeight    = "Height";
extern char *fnLegendHMode     = "SetHoriz";
extern char *fnLegendTextPos   = "TextPos";
extern char *fnLegendTextAlign = "TextAlign";

extern char *fnLegendCommonValues = "LegParamValues";
extern char *fnLegendCommonChanges = "LegParamChanges";
extern char *fnLegendDefPlace = "Place";
extern char *anLegendHeaders = "LegendHeaders";
extern char *fnLegendHeaderTitle        = "HeaderTitle";
extern char *fnLegendHeaderFontName     = "HeaderFontName";
extern char *fnLegendHeaderFontSize     = "HeaderFontSize";
extern char *fnLegendHeaderFontColor    = "HeaderFontColor";
extern char *fnLegendHeaderFlags        = "HeaderFlags";
extern char *fnLegendHeaderWidth        = "HeaderWidth";
extern char *fnLegendHeaderBottomIndent = "HeaderBottomInd";

extern char *anHeaderItems = "HeaderItems";
extern char *fnHeaderItemOwnerId   = "Owner";
extern char *fnHeaderItemIndex     = "Index";
extern char *fnHeaderItemFlags     = "Flags";
extern char *fnHeaderItemSeqNumber = "SeqNumber";

extern char *CBLOBText = "BLOB$TXT";

extern char *anViewCustom = "CustomView";
extern char *fnCVStart = "Start";
extern char *fnCVWidth = "Width";
extern char *fnCVData = "Data";
extern char *fnCVLibrary = "Library";
extern char *fnCVMake = "Make";
extern char *fnCVDraw = "Draw";
extern char *fnCVDrawMarker = "DrawMarker";
extern char *fnCVHandleDepth = "HandleDepth";
extern char *fnCVStatusStr = "StatusStr";
extern char *fnCVGlobalStr = "GlobalStr";
extern char *fnCVExposed = "Exposed";
extern char *fnCVRadius = "Radius";
extern char *fnCVViewRoof = "ViewRoof";
extern char *fnCVViewSole = "ViewSole";
extern char *fnCVActualClass = "ActualClass";
extern char *fnCVGetData = "GetData";
extern char *fnCVSetData = "SetData";
extern char *fnCVDataSize = "DataSize";
extern char *fnCVHaveHandle = "HaveHandle";
extern char *fnCVReset = "Reset";
extern char *fnCVWSName = "WSName";
extern char *fnCVEditDialog = "EditDialog";
extern char *fnCVDrawHeader = "DrawHeader";
extern char *fnCVHeaderStart = "HeaderStart";
extern char *fnCVHeaderWidth = "HeaderWidth";
extern char *fnCVHeaderHeigth = "HeaderHeigth";
extern char *fnCVDone = "Done";

extern char *mnCVDraw = "CVDraw";
extern char *mnCVDrawMarker = "CVDrawMarker";
extern char *mnCVStatusStr = "CVStatusStr";
extern char *mnCVGlobalStr = "CVGlobalStr";
extern char *mnCVExposed = "CVExposed";
extern char *mnCVRadius = "CVRadius";
extern char *mnCVViewRoof = "CVViewRoof";
extern char *mnCVViewSole = "CVViewSole";
extern char *mnCVActualClass = "CVActualClass";
extern char *mnCVMake = "CVMake";
extern char *mnCVHandleDepth = "CVHandleDepth";
extern char *mnCVGetData = "CVGetData";
extern char *mnCVSetData = "CVSetData";
extern char *mnCVDataSize = "CVDataSize";
extern char *mnCVHaveHandle = "CVHaveHandle";
extern char *mnCVReset = "CVReset";
extern char *mnCVWSName = "CVWSName";
extern char *mnCVEditDialog = "CVEditDialog";
extern char *mnCVDrawHeader = "CVDrawHeader";
extern char *mnCVHeaderStart = "CVHeaderStart";
extern char *mnCVHeaderWidth = "CVHeaderWidth";
extern char *mnCVHeaderHeigth = "CVHeaderHeigth";
extern char *mnCVDone = "CVDone";

extern char *anFrameCustom = "CustomFrame";
extern char *fnCFData = "Data";
extern char *fnCFLibrary = "Library";
extern char *fnCFMake = "Make";
extern char *fnCFReset = "Reset";
extern char *fnCFUpDate = "Update";
extern char *fnCFDraw = "Draw";
extern char *fnCFSetData = "SetData";
extern char *fnCFGetData = "GetData";
extern char *fnCFDataSize = "DataSize";
extern char *fnCFEditDialog = "EditDialog";
extern char *fnCFFrameWidth = "FrameWidth";
extern char *fnCFFrameHeigth = "FrameHeigth";
extern char *fnCFFrameClass = "FrameClass";
extern char *fnCFGlobalStr = "GlobalStr";
extern char *fnCFDone = "Done";

extern char *mnCFMake = "CFMake";
extern char *mnCFReset = "CFReset";
extern char *mnCFUpDate = "CFUpdate";
extern char *mnCFDraw = "CFDraw";
extern char *mnCFSetData = "CFSetData";
extern char *mnCFGetData = "CFGetData";
extern char *mnCFDataSize = "CFDataSize";
extern char *mnCFEditDialog = "CFEditDialog";
extern char *mnCFFrameWidth = "CFFrameWidth";
extern char *mnCFFrameHeigth = "CFFrameHeigth";
extern char *mnCFFrameClass = "CFFrameClass";
extern char *mnCFGlobalStr = "CFGlobalStr";
extern char *mnCFDone = "CFDone";

extern char *ppnDepthPrecIndex = "DepthPrecIndex";
extern char *ppnPosPrecIndex = "PosPrecIndex";
extern char *ppnDefTowerInterRec = "DefTowerInterRec";


/*****************************************************************************\
*                                                                             *
*    ÎÏÐÅÄÅËÅÍÈß ÂÛÇÎÂÎÂ ÔÓÍÊÖÈÉ ÈÇ ÂÍÅØÍÅÃÎ ÌÎÄÓËß (PRIME32.EXE)             *
*                                                                             *
\*****************************************************************************/

typedef unsigned char (__stdcall *PDll_GetHASPFlag)(void) ;
PDll_GetHASPFlag Dll_GetHASPFlag;
typedef long (__stdcall *PDll_WSIGFExec)(const char*,const char*,LongBoolean);
PDll_WSIGFExec Dll_WSIGFExec;
typedef HWND (__stdcall *PDll_Prime32Handle)(void);
PDll_Prime32Handle Dll_Prime32Handle;
typedef void (__stdcall *PDll_PrimeBringToFront)(void);
PDll_PrimeBringToFront Dll_PrimeBringToFront;
typedef long (__stdcall *PDll_GetPrimeWorkDir)(char*, long);
PDll_GetPrimeWorkDir Dll_GetPrimeWorkDir;
typedef long (__stdcall *PDll_GetPrimeWorkBaseDir)(char*, long);
PDll_GetPrimeWorkBaseDir Dll_GetPrimeWorkBaseDir;
typedef LongBoolean (__stdcall *PDll_SetPrimeWorkBaseDir)(const char*);
PDll_SetPrimeWorkBaseDir Dll_SetPrimeWorkBaseDir;
typedef long (__stdcall *PDll_GetPrimeSettingsDir)(char*, long);
PDll_GetPrimeSettingsDir Dll_GetPrimeSettingsDir;
typedef long (__stdcall *PDll_GetPrimeVersion)(char*, long);
PDll_GetPrimeVersion Dll_GetPrimeVersion;

typedef void (__stdcall *PDll_PrimeDisableUnload)(HINSTANCE);
PDll_PrimeDisableUnload Dll_PrimeDisableUnload;
typedef void (__stdcall *PDll_PrimeEnableUnload)(HINSTANCE);
PDll_PrimeEnableUnload Dll_PrimeEnableUnload;
typedef LongBoolean (__stdcall *PDll_PrimeUnloadEnabled)(HINSTANCE);
PDll_PrimeUnloadEnabled Dll_PrimeUnloadEnabled;
typedef LongBoolean (__stdcall *PDll_PrimeTerminating)(void);
PDll_PrimeTerminating Dll_PrimeTerminating;

typedef void (__stdcall *PDll_DoneObject)(void*);
PDll_DoneObject Dll_DoneObject;
typedef PPasString (__stdcall *PDll_NewPString)(const char*);
PDll_NewPString Dll_NewPString;
typedef unsigned char (__stdcall *PDll_LenPString)(PPasString);
PDll_LenPString Dll_LenPString;
typedef void (__stdcall *PDll_FreePString)(PPasString);
PDll_FreePString Dll_FreePString;
typedef void*  (__stdcall *PDll_GetMemLib)(long);
PDll_GetMemLib Dll_GetMemLib;
typedef void (__stdcall *PDll_FreeMemLib)(void*,long);
PDll_FreeMemLib Dll_FreeMemLib;
typedef void* (__stdcall *PDll_AllocMemLib)(long);
PDll_AllocMemLib Dll_AllocMemLib;
typedef void (__stdcall *PDll_ReallocMemLib)(void**,long);
PDll_ReallocMemLib Dll_ReallocMemLib;
typedef void (__stdcall *PDll_PCharDispose)(char*);
PDll_PCharDispose Dll_PCharDispose;
typedef void*  (__stdcall *PDll_InitList)(long,long);
PDll_InitList Dll_InitList;
typedef void*  (__stdcall *PDll_InitStringList)(long,long);
PDll_InitStringList Dll_InitStringList;
typedef void*  (__stdcall *PDll_InitEmptyList)(long,long);
PDll_InitEmptyList Dll_InitEmptyList;
typedef void*  (__stdcall *PDll_InitUnsortList)(long,long);
PDll_InitUnsortList Dll_InitUnsortList;
typedef long  (__stdcall *PDll_ListCount)(void*);
PDll_ListCount Dll_ListCount;
typedef void*  (__stdcall *PDll_ListAt)(void*,long);
PDll_ListAt Dll_ListAt;
typedef void (__stdcall *PDll_ListAtDelete)(void*,long);
PDll_ListAtDelete Dll_ListAtDelete;
typedef void (__stdcall *PDll_ListAtFree)(void*,long);
PDll_ListAtFree Dll_ListAtFree;
typedef void (__stdcall *PDll_ListAtInsert)(void*,long,void*);
PDll_ListAtInsert Dll_ListAtInsert;
typedef void (__stdcall *PDll_ListAtPut)(void*,long,void*);
PDll_ListAtPut Dll_ListAtPut;
typedef void (__stdcall *PDll_ListDelete)(void*,void*);
PDll_ListDelete Dll_ListDelete;
typedef void (__stdcall *PDll_ListDeleteAll)(void*);
PDll_ListDeleteAll Dll_ListDeleteAll;
typedef void (__stdcall *PDll_ListFree)(void*,void*);
PDll_ListFree Dll_ListFree;
typedef void (__stdcall *PDll_ListFreeAll)(void*);
PDll_ListFreeAll Dll_ListFreeAll;
typedef long (__stdcall *PDll_ListIndexOf)(void*,void*);
PDll_ListIndexOf Dll_ListIndexOf;
typedef void (__stdcall *PDll_ListInsert)(void*,void*);
PDll_ListInsert Dll_ListInsert;
typedef void (__stdcall *PDll_ListPack)(void*);
PDll_ListPack Dll_ListPack;
typedef long (__stdcall *PDll_ListSearch)(void*,const char*);
PDll_ListSearch Dll_ListSearch;
typedef void* (__stdcall *PDll_CreateWSCurve)(OType,long,OType,unsigned char);
PDll_CreateWSCurve Dll_CreateWSCurve;
typedef void* (__stdcall *PDll_CreateWSRotCurve)(OType,long,OType,unsigned char,unsigned char);
PDll_CreateWSRotCurve Dll_CreateWSRotCurve;
typedef void* (__stdcall *PDll_CreateWSPoint)(OType,long);
PDll_CreateWSPoint Dll_CreateWSPoint;
typedef void* (__stdcall *PDll_CreateWSInter)(OType,long);
PDll_CreateWSInter Dll_CreateWSInter;
typedef void* (__stdcall *PDll_CreateWSTower)(long,long,long,const char*);
PDll_CreateWSTower Dll_CreateWSTower;
typedef void* (__stdcall *PDll_CreateWSDepth)(long,long,long,const char*);
PDll_CreateWSDepth Dll_CreateWSDepth;
typedef void* (__stdcall *PDll_CreateWSLnGrid)(long,long,long,const char*);
PDll_CreateWSLnGrid Dll_CreateWSLnGrid;
typedef void* (__stdcall *PDll_CreateWSLgGrid)(long,long,long,const char*);
PDll_CreateWSLgGrid Dll_CreateWSLgGrid;
typedef void* (__stdcall *PDll_CreateWSPlast)(long,long,long,const char*,OType,OType,long,unsigned char,OType,OType,long);
PDll_CreateWSPlast Dll_CreateWSPlast;
typedef void* (__stdcall *PDll_CreateWSNotes)(long,const char*);
PDll_CreateWSNotes Dll_CreateWSNotes;
typedef void* (__stdcall *PDll_CreateWSFills)(long,long,long,long,long,long,long,long,long,void*,void*,float);
PDll_CreateWSFills Dll_CreateWSFills;
typedef void* (__stdcall *PDll_CreateWSPicture)(void);
PDll_CreateWSPicture Dll_CreateWSPicture;
typedef void* (__stdcall *PDll_CreateWSTwoDCurve)(void);
PDll_CreateWSTwoDCurve Dll_CreateWSTwoDCurve;
typedef void* (__stdcall *PDll_CreateWSFrame)(void);
PDll_CreateWSFrame Dll_CreateWSFrame;
typedef void* (__stdcall *PDll_CreateWSText)(void);
PDll_CreateWSText Dll_CreateWSText;
typedef void* (__stdcall *PDll_CreateWSTable)(void);
PDll_CreateWSTable Dll_CreateWSTable;
typedef void* (__stdcall *PDll_CreateWSBitmap)(void);
PDll_CreateWSBitmap Dll_CreateWSBitmap;
typedef void* (__stdcall *PDll_CreateWSChord)(long,long,long,long,void*,void*,long,long);
PDll_CreateWSChord Dll_CreateWSChord;
typedef void* (__stdcall *PDll_CreateWSScale)(long,long,long,long,float,float,void*,long,const char*);
PDll_CreateWSScale Dll_CreateWSScale;
typedef void* (__stdcall *PDll_GetHandleInter)(void*,long,long*,long*);
PDll_GetHandleInter Dll_GetHandleInter;
typedef void* (__stdcall *PDll_CreateHandleInter)(long,long,long,long,long);
PDll_CreateHandleInter Dll_CreateHandleInter;
typedef void (__stdcall *PDll_StartProcess)(const char*);
PDll_StartProcess Dll_StartProcess;
typedef void (__stdcall *PDll_StepProcess)(long,long,long);
PDll_StepProcess Dll_StepProcess;
typedef void (__stdcall *PDll_StopProcess)(void);
PDll_StopProcess Dll_StopProcess;
typedef long (__stdcall *PDll_WSStart)(void*);
PDll_WSStart Dll_WSStart;
typedef long (__stdcall *PDll_WSWidth)(void*);
PDll_WSWidth Dll_WSWidth;
typedef long (__stdcall *PDll_WSState)(void*);
PDll_WSState Dll_WSState;
typedef long (__stdcall *PDll_WSType)(void*);
PDll_WSType Dll_WSType;
typedef LongBoolean (__stdcall *PDll_WSMake)(void*);
PDll_WSMake Dll_WSMake;
typedef LongBoolean (__stdcall *PDll_WSActual)(void*,unsigned short);
PDll_WSActual Dll_WSActual;
typedef void (__stdcall *PDll_WSGetData)(void*, void*);
PDll_WSGetData Dll_WSGetData;
typedef void (__stdcall *PDll_WSSetData)(void *, void *);
PDll_WSSetData Dll_WSSetData;
typedef unsigned short (__stdcall *PDll_WSDataSize)(void*);
PDll_WSDataSize Dll_WSDataSize;
typedef void (__stdcall *PDll_WSReset)(void*);
PDll_WSReset Dll_WSReset;
typedef void (__stdcall *PDll_WSSetState)(void*,unsigned short,LongBoolean);
PDll_WSSetState Dll_WSSetState;
typedef LongBoolean (__stdcall *PDll_WSGetState)(void*,unsigned short);
PDll_WSGetState Dll_WSGetState;
typedef long (__stdcall *PDll_WSRoof)(void*);
PDll_WSRoof Dll_WSRoof;
typedef long (__stdcall *PDll_WSSole)(void*);
PDll_WSSole Dll_WSSole;
typedef long (__stdcall *PDll_WSNBRoof)(void*);
PDll_WSNBRoof Dll_WSNBRoof;
typedef long (__stdcall *PDll_WSNBSole)(void*);
PDll_WSNBSole Dll_WSNBSole;
typedef void (__stdcall *PDll_WSName)(void*,char*);
PDll_WSName Dll_WSName;
typedef LongBoolean (__stdcall *PDll_WSSetDialog)(void*);
PDll_WSSetDialog Dll_WSSetDialog;
typedef LongBoolean (__stdcall *PDll_WSGetDialog)(void*);
PDll_WSGetDialog Dll_WSGetDialog;
typedef void (__stdcall *PDll_WSSetStart)(void*,long);
PDll_WSSetStart Dll_WSSetStart;
typedef void (__stdcall *PDll_WSSetWidth)(void*,long);
PDll_WSSetWidth Dll_WSSetWidth;
typedef void (__stdcall *PDll_FrameGetData)(void*, void*);
PDll_FrameGetData Dll_FrameGetData;
typedef void (__stdcall *PDll_FrameSetData)(void*, void*);
PDll_FrameSetData Dll_FrameSetData;
typedef unsigned short (__stdcall *PDll_FrameDataSize)(void*);
PDll_FrameDataSize Dll_FrameDataSize;
typedef long (__stdcall *PDll_FrameGetStart)(void*);
PDll_FrameGetStart Dll_FrameGetStart;
typedef long (__stdcall *PDll_FrameGetWidth)(void*);
PDll_FrameGetWidth Dll_FrameGetWidth;
typedef long (__stdcall *PDll_FrameGetState)(void*);
PDll_FrameGetState Dll_FrameGetState;
typedef void (__stdcall *PDll_FrameSetStart)(void*,long);
PDll_FrameSetStart Dll_FrameSetStart;
typedef void (__stdcall *PDll_FrameSetWidth)(void*,long);
PDll_FrameSetWidth Dll_FrameSetWidth;
typedef void (__stdcall *PDll_FrameSetState)(void*,long);
PDll_FrameSetState Dll_FrameSetState;
typedef long (__stdcall *PDll_WSCurveActual)(void*);
PDll_WSCurveActual Dll_WSCurveActual;
typedef long (__stdcall *PDll_WSCurveCount)(void*);
PDll_WSCurveCount Dll_WSCurveCount;
typedef long (__stdcall *PDll_WSCurveDepth)(void*,long);
PDll_WSCurveDepth Dll_WSCurveDepth;
typedef long (__stdcall *PDll_WSCurveIndex)(void*,long);
PDll_WSCurveIndex Dll_WSCurveIndex;
typedef float (__stdcall *PDll_WSCurveValue)(void*,long);
PDll_WSCurveValue Dll_WSCurveValue;
typedef long (__stdcall *PDll_WSCurveValueStr)(void*,long,char*,long);
PDll_WSCurveValueStr Dll_WSCurveValueStr;
typedef long (__stdcall *PDll_GetLitholByDepth)(void*,long);
PDll_GetLitholByDepth Dll_GetLitholByDepth;
typedef long (__stdcall *PDll_GetStratByDepth)(void*,long,char*,long);
PDll_GetStratByDepth Dll_GetStratByDepth;
typedef long (__stdcall *PDll_GetLegendByDepth)(void*,long,char*,long);
PDll_GetLegendByDepth Dll_GetLegendByDepth;
typedef OType (__stdcall *PDll_GetTowerPlastArray)(void*);
PDll_GetTowerPlastArray Dll_GetTowerPlastArray;
typedef long (__stdcall *PDll_WSCurveMinMidMax)(void*,long,long,float*,float*,float*);
PDll_WSCurveMinMidMax Dll_WSCurveMinMidMax;
typedef long (__stdcall *PDll_WSCurveMinMidMaxH)(void*,long,long,float*,float*,float*,float*,float*);
PDll_WSCurveMinMidMaxH Dll_WSCurveMinMidMaxH;
typedef long (__stdcall *PDll_WSCurveLinear)(void*,long,long,float*,float*);
PDll_WSCurveLinear Dll_WSCurveLinear;
typedef long (__stdcall *PDll_WSCurveSetTemplate)(void*,const char*,char*);
PDll_WSCurveSetTemplate Dll_WSCurveSetTemplate;
typedef LongBoolean (__stdcall *PDll_SetTemplateObject)(void*,void*,long,void*);
PDll_SetTemplateObject Dll_SetTemplateObject;
typedef void* (__stdcall *PDll_GetTemplateObject)(void*,void*);
PDll_GetTemplateObject Dll_GetTemplateObject;
typedef OType (__stdcall *PDll_CreateTemplateDataObject)(void*,void*,const char*,void*);
PDll_CreateTemplateDataObject Dll_CreateTemplateDataObject;
typedef long (__stdcall *PDll_GetViewID)(void*);
PDll_GetViewID Dll_GetViewID;
typedef void* (__stdcall *PDll_FindViewByID)(void*,long);
PDll_FindViewByID Dll_FindViewByID;
typedef long (__stdcall *PDll_CurveGetLoadCondition)(void*,char*,long);
PDll_CurveGetLoadCondition Dll_CurveGetLoadCondition;
typedef LongBoolean (__stdcall *PDll_CurveSetLoadCondition)(void*,const char*);
PDll_CurveSetLoadCondition Dll_CurveSetLoadCondition;
typedef void (__stdcall *PDll_PutMessage)(const char*);
PDll_PutMessage Dll_PutMessage;
typedef void (__stdcall *PDll_WaitMessage)(const char*);
PDll_WaitMessage Dll_WaitMessage;
typedef void (__stdcall *PDll_ClrMessage)(void);
PDll_ClrMessage Dll_ClrMessage;
typedef void* (__stdcall *PDll_CurrentWindow)(void);
PDll_CurrentWindow Dll_CurrentWindow;
typedef void (__stdcall *PDll_WindowFileName)(char*);
PDll_WindowFileName Dll_WindowFileName;
typedef void (__stdcall *PDll_WindowTypeName)(char*);
PDll_WindowTypeName Dll_WindowTypeName;
typedef void* (__stdcall *PDll_CurrentPlansheet)(void);
PDll_CurrentPlansheet Dll_CurrentPlansheet;
typedef long (__stdcall *PDll_GetPlanTemplate)(void*,char*);
PDll_GetPlanTemplate Dll_GetPlanTemplate;
typedef long (__stdcall *PDll_GetPlanTitle)(void*,char*);
PDll_GetPlanTitle Dll_GetPlanTitle;
typedef long (__stdcall *PDll_GetPlanRoof)(void*);
PDll_GetPlanRoof Dll_GetPlanRoof;
typedef long (__stdcall *PDll_GetPlanSole)(void*);
PDll_GetPlanSole Dll_GetPlanSole;
typedef void (__stdcall *PDll_SetPlanRoof)(void*,long);
PDll_SetPlanRoof Dll_SetPlanRoof;
typedef void (__stdcall *PDll_SetPlanSole)(void*,long);
PDll_SetPlanSole Dll_SetPlanSole;
typedef long (__stdcall *PDll_GetPlanHandle)(void*);
PDll_GetPlanHandle Dll_GetPlanHandle;
typedef void (__stdcall *PDll_SetPlanHandle)(void*,long);
PDll_SetPlanHandle Dll_SetPlanHandle;
typedef long (__stdcall *PDll_GetPlanCount)(void*);
PDll_GetPlanCount Dll_GetPlanCount;
typedef void* (__stdcall *PDll_GetPlanList)(void*);
PDll_GetPlanList Dll_GetPlanList;
typedef void* (__stdcall *PDll_GetPlanListX)(void*);
PDll_GetPlanListX Dll_GetPlanListX;
typedef long (__stdcall *PDll_GetPlanActiveCount)(void*);
PDll_GetPlanActiveCount Dll_GetPlanActiveCount;
typedef void* (__stdcall *PDll_GetPlanActiveList)(void*);
PDll_GetPlanActiveList Dll_GetPlanActiveList;
typedef long (__stdcall *PDll_GetPlanDepth)(void*);
PDll_GetPlanDepth Dll_GetPlanDepth;
typedef void (__stdcall *PDll_SetPlanDepth)(void*,long);
PDll_SetPlanDepth Dll_SetPlanDepth;

typedef long (__stdcall *PDll_GetPlanScale)(void*);
PDll_GetPlanScale Dll_GetPlanScale;
typedef void (__stdcall *PDll_SetPlanScale)(void*,long);
PDll_SetPlanScale Dll_SetPlanScale;
typedef long (__stdcall *PDll_GetPlanWidth)(void*);
PDll_GetPlanWidth Dll_GetPlanWidth;
typedef void (__stdcall *PDll_SetPlanWidth)(void*,long);
PDll_SetPlanWidth Dll_SetPlanWidth;
typedef unsigned char (__stdcall *PDll_GetPlanColor)(long);
PDll_GetPlanColor Dll_GetPlanColor;
typedef void (__stdcall *PDll_SetPlanColor)(long,unsigned char);
PDll_SetPlanColor Dll_SetPlanColor;
typedef void (__stdcall *PDll_GetWorkSpace)(void*,char*);
PDll_GetWorkSpace Dll_GetWorkSpace;
typedef LongBoolean (__stdcall *PDll_HeaderState)(void*);
PDll_HeaderState Dll_HeaderState;
typedef void (__stdcall *PDll_ShowHeader)(void*);
PDll_ShowHeader Dll_ShowHeader;
typedef void (__stdcall *PDll_HideHeader)(void*);
PDll_HideHeader Dll_HideHeader;
typedef void (__stdcall *PDll_DrawPlansheet)(void*);
PDll_DrawPlansheet Dll_DrawPlansheet;
typedef long (__stdcall *PDll_ObjectCount)(void*,long);
PDll_ObjectCount Dll_ObjectCount;
typedef void* (__stdcall *PDll_ObjectList)(void*,long);
PDll_ObjectList Dll_ObjectList;
typedef long (__stdcall *PDll_ActiveCount)(void*,long);
PDll_ActiveCount Dll_ActiveCount;
typedef void* (__stdcall *PDll_ActiveList)(void*,long);
PDll_ActiveList Dll_ActiveList;
typedef long (__stdcall *PDll_StrictObjectCount)(void*,long);
PDll_StrictObjectCount Dll_StrictObjectCount;
typedef void* (__stdcall *PDll_StrictObjectList)(void*,long);
PDll_StrictObjectList Dll_StrictObjectList;
typedef long (__stdcall *PDll_StrictActiveCount)(void*,long);
PDll_StrictActiveCount Dll_StrictActiveCount;
typedef void* (__stdcall *PDll_StrictActiveList)(void*,long);
PDll_StrictActiveList Dll_StrictActiveList;
typedef void (__stdcall *PDll_InsertObject)(void*,void*);
PDll_InsertObject Dll_InsertObject;
typedef void (__stdcall *PDll_RedrawObject)(void*,void*);
PDll_RedrawObject Dll_RedrawObject;
typedef void (__stdcall *PDll_RedrawObjectXor)(void*,void*);
PDll_RedrawObjectXor Dll_RedrawObjectXor;
typedef void (__stdcall *PDll_DeleteObject)(void*,void*);
PDll_DeleteObject Dll_DeleteObject;
typedef void (__stdcall *PDll_SaveState)(void*);
PDll_SaveState Dll_SaveState;
typedef void (__stdcall *PDll_RestoreState)(void*);
PDll_RestoreState Dll_RestoreState;
typedef void (__stdcall *PDll_ClearState)(void*,long);
PDll_ClearState Dll_ClearState;
typedef void (__stdcall *PDll_SetupState)(void*,long);
PDll_SetupState Dll_SetupState;
typedef LongBoolean (__stdcall *PDll_ExecuteWindow)(void*);
PDll_ExecuteWindow Dll_ExecuteWindow;
typedef void (__stdcall *PDll_PointTable)(void*,OType*);
PDll_PointTable Dll_PointTable;
typedef void (__stdcall *PDll_InterTable)(void*,OType*);
PDll_InterTable Dll_InterTable;
typedef void (__stdcall *PDll_RedrawObjects)(void*);
PDll_RedrawObjects Dll_RedrawObjects;
typedef void (__stdcall *PDll_DisableHeaderRedraw)(void);
PDll_DisableHeaderRedraw Dll_DisableHeaderRedraw;
typedef void (__stdcall *PDll_EnableHeaderRedraw)(void);
PDll_EnableHeaderRedraw Dll_EnableHeaderRedraw;
typedef long (__stdcall *PDll_RegisterPrimeWindow)(HWND,const char*);
PDll_RegisterPrimeWindow Dll_RegisterPrimeWindow;
typedef long (__stdcall *PDll_RegisterPrimeWindowAt)(HWND,const char*,long);
PDll_RegisterPrimeWindowAt Dll_RegisterPrimeWindowAt;
typedef long (__stdcall *PDll_UnregisterPrimeWindow)(HWND);
PDll_UnregisterPrimeWindow Dll_UnregisterPrimeWindow;
typedef void* (__stdcall *PDll_CurrentTower)(void*);
PDll_CurrentTower Dll_CurrentTower;
typedef void* (__stdcall *PDll_CurrentCurve)(void*);
PDll_CurrentCurve Dll_CurrentCurve;
typedef long (__stdcall *PDll_CurveMode)(void*);
PDll_CurveMode Dll_CurveMode;
typedef float (__stdcall *PDll_AbsDepthValue)(void*,long);
PDll_AbsDepthValue Dll_AbsDepthValue;
typedef long (__stdcall *PDll_GetDepthByAbsDepth)(void*,float);
PDll_GetDepthByAbsDepth Dll_GetDepthByAbsDepth;
typedef long (__stdcall *PDll_GetReportHandle)(void*);
PDll_GetReportHandle Dll_GetReportHandle;
typedef void (__stdcall *PDll_SetReportHandle)(void*,long);
PDll_SetReportHandle Dll_SetReportHandle;
typedef long (__stdcall *PDll_GetReportCount)(void*);
PDll_GetReportCount Dll_GetReportCount;
typedef long (__stdcall *PDll_FrameCount)(void*,long);
PDll_FrameCount Dll_FrameCount;
typedef void* (__stdcall *PDll_FrameList)(void*,long);
PDll_FrameList Dll_FrameList;
typedef long (__stdcall *PDll_ActiveFramesCount)(void*,long);
PDll_ActiveFramesCount Dll_ActiveFramesCount;
typedef void* (__stdcall *PDll_ActiveFramesList)(void*,long);
PDll_ActiveFramesList Dll_ActiveFramesList;
typedef long (__stdcall *PDll_FooterFrameCount)(void*,long);
PDll_FooterFrameCount Dll_FooterFrameCount;
typedef void* (__stdcall *PDll_FooterFrameList)(void*,long);
PDll_FooterFrameList Dll_FooterFrameList;
typedef long (__stdcall *PDll_ActiveFooterFramesCount)(void*,long);
PDll_ActiveFooterFramesCount Dll_ActiveFooterFramesCount;
typedef void* (__stdcall *PDll_ActiveFooterFramesList)(void*,long);
PDll_ActiveFooterFramesList Dll_ActiveFooterFramesList;
typedef void (__stdcall *PDll_InsertFrames)(void*,void*);
PDll_InsertFrames Dll_InsertFrames;
typedef void (__stdcall *PDll_DeleteFrames)(void*,void*);
PDll_DeleteFrames Dll_DeleteFrames;
typedef void (__stdcall *PDll_SetLeftCurve)(void*,void*);
PDll_SetLeftCurve Dll_SetLeftCurve;
typedef void (__stdcall *PDll_SetRightCurve)(void*,void*);
PDll_SetRightCurve Dll_SetRightCurve;
typedef LongBoolean (__stdcall *PDll_TrackData)(void*,long);
PDll_TrackData Dll_TrackData;
typedef void (__stdcall *PDll_SetTrackFormat)(void*,const char*);
PDll_SetTrackFormat Dll_SetTrackFormat;
typedef void (__stdcall *PDll_SetTrackRoof)(void*,long);
PDll_SetTrackRoof Dll_SetTrackRoof;
typedef void (__stdcall *PDll_SetTrackSole)(void*,long);
PDll_SetTrackSole Dll_SetTrackSole;
typedef void (__stdcall *PDll_SetTrackDepth)(void*,long);
PDll_SetTrackDepth Dll_SetTrackDepth;
typedef void (__stdcall *PDll_SetTrackStart)(void*,long);
PDll_SetTrackStart Dll_SetTrackStart;
typedef void (__stdcall *PDll_SetTrackShift)(void*,long);
PDll_SetTrackShift Dll_SetTrackShift;
typedef void (__stdcall *PDll_SetTrackMinim)(void*,float);
PDll_SetTrackMinim Dll_SetTrackMinim;
typedef void (__stdcall *PDll_SetTrackScale)(void*,float);
PDll_SetTrackScale Dll_SetTrackScale;
typedef void (__stdcall *PDll_SetTrackValue)(void*,float);
PDll_SetTrackValue Dll_SetTrackValue;
typedef void (__stdcall *PDll_SetTrackCurve)(void*,void*);
PDll_SetTrackCurve Dll_SetTrackCurve;
typedef long (__stdcall *PDll_SetTrackUserValueCallback)(void*,long,
  TTrackUserValueFunc,void*);
PDll_SetTrackUserValueCallback Dll_SetTrackUserValueCallback;
typedef long (__stdcall *PDll_SetTrackUserStrCallback)(void*,long,
  TTrackUserStringFunc,void*);
PDll_SetTrackUserStrCallback Dll_SetTrackUserStrCallback;
typedef long (__stdcall *PDll_GetTrackDepth)(void*);
PDll_GetTrackDepth Dll_GetTrackDepth;
typedef long (__stdcall *PDll_GetTrackStart)(void*);
PDll_GetTrackStart Dll_GetTrackStart;
typedef float (__stdcall *PDll_GetTrackValue)(void*);
PDll_GetTrackValue Dll_GetTrackValue;
typedef double (__stdcall *PDll_GetTrackUserValue)(void*,long);
PDll_GetTrackUserValue Dll_GetTrackUserValue;
typedef long (__stdcall *PDll_GetTrackUserString)(void*,long,void*,long);
PDll_GetTrackUserString Dll_GetTrackUserString;
typedef long (__stdcall *PDll_GetPrintIntervalsCount)(void*);
PDll_GetPrintIntervalsCount Dll_GetPrintIntervalsCount;
typedef LongBoolean (__stdcall *PDll_GetPrintInterval)(void*,long,TPrintInterval*);
PDll_GetPrintInterval Dll_GetPrintInterval;
typedef LongBoolean (__stdcall *PDll_SetPrintInterval)(void*,long,const TPrintInterval*);
PDll_SetPrintInterval Dll_SetPrintInterval;
typedef LongBoolean (__stdcall *PDll_AddPrintInterval)(void*,const TPrintInterval*);
PDll_AddPrintInterval Dll_AddPrintInterval;
typedef LongBoolean (__stdcall *PDll_AddPrintIntervalAt)(void*,long,const TPrintInterval*);
PDll_AddPrintIntervalAt Dll_AddPrintIntervalAt;
typedef LongBoolean (__stdcall *PDll_DeletePrintInterval)(void*,long);
PDll_DeletePrintInterval Dll_DeletePrintInterval;
typedef LongBoolean (__stdcall *PDll_DeleteAllPrintIntervals)(void*);
PDll_DeleteAllPrintIntervals Dll_DeleteAllPrintIntervals;
typedef void* (__stdcall *PDll_ActiveCurves)(long,long,const char*);
PDll_ActiveCurves Dll_ActiveCurves;
typedef void* (__stdcall *PDll_ActiveDViews)(long,long,const char*);
PDll_ActiveDViews Dll_ActiveDViews;
typedef void* (__stdcall *PDll_ActivePlastTowers)(long,long,const char*);
PDll_ActivePlastTowers Dll_ActivePlastTowers;
typedef void* (__stdcall *PDll_ActiveTowers)(long,long,const char*);
PDll_ActiveTowers Dll_ActiveTowers;
typedef void* (__stdcall *PDll_ActiveText)(long,long,const char*);
PDll_ActiveText Dll_ActiveText;
typedef void* (__stdcall *PDll_GetOneCurve)(const char*,const char*);
PDll_GetOneCurve Dll_GetOneCurve;
typedef void* (__stdcall *PDll_GetOneCurveByName)(const char*);
PDll_GetOneCurveByName Dll_GetOneCurveByName;
typedef void* (__stdcall *PDll_GetPlastTower)(const char*);
PDll_GetPlastTower Dll_GetPlastTower;
typedef long (__stdcall *PDll_FindPlanObject)(void*,const char*,void*,long,
  long,void**,void*,void*);
PDll_FindPlanObject Dll_FindPlanObject;
typedef long (__stdcall *PDll_FindCurveLoadCondition)(const char*,const char*,long,
  char *,long,void*);
PDll_FindCurveLoadCondition Dll_FindCurveLoadCondition;
typedef LongBoolean (__stdcall *PDll_InsertOrReplaceObject)(void*,void**,
  long,long*,void*);
PDll_InsertOrReplaceObject Dll_InsertOrReplaceObject;
typedef void* (__stdcall *PDll_SelectObject)(const char*);
PDll_SelectObject Dll_SelectObject;
typedef void* (__stdcall *PDll_SelectObjectByType)(const char*,long);
PDll_SelectObjectByType Dll_SelectObjectByType;
typedef void* (__stdcall *PDll_SelectCurve)(const char*);
PDll_SelectCurve Dll_SelectCurve;
typedef void* (__stdcall *PDll_SelectDView)(const char*);
PDll_SelectDView Dll_SelectDView;
typedef void* (__stdcall *PDll_SelectPlastTower)(const char*);
PDll_SelectPlastTower Dll_SelectPlastTower;
typedef void* (__stdcall *PDll_SelectTower)(const char*);
PDll_SelectTower Dll_SelectTower;
typedef void* (__stdcall *PDll_SelectText)(const char*);
PDll_SelectText Dll_SelectText;
typedef void* (__stdcall *PDll_SelectTwoDCurve)(const char*);
PDll_SelectTwoDCurve Dll_SelectTwoDCurve;
typedef long (__stdcall *PDll_GetCurveH)(void*,OType*,OType*,unsigned short*);
PDll_GetCurveH Dll_GetCurveH;
typedef void (__stdcall *PDll_GetCurveName)(void*,char*); 
PDll_GetCurveName Dll_GetCurveName;
typedef void* (__stdcall *PDll_SelectOneCurve)(const char*);
PDll_SelectOneCurve Dll_SelectOneCurve;
typedef LongBoolean (__stdcall *PDll_CheckCurves)(void);
PDll_CheckCurves Dll_CheckCurves;
typedef LongBoolean (__stdcall *PDll_SelectDepth)(long*,const char*,void*);
PDll_SelectDepth Dll_SelectDepth;
typedef LongBoolean (__stdcall *PDll_SelectInter)(long*,long*,const char*,void*);
PDll_SelectInter Dll_SelectInter;
typedef LongBoolean (__stdcall *PDll_SelectShift)(long*,const char*);
PDll_SelectShift Dll_SelectShift;
typedef LongBoolean (__stdcall *PDll_SelectValue)(long,float,float,float*,const char*);
PDll_SelectValue Dll_SelectValue;
typedef LongBoolean (__stdcall *PDll_SelectStart)(long*,const char*);
PDll_SelectStart Dll_SelectStart;
typedef LongBoolean (__stdcall *PDll_SelectStartWidth)(long*,long*,const char*);
PDll_SelectStartWidth Dll_SelectStartWidth;
typedef void (__stdcall *PDll_MinInter)(void*,long*,long*);
PDll_MinInter Dll_MinInter;
typedef void (__stdcall *PDll_MaxInter)(void*,long*,long*);
PDll_MaxInter Dll_MaxInter;
typedef float (__stdcall *PDll_GetMainVal)(void*,long,long,long,long,long,long);
PDll_GetMainVal Dll_GetMainVal;
typedef void* (__stdcall *PDll_DuplicateCurve)(void*,long,long);
PDll_DuplicateCurve Dll_DuplicateCurve;
typedef void* (__stdcall *PDll_DuplicateCurveEx)(void*,long,long,const char*,const char*);
PDll_DuplicateCurveEx Dll_DuplicateCurveEx;
typedef void* (__stdcall *PDll_GetWSGroup)(void*);
PDll_GetWSGroup Dll_GetWSGroup;
typedef void* (__stdcall *PDll_GetPlanGroup)(void*);
PDll_GetPlanGroup Dll_GetPlanGroup;
typedef long (__stdcall *PDll_CrvTransform)(OType,OType,unsigned char,void*,TStartTransform,TCrvTransform,TGetTransform,PProcess);
PDll_CrvTransform Dll_CrvTransform;

typedef LongBoolean (__stdcall *PDll_GetDefaultTemplate)(TViewCurveRec*);
PDll_GetDefaultTemplate Dll_GetDefaultTemplate;
typedef long (__stdcall *PDll_SelectFilName)(const char*,const char*,const char*,char*,long,long*);
PDll_SelectFilName Dll_SelectFilName;
typedef long (__stdcall *PDll_SelectFilClassName)(const char *,const char *,char *,long);
PDll_SelectFilClassName Dll_SelectFilClassName;

typedef long (__stdcall *PDll_GetFillStyleCount)(void *);
PDll_GetFillStyleCount Dll_GetFillStyleCount;
typedef LongBoolean (__stdcall *PDll_GetFillStyleBitmap)(void*,const char*,
  long,long,long,long,long,COLORREF*,HBITMAP*Bmp,HPALETTE*);
PDll_GetFillStyleBitmap Dll_GetFillStyleBitmap;
typedef long (__stdcall *PDll_GetFillStyleName)(void*,long,char*,long);
PDll_GetFillStyleName Dll_GetFillStyleName;
typedef long (__stdcall *PDll_GetFillStyleClass)(void*,long,char*,long);
PDll_GetFillStyleClass Dll_GetFillStyleClass;
typedef LongBoolean (__stdcall *PDll_FindFillStyle)(void*,const char*,const char*,long*);
PDll_FindFillStyle Dll_FindFillStyle;


typedef void* (__stdcall *PDll_CreateNewPlansheet)(const char *,const char *);
PDll_CreateNewPlansheet Dll_CreateNewPlansheet;
typedef long (__stdcall *PDll_ReloadConfig)(long,long,const char *,OType);
PDll_ReloadConfig Dll_ReloadConfig;
typedef void* (__stdcall *PDll_GetSheetsList)(void);
PDll_GetSheetsList Dll_GetSheetsList;
typedef void* (__stdcall *PDll_GetSheetWindowsList)(void);
PDll_GetSheetWindowsList Dll_GetSheetWindowsList;
typedef void* (__stdcall *PDll_GetSheetsByWindow)(void*);
PDll_GetSheetsByWindow Dll_GetSheetsByWindow;
typedef void* (__stdcall *PDll_GetWindowBySheet)(void*);
PDll_GetWindowBySheet Dll_GetWindowBySheet;
typedef LongBoolean (__stdcall *PDll_ActivatePlansheet)(void*);
PDll_ActivatePlansheet Dll_ActivatePlansheet;
typedef long (__stdcall *PDll_GetBuildType)(long*);
PDll_GetBuildType Dll_GetBuildType;
typedef LongBoolean (__stdcall *PDll_GetHASPInfo)(THaspInfo*);
PDll_GetHASPInfo Dll_GetHASPInfo;

typedef LongBoolean (__stdcall *PDll_ApplyConds)(char*,long,const char*,
  const char*,TConflictFieldsAction*);
PDll_ApplyConds Dll_ApplyConds;
typedef LongBoolean (__stdcall *PDll_TestData)(OType,const char*,const char*,
  const char*,const char*,const char*,LongBoolean,OType*,long*);
PDll_TestData Dll_TestData;
typedef LongBoolean (__stdcall *PDll_GetLastTestDataColumns)(TColumnsSet*);
PDll_GetLastTestDataColumns Dll_GetLastTestDataColumns;
typedef long (__stdcall *PDll_SelectCurveDataByFilter)(void*,const char*,
  const char*,char*,long,OType*,OType*,long*,long*,long);
PDll_SelectCurveDataByFilter Dll_SelectCurveDataByFilter;
typedef long (__stdcall *PDll_GetSheetSelectMode)(void*,
  long*,long*,long*,long*,long*,long*,long*,long*,long*);
PDll_GetSheetSelectMode Dll_GetSheetSelectMode;
typedef long (__stdcall *PDll_SetSheetSelectMode)(void*,
  long,long,long,long,long,long,long,long,long);
PDll_SetSheetSelectMode Dll_SetSheetSelectMode;
typedef void (__stdcall *PDll_SetTopCaption)(const char*);
PDll_SetTopCaption Dll_SetTopCaption;
typedef long (__stdcall *PDll_GetPrimeParam)(const char*,void*,long);
PDll_GetPrimeParam Dll_GetPrimeParam;
typedef long (__stdcall *PDll_SetPrimeParam)(const char*,void*,long);
PDll_SetPrimeParam Dll_SetPrimeParam;
typedef long (__stdcall *PDll_GetTwoDValuesByDepth)(void*,long,long,
  float*,long,LongBoolean*);
PDll_GetTwoDValuesByDepth Dll_GetTwoDValuesByDepth;
typedef long (__stdcall *PDll_GetTwoDLastRowHeader)(void*,void*,long,long*);
PDll_GetTwoDLastRowHeader Dll_GetTwoDLastRowHeader;
typedef long (__stdcall *PDll_GetTwoDLastChannelHeader)(void*,void*,long,long*);
PDll_GetTwoDLastChannelHeader Dll_GetTwoDLastChannelHeader;
typedef long (__stdcall *PDll_GetTwoDHeader)(void*,void*,long);
PDll_GetTwoDHeader Dll_GetTwoDHeader;
typedef LongBoolean (__stdcall *PDll_GetTwoDDepthIndex)(void*,TPrimeDepthIndex*);
PDll_GetTwoDDepthIndex Dll_GetTwoDDepthIndex;
typedef long (__stdcall *PDll_AddCurveDataToList)(void*,const PTableCurveDataRec);
PDll_AddCurveDataToList Dll_AddCurveDataToList;
typedef LongBoolean (__stdcall *PDll_GetCurveDataFromList)(void*,long,PTableCurveDataRec);
PDll_GetCurveDataFromList Dll_GetCurveDataFromList;
typedef long (__stdcall *PDll_SelectCurves_1)(OType,const char*,long,void*);
PDll_SelectCurves_1 Dll_SelectCurves_1;
typedef LongBoolean (__stdcall *PDll_SelectCurveValue)(void*,float*,const char*);
PDll_SelectCurveValue Dll_SelectCurveValue;
typedef double (__stdcall *PDll_TrackCurveValueFunc)(void*,long,long);
PDll_TrackCurveValueFunc Dll_TrackCurveValueFunc;
typedef long (__stdcall *PDll_SetPrimeCommonCallback)(long,
  TPrimeCommonCallbackFunc,void*,long,long,void*,long,long,void*,long,
  const char*,const char*);
PDll_SetPrimeCommonCallback Dll_SetPrimeCommonCallback;
typedef LongBoolean (__stdcall *PDll_DeletePrimeCallback)(long);
PDll_DeletePrimeCallback Dll_DeletePrimeCallback;
typedef LongBoolean (__stdcall *PDll_IsPrimeCallback)(long);
PDll_IsPrimeCallback Dll_IsPrimeCallback;
typedef LongBoolean (__stdcall *PDll_DeletePrimeCallbacks)(HINSTANCE,long);
PDll_DeletePrimeCallbacks Dll_DeletePrimeCallbacks;
typedef LongBoolean (__stdcall *PDll_PlanObjDragDrop)(void*,void*,long,void*);
PDll_PlanObjDragDrop Dll_PlanObjDragDrop;
typedef long (__stdcall *PDll_PrimeExecuteFunction)(const char*,const char*,void*,void*,void*);
PDll_PrimeExecuteFunction Dll_PrimeExecuteFunction;
typedef long (__stdcall *PDll_GetStandardLayerCodeByIndex)(void*,long,char*,long,long);
PDll_GetStandardLayerCodeByIndex Dll_GetStandardLayerCodeByIndex;
typedef long (__stdcall *PDll_SetStandardLayerCodeByIndex)(void*,long,const char*,long);
PDll_SetStandardLayerCodeByIndex Dll_SetStandardLayerCodeByIndex;
typedef long (__stdcall *PDll_GetLayerIndex)(void*,long);
PDll_GetLayerIndex Dll_GetLayerIndex;
typedef long (__stdcall *PDll_GetTarget)(char*,long,char*,long,char*,long,void*,long);
PDll_GetTarget Dll_GetTarget;
typedef long (__stdcall *PDll_SetTarget)(const char*,const char*,const char*,LongBoolean,void*,long);
PDll_SetTarget Dll_SetTarget;
typedef char* (__stdcall *PDll_PrimeSimpleTranslateString)(char*,char*);
PDll_PrimeSimpleTranslateString Dll_PrimeSimpleTranslateString;


extern "C" LongBoolean Prime32Connect(void){
 hDLL_PRIME32 = GetModuleHandle(PRIME32DLL);
 if (hDLL_PRIME32 != NULL){
	 DSExtConnect();
	 /* Ïîëó÷åíèå àäðåñîâ âûçîâà ôóíêöèé âíåøíåãî ìîäóëÿ */
         Dll_AbsDepthValue = (PDll_AbsDepthValue)GetProcAddress(hDLL_PRIME32, "AbsDepthValue");
         Dll_ActivatePlansheet = (PDll_ActivatePlansheet)GetProcAddress(hDLL_PRIME32, "ActivatePlansheet");
	 Dll_ActiveCount = (PDll_ActiveCount)GetProcAddress(hDLL_PRIME32, "ActiveCount");
	 Dll_ActiveCurves = (PDll_ActiveCurves)GetProcAddress(hDLL_PRIME32, "ActiveCurves");
         Dll_ActiveDViews = (PDll_ActiveDViews)GetProcAddress(hDLL_PRIME32, "ActiveDViews");
	 Dll_ActiveFooterFramesCount = (PDll_ActiveFooterFramesCount)GetProcAddress(hDLL_PRIME32, "ActiveFooterFramesCount");
	 Dll_ActiveFooterFramesList = (PDll_ActiveFooterFramesList)GetProcAddress(hDLL_PRIME32, "ActiveFooterFramesList");
	 Dll_ActiveFramesCount = (PDll_ActiveFramesCount)GetProcAddress(hDLL_PRIME32, "ActiveFramesCount");
	 Dll_ActiveFramesList = (PDll_ActiveFramesList)GetProcAddress(hDLL_PRIME32, "ActiveFramesList");
	 Dll_ActiveList = (PDll_ActiveList)GetProcAddress(hDLL_PRIME32, "ActiveList");
	 Dll_ActivePlastTowers = (PDll_ActivePlastTowers)GetProcAddress(hDLL_PRIME32, "ActivePlastTowers");
	 Dll_ActiveText = (PDll_ActiveText)GetProcAddress(hDLL_PRIME32, "ActiveText");
	 Dll_ActiveTowers = (PDll_ActiveTowers)GetProcAddress(hDLL_PRIME32, "ActiveTowers");
	 Dll_AddPrintInterval = (PDll_AddPrintInterval)GetProcAddress(hDLL_PRIME32, "AddPrintInterval");
	 Dll_AddPrintIntervalAt = (PDll_AddPrintIntervalAt)GetProcAddress(hDLL_PRIME32, "AddPrintIntervalAt");
         Dll_AllocMemLib = (PDll_AllocMemLib)GetProcAddress(hDLL_PRIME32, "AllocMemLib");
         Dll_ApplyConds = (PDll_ApplyConds)GetProcAddress(hDLL_PRIME32, "ApplyConds");
	 Dll_CheckCurves = (PDll_CheckCurves)GetProcAddress(hDLL_PRIME32, "CheckCurves");
	 Dll_ClearState = (PDll_ClearState)GetProcAddress(hDLL_PRIME32, "ClearState");
	 Dll_ClrMessage = (PDll_ClrMessage)GetProcAddress(hDLL_PRIME32, "ClrMessage");
         Dll_CreateHandleInter = (PDll_CreateHandleInter)GetProcAddress(hDLL_PRIME32, "CreateHandleInter");
         Dll_CreateNewPlansheet = (PDll_CreateNewPlansheet)GetProcAddress(hDLL_PRIME32, "CreateNewPlansheet");
	 Dll_CreateTemplateDataObject = (PDll_CreateTemplateDataObject)GetProcAddress(hDLL_PRIME32, "CreateTemplateDataObject");
	 Dll_CreateWSBitmap = (PDll_CreateWSBitmap)GetProcAddress(hDLL_PRIME32, "CreateWSBitmap");
	 Dll_CreateWSChord = (PDll_CreateWSChord)GetProcAddress(hDLL_PRIME32, "CreateWSChord");
	 Dll_CreateWSCurve = (PDll_CreateWSCurve)GetProcAddress(hDLL_PRIME32, "CreateWSCurve");
	 Dll_CreateWSRotCurve = (PDll_CreateWSRotCurve)GetProcAddress(hDLL_PRIME32, "CreateWSRotCurve");
	 Dll_CreateWSDepth = (PDll_CreateWSDepth)GetProcAddress(hDLL_PRIME32, "CreateWSDepth");
	 Dll_CreateWSFills = (PDll_CreateWSFills)GetProcAddress(hDLL_PRIME32, "CreateWSFills");
	 Dll_CreateWSFrame = (PDll_CreateWSFrame)GetProcAddress(hDLL_PRIME32, "CreateWSFrame");
	 Dll_CreateWSInter = (PDll_CreateWSInter)GetProcAddress(hDLL_PRIME32, "CreateWSInter");
	 Dll_CreateWSLgGrid = (PDll_CreateWSLgGrid)GetProcAddress(hDLL_PRIME32, "CreateWSLgGrid");
	 Dll_CreateWSLnGrid = (PDll_CreateWSLnGrid)GetProcAddress(hDLL_PRIME32, "CreateWSLnGrid");
	 Dll_CreateWSNotes = (PDll_CreateWSNotes)GetProcAddress(hDLL_PRIME32, "CreateWSNotes");
         Dll_CreateWSPicture = (PDll_CreateWSPicture)GetProcAddress(hDLL_PRIME32, "CreateWSPicture");
	 Dll_CreateWSPlast = (PDll_CreateWSPlast)GetProcAddress(hDLL_PRIME32, "CreateWSPlast");
	 Dll_CreateWSPoint = (PDll_CreateWSPoint)GetProcAddress(hDLL_PRIME32, "CreateWSPoint");
	 Dll_CreateWSScale = (PDll_CreateWSScale)GetProcAddress(hDLL_PRIME32, "CreateWSScale");
	 Dll_CreateWSTable = (PDll_CreateWSTable)GetProcAddress(hDLL_PRIME32, "CreateWSTable");
	 Dll_CreateWSText = (PDll_CreateWSText)GetProcAddress(hDLL_PRIME32, "CreateWSText");
	 Dll_CreateWSTower = (PDll_CreateWSTower)GetProcAddress(hDLL_PRIME32, "CreateWSTower");
         Dll_CreateWSTwoDCurve = (PDll_CreateWSTwoDCurve)GetProcAddress(hDLL_PRIME32, "CreateWSTwoDCurve");
	 Dll_CrvTransform = (PDll_CrvTransform)GetProcAddress(hDLL_PRIME32, "CrvTransform");
	 Dll_CurrentCurve = (PDll_CurrentCurve)GetProcAddress(hDLL_PRIME32, "CurrentCurve");
	 Dll_CurrentPlansheet = (PDll_CurrentPlansheet)GetProcAddress(hDLL_PRIME32, "CurrentPlansheet");
	 Dll_CurrentTower = (PDll_CurrentTower)GetProcAddress(hDLL_PRIME32, "CurrentTower");
	 Dll_CurrentWindow = (PDll_CurrentWindow)GetProcAddress(hDLL_PRIME32, "CurrentWindow");
         Dll_CurveGetLoadCondition = (PDll_CurveGetLoadCondition)GetProcAddress(hDLL_PRIME32, "CurveGetLoadCondition");
	 Dll_CurveMode = (PDll_CurveMode)GetProcAddress(hDLL_PRIME32, "CurveMode");
         Dll_CurveSetLoadCondition = (PDll_CurveSetLoadCondition)GetProcAddress(hDLL_PRIME32, "CurveSetLoadCondition");
	 Dll_DeleteAllPrintIntervals = (PDll_DeleteAllPrintIntervals)GetProcAddress(hDLL_PRIME32, "DeleteAllPrintIntervals");
	 Dll_DeleteFrames = (PDll_DeleteFrames)GetProcAddress(hDLL_PRIME32, "DeleteFrames");
	 Dll_DeleteObject = (PDll_DeleteObject)GetProcAddress(hDLL_PRIME32, "DeleteObject");
         Dll_DeletePrimeCallback = (PDll_DeletePrimeCallback)GetProcAddress(hDLL_PRIME32, "DeletePrimeCallback");
         Dll_DeletePrimeCallbacks = (PDll_DeletePrimeCallbacks)GetProcAddress(hDLL_PRIME32, "DeletePrimeCallbacks");
	 Dll_DeletePrintInterval = (PDll_DeletePrintInterval)GetProcAddress(hDLL_PRIME32, "DeletePrintInterval");
         Dll_DisableHeaderRedraw = (PDll_DisableHeaderRedraw)GetProcAddress(hDLL_PRIME32, "DisableHeaderRedraw");
	 Dll_DoneObject = (PDll_DoneObject)GetProcAddress(hDLL_PRIME32, "DoneObject");
	 Dll_DrawPlansheet = (PDll_DrawPlansheet)GetProcAddress(hDLL_PRIME32, "DrawPlansheet");
	 Dll_DuplicateCurve = (PDll_DuplicateCurve)GetProcAddress(hDLL_PRIME32, "DuplicateCurve");
	 Dll_DuplicateCurveEx = (PDll_DuplicateCurveEx)GetProcAddress(hDLL_PRIME32, "DuplicateCurveEx");
         Dll_EnableHeaderRedraw = (PDll_EnableHeaderRedraw)GetProcAddress(hDLL_PRIME32, "EnableHeaderRedraw");
	 Dll_ExecuteWindow = (PDll_ExecuteWindow)GetProcAddress(hDLL_PRIME32, "ExecuteWindow");
	 //Dll_FillPString = (PDll_FillPString)GetProcAddress(hDLL_PRIME32, "FillPString");
	 Dll_FindCurveLoadCondition = (PDll_FindCurveLoadCondition)GetProcAddress(hDLL_PRIME32, "FindCurveLoadCondition");
         Dll_FindFillStyle = (PDll_FindFillStyle)GetProcAddress(hDLL_PRIME32, "FindFillStyle");
	 Dll_FindPlanObject = (PDll_FindPlanObject)GetProcAddress(hDLL_PRIME32, "FindPlanObject");
	 Dll_FindViewByID = (PDll_FindViewByID)GetProcAddress(hDLL_PRIME32, "FindViewByID");
	 Dll_FooterFrameCount = (PDll_FooterFrameCount)GetProcAddress(hDLL_PRIME32, "FooterFrameCount");
	 Dll_FooterFrameList = (PDll_FooterFrameList)GetProcAddress(hDLL_PRIME32, "FooterFrameList");
	 Dll_FrameCount = (PDll_FrameCount)GetProcAddress(hDLL_PRIME32, "FrameCount");
	 Dll_FrameDataSize = (PDll_FrameDataSize)GetProcAddress(hDLL_PRIME32, "FrameDataSize");
	 Dll_FrameGetData = (PDll_FrameGetData)GetProcAddress(hDLL_PRIME32, "FrameGetData");
	 Dll_FrameGetStart = (PDll_FrameGetStart)GetProcAddress(hDLL_PRIME32, "FrameGetStart");
	 Dll_FrameGetState = (PDll_FrameGetState)GetProcAddress(hDLL_PRIME32, "FrameGetState");
	 Dll_FrameGetWidth = (PDll_FrameGetWidth)GetProcAddress(hDLL_PRIME32, "FrameGetWidth");
	 Dll_FrameList = (PDll_FrameList)GetProcAddress(hDLL_PRIME32, "FrameList");
	 Dll_FrameSetData = (PDll_FrameSetData)GetProcAddress(hDLL_PRIME32, "FrameSetData");
	 Dll_FrameSetStart = (PDll_FrameSetStart)GetProcAddress(hDLL_PRIME32, "FrameSetStart");
	 Dll_FrameSetState = (PDll_FrameSetState)GetProcAddress(hDLL_PRIME32, "FrameSetState");
	 Dll_FrameSetWidth = (PDll_FrameSetWidth)GetProcAddress(hDLL_PRIME32, "FrameSetWidth");
	 Dll_FreeMemLib = (PDll_FreeMemLib)GetProcAddress(hDLL_PRIME32, "FreeMemLib");
	 Dll_FreePString = (PDll_FreePString)GetProcAddress(hDLL_PRIME32, "FreePString");
	 Dll_GetBuildType = (PDll_GetBuildType)GetProcAddress(hDLL_PRIME32, "GetBuildType");
	 Dll_GetCurveH = (PDll_GetCurveH)GetProcAddress(hDLL_PRIME32, "GetCurveH");
	 Dll_GetCurveName = (PDll_GetCurveName)GetProcAddress(hDLL_PRIME32, "GetCurveName");
	 Dll_GetDefaultTemplate = (PDll_GetDefaultTemplate)GetProcAddress(hDLL_PRIME32, "GetDefaultTemplate");
         Dll_GetDepthByAbsDepth = (PDll_GetDepthByAbsDepth)GetProcAddress(hDLL_PRIME32, "GetDepthByAbsDepth");
         Dll_GetFillStyleBitmap = (PDll_GetFillStyleBitmap)GetProcAddress(hDLL_PRIME32, "GetFillStyleBitmap");
         Dll_GetFillStyleClass = (PDll_GetFillStyleClass)GetProcAddress(hDLL_PRIME32, "GetFillStyleClass");
         Dll_GetFillStyleCount = (PDll_GetFillStyleCount)GetProcAddress(hDLL_PRIME32, "GetFillStyleCount");
         Dll_GetFillStyleName = (PDll_GetFillStyleName)GetProcAddress(hDLL_PRIME32, "GetFillStyleName");
	 Dll_GetHASPFlag = (PDll_GetHASPFlag)GetProcAddress(hDLL_PRIME32, "GetHASPFlag");
	 Dll_GetHASPInfo = (PDll_GetHASPInfo)GetProcAddress(hDLL_PRIME32, "GetHASPInfo");
	 Dll_GetHandleInter = (PDll_GetHandleInter)GetProcAddress(hDLL_PRIME32, "GetHandleInter");
	 Dll_GetLastTestDataColumns = (PDll_GetLastTestDataColumns)GetProcAddress(hDLL_PRIME32, "GetLastTestDataColumns");
	 Dll_GetLayerIndex = (PDll_GetLayerIndex)GetProcAddress(hDLL_PRIME32, "GetLayerIndex");
	 Dll_GetLegendByDepth = (PDll_GetLegendByDepth)GetProcAddress(hDLL_PRIME32, "GetLegendByDepth");
	 Dll_GetLitholByDepth = (PDll_GetLitholByDepth)GetProcAddress(hDLL_PRIME32, "GetLitholByDepth");
	 Dll_GetMainVal = (PDll_GetMainVal)GetProcAddress(hDLL_PRIME32, "GetMainVal");
	 Dll_GetMemLib = (PDll_GetMemLib)GetProcAddress(hDLL_PRIME32, "GetMemLib");
	 Dll_GetOneCurve = (PDll_GetOneCurve)GetProcAddress(hDLL_PRIME32, "GetOneCurve");
	 Dll_GetOneCurveByName = (PDll_GetOneCurveByName)GetProcAddress(hDLL_PRIME32, "GetOneCurveByName");
	 //Dll_GetPString = (PDll_GetPString)GetProcAddress(hDLL_PRIME32, "GetPString");
	 Dll_GetPlanActiveCount = (PDll_GetPlanActiveCount)GetProcAddress(hDLL_PRIME32, "GetPlanActiveCount");
	 Dll_GetPlanActiveList = (PDll_GetPlanActiveList)GetProcAddress(hDLL_PRIME32, "GetPlanActiveList");
	 Dll_GetPlanCount = (PDll_GetPlanCount)GetProcAddress(hDLL_PRIME32, "GetPlanCount");
	 Dll_GetPlanDepth = (PDll_GetPlanDepth)GetProcAddress(hDLL_PRIME32, "GetPlanDepth");
	 Dll_GetPlanGroup = (PDll_GetPlanGroup)GetProcAddress(hDLL_PRIME32, "GetPlanGroup");
	 Dll_GetPlanList = (PDll_GetPlanList)GetProcAddress(hDLL_PRIME32, "GetPlanList");
	 Dll_GetPlanListX = (PDll_GetPlanListX)GetProcAddress(hDLL_PRIME32, "GetPlanListX");
	 Dll_GetPlanRoof = (PDll_GetPlanRoof)GetProcAddress(hDLL_PRIME32, "GetPlanRoof");
	 Dll_GetPlanScale = (PDll_GetPlanScale)GetProcAddress(hDLL_PRIME32, "GetPlanScale");
	 Dll_GetPlanSole = (PDll_GetPlanSole)GetProcAddress(hDLL_PRIME32, "GetPlanSole");
	 Dll_GetPlanTemplate = (PDll_GetPlanTemplate)GetProcAddress(hDLL_PRIME32, "GetPlanTemplate");
	 Dll_GetPlanTitle = (PDll_GetPlanTitle)GetProcAddress(hDLL_PRIME32, "GetPlanTitle");
	 Dll_GetPlanWidth = (PDll_GetPlanWidth)GetProcAddress(hDLL_PRIME32, "GetPlanWidth");
	 Dll_GetPlastTower = (PDll_GetPlastTower)GetProcAddress(hDLL_PRIME32, "GetPlastTower");
    Dll_GetPrimeParam = (PDll_GetPrimeParam)GetProcAddress(hDLL_PRIME32, "GetPrimeParam");
    Dll_GetPrimeSettingsDir = (PDll_GetPrimeSettingsDir)GetProcAddress(hDLL_PRIME32, "GetPrimeSettingsDir");
    Dll_GetPrimeVersion = (PDll_GetPrimeVersion)GetProcAddress(hDLL_PRIME32, "GetPrimeVersion");
    Dll_GetPrimeWorkDir = (PDll_GetPrimeWorkDir)GetProcAddress(hDLL_PRIME32, "GetPrimeWorkDir");
    Dll_GetPrimeWorkBaseDir = (PDll_GetPrimeWorkBaseDir)GetProcAddress(hDLL_PRIME32, "GetPrimeWorkBaseDir");
    Dll_SetPrimeWorkBaseDir = (PDll_SetPrimeWorkBaseDir)GetProcAddress(hDLL_PRIME32, "SetPrimeWorkBaseDir");
	 Dll_GetPrintInterval = (PDll_GetPrintInterval)GetProcAddress(hDLL_PRIME32, "GetPrintInterval");
	 Dll_GetPrintIntervalsCount = (PDll_GetPrintIntervalsCount)GetProcAddress(hDLL_PRIME32, "GetPrintIntervalsCount");
	 Dll_GetReportCount = (PDll_GetReportCount)GetProcAddress(hDLL_PRIME32, "GetReportCount");
	 Dll_GetReportHandle = (PDll_GetReportHandle)GetProcAddress(hDLL_PRIME32, "GetReportHandle");
    Dll_GetSheetSelectMode = (PDll_GetSheetSelectMode)GetProcAddress(hDLL_PRIME32, "GetSheetSelectMode");
    Dll_GetSheetsByWindow = (PDll_GetSheetsByWindow)GetProcAddress(hDLL_PRIME32, "GetSheetsByWindow");
    Dll_GetSheetsList = (PDll_GetSheetsList)GetProcAddress(hDLL_PRIME32, "GetSheetsList");
    Dll_GetSheetWindowsList = (PDll_GetSheetWindowsList)GetProcAddress(hDLL_PRIME32, "GetSheetWindowsList");
    Dll_GetStandardLayerCodeByIndex = (PDll_GetStandardLayerCodeByIndex)GetProcAddress(hDLL_PRIME32, "GetStandardLayerCodeByIndex");
    Dll_GetStratByDepth = (PDll_GetStratByDepth)GetProcAddress(hDLL_PRIME32, "GetStratByDepth");
    Dll_GetTarget = (PDll_GetTarget)GetProcAddress(hDLL_PRIME32, "GetTarget");
	 Dll_GetTemplateObject = (PDll_GetTemplateObject)GetProcAddress(hDLL_PRIME32, "GetTemplateObject");
    Dll_GetTowerPlastArray = (PDll_GetTowerPlastArray)GetProcAddress(hDLL_PRIME32, "GetTowerPlastArray");
	 Dll_GetTrackDepth = (PDll_GetTrackDepth)GetProcAddress(hDLL_PRIME32, "GetTrackDepth");
	 Dll_GetTrackStart = (PDll_GetTrackStart)GetProcAddress(hDLL_PRIME32, "GetTrackStart");
    Dll_GetTrackUserString = (PDll_GetTrackUserString)GetProcAddress(hDLL_PRIME32, "GetTrackUserString");
    Dll_GetTrackUserValue = (PDll_GetTrackUserValue)GetProcAddress(hDLL_PRIME32, "GetTrackUserValue");
	 Dll_GetTrackValue = (PDll_GetTrackValue)GetProcAddress(hDLL_PRIME32, "GetTrackValue");
    Dll_GetTwoDDepthIndex = (PDll_GetTwoDDepthIndex)GetProcAddress(hDLL_PRIME32, "GetTwoDDepthIndex");
    Dll_GetTwoDHeader = (PDll_GetTwoDHeader)GetProcAddress(hDLL_PRIME32, "GetTwoDHeader");
    Dll_GetTwoDLastRowHeader = (PDll_GetTwoDLastRowHeader)GetProcAddress(hDLL_PRIME32, "GetTwoDLastRowHeader");
    Dll_GetTwoDLastChannelHeader = (PDll_GetTwoDLastChannelHeader)GetProcAddress(hDLL_PRIME32, "GetTwoDLastChannelHeader");
    Dll_GetTwoDValuesByDepth = (PDll_GetTwoDValuesByDepth)GetProcAddress(hDLL_PRIME32, "GetTwoDValuesByDepth");
	 Dll_GetViewID = (PDll_GetViewID)GetProcAddress(hDLL_PRIME32, "GetViewID");
	 Dll_GetWSGroup = (PDll_GetWSGroup)GetProcAddress(hDLL_PRIME32, "GetWSGroup");
    Dll_GetWindowBySheet = (PDll_GetWindowBySheet)GetProcAddress(hDLL_PRIME32, "GetWindowBySheet");
	 Dll_GetWorkSpace = (PDll_GetWorkSpace)GetProcAddress(hDLL_PRIME32, "GetWorkSpace");
	 Dll_HeaderState = (PDll_HeaderState)GetProcAddress(hDLL_PRIME32, "HeaderState");
	 Dll_HideHeader = (PDll_HideHeader)GetProcAddress(hDLL_PRIME32, "HideHeader");
	 Dll_InitEmptyList = (PDll_InitEmptyList)GetProcAddress(hDLL_PRIME32, "InitEmptyList");
	 Dll_InitList = (PDll_InitList)GetProcAddress(hDLL_PRIME32, "InitList");
	 Dll_InitStringList = (PDll_InitStringList)GetProcAddress(hDLL_PRIME32, "InitStringList");
	 Dll_InitUnsortList = (PDll_InitUnsortList)GetProcAddress(hDLL_PRIME32, "InitUnsortList");
	 Dll_InsertFrames = (PDll_InsertFrames)GetProcAddress(hDLL_PRIME32, "InsertFrames");
	 Dll_InsertObject = (PDll_InsertObject)GetProcAddress(hDLL_PRIME32, "InsertObject");
	 Dll_InsertOrReplaceObject = (PDll_InsertOrReplaceObject)GetProcAddress(hDLL_PRIME32, "InsertOrReplaceObject");
	 Dll_InterTable = (PDll_InterTable)GetProcAddress(hDLL_PRIME32, "InterTable");
     Dll_IsPrimeCallback = (PDll_IsPrimeCallback)GetProcAddress(hDLL_PRIME32, "IsPrimeCallback");
	 Dll_LenPString = (PDll_LenPString)GetProcAddress(hDLL_PRIME32, "LenPString");
	 Dll_ListAt = (PDll_ListAt)GetProcAddress(hDLL_PRIME32, "ListAt");
	 Dll_ListAtDelete = (PDll_ListAtDelete)GetProcAddress(hDLL_PRIME32, "ListAtDelete");
	 Dll_ListAtFree = (PDll_ListAtFree)GetProcAddress(hDLL_PRIME32, "ListAtFree");
	 Dll_ListAtInsert = (PDll_ListAtInsert)GetProcAddress(hDLL_PRIME32, "ListAtInsert");
	 Dll_ListAtPut = (PDll_ListAtPut)GetProcAddress(hDLL_PRIME32, "ListAtPut");
	 Dll_ListCount = (PDll_ListCount)GetProcAddress(hDLL_PRIME32, "ListCount");
	 Dll_ListDelete = (PDll_ListDelete)GetProcAddress(hDLL_PRIME32, "ListDelete");
	 Dll_ListDeleteAll = (PDll_ListDeleteAll)GetProcAddress(hDLL_PRIME32, "ListDeleteAll");
	 Dll_ListFree = (PDll_ListFree)GetProcAddress(hDLL_PRIME32, "ListFree");
	 Dll_ListFreeAll = (PDll_ListFreeAll)GetProcAddress(hDLL_PRIME32, "ListFreeAll");
	 Dll_ListIndexOf = (PDll_ListIndexOf)GetProcAddress(hDLL_PRIME32, "ListIndexOf");
	 Dll_ListInsert = (PDll_ListInsert)GetProcAddress(hDLL_PRIME32, "ListInsert");
	 Dll_ListPack = (PDll_ListPack)GetProcAddress(hDLL_PRIME32, "ListPack");
	 Dll_ListSearch = (PDll_ListSearch)GetProcAddress(hDLL_PRIME32, "ListSearch");
	 Dll_MaxInter = (PDll_MaxInter)GetProcAddress(hDLL_PRIME32, "MaxInter");
	 //Dll_MemPString = (PDll_MemPString)GetProcAddress(hDLL_PRIME32, "MemPString");
	 Dll_MinInter = (PDll_MinInter)GetProcAddress(hDLL_PRIME32, "MinInter");
	 Dll_NewPString = (PDll_NewPString)GetProcAddress(hDLL_PRIME32, "NewPString");
	 Dll_ObjectCount = (PDll_ObjectCount)GetProcAddress(hDLL_PRIME32, "ObjectCount");
	 Dll_ObjectList = (PDll_ObjectList)GetProcAddress(hDLL_PRIME32, "ObjectList");
	 Dll_PCharDispose = (PDll_PCharDispose)GetProcAddress(hDLL_PRIME32, "PCharDispose");
         Dll_PlanObjDragDrop = (PDll_PlanObjDragDrop)GetProcAddress(hDLL_PRIME32, "PlanObjDragDrop");
	 Dll_PointTable = (PDll_PointTable)GetProcAddress(hDLL_PRIME32, "PointTable");
	 Dll_Prime32Handle = (PDll_Prime32Handle)GetProcAddress(hDLL_PRIME32, "Prime32Handle");
	 Dll_PrimeBringToFront = (PDll_PrimeBringToFront)GetProcAddress(hDLL_PRIME32, "PrimeBringToFront");
    Dll_PrimeDisableUnload = (PDll_PrimeDisableUnload)GetProcAddress(hDLL_PRIME32, "PrimeDisableUnload");
    Dll_PrimeEnableUnload = (PDll_PrimeEnableUnload)GetProcAddress(hDLL_PRIME32, "PrimeEnableUnload");
    Dll_PrimeExecuteFunction = (PDll_PrimeExecuteFunction)GetProcAddress(hDLL_PRIME32, "PrimeExecuteFunction");
    Dll_PrimeSimpleTranslateString = (PDll_PrimeSimpleTranslateString)GetProcAddress(hDLL_PRIME32, "PrimeSimpleTranslateString");
    Dll_PrimeTerminating = (PDll_PrimeTerminating)GetProcAddress(hDLL_PRIME32, "PrimeTerminating");
    Dll_PrimeUnloadEnabled = (PDll_PrimeUnloadEnabled)GetProcAddress(hDLL_PRIME32, "PrimeUnloadEnabled");
	 Dll_PutMessage = (PDll_PutMessage)GetProcAddress(hDLL_PRIME32, "PutMessage");
	 //Dll_PutPString = (PDll_PutPString)GetProcAddress(hDLL_PRIME32, "PutPString");
         Dll_ReallocMemLib = (PDll_ReallocMemLib)GetProcAddress(hDLL_PRIME32, "ReallocMemLib");
	 Dll_RedrawObject = (PDll_RedrawObject)GetProcAddress(hDLL_PRIME32, "RedrawObject");
	 Dll_RedrawObjects = (PDll_RedrawObjects)GetProcAddress(hDLL_PRIME32, "RedrawObjects");
         Dll_RegisterPrimeWindow = (PDll_RegisterPrimeWindow)GetProcAddress(hDLL_PRIME32, "RegisterPrimeWindow");
         Dll_RegisterPrimeWindowAt = (PDll_RegisterPrimeWindowAt)GetProcAddress(hDLL_PRIME32, "RegisterPrimeWindowAt");
         Dll_ReloadConfig = (PDll_ReloadConfig)GetProcAddress(hDLL_PRIME32, "ReloadConfig");
	 Dll_RestoreState = (PDll_RestoreState)GetProcAddress(hDLL_PRIME32, "RestoreState");
	 Dll_SaveState = (PDll_SaveState)GetProcAddress(hDLL_PRIME32, "SaveState");
	 Dll_SelectCurve = (PDll_SelectCurve)GetProcAddress(hDLL_PRIME32, "SelectCurve");
         Dll_SelectCurveDataByFilter = (PDll_SelectCurveDataByFilter)GetProcAddress(hDLL_PRIME32, "SelectCurveDataByFilter");
         Dll_SelectCurveValue = (PDll_SelectCurveValue)GetProcAddress(hDLL_PRIME32, "SelectCurveValue");
	 Dll_SelectDepth = (PDll_SelectDepth)GetProcAddress(hDLL_PRIME32, "SelectDepth");
	 //Dll_SelectDepthEx = (PDll_SelectDepthEx)GetProcAddress(hDLL_PRIME32, "SelectDepthEx");
	 Dll_SelectDView = (PDll_SelectDView)GetProcAddress(hDLL_PRIME32, "SelectDView");
         Dll_SelectFilClassName = (PDll_SelectFilClassName)GetProcAddress(hDLL_PRIME32, "SelectFilClassName");
         Dll_SelectFilName = (PDll_SelectFilName)GetProcAddress(hDLL_PRIME32, "SelectFilName");
	 Dll_SelectInter = (PDll_SelectInter)GetProcAddress(hDLL_PRIME32, "SelectInter");
	 //Dll_SelectInterEx = (PDll_SelectInterEx)GetProcAddress(hDLL_PRIME32, "SelectInterEx");
         Dll_SelectObject = (PDll_SelectObject)GetProcAddress(hDLL_PRIME32, "SelectObject");
         Dll_SelectObjectByType = (PDll_SelectObjectByType)GetProcAddress(hDLL_PRIME32, "SelectObjectByType");
	 Dll_SelectOneCurve = (PDll_SelectOneCurve)GetProcAddress(hDLL_PRIME32, "SelectOneCurve");
	 Dll_SelectPlastTower = (PDll_SelectPlastTower)GetProcAddress(hDLL_PRIME32, "SelectPlastTower");
	 Dll_SelectShift = (PDll_SelectShift)GetProcAddress(hDLL_PRIME32, "SelectShift");
	 Dll_SelectStart = (PDll_SelectStart)GetProcAddress(hDLL_PRIME32, "SelectStart");
	 Dll_SelectStartWidth = (PDll_SelectStartWidth)GetProcAddress(hDLL_PRIME32, "SelectStartWidth");
	 Dll_SelectText = (PDll_SelectText)GetProcAddress(hDLL_PRIME32, "SelectText");
	 Dll_SelectTower = (PDll_SelectTower)GetProcAddress(hDLL_PRIME32, "SelectTower");
         Dll_SelectTwoDCurve = (PDll_SelectTwoDCurve)GetProcAddress(hDLL_PRIME32, "SelectTwoDCurve");
	 Dll_SelectValue = (PDll_SelectValue)GetProcAddress(hDLL_PRIME32, "SelectValue");
	 Dll_SetLeftCurve = (PDll_SetLeftCurve)GetProcAddress(hDLL_PRIME32, "SetLeftCurve");
         Dll_SetPlanDepth = (PDll_SetPlanDepth)GetProcAddress(hDLL_PRIME32, "SetPlanDepth");
	 Dll_SetPlanRoof = (PDll_SetPlanRoof)GetProcAddress(hDLL_PRIME32, "SetPlanRoof");
	 Dll_SetPlanScale = (PDll_SetPlanScale)GetProcAddress(hDLL_PRIME32, "SetPlanScale");
	 Dll_SetPlanSole = (PDll_SetPlanSole)GetProcAddress(hDLL_PRIME32, "SetPlanSole");
	 Dll_SetPlanWidth = (PDll_SetPlanWidth)GetProcAddress(hDLL_PRIME32, "SetPlanWidth");
	 Dll_SetPrimeCommonCallback = (PDll_SetPrimeCommonCallback)(hDLL_PRIME32, "SetPrimeCommonCallback");
         Dll_SetPrimeParam = (PDll_SetPrimeParam)GetProcAddress(hDLL_PRIME32, "SetPrimeParam");
	 Dll_SetPrintInterval = (PDll_SetPrintInterval)GetProcAddress(hDLL_PRIME32, "SetPrintInterval");
	 Dll_SetReportHandle = (PDll_SetReportHandle)GetProcAddress(hDLL_PRIME32, "SetReportHandle");
	 Dll_SetRightCurve = (PDll_SetRightCurve)GetProcAddress(hDLL_PRIME32, "SetRightCurve");
    Dll_SetSheetSelectMode = (PDll_SetSheetSelectMode)GetProcAddress(hDLL_PRIME32, "SetSheetSelectMode");
    Dll_SetStandardLayerCodeByIndex = (PDll_SetStandardLayerCodeByIndex)GetProcAddress(hDLL_PRIME32, "SetStandardLayerCodeByIndex");
    Dll_SetTarget = (PDll_SetTarget)GetProcAddress(hDLL_PRIME32, "SetTarget");
	 Dll_SetTemplateObject = (PDll_SetTemplateObject)GetProcAddress(hDLL_PRIME32, "SetTemplateObject");
    Dll_SetTopCaption = (PDll_SetTopCaption)GetProcAddress(hDLL_PRIME32, "SetTopCaption");
	 Dll_SetTrackCurve = (PDll_SetTrackCurve)GetProcAddress(hDLL_PRIME32, "SetTrackCurve");
	 Dll_SetTrackDepth = (PDll_SetTrackDepth)GetProcAddress(hDLL_PRIME32, "SetTrackDepth");
	 Dll_SetTrackFormat = (PDll_SetTrackFormat)GetProcAddress(hDLL_PRIME32, "SetTrackFormat");
	 Dll_SetTrackMinim = (PDll_SetTrackMinim)GetProcAddress(hDLL_PRIME32, "SetTrackMinim");
	 Dll_SetTrackRoof = (PDll_SetTrackRoof)GetProcAddress(hDLL_PRIME32, "SetTrackRoof");
	 Dll_SetTrackScale = (PDll_SetTrackScale)GetProcAddress(hDLL_PRIME32, "SetTrackScale");
	 Dll_SetTrackShift = (PDll_SetTrackShift)GetProcAddress(hDLL_PRIME32, "SetTrackShift");
	 Dll_SetTrackSole = (PDll_SetTrackSole)GetProcAddress(hDLL_PRIME32, "SetTrackSole");
	 Dll_SetTrackStart = (PDll_SetTrackStart)GetProcAddress(hDLL_PRIME32, "SetTrackStart");
         Dll_SetTrackUserStrCallback = (PDll_SetTrackUserStrCallback)GetProcAddress(hDLL_PRIME32, "SetTrackUserStrCallback");
         Dll_SetTrackUserValueCallback = (PDll_SetTrackUserValueCallback)GetProcAddress(hDLL_PRIME32, "SetTrackUserValueCallback");
	 Dll_SetTrackValue = (PDll_SetTrackValue)GetProcAddress(hDLL_PRIME32, "SetTrackValue");
	 Dll_SetupState = (PDll_SetupState)GetProcAddress(hDLL_PRIME32, "SetupState");
	 Dll_ShowHeader = (PDll_ShowHeader)GetProcAddress(hDLL_PRIME32, "ShowHeader");
	 Dll_StartProcess = (PDll_StartProcess)GetProcAddress(hDLL_PRIME32, "StartProcess");
	 Dll_StepProcess = (PDll_StepProcess)GetProcAddress(hDLL_PRIME32, "StepProcess");
	 Dll_StopProcess = (PDll_StopProcess)GetProcAddress(hDLL_PRIME32, "StopProcess");
         Dll_StrictActiveCount = (PDll_StrictActiveCount)GetProcAddress(hDLL_PRIME32, "StrictActiveCount");
         Dll_StrictActiveList = (PDll_StrictActiveList)GetProcAddress(hDLL_PRIME32, "StrictActiveList");
         Dll_StrictObjectCount = (PDll_StrictObjectCount)GetProcAddress(hDLL_PRIME32, "StrictObjectCount");
         Dll_StrictObjectList = (PDll_StrictObjectList)GetProcAddress(hDLL_PRIME32, "StrictObjectList");
         Dll_TestData = (PDll_TestData)GetProcAddress(hDLL_PRIME32, "TestData");
         Dll_TrackCurveValueFunc = (PDll_TrackCurveValueFunc)GetProcAddress(hDLL_PRIME32, "TrackCurveValueFunc");
	 Dll_TrackData = (PDll_TrackData)GetProcAddress(hDLL_PRIME32, "TrackData");
         Dll_UnregisterPrimeWindow = (PDll_UnregisterPrimeWindow)GetProcAddress(hDLL_PRIME32, "UnregisterPrimeWindow");
	 Dll_WSActual = (PDll_WSActual)GetProcAddress(hDLL_PRIME32, "WSActual");
	 Dll_WSCurveActual = (PDll_WSCurveActual)GetProcAddress(hDLL_PRIME32, "WSCurveActual");
	 Dll_WSCurveCount = (PDll_WSCurveCount)GetProcAddress(hDLL_PRIME32, "WSCurveCount");
	 Dll_WSCurveDepth = (PDll_WSCurveDepth)GetProcAddress(hDLL_PRIME32, "WSCurveDepth");
	 Dll_WSCurveIndex = (PDll_WSCurveIndex)GetProcAddress(hDLL_PRIME32, "WSCurveIndex");
	 Dll_WSCurveLinear = (PDll_WSCurveLinear)GetProcAddress(hDLL_PRIME32, "WSCurveLinear");
	 Dll_WSCurveMinMidMax = (PDll_WSCurveMinMidMax)GetProcAddress(hDLL_PRIME32, "WSCurveMinMidMax");
	 Dll_WSCurveMinMidMaxH = (PDll_WSCurveMinMidMaxH)GetProcAddress(hDLL_PRIME32, "WSCurveMinMidMaxH");
	 Dll_WSCurveSetTemplate = (PDll_WSCurveSetTemplate)GetProcAddress(hDLL_PRIME32, "WSCurveSetTemplate");
	 Dll_WSCurveValue = (PDll_WSCurveValue)GetProcAddress(hDLL_PRIME32, "WSCurveValue");
	 Dll_WSCurveValueStr = (PDll_WSCurveValueStr)GetProcAddress(hDLL_PRIME32, "WSCurveValueStr");
	 Dll_WSDataSize = (PDll_WSDataSize)GetProcAddress(hDLL_PRIME32, "WSDataSize");
	 Dll_WSGetData = (PDll_WSGetData)GetProcAddress(hDLL_PRIME32, "WSGetData");
	 Dll_WSGetDialog = (PDll_WSGetDialog)GetProcAddress(hDLL_PRIME32, "WSGetDialog");
	 Dll_WSGetState = (PDll_WSGetState)GetProcAddress(hDLL_PRIME32, "WSGetState");
	 Dll_WSIGFExec = (PDll_WSIGFExec)GetProcAddress(hDLL_PRIME32, "WSIGFExec");
	 Dll_WSMake = (PDll_WSMake)GetProcAddress(hDLL_PRIME32, "WSMake");
	 Dll_WSName = (PDll_WSName)GetProcAddress(hDLL_PRIME32, "WSName");
         Dll_WSNBRoof = (PDll_WSNBRoof)GetProcAddress(hDLL_PRIME32, "WSNBRoof");
         Dll_WSNBSole = (PDll_WSNBSole)GetProcAddress(hDLL_PRIME32, "WSNBSole");
	 Dll_WSReset = (PDll_WSReset)GetProcAddress(hDLL_PRIME32, "WSReset");
	 Dll_WSRoof = (PDll_WSRoof)GetProcAddress(hDLL_PRIME32, "WSRoof");
	 Dll_WSSetData = (PDll_WSSetData)GetProcAddress(hDLL_PRIME32, "WSSetData");
	 Dll_WSSetDialog = (PDll_WSSetDialog)GetProcAddress(hDLL_PRIME32, "WSSetDialog");
	 Dll_WSSetStart = (PDll_WSSetStart)GetProcAddress(hDLL_PRIME32, "WSSetStart");
	 Dll_WSSetState = (PDll_WSSetState)GetProcAddress(hDLL_PRIME32, "WSSetState");
	 Dll_WSSetWidth = (PDll_WSSetWidth)GetProcAddress(hDLL_PRIME32, "WSSetWidth");
	 Dll_WSSole = (PDll_WSSole)GetProcAddress(hDLL_PRIME32, "WSSole");
	 Dll_WSStart = (PDll_WSStart)GetProcAddress(hDLL_PRIME32, "WSStart");
	 Dll_WSState = (PDll_WSState)GetProcAddress(hDLL_PRIME32, "WSState");
	 Dll_WSType = (PDll_WSType)GetProcAddress(hDLL_PRIME32, "WSType");
	 Dll_WSWidth = (PDll_WSWidth)GetProcAddress(hDLL_PRIME32, "WSWidth");
	 Dll_WaitMessage = (PDll_WaitMessage)GetProcAddress(hDLL_PRIME32, "WaitMessage");
	 Dll_WindowFileName = (PDll_WindowFileName)GetProcAddress(hDLL_PRIME32, "WindowFileName");
	 Dll_WindowTypeName = (PDll_WindowTypeName)GetProcAddress(hDLL_PRIME32, "WindowTypeName");
	 return true;
	}
	else { return false; };
}

extern "C" LongBoolean Prime32CheckConnect(void)
{
  if (!hDLL_PRIME32)
  {
    return Prime32Connect();
  }
  else return true;
}


/*==================================================*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*=                                                =*/
/*==================================================*/
unsigned char GetHASPFlag(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetHASPFlag)) { return -1; }
	else { return Dll_GetHASPFlag(); }
}

long WSIGFExec(const char *ExeName,const char *CmdLine,LongBoolean TextMode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSIGFExec)) { return -1; }
	else { return Dll_WSIGFExec(ExeName,CmdLine,TextMode); }
}

HWND Prime32Handle(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_Prime32Handle)) { return NULL; }
	else { return Dll_Prime32Handle(); }
}

void PrimeBringToFront(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PrimeBringToFront)) {  }
	else { Dll_PrimeBringToFront(); }
}

long GetPrimeWorkDir(char *lpDirName,long nSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPrimeWorkDir)) { return -1; }
	else { return Dll_GetPrimeWorkDir(lpDirName,nSize); }
}

long GetPrimeWorkBaseDir(char *lpDirName,long nSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPrimeWorkBaseDir)) { return -1; }
	else { return Dll_GetPrimeWorkBaseDir(lpDirName,nSize); }
}

LongBoolean SetPrimeWorkBaseDir(const char *NewValue){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPrimeWorkBaseDir)) { return false; }
	else { return Dll_SetPrimeWorkBaseDir(NewValue); }
}

long GetPrimeSettingsDir(char *lpDirName,long nSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPrimeSettingsDir)) { return -1; }
	else { return Dll_GetPrimeSettingsDir(lpDirName,nSize); }
}

long GetPrimeVersion(char *lpVersion,long nSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPrimeVersion)) { return -1; }
	else { return Dll_GetPrimeVersion(lpVersion,nSize); }
}

void PrimeDisableUnload(HINSTANCE LibHandle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PrimeDisableUnload)) { }
	else { Dll_PrimeDisableUnload(LibHandle); }
}

void PrimeEnableUnload(HINSTANCE LibHandle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PrimeEnableUnload)) { }
	else { Dll_PrimeEnableUnload(LibHandle); }
}

LongBoolean PrimeUnloadEnabled(HINSTANCE LibHandle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PrimeUnloadEnabled)) { return false; }
	else { return Dll_PrimeUnloadEnabled(LibHandle); }
}

LongBoolean PrimeTerminating(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PrimeTerminating)) { return false; }
	else { return Dll_PrimeTerminating(); }
}

void DoneObject(void* P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DoneObject)) {  }
	else { Dll_DoneObject(P); }
}

PPasString NewPString(const char* S){
	if ((hDLL_PRIME32 == NULL)||(!Dll_NewPString)) { return NULL; }
	else { return Dll_NewPString(S); }
}

unsigned char LenPString(PPasString P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_LenPString)) { return 0; }
	else { return Dll_LenPString(P); }
}

void FreePString(PPasString P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FreePString)) {  }
	else { Dll_FreePString(P); }
}

void* GetMemLib(long ASize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetMemLib)) { return NULL; }
	else { return Dll_GetMemLib(ASize); }
}

void FreeMemLib(void *P,long ASize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FreeMemLib)) {  }
	else { Dll_FreeMemLib(P,ASize); }
}

void* AllocMemLib(long ASize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_AllocMemLib)) { return NULL; }
	else { return Dll_AllocMemLib(ASize); }
}

void ReallocMemLib(void** P, long NewSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ReallocMemLib)) {  }
	else { Dll_ReallocMemLib(P,NewSize); }
}

void  PCharDispose(char *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PCharDispose)) {  }
	else { Dll_PCharDispose(P); }
}

void*  InitList(long Limit,long Delta){
	if ((hDLL_PRIME32 == NULL)||(!Dll_InitList)) { return NULL; }
	else { return Dll_InitList(Limit,Delta); }
}

void*  InitStringList(long Limit,long Delta){
	if ((hDLL_PRIME32 == NULL)||(!Dll_InitStringList)) { return NULL; }
	else { return Dll_InitStringList(Limit,Delta); }
}

void*  InitEmptyList(long Limit,long Delta){
	if ((hDLL_PRIME32 == NULL)||(!Dll_InitEmptyList)) { return NULL; }
	else { return Dll_InitEmptyList(Limit,Delta); }
}

void*  InitUnsortList(long Limit,long Delta){
	if ((hDLL_PRIME32 == NULL)||(!Dll_InitUnsortList)) { return NULL; }
	else { return Dll_InitUnsortList(Limit,Delta); }
}

long  ListCount(void *List){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListCount)) { return -1; }
	else { return Dll_ListCount(List); }
}

void* ListAt(void *List,long Index){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListAt)) { return NULL; }
	else { return Dll_ListAt(List,Index); }
}

void ListAtDelete(void *List,long Index){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListAtDelete)) {  }
	else { Dll_ListAtDelete(List,Index); }
}

void ListAtFree(void *List,long Index){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListAtFree)) {  }
	else { Dll_ListAtFree(List,Index); }
}

void ListAtInsert(void *List,long Index,void* Item){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListAtInsert)) {  }
	else { Dll_ListAtInsert(List,Index,Item); }
}

void ListAtPut(void *List,long Index,void *Item){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListAtPut)) {  }
	else { Dll_ListAtPut(List,Index,Item); }
}

void ListDelete(void *List,void *Item){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListDelete)) {  }
	else { Dll_ListDelete(List,Item); }
}

void ListDeleteAll(void *List){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListDeleteAll)) {  }
	else { Dll_ListDeleteAll(List); }
}

void ListFree(void *List,void *Item){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListFree)) {  }
	else { Dll_ListFree(List,Item); }
}

void ListFreeAll(void *List){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListFreeAll)) {  }
	else { Dll_ListFreeAll(List); }
}

long ListIndexOf(void *List,void *Item){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListIndexOf)) { return -1; }
	else { return Dll_ListIndexOf(List,Item); }
}

void ListInsert(void *List,void *Item){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListInsert)) {  }
	else { Dll_ListInsert(List,Item); }
}

void ListPack(void *List){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListPack)) {  }
	else { Dll_ListPack(List); }
}

long ListSearch(void *List,const char *Key){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ListSearch)) { return -1; }
	else { return Dll_ListSearch(List,Key); }
}

void* CreateWSCurve(OType DataHandle,long RowNumber,OType ArrayHandle,unsigned char ColNumber){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSCurve)) { return NULL; }
	else { return Dll_CreateWSCurve(DataHandle,RowNumber,ArrayHandle,ColNumber); }
}

void* CreateWSRotCurve(OType DataHandle,long RowNumber,OType ArrayHandle,unsigned char ColNumber,unsigned char RotColNumber){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSRotCurve)) { return NULL; }
	else { return Dll_CreateWSRotCurve(DataHandle,RowNumber,ArrayHandle,ColNumber,RotColNumber); }
}

void* CreateWSPoint(OType ArrayHandle,long ArrayRow){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSPoint)) { return NULL; }
	else { return Dll_CreateWSPoint( ArrayHandle,ArrayRow); }
}

void* CreateWSInter(OType ArrayHandle,long ArrayRow){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSInter)) { return NULL; }
	else { return Dll_CreateWSInter( ArrayHandle,ArrayRow); }
}

void* CreateWSTower(long Color,long Start,long Width,const char *Name){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSTower)) { return NULL; }
	else { return Dll_CreateWSTower( Color,Start,Width,Name); }
}

void* CreateWSDepth(long Color,long Start,long Width,const char *Name){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSDepth)) { return NULL; }
	else { return Dll_CreateWSDepth( Color,Start,Width,Name); }
}

void* CreateWSLnGrid(long Color,long Start,long Width,const char *Name){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSLnGrid)) { return NULL; }
	else { return Dll_CreateWSLnGrid( Color,Start,Width,Name); }
}

void* CreateWSLgGrid(long Color,long Start,long Width,const char *Name){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSLgGrid)) { return NULL; }
	else { return Dll_CreateWSLgGrid( Color,Start,Width,Name); }
}

void* CreateWSPlast(long Color,long Start,long Width,const char *Name,OType DataHandle,OType ArrayHandle,long RowNumber,unsigned char ColNumber,OType DataInter,OType ArrayInter,long RowInter){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSPlast)) { return NULL; }
	else { return Dll_CreateWSPlast( Color,Start,Width,Name,DataHandle,ArrayHandle,RowNumber,ColNumber,DataInter,ArrayInter,RowInter); }
}

void* CreateWSNotes(long ADepth,const char *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSNotes)) { return NULL; }
	else { return Dll_CreateWSNotes( ADepth,P); }
}

void* CreateWSFills(long AStart,long AWidth,long AFlags,long ARoof,long ASole,long Filler,long RevFill,long LeftFill,long RightFill,void *ALeftCurve,void *ARightCurve,float AConst){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSFills)) { return NULL; }
	else { return Dll_CreateWSFills( AStart,AWidth,AFlags,ARoof,ASole,Filler,RevFill,LeftFill,RightFill,ALeftCurve,ARightCurve,AConst); }
}

void* CreateWSPicture(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSPicture)) { return NULL; }
	else { return Dll_CreateWSPicture(); }
}

void* CreateWSTwoDCurve(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSTwoDCurve)) { return NULL; }
	else { return Dll_CreateWSTwoDCurve(); }
}

void* CreateWSFrame(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSFrame)) { return NULL; }
	else { return Dll_CreateWSFrame(); }
}

void* CreateWSText(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSText)) { return NULL; }
	else { return Dll_CreateWSText(); }
}

void* CreateWSTable(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSTable)) { return NULL; }
	else { return Dll_CreateWSTable(); }
}

void* CreateWSBitmap(){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSBitmap)) { return NULL; }
	else { return Dll_CreateWSBitmap(); }
}

void* CreateWSChord(long Start,long Width,long Color,long Flags,void *LeftCurve,void *RightCurve,long LeftDepth,long RightDepth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSChord)) { return NULL; }
	else { return Dll_CreateWSChord( Start,Width,Color,Flags,LeftCurve,RightCurve,LeftDepth,RightDepth); }
}

void* CreateWSScale(long Start, long Width, long Color, long Flags,
                    float AMinim, float AScale, void *Curve, long Depth,
                    const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateWSScale)) { return NULL; }
	else { return Dll_CreateWSScale(Start,Width,Color,Flags,AMinim,AScale,Curve,Depth,Title); }
}

void *GetHandleInter(void *lpPlansheet, long dwReserved, long *dwRoof, long *dwSole){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetHandleInter)) { return NULL; }
	else { return Dll_GetHandleInter(lpPlansheet, dwReserved, dwRoof, dwSole); }
}

void *CreateHandleInter(long dwReserved, long dwColor, long dwFlags, long dwRoof, long dwSole){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateHandleInter)) { return NULL; }
	else { return Dll_CreateHandleInter(dwReserved, dwColor, dwFlags, dwRoof, dwSole); }
}

void StartProcess(const char *S){
	if ((hDLL_PRIME32 == NULL)||(!Dll_StartProcess)) {  }
	else { Dll_StartProcess(S); }
}

void StepProcess(long Min,long Val,long Max){
	if ((hDLL_PRIME32 == NULL)||(!Dll_StepProcess)) {  }
	else { Dll_StepProcess( Min,Val,Max); }
}

void StopProcess(){
	if ((hDLL_PRIME32 == NULL)||(!Dll_StopProcess)) {  }
	else { Dll_StopProcess(); }
}

long WSStart(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSStart)) { return -1; }
	else { return Dll_WSStart(P); }
}

long WSWidth(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSWidth)) { return -1; }
	else { return Dll_WSWidth(P); }
}

long WSState(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSState)) { return -1; }
	else { return Dll_WSState(P); }
}

long WSType(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSType)) { return -1; }
	else { return Dll_WSType(P); }
}

LongBoolean WSMake(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSMake)) { return false; }
	else { return Dll_WSMake(P); }
}

LongBoolean WSActual(void *P,unsigned short Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSActual)) { return false; }
	else { return Dll_WSActual(P,Mode); }
}

void WSGetData(void *P, void *Rec){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSGetData)) { }
	else { Dll_WSGetData(P,Rec); }
}

void WSSetData(void *P, void *Rec){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSetData)) { }
	else { Dll_WSSetData(P,Rec); }
}

unsigned short WSDataSize(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSDataSize)) { return -1; }
	else { return Dll_WSDataSize(P); }
}

void WSReset(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSReset)) {  }
	else { Dll_WSReset(P); }
}

void WSSetState(void *P,unsigned short Mask,LongBoolean Enable){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSetState)) {  }
	else { Dll_WSSetState(P,Mask,Enable); }
}

LongBoolean WSGetState(void *P,unsigned short Mask){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSGetState)) { return false; }
	else { return Dll_WSGetState(P,Mask); }
}

long WSRoof(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSRoof)) { return -1; }
	else { return Dll_WSRoof(P); }
}

long WSSole(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSole)) { return -1; }
	else { return Dll_WSSole(P); }
}

long WSNBRoof(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSNBRoof)) { return -1; }
	else { return Dll_WSNBRoof(P); }
}

long WSNBSole(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSNBSole)) { return -1; }
	else { return Dll_WSNBSole(P); }
}

void WSName(void *P,char *Name){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSName)) {  }
	else { Dll_WSName(P,Name); }
}

LongBoolean WSSetDialog(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSetDialog)) { return false; }
	else { return Dll_WSSetDialog(P); }
}

LongBoolean WSGetDialog(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSGetDialog)) { return false; }
	else { return Dll_WSGetDialog(P); }
}

void WSSetStart(void *P,long Start){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSetStart)) {  }
	else { Dll_WSSetStart(P,Start); }
}

void WSSetWidth(void *P,long Width){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSetWidth)) {  }
	else { Dll_WSSetWidth(P,Width); }
}

void FrameGetData(void *Frame, void *Rec){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSetWidth)) {  }
	else { Dll_FrameGetData(Frame,Rec); }
}

void FrameSetData(void *Frame, void *Rec){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSSetWidth)) {  }
	else { Dll_FrameSetData(Frame,Rec); }
}

unsigned short FrameDataSize(void *Frame){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameDataSize)) { return -1; }
	else { return Dll_FrameDataSize(Frame); }
}

long FrameGetStart(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameGetStart)) { return -1; }
	else { return Dll_FrameGetStart(P); }
}

long FrameGetWidth(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameGetWidth)) { return -1; }
	else { return Dll_FrameGetWidth(P); }
}

long FrameGetState(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameGetState)) { return -1; }
	else { return Dll_FrameGetState(P); }
}

void FrameSetStart(void *P,long Value){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameSetStart)) {  }
	else { Dll_FrameSetStart(P,Value); }
}

void FrameSetWidth(void *P,long Value){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameSetWidth)) {  }
	else { Dll_FrameSetWidth(P,Value); }
}

void FrameSetState(void *P,long Value){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameSetState)) {  }
	else { Dll_FrameSetState(P,Value); }
}

long WSCurveActual(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveActual)) { return -1; }
	else { return Dll_WSCurveActual(P); }
}

long WSCurveCount(void *P){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveCount)) { return -1; }
	else { return Dll_WSCurveCount(P); }
}

long WSCurveDepth(void *P,long Index){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveDepth)) { return -1; }
	else { return Dll_WSCurveDepth(P,Index); }
}

long WSCurveIndex(void *P,long Depth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveIndex)) { return -1; }
	else { return Dll_WSCurveIndex(P,Depth); }
}

float WSCurveValue(void *P,long Depth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveValue)) { return BlankSingle; }
	else { return Dll_WSCurveValue(P,Depth); }
}

long WSCurveValueStr(void *P,long Depth,char *Value,long ValueSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveValueStr)) { return -1; }
	else { return Dll_WSCurveValueStr(P,Depth,Value,ValueSize); }
}

long GetLitholByDepth(void *P, long Depth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetLitholByDepth)) { return BlankLongInt; }
	else { return Dll_GetLitholByDepth(P,Depth); }
}

long GetStratByDepth(void *P, long Depth, char *Strat, long StratSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetStratByDepth)) { return -1; }
	else { return Dll_GetStratByDepth(P,Depth,Strat,StratSize); }
}

long GetLegendByDepth(void *P, long Depth, char *Legend, long LegendSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetLegendByDepth)) { return -1; }
	else { return Dll_GetLegendByDepth(P,Depth,Legend,LegendSize); }
}

OType GetTowerPlastArray(void *Tower){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTowerPlastArray)) { return hNil; }
	else { return Dll_GetTowerPlastArray(Tower); }
}

long WSCurveMinMidMax(void *P,long Roof,long Sole,float *Min,float *Mid,float *Max){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveMinMidMax)) { return -1; }
	else { return Dll_WSCurveMinMidMax(P,Roof,Sole,Min,Mid,Max); }
}

long WSCurveMinMidMaxH(void *P,long Roof,long Sole,float *Min,float *Mid,float *Max,float *MinH,float *MaxH){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveMinMidMaxH)) { return -1; }
	else { return Dll_WSCurveMinMidMaxH(P,Roof,Sole,Min,Mid,Max,MinH,MaxH); }
}

long WSCurveLinear(void *P,long Roof,long Sole,float *A,float *B){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveLinear)) { return -1; }
	else { return Dll_WSCurveLinear(P,Roof,Sole,A,B); }
}

long WSCurveSetTemplate(void *P,const char *ATemplateName,char *Res){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WSCurveSetTemplate)) { return -1; }
	else { return Dll_WSCurveSetTemplate(P,ATemplateName,Res); }
}

LongBoolean SetTemplateObject(void *Obj, void *TemplateObj, long dwFlags, void *lpReserved)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTemplateObject)) { return false; }
	else { return Dll_SetTemplateObject(Obj, TemplateObj, dwFlags, lpReserved); }
}

void *GetTemplateObject(void *Obj, void *Plansheet)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTemplateObject)) { return NULL; }
	else { return Dll_GetTemplateObject(Obj, Plansheet); }
}

OType CreateTemplateDataObject(void *Obj, void *Plansheet, const char *ID, void *Reserved)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateTemplateDataObject)) { return hNil; }
	else { return Dll_CreateTemplateDataObject(Obj, Plansheet, ID, Reserved); }
}

long GetViewID(void *View)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetViewID)) { return -1; }
	else { return Dll_GetViewID(View); }
}

void *FindViewByID(void *Plansheet, long ID)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_FindViewByID)) { return NULL; }
	else { return Dll_FindViewByID(Plansheet, ID); }
}

long CurveGetLoadCondition(void *Curve, char *lpCondition, long nConditionSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CurveGetLoadCondition)) { return -1; }
	else { return Dll_CurveGetLoadCondition(Curve,lpCondition,nConditionSize); }
}

LongBoolean CurveSetLoadCondition(void *Curve, const char *lpCondition){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CurveSetLoadCondition)) { return false; }
	else { return Dll_CurveSetLoadCondition(Curve,lpCondition); }
}

void PutMessage(const char *S){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PutMessage)) {  }
	else { Dll_PutMessage(S); }
}

void WaitMessage(const char *S){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WaitMessage)) {  }
	else { Dll_WaitMessage(S); }
}

void ClrMessage(){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ClrMessage)) {  }
	else { Dll_ClrMessage(); }
}

void* CurrentWindow(){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CurrentWindow)) { return NULL; }
	else { return Dll_CurrentWindow(); }
}

void WindowFileName(char *FileName){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WindowFileName)) {  }
	else { Dll_WindowFileName(FileName); }
}

void WindowTypeName(char *TypeName){
	if ((hDLL_PRIME32 == NULL)||(!Dll_WindowTypeName)) {  }
	else { Dll_WindowTypeName(TypeName); }
}
                    
void* CurrentPlansheet(){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CurrentPlansheet)) { return NULL; }
	else { return Dll_CurrentPlansheet(); }
}

long GetPlanTemplate(void *Plansheet,char *PlanTemplate){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanTemplate)) { return -1; }
	else { return Dll_GetPlanTemplate(Plansheet,PlanTemplate); }
}

long GetPlanTitle(void *Plansheet,char *PlanTitle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanTitle)) { return -1; }
	else { return Dll_GetPlanTitle(Plansheet,PlanTitle); }
}

long GetPlanRoof(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanRoof)) { return -1; }
	else { return Dll_GetPlanRoof(Plansheet); }
}

long GetPlanSole(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanSole)) { return -1; }
	else { return Dll_GetPlanSole(Plansheet); }
}

void SetPlanRoof(void *Plansheet,long Roof){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPlanRoof)) {  }
	else { Dll_SetPlanRoof(Plansheet,Roof); }
}

void SetPlanSole(void *Plansheet,long Sole){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPlanSole)) {  }
	else { Dll_SetPlanSole(Plansheet,Sole); }
}

long GetPlanHandle(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanHandle)) { return -1; }
	else { return Dll_GetPlanHandle(Plansheet); }
}

void SetPlanHandle(void *Plansheet,long Handle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPlanHandle)) {  }
	else { Dll_SetPlanHandle(Plansheet,Handle); }
}

long GetPlanCount(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanCount)) { return -1; }
	else { return Dll_GetPlanCount(Plansheet); }
}

void* GetPlanList(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanList)) { return NULL; }
	else { return Dll_GetPlanList(Plansheet); }
}

void* GetPlanListX(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanListX)) { return NULL; }
	else { return Dll_GetPlanListX(Plansheet); }
}

long GetPlanActiveCount(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanActiveCount)) { return -1; }
	else { return Dll_GetPlanActiveCount(Plansheet); }
}

void* GetPlanActiveList(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanActiveList)) { return NULL; }
	else { return Dll_GetPlanActiveList(Plansheet); }
}

long GetPlanDepth(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanDepth)) { return -1; }
	else { return Dll_GetPlanDepth(Plansheet); }
}

void SetPlanDepth(void *Plansheet, long Depth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPlanDepth)) {  }
	else { Dll_SetPlanDepth(Plansheet,Depth); }
}

long GetPlanScale(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanScale)) { return -1; }
	else { return Dll_GetPlanScale(Plansheet); }
}

void SetPlanScale(void *Plansheet,long Scale){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPlanScale)) {  }
	else { Dll_SetPlanScale(Plansheet,Scale); }
}

long GetPlanWidth(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanWidth)) { return -1; }
	else { return Dll_GetPlanWidth(Plansheet); }
}

void SetPlanWidth(void *Plansheet,long Width){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPlanWidth)) {  }
	else { Dll_SetPlanWidth(Plansheet,Width); }
}

unsigned char GetPlanColor(long Index){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanColor)) { return 0; }
	else { return Dll_GetPlanColor(Index); }
}

void SetPlanColor(long Index,unsigned char Color){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPlanColor)) {  }
	else { Dll_SetPlanColor(Index,Color); }
}

void GetWorkSpace(void *Plansheet,char *WorkSpace){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetWorkSpace)) {  }
	else { Dll_GetWorkSpace(Plansheet,WorkSpace); }
}

LongBoolean HeaderState(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_HeaderState)) { return false; }
	else { return Dll_HeaderState(Plansheet); }
}

void ShowHeader(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ShowHeader)) {  }
	else { Dll_ShowHeader(Plansheet); }
}

void HideHeader(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_HideHeader)) {  }
	else { Dll_HideHeader(Plansheet); }
}

void DrawPlansheet(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DrawPlansheet)) {  }
	else { Dll_DrawPlansheet(Plansheet); }
}

long ObjectCount(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ObjectCount)) { return -1; }
	else { return Dll_ObjectCount(Plansheet,Mode); }
}

void* ObjectList(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ObjectList)) { return NULL; }
	else { return Dll_ObjectList(Plansheet,Mode); }
}

long ActiveCount(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveCount)) { return -1; }
	else { return Dll_ActiveCount(Plansheet,Mode); }
}

void* ActiveList(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveList)) { return NULL; }
	else { return Dll_ActiveList(Plansheet,Mode); }
}

long StrictObjectCount(void *Plansheet, long AWSType){
	if ((hDLL_PRIME32 == NULL)||(!Dll_StrictObjectCount)) { return -1; }
	else { return Dll_StrictObjectCount(Plansheet,AWSType); }
}

void* StrictObjectList(void *Plansheet, long AWSType){
	if ((hDLL_PRIME32 == NULL)||(!Dll_StrictObjectList)) { return NULL; }
	else { return Dll_StrictObjectList(Plansheet,AWSType); }
}

long StrictActiveCount(void *Plansheet, long AWSType){
	if ((hDLL_PRIME32 == NULL)||(!Dll_StrictActiveCount)) { return -1; }
	else { return Dll_StrictActiveCount(Plansheet,AWSType); }
}

void* StrictActiveList(void *Plansheet, long AWSType){
	if ((hDLL_PRIME32 == NULL)||(!Dll_StrictActiveList)) { return NULL; }
	else { return Dll_StrictActiveList(Plansheet,AWSType); }
}

void InsertObject(void *Plansheet,void *View){
	if ((hDLL_PRIME32 == NULL)||(!Dll_InsertObject)) {  }
	else { Dll_InsertObject(Plansheet,View); }
}

void RedrawObject(void *Plansheet,void *View){
	if ((hDLL_PRIME32 == NULL)||(!Dll_RedrawObject)) {  }
	else { Dll_RedrawObject(Plansheet,View); }
}

void RedrawObjectXor(void *Plansheet,void *View){
	if ((hDLL_PRIME32 == NULL)||(!Dll_RedrawObjectXor)) {  }
	else { Dll_RedrawObjectXor(Plansheet,View);}
}

void DeleteObject(void *Plansheet,void *View){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DeleteObject)) {  }
	else { Dll_DeleteObject(Plansheet,View); }
}

void SaveState(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SaveState)) {  }
	else { Dll_SaveState(Plansheet); }
}

void RestoreState(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_RestoreState)) {  }
	else { Dll_RestoreState(Plansheet); }
}

void ClearState(void *Plansheet,long Mask){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ClearState)) {  }
	else { Dll_ClearState(Plansheet,Mask); }
}

void SetupState(void *Plansheet,long Mask){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetupState)) {  }
	else { Dll_SetupState(Plansheet,Mask); }
}

LongBoolean ExecuteWindow(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ExecuteWindow)) { return false; }
	else { return Dll_ExecuteWindow(Plansheet); }
}

void PointTable(void *Plansheet,OType *Handle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_PointTable)) {  }
	else { Dll_PointTable(Plansheet,Handle); }
}

void InterTable(void *Plansheet,OType *Handle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_InterTable)) {  }
	else { Dll_InterTable(Plansheet,Handle); }
}

void RedrawObjects(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_RedrawObjects)) {  }
	else { Dll_RedrawObjects(Plansheet); }
}

void DisableHeaderRedraw(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DisableHeaderRedraw)) {  }
	else { Dll_DisableHeaderRedraw(); }
}

void EnableHeaderRedraw(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_EnableHeaderRedraw)) {  }
	else { Dll_EnableHeaderRedraw(); }
}

long RegisterPrimeWindow(HWND H, const char* PrimeName){
	if ((hDLL_PRIME32 == NULL)||(!Dll_RegisterPrimeWindow)) { return -1; }
	else { return Dll_RegisterPrimeWindow(H,PrimeName); }
}

long RegisterPrimeWindowAt(HWND H, const char* PrimeName, long Number){
	if ((hDLL_PRIME32 == NULL)||(!Dll_RegisterPrimeWindowAt)) { return -1; }
	else { return Dll_RegisterPrimeWindowAt(H,PrimeName,Number); }
}

long UnregisterPrimeWindow(HWND H){
	if ((hDLL_PRIME32 == NULL)||(!Dll_UnregisterPrimeWindow)) { return -1; }
	else { return Dll_UnregisterPrimeWindow(H); }
}

void* CurrentTower(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CurrentTower)) { return NULL; }
	else { return Dll_CurrentTower(Plansheet); }
}

void* CurrentCurve(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CurrentCurve)) { return NULL; }
	else { return Dll_CurrentCurve(Plansheet); }
}

long CurveMode(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CurveMode)) { return -1; }
	else { return Dll_CurveMode(Plansheet); }
}


float AbsDepthValue(void* Tower, long Depth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_AbsDepthValue)) { return BlankSingle; }
	else { return Dll_AbsDepthValue(Tower,Depth); }
}

long GetDepthByAbsDepth(void *Tower, float AbsDepth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetDepthByAbsDepth)) { return BlankLongInt; }
	else { return Dll_GetDepthByAbsDepth(Tower,AbsDepth); }
}

long GetPrintIntervalsCount(void* Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPrintIntervalsCount)) { return 0; }
	else { return Dll_GetPrintIntervalsCount(Plansheet); }
}

LongBoolean GetPrintInterval(void* Plansheet, long Index, TPrintInterval* Interval){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPrintInterval)) { return false; }
	else { return Dll_GetPrintInterval(Plansheet,Index,Interval); }
}

LongBoolean SetPrintInterval(void* Plansheet, long Index, TPrintInterval* Interval){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPrintInterval)) { return false; }
	else { return Dll_SetPrintInterval(Plansheet,Index,Interval); }
}

LongBoolean AddPrintInterval(void* Plansheet, TPrintInterval* Interval){
	if ((hDLL_PRIME32 == NULL)||(!Dll_AddPrintInterval)) { return false; }
	else { return Dll_AddPrintInterval(Plansheet,Interval); }
}

LongBoolean AddPrintIntervalAt(void* Plansheet, long Index, TPrintInterval* Interval){
	if ((hDLL_PRIME32 == NULL)||(!Dll_AddPrintIntervalAt)) { return false; }
	else { return Dll_AddPrintIntervalAt(Plansheet,Index,Interval); }
}

LongBoolean DeletePrintInterval(void* Plansheet, long Index){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DeletePrintInterval)) { return false; }
	else { return Dll_DeletePrintInterval(Plansheet,Index); }
}

LongBoolean DeleteAllPrintIntervals(void* Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DeleteAllPrintIntervals)) { return false; }
	else { return Dll_DeleteAllPrintIntervals(Plansheet); }
}

long GetReportHandle(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetReportHandle)) { return -1; }
	else { return Dll_GetReportHandle(Plansheet); }
}

void SetReportHandle(void *Plansheet,long Handle){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetReportHandle)) {  }
	else { Dll_SetReportHandle(Plansheet,Handle); }
}

long GetReportCount(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetReportCount)) { return -1; }
	else { return Dll_GetReportCount(Plansheet); }
}

long FrameCount(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameCount)) { return -1; }
	else { return Dll_FrameCount(Plansheet,Mode); }
}

void* FrameList(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FrameList)) { return NULL; }
	else { return Dll_FrameList(Plansheet,Mode); }
}

long ActiveFramesCount(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveFramesCount)) { return -1; }
	else { return Dll_ActiveFramesCount(Plansheet,Mode); }
}

void* ActiveFramesList(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveFramesList)) { return NULL; }
	else { return Dll_ActiveFramesList(Plansheet,Mode); }
}

long FooterFrameCount(void *Plansheet, long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FooterFrameCount)) { return -1; }
	else { return Dll_FooterFrameCount(Plansheet,Mode); }
}

void* FooterFrameList(void *Plansheet, long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FooterFrameList)) { return NULL; }
	else { return Dll_FooterFrameList(Plansheet,Mode); }
}

long ActiveFooterFramesCount(void *Plansheet, long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveFooterFramesCount)) { return -1; }
	else { return Dll_ActiveFooterFramesCount(Plansheet,Mode); }
}

void* ActiveFooterFramesList(void *Plansheet, long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveFooterFramesList)) { return NULL; }
	else { return Dll_ActiveFooterFramesList(Plansheet,Mode); }
}

void InsertFrames(void *Plansheet,void *Frame){
	if ((hDLL_PRIME32 == NULL)||(!Dll_InsertFrames)) {  }
	else { Dll_InsertFrames(Plansheet,Frame); }
}

void DeleteFrames(void *Plansheet,void *Frame){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DeleteFrames)) {  }
	else { Dll_DeleteFrames(Plansheet,Frame); }
}

void SetLeftCurve(void *Plansheet,void *Curve){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetLeftCurve)) {  }
	else { Dll_SetLeftCurve(Plansheet,Curve); }
}

void SetRightCurve(void *Plansheet,void *Curve){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetRightCurve)) {  }
	else { Dll_SetRightCurve(Plansheet,Curve); }
}

LongBoolean TrackData(void *Plansheet,long Mode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_TrackData)) { return false; }
	else { return Dll_TrackData(Plansheet,Mode); }
}

void SetTrackFormat(void *Plansheet,const char *S){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackFormat)) {  }
	else { Dll_SetTrackFormat(Plansheet,S); }
}

void SetTrackRoof(void *Plansheet,long Roof){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackRoof)) {  }
	else { Dll_SetTrackRoof(Plansheet,Roof); }
}

void SetTrackSole(void *Plansheet,long Sole){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackSole)) {  }
	else { Dll_SetTrackSole(Plansheet,Sole); }
}

void SetTrackDepth(void *Plansheet,long Depth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackDepth)) {  }
	else { Dll_SetTrackDepth(Plansheet,Depth); }
}

void SetTrackStart(void *Plansheet,long Start){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackStart)) {  }
	else { Dll_SetTrackStart(Plansheet,Start); }
}

void SetTrackShift(void *Plansheet,long Shift){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackShift)) {  }
	else { Dll_SetTrackShift(Plansheet,Shift); }
}

void SetTrackMinim(void *Plansheet,float Minim){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackMinim)) {  }
	else { Dll_SetTrackMinim(Plansheet,Minim); }
}

void SetTrackScale(void *Plansheet,float Scale){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackScale)) {  }
	else { Dll_SetTrackScale(Plansheet,Scale); }
}

void SetTrackValue(void *Plansheet,float Value){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackValue)) {  }
	else { Dll_SetTrackValue(Plansheet,Value); }
}

void SetTrackCurve(void *Plansheet,void *Curve){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackCurve)) {  }
	else { Dll_SetTrackCurve(Plansheet,Curve); }
}

long SetTrackUserValueCallback(void *lpPlansheet, long dwIndex,
  TTrackUserValueFunc lpfnTrackUserValueCallback, void *dwCookie){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackUserValueCallback)) { return -1; }
	else { return Dll_SetTrackUserValueCallback(lpPlansheet,dwIndex,lpfnTrackUserValueCallback,dwCookie); }
}

long SetTrackUserStrCallback(void *lpPlansheet, long dwIndex,
  TTrackUserStringFunc lpfnTrackUserStrCallback, void *dwCookie){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTrackUserStrCallback)) { return -1; }
	else { return Dll_SetTrackUserStrCallback(lpPlansheet,dwIndex,lpfnTrackUserStrCallback,dwCookie); }
}

long GetTrackDepth(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTrackDepth)) { return -1; }
	else { return Dll_GetTrackDepth(Plansheet); }
}

long GetTrackStart(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTrackStart)) { return -1; }
	else { return Dll_GetTrackStart(Plansheet); }
}

float GetTrackValue(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTrackValue)) { return BlankSingle; }
	else { return Dll_GetTrackValue(Plansheet); }
}

double GetTrackUserValue(void *lpPlansheet, long dwIndex){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTrackUserValue)) { return BlankDouble; }
	else { return Dll_GetTrackUserValue(lpPlansheet,dwIndex); }
}

long GetTrackUserString(void *lpPlansheet, long dwIndex,
  void *lpBuffer, long dwBufferSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTrackUserString)) { return -1; }
	else { return Dll_GetTrackUserString(lpPlansheet,dwIndex,lpBuffer,dwBufferSize); }
}

void* ActiveCurves(long Min,long Max,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveCurves)) { return NULL; }
	else { return Dll_ActiveCurves(Min,Max,Title); }
}

void* ActiveDViews(long Min,long Max,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveDViews)) { return NULL; }
	else { return Dll_ActiveDViews(Min,Max,Title); }
}

void* ActivePlastTowers(long Min,long Max,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActivePlastTowers)) { return NULL; }
	else { return Dll_ActivePlastTowers(Min,Max,Title); }
}

void* ActiveTowers(long Min,long Max,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveTowers)) { return NULL; }
	else { return Dll_ActiveTowers(Min,Max,Title); }
}

void* ActiveText(long Min,long Max,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActiveText)) { return NULL; }
	else { return Dll_ActiveText(Min,Max,Title); }
}

void* GetOneCurve(const char *Name,const char *Value){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetOneCurve)) { return NULL; }
	else { return Dll_GetOneCurve(Name,Value); }
}

void* GetOneCurveByName(const char *Value){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetOneCurveByName)) { return NULL; }
	else { return Dll_GetOneCurveByName(Value); }
}

void* GetPlastTower(const char *Name){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlastTower)) { return NULL; }
	else { return Dll_GetPlastTower(Name); }
}

long FindPlanObject(void *lpPlansheet, const char *lpszConditions,
  void *lpTestObject, long dwFindFlags, long dwObjMask, void **lplpFound,
  void *lpFoundObjs, void *lpReserved){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FindPlanObject)) { return NULL; }
	else { return Dll_FindPlanObject(lpPlansheet, lpszConditions,
                 lpTestObject, dwFindFlags, dwObjMask, lplpFound, lpFoundObjs,
                 lpReserved); }
}

/* Ïîèñê óñëîâèé çàãðóçêè êðèâîé ïî çàäàííîìó ìåòîäó â çàäàííîì ôàéëå øàáëîíà */
long FindCurveLoadCondition(const char *lpSheetTemplateFileName,
  const char *lpCurveMethodName, long FindFlags,
  char *lpLoadCondition, long dwLoadConditionSize,
  void *lpReserved)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_FindCurveLoadCondition)) { return -1; }
	else { return Dll_FindCurveLoadCondition(lpSheetTemplateFileName,
                    lpCurveMethodName,FindFlags,lpLoadCondition,
					dwLoadConditionSize,lpReserved); }
}

LongBoolean InsertOrReplaceObject(void *Plansheet, void **lplpObj,
  long Flags, long *lpErrCode, void *Reserved)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_InsertOrReplaceObject)) { return false; }
	else { return Dll_InsertOrReplaceObject(Plansheet,lplpObj,Flags,lpErrCode,Reserved); }
}

void* SelectCurve(const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectCurve)) { return NULL; }
	else { return Dll_SelectCurve(Title); }
}

void* SelectDView(const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectDView)) { return NULL; }
	else { return Dll_SelectDView(Title); }
}

void* SelectPlastTower(const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectPlastTower)) { return NULL; }
	else { return Dll_SelectPlastTower(Title); }
}

void* SelectTower(const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectTower)) { return NULL; }
	else { return Dll_SelectTower(Title); }
}

void* SelectText(const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectText)) { return NULL; }
	else { return Dll_SelectText(Title); }
}

void* SelectTwoDCurve(const char *Prompt){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectTwoDCurve)) { return NULL; }
	else { return Dll_SelectTwoDCurve(Prompt); }
}

long GetCurveH(void *P,OType *ObjHandle,OType *ArrHandle,unsigned short *Column){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetCurveH)) { return -1; }
	else { return Dll_GetCurveH(P,ObjHandle,ArrHandle,Column); }
}

void GetCurveName(void *Curve, char *CurveName){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetCurveName)) { return; }
	else { Dll_GetCurveName(Curve,CurveName); }
}

void* SelectOneCurve(const char *Prompt){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectOneCurve)) { return NULL; }
	else { return Dll_SelectOneCurve(Prompt); }
}

void* SelectObject(const char *Prompt){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectObject)) { return NULL; }
	else { return Dll_SelectObject(Prompt); }
}

void* SelectObjectByType(const char *Prompt, long AWSType){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectObjectByType)) { return NULL; }
	else { return Dll_SelectObjectByType(Prompt,AWSType); }
}


LongBoolean CheckCurves(){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CheckCurves)) { return false; }
	else { return Dll_CheckCurves(); }
}

LongBoolean SelectDepth(long *Depth,const char *Title, void *Curve){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectDepth)) { return false; }
	else { return Dll_SelectDepth(Depth,Title,Curve); }
}

LongBoolean SelectInter(long *Roof,long *Sole,const char *Title,void *Curve){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectInter)) { return false; }
	else { return Dll_SelectInter(Roof,Sole,Title,Curve); }
}

LongBoolean SelectShift(long *Delta,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectShift)) { return false; }
	else { return Dll_SelectShift(Delta,Title); }
}

LongBoolean SelectValue(long Start,float Minimum,float Scale,float *Value,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectValue)) { return false; }
	else { return Dll_SelectValue(Start,Minimum,Scale,Value,Title); }
}

LongBoolean SelectStart(long *Start,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectStart)) { return false; }
	else { return Dll_SelectStart(Start,Title); }
}

LongBoolean SelectStartWidth(long *Start,long *Width,const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectStartWidth)) { return false; }
	else { return Dll_SelectStartWidth(Start,Width,Title); }
}

void MinInter(void *List,long *Roof,long *Sole){
	if ((hDLL_PRIME32 == NULL)||(!Dll_MinInter)) {  }
	else { Dll_MinInter(List,Roof,Sole); }
}

void MaxInter(void *List,long *Roof,long *Sole){
	if ((hDLL_PRIME32 == NULL)||(!Dll_MaxInter)) {  }
	else { Dll_MaxInter(List,Roof,Sole); }
}

float GetMainVal(void *Curve,long Roof,long Sole,long Num,long HC,long DH,long Option){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetMainVal)) { return BlankSingle; }
	else { return Dll_GetMainVal(Curve,Roof,Sole,Num,HC,DH,Option); }
}

void* DuplicateCurve(void *View,long Roof,long Sole){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DuplicateCurve)) { return NULL; }
	else { return Dll_DuplicateCurve(View,Roof,Sole); }
}

void *DuplicateCurveEx(void *View, long Roof, long Sole, const char *MethodName, const char *UnitName){
	if ((hDLL_PRIME32 == NULL)||(!Dll_DuplicateCurveEx)) { return NULL; }
	else { return Dll_DuplicateCurveEx(View,Roof,Sole,MethodName,UnitName); }
}

void* GetWSGroup(void *Curve){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetWSGroup)) { return NULL; }
	else { return Dll_GetWSGroup(Curve); }
}

void* GetPlanGroup(void *Curve){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPlanGroup)) { return NULL; }
	else { return Dll_GetPlanGroup(Curve); }
}

long CrvTransform(OType DataHandle,OType ArrHandle,unsigned char Column,void *List, TStartTransform StartP,TCrvTransform DoP,TGetTransform GetP,PProcess Ind){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CrvTransform)) { return -1; }
	else { return Dll_CrvTransform(DataHandle,ArrHandle,Column,List,StartP,DoP,GetP,Ind); }
}

LongBoolean GetDefaultTemplate(TViewCurveRec *Rec){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetDefaultTemplate)) { return false; }
	else { return Dll_GetDefaultTemplate(Rec); }
}

long SelectFilName(const char *lpTitle, const char *lpPrompt, const char *lpFilClass, char *lpFilName, long nFilNameSize, long *lpnCode){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectFilName)) { return -1; }
	else { return Dll_SelectFilName(lpTitle,lpPrompt,lpFilClass,lpFilName,nFilNameSize,lpnCode); }
}

long SelectFilClassName(const char *lpTitle, const char *lpPrompt, char *lpClassName, long nClassNameSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectFilClassName)) { return -1; }
	else { return Dll_SelectFilClassName(lpTitle,lpPrompt,lpClassName,nClassNameSize); }
}

long GetFillStyleCount(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetFillStyleCount)) { return -1; }
	else { return Dll_GetFillStyleCount(Plansheet); }
}

LongBoolean GetFillStyleBitmap(void *Plansheet, const char *DeviceName,
  long DeviceDPIX, long DeviceDPIY, long RotateAngle, long DeviceFlags,
  long Number, COLORREF *Color, HBITMAP *Bmp, HPALETTE *Palette){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetFillStyleBitmap)) { return false; }
	else { return Dll_GetFillStyleBitmap(Plansheet, DeviceName,
                 DeviceDPIX, DeviceDPIY, RotateAngle, DeviceFlags,
                 Number, Color, Bmp, Palette); }
}

long GetFillStyleName(void *Plansheet, long Number,
  char *StyleName, long StyleNameLen){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetFillStyleName)) { return -1; }
	else { return Dll_GetFillStyleName(Plansheet, Number, StyleName, StyleNameLen); }
}

long GetFillStyleClass(void *Plansheet, long Number,
  char *StyleClass, long StyleClassLen){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetFillStyleClass)) { return -1; }
	else { return Dll_GetFillStyleClass(Plansheet, Number, StyleClass, StyleClassLen); }
}

LongBoolean FindFillStyle(void *Plansheet, const char *StyleName, const char *StyleClass,
  long *Number){
	if ((hDLL_PRIME32 == NULL)||(!Dll_FindFillStyle)) { return false; }
	else { return Dll_FindFillStyle(Plansheet, StyleName, StyleClass, Number); }
}

void *CreateNewPlansheet(const char *lpTemplateFileName, const char *lpWSFileName){
	if ((hDLL_PRIME32 == NULL)||(!Dll_CreateNewPlansheet)) { return NULL; }
	else { return Dll_CreateNewPlansheet(lpTemplateFileName,lpWSFileName); }
}

long ReloadConfig(long ConfigType, long Flags, const char *lpFileName, OType hData){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ReloadConfig)) { return -1; }
	else { return Dll_ReloadConfig(ConfigType,Flags,lpFileName,hData); }
}

void *GetSheetsList(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetSheetsList)) { return NULL; }
	else { return Dll_GetSheetsList(); }
}

void *GetSheetWindowsList(void){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetSheetWindowsList)) { return NULL; }
	else { return Dll_GetSheetWindowsList(); }
}

void *GetSheetsByWindow(void *Window){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetSheetsByWindow)) { return NULL; }
	else { return Dll_GetSheetsByWindow(Window); }
}

void *GetWindowBySheet(void *Sheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetWindowBySheet)) { return NULL; }
	else { return Dll_GetWindowBySheet(Sheet); }
}

LongBoolean ActivatePlansheet(void *Plansheet){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ActivatePlansheet)) { return false; }
	else { return Dll_ActivatePlansheet(Plansheet); }
}

long GetBuildType(long *lpBuildSubType){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetBuildType)) { return pbtUnknown; }
	else { return Dll_GetBuildType(lpBuildSubType); }
}

LongBoolean GetHASPInfo(THaspInfo *lpInfo){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetHASPInfo)) { return false; }
	else { return Dll_GetHASPInfo(lpInfo); }
}

LongBoolean ApplyConds(char *lpDestCondStr, long nDestCondStrSize,
  const char *lpSrcCondStr, const char *lpCurveName,
  TConflictFieldsAction *lpConflictAction){
	if ((hDLL_PRIME32 == NULL)||(!Dll_ApplyConds)) { return false; }
	else { return Dll_ApplyConds(lpDestCondStr, nDestCondStrSize,
                 lpSrcCondStr, lpCurveName, lpConflictAction); }
}

LongBoolean TestData(OType hObj, const char *lpAValueName, const char *lpAUnitName,
  const char *lpAnArrayName, const char *lpTestConds, const char *lpFilter,
  LongBoolean EmptyValid, OType *lphArr, long *lpColumn){
	if ((hDLL_PRIME32 == NULL)||(!Dll_TestData)) { return false; }
	else { return Dll_TestData(hObj, lpAValueName, lpAUnitName,
                 lpAnArrayName, lpTestConds, lpFilter,
                 EmptyValid, lphArr, lpColumn); }
}

long SelectCurveDataByFilter(void *lpTablesList, const char *lpCurveName,
  const char *lpFilter, char *lpAddFilter, long nAddFilterSize,
  OType *lphObj, OType *lphArr, long *lpColNumber, long *lpRowNumber, long Flags){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectCurveDataByFilter)) { return -1; }
	else { return Dll_SelectCurveDataByFilter(lpTablesList, lpCurveName,
                 lpFilter, lpAddFilter, nAddFilterSize,
                 lphObj, lphArr, lpColNumber, lpRowNumber, Flags); }
}

LongBoolean GetLastTestDataColumns(TColumnsSet *lpColumns){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetLastTestDataColumns)) { return false; }
	else { return Dll_GetLastTestDataColumns(lpColumns); }
}

long GetSheetSelectMode(void *lpPlansheet,
  long *lpdwFlags0, long *lpdwFlags1, long *lpdwFlags2, long *lpdwFlags3,
  long *lpdwFlags4, long *lpdwFlags5, long *lpdwFlags6, long *lpdwFlags7,
  long *lpdwFlags8){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetSheetSelectMode)) { return -1; }
	else { return Dll_GetSheetSelectMode(lpPlansheet,
                 lpdwFlags0, lpdwFlags1, lpdwFlags2, lpdwFlags3,
                 lpdwFlags4, lpdwFlags5, lpdwFlags6, lpdwFlags7, lpdwFlags8); }
}

long SetSheetSelectMode(void *lpPlansheet,
  long dwFlags0, long dwFlags1, long dwFlags2, long dwFlags3,
  long dwFlags4, long dwFlags5, long dwFlags6, long dwFlags7,
  long dwFlags8){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetSheetSelectMode)) { return -1; }
	else { return Dll_SetSheetSelectMode(lpPlansheet,
                 dwFlags0, dwFlags1, dwFlags2, dwFlags3,
                 dwFlags4, dwFlags5, dwFlags6, dwFlags7, dwFlags8); }
}

void SetTopCaption(const char *lpCaption){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTopCaption)) { return; }
	else { Dll_SetTopCaption(lpCaption); }
}

long GetPrimeParam(const char *ParamName, void *lpBuffer, long cbBufSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetPrimeParam)) { return -1; }
	else { return Dll_GetPrimeParam(ParamName, lpBuffer, cbBufSize); }
}

long SetPrimeParam(const char *ParamName, void *lpBuffer, long cbBufSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPrimeParam)) { return -1; }
	else { return Dll_SetPrimeParam(ParamName, lpBuffer, cbBufSize); }
}

long GetTwoDValuesByDepth(void *TwoDCurve, long dwDepth,
  long nChannelIndex, float *lpfBuffer,
  long dwBufLenInFloats, LongBoolean *lplbValidRow){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTwoDValuesByDepth)) { return -1; }
	else { return Dll_GetTwoDValuesByDepth(TwoDCurve, dwDepth,
                 nChannelIndex, lpfBuffer, dwBufLenInFloats, lplbValidRow); }
}

long GetTwoDLastRowHeader(void *TwoDCurve, void *lpBuffer,
  long dwBufSize, long *lpdwBitIndex){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTwoDLastRowHeader)) { return -1; }
	else { return Dll_GetTwoDLastRowHeader(TwoDCurve, lpBuffer,
                 dwBufSize, lpdwBitIndex); }
}

long GetTwoDLastChannelHeader(void *TwoDCurve, void *lpBuffer,
  long dwBufSize, long *lpdwBitIndex){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTwoDLastChannelHeader)) { return -1; }
	else { return Dll_GetTwoDLastChannelHeader(TwoDCurve, lpBuffer,
                 dwBufSize, lpdwBitIndex); }
}

long GetTwoDHeader(void *TwoDCurve, void *lpBuffer, long dwBufSize){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTwoDHeader)) { return -1; }
	else { return Dll_GetTwoDHeader(TwoDCurve, lpBuffer, dwBufSize); }
}

LongBoolean GetTwoDDepthIndex(void *TwoDCrv, TPrimeDepthIndex *Index)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTwoDDepthIndex)) { return false; }
	else { return Dll_GetTwoDDepthIndex(TwoDCrv, Index); }
}

long AddCurveDataToList(void *CurvesList, const PTableCurveDataRec Data){
	if ((hDLL_PRIME32 == NULL)||(!Dll_AddCurveDataToList)) { return -1; }
	else { return Dll_AddCurveDataToList(CurvesList, Data); }
}

LongBoolean GetCurveDataFromList(void *CurvesList, long Index,
  PTableCurveDataRec Data){
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetCurveDataFromList)) { return false; }
	else { return Dll_GetCurveDataFromList(CurvesList, Index, Data); }
}

long SelectCurves_1(OType hWS, const char *TableName, long Flags,
  void *CurvesList){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectCurves_1)) { return -1; }
	else { return Dll_SelectCurves_1(hWS, TableName, Flags, CurvesList); }
}

LongBoolean SelectCurveValue(void *Curve, float *Value, const char *Title){
	if ((hDLL_PRIME32 == NULL)||(!Dll_SelectCurveValue)) { return 0; }
	else { return Dll_SelectCurveValue(Curve, Value, Title); }
}

double __stdcall TrackCurveValueFunc(void *Curve, long AStart, long ADepth){
	if ((hDLL_PRIME32 == NULL)||(!Dll_TrackCurveValueFunc)) { return BlankDouble; }
	else { return Dll_TrackCurveValueFunc(Curve, AStart, ADepth); }
}

long SetPrimeCommonCallback(long dwEventType,
       TPrimeCommonCallbackFunc lpFunc, void *dwCookie, long dwCallbackFlags,
       long dwPriority, void *lpObject, long dwObjectType,
       long dwObjectSubType, void *lpInput, long dwInputSize,
       const char *LibraryName, const char *FuncName)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetPrimeCommonCallback)) { return 0; }
	else { return Dll_SetPrimeCommonCallback(dwEventType,lpFunc,dwCookie,
                 dwCallbackFlags,dwPriority,lpObject,dwObjectType,
                 dwObjectSubType,lpInput,dwInputSize,LibraryName,FuncName); }
}

LongBoolean DeletePrimeCallback(long dwHandle)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_DeletePrimeCallback)) { return 0; }
	else { return Dll_DeletePrimeCallback(dwHandle); }
}

LongBoolean IsPrimeCallback(long dwHandle)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_IsPrimeCallback)) { return 0; }
	else { return Dll_IsPrimeCallback(dwHandle); }
}

LongBoolean DeletePrimeCallbacks(HINSTANCE H, long dwFlags)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_DeletePrimeCallbacks)) { return 0; }
	else { return Dll_DeletePrimeCallbacks(H, dwFlags); }
}

LongBoolean PlanObjDragDrop(void *lpObjectToDrop, void *lpDropTemplate, long dwFlags, void *lpReserved)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_PlanObjDragDrop)) { return 0; }
	else { return Dll_PlanObjDragDrop(lpObjectToDrop, lpDropTemplate, dwFlags, lpReserved); }
}

long PrimeExecuteFunction(const char *lpLibraryName, const char *lpFuncName,
       void *lpPlansheet, void *lpUser, void *lpReserved)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_PrimeExecuteFunction)) { return paNotExecuted; }
	else { return Dll_PrimeExecuteFunction(lpLibraryName, lpFuncName,
                        lpPlansheet, lpUser, lpReserved); }
}

long GetStandardLayerCodeByIndex(void *Tower, long Index,
           char *Code, long CodeMaxLen, long Flags)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetStandardLayerCodeByIndex)) { return -1; }
	else { return Dll_GetStandardLayerCodeByIndex(Tower, Index, Code,
                        CodeMaxLen, Flags); }
}

long SetStandardLayerCodeByIndex(void *Tower, long Index,
           const char *Code, long Flags)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetStandardLayerCodeByIndex)) { return -1; }
	else { return Dll_SetStandardLayerCodeByIndex(Tower, Index, Code, Flags); }
}

long GetLayerIndex(void *Tower, long Depth)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetLayerIndex)) { return -1; }
	else { return Dll_GetLayerIndex(Tower, Depth); }
}

long GetTarget(char *lpRegion, long nRegionLen, char *lpField, long nFieldLen,
           char *lpWell, long nWellLen, void *lpOtherData, long nOtherDataLen)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_GetTarget)) { return -1; }
	else { return Dll_GetTarget(lpRegion, nRegionLen, lpField, nFieldLen,
            lpWell, nWellLen, lpOtherData, nOtherDataLen); }
}

long SetTarget(const char *lpRegion, const char *lpField, const char *lpWell,
           LongBoolean lbCanCreate, void *lpOtherData, long nOtherDataLen)
{
	if ((hDLL_PRIME32 == NULL)||(!Dll_SetTarget)) { return -1; }
	else { return Dll_SetTarget(lpRegion, lpField, lpWell, lbCanCreate,
            lpOtherData, nOtherDataLen); }
}

char* __cdecl Prime_C_Translate(long Magic1, long Magic2, long Magic3, long Magic4, char *Str, char *StrID)
{
  if (hDLL_PRIME32 == NULL)
  {
    hDLL_PRIME32 = GetModuleHandle(PRIME32DLL);
    if (hDLL_PRIME32 != NULL)
    {
      Dll_PrimeSimpleTranslateString = (PDll_PrimeSimpleTranslateString)GetProcAddress(hDLL_PRIME32, "PrimeSimpleTranslateString");
    }
  }
  if ((hDLL_PRIME32 == NULL)||(!Dll_PrimeSimpleTranslateString)) { return Str; }
  else { return Dll_PrimeSimpleTranslateString(Str, StrID); }
}

#ifndef NOVCL

#ifdef __BORLANDC__
  // Borland C++ or Builder
  #if __BCPLUSPLUS__ > 0x520
      // Builder

const unsigned short CallAddrx86OpCode = 0x25FF; /* call dword ptr [disp32] */

typedef struct {
  unsigned short Code;
  void **NewAddrPtr;
} TDLLJumpRec, *PDLLJumpRec;

void *GetRealFuncAddr(void *Addr)
{
  void *Result;
  for(Result = Addr;
      Result && (((PDLLJumpRec) Result)->Code == CallAddrx86OpCode);
      Result = *((PDLLJumpRec) Result)->NewAddrPtr);
  return Result;
};

LongBoolean NeedNotTerminating()
// Âûäà¸ò True, åñëè âûçâàíî èç DLL è VCL ïðèëèíêîâàíà ñòàòè÷åñêè
{
  return ModuleIsLib &&
    ((long) FindHInstance(GetRealFuncAddr(&FindHInstance)) == (long) HInstance);
};

bool __fastcall PrimeLibraryTerminateProc(void) // Çàïðåò Application.Terminate
{
  if(NeedNotTerminating && (Application->MainForm))
  {
    Application->MainForm->Release();
  }
  return false;
};

BOOL __stdcall DestroyThisModuleWindowsProc(HWND Handle, void *Info)
{
  char AClassName[256];
  DWORD PID;
  GetWindowThreadProcessId(Handle,&PID);
  if (PID != GetCurrentProcessId())
  {
    return true;
  }
  TWinControl *Control = FindControl(Handle);
  if (Control)
  {
    if ((long) FindHInstance((void*)Control->ClassType()) == (long)HInstance)
    {
      try {
        Control->Free();
      }
      catch(...) {
      };
      if ( (GetClassName(Handle,AClassName,255) > 0) && (strcmp("TPUtilWindow",AClassName) == 0))
      {
        DeallocateHWnd(Handle);
      }
      else {
        DestroyWindow(Handle);
      }
    };
  }
  else {
    if ((long)GetWindowLong(Handle, GWL_HINSTANCE) == (long) HInstance)
    {
      try {
        SendMessage(Handle,CM_RELEASE,0,0);
      }
      catch(...) {
      };
      if ( (GetClassName(Handle,AClassName,255) > 0) && (strcmp("TPUtilWindow",AClassName) == 0))
      {
        DeallocateHWnd(Handle);
      }
      else {
        DestroyWindow(Handle);
      }
    };
  };
  return true;
};

void DestroyThisModuleWindows()
{
  EnumWindows((int (__stdcall *) ())&DestroyThisModuleWindowsProc,0);
};

void initialization()
{
  if (NeedNotTerminating()) AddTerminateProc(&PrimeLibraryTerminateProc);
  //DecimalSeparator := '.';
}

void finalization()
{
  if (NeedNotTerminating() && Application)
  {
    Application->ShowHint = false;
    Application->Handle = 0;
    Application->CancelHint();
  }
  DestroyThisModuleWindows();
}

#pragma startup initialization
#pragma exit finalization

  #endif
#endif
#endif //NOVCL



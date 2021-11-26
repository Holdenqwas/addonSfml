/*************************************************************************\
*                                                                         *
* Система информационного обеспечения геофизических исследований скважин  *
*   "ПРАЙМ" для Windows                                                   *
* HelloExe.cpp - пример программы, работающей с сервером данных Прайм     *
* Язык: C++ (Microsoft Visual C++)                                        *
*                                                                         *
* Подключение к функциям сервера данных производится динамически,         *
*                                                                         *
\*************************************************************************/

#include <windows.h>
#include <commdlg.h>
#include <stdio.h>
#include <time.h>
#include "DSAPI.h"
#include "DSExt.h"

HWND MainHWnd = NULL;

// Получить от пользователя имя файла WS для записи
bool GetSaveWSFile(char *Result){
	OPENFILENAME ofn;
	bool Res;
	strcpy(Result,"");
	ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = MainHWnd;
	ofn.hInstance = NULL;
    ofn.lpstrFilter ="Файлы WS (*.ws)\000*.ws\000Все файлы (*.*)\000*.*\000\000";
    ofn.lpstrCustomFilter = NULL;
    ofn.nMaxCustFilter = 0;
    ofn.nFilterIndex = 0;
    ofn.lpstrFile = Result;
    ofn.nMaxFile = 256;
    ofn.lpstrFileTitle = NULL; 
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.lpstrTitle = "Выберите файл рабочей области для записи";
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

/* Пример создания данных непрерывной кривой (что-то подобное есть в любой
   программе, создающей с нуля кривые или попластовые колонки). Функция
   CreateCurveData создаёт непрерывные данные по методу ГИС и параметрам
   дискретизации, используя структуру PCURVE из файла системных ресурсов
   WSIGF.RES. Вообще рекомендуется отделять эту функцию, создающую данные
   и заполняющую все нужные поля от функций, заполняющих собственно данные
   кривой (в массиве этого объекта).
     Method - Метод ГИС
     Roof - кровля
     Sole - подошва
     Step - шаг дискретизации (должен быть больше нуля!)
     hObj - указатель на переменную, в которую заносится созданный Handle 
            данных */
bool CreateCurveData(const char *Method, long Roof, long Sole, long Step, OType *hObj)
{
  /* Получение корневого каталога системы Прайм */
  char SystemResFileName[MAX_PATH+1];
  GetAlgPath(SystemResFileName,MAX_PATH);
  strcat(SystemResFileName,"WSIGF.RES");
  /* Создание данных из ресурса для непрерывной кривой */
  if (ObjTDInit(SystemResFileName,"PCURVE",hObj)) return false;
  PutFieldString(*hObj,MGIS,Method); // запись метода кривой
  /* Рекомендуется записывать в поле "ИСТОЧНИК" идентификатор программы,
     создавшей данные */
  PutFieldString(*hObj,"ИСТОЧНИК","FXC-PNG Hello"); // макс. 25 символов
  OType hArr = hNil;
  GetArrayByName(&hArr,"",*hObj);
  SetField(*hObj,hArr,Roof,Sole,Step);
  DoneHandle(&hArr);
  return true;
} // CreateCurveData

/* Пример создания попластовых данных. Функция CreateLayerData
   создаёт попластовые данные данные по методу ГИС, кровле и подошве,
   используя структуру HCURVE из файла системных ресурсов WSIGF.RES.
     Method - Метод ГИС
     Roof - кровля
     Sole - подошва
     hObj - указатель на переменную, в которую заносится созданный Handle 
            данных */
bool CreateLayerData(const char *Method, long Roof, long Sole, OType *hObj)
{
  /* Получение корневого каталога системы Прайм */
  char SystemResFileName[MAX_PATH+1];
  GetAlgPath(SystemResFileName,MAX_PATH);
  strcat(SystemResFileName,"WSIGF.RES");
  /* Создание данных из ресурса для попластовой кривой */
  if (ObjTDInit(SystemResFileName,"HCURVE"/*"ЛИТОЛОГИЯ"*/,hObj)) return false;
  PutFieldString(*hObj,MGIS,Method); // запись метода кривой
  //PutFieldString(*hObj,"ИДЕНТИФИКАТОР",Method); - для ресурса "ЛИТОЛОГИЯ" 
  /* Рекомендуется записывать в поле "ИСТОЧНИК" идентификатор программы,
     создавшей данные */
  PutFieldString(*hObj,"ИСТОЧНИК","FXC-PNG Hello"); // макс. 25 символов
  OType hArr = hNil;
  GetArrayByName(&hArr,"",*hObj);
  SetField(*hObj,hArr,Roof,Sole,0);
  DoneHandle(&hArr);
  return true;
} // CreateLayerData

/* Записывает тестовые данные кривой в таблицу PCURVE указанного WS-файла */
void SaveTestData(const char *FileName)
{
  OType hObj;
  long Roof = 140000; // Кровля - 1400.00 м
  long Sole = 150000; // Подошва - 1500.00 м
  long Step = 20; // Шаг дискретизации - 0.2 м
  if (CreateCurveData("Например, T1",140000,150000,20,&hObj))
  {
    srand( (unsigned)time( NULL ) );
    OType hArr;
	GetArrayByName(&hArr,"",hObj);
	/* Собственно запись данных */
	for (int i = 0; i <= (Sole-Roof)/Step; i++)
	{
	  ArrayPutSingleColumnData(hArr,1,i,(float)0.0001*rand()*rand());
	}
	DoneHandle(&hArr);
	/* Сохранение данных */
	int ErrCode = Save_WS("PCURVE","PCURVE",FileName,false,hObj);
	if (ErrCode)
	{
	  char Msg[255];
	  sprintf(Msg,"Функция Save_WS возвратила код ошибки %d",ErrCode);
      MessageBox(0,
        Msg,
        "Информация функции SaveTestData", 
        MB_OK | MB_ICONERROR | MB_TASKMODAL);
	}
	else
	{
      MessageBox(0,
        "Успешное сохранение данных",
        "Информация функции SaveTestData", 
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
  // Запрос имени файла для записи
  if (!GetSaveWSFile(WorkSpace))
  {
    return -2;
  }
  SaveTestData(WorkSpace);
  DSExtFree();
  return 0;
}
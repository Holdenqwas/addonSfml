#include <iostream>
//#include <string>

//#include <fstream>

#include "Form.h"

#include "DSAPI.h"
#include "DSExt.h"
#include "PrimeAPI.h"



void CreateConsole()
{
	setlocale(LC_ALL, "Russian");
	if (!AllocConsole()) {
		// Add some error handling here.
		// You can call GetLastError() to get more info about the error.
		return;
	}

	// std::cout, std::clog, std::cerr, std::cin
	FILE* fDummy;
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	std::cout.clear();
	std::clog.clear();
	std::cerr.clear();
	std::cin.clear();

}
*/
extern "C" void __stdcall Hello(void) {
	/* Попытка динамического подключения к графическому монитору */
	if (!Prime32Connect())
	{
		return;
	}

	sf::RenderWindow window(sf::VideoMode(900, 900), "Autoreload");
	window.setFramerateLimit(30);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		
		}

		window.clear(sf::Color::White);

		window.draw(text);
		window.display();
	}


	char FileName[1000] = "";
	char AWildCard[1000] = "WildCard";
	char ATitle[1000] = "Title";
	char Value[1000] = "";
	char temp[100] = "";
	char result;
	char well[100] = "";
	char alt[100] = "";
	float li = 0;

	std::map <int, char*> ::iterator it;

	void reloadColl()
	{
		std::map <int, char*> choices_col = { {818, "¦¦¦КПСР¦¦¦0"},
										{823, "¦¦¦КП_Н¦¦¦0" },
										{825, "¦¦¦RП_П¦¦¦0"},
										{827, "¦¦¦КП_П¦¦¦0"},
										{828, "¦¦¦КНГ_П¦¦¦0"},
										{849, "¦¦¦НН¦¦¦0"},
										{855, "¦¦¦Н¦¦¦0"} };
	}


	void reloadCurve()
	{
		std::map <int, char*> choices = { {649, "¦¦¦¦КП¦¦0"},
										{651, "¦¦¦¦КГЛ¦¦0"},
										{652, "¦¦¦¦КНГ¦¦0"},
										{659, "¦¦¦¦АГК¦¦0"},
										{660, "¦¦¦¦АНГК¦¦0"},
										{664, "¦¦¦АГК_П¦¦¦0"},
										{665, "¦¦¦КГЛ_П¦¦¦0"},
										{666, "¦¦¦АНГК_П¦¦¦0"},
										{715, "¦¦¦¦КПР¦¦0"},
										{716, "¦¦¦КПР_П¦¦¦0"},
										{814, "¦¦¦КП_П¦¦¦0"},
										{815, "¦¦¦КНГ_П¦¦¦0"},
										{850, "¦¦¦КП_Н¦¦¦0"},
										{852, "¦¦¦КПСР¦¦¦0"},
										{854, "¦¦¦НН¦¦¦0"},
										{856, "¦¦¦Н¦¦¦0"},
										{863, "¦¦¦СУМ_КП_Н¦¦¦0"},
										{864, "¦¦¦СУМ_НН¦¦¦0"},
										{875, "¦¦¦RП_П¦¦¦0"} };
	}


	//CreateConsole();

	OType LFHandle, LRHandle, ObjHandle, ArrHandle, THandle = hNil;
	namespace fs = std::filesystem;



	InputString("Введите путь", "Путь папки с планшетами", 200, Value);
	//GetFilename("AWildCard", "ATitle", FileName);
	//std::cout << FileName << std::endl;
	std::string path = Value;

	//для тестирования
	//std::string path = "\\\\PRIME.ec.tatneft.ru\\Prime_Татнефть$\\Подсчет запасов\\Тест\\автозагрузка\\папка";
	//int count = 0;

	std::ofstream logError;				//дял записи в свс

	logError.open(path + "\\errors.csv");
	logError << "Well;Curves;Towers;Perforations;Well testing;Error" << std::endl;

	//фильип скважин
	std::string path_csv = path + "\\test.csv";
	std::ifstream  data(path_csv.c_str());
	std::string line;
	std::vector<std::vector<std::string> > parsedCsv;
	while (std::getline(data, line))
	{
		std::stringstream lineStream(line);
		std::string cell;
		std::vector<std::string> parsedRow;
		while (std::getline(lineStream, cell, ';'))
		{
			parsedRow.push_back(cell);
		}

		parsedCsv.push_back(parsedRow);
	}

	for (auto& p : fs::directory_iterator(path)) {
		//для подсчета времени
		//auto start = std::chrono::system_clock::now();

		//std::cout << p.path() << std::endl;
		for (auto& file : fs::directory_iterator(p.path())) {
			std::string path2 = file.path().string();

			if (path2.substr(path2.length() - 2) == "WS" || path2.substr(path2.length() - 2) == "ws")
			{
				std::string name_plan = file.path().stem().string();
				for (int i = 0; i < parsedCsv.size(); i++) {

					//если имя планшета есть в списке csv
					if (parsedCsv[i][0] == name_plan) {
						logError << name_plan << ";";
						//std::cout << "начал" << std::endl;
						SysLFInitOpen(path2.c_str(), &LFHandle);

						Get_Table("ПЛАНШЕТ", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);

						//кривые
						GetArrayByName(&ArrHandle, "VIEWCURVES", ObjHandle);
						logError << ArrayGetLen(ArrHandle) << ";";
						for (long i = 0; i < ArrayGetLen(ArrHandle); i++)
						{
							GetArraySingle(ArrHandle, i, "Ident", &li);

							it = choices.find(li);
							if (it != choices.end())
							{
								boost::uuids::random_generator uuid_gen;
								boost::uuids::uuid u = uuid_gen();
								std::string tmp = boost::uuids::to_string(u);

								std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
								tmp = "{" + tmp + "}";

								xPutArrayString(ArrHandle, i, "PackCurveInfo", it->second);
								xPutArrayString(ArrHandle, i, "CurveGUID", tmp.c_str());
							}

						}

						LRPutObj(LRHandle, ObjHandle, 0, 0);

						//колонки
						GetArrayByName(&ArrHandle, "ViewInterTowers", ObjHandle);
						logError << ArrayGetLen(ArrHandle) << ";";
						for (long i = 0; i < ArrayGetLen(ArrHandle); i++)
						{
							GetArraySingle(ArrHandle, i, "Ident", &li);

							it = choices_col.find(li);
							if (it != choices_col.end())
							{
								boost::uuids::random_generator uuid_gen;
								boost::uuids::uuid u = uuid_gen();
								std::string tmp = boost::uuids::to_string(u);

								std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
								tmp = "{" + tmp + "}";

								xPutArrayString(ArrHandle, i, "PackedDataKey", it->second);
								xPutArrayString(ArrHandle, i, "DataGUID", tmp.c_str());
							}
						}

						LRPutObj(LRHandle, ObjHandle, 0, 0);

						DoneHandle(&ArrHandle);
						DoneHandle(&ObjHandle);
						DoneHandle(&LRHandle);
						//перфорация
						Get_Table("ПРИМИТИВЫ_ИНТЕРВАЛА", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);
						DoneHandle(&ArrHandle);
						GetArrayByName(&ArrHandle, "ПЕРФОРАЦИЯ_ФАКТИЧЕСК", ObjHandle);
						long count_perf = ArrayGetLen(ArrHandle);

						DoneHandle(&ArrHandle);
						GetArrayByName(&ArrHandle, "ИНТ_ОПР_ЗАКР", ObjHandle);
						long count_opr = ArrayGetLen(ArrHandle);

						logError << count_perf << ";" << count_opr << ";";

						DoneHandle(&ArrHandle);
						Get_Table("ПЛАНШЕТ", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);

						GetArrayByName(&ArrHandle, "ViewIntervals", ObjHandle);

						std::string tmp;
						std::string tmp_counter;

						if (count_perf) {
							for (int i = 0; i < count_perf; i++)
							{
								tmp_counter = std::to_string(921 + i);

								xPutArrayString(ArrHandle, i, "Ident", tmp_counter.c_str());
								xPutArrayString(ArrHandle, i, "Owner", "-1");
								xPutArrayString(ArrHandle, i, "State", "0");
								xPutArrayString(ArrHandle, i, "Start", "1433");
								xPutArrayString(ArrHandle, i, "Width", "50");
								xPutArrayString(ArrHandle, i, "Color", "0");
								xPutArrayString(ArrHandle, i, "ArrayName", "ПЕРФОРАЦИЯ_ФАКТИЧЕСК");
								tmp_counter = std::to_string(i);
								xPutArrayString(ArrHandle, i, "ArrayRow", tmp_counter.c_str());

								xPutArrayString(ArrHandle, i, "Copies", "Array 0");

							}
						}

						if (count_opr) {
							int pos_opr = 0;
							for (int i = (count_perf ? count_perf : 0); i < count_opr + (count_perf ? count_perf : 0); i++)
							{
								tmp_counter = std::to_string(921 + i);

								xPutArrayString(ArrHandle, i, "Ident", tmp_counter.c_str());
								xPutArrayString(ArrHandle, i, "Owner", "-1");
								xPutArrayString(ArrHandle, i, "State", "0");
								xPutArrayString(ArrHandle, i, "Start", "1580");
								xPutArrayString(ArrHandle, i, "Width", "50");
								xPutArrayString(ArrHandle, i, "Color", "0");
								xPutArrayString(ArrHandle, i, "ArrayName", "ИНТ_ОПР_ЗАКР");
								tmp_counter = std::to_string(pos_opr);
								xPutArrayString(ArrHandle, i, "ArrayRow", tmp_counter.c_str());

								xPutArrayString(ArrHandle, i, "Copies", "Array 0");
								pos_opr++;
							}
						}

						LRPutObj(LRHandle, ObjHandle, 0, 0);

						DoneHandle(&ArrHandle);
						DoneHandle(&ObjHandle);
						DoneHandle(&LRHandle);
						DoneHandle(&LFHandle);

						logError << std::endl;
					}
				}
			}
		}


		//для подсчета времени
		/*
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;
		*/
	}

	//std::cout << "Done " << std::endl;
	logError.close();
	//CreateConsole();

	//std::cout << "Done."<< std::endl;
	
} // Hello01



const char* CopyrightMessage = "Графическая библиотека для системы \"Прайм\"\r(c) 2021 Антон Хорн";

extern "C" const char* __stdcall PrimeLibraryCopyright(void)
{
	return CopyrightMessage;
}

const char* ExportedFunctions[] =
{
	"Hello\rЗагрузить пласты\rГрузит пласты из стратиграфии",
	NULL
};

extern "C" const char** __stdcall PrimeExportedFunctions(void) {
	return ExportedFunctions;
}

const char* Version = "01.00.00.0021";

extern "C" const char* __stdcall PrimeLibraryVersion(void)
{
	return Version;
}
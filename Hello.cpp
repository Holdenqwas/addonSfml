#include "DSAPI.h"
#include "DSExt.h"
#include "PrimeAPI.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <commdlg.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <algorithm>

#include <sstream>

#include "Form.h"

void CreateConsole()
{
	setlocale(LC_ALL, "Russian");
	if (!AllocConsole())
	{
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

extern "C" void __stdcall Hello(void)
{
	if (!Prime32Connect())
	{
		return;
	}

	// Variables
	std::string path;
	std::vector <std::string> arrWells;

	OType LFHandle, LRHandle, ObjHandle, ArrHandle, THandle = hNil;
	namespace fs = std::filesystem;

	// App
	sf::RenderWindow window(sf::VideoMode(600, 500), "Autoreload");
	window.setFramerateLimit(30);

	// left block
	Text editPathText("Input work directory:");
	editPathText.setPosition(sf::Vector2f(30, 30));

	TextEdit editPath(170);
	editPath.setPosition(sf::Vector2f(30, 70));

	Text inputWell("Input wells:");
	inputWell.setPosition(sf::Vector2f(30, 110));

	ListText list(170, 250, 10);
	list.setPosition(sf::Vector2f(30, 150));

	// rigth block
	CheckBox editPz;
	editPz.setPosition(sf::Vector2f(270, 30));
	Text editPzTitle("Reload PZ coefficients");
	editPzTitle.setPosition(sf::Vector2f(300, 30));

	CheckBox editRigis;
	editRigis.setPosition(sf::Vector2f(270, 70));
	Text editRigisTitle("Reload RIGIS");
	editRigisTitle.setPosition(sf::Vector2f(300, 70));

	CheckBox editIndex;
	editIndex.setPosition(sf::Vector2f(270, 110));
	Text editIndexTitle("Reload Indexes");
	editIndexTitle.setPosition(sf::Vector2f(300, 110));

	CheckBox editPerf;
	editPerf.setPosition(sf::Vector2f(270, 150));
	Text editPerfTitle("Reload Perforations");
	editPerfTitle.setPosition(sf::Vector2f(300, 150));

	Text perfStartTitle("Input start Perforation:");
	perfStartTitle.setPosition(sf::Vector2f(300, 190));
	TextEdit perfStart(50);
	perfStart.setPosition(sf::Vector2f(480, 190));

	CheckBox editTest;
	editTest.setPosition(sf::Vector2f(270, 230));
	Text editTestTitle("Reload Tests");
	editTestTitle.setPosition(sf::Vector2f(300, 230));

	Text testStartTitle("Input start Tests:");
	testStartTitle.setPosition(sf::Vector2f(300, 270));
	TextEdit testStart(50);
	testStart.setPosition(sf::Vector2f(480, 270));

	Text editCurveTitle("Reload Curves");
	editCurveTitle.setPosition(sf::Vector2f(270, 310));

	CheckBox editKS;
	editKS.setPosition(sf::Vector2f(300, 340));
	Text editKSTitle("KS");
	editKSTitle.setPosition(sf::Vector2f(330, 340));

	CheckBox editPS;
	editPS.setPosition(sf::Vector2f(300, 370));
	Text editPSTitle("PS");
	editPSTitle.setPosition(sf::Vector2f(330, 370));

	CheckBox editDS;
	editDS.setPosition(sf::Vector2f(300, 400));
	Text editDSTitle("DS");
	editDSTitle.setPosition(sf::Vector2f(330, 400));

	CheckBox editGK;
	editGK.setPosition(sf::Vector2f(400, 340));
	Text editGKTitle("GK");
	editGKTitle.setPosition(sf::Vector2f(430, 340));

	CheckBox editNGK;
	editNGK.setPosition(sf::Vector2f(400, 370));
	Text editNGKTitle("NGK");
	editNGKTitle.setPosition(sf::Vector2f(430, 370));

	CheckBox editBK;
	editBK.setPosition(sf::Vector2f(500, 340));
	Text editBKTitle("BK");
	editBKTitle.setPosition(sf::Vector2f(530, 340));

	CheckBox editIK;
	editIK.setPosition(sf::Vector2f(500, 370));
	Text editIKTitle("IK");
	editIKTitle.setPosition(sf::Vector2f(530, 370));

	Button startProcess("Start");
	startProcess.setPosition(sf::Vector2f(480, 450));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			path = editPath.process(event);
			arrWells = list.process(event);
			editPz.process(event);
			editRigis.process(event);
			editIndex.process(event);
			editPerf.process(event);
			perfStart.process(event);
			editTest.process(event);
			testStart.process(event);

			editKS.process(event);
			editPS.process(event);
			editDS.process(event);

			editGK.process(event);
			editNGK.process(event);

			editBK.process(event);
			editIK.process(event);

			startProcess.process(event);
		}

		window.clear(sf::Color::White);

		editPath.render(window);
		editPathText.render(window);
		inputWell.render(window);
		list.render(window);
		editPz.render(window);
		editPzTitle.render(window);
		editRigis.render(window);
		editRigisTitle.render(window);
		editIndex.render(window);
		editIndexTitle.render(window);
		editPerf.render(window);
		editPerfTitle.render(window);
		perfStart.render(window);
		perfStartTitle.render(window);
		editTest.render(window);
		editTestTitle.render(window);
		testStart.render(window);
		testStartTitle.render(window);
		editCurveTitle.render(window);

		editKS.render(window);
		editKSTitle.render(window);
		editPS.render(window);
		editPSTitle.render(window);
		editDS.render(window);
		editDSTitle.render(window);

		editGK.render(window);
		editGKTitle.render(window);
		editNGK.render(window);
		editNGKTitle.render(window);

		editIK.render(window);
		editIKTitle.render(window);
		editBK.render(window);
		editBKTitle.render(window);

		startProcess.render(window);

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

	std::map<int, char*>::iterator it;

	std::map <int, char*> choices_col = { {818, "¦¦¦КПСР¦¦¦0"},
										{823, "¦¦¦КП_Н¦¦¦0" },
										{825, "¦¦¦RП_П¦¦¦0"},
										{827, "¦¦¦КП_П¦¦¦0"},
										{828, "¦¦¦КНГ_П¦¦¦0"},
										{849, "¦¦¦НН¦¦¦0"},
										{855, "¦¦¦Н¦¦¦0"} };

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



	// CreateConsole();

	//��� ������������
	// std::string path = "\\\\PRIME.ec.tatneft.ru\\Prime_Татнефть$\\Подсчет запасов\\Тест\\автозагрузка\\папка";
	// int count = 0;

	for (int i = 0; i < arrWells.size(); i++)
	{
		std::cout << arrWells[i] << std::endl;
	}

	for (auto& p : fs::directory_iterator(path))
	{

		// auto start = std::chrono::system_clock::now();

		// std::cout << p.path() << std::endl;
		for (auto& file : fs::directory_iterator(p.path()))
		{
			std::string path2 = file.path().string();

			if (path2.substr(path2.length() - 2) == "WS" || path2.substr(path2.length() - 2) == "ws")
			{
				std::string name_plan = file.path().stem().string();
				for (int i = 0; i < arrWells.size(); i++)
				{


					if (arrWells[i] == name_plan)
					{
						// std::cout << "�����" << std::endl;
						SysLFInitOpen(path2.c_str(), &LFHandle);

						Get_Table("ПЛАНШЕТ", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);

						//������
						GetArrayByName(&ArrHandle, "VIEWCURVES", ObjHandle);
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

						//�������
						GetArrayByName(&ArrHandle, "ViewInterTowers", ObjHandle);
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
						//����������
						Get_Table("ПРИМИТИВЫ_ИНТЕРВАЛА", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);
						DoneHandle(&ArrHandle);
						GetArrayByName(&ArrHandle, "ПЕРФОРАЦИЯ_ФАКТИЧЕСК", ObjHandle);
						long count_perf = ArrayGetLen(ArrHandle);

						DoneHandle(&ArrHandle);
						GetArrayByName(&ArrHandle, "ИНТ_ОПР_ЗАКР", ObjHandle);
						long count_opr = ArrayGetLen(ArrHandle);


						DoneHandle(&ArrHandle);
						Get_Table("ПЛАНШЕТ", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);

						GetArrayByName(&ArrHandle, "ViewIntervals", ObjHandle);

						std::string tmp;
						std::string tmp_counter;

						if (count_perf)
						{
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

						if (count_opr)
						{
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

					}
				}
			}
		}

		//��� �������� �������
		/*
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;
		*/
	}

	// std::cout << "Done " << std::endl;

	// CreateConsole();

	// std::cout << "Done."<< std::endl;

} // Hello01

const char* CopyrightMessage = "Библиотека для системы \"Прайм\"\r(c) 2021 Антон Хорн";

extern "C" const char* __stdcall PrimeLibraryCopyright(void)
{
	return CopyrightMessage;
}

const char* ExportedFunctions[] =
{
	"Hello\rЗагрузить колонки и примитивы\rПерезагружает кривые",
	NULL };

extern "C" const char** __stdcall PrimeExportedFunctions(void)
{
	return ExportedFunctions;
}

const char* Version = "01.00.00.0021";

extern "C" const char* __stdcall PrimeLibraryVersion(void)
{
	return Version;
}
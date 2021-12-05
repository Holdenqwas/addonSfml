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
	if (!AllocConsole())
	{
		// Add some error handling here.
		// You can call GetLastError() to get more info about the error.
		return;
	}

	// std::cout, std::clog, std::cerr, std::cin
	FILE *fDummy;
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

	std::string pathFont = "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf";
	sf::RenderWindow window(sf::VideoMode(600, 500), "Autoreload");
	window.setFramerateLimit(30);

	// left block
	Text inputWell("Input wells:", pathFont);
	inputWell.setPosition(sf::Vector2f(30, 30));

	ListText list(170, 350, 10);
	list.setPosition(sf::Vector2f(30, 60));

	// rigth block
	CheckBox editPz;
	editPz.setPosition(sf::Vector2f(270, 30));
	Text editPzTitle("Reload PZ coefficients", pathFont);
	editPzTitle.setPosition(sf::Vector2f(300, 30));

	CheckBox editRigis;
	editRigis.setPosition(sf::Vector2f(270, 70));
	Text editRigisTitle("Reload RIGIS", pathFont);
	editRigisTitle.setPosition(sf::Vector2f(300, 70));

	CheckBox editIndex;
	editIndex.setPosition(sf::Vector2f(270, 110));
	Text editIndexTitle("Reload Indexes", pathFont);
	editIndexTitle.setPosition(sf::Vector2f(300, 110));

	CheckBox editPerf;
	editPerf.setPosition(sf::Vector2f(270, 150));
	Text editPerfTitle("Reload Perforations", pathFont);
	editPerfTitle.setPosition(sf::Vector2f(300, 150));

	Text perfStartTitle("Input start Perforation:", pathFont);
	perfStartTitle.setPosition(sf::Vector2f(300, 190));
	TextEdit perfStart(50, pathFont);
	perfStart.setPosition(sf::Vector2f(480, 190));

	CheckBox editTest;
	editTest.setPosition(sf::Vector2f(270, 230));
	Text editTestTitle("Reload Tests", pathFont);
	editTestTitle.setPosition(sf::Vector2f(300, 230));

	Text testStartTitle("Input start Tests:", pathFont);
	testStartTitle.setPosition(sf::Vector2f(300, 270));
	TextEdit testStart(50, pathFont);
	testStart.setPosition(sf::Vector2f(480, 270));

	Text editCurveTitle("Reload Curves", pathFont);
	editCurveTitle.setPosition(sf::Vector2f(270, 310));

	CheckBox editKS;
	editKS.setPosition(sf::Vector2f(300, 340));
	Text editKSTitle("KS", pathFont);
	editKSTitle.setPosition(sf::Vector2f(330, 340));

	CheckBox editPS;
	editPS.setPosition(sf::Vector2f(300, 370));
	Text editPSTitle("PS", pathFont);
	editPSTitle.setPosition(sf::Vector2f(330, 370));

	CheckBox editDS;
	editDS.setPosition(sf::Vector2f(300, 400));
	Text editDSTitle("DS", pathFont);
	editDSTitle.setPosition(sf::Vector2f(330, 400));

	CheckBox editGK;
	editGK.setPosition(sf::Vector2f(400, 340));
	Text editGKTitle("GK", pathFont);
	editGKTitle.setPosition(sf::Vector2f(430, 340));

	CheckBox editNGK;
	editNGK.setPosition(sf::Vector2f(400, 370));
	Text editNGKTitle("NGK", pathFont);
	editNGKTitle.setPosition(sf::Vector2f(430, 370));

	CheckBox editBK;
	editBK.setPosition(sf::Vector2f(500, 340));
	Text editBKTitle("BK", pathFont);
	editBKTitle.setPosition(sf::Vector2f(530, 340));

	CheckBox editIK;
	editIK.setPosition(sf::Vector2f(500, 370));
	Text editIKTitle("IK", pathFont);
	editIKTitle.setPosition(sf::Vector2f(530, 370));

	Button startProcess("Start", pathFont);
	startProcess.setPosition(sf::Vector2f(480, 450));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			list.process(event);
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

	std::map<int, char *>::iterator it;

	void reloadColl()
	{
		std::map<int, char *> choices_col = {{818, "������Ц��0"},
											 {823, "�����_ͦ��0"},
											 {825, "���R�_Ϧ��0"},
											 {827, "�����_Ϧ��0"},
											 {828, "������_Ϧ��0"},
											 {849, "����ͦ��0"},
											 {855, "���ͦ��0"}};
	}

	void reloadCurve()
	{
		std::map<int, char *> choices = {{649, "�����Ϧ�0"},
										 {651, "������˦�0"},
										 {652, "������æ�0"},
										 {659, "������ʦ�0"},
										 {660, "�������ʦ�0"},
										 {664, "������_Ϧ��0"},
										 {665, "������_Ϧ��0"},
										 {666, "�������_Ϧ��0"},
										 {715, "������Ц�0"},
										 {716, "������_Ϧ��0"},
										 {814, "�����_Ϧ��0"},
										 {815, "������_Ϧ��0"},
										 {850, "�����_ͦ��0"},
										 {852, "������Ц��0"},
										 {854, "����ͦ��0"},
										 {856, "���ͦ��0"},
										 {863, "������_��_ͦ��0"},
										 {864, "������_�ͦ��0"},
										 {875, "���R�_Ϧ��0"}};
	}

	// CreateConsole();

	OType LFHandle, LRHandle, ObjHandle, ArrHandle, THandle = hNil;
	namespace fs = std::filesystem;

	InputString("������� ����", "���� ����� � ����������", 200, Value);
	// GetFilename("AWildCard", "ATitle", FileName);
	// std::cout << FileName << std::endl;
	std::string path = Value;

	//��� ������������
	// std::string path = "\\\\PRIME.ec.tatneft.ru\\Prime_��������$\\������� �������\\����\\������������\\�����";
	// int count = 0;

	std::ofstream logError; //��� ������ � ���

	logError.open(path + "\\errors.csv");
	logError << "Well;Curves;Towers;Perforations;Well testing;Error" << std::endl;

	//������ �������
	std::string path_csv = path + "\\test.csv";
	std::ifstream data(path_csv.c_str());
	std::string line;
	std::vector<std::vector<std::string>> parsedCsv;
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

	for (auto &p : fs::directory_iterator(path))
	{
		//��� �������� �������
		// auto start = std::chrono::system_clock::now();

		// std::cout << p.path() << std::endl;
		for (auto &file : fs::directory_iterator(p.path()))
		{
			std::string path2 = file.path().string();

			if (path2.substr(path2.length() - 2) == "WS" || path2.substr(path2.length() - 2) == "ws")
			{
				std::string name_plan = file.path().stem().string();
				for (int i = 0; i < parsedCsv.size(); i++)
				{

					//���� ��� �������� ���� � ������ csv
					if (parsedCsv[i][0] == name_plan)
					{
						logError << name_plan << ";";
						// std::cout << "�����" << std::endl;
						SysLFInitOpen(path2.c_str(), &LFHandle);

						Get_Table("�������", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);

						//������
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

						//�������
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
						//����������
						Get_Table("���������_���������", LFHandle, &LRHandle);
						Goto_BeginObj(LRHandle);
						GetCurObj(LRHandle, &ObjHandle);
						DoneHandle(&ArrHandle);
						GetArrayByName(&ArrHandle, "����������_���������", ObjHandle);
						long count_perf = ArrayGetLen(ArrHandle);

						DoneHandle(&ArrHandle);
						GetArrayByName(&ArrHandle, "���_���_����", ObjHandle);
						long count_opr = ArrayGetLen(ArrHandle);

						logError << count_perf << ";" << count_opr << ";";

						DoneHandle(&ArrHandle);
						Get_Table("�������", LFHandle, &LRHandle);
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
								xPutArrayString(ArrHandle, i, "ArrayName", "����������_���������");
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
								xPutArrayString(ArrHandle, i, "ArrayName", "���_���_����");
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

		//��� �������� �������
		/*
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;
		*/
	}

	// std::cout << "Done " << std::endl;
	logError.close();
	// CreateConsole();

	// std::cout << "Done."<< std::endl;

} // Hello01

const char *CopyrightMessage = "����������� ���������� ��� ������� \"�����\"\r(c) 2021 ����� ����";

extern "C" const char *__stdcall PrimeLibraryCopyright(void)
{
	return CopyrightMessage;
}

const char *ExportedFunctions[] =
	{
		"Hello\r��������� ������\r������ ������ �� ������������",
		NULL};

extern "C" const char **__stdcall PrimeExportedFunctions(void)
{
	return ExportedFunctions;
}

const char *Version = "01.00.00.0021";

extern "C" const char *__stdcall PrimeLibraryVersion(void)
{
	return Version;
}
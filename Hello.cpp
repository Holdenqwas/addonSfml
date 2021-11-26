#include <iostream>
#include <string>

//#include <fstream>

#include <SFML/Graphics.hpp>

#include "DSAPI.h"
#include "DSExt.h"
#include "PrimeAPI.h"


/*
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

	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	sf::CircleShape shape(100.f, 4);

	shape.setFillColor(sf::Color::Green);

	sf::String playerInput = "";
	
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");

	
	sf::Text text;
	text.setFont(font);
	text.setString("");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::TextEntered)
			{

				if (event.text.unicode == '\b')
				{
					playerInput.erase(playerInput.getSize() - 1, 1);
					text.setString(playerInput);
				}
				else if (event.text.unicode < 128) {
					playerInput += event.text.unicode;
					text.setString(playerInput);
				}
				
			}
		
		}

		window.clear(sf::Color::White);

		//window.draw(shape);
		window.draw(text);
		window.display();
	}
	//CreateConsole();

	//std::cout << "Done."<< std::endl;
	
} // Hello01



const char* CopyrightMessage = "Библиотека для системы \"Прайм\"\r(c) 2021 Антон Хорн";

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
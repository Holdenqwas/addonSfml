#ifndef ASSETMGR
#define ASSETMGR

//STD includes
#include <map>
#include <string>
#include <list>

//Thirdparty includes
#include <SFML/Graphics.hpp>

const std::string ASSETS_PATH = "resurses";

class AssetManager {
	public:
		AssetManager();
		void loadAll();
		bool init(char* arg0);

		void destroy();

		void loadFont(std::string name, std::string path);
		void loadTexture(std::string name, std::string path);

		void update();

		sf::Texture& getTexture(std::string key);
		sf::Font& getFont(std::string name);
	private:
		std::map<std::string, sf::Texture*> textures;
		std::map<std::string, sf::Font*> fonts;
};

#endif
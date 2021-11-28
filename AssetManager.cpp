#include "AssetManager.h"

AssetManager::AssetManager() {

}

void AssetManager::loadAll() {
	//fonts
	loadFont("main", "fonts/Roboto-Regular.ttf");

	//le player
	loadTexture("player", "player/idle.png");
	loadTexture("player_ak47", "player/ak47.png");
	loadTexture("player_pistol", "player/pistol.png");

	//weapons
	loadTexture("weapon_", "weapons/pistol.png");
}

bool AssetManager::init(char* arg0) {
	return true;
}

void AssetManager::destroy() {
	std::map<std::string, sf::Font*>::iterator fit;

	for ( fit = fonts.begin(); fit != fonts.end(); fit++ )
	{
		delete fit->second;
	}

	std::map<std::string, sf::Texture*>::iterator tit; //NO TITS

	for ( tit = textures.begin(); tit != textures.end(); tit++ )
	{
		delete tit->second;
	}

}


void AssetManager::loadTexture(std::string name, std::string path) {
	sf::Texture* t = new sf::Texture();

	if (!t->loadFromFile(ASSETS_PATH + "/" + path)) {

		return;
	}

	textures.insert(std::make_pair(name, t));
}

void AssetManager::update() {

}

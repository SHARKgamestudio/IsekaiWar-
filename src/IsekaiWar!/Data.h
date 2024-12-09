#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class Data
{
private:
	
	std::map<std::string, sf::Texture> textures;

public:

	Data();

	void SetTexture(std::string name, std::string path);
	sf::Texture* getTexture(std::string name);
};
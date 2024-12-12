#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#pragma endregion

const std::string path = "../../../src/IsekaiWar!/Assets/";

class ResourceManager {
private:
	std::map<std::string, sf::Texture> textures;
	ResourceManager();

public:
	void AddTexture(std::string name, std::string path);
	sf::Texture* GetTexture(std::string name);

	friend class Managers;
};
#include <SFML/Graphics.hpp>

#pragma region External Dependencies

#include <string>
#include <map>

#pragma endregion

const std::string path = "../../../src/";

static class ResourceManager {
private:
	std::map<std::string, sf::Texture> textures;
	ResourceManager();

public:
	void AddTexture(std::string name, std::string path);
	sf::Texture* GetTexture(std::string name);

	friend class Managers;
};
#include "pch.h"
#include "Data.h"

Data::Data()
{
	return;
}

void Data::SetTexture(std::string name, std::string path)
{
	static sf::Texture newTexture;
	if (!newTexture.loadFromFile(path))
	{
		// error
	}

	textures[name] = newTexture;
}

sf::Texture* Data::getTexture(std::string name)
{
	return &textures[name];
}
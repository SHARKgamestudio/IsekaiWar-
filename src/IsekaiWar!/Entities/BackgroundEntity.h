#pragma once

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/TravelingTexture.h"

#pragma endregion

class BackgroundEntity : public Entity, public TravelingTexture {	
public :
	BackgroundEntity(float x, float y, sf::Texture* texture, float speed);
	BackgroundEntity(sf::Vector2f pos, sf::Texture* texture, float speed);

	void Traveling(float dt);
	void Update(float dt);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
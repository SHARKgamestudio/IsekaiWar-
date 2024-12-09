#pragma once
#include "Entities/Entity.h"
#include "TravelingTexture.h"

class SpriteBackground : public Entity, public TravelingTexture
{	
public :

	SpriteBackground(float x, float y, sf::Texture* texture, float speed);
	SpriteBackground(sf::Vector2f pos, sf::Texture* texture, float speed);

	void Traveling(float dt);
	void Update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
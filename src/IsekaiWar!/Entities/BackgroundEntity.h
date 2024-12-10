#pragma once

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/TravellingModule.h"

#pragma endregion

class BackgroundEntity : public Entity, public TravellingModule {	
public :
	BackgroundEntity(float x, float y, sf::Texture* texture, float speed);
	BackgroundEntity(sf::Vector2f position, sf::Texture* texture, float speed);

	void Traveling(float deltaTime);
	void Update(float deltaTime) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
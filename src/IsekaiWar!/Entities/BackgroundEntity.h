#pragma once

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/TravellingModule.h"

#pragma endregion

class BackgroundEntity : public Entity, public TravellingModule {	
public :

	BackgroundEntity(sf::Texture* texture);

	void Traveling(float deltaTime);
	void Update(float deltaTime) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
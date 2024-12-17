#include "BackgroundEntity.h"
#include "../Managers.h"

BackgroundEntity::BackgroundEntity(sf::Texture* texture)
	: Entity(0, 0, texture, 1, 1),
	TravellingModule(sf::Vector2f(0, 1), 20.f) {
	texture->setRepeated(true);
	this->spritesheet.SetTexture(texture, 1, 1);
}

void BackgroundEntity::Traveling(float deltaTime) {
	u = u - normalisedDirection.x * deltaTime * speed;
	v = v - normalisedDirection.y * deltaTime * speed;

	spritesheet.SetTextureRect(sf::IntRect(int(u), int(v), 850, 650));
}

void BackgroundEntity::UpdateLogic(float deltaTime) {
	Traveling(deltaTime);
}

void BackgroundEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(this->getTransform());
	target.draw(spritesheet, states);
}

void BackgroundEntity::Despawn() {
	Managers::GetInstance()->SceneManager->currentLevel->DespawnBackground(this);
}
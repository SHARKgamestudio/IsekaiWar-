#include "CharacterEntity.h"

CharacterEntity::CharacterEntity(float x, float y, float w, float h, sf::Texture* texture, float radius, float health)
	: LivingEntity(x, y, w, h, texture, radius, health),
	MoveModule(sf::Vector2f(0, 0), 0) {
}

CharacterEntity::CharacterEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float health)
	: LivingEntity(position, scale, texture, radius, health),
	MoveModule(sf::Vector2f(0, 0), 0) {
}
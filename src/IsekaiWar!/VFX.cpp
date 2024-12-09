#include "VFX.h"

VFX::VFX(float x, float y, sf::Texture* texture, float speed) : Entity(x, y, texture), Movable(sf::Vector2f(0, 1), speed)
{
}
VFX::VFX(sf::Vector2f pos, sf::Texture* texture, float speed) : Entity(pos, texture), Movable(sf::Vector2f(0, 1), speed)
{
}

void VFX::Move(float dt)
{
	sprite.move(direction);
}

void VFX::Update(float dt)
{
	Move(dt);
}
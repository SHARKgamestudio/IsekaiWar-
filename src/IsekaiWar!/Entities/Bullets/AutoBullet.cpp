#include "AutoBullet.h"

AutoBullet::AutoBullet(float x, float y, sf::Texture* texture) : PlayerBullet(x, y, texture, 5.f, 5.f), MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {

};
AutoBullet::AutoBullet(sf::Vector2f pos, sf::Texture* texture) : PlayerBullet(pos, texture, 5.f, 5.f), MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {

};

void AutoBullet::Move(float dt) {
	sprite.move(normalisedDirection);
}

void AutoBullet::Update(float dt, std::vector<Entity*> entities) {
	Move(dt);
}
#include "StandardBullet.h"

StandardBullet::StandardBullet(float x, float y, sf::Texture* texture, int columns, int rows)
	: EnemyBullet(x, y, texture, columns, rows, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

StandardBullet::StandardBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split)
	: EnemyBullet(position, texture, split, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

void StandardBullet::Move(float deltaTime) {
}

void StandardBullet::Update(float deltaTime, std::vector<CollidableEntity*> entities) {
}
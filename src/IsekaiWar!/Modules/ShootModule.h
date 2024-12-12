#pragma once

#include <SFML/Graphics.hpp>

class BulletEntity;

class ShootModule {
protected:
	sf::Vector2f directionShoot;
	BulletEntity* bullet;

public:
	ShootModule(BulletEntity* bullet, sf::Vector2f directionShoot);

	void virtual Shoot();
};
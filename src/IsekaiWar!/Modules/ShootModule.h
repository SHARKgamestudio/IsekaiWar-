#pragma once
#include <SFML/Graphics.hpp>

class BulletEntity;

class ShootModule {
protected:
	sf::Vector2f directionShoot;

public:
	ShootModule(sf::Vector2f directionShoot);

	void virtual Shoot(BulletEntity* bullet);
};
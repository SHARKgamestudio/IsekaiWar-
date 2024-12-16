#pragma once
#include <SFML/Graphics.hpp>

enum StateAuto {
	Neutral,
	Fire,
	Water,
	FireAndWater,
};

class PlayerEntity;

class ShootModule {
protected:
	PlayerEntity* player;
	int currentBullet;

public:
	ShootModule();

	void ShootAuto();
	void ShootSpecial();
	void ShootUltime();
};
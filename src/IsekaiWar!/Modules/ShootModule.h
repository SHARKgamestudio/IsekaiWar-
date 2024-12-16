#pragma once
#include <SFML/Graphics.hpp>

enum StateAuto {
	Neutral,
	Fire,
	Water,
	FireAndWater,
};

class PlayerEntity;
class UltimeBullet;

class ShootModule {
protected:
	PlayerEntity* player;
	UltimeBullet* ultimeBullet;
	int currentBullet;

	bool canAuto;
	bool canSpecial;
	bool canUltime;

public:
	ShootModule(PlayerEntity* player);

	void ShootAuto();
	void ShootSpecial();
	void StartUltime();
	void StopUltime();
};
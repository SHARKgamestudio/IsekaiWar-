#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils/IntervalClock.h"

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

	IntervalClock clockAuto;
	IntervalClock clockSpecial;
	IntervalClock clockUltime;

	PlayerEntity* player;
	UltimeBullet* ultimeBullet;
	int currentBullet;

	bool canAuto;
	bool canSpecial;
	bool canUltime;

public:

	bool isFire;
	bool isWater;

	ShootModule(PlayerEntity* player);

	void ShootAuto();
	void ShootSpecial();
	void StartUltime();
	void StopUltime();

	void Update(float deltaTime);
	void UpdateBullets();
};
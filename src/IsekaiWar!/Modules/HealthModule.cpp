#include "HealthModule.h"

HealthModule::HealthModule(float health) {
	isDead = false;
	maxHP = health;
	HP = health;
}

float HealthModule::GetHealth() {
	return HP;
}

float HealthModule::GetMaxHealth() {
	return maxHP;
}

bool HealthModule::IsDead() {
	return isDead;
}

void HealthModule::TakeDamage(float damage) {
	HP -= damage;

	if (HP < 0) {
		HP = 0; isDead = true;
	}
}

void HealthModule::Heal(float health) {
	HP += health;
	if (HP > maxHP) {
		HP = maxHP;
	}
}

void HealthModule::UpdateMaxHealth(float newMaxHealth) {
	maxHP = newMaxHealth;
}
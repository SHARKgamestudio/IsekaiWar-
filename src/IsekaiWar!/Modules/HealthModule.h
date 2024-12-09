#pragma once

class HealthModule {
private:
	bool isDead;
	float HP, maxHP;

public:
	HealthModule(float health);

	float GetHealth();
	float GetMaxHealth();
	bool IsDead();

	void TakeDamage(float damage);
	void Heal(float health);
	void UpdateMaxHealth(float newMaxHealth);
};
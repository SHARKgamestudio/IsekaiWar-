#pragma once

class HealthModule {
private:
	bool isDead;
	float maxHP;
	float HP;

public:
	HealthModule(float health);

	float GetHealth();
	float GetMaxHealth();
	bool IsDead();

	void TakeDamage(float damage);
	void Heal(float health);
	void UpdateMaxHealth(float newMaxHealth);
};
#pragma once
class LifeManager
{
private:

	bool isDead;
	float maxHP;
	float HP;

public:

	LifeManager(float health);

	float GetHealth();
	float GetMaxHealth();
	bool IsDead();

	void TakeDamage(float damage);
	void Heal(float health);
	void UpdateMaxHealth(float newMaxHealth);
};


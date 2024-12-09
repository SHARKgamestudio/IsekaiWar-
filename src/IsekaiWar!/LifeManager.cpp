#include "LifeManager.h"

LifeManager::LifeManager(float health)
{
	isDead = false;
	maxHP = health;
	HP = health;
}

float LifeManager::GetHealth()
{
	return HP;
}

float LifeManager::GetMaxHealth()
{
	return maxHP;
}

bool LifeManager::IsDead()
{
	return isDead;
}

void LifeManager::TakeDamage(float damage)
{
	HP -= damage;

	if (HP < 0) 
	{
		HP = 0;
		isDead = true;
	}
}

void LifeManager::Heal(float health)
{
	HP += health;
	if (HP > maxHP)
	{
		HP = maxHP;
	}
}

void LifeManager::UpdateMaxHealth(float newMaxHealth)
{
	maxHP = newMaxHealth;
}
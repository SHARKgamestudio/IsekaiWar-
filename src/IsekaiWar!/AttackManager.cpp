#include "AttackManager.h"
#include "LivingEntity.h"

AttackManager::AttackManager(float damage)
{
	this->damage = damage;
}

void AttackManager::Attack(LivingEntity& entity)
{
	entity.TakeDamage(damage);
}
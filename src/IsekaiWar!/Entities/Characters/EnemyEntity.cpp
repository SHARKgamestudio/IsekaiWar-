#include "EnemyEntity.h"

#include "../VisualEffectEntity.h"
#include "../../Managers.h"
#include "../../Entities/PowerUps/FirePowerUp.h"
#include "../../Entities/PowerUps/WaterPowerUp.h"

EnemyEntity::EnemyEntity(float x, float y, sf::Texture* texture, float birth, int columns, int rows, float radius, float health)
	: CharacterEntity(x, y, texture, columns, rows, radius, health) {
	this->birth = birth;
}

EnemyEntity::EnemyEntity(sf::Vector2f position, sf::Texture* texture, float birth, sf::Vector2i split, float radius, float health)
	: CharacterEntity(position, texture, split, radius, health) {
	this->birth = birth;
}

void EnemyEntity::UpdateLogic(float deltaTime) {
	LivingEntity::UpdateLogic(deltaTime);

	if (toDestroy) {
		(new VisualEffectEntity(getPosition(), Managers::GetInstance()->ResourceManager->GetTexture("explosion"), sf::Vector2i(6, 1), 0.8f))->Spawn();

		int randint = rand() % 100;

		if (randint <= 5) {
			(new FirePowerUp(getPosition()))->Spawn();
		}
		else if (randint <= 10) {
			(new WaterPowerUp(getPosition()))->Spawn();
		}
	}
}
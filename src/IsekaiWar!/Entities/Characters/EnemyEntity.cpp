#include "EnemyEntity.h"

#include "../VisualEffectEntity.h"
#include "../../Managers.h"
#include "../../Entities/PowerUps/FireBook.h"
#include "../../Entities/PowerUps/WaterBook.h"
#include "../../Entities/PowerUps/DoubleParchment.h"
#include "../../Entities/PowerUps/TripleParchment.h"
#include "../../Entities/PowerUps/QuadrupleParchment.h"

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

		if (randint <= 10) {
			int randint = rand() % 100;

			if (randint <= 30) {
				(new FireBook(getPosition()))->Spawn();
			}
			else if (randint <= 60) {
				(new WaterBook(getPosition()))->Spawn();
			} 
			else if (randint <= 73) {
				(new DoubleParchment(getPosition()))->Spawn();
			}
			else if (randint <= 86) {
				(new TripleParchment(getPosition()))->Spawn();
			}
			else {
				(new QuadrupleParchment(getPosition()))->Spawn();
			}
		}
		Managers::GetInstance()->SceneManager->currentLevel->UpdateScore(200);
	}
}
#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"
#include "../Entities/CollidableEntity.h"
#include "../Entities/BackgroundEntity.h"
#include "../Entities/VisualEffectEntity.h"
#include "../Entities/BulletEntity.h"
#include "../Entities/Characters/PlayerEntity.h"
#include "../Entities/Characters/EnemyEntity.h"

#pragma endregion

class LevelScene : public Scene {
protected:
	PlayerEntity* player;
	std::vector<BackgroundEntity*> backgrounds; //mettre en const à terme
	std::vector<EnemyEntity*> ennemies; //mettre en const à terme
	std::vector<CollidableEntity*> entities; //mettre en const à terme
	std::vector<BulletEntity*> bullets; //mettre en const à terme

	std::vector<CollidableEntity*> entitiesToDestroy;
	std::vector<EnemyEntity*> ennemiesToDestroy;
	std::vector<BulletEntity*> bulletsToDestroy;

public:
	std::vector<CollidableEntity*>* GetEntities();
	PlayerEntity* GetPlayer();

	void virtual Load();

	void virtual Update(float dt);
	void virtual Draw(sf::RenderWindow& window) override;

	void virtual SpawnPlayerBullet(BulletEntity* bullet);
	void virtual SpawnEnnemyBullet(BulletEntity* bullet);
	void virtual DespawnBullet(BulletEntity* bullet);

	void virtual SpawnEnnemy(EnemyEntity* ennemy);
	void virtual DespawnEnnemy(EnemyEntity* ennemy);

	void virtual SpawnEntity(CollidableEntity* entity);
	void virtual DespawnEntity(CollidableEntity* entity);

	void virtual SpawnBackground(BackgroundEntity* background);
	void virtual DespawnBackground(BackgroundEntity* background);
};
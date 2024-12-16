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

#pragma endregion

class LevelScene : public Scene {
protected:

	PlayerEntity* player;
	std::vector<BackgroundEntity*> backgrounds; //mettre en const à terme
	std::vector<CollidableEntity*> entities; //mettre en const à terme
	std::vector<VisualEffectEntity*> visualEffects; //mettre en const à terme
	std::vector<BulletEntity*> bullets;

	std::vector<CollidableEntity*> entitiesToDestroy;
	std::vector<BulletEntity*> bulletsToDestroy;

public:

	std::vector<CollidableEntity*>* GetEntities();
	PlayerEntity* GetPlayer();
	void virtual Update(float dt);
	void virtual Draw(sf::RenderWindow& window) override;

	void virtual SpawnPlayerBullet(BulletEntity* bullet);
	void virtual SpawnEnnemyBullet(BulletEntity* bullet);
	void virtual DespawnBullet(BulletEntity* bullet);

	void virtual SpawnEntity(CollidableEntity* entity);
	void virtual DespawnEntity(CollidableEntity* entity);

	void virtual SpawnBackground(BackgroundEntity* background);
	void virtual DespawnBackground(BackgroundEntity* background);

};

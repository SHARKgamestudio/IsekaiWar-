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
#include "../Utils/Clock.h"
#include "../Entities/Characters/Player.h"

#pragma endregion

class LevelScene : public Scene {
protected:

	Clock clock;
	Player* player;
	std::vector<BackgroundEntity*> backgrounds; //mettre en const à terme
	std::vector<CollidableEntity*> entities; //mettre en const à terme
	std::vector<VisualEffectEntity*> visualEffects; //mettre en const à terme
	std::vector<BulletEntity*> bullets;

public:

	void Pause();
	void Resume();

	std::vector<CollidableEntity*>* GetEntities();
	void virtual Update(float dt);
	void virtual Draw(sf::RenderWindow& window) override;

	void virtual SpawnBullet(BulletEntity* bullet);
	void virtual DespawnBullet(BulletEntity* bullet);

	void virtual SpawnEntity(CollidableEntity* entity);
	void virtual DespawnEntity(CollidableEntity* entity);

};

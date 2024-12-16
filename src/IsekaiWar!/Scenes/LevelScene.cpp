#include "LevelScene.h"

#pragma region External Dependencies

#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"

#pragma endregion

void LevelScene::Update(float dt) {
	// PARCOURS D'UPDATES
	player->Update(dt);

	for (BackgroundEntity* background : backgrounds) {
		background->Update(dt);
	}

	for (CollidableEntity* entity : entities) {
		entity->Update(dt);

		if (entity->ToDestroy()) {
			entitiesToDestroy.push_back(entity);
		}
	}
	/*
	for (VisualEffectEntity* visualEffect : visualEffects) {
		visualEffect->Update(dt);
	}
	*/
	for (BulletEntity* bullet : bullets) {
		bullet->Update(dt);

		if (bullet->ToDestroy()) {
			bulletsToDestroy.push_back(bullet);
		}
	}


	// PARCOURS DE DESPAWN
	for (CollidableEntity* entity : entitiesToDestroy) {
		DespawnEntity(entity);
	}

	for (BulletEntity* bullet : bulletsToDestroy) {
		DespawnBullet(bullet);
	}
}

void LevelScene::Draw(sf::RenderWindow& window) {
	for (BackgroundEntity* background : backgrounds) {
		window.draw(*background);
	}

	for (CollidableEntity* entity : entities) {
		window.draw(*entity);
	}
	/*
	for (VisualEffectEntity* visualEffect : visualEffects) {
		window.draw(*visualEffect);
	}
	*/
	for (BulletEntity* bullet : bullets) {
		window.draw(*bullet);
	}
	window.draw(*player);
}

std::vector<CollidableEntity*>* LevelScene::GetEntities() {
	return &entities;
}

PlayerEntity* LevelScene::GetPlayer() {
	return player;
}

void LevelScene::SpawnPlayerBullet(BulletEntity* bullet) {
	for (CollidableEntity* entity : entities) {
		bullet->AddToCheck(entity);
	}

	bullets.push_back(bullet);
}

void LevelScene::SpawnEnnemyBullet(BulletEntity* bullet) {
	bullet->AddToCheck(player);

	bullets.push_back(bullet);
}

void LevelScene::DespawnBullet(BulletEntity* bullet) {
	auto it = std::find(bullets.begin(), bullets.end(), bullet);

	if (it != bullets.end()) {
		int index = std::distance(bullets.begin(), it);

		bullets.erase(it);
	}
}

void LevelScene::SpawnEntity(CollidableEntity* entity) {
	for (BulletEntity* bullet : bullets) {
		bullet->AddToCheck(entity);
	}

	entities.push_back(entity);
}

void LevelScene::DespawnEntity(CollidableEntity* entity) {
	auto it = std::find(entities.begin(), entities.end(), entity);

	if (it != entities.end()) {
		int index = std::distance(entities.begin(), it);

		entities.erase(it);
	}

	for (BulletEntity* bullet : bullets) {
		bullet->RemoveToCheck(entity);
	}
}

void LevelScene::SpawnBackground(BackgroundEntity* background) {
	backgrounds.push_back(background);
}

void LevelScene::DespawnBackground(BackgroundEntity* background) {
	auto it = std::find(backgrounds.begin(), backgrounds.end(), background);

	if (it != backgrounds.end()) {
		int index = std::distance(backgrounds.begin(), it);

		backgrounds.erase(it);
	}
}
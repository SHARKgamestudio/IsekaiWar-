#include "LevelScene.h"

#pragma region External Dependencies

#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../Utils/Clock.h"

#include <iostream>

#pragma endregion

void LevelScene::Update(float deltaTime) {
	player->Update(deltaTime);

	for (BackgroundEntity* background : backgrounds) {
		background->Update(deltaTime);
	}

	for (CollidableEntity* entity : entities) {
		entity->Update(deltaTime);

		if (entity->ToDestroy()) {
			entitiesToDestroy.push_back(entity);
		}
	}

	for (EnemyEntity* ennemy : ennemies) {
		ennemy->Update(deltaTime);

		if (ennemy->ToDestroy()) {
			ennemiesToDestroy.push_back(ennemy);
		}
	}

	for (BulletEntity* bullet : bullets) {
		bullet->Update(deltaTime);

		if (bullet->ToDestroy()) {
			bulletsToDestroy.push_back(bullet);
		}
	}

	// PARCOURS DE DESPAWN
	for (CollidableEntity* entity : entitiesToDestroy) {
		DespawnEntity(entity);
	}

	for (EnemyEntity* ennemy : ennemiesToDestroy) {
		DespawnEnnemy(ennemy);
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

	for (EnemyEntity* ennemy : ennemies) {
		window.draw(*ennemy);
	}

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

void LevelScene::Load() {

}

void LevelScene::SpawnPlayerBullet(BulletEntity* bullet) {
	for (EnemyEntity* ennemy : ennemies) {
		bullet->AddToCheck(ennemy);
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

void LevelScene::SpawnEnnemy(EnemyEntity* ennemy) {
	for (BulletEntity* bullet : bullets) {
		bullet->AddToCheck(ennemy);
	}

	ennemies.push_back(ennemy);
}

void LevelScene::DespawnEnnemy(EnemyEntity* ennemy) {
	auto it = std::find(ennemies.begin(), ennemies.end(), ennemy);

	if (it != ennemies.end()) {
		int index = std::distance(ennemies.begin(), it);

		ennemies.erase(it);
	}

	for (BulletEntity* bullet : bullets) {
		bullet->RemoveToCheck(ennemy);
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
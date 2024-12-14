#include "LevelScene.h"

#pragma region External Dependencies

#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"

#pragma endregion

void LevelScene::Update(float dt) {
	player->Update(dt);

	for (BackgroundEntity* background : backgrounds) {
		background->Update(dt);
	}

	for (CollidableEntity* entity : entities) {
		entity->Update(dt);
	}
	/*
	for (VisualEffectEntity* visualEffect : visualEffects) {
		visualEffect->Update(dt);
	}
	*/
	for (BulletEntity* bullet : bullets) {
		bullet->Update(dt);
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

void LevelScene::Pause() {
	clock.Pause();
}

void LevelScene::Resume() {
	clock.Resume();
}

std::vector<CollidableEntity*>* LevelScene::GetEntities() {
	return &entities;
}

void LevelScene::SpawnPlayerBullet(BulletEntity* bullet) {
	for (CollidableEntity* entity : entities) {
		bullet->hitbox->AddToCheck(entity);
	}

	bullets.push_back(bullet);
}

void LevelScene::SpawnEnnemyBullet(BulletEntity* bullet) {
	bullet->hitbox->AddToCheck(player);

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
		bullet->hitbox->AddToCheck(entity);
	}

	entities.push_back(entity);
}

void LevelScene::DespawnEntity(CollidableEntity* entity) {
	auto it = std::find(entities.begin(), entities.end(), entity);

	if (it != entities.end()) {
		int index = std::distance(entities.begin(), it);

		entities.erase(it);
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
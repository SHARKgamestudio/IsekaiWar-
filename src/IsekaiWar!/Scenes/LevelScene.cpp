#include "LevelScene.h"

#pragma region External Dependencies

#include "../Entities/Bullets/PlayerBullet/SpecialBullet.h"

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

void LevelScene::SpawnBullet(BulletEntity* bullet) {
	bullets.push_back(bullet);
}
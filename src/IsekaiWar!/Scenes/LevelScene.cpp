#include "LevelScene.h"

void LevelScene::Update(float dt) {
	//player.Update(dt);

	for (auto& background : backgrounds) {
		background.Update(dt);
	}

	for (auto& entity : entities) {
		entity.Update(dt);
	}

	for (auto& visualEffect : visualEffects) {
		visualEffect.Update(dt);
	}
}

void LevelScene::Draw(sf::RenderWindow& window) {
	for (BackgroundEntity& background : backgrounds) {
		window.draw(background);
	}

	for (CollidableEntity& entity : entities) {
		window.draw(entity);
	}

	for (VisualEffectEntity& visualEffect : visualEffects) {
		window.draw(visualEffect);
	}

	//window.draw(player);
}

void LevelScene::Pause() {
	clock.Pause();
}

void LevelScene::Resume() {
	clock.Resume();
}
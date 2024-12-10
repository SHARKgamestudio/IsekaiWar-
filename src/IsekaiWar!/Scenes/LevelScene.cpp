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

void LevelScene::Draw(sf::RenderTarget& target, sf::RenderStates states) {
	for (BackgroundEntity& background : backgrounds) {
		background.draw(target, states);
	}

	for (CollidableEntity& entity : entities) {
		entity.draw(target, states);
	}

	for (VisualEffectEntity& visualEffect : visualEffects) {
		visualEffect.draw(target, states);
	}

	//player.draw(target, states);
}

void LevelScene::Pause() {
	clock.Pause();
}

void LevelScene::Resume() {
	clock.Resume();
}
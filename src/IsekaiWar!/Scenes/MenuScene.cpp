#include "MenuScene.h"

#include "../UI/UIComponent.h"

void MenuScene::Load(){

}

void MenuScene::UpdateLogic(float dt) { 
	for (UIComponent* element : elements) {
		element->UpdateLogic(dt);
	}
}

void MenuScene::Draw(sf::RenderWindow& window) {
	for (UIComponent* element : elements) {
		element->UpdateCursor(window);
		window.draw(*element);
	}
}
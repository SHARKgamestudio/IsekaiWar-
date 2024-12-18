#include "MenuScene.h"

#include "../UI/UIComponent.h"

MenuScene::MenuScene() {
	cursor = nullptr;
}

void MenuScene::Load(){

}

void MenuScene::UpdateLogic(float dt) { 
	for (UIComponent* element : elements) {
		element->UpdateLogic(dt);
	}
}

void MenuScene::Draw(sf::RenderWindow& window) {
	for (UIComponent* element : elements) {
		element->UpdateCursor(window, cursor->getGlobalBounds());
		window.draw(*element);
	}
	
	window.draw(*cursor);
}
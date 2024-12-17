#include "MenuScene.h"

#include "../UI/UIComponent.h"

void MenuScene::Load(){

}

void MenuScene::Update(float dt) { 
	for (UIComponent* element : elements) {
		element->Update(dt);
	}
}

void MenuScene::Draw(sf::RenderWindow& window) {
	for (UIComponent* element : elements) {
		element->UpdateCursor(window);
		window.draw(*element);
	}
}
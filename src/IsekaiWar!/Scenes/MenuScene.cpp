#include "MenuScene.h"

#include "../UI/UIComponent.h"

void MenuScene::Load(){

}

void MenuScene::Update(float dt) { 

}

void MenuScene::Draw(sf::RenderWindow& window) {
	for (UIComponent* element : elements) {
		element->Update(window);
		window.draw(*element);
	}
}
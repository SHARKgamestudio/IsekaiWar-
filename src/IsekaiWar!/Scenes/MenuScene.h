#pragma once

#pragma region External Dependencies

#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"

#pragma endregion

class UIComponent;

class MenuScene : public Scene {
protected:
	std::vector<UIComponent*> elements;
public:
	void virtual Load();
	void virtual Update(float dt);
	void virtual Draw(sf::RenderWindow& window) override;
};
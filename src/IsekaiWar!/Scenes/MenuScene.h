#pragma once

#pragma region External Dependencies

#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"

#pragma endregion

class UIComponent;
class Sprite;

class MenuScene : public Scene {
protected:
	sf::Sprite* cursor;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
public:
	std::vector<UIComponent*> elements;
=======
>>>>>>> Stashed changes

	~MenuScene();
=======

public:
	std::vector<UIComponent*> elements;
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

	void virtual Load();
	void virtual UpdateLogic(float dt);
	void virtual Draw(sf::RenderWindow& window) override;
};
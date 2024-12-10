#pragma region Local Dependencies

#include "Managers/GameManager.h"
#include "Managers/InputManager.h"
#include "Managers/ResourceManager.h"

#pragma endregion

class Managers {
private:
	static Managers* Instance;
public:
	Managers();

	GameManager GameManager;
	InputManager InputManager;
	ResourceManager ResourceManager;

	static Managers* GetInstance();
};
#pragma region Local Dependencies

#include "Managers/GameManager.h"
#include "Managers/ResourceManager.h"

#pragma endregion

class Managers {
private:
	static Managers* Instance;
public:
	Managers();

	GameManager GameManager;
	ResourceManager ResourceManager;

	static Managers* GetInstance();
};
#pragma region Local Dependencies

#include "GameManager.h"
#include "ResourceManager.h"

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
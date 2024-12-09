#include "Managers.h"

Managers* Managers::Instance = nullptr;

Managers::Managers() : GameManager(), ResourceManager() {
	// DO STUFF AFTER OBJECT CREATION //
}

Managers* Managers::GetInstance() {
	if (Instance == nullptr) {
		Instance = new Managers();
	}

    return Instance;
}
#include "Managers.h"

Managers* Managers::Instance = nullptr;

Managers::Managers() {
	// DO STUFF AFTER OBJECT CREATION //
	if (Instance == nullptr) {
		Instance = this;
	}
	this->GameManager = new ::GameManager();
	this->InputManager = new ::InputManager();
	this->ResourceManager = new ::ResourceManager();
	this->SceneManager = new ::SceneManager();
}

Managers* Managers::GetInstance() {
	if (Instance == nullptr) {
		Instance = new Managers();
	}

    return Instance;
}
#include "Managers.h"

int main() {
	srand(time(NULL));
	Managers::GetInstance()->GameManager->Run();
	delete Managers::GetInstance();
	return 0;
}
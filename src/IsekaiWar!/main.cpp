#include "Managers.h"

int main() {
	srand(time(NULL));
	Managers::GetInstance()->GameManager->Run();
	return 0;
}
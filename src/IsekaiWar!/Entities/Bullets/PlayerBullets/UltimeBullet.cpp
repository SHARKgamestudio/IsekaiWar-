#include "UltimeBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

UltimeBullet::UltimeBullet(float x, float y, int columns, int rows) 
	: Entity(x, y, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), columns, rows),
	AttackModule(120.f) {

}

UltimeBullet::UltimeBullet(sf::Vector2f position, sf::Vector2i split) {
}

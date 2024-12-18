#include "StandardBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("laserBullet")
#define COLUMNS 1
#define ROWS 1
#define RADIUS 5.f
#define ATTACK 5.f
#define SPEED 700.f
#define SPEED_ANIMATION 2.f

StandardBullet::StandardBullet(float x, float y)
	: EnemyBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED)
{
	spritesheet.setScale(0.5f, 0.5f);
	spritesheet.setOrigin(64 / 2, 64 / 2);
	spritesheet.setRotation(90);
}

StandardBullet::StandardBullet(sf::Vector2f position)
	: EnemyBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED)
{
	spritesheet.setScale(0.5f, 0.5f);
	spritesheet.setOrigin(64 / 2, 64 / 2);
	spritesheet.setRotation(90);

}

void StandardBullet::UpdateLogic(float deltaTime) {
	EnemyBullet::UpdateLogic(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {
		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit);

		if (!castEntity) {
			continue;
		}

		if (toDisable || toDestroy) {
			return;
		}

		Attack(castEntity, deltaTime);
		toDisable = true;
		return;
	}
}
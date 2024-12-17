#include "SpecialBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("fireAuto")
#define COLUMNS 6
#define ROWS 1
#define RADIUS 10.f
#define ATTACK 2.f
#define SPEED 700.f
#define SPEED_ANIMATION 2.f

SpecialBullet::SpecialBullet(float x, float y)
	: PlayerBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS, SPEED_ANIMATION) })
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

SpecialBullet::SpecialBullet(sf::Vector2f position)
	: PlayerBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS, SPEED_ANIMATION) })
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

void SpecialBullet::Update(float deltaTime) {
	PlayerBullet::Update(deltaTime);

	animator.Update(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {
		if (LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit)) {
			Attack(castEntity, deltaTime);
		}
	}
}
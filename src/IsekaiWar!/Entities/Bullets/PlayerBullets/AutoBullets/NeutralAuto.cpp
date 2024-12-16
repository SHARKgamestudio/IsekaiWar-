#include "NeutralAuto.h"

#pragma region Local Dependencies

#include "../../../LivingEntity.h"
#include "../../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("neutralAuto")
#define COLUMNS 1
#define ROWS 2
#define RADIUS 25.f
#define ATTACK 2.f
#define SPEED 700.f
#define SPEED_ANIMATION 2.f

NeutralAuto::NeutralAuto(float x, float y)
	: AutoBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED, SPEED_ANIMATION) 
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setPosition(-90.f, 80.f);
	spritesheet.setRotation(90);
}

NeutralAuto::NeutralAuto(sf::Vector2f position)
	: AutoBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED, SPEED_ANIMATION)
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setPosition(-90.f, 80.f);
	spritesheet.setRotation(90);
}
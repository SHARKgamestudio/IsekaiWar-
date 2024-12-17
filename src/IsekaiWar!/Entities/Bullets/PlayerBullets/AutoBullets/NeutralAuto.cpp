#include "NeutralAuto.h"

#pragma region Local Dependencies

#include "../../../LivingEntity.h"
#include "../../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("neutralAuto")
#define COLUMNS 1
#define ROWS 2
#define RADIUS 20.f
#define ATTACK 0.7f
#define SPEED 500.f
#define SPEED_ANIMATION 2.f
#define SCALE 0.6f

NeutralAuto::NeutralAuto(float x, float y)
	: AutoBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED, SPEED_ANIMATION) 
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(90);
}

NeutralAuto::NeutralAuto(sf::Vector2f position)
	: AutoBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED, SPEED_ANIMATION)
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(90);
}
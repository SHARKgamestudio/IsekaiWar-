#include "WaterAuto.h"

#pragma region Local Dependencies

#include "../../../LivingEntity.h"
#include "../../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("waterAuto")
#define COLUMNS 6
#define ROWS 1
#define RADIUS 10.f
#define ATTACK 0.7f
#define SPEED 700.f
#define SPEED_ANIMATION 2.f

WaterAuto::WaterAuto(float x, float y)
	: AutoBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED, SPEED_ANIMATION) 
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setRotation(90);
}

WaterAuto::WaterAuto(sf::Vector2f position)
	: AutoBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED, SPEED_ANIMATION)
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setRotation(90);
}
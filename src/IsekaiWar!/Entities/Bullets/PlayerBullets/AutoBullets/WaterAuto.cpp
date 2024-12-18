#include "WaterAuto.h"

#pragma region Local Dependencies

#include "../../../LivingEntity.h"
#include "../../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("waterAuto")
#define COLUMNS 6
#define ROWS 1
#define RADIUS 20
#define ATTACK 0.7f
#define SPEED 500
#define SPEED_ANIMATION 2
#define SCALE 0.55f
#define POSITION_X 0
#define POSITION_Y 30


WaterAuto::WaterAuto(float x, float y)
	: AutoBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED, SPEED_ANIMATION) 
{
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(90);
}

WaterAuto::WaterAuto(sf::Vector2f position)
	: AutoBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED, SPEED_ANIMATION)
{
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(90);
}
#include "FireAuto.h"

#pragma region Local Dependencies

#include "../../../LivingEntity.h"
#include "../../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("fireAuto")
#define COLUMNS 6
#define ROWS 1
#define RADIUS 20
#define ATTACK 1.2f	
#define SPEED 500
#define SPEED_ANIMATION 2
#define SCALE 0.45f
#define POSITION_X 5
#define POSITION_Y 5

FireAuto::FireAuto(float x, float y)
	: AutoBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED, SPEED_ANIMATION) 
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setRotation(-90);
}

FireAuto::FireAuto(sf::Vector2f position)
	: AutoBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED, SPEED_ANIMATION)
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setRotation(-90);
}
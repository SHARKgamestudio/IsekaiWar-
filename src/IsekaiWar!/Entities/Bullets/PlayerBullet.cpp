#include "PlayerBullet.h"
#include "../LivingEntity.h"

PlayerBullet::PlayerBullet(float x, float y, sf::Texture* texture, float radius, float attack)
	: BulletEntity(x, y, texture, radius, attack) {
}

PlayerBullet::PlayerBullet(sf::Vector2f position, sf::Texture* texture, float radius, float attack)
	: BulletEntity(position, texture, radius, attack) {
}

void PlayerBullet::Update(float deltaTime, std::vector<Entity*> entities) {
	for (auto& entity : entities) {

		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entity);

		if (castEntity == nullptr) continue;
		if (!IsColliding(castEntity)) continue;

		Attack(castEntity);
		hasCollided = true;
	}
}
#include "PlayerBullet.h"
#include "../LivingEntity.h"

PlayerBullet::PlayerBullet(float x, float y, sf::Texture* texture, float radius, float attack)
	: BulletEntity(x, y, texture, radius, attack) {
};

PlayerBullet::PlayerBullet(sf::Vector2f pos, sf::Texture* texture, float radius, float attack)
	: BulletEntity(pos, texture, radius, attack) {
};

void PlayerBullet::Update(float dt, std::vector<Entity*> entities) {
	for (auto& entity : entities) {

		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entity);

		if (castEntity == nullptr) {
			continue;
		}

		if (!IsColliding(castEntity)) {
			continue;
		}

		Attack(reinterpret_cast<LivingEntity*>(castEntity));
		hasCollided = true;
	}
}
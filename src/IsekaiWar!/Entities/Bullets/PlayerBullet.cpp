#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float x, float y, sf::Texture* texture, float radius, float attack)
	: BulletEntity(x, y, texture, radius, attack) {
};

PlayerBullet::PlayerBullet(sf::Vector2f pos, sf::Texture* texture, float radius, float attack)
	: BulletEntity(pos, texture, radius, attack) {
};

void PlayerBullet::Update(float dt, std::vector<Entity*> entities) {
	for (auto& entity : entities) {
		if (typeid(entity) != typeid(LivingEntity*) && typeid(entity) != typeid(CollidableEntity*)) {
			continue;
		}

		if (!IsColliding(reinterpret_cast<CollidableEntity*>(entity))) {
			continue;
		}

		Attack(reinterpret_cast<LivingEntity*>(entity));
		toDestroy = true;
	}
}
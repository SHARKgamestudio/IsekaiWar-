#include "PlayerBullet.h"
#include "../LivingEntity.h"
#include "../../Managers.h"

PlayerBullet::PlayerBullet(float x, float y, float w, float h, sf::Texture* texture, float radius, float attack)
	: BulletEntity(x, y, w, h, texture, radius, attack) {
}

PlayerBullet::PlayerBullet(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float attack)
	: BulletEntity(position, scale, texture, radius, attack) {
}

void PlayerBullet::Update(float deltaTime) {
	entitiesHit.clear();

	std::vector<CollidableEntity*>* entities = Managers::GetInstance()->SceneManager.currentLevel->GetEntities();

	for (CollidableEntity* entity : *entities) {

		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entity);

		if (castEntity == nullptr) continue;
		if (!IsColliding(castEntity)) continue;

		entitiesHit.push_back(castEntity);
		hasCollided = true;
	}
}
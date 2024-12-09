
class LivingEntity;

class AttackManager
{
private:
	float damage;

public:

	AttackManager(float damage);

	void Attack(LivingEntity& entity);
};
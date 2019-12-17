#include "enemyentity.h"

using namespace godot;

void EnemyEntity::_register_methods() {
    register_method("_process", &EnemyEntity::_process);
	//register_property<EnemyEntity, Vector2>("target", &EnemyEntity::target, Vector2(0,0));
	//Entity::_register_methods();
	//register_property<EnemyEntity, float>("speed", &Entity::speed, 5.0);
	//register_property<EnemyEntity, int>("health", &Entity::maxHealth, 100);
	//register_property<EnemyEntity, Vector2>("direction", &EnemyEntity::direction, Vector2(0, 0));
	//register_property<EnemyEntity, Transform2D>("targetEntity", &EnemyEntity::entityTarget, Transform2D());

}

void EnemyEntity::Die() {
	Entity::Die();
	queue_free();
	GameManager::instance->IncreaseScore();
	//GameManager::instance->GameOver();
}


EnemyEntity::EnemyEntity() {
	
}

EnemyEntity::~EnemyEntity() {
    // add your cleanup here
}

void EnemyEntity::_init() {
    // initialize any variables here
	speed = 3.0;

}

void EnemyEntity::_process(float delta) {
	target = GameManager::pPlayer->get_position() - get_position();
	set_rotation(target.angle());

	Entity::SetDirection(target);
	Entity::_process(delta);

	if (get_rotation() > 3.12 / 2 || get_rotation() < -3.12 / 2) {
		set_scale(Vector2(1, -1));
	}
	else {
		set_scale(Vector2(1, 1));
	}


}

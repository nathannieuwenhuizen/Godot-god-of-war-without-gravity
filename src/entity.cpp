#include "entity.h"

using namespace godot;

void Entity::_register_methods() {
    register_method("_process", &Entity::_process);
	register_property<Entity, float>("speed", &Entity::speed, 5.0);
	register_property<Entity, int>("health", &Entity::maxHealth, 100);
}

Entity::Entity() {
	health = maxHealth;
	direction = Vector2(1, 0);

	Godot::print("base cpp start");
}

Entity::~Entity() {
    // add your cleanup here
}

void Entity::Spawn(Vector2 _pos) {
	set_position(_pos);
	health = maxHealth;
}

void Entity::Die() {

}

void Entity::TakeDamage(int value) {
	health -= value;
	if (health <= 0) {
		Die();
	}
}

void Entity::_init() {
	Godot::print("init");
    // initialize any variables here
}

void Entity::_process(float delta) {
	set_position(get_position() + direction * speed);
}

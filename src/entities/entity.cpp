#include "entity.h"

using namespace godot;

void Entity::_register_methods() {
    //register_method("_process", &Entity::_process);
	register_property<Entity, float>("speed", &Entity::speed, 5.0);
	register_property<Entity, int>("health", &Entity::maxHealth, 100);
}

Entity::Entity() {
	health = maxHealth;
	direction = Vector2(1, 0);


	Godot::print("base cpp start!!!");
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
void Entity::SetDirection(Vector2 val) {
	direction = val.normalized();
}

void Entity::_init() {
	Godot::print("init!!!");
    // initialize any variables here
}

void Entity::_process(float delta) {

	//bounce
	if (get_position().x > get_viewport_rect().size.x || get_position().x < 0) {
		direction.x *= -1;
	}
	if (get_position().y > get_viewport_rect().size.y || get_position().y < 0) {
		direction.y *= -1;
	}
	Ref<KinematicCollision2D> info = move_and_collide(direction * speed);
	if (info != NULL) {

		Godot::print("coll info: ");
		Godot::print(info.ptr()->get_collider()->get_class());
		//Godot::print(info.ptr()->get_script());
		//Godot::print(info.ptr()->get_collider_id);
		Godot::print(typeid(info.ptr()->get_script()).name());
		Godot::print(typeid(Entity*).name());
		//Godot::print(info.ptr()->get_collider()->get_script());
	}
	//translate(direction * speed);
}

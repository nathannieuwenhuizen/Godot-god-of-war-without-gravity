#include "playerentity.h"

using namespace godot;

void PlayerEntity::_register_methods() {
    register_method("_process", &PlayerEntity::_process);
	register_property<PlayerEntity, Vector2>("mouse pos", &PlayerEntity::mousePos, Vector2(0,0));
	//Entity::_register_methods();
	register_property<PlayerEntity, float>("speed", &Entity::speed, 5.0);
	register_property<PlayerEntity, int>("health", &Entity::maxHealth, 100);
	register_property<PlayerEntity, Vector2>("direction", &PlayerEntity::direction, Vector2(0, 0));

}

PlayerEntity::PlayerEntity() {
}

PlayerEntity::~PlayerEntity() {
    // add your cleanup here
}

void PlayerEntity::_init() {
    // initialize any variables here
    //time_passed = 0.0;
}

void PlayerEntity::_process(float delta) {
	Entity::_process(delta);
	mousePos = get_local_mouse_position();
	rotate(mousePos.angle());
}

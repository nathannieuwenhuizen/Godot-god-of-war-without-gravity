#include "playerentity.h"

using namespace godot;

void PlayerEntity::_register_methods() {
    register_method("_process", &PlayerEntity::_process);
}

PlayerEntity::PlayerEntity() {
}

PlayerEntity::~PlayerEntity() {
    // add your cleanup here
}

void PlayerEntity::_init() {
    // initialize any variables here
    time_passed = 0.0;
}

void PlayerEntity::_process(float delta) {
    //time_passed += delta;
	mousePos = get_local_mouse_position();
	//set_rotation(&mousePos.angle);
	rotate(mousePos.angle());
    //Vector2 new_position = Vector2(50.0 + (30.0 * sin(time_passed * 2.0)), 50.0 + (10.0 * cos(time_passed * 2.0)));
    //set_position(new_position);
}

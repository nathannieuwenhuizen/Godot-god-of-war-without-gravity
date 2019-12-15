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
    //time_passed = 0.0;
}

void PlayerEntity::_process(float delta) {
	mousePos = get_local_mouse_position();
	rotate(mousePos.angle());
}

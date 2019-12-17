#include "playerentity.h"

using namespace godot;
Sword* PlayerEntity::sword;
void PlayerEntity::_register_methods() {
	register_method("_process", &PlayerEntity::_process);
	register_method("_ready", &PlayerEntity::_ready);

	//register_property<PlayerEntity, Vector2>("mouse pos", &PlayerEntity::mousePos, Vector2(0,0));
	//Entity::_register_methods();
	//register_property<PlayerEntity, float>("speed", &Entity::speed, 5.0);
	//register_property<PlayerEntity, int>("health", &Entity::maxHealth, 100);
	//register_property<PlayerEntity, Vector2>("direction", &Entity::direction, Vector2(0, 0));

}

PlayerEntity::PlayerEntity() {
	srand(time(NULL));
}

PlayerEntity::~PlayerEntity() {
    // add your cleanup here
}
void PlayerEntity::Slash() {
	sword->Slash();
}
void PlayerEntity::Die() {
	//Entity::Die();
	GameManager::instance->GameOver();
}

void PlayerEntity::_ready() {
	GameManager::pPlayer = this;
}

void PlayerEntity::_init() {

	Entity::SetDirection(Vector2(1,0));
	speed = 5.0;

}

void PlayerEntity::_process(float delta) {
	Input* i = Input::get_singleton();
	if (i->is_action_just_pressed("leftClick")) {
		Slash();
	}
	

	Entity::_process(delta);
	
	mousePos = get_local_mouse_position();
	rotate(mousePos.angle());
	//Entity::SetDirection(Vector2(1, 0));
}

void PlayerEntity::RedirectSpeed() {
	Vector2 redirectedSpeed = (get_global_mouse_position() - get_position());
	SetDirection(redirectedSpeed * -1);
}


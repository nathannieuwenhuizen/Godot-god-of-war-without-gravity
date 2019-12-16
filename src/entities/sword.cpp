#include "sword.h"

using namespace godot;

void Sword::_register_methods() {
	register_method("_process", &Sword::_process);
	register_method("_ready", &Sword::_ready);
}

Sword::Sword() {
}

Sword::~Sword() {
}

void Sword::Slash() {
	if (slashing) { return; }

	slashing = true;
	clockWise = !clockWise;
	Godot::print(clockWise);
	set_scale(Vector2(1,1));

	if (clockWise) {
		set_rotation_degrees(-angle / 2);
	}
	else {
		set_rotation_degrees(angle / 2);
	}
	set_position(Vector2(0, 0));
	show();
}

void Sword::_ready() {
	GameManager::pPlayer->sword = this;
	RetrieveSword();
}

void Sword::_init() {
}

void Sword::RetrieveSword() {
	set_scale(Vector2(0.01, 0.01));
	hide();
	if (!hitted) {
		GameManager::instance->CancelCombo();
	}
	hitted = false;
	slashing = false;
}
void Sword::_process(float delta) {
	if (slashing) {
		//swinging sword
		rotate(speed * (clockWise ? 1 : -1));
		if (clockWise) {
			if (get_rotation_degrees() > (angle / 2)) {
				RetrieveSword();
			}
		}
		else {
			if (get_rotation_degrees() < -(angle / 2)) {
				RetrieveSword();
			}
		}

		//check if it hit some enemy
		Ref<KinematicCollision2D> info  = move_and_collide(Vector2(0, 0));
		if (info != NULL && !hitted) {
			hitted = true;
			GameManager::pPlayer->RedirectSpeed();
		}
	}
}

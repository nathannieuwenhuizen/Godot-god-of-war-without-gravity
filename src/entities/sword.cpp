#include "sword.h"

using namespace godot;

void Sword::_register_methods() {
	register_method("_process", &Sword::_process);
	register_method("_ready", &Sword::_ready);

	register_property<Sword, float>("angle", &Sword::angle, 180);
	register_property<Sword, float>("speed", &Sword::speed, .1);

}

Sword::Sword() {
}

Sword::~Sword() {
}

void Sword::Slash() {
	if (slashing) { return; }

	slashing = true;
	set_rotation_degrees(-angle / 2);
	show();
	Godot::print("SLASH!");
}

void Sword::_ready() {
	GameManager::pPlayer->sword = this;
}

void Sword::_init() {
	hide();
}

void Sword::_process(float delta) {
	if (slashing) {
		rotate(speed);
		if (get_rotation_degrees() > (angle / 2)) {
			slashing = false;
			hide();
		}
	}
}

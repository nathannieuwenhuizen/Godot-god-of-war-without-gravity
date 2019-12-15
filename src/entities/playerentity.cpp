#include "playerentity.h"

using namespace godot;
Sword* PlayerEntity::sword;
void PlayerEntity::_register_methods() {
	register_method("_process", &PlayerEntity::_process);
	register_method("_ready", &PlayerEntity::_ready);

	register_property<PlayerEntity, Vector2>("mouse pos", &PlayerEntity::mousePos, Vector2(0,0));
	//Entity::_register_methods();
	register_property<PlayerEntity, float>("speed", &Entity::speed, 5.0);
	register_property<PlayerEntity, int>("health", &Entity::maxHealth, 100);
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
	Godot::print("hello");
}

void PlayerEntity::_ready() {
	/*const godot::String gsCamera2D = "Camera2D";
	Node* n;
	godot::Array a = get_children();
	int64_t childCount = get_child_count();
	for (int64_t x = 0; x < childCount; x++) {
		n = get_child(x);
		if (gsCamera2D == n->get_name()) {
			x = (Node2D*)n;
		}
	}*/
	GameManager::pPlayer = this;
}

void PlayerEntity::_init() {
    // initialize any variables here
	//Vector2 randomVector = Vector2(rand() * 2 - 1, rand() * 2 - 1);
	//Godot::print("random vector");
	//Godot::print(randomVector);
	/*randomVector.x = 1;
	randomVector.y = 1;*/
	Entity::SetDirection(Vector2(1,0));
}

void PlayerEntity::_process(float delta) {
	Input* i = Input::get_singleton();
	if (i->is_action_just_pressed("leftClick")) {
		Godot::print("lash");
		Slash();
	}

	/*if (is_coll)
	int length = 5;
	for (int i = 0; i < length; ++i) {
		godot::Ref<godot::KinematicCollision2D> collission = get_slide_collision(i);
		
		Godot::print("Collided with: " + get_slide_collision(i).collider.name);
	}*/

	Entity::_process(delta);
	mousePos = get_local_mouse_position();
	rotate(mousePos.angle());
}

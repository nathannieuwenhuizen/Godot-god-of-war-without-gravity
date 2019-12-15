#include "gamemanager.h"

using namespace godot;
PlayerEntity* GameManager::pPlayer;
void GameManager::_register_methods() {
    register_method((char*)"_input", &GameManager::HandleInputEvent);
}

GameManager::GameManager() {
}

GameManager::~GameManager() {
}

void GameManager::HandleInputEvent(InputEvent* e) {
	const godot::String gsIEMB = "InputEventMouseButton";
	godot::String gsClass = e->get_class();
	if (gsClass == gsIEMB) {

		//int64_t buttonIndex = (InputEventMouseButton)e->get_button_index();
		//if (e->is_pressed()) {
		//	if (buttonIndex == GlobalConstants::BUTTON_LEFT) {
		//		//pPlayer->Slash();
		//	}
		//}
	}
	const godot::String gsIEK = "InputEventKey";
	if (gsClass == gsIEK) {
		Godot::print("player");
		pPlayer->direction.x += 1;
		InputEventKey* k = (InputEventKey*)e;
		if (k->get_scancode() == GlobalConstants::KEY_ESCAPE) {
			get_tree()->quit();
		}
	}


}

void GameManager::_init() {
	Godot::print("start game!");
}

void GameManager::_process(float delta) {
}

#include "gamemanager.h"

using namespace godot;
PlayerEntity* GameManager::pPlayer;
GameManager* GameManager::instance;
//CanvasItem* resultScreen;
void GameManager::_register_methods() {
    register_method((char*)"_input", &GameManager::HandleInputEvent);
	register_method("_ready", &GameManager::_ready);

}

GameManager::GameManager() {
	GameManager::instance = this;
}

GameManager::~GameManager() {
}

void GameManager::HandleInputEvent(InputEvent* e) {
	godot::String gsClass = e->get_class();

	const godot::String gsIEK = "InputEventKey";
	if (gsClass == gsIEK) {
		Godot::print("player");
		pPlayer->direction.x += 1;
		InputEventKey* k = (InputEventKey*)e;
		if (k->get_scancode() == GlobalConstants::KEY_ESCAPE) {
			get_tree()->quit();
		}
		if (k->get_scancode() == GlobalConstants::KEY_R) {
			get_tree()->reload_current_scene();
		}
	}
}

void GameManager::_ready() {
	const godot::String scoreText = "ResultScoreText";
	const godot::String resultCanvas = "CanvasLayer";
	Node* n;
	godot::String gsName;
	godot::Array a = get_children();
	int64_t childCount = get_child_count();
	for (int64_t x = 0; x < childCount; x++) {
		n = get_child(x);
		gsName = n->get_name();
		Godot::print("name: " + gsName);

		if (gsName == resultCanvas) {
			resultScreen = (CanvasItem*)n;
		}
	}
}


void GameManager::GameOver() {
	TextureRect* t = (TextureRect*)resultScreen->get_child(0);
	t->set_visible(true);
	Godot::print("result!");
}

void GameManager::_init() {
	Godot::print("start game!");
}

void GameManager::_process(float delta) {
}

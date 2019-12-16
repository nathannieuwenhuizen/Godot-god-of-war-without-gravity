#include "resultscreen.h"

using namespace godot;

void ResultScreen::_register_methods() {
	register_method("_on_RestartButton_pressed", &ResultScreen::_on_RestartButton_pressed);
	register_method("_on_QuitButton_pressed", &ResultScreen::_on_QuitButton_pressed);
}

ResultScreen::ResultScreen() {
}

ResultScreen::~ResultScreen() {
}

void ResultScreen::_init() {
	//Godot::print("init!" );

	/*
	const godot::String scoreText = "ResultScoreText";
	Node* n;
	godot::String gsName;
	godot::Array a = get_children();
	int64_t childCount = get_child_count();
	Godot::print("childcount:");
	Godot::print(childCount);

	for (int64_t x = 0; x < childCount; x++) {
		n = get_child(x);
		gsName = n->get_name();
		Godot::print("name: " + gsName);

		if (gsName == scoreText) {
			scoreLabel = (Label*)n;
		}
	}
	if (scoreLabel != NULL) {
		scoreLabel->set_text("test");
	}
	*/
}


void ResultScreen::_on_RestartButton_pressed(Variant)
{
	SceneTree* t = get_tree();
	t->reload_current_scene();
}

void ResultScreen::_on_QuitButton_pressed(Variant)
{
	SceneTree* t = get_tree();
	t->quit();
}

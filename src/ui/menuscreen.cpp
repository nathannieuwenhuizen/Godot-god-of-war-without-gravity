#include "menuscreen.h"

using namespace godot;

void MenuScreen::_register_methods() {
	register_method("_on_StartButton_pressed", &MenuScreen::_on_StartButton_pressed);
	register_method("_on_RestartButton_pressed", &MenuScreen::_on_RestartButton_pressed);
	register_method("_on_QuitButton_pressed", &MenuScreen::_on_QuitButton_pressed);
}

MenuScreen::MenuScreen() {
	hs = new Highscore();
	hs->getHighScore();
}

MenuScreen::~MenuScreen() {
}

void MenuScreen::_init() {
	String highscoreVal = String(Vector2(0, (real_t)hs->getHighScore())).right(3);
	set_text("Highscore: " + highscoreVal);
}


void MenuScreen::_on_StartButton_pressed(Variant)
{
	SceneTree* t = get_tree();
	t->change_scene("res://main.tscn");
	//t->reload_current_scene();
}

void MenuScreen::_on_RestartButton_pressed(Variant)
{
	//SceneTree* t = get_tree();
	//t->change_scene("res://main.tscn");
	//t->reload_current_scene();
}

void MenuScreen::_on_QuitButton_pressed(Variant)
{
	SceneTree* t = get_tree();
	t->quit();
}

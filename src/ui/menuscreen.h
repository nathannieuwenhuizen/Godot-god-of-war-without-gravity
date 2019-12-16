#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <Godot.hpp>
#include <Tree.hpp>
#include <SceneTree.hpp>
#include <TextureRect.hpp>
#include <Label.hpp>
#include "../backend/highscore.h"

#include "../managers/gamemanager.h"

namespace godot {

class MenuScreen : public Label {
    GODOT_CLASS(MenuScreen, Label)

private:

public:
    static void _register_methods();
	
	MenuScreen();
    ~MenuScreen();

    void _init(); // our initializer called by Godot
	Highscore* hs;
	Label* scoreLabel;
	void _on_RestartButton_pressed(Variant body);
	void _on_StartButton_pressed(Variant body);
	void _on_QuitButton_pressed(Variant body);
};

}

#endif

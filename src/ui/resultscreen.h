#ifndef RESULTSCREEN_H
#define RESULTSCREEN_H

#include <Godot.hpp>
#include <Tree.hpp>
#include <SceneTree.hpp>
#include <TextureRect.hpp>
#include <Label.hpp>

#include "../managers/gamemanager.h"

namespace godot {

class ResultScreen : public TextureRect {
    GODOT_CLASS(ResultScreen, TextureRect)

private:

public:
    static void _register_methods();

	ResultScreen();
    ~ResultScreen();

    void _init(); // our initializer called by Godot

	Label* scoreLabel;
	void _on_RestartButton_pressed(Variant body);
	void _on_QuitButton_pressed(Variant body);
	void _on_StartButton_pressed(Variant body);
};

}

#endif

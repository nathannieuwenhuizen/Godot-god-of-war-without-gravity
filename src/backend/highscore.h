#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>

namespace godot {

class Highscore: public Node2D {
    GODOT_CLASS(Highscore, Node2D)

private:

public:
    static void _register_methods();

	Highscore();
    ~Highscore();

    void _init(); // our initializer called by Godot

	int highScore = 0;
    void _process(float delta);
	int getHighScore();
	void setHighScore(int _val);
};

}

#endif

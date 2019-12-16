#pragma once

#ifndef Sword_H
#define Sword_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <CollisionPolygon2D.hpp>

#include "../managers/gamemanager.h"

namespace godot {

class Sword : public KinematicBody2D {
    GODOT_CLASS(Sword, KinematicBody2D)
    
    private:
		float angle = 90;
		bool slashing = false;
		float speed = 0.2;
		bool hitted = false;
		bool clockWise = false;
    public:
        static void _register_methods();

		Sword();
        ~Sword();
		void Slash();
		void RetrieveSword(); 

        void _init(); // our initializer called by Godot
		void _process(float delta);
		void _ready();
};

}

#endif

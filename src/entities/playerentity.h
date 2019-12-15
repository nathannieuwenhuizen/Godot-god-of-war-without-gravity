#pragma once

#ifndef Player_H
#define Player_H

#include "entity.h"
#include "sword.h"
#include "../managers/gamemanager.h"

#include <Godot.hpp>
#include <Input.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


namespace godot {

class Sword;
class PlayerEntity : public Entity {
    GODOT_CLASS(PlayerEntity, Entity)
    
    private:
		//float time_passed;
		Vector2 mousePos;

    public:
		static Sword* sword;
        static void _register_methods();

        PlayerEntity();
        ~PlayerEntity();
		void Slash();

        void _init(); // our initializer called by Godot
		void _process(float delta);
		void _ready();

};

}

#endif

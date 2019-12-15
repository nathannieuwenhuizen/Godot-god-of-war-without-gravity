#ifndef Player_H
#define Player_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include "entity.h"
namespace godot {

class PlayerEntity : public Entity {
    GODOT_CLASS(PlayerEntity, Entity)
    
    private:
		//float time_passed;
		Vector2 mousePos;

    public:
        static void _register_methods();

        PlayerEntity();
        ~PlayerEntity();

        void _init(); // our initializer called by Godot

        void _process(float delta);
};

}

#endif

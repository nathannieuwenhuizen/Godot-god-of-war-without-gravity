#ifndef Player_H
#define Player_H

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot {

class PlayerEntity : public Sprite {
    GODOT_CLASS(PlayerEntity, Sprite)
    
    private:
		float time_passed;
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

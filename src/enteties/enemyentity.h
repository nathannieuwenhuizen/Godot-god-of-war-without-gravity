#ifndef Enemy_H
#define Enemy_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include "entity.h"
namespace godot {

class EnemyEntity : public Entity {
    GODOT_CLASS(EnemyEntity, Entity)
    
    private:
		//float time_passed;
		Vector2 target;

    public:
        static void _register_methods();

        EnemyEntity();
        ~EnemyEntity();

        void _init(); // our initializer called by Godot

        void _process(float delta);
};

}

#endif

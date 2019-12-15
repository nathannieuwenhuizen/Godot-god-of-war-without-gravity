#ifndef Entity_H
#define Entity_H

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot {

class Entity : public Sprite {
    GODOT_CLASS(Entity, Sprite)
    
    private:
		int maxHealth;
    public:
		int health;
		float speed;
		Vector2 direction;

        static void _register_methods();

        Entity();
        ~Entity();

        void _init(); // our initializer called by Godot

		void Die();
		void Spawn(Vector2 _pos);
		void TakeDamage(int value);

        void _process(float delta);
};

}

#endif

#ifndef Entity_H
#define Entity_H

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot {

class Entity : public Sprite {
    GODOT_CLASS(Entity, Sprite)
    
    private:
    public:
		int maxHealth;
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
		void SetDirection(Vector2 val);

        void _process(float delta);
};

}

#endif

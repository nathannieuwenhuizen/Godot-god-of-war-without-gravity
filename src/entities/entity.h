#ifndef Entity_H
#define Entity_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>
#include <CollisionPolygon2D.hpp>
namespace godot {

class Entity : public KinematicBody2D {
    GODOT_CLASS(Entity, KinematicBody2D)
    
    private:
    public:
		int maxHealth = 100;
		int health = 100;
		float speed;
		Vector2 direction;
		bool alive = true;
		int deathIndex = 0;
		int delayDeathIndex = 2;
		
        static void _register_methods();

        Entity();
        ~Entity();
        void _init(); // our initializer called by Godot

		virtual void Die();
		void Spawn(Vector2 _pos);
		void TakeDamage(int value);
		void SetDirection(Vector2 val);

        virtual void _process(float delta);
};

}

#endif

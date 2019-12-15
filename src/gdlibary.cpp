#include "gdexample.h"
#include "entities/playerentity.h"
#include "entities/entity.h"
#include "entities/enemyentity.h"
#include "entities/sword.h"
#include "managers/gamemanager.h"
extern "C" 
{
    void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
        godot::Godot::gdnative_init(o);
    }

    void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
        godot::Godot::gdnative_terminate(o);
    }

    void GDN_EXPORT godot_nativescript_init(void *handle) {
        godot::Godot::nativescript_init(handle);

		godot::register_class<godot::GameManager>();

		godot::register_class<godot::Entity>();
		godot::register_class<godot::PlayerEntity>();
		godot::register_class<godot::EnemyEntity>();

		godot::register_class<godot::Sword>();

		godot::register_class<godot::GDExample>();
    }
}

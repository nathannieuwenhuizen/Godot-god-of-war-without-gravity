#pragma once

#ifndef EnemySpawner_H
#define EnemySpawner_H

#include "../entities/enemyentity.h"

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Resource.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <core/Ref.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace godot {
class EnemySpawner : public Node2D {

    GODOT_CLASS(EnemySpawner, Node2D)
    
	private:
		int intervalIndex = 0;
    public:
		int maxAmount = 10;
		float maxInterval = 60;
		godot::Ref<PackedScene> enemyScene;

        static void _register_methods();

		EnemySpawner();
        ~EnemySpawner();

		void _init();
		void _ready();
        void _process(float delta);

		void Spawn();
};

}

#endif

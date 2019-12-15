#pragma once

#ifndef GameManager_H
#define GameManger_H

#include "../entities/playerentity.h"

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>
#include <InputEventKey.hpp>
#include <InputEventMouseButton.hpp>
#include <GlobalConstants.hpp>
#include <SceneTree.hpp>

namespace godot {

class PlayerEntity;
class GameManager : public Node2D {

    GODOT_CLASS(GameManager, Node2D) 
    
    public:
		static PlayerEntity* pPlayer;
        static void _register_methods();

		GameManager();
        ~GameManager();

        void _init(); // our initializer called by Godot

        void _process(float delta);

		void HandleInputEvent(InputEvent* e);

};

}

#endif

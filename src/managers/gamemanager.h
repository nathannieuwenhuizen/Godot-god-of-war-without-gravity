#pragma once

#ifndef GameManager_H
#define GameManger_H

#include "../entities/playerentity.h"
#include "enemyspawner.h"
#include "../backend/highscore.h"

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>
#include <InputEventKey.hpp>
#include <InputEventMouseButton.hpp>
#include <GlobalConstants.hpp>
#include <SceneTree.hpp>
#include <CanvasItem.hpp>
#include <TextureRect.hpp>
#include <Label.hpp>
#include <sstream>

namespace godot {

class PlayerEntity;
class EnemySpawner;
class GameManager : public Node2D {

    GODOT_CLASS(GameManager, Node2D) 
    
    public:
		//static GameManager& Instance();

		//game objects
		static PlayerEntity* pPlayer;
		static GameManager* instance;
		EnemySpawner* enemySpawner;

		//ui
		CanvasItem* resultScreen;
		Label* scoreLabel;
		Label* comboLabel;

		//backend
		Highscore* hs;

		int score = 0;
		int maxCombo = 128;
		int currentCombo = 1;
		int streakIndex = 0;
		int streakSize = 4;

		int amountOfEnemiesSlain = 0;
		void IncreaseScore();
		void CancelCombo();
		void SetScore(int val);
		void SetCombo(int val);

        static void _register_methods();

		GameManager();
		~GameManager();

        void _init();
		void _ready();
        void _process(float delta);

		void HandleInputEvent(InputEvent* e);
		void GameOver();
};

}

#endif

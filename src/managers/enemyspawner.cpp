#include "enemyspawner.h"

using namespace godot;
//CanvasItem* resultScreen;
void EnemySpawner::_register_methods() {
	register_method("_ready", &EnemySpawner::_ready);
	register_method("_process", &EnemySpawner::_process);

}

EnemySpawner::EnemySpawner() {

	ResourceLoader* rl = ResourceLoader::get_singleton();
	enemyScene = rl->load("res://nodes/Enemy.tscn");
}

EnemySpawner::~EnemySpawner() {
} 

void EnemySpawner::_ready() {
	GameManager::instance->enemySpawner = this;
}

void EnemySpawner::Spawn() {
	Node2D* n = (Node2D*)enemyScene->instance();
	n->set_name("enemy");


	real_t xPos = real_t( rand() % (int)get_viewport_rect().size.x);
	Vector2 spawnPos = Vector2(xPos, 0);

	if (GameManager::pPlayer->get_position().y < get_viewport_rect().size.y / 2) {
		spawnPos.y = get_viewport_rect().size.y;
	}
	/*if (GameManager::pPlayer->get_position().x < get_viewport_rect().size.x / 2) {
		spawnPos.x = get_viewport_rect().size.x;
	}*/
	n->set_position(spawnPos);

	add_child(n);
}

void EnemySpawner::_init() {
	srand(time(NULL));
	//Spawn();
}

void EnemySpawner::_process(float delta) {
	intervalIndex++;
	if (intervalIndex > maxInterval) {
		intervalIndex = 0;
		if (get_child_count() < maxAmount) {
			Spawn();
		}
	}
}

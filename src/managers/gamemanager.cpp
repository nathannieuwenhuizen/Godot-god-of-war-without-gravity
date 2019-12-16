#include "gamemanager.h"

using namespace godot;
PlayerEntity* GameManager::pPlayer;
GameManager* GameManager::instance;
void GameManager::_register_methods() {
    register_method((char*)"_input", &GameManager::HandleInputEvent);
	register_method("_ready", &GameManager::_ready);

}

GameManager::GameManager() {
	GameManager::instance = this;
	hs = new Highscore();
}

GameManager::~GameManager() {
}

void GameManager::HandleInputEvent(InputEvent* e) {
	godot::String gsClass = e->get_class();

	const godot::String gsIEK = "InputEventKey";
	if (gsClass == gsIEK) {
		Godot::print("player");
		pPlayer->direction.x += 1;
		InputEventKey* k = (InputEventKey*)e;
		if (k->get_scancode() == GlobalConstants::KEY_ESCAPE) {
			get_tree()->quit();
		}
		if (k->get_scancode() == GlobalConstants::KEY_R) {
			get_tree()->reload_current_scene();
		}
	}
}

void GameManager::_ready() {
	const godot::String scoreText = "ScoreLabel";
	const godot::String comboText = "ComboLabel";
	const godot::String resultCanvas = "CanvasLayer";
	Node* n;
	godot::String gsName;
	godot::Array a = get_children();
	int64_t childCount = get_child_count();
	for (int64_t x = 0; x < childCount; x++) {
		n = get_child(x);
		gsName = n->get_name();
		Godot::print("name: " + gsName);

		if (gsName == resultCanvas) {
			resultScreen = (CanvasItem*)n;
		}
		else if (gsName == scoreText) {
			scoreLabel = (Label*)n;
		}
		else if (gsName == comboText) {
			comboLabel = (Label*)n;
		}

	}
	enemySpawner->maxAmount = 2;
	//scoreLabel->set_text("test");
	//comboLabel->set_text("test");
	SetScore(0);
	SetCombo(1);
}



void GameManager::GameOver() {
	TextureRect* t = (TextureRect*)resultScreen->get_child(0);
	Label* l = (Label*)t->get_child(1);
	t->set_visible(true);
	String optionalText = "";
	if (score > hs->getHighScore()) {
		optionalText = " \n NEW HIGHSCORE!";
		hs->setHighScore(score);
	}
	l->set_text( "Your score is: " + String(Vector2(0, (real_t)score)).right(3) + optionalText);

	Godot::print("result!");
}

void GameManager::_init() {
	Godot::print("start game!");
}

void GameManager::_process(float delta) {
}


//score
void GameManager::IncreaseScore()
{
	amountOfEnemiesSlain++;

	SetScore(score + currentCombo);
	streakIndex++;
	if (streakIndex >= streakSize) {
		streakIndex = 0;
		if (currentCombo < maxCombo) {
			SetCombo(currentCombo * 2);
		}
	}

	switch (amountOfEnemiesSlain)
	{

	case 5:
		enemySpawner->maxAmount = 3;
		enemySpawner->maxInterval = 60;
		break;
	case 10:
		enemySpawner->maxAmount = 5;
		enemySpawner->maxInterval = 50;
		break;
	case 20:
		enemySpawner->maxAmount = 10;
		enemySpawner->maxInterval = 40;
		break;
	case 40:
		enemySpawner->maxAmount = 20;
		enemySpawner->maxInterval = 30;
		break;
	default:
		break;
	}
}

void GameManager::CancelCombo()
{
	SetCombo(1);
}

void GameManager::SetScore(int val)
{
	score = val;
	Godot::print(String(Vector2(0, (real_t)val)).right(3));

	scoreLabel->set_text( String(Vector2(0, (real_t)val)).right(3));
}
void GameManager::SetCombo(int val)
{
	currentCombo = val;
	comboLabel->set_text("X" + String(Vector2(0, (real_t)val)).right(3));
}

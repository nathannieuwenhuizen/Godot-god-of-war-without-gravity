#include "highscore.h"

using namespace godot;

void Highscore::_register_methods() {
    register_method("_process", &Highscore::_process);
}

Highscore::Highscore() {
}

Highscore::~Highscore() {
}

void Highscore::_init() {
}

void Highscore::setHighScore(int _val) {
	highScore = _val;
	std::ofstream mfile;
	mfile.open("data.txt");
	mfile << _val;
}

int Highscore::getHighScore() {
	//default value, go figure ;)
	std::string y = "0";

	std::ifstream myfile("data.txt");
	std::getline(myfile, y);
	std::stringstream ss(y);
	int strAsInt;
	ss >> strAsInt;

	return strAsInt;
}

void Highscore::_process(float delta) {
}

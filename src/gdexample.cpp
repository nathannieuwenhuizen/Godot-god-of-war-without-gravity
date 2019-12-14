#include "gdexample.h"

using namespace godot;

void GDExample::_register_methods() {
    register_method("_process", &GDExample::_process);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() {
    // initialize any variables here
    time_passed = 0.0;
}

void GDExample::_process(float delta) {
    time_passed += delta;

    Vector2 new_position = Vector2(50.0 + (300.0 * sin(time_passed * 2.0)), 50.0 + (10.0 * cos(time_passed * 2.0)));

    set_position(new_position);
}

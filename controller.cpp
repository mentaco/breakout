#include "controller.h"

void Controller::update(){
    paddle.movement();
}

void Controller::draw(){
    paddle.draw();
}


#include "controller.h"

Controller::Controller(){
    Paddle paddle;
}

void Controller::update(){
    paddle.movement();
}

void Controller::draw(){
    paddle.draw();
}


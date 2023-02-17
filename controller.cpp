#include <ncurses.h>
#include "controller.h"

void Controller::update(){
    paddle.movement();
}

void Controller::draw(){
    clear();
    paddle.draw();
    refresh();
}


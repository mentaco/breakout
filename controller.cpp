#include <ncurses.h>
#include "controller.h"

int Controller::update(){
    int ch = getch();
    if (ch == 'q') {
        return 1;
    } else {
        paddle.movement(ch);
        ball.movement();
        return 0;
    }
}

void Controller::draw(){
    clear();
    paddle.draw();
    ball.draw();
    refresh();
}


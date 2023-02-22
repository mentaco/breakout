#include <ncurses.h>
#include "controller.h"

int Controller::update() {
    int ch = getch();
    if (ch == 'q') {
        return 0;
    } else {
        paddle.movement(ch);
        ball.movement();
        return 1;
    }
}

void Controller::draw() {
    clear();
    paddle.draw();
    ball.draw();
    refresh();
}


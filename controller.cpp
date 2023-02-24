#include <ncurses.h>
#include <thread>
#include "constants.h"
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
    while (loop) {
        clear();
        paddle.draw();
        ball.draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        refresh();
    }
}


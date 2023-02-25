#include <ncurses.h>
#include <thread>
#include "controller.h"

int Controller::q_input(int* ch) {
    *ch = getch();
    if (*ch == 'q') return 1;
    return 0;
}

int Controller::update() {
    int ch = getch();
    // paddle.movement(ch);
    ball.movement();
    return 1;
}

void Controller::draw(int* loop) {
    while (*loop) {
        clear();
        paddle.draw();
        ball.draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        refresh();
    }
}


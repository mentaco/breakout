#include <ncurses.h>
#include <thread>
#include "controller.h"

int Controller::q_input(int* ch) {
    *ch = getch();
    if (*ch == 'q') return 1;
    return 0;
}

int Controller::update() {
    // int ch = getch();
    // paddle.update(ch);
    ball.movement();
    return 1;
}

void Controller::draw() {
        clear();
        paddle.draw();
        ball.draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        refresh();
}

void Controller::all_ctrl(int* loop) {
    while (*loop) {
        this->update();
        this->draw();
    }
}


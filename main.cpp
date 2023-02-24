#include <ncurses.h>
#include <thread>
#include "constants.h"
#include "controller.h"

int loop = 1;

int main(void) {
    int ch;
    MEVENT e;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    Controller controller;
    auto game_loop = std::thread([&controller] {controller.draw();});
    while (1) {
        if (controller.q_input(&ch)) break;
    }
    loop = 0;
    game_loop.join();
    endwin();
}


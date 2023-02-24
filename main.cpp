#include <ncurses.h>
#include <thread>
#include "constants.h"
#include "controller.h"

int loop = 1;

int main(void) {
    initscr();
    noecho();
    curs_set(0);
    Controller controller;
    auto game_loop = std::thread([&controller] {controller.draw();});
    while (controller.update())
    loop = 0;
    game_loop.join();
    endwin();
}


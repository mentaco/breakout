#include <ncurses.h>
#include <thread>
#include "controller.h"

int main(void) {
    int ch;
    int loop = 1;
    MEVENT e;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    Controller controller;
    auto game_loop = std::thread(
                                [&controller, &loop]
                                {controller.all_ctrl(&loop);}
                                );
    while (1) {
        ch = getch();
        if (controller.q_input(&ch)) break;
    }
    loop = 0;
    game_loop.join();
    endwin();
}


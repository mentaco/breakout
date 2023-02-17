#include <ncurses.h>
#include "controller.h"

int main(void){
    initscr();
    noecho();
    curs_set(0);
    Controller controller;

    while (1){
        if (controller.update()) break;
        controller.draw();
    }
    endwin();
}


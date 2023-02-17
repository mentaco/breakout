#include <ncurses.h>
#include "conroller.h"

int main(void){
    initscr();
    noecho();
    curs_set(0);
    Controller controller;

    while (1){
        int ch = getch();
        if (ch == 'q') break;

        controller.update();
        controller.draw();
    }
    endwin();
}


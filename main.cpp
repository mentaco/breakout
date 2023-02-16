#include <ncurses.h>
#include "paddle.h"

int main(void){
    int result;
    initscr();
    noecho();
    curs_set(0);
    Paddle paddle;
    while (1){
        int ch = getch();
        if (ch == 'q') break;
        result = paddle.sum_x(100);
    }
    endwin();
}


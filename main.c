#include <ncurses.h>

int main(void){
    initscr();
    noecho();
    curs_set(0);
    while (1){
        int ch = getch();
        if (ch == 'q') break;
    }
    endwin();
}


#include <ncurses.h>
#include "paddle.h"

Paddle::Paddle()
    : row(12), column(23)
{
    
}

void Paddle::movement(){
    int key = getch();
//    if (key == 'a') column -= 3;
//    else if (key == 'd') column += 3;
    if (key == 0xE0){
        if (key == 0x4B) column -= 3;
        else if (key == 0x4D) column += 3;
    }
}

void Paddle::draw(){
    mvprintw(row, column, "-----");
}


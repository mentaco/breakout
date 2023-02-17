#include <ncurses.h>
#include "paddle.h"

Paddle::Paddle()
    : row(28), column(27)
{
    
}

void Paddle::movement(int ch){
    if (ch == 'a') column -= 3;
    else if (ch == 'd') column += 3;
}

void Paddle::draw(){
    mvprintw(row, column, "-----");
}


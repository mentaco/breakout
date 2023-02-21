#include <ncurses.h>
#include "paddle.h"
#include "constants.h"

Paddle::Paddle()
    : row(ROW_SIZE), column(COLUMN_SIZE), v(3)
{
    
}

void Paddle::movement(int ch){
    if (ch == 'a') column -= v;
    else if (ch == 'd') column += v;
}

void Paddle::draw(){
    mvprintw(row, column, "-----");
}


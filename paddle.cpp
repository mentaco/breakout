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

    if (column < 0) column = 0;
    else if (ROW_SIZE < column + 5) column = ROW_SIZE - 5;
}

void Paddle::draw(){
    mvprintw(row, column, "-----");
}


#include <ncurses.h>
#include "paddle.h"
#include "constants.h"

Paddle::Paddle()
    : row(ROW_SIZE), column(COLUMN_SIZE / 2 - 3), v(3)
{
    
}

int Paddle::getx() {
    return column;
}

int Paddle::gety() {
    return row;
}

void Paddle::move(int mx) {
    column = mx;

    if (column < 0) column = 0;
    else if (COLUMN_SIZE < column + 5) column = COLUMN_SIZE - 5;
}

void Paddle::draw() {
    mvprintw(row, column, "-----");
}


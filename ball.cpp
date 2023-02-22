#include <ncurses.h>
#include "ball.h"
#include "constants.h"

Ball::Ball()
    : x(COLUMN_SIZE / 3 * 2), y(ROW_SIZE / 2), vx(2), vy(2)
{
    
}

void Ball::movement(){
    if (x <= 0 || COLUMN_SIZE <= x) vx = -vx;
    x += vx;
    y += vy;
}

void Ball::draw(){
    if (y < ROW_SIZE){
        mvprintw(y, x, "@");
    }
}


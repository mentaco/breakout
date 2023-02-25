#include <ncurses.h>
#include "ball.h"
#include "constants.h"

Ball::Ball()
    : x(COLUMN_SIZE / 3 * 2), y(ROW_SIZE / 2), vx(0.02), vy(0.02)
{
    
}

void Ball::movement(){
    if (x <= 0 || COLUMN_SIZE <= x) vx = -vx;
    x += vx;
    y += vy;
}

void Ball::draw(){
    if (y < ROW_SIZE){
        mvprintw(static_cast<int>(y), static_cast<int>(x), "@");
    }
}


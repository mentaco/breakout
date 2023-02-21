#include <ncurses.h>
#include "ball.h"

Ball::Ball()
    : x(15), y(15), vx(2), vy(2)
{
    
}

void Ball::movement(){
    if (x <= 0 || 28 <= x) vx = -vx;
    x += vx;
    y += vy;
}

void Ball::draw(){
    if (y >= 27){
        mvprintw(y, x, "@");
    }
}


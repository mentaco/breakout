#include <ncurses.h>
#include "ball.h"

Ball::Ball()
    : x(15), y(15), vx(2), vy(2)
{
    
}

void Ball::movement(){
    x += vx;
    y += vy;
}

void Ball::draw(){
    mvprintw(y, x, "@");
}


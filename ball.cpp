#include <ncurses.h>
#include "ball.h"

Ball::Ball()
    : x(15), y(15), ax(2), ay(2)
{
    
}

void Ball::movement(){
    x += ax;
    y += ay;
}

void Ball::draw(){
    mvprintw(y, x, "@");
}


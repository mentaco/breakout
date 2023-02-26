#include <ncurses.h>
#include "ball.h"
#include "constants.h"

Ball::Ball()
    : x(10), y(10), vx(0.02), vy(0.02)
{
    
}

int Ball::getx() {
    return x;
}

int Ball::gety() {
    return y;
}

double Ball::getvx() {
    return vx;
}

double Ball::getvy() {
    return vy;
}

void Ball::movement(bool coll){
    if (x < 0 || COLUMN_SIZE <  x) vx = -vx;
    if (coll) vy = -vy;
    x += vx;
    y += vy;
}

void Ball::draw(){
    if (y < ROW_SIZE){
        mvprintw(static_cast<int>(y), static_cast<int>(x), "@");
    }
}


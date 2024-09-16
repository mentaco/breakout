#include "ball.h"

Ball::Ball(int x, int y) : x(x), y(y), dir_x(1), dir_y(1) {}

void Ball::move() {
  x += dir_x;
  y += dir_y;
}

void Ball::reverse_x() { dir_x = -dir_x; }

void Ball::reverse_y() { dir_y = -dir_y; }

int Ball::get_x() const { return x; }

int Ball::get_y() const { return y; }

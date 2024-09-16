#include "ball.h"

Ball::Ball(float x, float y) : x(x), y(y), dir_x(0.4), dir_y(0.4) {}

void Ball::move() {
  x += dir_x;
  y += dir_y;
}

void Ball::reverse_x() { dir_x = -dir_x; }

void Ball::reverse_y() { dir_y = -dir_y; }

int Ball::get_x() const { return static_cast<int>(x); }

int Ball::get_y() const { return static_cast<int>(y); }

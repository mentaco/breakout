#include "paddle.h"

Paddle::Paddle(int x, int y, int width) : x(x), y(y), width(width) {}

void Paddle::move_left() {
  if (x > 1)
    x--;
}

void Paddle::move_right(int border) {
  if (x + width < border)
    x++;
}

int Paddle::get_x() const { return x; }

int Paddle::get_y() const { return y; }

int Paddle::get_width() const { return width; }

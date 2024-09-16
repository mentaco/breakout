#include "block.h"

Block::Block(int x, int y, bool is_destroyed)
    : x(x), y(y), destroyed(is_destroyed) {}

bool Block::is_hit(int ball_x, int ball_y) {
  return ball_x == x && ball_y == y;
}

bool Block::is_destroyed() const { return destroyed; }

void Block::destroy() { destroyed = true; }

int Block::get_x() const { return x; }

int Block::get_y() const { return y; }

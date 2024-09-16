#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "block.h"
#include "paddle.h"
#include <vector>

class Game {
public:
  Game();
  ~Game();
  void run();

private:
  void draw();
  void update();
  void input();

  int width, height;
  bool is_running, game_clear;

  Ball ball;
  Paddle paddle;
  std::vector<Block> blocks;

  void init_blocks();
};

#endif

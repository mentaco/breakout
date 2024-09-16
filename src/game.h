#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "block.h"
#include "paddle.h"
#include <atomic>
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
  std::atomic<bool> is_running, clear_flag;

  Ball ball;
  Paddle paddle;
  std::vector<Block> blocks;

  void init_blocks();
  void show_message(bool clear_flag);
};

#endif

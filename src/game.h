#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "paddle.h"

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
  bool is_running;

  Ball ball;
  Paddle paddle;
};

#endif

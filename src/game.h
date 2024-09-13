#ifndef GAME_H
#define GAME_H

#include "paddle.h"
#include <ncurses.h>

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

  Paddle paddle;
};

#endif

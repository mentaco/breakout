#include "game.h"
#include <ncurses.h>
#include <unistd.h>

Game::Game() : width(40), height(20), paddle((width - 6) / 2, height - 2, 6) {
  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  timeout(100);

  is_running = true;
}

Game::~Game() { endwin(); }

void Game::run() {
  while (is_running) {
    input();
    update();
    draw();
    usleep(50000);
  }
}

void Game::input() {
  int ch = getch();
  switch (ch) {
    case KEY_LEFT:
      paddle.move_left();
      break;
    case KEY_RIGHT:
      paddle.move_right(width);
      break;
    case 'q':
      is_running = false;
      break;
  }
}

void Game::update() {
  // Unimplemented
}

void Game::draw() {
  clear();

  // Draw border
  for (int i = 0; i < width; i++) {
    mvprintw(0, i, "#");
    mvprintw(height, i, "#");
  }
  for (int i = 0; i < height; i++) {
    mvprintw(i, 0, "#");
    mvprintw(i, width, "#");
  }

  // Draw paddle
  for (int i = 0; i < paddle.get_width(); i++) {
    mvprintw(paddle.get_y(), paddle.get_x() + i, "=");
  }

  refresh();
}

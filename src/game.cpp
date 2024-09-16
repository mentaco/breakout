#include "game.h"
#include <ncurses.h>
#include <unistd.h>

Game::Game()
    : width(40), height(20),
      ball(static_cast<float>(width) / 2, static_cast<float>(height) / 3),
      paddle((width - 6) / 2, height - 2, 6) {
  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

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
  ball.move();

  // Border reflection
  if (ball.get_x() < 2 || ball.get_x() > width - 2)
    ball.reverse_x();
  if (ball.get_y() < 2)
    ball.reverse_y();

  // Paddle reflection
  if ((paddle.get_x() <= ball.get_x()) &&
      (ball.get_x() < paddle.get_x() + paddle.get_width()) &&
      (ball.get_y() == paddle.get_y())) {
    ball.reverse_y();
  }

  // Game over
  if (ball.get_y() >= height)
    is_running = false;
}

void Game::draw() {
  clear();

  // Draw border
  for (int i = 0; i < width + 1; i++) {
    mvprintw(0, i, "#");
    mvprintw(height, i, "#");
  }
  for (int i = 0; i < height; i++) {
    mvprintw(i, 0, "#");
    mvprintw(i, width, "#");
  }

  // Draw ball
  mvprintw(ball.get_y(), ball.get_x(), "O");

  // Draw paddle
  for (int i = 0; i < paddle.get_width(); i++) {
    mvprintw(paddle.get_y(), paddle.get_x() + i, "=");
  }

  refresh();
}

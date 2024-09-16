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
  game_clear = false;
  init_blocks();
}

Game::~Game() { endwin(); }

void Game::run() {
  while (is_running) {
    input();
    update();
    draw();
    usleep(50000);
  }

  clear();
  if (game_clear) {
    mvprintw(height / 2, width / 2 - 7, "CLEAR!");
  } else {
    mvprintw(height / 2, width / 2 - 7, "GAME OVER!");
  }
  refresh();
  usleep(600000);
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

  // Blocks collision
  for (auto &block : blocks) {
    if (!block.is_destroyed() && block.is_hit(ball.get_x(), ball.get_y())) {
      block.destroy();
      ball.reverse_y();
      break;
    }
  }

  // Game clear
  bool all_blocks_destroyed = true;
  for (const auto &block : blocks) {
    if (!block.is_destroyed()) {
      all_blocks_destroyed = false;
      break;
    }
  }
  if (all_blocks_destroyed) {
    is_running = false;
    game_clear = true;
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

  // Draw blocks
  for (const auto &block : blocks) {
    if (!block.is_destroyed()) {
      mvprintw(block.get_y(), block.get_x(), "?");
    }
  }

  // Draw ball
  mvprintw(ball.get_y(), ball.get_x(), "O");

  // Draw paddle
  for (int i = 0; i < paddle.get_width(); i++) {
    mvprintw(paddle.get_y(), paddle.get_x() + i, "=");
  }

  refresh();
}

void Game::init_blocks() {
  for (int y = 2; y < 3; y++) {
    for (int x = 4; x < width - 2; x += 5) {
      blocks.emplace_back(x, y);
    }
  }
}

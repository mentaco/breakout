#include "game.h"
#include <chrono>
#include <ncurses.h>
#include <thread>
#include <unistd.h>

Game::Game()
    : width(40), height(20), ball(width / 2, height / 6),
      paddle((width - 6) / 2, height - 2, 6) {
  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);

  is_running = true;
  clear_flag = false;
  init_blocks();
}

Game::~Game() { endwin(); }

void Game::run() {
  std::thread input_thread(&Game::input, this);

  auto last_time = std::chrono::steady_clock::now();
  auto frame_duration = std::chrono::milliseconds(83); // About 12FPS

  while (is_running) {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - last_time;
    if (elapsed > frame_duration) {
      update();
      draw();
      last_time = now;
    }
  }

  show_message(clear_flag);

  usleep(5000);

  input_thread.join();
}

void Game::input() {
  while (is_running) {
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

    // Sleep a little to reduce CPU load
    std::this_thread::sleep_for(std::chrono::milliseconds(15));
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
    clear_flag = true;
  }

  // Game over
  if (ball.get_y() >= height) {
    is_running = false;
    clear_flag = false;
  }
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
    for (int x = 5; x < width - 2; x += 8) {
      blocks.emplace_back(x, y);
    }
  }
}

void Game::show_message(bool game_clear) {
  clear();

  if (game_clear)
    mvprintw(height / 2, width / 2 - 7, "CLEAR!");
  else
    mvprintw(height / 2, width / 2 - 7, "GAME OVER");

  refresh();
  usleep(50000);
}

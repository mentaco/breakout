#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
  Paddle(int x, int y, int width);
  void move_left();
  void move_right(int border);
  int get_x() const;
  int get_y() const;
  int get_width() const;

private:
  int x, y, width;
};

#endif

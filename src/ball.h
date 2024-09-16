#ifndef BALL_H
#define BALL_H

class Ball {
public:
  Ball(int x, int y);
  void move();
  void reverse_x();
  void reverse_y();

  int get_x() const;
  int get_y() const;

private:
  int x, y;
  int dir_x, dir_y;
};

#endif

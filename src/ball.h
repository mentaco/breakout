#ifndef BALL_H
#define BALL_H

class Ball {
public:
  Ball(float x, float y);
  void move();
  void reverse_x();
  void reverse_y();

  int get_x() const;
  int get_y() const;

private:
  float x, y;
  float dir_x, dir_y;
};

#endif

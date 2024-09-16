#ifndef BLOCK_H
#define BLOCK_H

class Block {
public:
  Block(int x, int y, bool is_destroyed = false);
  bool is_hit(int ball_x, int ball_y);
  bool is_destroyed() const;
  void destroy();

  int get_x() const;
  int get_y() const;

private:
  int x, y;
  bool destroyed;
};

#endif

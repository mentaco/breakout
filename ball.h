#ifndef BALL_H
#define BALL_H

class Ball{
    private:
        int x;
        int y;
        int vx;
        int vy;
    public:
        Ball();
        void movement();
        void draw();
};
#endif


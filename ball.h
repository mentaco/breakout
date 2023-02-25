#ifndef BALL_H
#define BALL_H

class Ball{
    private:
        double x;
        double y;
        double vx;
        double vy;
    public:
        Ball();
        void movement();
        void draw();
};
#endif


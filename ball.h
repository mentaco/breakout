#ifndef BALL_H
#define BALL_H

class Ball{
    private:
        int x;
        int y;
        int ax;
        int ay;
    public:
        Ball();
        void movement();
        void draw();
};
#endif


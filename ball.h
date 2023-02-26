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
        int getx();
        int gety();
        double getvx();
        double getvy();
        void movement(bool coll = false);
        void draw();
};
#endif


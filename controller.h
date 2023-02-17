#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "paddle.h"
#include "ball.h"

class Controller{
    private:
        Paddle paddle;
        Ball ball;
    public:
        int update();
        void draw();
};

#endif


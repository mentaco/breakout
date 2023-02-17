#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"paddle.h"

class Controller{
    private:
        Paddle paddle;
    public:
        void update();
        void draw();
};

#endif


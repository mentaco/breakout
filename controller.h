#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"paddle.h"

class Controller{
    private:
        Paddle paddle;
    public:
        int update();
        void draw();
};

#endif


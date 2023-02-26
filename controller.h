#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "paddle.h"
#include "ball.h"

class Controller {
    private:
        Paddle paddle;
        Ball ball;
    public:
        int q_input(int* ch);
        int update();
        void draw();
        void all_ctrl(int* loop);
        void p_move(MEVENT e);
};

#endif


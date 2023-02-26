#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "paddle.h"
#include "block.h"
#include "ball.h"

class Controller {
    private:
        Paddle paddle;
        Block block;
        Ball ball;
        int paddlex, paddley;
        int blockx, blocky;
        int ballx, bally;
        double ballvx, ballvy;
    public:
        int update();
        void draw();
        bool pb_coll_check(
                int paddlex, int paddley,
                int ballx, int bally
            );
//        bool bb_coll_check(
//                int blockx, int blocky,
//                int ballx, int bally
//            );
        void all_ctrl(int* loop);
        void p_move(MEVENT e);
};

#endif


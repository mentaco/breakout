#include <ncurses.h>
#include <thread>
#include "controller.h"

int Controller::update() {
    paddlex = paddle.getx();
    paddley = paddle.gety();
    ballx = ball.getx();
    bally = ball.gety();
    ballvx = ball.getvx();
    ballvy = ball.getvy();

    ballx = static_cast<int>(ballx + ballvx);
    bally = static_cast<int>(bally + ballvy);

    ball.movement(pb_coll_check(paddlex, paddley,ballx, bally)
                //|| bb_coll_check(blockx, blocky, ballx, bally)
                );
    return 1;
}

void Controller::draw() {
    clear();
    paddle.draw();
    block.draw();
    ball.draw();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    refresh();
}

bool Controller::pb_coll_check(int paddlex, int paddley, int ballx, int bally)
{
    if (paddley == bally + ballvy) {
        if (paddlex <= ballx + ballvx && ballx + ballvx <= paddley + 4) {
            return true;
        }
    }
    return false;
}

//bool Controller::bb_coll_check(int blockx, int blocky, int ballx, int bally)
//{
//    if (blocky == bally + ballvy) {
//        if (blockx == ballx + ballvx) {
//            return true;
//        }
//    }
//    return false;
//}

void Controller::all_ctrl(int* loop) {
    while (*loop) {
        this->update();
        this->draw();
    }
}

void Controller::p_move(MEVENT e) {
    paddle.move(e.x - 2);
}


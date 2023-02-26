#include <ncurses.h>
#include <thread>
#include "controller.h"

//int Controller::q_input(int* ch) {
//    if (*ch == 'q') return 1;
//    return 0;
//}

int Controller::update() {
    paddlex = paddle.getx();
    paddley = paddle.gety();
    ballx = ball.getx();
    bally = ball.gety();
    ballvx = ball.getvx();
    ballvy = ball.getvy();

    ball.movement(pb_coll_check(
                    paddlex, paddley,
                    ballx, bally,
                    ballvx, ballvy
                    );
                || bb_coll_check(
                    blockx, blocky,
                    ballx, bally,
                    ballvx, ballvy);
                )
    return 1;
}

void Controller::draw() {
    clear();
    paddle.draw();
    ball.draw();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    refresh();
}

bool Controller::pb_coll_check(int paddlex, int paddley,
                                int ballx, int bally,
                                double ballvx, double ballvy)
{
    if (paddley == bally + vy) {
        if (paddlex <= ballx && ballx <= paddley + 4) {
            return true;
        }
    }
    return false;
}

bool Controller::bb_coll_check(int blockx, int blocky,
                                int ballx, int bally,
                                double ballvx, double ballvy)
{
    if (blocky == bally + vy) {
        if (blockx == ballx + vx) {
            return true;
        }
    }
    return false;
}
void Controller::all_ctrl(int* loop) {
    while (*loop) {
        this->update();
        this->draw();
        this->coll_check();
    }
}

void Controller::p_move(MEVENT e) {
    paddle.move(e.x);
}


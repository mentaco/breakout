#ifndef PADDLE_H
#define PADDLE_H

class Paddle{
    private:
        int row;
        int column;
    public:
        Paddle();
        void movement();
        void draw();
};

#endif


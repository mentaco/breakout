#ifndef PADDLE_H
#define PADDLE_H

class Paddle{
    private:
        int row;
        int column;
    public:
        Paddle();
        void movement(int ch);
        void draw();
};

#endif


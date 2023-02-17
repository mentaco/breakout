#ifndef PADDLE_H
#define PADDLE_H

class Paddle{
    private:
        static int row;
        static int column;
    public:
        Paddle();
        void movement();
};

#endif


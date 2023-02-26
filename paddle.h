#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
    private:
        int row;
        int column;
        int v;
    public:
        Paddle();
        int getx();
        int gety();
        void move(int mx);
        void draw();
};

#endif


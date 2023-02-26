#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
    private:
        int row;
        int column;
        int v;
    public:
        Paddle();
        void update(int ch);
        void draw();
        void move(int mx);
};

#endif


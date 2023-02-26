#ifndef BLOCK_H
#define BLOCK_H
#include "constants.h"

class Block {
    private:
        bool blocks[BLOCK_ROW][BLOCK_COLUMN];
        int row;
        int column;
    public:
        Block();
        void draw();
};

#endif


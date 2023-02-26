#include <ncurses.h>
#include "block.h"

Block::Block() {
    int i, j;
    for (i = 0; i < BLOCK_ROW; i++) {
        for (j = 0; j < BLOCK_COLUMN; j++) {
            blocks[i][j] = true;
        }
    }
}

void Block::draw() {
    int i, j;
    for (i = 0; i < BLOCK_ROW; i++) {
        for (j = 0; j < BLOCK_COLUMN; j++) {
            if (blocks[i][j]) {
                mvprintw(i + 1, j + 1, "#");
            }
        }
    }
}


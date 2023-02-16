#include <ncurses.h>
#include "paddle.h"

Paddle::Paddle(){
    row = 12;
    column = 23;
}
void Paddle::movement(){
    int key = getch();
    if (key == 0xE0){
        if (key == 0x4B) row -= 2;
        else if (key == 0x4D) row += 2;
    }
}

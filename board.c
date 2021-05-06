#define _CRT_SECURE_NO_WARNINGS 1
#include "SDL.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "board.h"
#include "main.c"

board* createBoard(int w, int h) {
    if (w <= 0 || h <= 0) {  //if widght or height is negative, return NULL
        return NULL;
    }

    board* b = (board*)malloc(sizeof(board));
    if (!b) {  //if b is not successfully created, return NULL
        return NULL;
    }

    b->box = (char*)calloc(w * h, sizeof(char));

    if (!(b->box)) {
        free(b);
        return NULL;
    }

    b->width = w;
    b->height = h;

    return b;
}

int checkNeighbors(board* b, int x, int y) {
    int m, n;
    int count = 0;

    if (x >= b->width || y >= b->height || x < 0 || y < 0) {
        return 0;
    }

    if (b == NULL) {
        return 0;
    }

    for (m = -1; m <= 1; m++) {
        for (n = -1; n <= 1; n++) {
            if (x + m >= 0 && x + m < b->width && y + n >= 0 && y + n < b->height && !(m == 0 && n == 0)) {
                if ((b->box)[(x + m) + (y + n) * b->width] == 1) {
                    count++;
                }
            }
        }
    }

    return count;
}

void generation(board* current, board* next) {
    int i, j;
    int count;
    memcpy(next->box, current->box, (current->width * current->height) * sizeof(char));

    for (i = 0; i < next->width; i++) {
        for (j = 0; j < next->height; j++)
        {
            count = checkNeighbors(next, i, j);
            if ((next->box)[i + j * next->width] == 1 && count < 2)
                (current->box)[i + j * next->width] = 0;
            else if ((next->box)[i + j * next->width] == 1 && count > 3)
                (current->box)[i + j * next->width] = 0;
            else if ((next->box)[i + j * next->width] == 1 && count <= 3)
                (current->box)[i + j * next->width] = 1;
            else if ((next->box)[i + j * next->width] == 0 && count == 3)
                (current->box)[i + j * next->width] = 1;
            // If cell is alive and neighbors equals 2 or 3 it stays alive
            // If cell is dead and neighbors is not equal to 3 it stays dead
        }
    }
}

void init() {
    int box_width  = WIDTH / CELLSIZE;
    int box_height = HEIGHT / CELLSIZE;

    //    //Blinker
    //    (current->box)[10+1*box_width] = 1;
    //    (current->box)[10+2*box_width] = 1;
    //    (current->box)[10+3*box_width] = 1;

    //    (current->box)[10+20*box_width] = 1;
    //    (current->box)[11+20*box_width] = 1;
    //    (current->box)[12+20*box_width] = 1;
                               
    //    //Toad              
    //    (current->box)[30+30*box_width] = 1;
    //    (current->box)[31+30*box_width] = 1;
    //    (current->box)[32+30*box_width] = 1;
    //    (current->box)[29+31*box_width] = 1;
    //    (current->box)[30+31*box_width] = 1;
    //    (current->box)[31+31*box_width] = 1;

    //    //Block
    //    (current->box)[1+1*box_width] = 1;
    //    (current->box)[1+2*box_width] = 1;
    //    (current->box)[2+1*box_width] = 1;
    //    (current->box)[2+2*box_width] = 1;

        //Glider
    //    (current->box)[30+20*box_width] = 1;
    //    (current->box)[31+20*box_width] = 1;
    //    (current->box)[32+20*box_width] = 1;
    //    (current->box)[30+21*box_width] = 1;
    //    (current->box)[31+22*box_width] = 1;

    //Gosper glider gun
    (current->box)[1 + 5 * box_width] = 1;
    (current->box)[2 + 5 * box_width] = 1;
    (current->box)[1 + 6 * box_width] = 1;
    (current->box)[2 + 6 * box_width] = 1;

    (current->box)[35 + 3 * box_width] = 1;
    (current->box)[36 + 3 * box_width] = 1;
    (current->box)[35 + 4 * box_width] = 1;
    (current->box)[36 + 4 * box_width] = 1;

    (current->box)[13 + 3 * box_width] = 1;
    (current->box)[14 + 3 * box_width] = 1;
    (current->box)[12 + 4 * box_width] = 1;
    (current->box)[16 + 4 * box_width] = 1;
    (current->box)[11 + 5 * box_width] = 1;
    (current->box)[17 + 5 * box_width] = 1;
    (current->box)[11 + 6 * box_width] = 1;
    (current->box)[15 + 6 * box_width] = 1;
    (current->box)[17 + 6 * box_width] = 1;
    (current->box)[18 + 6 * box_width] = 1;
    (current->box)[11 + 7 * box_width] = 1;
    (current->box)[17 + 7 * box_width] = 1;
    (current->box)[12 + 8 * box_width] = 1;
    (current->box)[16 + 8 * box_width] = 1;
    (current->box)[13 + 9 * box_width] = 1;
    (current->box)[14 + 9 * box_width] = 1;

    (current->box)[21 + 3 * box_width] = 1;
    (current->box)[22 + 3 * box_width] = 1;
    (current->box)[21 + 4 * box_width] = 1;
    (current->box)[22 + 4 * box_width] = 1;
    (current->box)[21 + 5 * box_width] = 1;
    (current->box)[22 + 5 * box_width] = 1;
    (current->box)[23 + 2 * box_width] = 1;
    (current->box)[23 + 6 * box_width] = 1;
    (current->box)[25 + 2 * box_width] = 1;
    (current->box)[25 + 6 * box_width] = 1;
    (current->box)[25 + 1 * box_width] = 1;
    (current->box)[25 + 7 * box_width] = 1;

    current = createBoard(box_width, box_height);
    next = createBoard(box_width, box_height);

}

void shutdown();
void display();
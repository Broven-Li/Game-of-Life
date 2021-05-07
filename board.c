#define _CRT_SECURE_NO_WARNINGS 1
#include "SDL.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "board.h"
#include "variable.h"

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

void Init() {

    
    int b_width = WIDTH / CELLSIZE;
    int b_height = HEIGHT / CELLSIZE;

    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("Game of Life",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN);

    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
    SDL_RenderClear(rend);
    SDL_RenderPresent(rend);
    
    current = createBoard(b_width, b_height);
    
    //    //Blinker
    //    (current->box)[10+1*b_width] = 1;
    //    (current->box)[10+2*b_width] = 1;
    //    (current->box)[10+3*b_width] = 1;
    
    //    (current->box)[10+20*b_width] = 1;
    //    (current->box)[11+20*b_width] = 1;
    //    (current->box)[12+20*b_width] = 1;
    
    //    //Toad
    //    (current->box)[30+30*b_width] = 1;
    //    (current->box)[31+30*b_width] = 1;
    //    (current->box)[32+30*b_width] = 1;
    //    (current->box)[29+31*b_width] = 1;
    //    (current->box)[30+31*b_width] = 1;
    //    (current->box)[31+31*b_width] = 1;
    
    //    //Block
    //    (current->box)[1+1*b_width] = 1;
    //    (current->box)[1+2*b_width] = 1;
    //    (current->box)[2+1*b_width] = 1;
    //    (current->box)[2+2*b_width] = 1;
    
        //Glider
    //    (current->box)[30+20*b_width] = 1;
    //    (current->box)[31+20*b_width] = 1;
    //    (current->box)[32+20*b_width] = 1;
    //    (current->box)[30+21*b_width] = 1;
    //    (current->box)[31+22*b_width] = 1;
    
    //Gosper glider gun
    (current->box)[1 + 5 * b_width] = 1;
    (current->box)[2 + 5 * b_width] = 1;
    (current->box)[1 + 6 * b_width] = 1;
    (current->box)[2 + 6 * b_width] = 1;
    
    (current->box)[35 + 3 * b_width] = 1;
    (current->box)[36 + 3 * b_width] = 1;
    (current->box)[35 + 4 * b_width] = 1;
    (current->box)[36 + 4 * b_width] = 1;
    
    (current->box)[13 + 3 * b_width] = 1;
    (current->box)[14 + 3 * b_width] = 1;
    (current->box)[12 + 4 * b_width] = 1;
    (current->box)[16 + 4 * b_width] = 1;
    (current->box)[11 + 5 * b_width] = 1;
    (current->box)[17 + 5 * b_width] = 1;
    (current->box)[11 + 6 * b_width] = 1;
    (current->box)[15 + 6 * b_width] = 1;
    (current->box)[17 + 6 * b_width] = 1;
    (current->box)[18 + 6 * b_width] = 1;
    (current->box)[11 + 7 * b_width] = 1;
    (current->box)[17 + 7 * b_width] = 1;
    (current->box)[12 + 8 * b_width] = 1;
    (current->box)[16 + 8 * b_width] = 1;
    (current->box)[13 + 9 * b_width] = 1;
    (current->box)[14 + 9 * b_width] = 1;
    
    (current->box)[21 + 3 * b_width] = 1;
    (current->box)[22 + 3 * b_width] = 1;
    (current->box)[21 + 4 * b_width] = 1;
    (current->box)[22 + 4 * b_width] = 1;
    (current->box)[21 + 5 * b_width] = 1;
    (current->box)[22 + 5 * b_width] = 1;
    (current->box)[23 + 2 * b_width] = 1;
    (current->box)[23 + 6 * b_width] = 1;
    (current->box)[25 + 2 * b_width] = 1;
    (current->box)[25 + 6 * b_width] = 1;
    (current->box)[25 + 1 * b_width] = 1;
    (current->box)[25 + 7 * b_width] = 1;
    
    next = createBoard(b_width, b_height);
}

void display() {
    int i, j;
    int Y, X;

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 1);
    SDL_RenderClear(rend);

    for (i = 0; i < current->width; i++) {
        for (j = 0; j < current->height; j++)
        {
            SDL_Rect rect = { i * CELLSIZE, j * CELLSIZE, CELLSIZE, CELLSIZE };

            if ((current->box)[i + j * current->width] == 1) {
                SDL_SetRenderDrawColor(rend, 0, 0, 0, 1);
            }
            else if ((current->box)[i + j * current->width] == 0) {
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 1);
            }
            SDL_RenderFillRect(rend, &rect);
        }
    }
    SDL_RenderPresent(rend);
}

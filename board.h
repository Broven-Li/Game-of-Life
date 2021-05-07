#pragma once
#ifndef BOARD_H
#define BOARD_H

#define WIDTH 800
#define HEIGHT 600
#define CELLSIZE 3
#define DTIME 1.0/10.0

typedef struct board {
    char* box;
    int width;
    int height;
} board;

board* current;
board* next;
int lastTime;
int newTime;
double deltaTime;

void shutdown();

void display();

board* createBoard(int w, int h);

int checkNeighbors(board* b, int x, int y);

void generation(board* current, board* next);

#endif

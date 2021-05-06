#pragma once
#ifndef BOARD_H
#define BOARD_H

typedef struct board {
    char* box;
    int width;
    int height;
} board;

void init();

void shutdown();

void display();

board* createBoard(int w, int h);

int checkNeighbors(board* b, int x, int y);

void generation(board* current, board* next);

#endif

#pragma once
#ifndef BOARD_H
#define BOARD_H

int WIDTH;
int HEIGHT;
int CELLSIZE;


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

void Init();

void save();

void loadInit();

void loadArray();

#endif

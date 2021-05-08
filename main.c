#define _CRT_SECURE_NO_WARNINGS 1
#include "SDL.h"
#include "stdio.h"
#include <stdbool.h>
#include "math.h"
#include "board.h"



int main(int argc, char* argv[]) {

	Init();

	SDL_Event event;
	bool quit = false;
	int start = 1;


	while (quit == false) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				save();
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					save();
					quit = true;
				}
				if (event.key.keysym.sym == SDLK_SPACE) {
					if (!start) {
						start = 1;
					}
					else {
						start = 0;
					}
				}
				if (event.key.keysym.sym == SDLK_l) {
					
					loadArray();
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				extern int b_width;
				b_width = WIDTH / CELLSIZE;
				SDL_GetMouseState(&x, &y);
				int gridX, gridY;
				gridX = x / CELLSIZE;
				gridY = y / CELLSIZE;

				if (event.button.button == SDL_BUTTON_LEFT) {
					(current->box)[gridX + gridY * b_width] = 1;
				}
				if (event.button.button == SDL_BUTTON_RIGHT) {
					(current->box)[gridX + gridY * b_width] = 0;

				}
			}
		}
		if (start) {
			generation(current, next);
			display();
		}
		SDL_Delay(50);
	}
	SDL_Quit();
	return 0;
}
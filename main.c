#define _CRT_SECURE_NO_WARNINGS 1
#include "SDL.h"
#include "stdio.h"
#include "stdbool.h"
#include "math.h"
#include "board.h"


#define WIDTH 800
#define HEIGHT 600
#define CELLSIZE 2

int main(int argc, char* argv[]) {

	Init();

	SDL_Event event;
	bool quit = false;
	int start = 1;

	while (quit == false) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
				else if (event.key.keysym.sym == SDLK_SPACE) {
					if (!start) {
						start = 1;
					}
					else {
						start = 0;
					}
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {

				}
				if (event.button.button == SDL_BUTTON_RIGHT) {


				}
			}

			if (start) {
				newTime = SDL_GetTicks();
				deltaTime = (double)(newTime - lastTime) / 1000;
				if (deltaTime >= DTIME) {
					generation(current, next);
					lastTime = newTime;
				}
				display();
			}
			SDL_Delay(5);
		}
	}
	SDL_Quit();
	return 0;
}
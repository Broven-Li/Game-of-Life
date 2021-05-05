#define _CRT_SECURE_NO_WARNINGS 1
#include "SDL.h"
#include "stdio.h"
#include "stdbool.h"
#include "math.h"

int main(int argc, char* argv[]) {
	
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Game of Life",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_SHOWN);

	SDL_Event event;
	bool quit = false;

	while (quit == false) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			//else if 
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
/*
Zaine Rehman
1-3-2024 through 1-3-2024

The previous program worked but had very messy code. 
I also want to implement SIMD and possibly multithreading. 
*/

#include <iostream>
#include <SDL.h>
#undef main

#ifdef __SSE2__
	#include <emmintrin.h>
#else
	#error SSE2 not supported; speed will be limited
#endif

#ifdef __AVX__
	#include <immintrin.h>
#else
	#warning AVX not supported; speed will be limited
#endif

#include "specifications.hpp"
	
namespace ball {
// window
	SDL_Window* WINDOW = NULL;
	// renderer
	SDL_Renderer* RENDERER;
};

int main() {
	srand(time(0));

	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	SDL_CreateWindowAndRenderer(ball::SCREENWIDTH, ball::SCREENHEIGHT, SDL_WINDOW_RESIZABLE, &ball::WINDOW, &ball::RENDERER);
	if (ball::WINDOW == NULL) {
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}
	SDL_SetRenderDrawColor(ball::RENDERER, 0, 0, 0, 0);
	SDL_RenderClear(ball::RENDERER);

	SDL_Event event;

	clock_t timeNew = clock();
	clock_t timeOld = clock();
	double deltaTime = 0;
	uint32_t mouseX = 0, mouseY = 0;

	while (!ball::QUIT) {
		timeNew = clock();
		deltaTime = timeNew - timeOld;

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			ball::QUIT = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				ball::QUIT = true;
				break;
			}
		}
	}
	
	return 0;
}
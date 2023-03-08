#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FPS 60
#define FRAME_DELAY 1000/60
#define W_TITLE "cube"
#define W_WIDTH 500
#define W_HEIGHT 500

void init(SDL_Window** window, SDL_Renderer** renderer);

int main(void)
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    init(&window, &renderer);

    bool running = true;
    SDL_Event e;

    unsigned int frameStart;
    int frameTime;
    int count = 0;

    while (running) {
	frameStart = SDL_GetTicks(); 

	while (SDL_PollEvent(&e)) {
	    if (e.type == SDL_QUIT)
		running = false;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
	SDL_RenderDrawLine(renderer, 100, 100, 200, 100);
	SDL_RenderDrawLine(renderer, 200, 100, 200, 200);
	SDL_RenderDrawLine(renderer, 200, 200, 100, 200);
	SDL_RenderDrawLine(renderer, 100, 200, 100, 100);

	frameTime = SDL_GetTicks() - frameStart; 
	if (FRAME_DELAY >= frameTime) 
	    SDL_Delay(FRAME_DELAY - frameTime);

	printf("%d\n", count);
	count++;
	SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}

void init(SDL_Window** window, SDL_Renderer** renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0) fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    if (!(IMG_Init(IMG_INIT_PNG))) fprintf(stderr, "Error initializing SDL image: %s\n", SDL_GetError());

    *window = SDL_CreateWindow(W_TITLE, 0, 0, W_WIDTH, W_HEIGHT, 0);
    if (!*window) fprintf(stderr, "Error creating window: %s\n", SDL_GetError());

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer) fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
}

void drawCube(int cube[])
{
    
}

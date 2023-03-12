#include "./window.h"

void create_window_renderer(SDL_Window** window, SDL_Renderer** renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
	fprintf(stderr, "Error sdl init: %s\n", SDL_GetError());

    if (!(IMG_Init(IMG_INIT_PNG)))
	fprintf(stderr, "Error sdl_img init: %s\n", SDL_GetError());

    *window = SDL_CreateWindow(W_TITLE, 0, 0, W_WIDTH, W_HEIGHT, 0);
    if (*window == NULL)
	fprintf(stderr, "Error creating window: %s\n", SDL_GetError());

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL)
	fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
}

void draw(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
}
void clear(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
    SDL_RenderClear(renderer);
}

void clean(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

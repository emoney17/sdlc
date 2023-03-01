#include <stdio.h>
#include <SDL2/SDL.h>

int main(void)
{
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	fprintf(stderr, "Init Error: %s\n", SDL_GetError());
	return -1;
    }

    SDL_Window *window = SDL_CreateWindow(
	"SDL2 Window", // Title
	SDL_WINDOWPOS_CENTERED, // X pos
	SDL_WINDOWPOS_CENTERED, // Y pos
	680, 400, 0); // Width, Height, Success
    if (!window) {
	fprintf(stderr, "Window Error: %s\n", SDL_GetError());
	return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    if (!window_surface) {
	fprintf(stderr, "Surface Error: %s\n", SDL_GetError());
	return -1;
    }

    SDL_UpdateWindowSurface(window);
    SDL_Delay(2500);

    return 0;
}

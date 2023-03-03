#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define TITLE "SDL2 Window"
#define WIDTH 680
#define HEIGHT 400

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	fprintf(stderr, "Init Error: %s\n", SDL_GetError());
	return -1;
    }

    SDL_Window *window = SDL_CreateWindow(
	TITLE,
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WIDTH,
	HEIGHT,
	0);
    if (!window) {
	fprintf(stderr, "Window Error: %s\n", SDL_GetError());
	return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    if (!window_surface) {
	fprintf(stderr, "Surface Error: %s\n", SDL_GetError());
	return -1;
    }

    SDL_Surface* image = SDL_LoadBMP("./Untitled.bmp");
    if (!image) {
	fprintf(stderr, "Image load Error: %s\n", SDL_GetError());
	return -1;
    }
    SDL_Rect image_position;
    image_position.x = 0;
    image_position.y = 0;
    image_position.w = 50;
    image_position.h = 50;

    double delta_time = 1.0/60.0; // Cap framerate to 60fps
    bool running = true; // App is running
    double image_x = 0;
    double image_y = 0;
    SDL_Event e;

    while (running) {
	while (SDL_PollEvent(&e) > 0) {
	    switch(e.type) {
	    case SDL_QUIT:
		running = false;
		break;
	    }
	}
	image_x = image_x + (5 * delta_time); // Move image every frame
	image_position.x = image_x;
	SDL_BlitSurface(image, NULL, window_surface, &image_position);
	SDL_UpdateWindowSurface(window);
    }
    // Clean
    SDL_FreeSurface(window_surface);
    SDL_DestroyWindow(window);
    return 0;
}

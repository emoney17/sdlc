#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define TITLE "SDL2 Window"
#define WIDTH 680
#define HEIGHT 400
#define delta_time 1.0/60.0 // Cap framerate to 60fps

enum Direction{ NONE, UP, DOWN, LEFT, RIGHT };
enum Direction direction;

void process_keys(SDL_Event event);
void process_directions(double* x, double* y);

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	    fprintf(stderr, "Init Error: %s\n", SDL_GetError());
	    return -1;
    }

    SDL_Window *window = SDL_CreateWindow(
	    TITLE,
	    0,
	    0,
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

    double x = 0.0;
    double y = 0.0;
    bool running = true; // App is running

    SDL_Event e;
    while (running) {
	    while (SDL_PollEvent(&e) > 0) {
            process_keys(e);
	        switch(e.type) {
	            case SDL_QUIT:
		        running = false;
		        break;
	        }
	    }
	    process_directions(&x, &y);
	    image_position.x = x;
	    image_position.y = y;
	    SDL_FillRect(window_surface, NULL,
		     SDL_MapRGB(window_surface->format, 0, 0, 0)); // Clean the screen before draw
	    SDL_BlitSurface(image, NULL, window_surface, &image_position);
	    SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(window_surface);
    SDL_DestroyWindow(window);
    return 0;
}

void process_keys(SDL_Event event)
{
    Uint8 const* keys;
    switch(event.type) {
        case SDL_KEYDOWN:
            keys = SDL_GetKeyboardState(NULL);
            if (keys[SDL_SCANCODE_W] == 1) {
                direction = UP;
                printf("UP\n");
            }
            else if (keys[SDL_SCANCODE_S] == 1) {
                direction = DOWN;
                printf("DOWN\n");
            }
            else if (keys[SDL_SCANCODE_A] == 1) {
                direction = LEFT;
                printf("LEFT\n");
            }
            else if (keys[SDL_SCANCODE_D] == 1) {
                printf("RIGHT\n");
                direction = RIGHT;
            }
            break;
    }
}

void process_directions(double* x, double* y)
{
    switch(direction) {
        case NONE:
	    *x += 0.0;
	    *y += 0.0;
	    break;
        case UP:
	    *y  = *y - (5.0 * delta_time);
            break;
        case DOWN:
            *y = *y + (5.0 * delta_time);
            break;
        case LEFT:
            *x = *x - (5.0 * delta_time);
            break;
        case RIGHT:
            *x = *x + (5.0 * delta_time);
            break;
    }
}

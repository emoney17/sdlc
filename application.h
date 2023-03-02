#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_Surface* window_surface;
    SDL_Event window_event;
} Application;

void create(const char* title, int height, int width);
void update();
void draw();
void clean();

#endif // APPLICATION_H_

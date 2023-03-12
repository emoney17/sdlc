#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define W_TITLE "window in c"
#define W_WIDTH 640
#define W_HEIGHT 400

void create_window_renderer(SDL_Window** window, SDL_Renderer** renderer);
void draw(SDL_Renderer* renderer);
void clear(SDL_Renderer* renderer);
void clean(SDL_Window* window, SDL_Renderer* renderer);

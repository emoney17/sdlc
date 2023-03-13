#ifndef _RENDER_H_
#define _RENDER_H_

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

bool init();
void clear_screen();
void create_entity(int x, int y, int w, int h, const char* path);
void draw_entity();
void draw_screen();
void clean_up();

#endif // _RENDER_H_

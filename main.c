#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "./render.h"

typedef struct
{
    int x;
    int y;
    int w;
    int h;
    const char* path;
}Entity;

int main(void)
{
    if (!init())
	return -1;

    SDL_Event e;
    bool running = true;

    // Create entities
    Entity e0 = {0, 0, 50, 50, "./demo/sankyuu.png"};
    create_entity(e0.x, e0.y, e0.w, e0.h, e0.path);

    while (running)
    {
	while(SDL_PollEvent(&e))
	{
	    switch(e.type)
	    {
	    case SDL_QUIT:
		running = false;
	    }
	    clear_screen();
	    // Draw entity
	    draw_entity();
	}
	draw_screen();
    }
    clean_up();
    printf("End of program\n");
    return 0;
}

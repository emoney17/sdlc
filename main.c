#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "./render.h"

int main(void)
{
    if (!init())
	return -1;

    SDL_Event e;
    bool running = true;

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
	    draw_entity();
	}
	draw_screen();
    }
    clean_up();
    printf("End of program\n");
    return 0;
}

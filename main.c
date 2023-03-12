#include <stdio.h>
#include <stdbool.h>

#include "./window.h"

int main(void)
{
    // Setup
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    create_window_renderer(&window, &renderer);
    bool running = true;
    SDL_Event e;

    // Window loop
    while (running)
    {
	clear(renderer); // Clear window to black
	while(SDL_PollEvent(&e))
	{
	    switch(e.type)
	    {
	    case SDL_QUIT:
		running = false;
	    }
	}
	draw(renderer); // Draw things from renderer
    }
    // Cleanup
    clean(window, renderer);
    return 0;
}

#include "./application.h"
Application app;
void create(const char* title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	fprintf(stderr, "Init Error: %s\n", SDL_GetError());
	return;
    }

    app.window = SDL_CreateWindow(
	title,
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	width, height, 0);
    if (!app.window) {
	fprintf(stderr, "Window Error: %s\n", SDL_GetError());
	return;
    }

    app.window_surface = SDL_GetWindowSurface(app.window);
    if (!app.window_surface) {
	fprintf(stderr, "Surface Error: %s\n", SDL_GetError());
	return;
    }
}

void update()
{
    bool running = true;
    while (running) {
	while(SDL_PollEvent(&app.window_event) > 0) {
	    switch(app.window_event.type) {
	    case SDL_QUIT:
		running = false;
		break;
	    }
	}
	draw();
    }
}

void draw()
{
    SDL_UpdateWindowSurface(app.window);
}

void clean() // Free resources
{
    SDL_FreeSurface(app.window_surface);
    SDL_DestroyWindow(app.window);
}

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
{
    int x;
    int y;
    int w;
    int h;
    const char* path;
}Entity;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

const int W_WIDTH =  680;
const int W_HEIGHT = 400;

bool init_sdl();
void clear_screen();
void create_entity(Entity entity);
void draw_renderer();
void clean_up();

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
    	fprintf(stderr, "Error with SDL init: %s\n", SDL_GetError());
    	return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
    	fprintf(stderr, "Error with SDL_img init: %s\n", SDL_GetError());
    	return -1;
    }

    window = SDL_CreateWindow(
    	"TITLE",
    	SDL_WINDOWPOS_CENTERED,
    	SDL_WINDOWPOS_CENTERED,
    	W_WIDTH,
    	W_HEIGHT,
    	SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
    	fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
    	return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
    	fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
    	return -1;
    }

    Entity miku = {100, 100, 50, 50, "./demo/sankyuu.png"};
    SDL_Texture* texture = IMG_LoadTexture(renderer, miku.path);
    SDL_Rect dest;
    dest.x = 100;
    dest.y = 100;
    dest.w = 50;
    dest.h = 50;
    
    SDL_Event e;
    bool running = true;
    double x = 0;
    double y = 0;

    while(running)
    {
	while(SDL_PollEvent(&e))
	{
	    if (e.type == SDL_QUIT)
		running = false;
	    if (e.type == SDL_KEYDOWN)
	    {
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
		    y -= 10;
		    break;
		case SDLK_a:
		    x -= 10;
		    break;
		case SDLK_s:
		    y += 10;
		    break;
		case SDLK_d:
		    x += 10;
		    break;
		}
	    }
	    // Clear screen
	    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 225);
	    SDL_RenderClear(renderer);

	    dest.x = x;
	    dest.y = y;
	    SDL_RenderCopy(renderer, texture, NULL, &dest);

	    // Draw with renderer
	    SDL_RenderPresent(renderer);
	}

    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

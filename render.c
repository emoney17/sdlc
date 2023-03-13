#include "./render.h"

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
int W_WIDTH = 640;
int W_HEIGHT = 400;

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
	fprintf(stderr, "Error with SDL init: %s\n", SDL_GetError());
	return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
	fprintf(stderr, "Error with SDL_img init: %s\n", SDL_GetError());
	return false;
    }

    window = SDL_CreateWindow("TITLE", 0, 0, W_WIDTH, W_HEIGHT, 0);
    if (window == NULL)
    {
	fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
	return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
	fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
	return false;
    }

    return true;
}

void clear_screen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
    SDL_RenderClear(renderer);
}

void draw_entity()
{
    Entity entity = {0, 0, 50, 50, "./demo/sankyuu.png"};
    texture = IMG_LoadTexture(renderer,entity.path);
    if (texture == NULL)
	fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());

    SDL_Rect dest = {entity.x, entity.y, entity.w, entity.h};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void draw_screen()
{
    SDL_RenderPresent(renderer);
}

void clean_up()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}

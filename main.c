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

#define W_WIDTH 680
#define W_HEIGHT 400
#define VEL 10;

bool init_create_window_renderer(SDL_Window** window, SDL_Renderer** renderer);
void move(SDL_Rect* dest, float* pos_x, float* pos_y, Entity e);

int main(void)
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!init_create_window_renderer(&window, &renderer))
        return -1;

    Entity m = {300, 300, 50, 50, "./demo/sankyuu.png"};
    SDL_Texture* texture = IMG_LoadTexture(renderer, m.path);
    SDL_Rect dest = {m.x, m.y, m.w, m.h};

    SDL_Event e;
    bool running = true;
    float pos_x = dest.x;
    float pos_y = dest.y;

    while(running)
    {
	while(SDL_PollEvent(&e))
	{
	    if (e.type == SDL_QUIT)
		running = false;
	    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	    {
		switch (e.key.keysym.sym)
		{
		case SDLK_w: pos_y -= VEL; break;
		case SDLK_a: pos_x -= VEL; break;
		case SDLK_s: pos_y += VEL; break;
		case SDLK_d: pos_x += VEL; break;
		}
	    }
	    // Clear screen
	    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 225);
	    SDL_RenderClear(renderer);

	    // Set pos from key press
	    move(&dest, &pos_x, &pos_y, m);
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

bool init_create_window_renderer(SDL_Window** window, SDL_Renderer** renderer)
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

    *window = SDL_CreateWindow(
    	"TITLE",
    	SDL_WINDOWPOS_CENTERED,
    	SDL_WINDOWPOS_CENTERED,
    	W_WIDTH,
    	W_HEIGHT,
    	SDL_WINDOW_SHOWN);
    if (*window == NULL)
    {
    	fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
    	return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL)
    {
    	fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
    	return false;
    }

    return true;
}

void move(SDL_Rect* dest, float* pos_x, float* pos_y, Entity e)
{
    if (*pos_x < 0) *pos_x = 0;
    else if (*pos_x + e.w > W_WIDTH) *pos_x = W_WIDTH - e.w;
    if (*pos_y < 0) *pos_y = 0;
    else if (*pos_y + e.h > W_HEIGHT) *pos_y = W_HEIGHT - e.h;

    dest->x = *pos_x;
    printf ("pos_x:%d, ", dest->x);
    dest->y = *pos_y;
    printf ("pos_y:%d ", dest->y);
}

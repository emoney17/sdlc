#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FPS 60
#define FRAME_DELAY 1000/60
#define W_TITLE "no clean code"
#define W_WIDTH 500
#define W_HEIGHT 500

typedef struct
{
    int x;
    int y;
    int w;
    int h;
    const char* path;
}Entity;

void init(SDL_Window** window, SDL_Renderer** renderer);
Entity createEntity(int x, int y, int w, int h, const char* path);
void draw(Entity entity, SDL_Renderer* renderer);
float hireTimeInSeconds();

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    init(&window, &renderer);

    Entity allEntities[] = {
	createEntity(200, 0, 50, 50, "./sankyuu.png"),
	createEntity(300, 300, 50, 50, "./sankyuu.png"),
	createEntity(0, 0, 200, 200, "./splash.png"),
    };

    SDL_Rect rect1;
    rect1.x = 400;
    rect1.y = 400;
    rect1.w = 100;
    rect1.h = 100;
    
    SDL_Rect rect2;
    rect2.x = 370;
    rect2.y = 370;
    rect2.w = 100;
    rect2.h = 100;

    SDL_Rect inter;
    SDL_IntersectRect(&rect1, &rect2, &inter);
    
    bool running = true;
    SDL_Event e;

    unsigned int frameStart;
    int frameTime;
    int count = 0;
    
    while (running) {

	frameStart = SDL_GetTicks(); // how many ms since init sdl2

	while (SDL_PollEvent(&e)) {
	    if (e.type == SDL_QUIT)
		running = false;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225); // clear color
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225); // rect color
	SDL_RenderDrawRect(renderer, &rect1);
	SDL_RenderDrawRect(renderer, &rect2);

	SDL_SetRenderDrawColor(renderer, 225, 0, 0, 225); // inter color
	SDL_RenderFillRect(renderer, &inter);

	for (int i = 0; i < 3; i++) {
	    draw(allEntities[i], renderer);
	}
	frameTime = SDL_GetTicks() - frameStart; // how long in ms frames taken to render and everything
	if (FRAME_DELAY >= frameTime) 
	    SDL_Delay(FRAME_DELAY - frameTime);

	printf("%d\n", count);
	count++;
	SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_QUIT;

    return 0;
}

void init(SDL_Window** window, SDL_Renderer** renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0) fprintf(stderr, "Error initializing sdl: %s\n", SDL_GetError());
    if (!(IMG_Init(IMG_INIT_PNG))) fprintf(stderr, "Error initializing sdl image: %s\n", SDL_GetError());

    *window = SDL_CreateWindow(W_TITLE, 0, 0, W_WIDTH, W_HEIGHT, 0);
    if (!*window) fprintf(stderr, "Error creating window: %s\n", SDL_GetError());

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer) fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
}

Entity createEntity(int x, int y, int w, int h, const char* path)
{
    Entity entity;
    entity.x = x; 
    entity.y = y; 
    entity.w = w; 
    entity.h = h; 
    entity.path = path; 
    return entity;
}

void draw(Entity entity, SDL_Renderer* renderer)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, entity.path);
    if (!texture) 
	fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());

    SDL_Rect dst;
    dst.x = entity.x;
    dst.y = entity.y;
    dst.w = entity.w;
    dst.h = entity.h;

    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

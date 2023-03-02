#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "./application.h"

int main(void)
{
    create("SDL2 WINDOW", 680, 400);
    update();
    draw();
    clean();
    return 0;
}

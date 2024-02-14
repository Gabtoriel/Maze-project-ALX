#ifndef __MAZE_H__
#define __MAZE_H__

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGTH 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
int poll_events(void);
void draw_RayCaster(SDL_Instance *);
#endif /* __MAZE_H__ */

#ifndef __MAZE_H__
#define __MAZE_H__

#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGTH 480
#define MAP_WIDTH 24
#define MAP_HEIGTH 24

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
int poll_events(void);

#endif /* __MAZE_H__ */

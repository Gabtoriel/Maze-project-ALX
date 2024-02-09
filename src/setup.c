#include "../dependencies/maze.h"

/**
 * init_instance - initializes the game window and instantiates the renderer.
 * @instance: point to struct that holds window instance
 * Return: int (0) successful 1 (failed)
 */
int init_instance(SDL_Instance *instance)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "unable to initialize SDL: %s\n",
SDL_GetError());
		return (1);
	}
	/* Create a window */
	instance->window = SDL_CreateWindow("MAZE GAME", SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGTH, 0);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL Window Error %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	/* Create a new renderer instance linked to the window. */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "Failed to instantiate renderer %s\n",
SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}

/**
 * poll_events - check for sdl events and then run a process
 * Return: (1) quit
 */
int poll_events()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
		}
	}
	return (0);
}


#include "../dependencies/maze.h"

/**
 * draw_RayCaster - draws the game world using ray casting
 * Resources: https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
 * return: void
 */
void draw_RayCaster(SDL_Instance * instance)
{
	int world_map[MAP_HEIGHT][MAP_WIDTH]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int posX;
	int posY;
	int gposX = 240;
	int gposY = 240;
	float player_angle = M_PI;
	float FOV = (M_PI / 3);
	float HALF_FOV = FOV / 2;
	int grid_width = 20;
	int grid_height = 20;
	int grid_length = 20;
	SDL_Rect grect;
	SDL_Rect prect = {240, 240, 5, 5};

	SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 0); 
        SDL_RenderClear(instance->renderer);

	// draw a 2d grid
	posY = 0;
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		posX = 0;
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (world_map[i][j] > 0)
			{
				grect.x = posX;
				grect.y = posY;
				grect.w = grid_width - 2;
				grect.h = grid_length - 2;
				SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255);
				SDL_RenderDrawRect(instance->renderer, &grect);
				SDL_RenderFillRect(instance->renderer, &grect);
				posX += 20;
			}
			else
                        {
				grect.x = posX;
                                grect.y = posY;
                                grect.w = grid_width - 2;
                                grect.h = grid_length - 2;
                                SDL_SetRenderDrawColor(instance->renderer, 128, 128, 128, 255);
                                SDL_RenderDrawRect(instance->renderer, &grect);
                                SDL_RenderFillRect(instance->renderer, &grect);
                                posX += 20; 
                        }
		}
		posY += 20;
	}
	// draw a red rectangle to represent player position
	SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(instance->renderer, &prect);
	SDL_RenderFillRect(instance->renderer, &prect);

	// draw a line to represent player position
	SDL_SetRenderDrawColor(instance->renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(instance->renderer, gposX, gposY, (gposX + sin ( (double)player_angle ) * 50),
(gposY + cos ( (double)player_angle ) * 50) );

	// draw field of view
	SDL_RenderDrawLine(instance->renderer, gposX, gposY,
(gposX + sin ( (double)player_angle + HALF_FOV ) * 50),
(gposY + cos ( (double)player_angle + HALF_FOV ) * 50) );
	SDL_RenderDrawLine(instance->renderer, gposX, gposY,
(gposX + sin ( (double)player_angle - HALF_FOV ) * 50),
(gposY + cos ( (double)player_angle - HALF_FOV ) * 50) );

	// print certain values
	printf("math.pi %lf\n", M_PI);
	printf("fov %f\n", FOV);
	printf("half fov %f\n", HALF_FOV);
	printf("math sin of player angle + pos - fov/2 %lf\n", (gposX + sin ( (double)player_angle + HALF_FOV )) * 50);
	printf("math cos of player angle +  pos - fov/2%lf\n", (gposX + sin ( (double)player_angle + HALF_FOV ))) * 50;
}

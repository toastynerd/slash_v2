/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 */

#include "slash.h"
#include "init.h"
#include "game_map.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

GlobalRenderObjects* init_render()
{
	if (SDL_Init(SDL_INIT_EVERYTHING < 0)) {
		printf("could not init SDL: %s \n", SDL_GetError());
		exit(1);
	}

	GlobalRenderObjects *gro = (GlobalRenderObjects*)malloc(sizeof(GlobalRenderObjects));
	gro->window = SDL_CreateWindow("Slash!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gro->window == NULL) {
		printf("could not create window: %s \n", SDL_GetError());
		free(gro);
		exit(1);
	}

	gro->renderer = SDL_CreateRenderer(gro->window, -1, 0);
	if (gro->renderer == NULL) {
		printf("could not create renderer: %s \n", SDL_GetError());
		free(gro);
		exit(1);
	}

	SDL_SetRenderDrawColor(gro->renderer, 200, 200, 200, 255);
	//SDL_RenderClear(gro->renderer);

	return gro;
}

void cleanup(GlobalRenderObjects* global_render_objects, GameMap *map)
{
	cleanup_map(map);
	SDL_DestroyRenderer(global_render_objects->renderer);
	SDL_DestroyWindow(global_render_objects->window);
	free(global_render_objects);
	SDL_Quit();
}

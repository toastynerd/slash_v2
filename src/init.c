/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 */

#include "slash.h"
#include "init.h"
#include <SDL2/SDL.h>

GlobalRenderObjects* init_render()
{
	if (SDL_Init(SDL_INIT_EVERYTHING < 0)) {
		printf("could not init SDL: %s \n", SDL_GetError());
		exit(1);
	}

	GlobalRenderObjects *gro = (GlobalRenderObjects*)malloc(sizeof(GlobalRenderObjects));
	gro->window = SDL_CreateWindow("Slash!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gro->window == 0) {
		printf("could not create window: %s \n", SDL_GetError());
		free(gro);
		exit(1);
	}

	return gro;
}

void cleanup(GlobalRenderObjects* global_render_objects)
{
	SDL_DestroyWindow(global_render_objects->window);
	free(global_render_objects);
	SDL_Quit();
}

/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 */

#include "game_map.h"
#include <SDL2/SDL.h>
#include <time.h>

#ifndef _INIT_H_
#define _INIT_H_

typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
	time_t seed;
	char running;
} GlobalRenderObjects;

GlobalRenderObjects* init_render(int argc, char **argv);

void cleanup(GlobalRenderObjects* global_render_objects, GameMap *map);

#endif

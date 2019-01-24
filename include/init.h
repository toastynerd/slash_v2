/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 */

#include "game_map.h"
#include <SDL2/SDL.h>

#ifndef _INIT_H_
#define _INIT_H_

typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
} GlobalRenderObjects;

GlobalRenderObjects* init_render();

void cleanup(GlobalRenderObjects* global_render_objects, GameMap *map);

#endif

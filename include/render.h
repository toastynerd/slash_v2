/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * render.h
 */

#include "slash.h"
#include "game_map.h"
#include <SDL2/SDL.h>

#ifndef _RENDER_H_
#define _RENDER_H_
void render_map(GameMap *map, SDL_Renderer * renderer);
#endif

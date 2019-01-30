/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * map_generation.h
 */

#include "slash.h"
#include "game_map.h"
#include <SDL2/SDL.h>

#ifndef _MAP_GENERATION_H_
#define _MAP_GENERATION_H_
void initialize_map(GameMap *map);
int count_alive_neighbors(GameMap *map, int x, int y);
void do_simulation_step(GameMap *map);
#endif

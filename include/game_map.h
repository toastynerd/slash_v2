/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * game_map.h
 */

#include "slash.h"
#include <SDL2/SDL.h>

#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

typedef struct {
	enum TileType map_tiles[MAP_WIDTH][MAP_HEIGHT];
	SDL_Texture *tile_textures[NUM_TILE_TYPES];
} GameMap;

GameMap *create_map();
int load_tile_textures(GameMap *map, SDL_Renderer *renderer);
void cleanup_map(GameMap *map);

#endif

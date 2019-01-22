/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * game_map.h
 */

#include "slash.h"

#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

typedef struct {
	enum TileType map_tiles[MAP_WIDTH - 1][MAP_HEIGHT - 1]
} GameMap;

GameMap *create_map();
void cleanup_map(GameMap *map);

#endif

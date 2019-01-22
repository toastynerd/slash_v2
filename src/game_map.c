/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * game_map.c
 */

#include "slash.h"
#include "game_map.h"
#include <stdio.h>
#include <stdlib.h>

GameMap *create_map()
{
	GameMap *map = (GameMap*)malloc(sizeof(GameMap));

	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_WIDTH; y++) {
			map->map_tiles[x][y] = (enum TileType)(rand() % 2);
		}
	}
	return map;
}

void cleanup_map(GameMap *map)
{
	free(map);
}

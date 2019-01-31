/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * game_map.c
 */

#include "slash.h"
#include "game_map.h"
#include "map_generation.h"
#include "texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

GameMap *create_map()
{
	GameMap *map = (GameMap*)malloc(sizeof(GameMap));

	for (int x = 0; x < MAP_WIDTH ; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++) {
			map->map_tiles[x][y] = WALL_TILE;
		}
	}
	initialize_map(map);
	for (int x = 0; x < MAP_ITERATIONS; x++) {
		do_simulation_step(map);
	}
	printf("size of largest cavern: %d\n", find_largest_cavern(map));
	printf("total floor tiles: %d\n", find_total_floor_tiles(map));
	return map;
}

int load_tile_textures(GameMap *map, SDL_Renderer *renderer)
{
	int tiles_loaded = 0;

	map->tile_textures[FLOOR_TILE] = load_texture("assets/floor_tile.png", renderer);
	if (map->tile_textures[FLOOR_TILE] != NULL)
		tiles_loaded++;

	map->tile_textures[WALL_TILE] = load_texture("assets/wall_tile.png", renderer);
	if (map->tile_textures[WALL_TILE] != NULL)
		tiles_loaded++;
	return tiles_loaded;
}

void cleanup_map(GameMap *map)
{
	for (int i = 0; i < NUM_TILE_TYPES; i++) {
		SDL_DestroyTexture(map->tile_textures[i]);
	}
	free(map);
}

int find_total_floor_tiles(GameMap *map)
{
	int count = 0;
	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++) {
			if (map->map_tiles[x][y] == FLOOR_TILE)
				count++;
		}
	}

	return count;
}

int find_largest_cavern(GameMap *map)
{
	int largest = 0;
	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++) {
			int temp = find_connected_area(map, x, y);
			if (temp > largest)
				largest = temp;
		}
	}
	return largest;
}

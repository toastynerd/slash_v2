/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * map_generation.c
 */

#include "slash.h"
#include "map_generation.h"
#include <stdio.h>
#include <stdlib.h> 

void initialize_map(GameMap *map)
{
	for(int x = 0; x < MAP_WIDTH; x++) {
		for(int y = 0; y < MAP_HEIGHT; y++) {
			if (rand() % 100 < CHANCE_TO_START_ALIVE)
				map->map_tiles[x][y] = FLOOR_TILE;
		}
	}
}

int count_alive_neighbors(GameMap *map, int x, int y)
{
	int count = 0;
	for(int i = -1; i < 2; i++) {
		for(int j = -1; j < 2; j++) {
			int neighbor_x = x + i;
			int neighbor_y = y + j;
			if (i == 0 && j == 0) {
				//do nothing
			} else if(neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= MAP_WIDTH || neighbor_y >= MAP_HEIGHT) {
//				count++;
			} else if(map->map_tiles[neighbor_x][neighbor_y] == FLOOR_TILE) {
				count++;
			}
		}
	}
	return count;
}

void do_simulation_step(GameMap *map)
{
	for(int x = 0; x < MAP_WIDTH; x++) {
		for(int y = 0; y < MAP_HEIGHT; y++) {
			int neighbors = count_alive_neighbors(map, x, y);
			if (map->map_tiles[x][y] == FLOOR_TILE) {
				if (neighbors < DEATH_LIMIT) {
					map->map_tiles[x][y] = WALL_TILE;
				}
			} else {
				if (neighbors > BIRTH_LIMIT) {
					map->map_tiles[x][y] = FLOOR_TILE;
				} 
			}
		}
	}
}

int abs(int input)
{
	if (input < 0)
		return 0 - input;
	return input;
}

int flood_fill(GameMap *map, int x, int y, char visited[MAP_WIDTH][MAP_HEIGHT], int *count)
{
	visited[x][y] = 1;
	*count = *count + 1;
	for(int i = -1; i < 2; i++) {
		for(int j = -1; j < 2; j++) {
			int neighbor_x = x + i;
			int neighbor_y = y + j;
			if (abs(i + j) == 0 || abs(i + j) == 2) {}
			else if (map->map_tiles[neighbor_x][neighbor_y] == FLOOR_TILE && visited[neighbor_x][neighbor_y] != 1) {
				flood_fill(map, neighbor_x, neighbor_y, visited, count);
			}
		}
	}
	return *count;
}

int find_connected_area(GameMap *map, int x, int y)
{
	int count = 0;
	char visited[MAP_WIDTH][MAP_HEIGHT];
	if (map->map_tiles[x][y] == WALL_TILE)
		return 0;
	for(int x = 0; x < MAP_WIDTH; x++) {
		for(int y = 0; y < MAP_HEIGHT; y++) {
			visited[x][y] = 0;
		}
	}

	return flood_fill(map, x, y, visited, &count);
}

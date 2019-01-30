/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 */

#ifndef _SLASH_H_
#define _SLASH_H_

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//tile width and height in pixels
#define TILE_WIDTH 16
#define TILE_HEIGHT 16

//map width and height in tiles
#define MAP_WIDTH 40
#define MAP_HEIGHT 30

enum TileType {
	WALL_TILE,
	FLOOR_TILE,
	NUM_TILE_TYPES
};

//map generation variables
#define CHANCE_TO_START_ALIVE 50
#define DEATH_LIMIT 6
#define BIRTH_LIMIT 3
#define MAP_ITERATIONS 35

#endif

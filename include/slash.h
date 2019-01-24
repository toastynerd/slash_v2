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
	FLOOR_TILE,
	WALL_TILE,
	NUM_TILE_TYPES
};

#endif

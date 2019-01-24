/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 */

#include "render.h"
#include <SDL2/SDL.h>

void render_map(GameMap *map, SDL_Renderer *renderer)
{
	SDL_Rect source_rect;
	SDL_Rect dest_rect;
	source_rect.x = 0;
	source_rect.y = 0;
	source_rect.w = TILE_WIDTH;
	source_rect.h = TILE_HEIGHT;
	dest_rect.w = TILE_WIDTH;
	dest_rect.h = TILE_HEIGHT;
	for (int x = 0; x < MAP_WIDTH; x++) {
		for(int y = 0; y < MAP_HEIGHT; y++) {
			dest_rect.x = x * TILE_WIDTH;
			dest_rect.y = y * TILE_HEIGHT;
			SDL_RenderCopy(renderer, map->tile_textures[map->map_tiles[x][y]], &source_rect, &dest_rect);
		}
	}
}

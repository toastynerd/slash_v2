/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * main.c
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "slash.h"
#include "init.h"
#include "game_map.h"
#include "render.h"

int main(int argc, char **argv)
{
	GlobalRenderObjects *gro = init_render();

	GameMap *map = create_map();

	if (load_tile_textures(map, gro->renderer) != NUM_TILE_TYPES) {
		printf("could not load tile texures: %s\n", SDL_GetError());
	}

	render_map(map, gro->renderer);

	SDL_RenderPresent(gro->renderer);

	SDL_Delay(5000);

//	cleanup(gro, map);
	return 0;
}

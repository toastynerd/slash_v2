/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * texture.c
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "texture.h"

SDL_Texture *load_texture(char *path, SDL_Renderer *renderer)
{
	SDL_Surface *temp_surface = IMG_Load(path);
	if (temp_surface == NULL) {
		printf("Could not load Image %s error: %s\n", path, SDL_GetError());
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	if (texture == NULL) {
		printf("Could not create texutre: %s\n", SDL_GetError());
		return NULL;
	}

	return texture;
}

/*
 * Slash! a rogue like
 * tylermorgan86@gmail.com
 * events.c
 */

#include <SDL2/SDL.h>
#include "events.h"

void handle_events(GlobalRenderObjects *gro)
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				gro->running = 0;
				break;
			default:
				break;
		}
	}
}

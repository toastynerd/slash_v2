#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "init.h"

int main(int argc, char **argv)
{
	GlobalRenderObjects *gro = init_render();

	SDL_Delay(5000);

	cleanup(gro);
	return 0;
}

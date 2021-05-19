#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include "asciifier.hpp"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("No image given.\n");
        return -1;
    }

    Asciifier asciifier = Asciifier(argv[1]);
    asciifier.run();
    std::cout << asciifier << std::endl;

	return 0;
}
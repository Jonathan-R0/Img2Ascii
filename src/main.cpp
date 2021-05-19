#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include "protocol.h"
#include "sdlsurface.h"

char values[] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("No image given.\n");
        return -1;
    }

	SdlSurface surface = SdlSurface(argv[1]);

    int w, h;
    surface.getSizes(&w, &h);

    std::string art = "";
    SDL_Color color;

    int factor = 255/sizeof(values);

    for (int i = 0; i < h; i += h/100) {
        for (int j = 0; j < w; j += w/200) {
            color = surface.getPixelColor(j,i);
            // 0 <= brightness <= 255
            float b = 0.299 * color.r + 0.587 * color.g + 0.114 * color.b;
            art += values[int(b/factor)];
        }
        art += "\n";
    }

    std::cout << art << std::endl;
	return 0;
}
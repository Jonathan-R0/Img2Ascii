#include "sdlsurface.hpp"
#include "log.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "protocol.hpp"

SdlSurface::SdlSurface(const char* imgpath) :
    surface(IMG_Load(imgpath)) {
    if (!this->surface) {
        std::string error = "Could not open file ";
        error += imgpath;
        LOG(error.c_str());
    }
    this->w = this->surface->w;
    this->h = this->surface->h;
}

SdlSurface::SdlSurface(SdlSurface&& other) {
    this->surface = other.surface;
}

SdlSurface::~SdlSurface() {
    SDL_FreeSurface(this->surface);
}

SDL_Color SdlSurface::getPixelColor(const int x, const int y) {
	const Uint8 bpp = this->surface->format->BytesPerPixel;
	Uint8* pixel = (Uint8*)this->surface->pixels + y * this->surface->pitch + x * bpp;
	SDL_Color color = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};
	SDL_GetRGB(*(Uint32*)pixel, this->surface->format, &color.r, &color.g, &color.b);
	return color;
}

void SdlSurface::getSizes(int* w, int* h) {
    *w = this->w;
    *h = this->h;
}
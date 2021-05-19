#include "sdlsurface.h"
#include "log.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "protocol.h"

SdlSurface::SdlSurface(const std::string& imgpath) :
    surface(IMG_Load(std::string(IMG_PATH + imgpath).c_str())) {
    if (!this->surface) {
        LOG(std::string("Could not open file " + imgpath).c_str());
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
	Uint32 pixelData = *(Uint32*)pixel;
	SDL_Color Color = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};
	SDL_GetRGB(pixelData, this->surface->format, &Color.r, &Color.g, &Color.b);
	return Color;
}

void SdlSurface::getSizes(int* w, int* h) {
    *w = this->w;
    *h = this->h;
}
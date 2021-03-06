#ifndef __SDL_SURFACE_HPP__
#define __SDL_SURFACE_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class SdlSurface {
  private:
    SDL_Surface* surface;
    int w,h;

  public:
    SdlSurface(const char* imgpath);
    SdlSurface(SdlSurface&& other);
    ~SdlSurface();
    void getSizes(int* w, int* h);
    SDL_Color getPixelColor(const int x, const int y);
};

#endif  // __SDL_SURFACE_HPP__
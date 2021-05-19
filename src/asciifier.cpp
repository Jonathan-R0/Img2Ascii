#include "asciifier.hpp"
#include "sdlsurface.hpp"
#include "protocol.hpp"
#include <iostream>

Asciifier::Asciifier(const char* imgpath) :
	surface(SdlSurface(imgpath)) {
    surface.getSizes(&this->w, &this->h);
    this->art.reserve(this->w * this->h / 150);
}

void Asciifier::run() {
    SDL_Color color;

    for (int i = 0; i < this->h; i += this->h/100) {
        for (int j = 0; j < this->w; j += this->w/200) {
            color = surface.getPixelColor(j,i);
            // 0 <= brightness <= 255
            float b = 0.299 * color.r + 0.587 * color.g + 0.114 * color.b;
            this->art += this->values[int(b/this->factor)];
        }
        this->art += "\n";
    }
}

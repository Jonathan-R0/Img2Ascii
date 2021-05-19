#ifndef __ASCIIFIER_HPP__
#define __ASCIIFIER_HPP__

#include "sdlsurface.hpp"
#include <string>

class Asciifier {
  private:
    SdlSurface surface;
    std::string art;
    int w, h;
    char values[71] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int factor = 255/sizeof(this->values);

  public:
    Asciifier(const char* imgpath);
    void run();
    friend std::ostream& operator<<(std::ostream& out, const Asciifier& other) {
        out << other.art;
        return out;
    }
};

#endif  // __ASCIIFIER_HPP__
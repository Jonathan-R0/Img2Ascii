#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "log.h"

#define IMG_PATH "./images/"
#define TITLE "Image to Ascii"
#define FONT_PATH "./fonts/"
#define FONT "UbuntuMono-Regular.ttf"
#define LOGO "images.jpg"
#define WHITE 255,255,255
#define LOG_WITH_ID(Y) LOG((Y + std::to_string(id)).c_str())
#define LOG(ERROR) Log::log(__FILE__, __FUNCTION__, __LINE__, ERROR);

#endif
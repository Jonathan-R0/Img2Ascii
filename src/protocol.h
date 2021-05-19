#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "log.h"

#define LOG_WITH_ID(Y) LOG((Y + std::to_string(id)).c_str())
#define LOG(ERROR) Log::log(__FILE__, __FUNCTION__, __LINE__, ERROR);

#endif
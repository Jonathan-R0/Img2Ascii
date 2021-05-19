#ifndef __PROTOCOL_HPP__
#define __PROTOCOL_HPP__

#include "log.hpp"

#define LOG_WITH_ID(Y) LOG((Y + std::to_string(id)).c_str())
#define LOG(ERROR) Log::log(__FILE__, __FUNCTION__, __LINE__, ERROR);

#endif  // __PROTOCOL_HPP__
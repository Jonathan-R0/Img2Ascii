cmake_minimum_required(VERSION 2.8)

project(qt-sdl)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

add_library(img2ascii
  src/sdlsurface.cpp
  src/sdlsurface.h
  src/log.h
  src/log.cpp
  src/protocol.h
)

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

add_executable (exec
  src/main.cpp  
)

target_link_libraries(exec img2ascii SDL2 SDL2_image)
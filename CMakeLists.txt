cmake_minimum_required(VERSION 3.24)

project(sdl2-gaming)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_subdirectory(SDL)
add_subdirectory(SDL_image)
add_subdirectory(SDL_ttf)

add_subdirectory(src)
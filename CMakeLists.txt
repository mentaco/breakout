cmake_minimum_required(VERSION 3.10)
project(Breakout)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(breakout src/main.cpp src/game.cpp src/paddle.cpp)

target_link_libraries(breakout ${CURSES_LIBRARIES})

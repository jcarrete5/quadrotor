cmake_minimum_required(VERSION 3.10.2)
set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules)

# Include AVR toolchain for CMake
include(avr-gcc-toolchain)

project(quadrotor C)

add_subdirectory(src/aircraft)
add_subdirectory(src/controller)

cmake_minimum_required(VERSION 3.28.0)
project(dna_transcriptor VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -std=gnu++2c")
file(GLOB SOURCES *.h *.cpp)
add_executable(dna_transcriptor main.cpp ${SOURCES})
target_compile_options(dna_transcriptor PRIVATE -Wall -Wextra -Wpedantic -Werror)

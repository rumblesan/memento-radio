cmake_minimum_required(VERSION 3.0)

project(memento)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99 -D_POSIX_C_SOURCE=199309L")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(libmemento/include)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_subdirectory(libmemento)
add_subdirectory(main)

enable_testing()
add_subdirectory(tests)

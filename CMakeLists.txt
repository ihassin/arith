cmake_minimum_required(VERSION 3.10)

project(addition)

include_directories(lib/include)

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(app)

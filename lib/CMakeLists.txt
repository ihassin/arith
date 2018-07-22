cmake_minimum_required(VERSION 3.10)

include_directories ("./include")

add_definitions(-DDEBUG)

file(GLOB SRC_FILES *.c include/*.h)

add_library(additionLib ${SRC_FILES})

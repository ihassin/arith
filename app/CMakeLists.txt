add_definitions(-DDEBUG)

file(GLOB SRC_FILES *.c *.h)
add_executable (addition ${SRC_FILES})

target_link_libraries(addition additionLib)

set(EXECUTABLE_OUTPUT_PATH ../bin)

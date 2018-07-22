include_directories ("./include")

add_definitions(-DDEBUG)

file(GLOB SRC_FILES *.c *.h)

set(SOURCE_FILES
    unity/unity.c
    unity/unity.h
    unity/unity_config.h
    unity/unity_fixture.c
    unity/unity_fixture.h
    unity/unity_fixture_internals.h
    unity/unity_fixture_malloc_overrides.h
    unity/unity_internals.h
    all_tests.c
        TestAddition_Runner.c
        TestAddition.c)

include_directories(.)
include_directories(unity)

add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests additionLib)

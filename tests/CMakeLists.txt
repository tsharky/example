set(THIS ExampleTests)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

set(SOURCES
    example_tests.cpp
)

add_executable(${THIS} ${SOURCES})
target_link_libraries(${THIS}
    gtest
    gmock
    gtest_main
    example
)

add_test(
    NAME ${THIS}
    COMMAND ${THIS}
)

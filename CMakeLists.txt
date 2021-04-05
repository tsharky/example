cmake_minimum_required(VERSION 3.17)
project(example C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(extern/googletest)

set(Headers
        Example.hpp
        )

set(Sources
        Example.cpp
        )

add_library(${CMAKE_PROJECT_NAME} STATIC ${Sources} ${Headers})

add_executable(main main.cpp)
target_link_libraries(main PUBLIC
        example
        )

add_subdirectory(tests)
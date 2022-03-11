cmake_minimum_required(VERSION 3.22)
project(ModernCMakeExample
    DESCRIPTION "An example project with CMake"
    LANGUAGES C CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_C_STANDARD 99)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)

    set(CMAKE_CXX_EXTENSIONS OFF)
    
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing
    option(PACKAGE_TESTS "Build the tests" ON)

    # Doxygen
    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs.")
    endif()
endif()

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

message(STATUS "Hallo1")
message(STATUS ${PACKAGE_TESTS})
if(${PACKAGE_TESTS})
    message("Hallo2")
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()

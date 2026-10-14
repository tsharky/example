cmake_minimum_required(VERSION 4.4)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD f35a9ac6-8463-4d38-8eec-5d6008153e7d)

project(ExampleProject
    DESCRIPTION "An example project with CMake"
    LANGUAGES CXX
    VERSION 0.1.0
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Add libraries
add_subdirectory(libs/syslog)

# Add applications
add_subdirectory(apps/example)

# Doxygen
find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, not building docs.")
endif()

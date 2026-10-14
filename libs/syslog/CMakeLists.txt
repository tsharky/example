set(THIS syslog)

add_library(${THIS})

if(CMAKE_CXX_MODULES)
    target_sources(${THIS}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS src/
        FILES
            src/syslog.cppm
    )

    list(APPEND DOXYGEN_INPUTS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/syslog.cppm"
    )
    set(DOXYGEN_INPUTS "${DOXYGEN_INPUTS}" PARENT_SCOPE)
else()
    target_sources(${THIS}
    PRIVATE
        src/syslog.cpp
    
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include/
        FILES
            include/syslog.hpp
    )

    list(APPEND DOXYGEN_INPUTS
        "${CMAKE_CURRENT_SOURCE_DIR}/include/syslog.hpp"
    )
    set(DOXYGEN_INPUTS "${DOXYGEN_INPUTS}" PARENT_SCOPE)
endif()



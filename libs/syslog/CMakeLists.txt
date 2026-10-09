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
endif()



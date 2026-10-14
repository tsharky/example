set(THIS example)

add_executable(${THIS})

target_sources(${THIS}
PRIVATE
    src/example.cpp
)

target_compile_definitions(${THIS}
PRIVATE
    VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    VERSION_MINOR=${PROJECT_VERSION_MINOR}
    VERSION_PATCH=${PROJECT_VERSION_PATCH}
)

target_link_libraries(${THIS}
PRIVATE
    syslog
)

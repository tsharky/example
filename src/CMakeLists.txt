set(THIS example_library)

set(HEADER_LIST
	"${PROJECT_SOURCE_DIR}/include/example/example.hpp"
)

set(SOURCE_LIST
    "example.cpp"
)

add_library(${THIS} ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${THIS} PUBLIC
    "../include"
)


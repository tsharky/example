set(THIS example_app)

include(GetGitRevisionDescription)
git_describe(VERSION --tags)

if (NOT "${VERSION}" STREQUAL "HEAD-HASH-NOTFOUND")
	string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION}")
	string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION}")
	string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH "${VERSION}")
	set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
else ()
	set(VERSION_SHORT "0.0.0")
endif ()

add_executable(${THIS}
	main.cpp
)

target_compile_features(${THIS} PRIVATE
	cxx_std_20
)

target_compile_definitions(${THIS} PRIVATE
	VERSION="${VERSION_SHORT}"
)

target_compile_options(${THIS} PRIVATE
	-Wall
	-Wextra
	-Wconversion
	-Wsign-conversion
	-Werror=unused-result
	-Werror
)

target_link_libraries(${THIS} PRIVATE
    example_library
)

# install(TARGETS ${THIS} DESTINATION "")

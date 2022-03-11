set(THIS example_app)

add_executable(${THIS}
	main.cpp
)

target_compile_features(${THIS} PRIVATE
	cxx_std_20
)

target_link_libraries(${THIS} PRIVATE
    example_library
)

make_minimum_required(VERSION 3.18)
project(TestProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
	${PROJECT_NAME}
	       ${PROJECT_SOURCE_DIR}/src/main.cpp
}

if (EMSCRIPTEN)
    target_compile_options(
	${PROJECT_NAME}
	PRIVATE
        -O3
        -Wall
        -sUSE_SDL=2
    )

    target_link_options(
	${PROJECT_NAME}
	PRIVATE
        -sUSE_SDL=2
        -sALLOW_MEMORY_GROWTH=1
    )

    set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        SUFFIX ".html"
    )
endif()
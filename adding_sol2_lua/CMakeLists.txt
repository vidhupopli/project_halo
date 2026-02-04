cmake_minimum_required(VERSION 3.18)
# This creates PROJECT_NAME variable
project(index LANGUAGES CXX C)

# Setting flags and variables
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(LUA_SRC_DIR ${PROJECT_SOURCE_DIR}/dependencies/lua)
set(LUA_SOURCES
    ${LUA_SRC_DIR}/onelua.c
)
add_library(lua_lib STATIC ${LUA_SOURCES})
target_include_directories(lua_lib PUBLIC ${LUA_SRC_DIR})

# Target Type Executable
add_executable(
	${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/src/main.cpp
)
# Link Lua library to executable
target_link_libraries(${PROJECT_NAME} PRIVATE lua_lib)
target_include_directories(${PROJECT_NAME} PRIVATE ${LUA_SRC_DIR})
# Link Sol2 library (header-only)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/sol2/include)
# Enable all sol2 safety checks at compile time like: type checking / validating that lua values match expected C++ types
target_compile_definitions(${PROJECT_NAME} PRIVATE SOL_ALL_SAFETIES_ON)
# Linking SDL2 library
if (EMSCRIPTEN)
    target_compile_options(
	${PROJECT_NAME}
	PRIVATE
        -O3
        -Wall
        -sUSE_SDL=2
    )

    # Linking SDL2 Library
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

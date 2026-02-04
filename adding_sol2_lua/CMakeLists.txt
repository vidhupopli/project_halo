cmake_minimum_required(VERSION 3.18)
# This creates PROJECT_NAME variable
project(proj_adding_lua LANGUAGES CXX C)

# Setting flags and variables
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(LUA_SRC_DIR ${PROJECT_SOURCE_DIR}/dependencies/lua/src)
set(LUA_SOURCES
    ${LUA_SRC_DIR}/lapi.c
    ${LUA_SRC_DIR}/lauxlib.c
    ${LUA_SRC_DIR}/lbaselib.c
    ${LUA_SRC_DIR}/lcode.c
    ${LUA_SRC_DIR}/lcorolib.c
    ${LUA_SRC_DIR}/lctype.c
    ${LUA_SRC_DIR}/ldblib.c
    ${LUA_SRC_DIR}/ldebug.c
    ${LUA_SRC_DIR}/ldo.c
    ${LUA_SRC_DIR}/ldump.c
    ${LUA_SRC_DIR}/lfunc.c
    ${LUA_SRC_DIR}/lgc.c
    ${LUA_SRC_DIR}/linit.c
    ${LUA_SRC_DIR}/liolib.c
    ${LUA_SRC_DIR}/llex.c
    ${LUA_SRC_DIR}/lmathlib.c
    ${LUA_SRC_DIR}/lmem.c
    ${LUA_SRC_DIR}/loadlib.c
    ${LUA_SRC_DIR}/lobject.c
    ${LUA_SRC_DIR}/lopcodes.c
    ${LUA_SRC_DIR}/loslib.c
    ${LUA_SRC_DIR}/lparser.c
    ${LUA_SRC_DIR}/lstate.c
    ${LUA_SRC_DIR}/lstring.c
    ${LUA_SRC_DIR}/lstrlib.c
    ${LUA_SRC_DIR}/ltable.c
    ${LUA_SRC_DIR}/ltablib.c
    ${LUA_SRC_DIR}/ltm.c
    ${LUA_SRC_DIR}/lundump.c
    ${LUA_SRC_DIR}/lvm.c
    ${LUA_SRC_DIR}/lzio.c
    ${LUA_SRC_DIR}/lutf8lib.c
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

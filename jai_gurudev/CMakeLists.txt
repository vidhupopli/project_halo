# cmake_minimum_required(VERSION 3.20)

# project(getting_started)

# set(CMAKE_CXX_STANDARD 20)

# add_executable(
#     ${PROJECT_NAME}
#     main.cpp
# )

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# set(CMAKE_EXECUTABLE_SUFFIX ".html")

cmake_minimum_required(VERSION 3.20)

project(getting_started)

# 1. Use the standard variables
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

# 2. Add Emscripten-specific linker flags
# These tell Emscripten to generate the HTML shell and use specific features
target_link_options(${PROJECT_NAME} PRIVATE "-O3")

# 3. This is what makes it output .html instead of a binary
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
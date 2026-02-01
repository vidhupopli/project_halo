###############################
# Q. What are we trying to do here?
# Generate the config for make such that it is able to generate
# wasm file, js file, and the html file.
###############################

###############################
# Way 1
###############################
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
###############################

###############################
# Way 2
###############################
cmake_minimum_required(VERSION 3.20)
project(jai_gurudev)

# 1. Use the standard variables
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. The executable file is going to be called jai_gurudev
add_executable(${PROJECT_NAME} main.cpp)

# 3. Add Emscripten-specific linker flags
# These tell Emscripten to generate the HTML shell and use specific features
target_link_options(${PROJECT_NAME} PRIVATE "-O3")

# 3(contd). This is what makes it output .html instead of a binary
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
###############################
cmake_minimum_required(VERSION 3.10)
project(narayan_lib)

# - Step 3: narayan library's target is defined
add_library(narayan STATIC src/narayan.cpp)
# - Step 3 (cont'd): Set include directories for the library
target_include_directories(narayan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

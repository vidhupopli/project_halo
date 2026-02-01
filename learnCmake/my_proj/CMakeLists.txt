# Process of what is being configured to happen
# - Step 1: cmake starts from build folder in the my_proj directory
cmake_minimum_required(VERSION 3.10)
project(my_project)

# - Step 2: This line tells cmake to process nlibrary/CMakeLists.txt
add_subdirectory(nlibrary)

# - Step 4: Back in root CMakeLists.txt, create an executable from main.cpp
add_executable(my_project src/main.cpp)

# - Step 5: Link the narayan library to the executable
target_link_libraries(my_project narayan)



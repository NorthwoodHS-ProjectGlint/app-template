cmake_minimum_required(VERSION 3.16)
project(my_game)
set(CMAKE_CXX_STANDARD 17)

# Find dependencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLINT REQUIRED glint)
pkg_check_modules(GLFW REQUIRED glfw3)

# Build the shared library
add_library(my_game SHARED
    src/main.cpp
)

# Include directories
target_include_directories(my_game PRIVATE
    ${GLINT_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(my_game
    ${GLINT_LIBRARIES}
    ${GLFW_LIBRARIES}
)

# Package into .glt file
add_custom_target(run_glt_my_game ALL
    COMMAND glt_execcreate $<TARGET_FILE:my_game> ${CMAKE_CURRENT_SOURCE_DIR}/.titleconfig
    DEPENDS my_game
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
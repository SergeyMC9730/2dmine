cmake_minimum_required(VERSION 3.0.0)
project(elgarenta VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(raylib)

add_library(elgarenta 
    src/test.c
)
target_link_libraries(elgarenta raylib)
target_include_directories(elgarenta PRIVATE include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.10)
project(jpeg-endianness-tests  CXX)
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)


add_compile_options(-Wall -Wextra -Wpedantic -Werror)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        add_compile_options(-O0)
        add_compile_options(-g)
endif()



#add_library(initialization 
#    ${PROJECT_SOURCE_DIR}/initialization/*
#)

add_subdirectory(src)
add_subdirectory(tests)
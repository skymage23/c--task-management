cmake_minimum_required(VERSION 3.10)
project(cplusplus-task-management  CXX)
include(cmake_build_system_message.cmake)

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

#Test helper scripts before anything else.
add_subdirectory(scripts)

add_subdirectory(scripts/os_helpers)

find_package(Python3 REQUIRED COMPONENTS Interpreter)


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

#add_subdirectory(src)
#add_subdirectory(tests)
#add_subdirectory(Documentation)


#include(scripts/cmake/gen_launch_json_args.cmake)
add_custom_target(generate_launch_json
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/.vscode
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/generate_launch_json.py 
        ${LAUNCH_JSON_ARG_STRING}
        > ${CMAKE_SOURCE_DIR}/.vscode/launch.json
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_NAME ${CMAKE_SOURCE_DIR}/.vscode/launch.json
    COMMENT "Generating launch.json for VS Code debugging"
)

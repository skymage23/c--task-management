include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/common.cmake)
include(common.cmake)

set(BUILD_DIR_PATH "${CMAKE_CURRENT_LIST_DIR}/build")

if(NOT EXISTS "${BUILD_DIR_PATH}")
    make_directory("${BUILD_DIR_PATH}")
endif()

execute_process( COMMAND ${CMAKE_COMMAND}  ${TEST_HELPERS_DIR}/test_get_dirs_with_cmake_lists_timeout/CMakeLists.txt
    TIMEOUT 1s
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build
    COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
)

file(REMOVE_RECURSE "${BUILD_DIR_PATH}")


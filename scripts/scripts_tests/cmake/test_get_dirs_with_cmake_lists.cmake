cmake_minimum_required(VERSION 3.10)
include(${CMAKE_CURRENT_LIST_DIR}/common.cmake)
message(STATUS "${HELPERS_DIR}")
execute_process( COMMAND ${CMAKE_COMMAND} -P ${HELPERS_DIR}/timeout_test_get_dirs_with_cmake_lists.cmake
    TIMEOUT 1s
    COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
)

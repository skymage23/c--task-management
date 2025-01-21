include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/common.cmake)
include(common.cmake)

execute_process( COMMAND ${CMAKE_COMMAND}  ${TEST_HELPERS_DIR}/timeout_test_get_dirs_with_cmake_lists/CMakeLists.txt
    TIMEOUT 1s
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build
    COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
)

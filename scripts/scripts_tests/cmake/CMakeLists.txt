set (CMAKE_SCRIPTS_DIR "${CMAKE_SOURCE_DIR}/scripts/scripts_tests/cmake")

execute_process(COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SCRIPTS_DIR}/test_get_dirs_with_cmake_lists.cmake
   WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
   COMMAND_ECHO STDOUT
   COMMAND_ERROR_IS_FATAL ANY
)

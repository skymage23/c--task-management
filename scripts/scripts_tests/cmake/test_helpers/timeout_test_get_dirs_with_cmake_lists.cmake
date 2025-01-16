include(${CMAKE_CURRENT_LIST_DIR}/../common.cmake)
include(${SCRIPTS_DIR}/dir_opts.cmake)
message(STATUS "SCRIPTS_DIR: ${SCRIPTS_DIR}")
get_subdirectories_with_cmake_lists_txt(${SCRIPTS_DIR}/scripts_tests)

if(NOT ${GET_SUBDIRECTORIES_OUTPUT} MATCHES cmake)
    message(FATAL "${CMAKE_CURRENT_LIST_FILE}" )
endif()





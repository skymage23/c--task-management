cmake_minimum_required(VERSION 3.31)
project(cmake_script_tests)
#
# Here, we are mainly concerned with testing the CMake scripts.
# For testing purposes, we make up some nonsense targets
#


add_subdirectory(custom_targets)

include(test_get_dirs_with_cmake_lists.cmake)

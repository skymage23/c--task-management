cmake_minimum_required(VERSION 3.10)
include(os_host_setup.cmake)

#look_for_dependency_program()
get_realpath("$ENV{HOME}/Documents")
message(STATUS "REALPATH: ${REALPATH}")
#message(STATUS "PRG: ${PRG}")

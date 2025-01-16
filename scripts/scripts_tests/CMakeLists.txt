message(STATUS "Running tests of script files. If any of these file, so will the build configuration.")

#Test CMake files first.
#The build depends on these foremost.
add_subdirectory(cmake)

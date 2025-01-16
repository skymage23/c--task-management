
include(${CMAKE_SOURCE_DIR}/scripts/cmake/stack.cmake)

# Iterate over all targets in the projecti

#set(DIRECTORIES)
#get_property(DIRECTORIES DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY SUBDIRECTORIES)
#message(STATUS "DIRECTORIES: ${DIRECTORIES}")

function(get_realpath PATH)
    set(GET_REALPATH_OUTPUT "" PARENT_SCOPE)
    execute_process(
        COMMAND /usr/bin/realpath
    )
endfunction()


function(get_subdirectories_with_cmake_lists_txt DIRECTORY)
    set(GET_SUBDIRECTORIES_OUTPUT "" PARENT_SCOPE)
    set(STACK "STACK")
    set(STACK_EMPTY FALSE)
    stack_init(STACK)
    set(SUBDIRECTORIES)
    get_property(SUBDIRECTORIES DIRECTORY "${DIRECTORY}" PROPERTY SUBDIRECTORIES)
    foreach(SUBDIRECTORY ${SUBDIRECTORIES})
        if(EXISTS "${SUBDIRECTORY}/CMakeLists.txt")
            stack_push(STACK ${SUBDIRECTORY})
        endif()
    endforeach()
    stack_is_empty(STACK_NAME STACK STACK_EMPTY)
    while(NOT STACK_EMPTY)
        stack_pop(STACK SUBDIRECTORY)
        if(EXISTS "${SUBDIRECTORY}/CMakeLists.txt")
            set(SUBDIRECTORIES ${SUBDIRECTORIES} ${SUBDIRECTORY})
            foreach(SUBDIRECTORY ${SUBDIRECTORIES})
                stack_push(STACK ${SUBDIRECTORY})
            endforeach()
        endif()
    endwhile()
    set(${GET_SUBDIRECTORIES_OUTPUT} ${SUBDIRECTORIES} PARENT_SCOPE)
endfunction()


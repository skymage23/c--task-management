include_guard(GLOBAL)

#Universal dependencies:
find_package(Python3)
#preliminary universal functions

function(find_dependency_program PROGRAM_NAME)
    find_program(PROGRAM_FOUND ${PROGRAM_NAME})
    if(PROGRAM_FOUND)
        set(PROGRAM_FOUND TRUE PARENT_SCOPE)
    endif()
endfunction()

function(look_for_dependency_program)
    unset(FOUND_ALTERNATIVE PARENT_SCOPE)
    list(LENGTH ARGN ARG_LEN_OUTPUT)
    if(ARG_LEN_OUTPUT LESS 1)
        message(FATAL_ERROR "No arguments passed.")
    endif()
    unset(FOUND_ALTERNATIVE)
    foreach(ALTERNATIVE ${ARGN})
        #find_dependency_program(${ALTERNATIVE})
	find_program(PROGRAM_FOUND ${ALTERNATIVE})
        if(PROGRAM_FOUND)
	    set(FOUND_ALTERNATIVE "${PROGRAM_FOUND}" PARENT_SCOPE)
    	    return()
        endif()
    endforeach()
endfunction()

#Host OS specific setup:
if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    #Dependencies
    look_for_dependency_program("powershell" "pwsh")
    if(NOT FOUND_ALTERNATIVE)
        message(FATAL_ERROR "PowerShell not found.")
    endif()
    set(POWERSHELL_COMMAND ${FOUND_ALTERNATIVE})
                                	
elseif( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")

else()
    message(FATAL_ERROR "\"${CMAKE_HOST_SYSTEM_NAME}\" is not a supported build host OS.")
endif()

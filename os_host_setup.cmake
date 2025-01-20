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
                                
    #OS-specific functions:
    function (get_realpath RELATIVE_PATH)
	    execute_process(
                COMMAND ${POWERSHELL_COMMAND} -Command "$(Resolve-Path -Path \"${RELATIVE_PATH}\").Path"
		OUTPUT_VARIABLE REALPATH
		COMMAND_ECHO STDOUT
		COMMAND_ERROR_IS_FATAL ANY
	    )
	    if(NOT REALPATH)
	        message(FATAL_ERROR "Unable to resolve path \"${RELATIVE_PATH}\".")
	    endif()
	    set(REALPATH ${REALPATH} PARENT_SCOPE)
    endfunction()       	
                        	
elseif( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
    #dependencies:
    look_for_dependency_program("realpath")
    if(NOT FOUND_ALTERNATIVE)
        message(FATAL_ERROR "\"realpath\" not found.")
    endif()
    #OS-specific functions:
    set(REALPATH_COMMAND ${FOUND_ALTERNATIVE})
    function (get_realpath RELATIVE_PATH)
	    execute_process(
	        COMMAND ${REALPATH_COMMAND} "${RELATIVE_PATH}"
		RESULT_VARIABLE RESULT_CODE
		OUTPUT_VARIABLE REALPATH
		COMMAND_ECHO STDOUT
	    )
	    if(NOT REALPATH OR NOT RESULT_CODE EQUAL 0)
		    message(FATAL_ERROR "Unable to resolve path \"${RELATIVE_PATH}\". Result code: ${RESULT_CODE}")
	    endif()
	    set(REALPATH ${REALPATH} PARENT_SCOPE)
    endfunction()
else()
    message(FATAL_ERROR "\"${CMAKE_HOST_SYSTEM_NAME}\" is not a supported build host OS.")
endif()

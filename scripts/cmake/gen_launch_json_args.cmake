include(${CMAKE_SOURCE_DIR}/scripts/cmake/dir_opts.cmake)
# Create a list to store executable names

set(GET_TARGETS_OUTPUT)
function(get_targets_launch_json_args DIRECTORY)
    set(JSON_TARGET_PROPERTIES)
    set(JSON_ARG_STRING)
    set(TARGET_NAME)
    set(TARGET_BINARY_PATH)
    set(TARGET_LAUNCH_TYPE)
    message(STATUS "DIRECTORY: ${DIRECTORY}")
    get_property(TARGETS DIRECTORY "${DIRECTORY}" PROPERTY BUILDSYSTEM_TARGETS)
    foreach(TARGET ${TARGETS})
        # Check if the target is an executable
        message(STATUS "TARGET: ${TARGET}")
        get_target_property(TARGET_TYPE ${TARGET} TYPE)
        if(TARGET_TYPE STREQUAL "EXECUTABLE")
            set(TARGET_NAME ${TARGET})
            get_target_property(TARGET_BINARY_PATH ${TARGET} LOCATION)
    
            if(TARGET_BINARY_PATH MATCHES "tests")
                set(TARGET_LAUNCH_TYPE "test")
            else()
                set(TARGET_LAUNCH_TYPE "release")
            endif()
    
            set(JSON_TARGET_PROPERTIES ${TARGET_BINARY_PATH},${TARGET_NAME},${TARGET_LAUNCH_TYPE})
            set(JSON_ARG_STRING ${JSON_ARG_STRING} ${JSON_TARGET_PROPERTIES})
        endif()
    endforeach()
    set(${GET_TARGETS_OUTPUT} ${JSON_ARG_STRING} PARENT_SCOPE)
endfunction()

get_subdirectories_with_cmake_lists_txt(${CMAKE_SOURCE_DIR})
message(STATUS "SUBDIRECTORIES: ${SUBDIRECTORIES}")

foreach(VAR ${GET_SUBDIRECTORIES_OUTPUT})
   message(STATUS "VAR: ${VAR}")
endforeach()
#get_targets_launch_json_args(${CMAKE_SOURCE_DIR}/src)
#set(LAUNCH_JSON_ARG_STRING ${GET_TARGETS_OUTPUT})

#get_targets_launch_json_args(${CMAKE_SOURCE_DIR}/tests)
#set(LAUNCH_JSON_ARG_STRING ${LAUNCH_JSON_ARG_STRING} ${GET_TARGETS_OUTPUT})

message(STATUS "LAUNCH_JSON_ARG_STRING: ${LAUNCH_JSON_ARG_STRING}")

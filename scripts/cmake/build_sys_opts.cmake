include_guard(GLOBAL)
include(common.cmake)
include(${CMAKE_SCRIPTS_DIR}/debug.cmake)
include(${CMAKE_SCRIPTS_DIR}/dir_opts.cmake)

function(get_targets_list_under_dir DIRECTORY)
    set(DIR_LIST "")
    set(TARGET_LIST "")
    assert_is_directory("${DIRECTORY}")
    get_subdirectories_with_cmake_lists_txt(${DIRECTORY})
    set(DIR_LIST GET_SUBDIRECTORIES_OUTPUT)

    foreach(VAR ${DIR_LIST)){

    }
endfunction()

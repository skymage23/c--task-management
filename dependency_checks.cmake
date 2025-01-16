find_package(Python3)

if(${CMAKE_HOST_SYSTEM_NAME} == "Windows")
    find_package(PowerShell)
elseif(${CMAKE_HOST_SYSTEM_NAME} == "Linux")
    #Make sure "realpath" exists:
    if(NOT IS_EXECUTABLE "/usr/bin/realpath")
         message(FATAL "\"realpath\" not found in \"/usr/bin\".")
    endif()
#elseif(${CMAKE_HOST_SYSTEM_NAME} == "macOS")
endif()

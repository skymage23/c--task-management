find_package(Doxygen REQUIRED dot OPTIONAL_COMPONENTS mscgen dia)

if(NOT DOXYGEN_FOUND)
    message(WARN "Doxygen not found. Documentation cannot be built")
    return() 
endif()

message(STATUS "Doxygen: ${DOXYGEN_FOUND}, Version: ${DOXYGEN_VERSION}")
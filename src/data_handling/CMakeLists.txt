add_library(vectorwrapping OBJECT
    ${CMAKE_CURRENT_LIST_DIR}/vectorwrapper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/vectorreadwrapperiterator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/vectorwritewrapper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/vectorwrapperiteratorbase.cpp
    ${CMAKE_CURRENT_LIST_DIR}/vectorwrapper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/vectorreadwrapper.cpp
   # ${CMAKE_CURRENT_LIST_DIR}/serialization.cpp
   # ${CMAKE_CURRENT_LIST_DIR}/datahouse.cpp
)

target_include_directories(vectorwrapping
    INTERFACE ${CMAKE_SOURCE_DIR}/include
)
add_library(tasks OBJECT
    ${CMAKE_CURRENT_LIST_DIR}/task.cpp
)

target_include_directories(tasks 
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)
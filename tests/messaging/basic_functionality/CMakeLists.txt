add_executable(message_passing
    ${CMAKE_CURRENT_LIST_DIR}/message_passing.cpp
)
message(STATUS ${CMAKE_SOURCE_DIR})
target_include_directories(message_passing
   PRIVATE ${CMAKE_SOURCE_DIR}/include
   PRIVATE ${CMAKE_SOURCE_DIR}/tests/third_party/googletest/googletest/include
)

target_link_libraries(message_passing
   PUBLIC messaging
   PUBLIC GTest::gtest_main
)
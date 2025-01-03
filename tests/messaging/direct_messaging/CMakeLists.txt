
add_executable(direct_message_passing
    ${CMAKE_CURRENT_LIST_DIR}/message_passing.cpp
)

target_include_directories(direct_message_passing
   PRIVATE ${CMAKE_SOURCE_DIR}/include
   PRIVATE ${CMAKE_SOURCE_DIR}/tests/third_party/googletest/googletest/include
)

target_link_libraries(direct_message_passing
   PUBLIC messaging
   PUBLIC GTest::gtest_main
)
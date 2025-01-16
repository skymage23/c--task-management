add_executable(vectorwrappers_test
    ${CMAKE_CURRENT_LIST_DIR}/vectorwrappertests.cpp
    ${CMAKE_CURRENT_LIST_DIR}/vectorreadwrappertests.cpp
    ${CMAKE_CURRENT_LIST_DIR}/vectorwritewrappertests.cpp
)

target_sources(vectorwrappers_test
    PRIVATE $<TARGET_PROPERTY:vectorwrapping,SOURCES>
)

target_include_directories(vectorwrappers_test
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PUBLIC ${CMAKE_SOURCE_DIR}/tests/include
)

target_link_libraries(vectorwrappers_test
    gtest
    gtest_main
)

target_compile_definitions(vectorwrappers_test
    PRIVATE TESTING_MODE
)

gtest_discover_tests(
    vectorwrappers_test
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    TEST_PREFIX "test_"
)

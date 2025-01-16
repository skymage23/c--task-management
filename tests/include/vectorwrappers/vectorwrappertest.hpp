#ifndef CPP_TASK_MANAGEMENT_TESTS_INCLUDE_VECTORWRAPPERTEST_HPP
#define CPP_TASK_MANAGEMENT_TESTS_INCLUDE_VECTORWRAPPERTEST_HPP

#include <gtest/gtest.h>
#include <memory>
#include <vector>

#define TEST_ENABLE_MOVE_CHECK
#include <data_handling/vectorwrapper.hpp>

class VectorWrapperTest : public ::testing::Test {
    protected:
    std::shared_ptr<std::vector<char>> test_vec;

    protected:
    void SetUp() override;

    public:
    void test_move_validity();  // Declaration of friend method
};
#endif
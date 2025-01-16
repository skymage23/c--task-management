#ifndef CPP_TASK_MANAGEMENT_TESTS_INCLUDE_VECTORREADWRAPPERTEST_HPP
#define CPP_TASK_MANAGEMENT_TESTS_INCLUDE_VECTORREADWRAPPERTEST_HPP

#include <gtest/gtest.h>
#include <memory>
#include <vector>

#include <data_handling/vectorreadwrapper.hpp>

class VectorReadWrapperTest : public ::testing::Test {

    protected:
    std::shared_ptr<std::vector<char>> test_vec;

    protected:
    void SetUp() override;

    public:
    void test_read_validity();
    void test_bounds_check();
    void test_iterator_validity();
    void test_range_validity();
};

#endif
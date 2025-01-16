#ifndef CPP_TASK_MANAGEMENT_TESTS_INCLUDE_VECTORWRITEWRAPPERTEST_HPP
#define CPP_TASK_MANAGEMENT_TESTS_INCLUDE_VECTORWRITEWRAPPERTEST_HPP

#include <gtest/gtest.h>
#include <memory>
#include <vector>

class VectorWriteWrapperTest : public ::testing::Test {

    protected:
    std::shared_ptr<std::vector<char>> test_vec;

    protected:
    void SetUp() override;

    public:
    void test_write_validity();
    void test_sequential_writes(); 
};

#endif
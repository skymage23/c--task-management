#include <gtest/gtest.h>
#include <memory>
#include <vector>

#define TEST_ENABLE_MOVE_CHECK
#include <data_handling/vectorwrapper.hpp>
#include <vectorwrappers/vectorwrappertest.hpp>

void VectorWrapperTest::SetUp() {
    test_vec = std::make_shared<std::vector<char>>();
    for (char i = 0; i < 10; i++) {
        test_vec->push_back(i);
    }
}

void VectorWrapperTest::test_move_validity() {
    task_mgmt::datacollection::VectorWrapper wrapper1(test_vec);
    task_mgmt::datacollection::VectorWrapper wrapper2(std::move(wrapper1));
    ASSERT_NE(wrapper2.internal_vector, nullptr);
}

TEST_F(VectorWrapperTest, test_move_constructor) {
    this -> test_move_validity();
}
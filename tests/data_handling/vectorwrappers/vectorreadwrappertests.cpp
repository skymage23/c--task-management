#include <gtest/gtest.h>
#include <memory>
#include <vector>

#include <data_handling/vectorreadwrapper.hpp>
#include <vectorwrappers/vectorreadwrappertest.hpp>

void VectorReadWrapperTest::SetUp() {
    test_vec = std::make_shared<std::vector<char>>();
    for (unsigned char i = 0; i < 10; i++) {
        test_vec->push_back(i);
    }
}


void VectorReadWrapperTest::test_read_validity() {
    task_mgmt::datacollection::VectorReadWrapper wrapper(test_vec, 2, 5);
    ASSERT_EQ(static_cast<char>(wrapper[0]), 2);
    ASSERT_EQ(static_cast<char>(wrapper[2]), 4);
}

void VectorReadWrapperTest::test_bounds_check() {
    task_mgmt::datacollection::VectorReadWrapper wrapper(test_vec, 2, 5);
    ASSERT_THROW(wrapper[3], std::out_of_range);
    ASSERT_THROW(wrapper[-1], std::out_of_range);
}

void VectorReadWrapperTest::test_iterator_validity() {
    task_mgmt::datacollection::VectorReadWrapper wrapper(test_vec, 2, 5);
    size_t count = 0;
    for (char c : wrapper) {
        std::cout << "c: " << static_cast<int>(c) << std::endl;
        ASSERT_EQ(static_cast<char>(c), count + 2);
        count++;
    }
    ASSERT_EQ(count, 3); // Should iterate 3 times (5-2)
}

void VectorReadWrapperTest::test_range_validity() {
    ASSERT_THROW(
        task_mgmt::datacollection::VectorReadWrapper(test_vec, 5, 2),
        std::invalid_argument
    );
    ASSERT_THROW(
        task_mgmt::datacollection::VectorReadWrapper(test_vec, 0, 11),
        std::out_of_range
    );
}

TEST_F(VectorReadWrapperTest, test_read) {
    test_read_validity();
}

TEST_F(VectorReadWrapperTest, test_bounds) {
    test_bounds_check();
}

TEST_F(VectorReadWrapperTest, test_iterator) {
    test_iterator_validity();
}

TEST_F(VectorReadWrapperTest, test_range) {
    test_range_validity();
}
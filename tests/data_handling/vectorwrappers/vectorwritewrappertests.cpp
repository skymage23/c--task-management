#include <gtest/gtest.h>
#include <memory>
#include <vector>

#define TEST_ENABLE_WRITE_CHECK
#include <data_handling/vectorwritewrapper.hpp>
#include <vectorwrappers/vectorwritewrappertest.hpp>

void VectorWriteWrapperTest::SetUp() {
    test_vec = std::make_shared<std::vector<char>>();
}


void VectorWriteWrapperTest::test_write_validity() {
    task_mgmt::datacollection::VectorWriteWrapper wrapper(test_vec);
    wrapper.append(static_cast<char>(0xFF));
    ASSERT_EQ(wrapper.internal_vector->size(), 1);
    ASSERT_EQ(
        static_cast<unsigned char>((*wrapper.internal_vector)[0]),
        static_cast<char>(0xFF)
    );
}

void VectorWriteWrapperTest::test_sequential_writes() {
    task_mgmt::datacollection::VectorWriteWrapper wrapper(test_vec);
    const unsigned char test_values[] = {0x00, 0xFF, 0x7F, 0x80};   
    for(unsigned char val : test_values) {
        wrapper.append(val);
    }
    
    ASSERT_EQ(wrapper.internal_vector->size(), 4);
    for(size_t i = 0; i < 4; ++i) {
        ASSERT_EQ(static_cast<unsigned char>((*wrapper.internal_vector)[i]), test_values[i]);
    }
}

TEST_F(VectorWriteWrapperTest, test_append) {
    test_write_validity();
}

TEST_F(VectorWriteWrapperTest, test_multiple_appends) {
    test_sequential_writes();
}
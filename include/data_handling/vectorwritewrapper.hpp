#ifndef CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORWRITEWRAPPER_HPP
#define CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORWRITEWRAPPER_HPP

#include <data_handling/vectorwrapper.hpp>

#ifdef TESTING_MODE
    #include <vectorwrappers/vectorwritewrappertest.hpp>
#endif

namespace task_mgmt {
    namespace datacollection {
        class VectorWriteWrapper : VectorWrapper { 
            #ifdef TESTING_MODE
                #ifdef TEST_ENABLE_WRITE_CHECK
                    friend void VectorWriteWrapperTest::test_write_validity();
                    friend void VectorWriteWrapperTest::test_sequential_writes();
                #endif
            #endif

            public:
            VectorWriteWrapper(
                std::shared_ptr<std::vector<char>> vec
            );
            VectorWriteWrapper(VectorWriteWrapper&& input);
            void append(char input);
        };
    };
 };
#endif
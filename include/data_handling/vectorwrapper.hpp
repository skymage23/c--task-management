#ifndef CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORWRAPPER_HPP
#define CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORWRAPPER_HPP

#include <memory>
#include <vector>

#ifdef TESTING_MODE
#include <vectorwrappers/vectorwrappertest.hpp>
#endif

namespace task_mgmt {
    namespace datacollection {
        class VectorWrapper {
            #ifdef TESTING_MODE
            #ifdef TEST_ENABLE_MOVE_CHECK
                friend void VectorWrapperTest::test_move_validity();
            #endif
            #endif

            protected:
            std::shared_ptr<std::vector<char>> internal_vector;
            size_t start_index;
            size_t end_index;
            size_t range_size;
            public:
            VectorWrapper(
                std::shared_ptr<std::vector<char>> vec
            );

            VectorWrapper(VectorWrapper&& input);
            char* get_element_address(size_t place);
            size_t size() const;
        };
    };
 };
#endif
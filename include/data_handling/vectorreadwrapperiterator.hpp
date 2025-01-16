#ifndef CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORREADWRAPPERITERATOR_HPP
#define CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORREADWRAPPERITERATOR_HPP

#include <data_handling/vectorwrapper.hpp>
#include <data_handling/vectorwrapperiteratorbase.hpp>

namespace task_mgmt {
    namespace datacollection {

        class VectorReadWrapperIterator : public VectorWrapperIteratorBase {
            //typedefs:
            using value_type = char;
            using difference_type = std::ptrdiff_t;
            using reference = char&;
            using pointer = char*;

            private:
            VectorWrapper *internal_collection;

            private:
            VectorReadWrapperIterator (
                VectorWrapper *input,
                size_t place,
                size_t range_size
            );
            friend class VectorReadWrapper;
            #ifdef TESTING
            friend class VectorReadWrapperIteratorTest;
            #endif

            public:
            VectorReadWrapperIterator(VectorReadWrapperIterator& input);
            VectorReadWrapperIterator(VectorReadWrapperIterator&& input);
            reference operator*();
        };
    };
 };
#endif
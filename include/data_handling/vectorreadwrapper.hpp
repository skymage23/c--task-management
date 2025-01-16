#ifndef CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORREADWRAPPER_HPP
#define CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORREADWRAPPER_HPP

#include <data_handling/vectorwrapper.hpp>
#include <data_handling/vectorreadwrapperiterator.hpp>
namespace task_mgmt {
    namespace datacollection {
        class VectorReadWrapper : public VectorWrapper {
            private:
            size_t start_index;
            size_t range_size;
            size_t end_index;

            public:
            VectorReadWrapper(
                std::shared_ptr<std::vector<char>> vec,
                size_t start_index,
                size_t end_index 
            );

            VectorReadWrapper(VectorReadWrapper& input);
            VectorReadWrapper(VectorReadWrapper&& input);
            
            char* get_element_address(size_t index);
            char operator[](size_t input);
            size_t size();
            VectorReadWrapperIterator begin();
            VectorReadWrapperIterator end();
            std::string to_string();
        };
    };
 };
#endif
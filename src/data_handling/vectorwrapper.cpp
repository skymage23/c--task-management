#include <data_handling/vectorwrapper.hpp>

namespace task_mgmt {
    namespace datacollection {
        VectorWrapper::VectorWrapper(
            std::shared_ptr<std::vector<char>> vec
        ) : internal_vector(vec){}

        VectorWrapper::VectorWrapper(VectorWrapper&& input) : 
            internal_vector(input.internal_vector),
            start_index(input.start_index),
            end_index(input.end_index),
            range_size(input.range_size)
        {}


        char* VectorWrapper::get_element_address(size_t index){
            if (index > this -> range_size){
                throw std::out_of_range("index");
            }
            return this -> internal_vector -> data() + index;
        }

        size_t VectorWrapper::size() const {
            return this -> range_size;
        }
    };
 };
#include <stdexcept>

#include <data_handling/vectorreadwrapper.hpp>
#include <data_handling/vectorreadwrapperiterator.hpp>

namespace task_mgmt {
    namespace datacollection {
        VectorReadWrapper::VectorReadWrapper(
            std::shared_ptr<std::vector<char>> vec,
            size_t start_index,
            size_t end_index
        ) : VectorWrapper(vec), start_index(start_index),end_index(end_index){
            if (end_index <= start_index){
                //Need custom error here.
                throw std::range_error("end_index <= start_index");
            }
            this -> range_size = end_index - start_index;
        }

       /* char* VectorReadWrapper::get_char_address(size_t index){

            if ((index < 0) || (index >= this -> range_size)){
                throw std::invalid_argument();
            }
            index = index + start_index;
            return &( this -> internal_vector -> [index]);
        }*/

        char* VectorReadWrapper::get_element_address(size_t index){
            if (index >= this -> range_size){
                throw std::out_of_range("index");
            }
            index = index + start_index;
            return this -> internal_vector -> data() + index;
        }

        char VectorReadWrapper::operator[](size_t index){
            if (index >= this -> range_size)
            { 
                throw std::out_of_range("index");
            }

            return this -> internal_vector -> at(
                    this -> start_index + index
                );
        }

        VectorReadWrapperIterator VectorReadWrapper::begin() {
            return VectorReadWrapperIterator(
                dynamic_cast<VectorWrapper*>(this), 
                0, 
                this -> range_size
            );
        }

        VectorReadWrapperIterator VectorReadWrapper::end() {
            return VectorReadWrapperIterator(
                dynamic_cast<VectorWrapper*>(this), 
                this -> range_size, 
                this -> range_size
            );
        }
    };
 };
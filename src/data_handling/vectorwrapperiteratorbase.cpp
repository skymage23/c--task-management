#include <iterator>
#include <memory>
#include <stdexcept>

#include <data_handling/vectorwrapperiteratorbase.hpp>
 
 namespace task_mgmt {
    namespace datacollection {
        VectorWrapperIteratorBase::VectorWrapperIteratorBase(
            size_t index,
            size_t range_size
        ) : place(index), range_size(range_size){
            if (this -> place >= this -> range_size + 1){
                throw std::out_of_range("index: " + std::to_string(index) + 
                " is outside of the allowed range: " + std::to_string(range_size));
            }
        }

        VectorWrapperIteratorBase::VectorWrapperIteratorBase(
            VectorWrapperIteratorBase& input
        ) : place(input.place), range_size(input.range_size){
            if (this -> place >= this -> range_size + 1){
                throw std::out_of_range("input.place is outside of the allowed range.");
            }
        }

        VectorWrapperIteratorBase::VectorWrapperIteratorBase(
            VectorWrapperIteratorBase&& input
        ) : place(input.place), range_size(input.range_size){
            if (this -> place >= this -> range_size){
                throw std::out_of_range("input.place is outside of the allowed range.");
            }
        }

        VectorWrapperIteratorBase& VectorWrapperIteratorBase::operator++(){
            if (this -> place > this -> range_size){
                throw std::out_of_range("Unable to increment iterator further.");
            }

            ++(this -> place);
            return *this;
        }
    };
 };
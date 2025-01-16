#include <iterator>
#include <memory>
#include <stdexcept>

#include <data_handling/vectorwrapper.hpp>
#include <data_handling/vectorreadwrapperiterator.hpp>
 
 namespace task_mgmt {
    namespace datacollection {
        using iterator_category = std::forward_iterator_tag;
        using value_type = char;
        using difference_type = std::ptrdiff_t;
        using pointer = char*;
        using reference = char&;

        VectorReadWrapperIterator::VectorReadWrapperIterator(
            VectorWrapper *input,
            size_t place,
            size_t range_size
        ) : VectorWrapperIteratorBase(place, range_size), internal_collection(input){}

        reference VectorReadWrapperIterator::operator*(){
            return *(this -> internal_collection -> get_element_address(
                this -> place
            ));
        }
    };
 };
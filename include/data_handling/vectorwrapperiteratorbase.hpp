#ifndef CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORWRAPPERITERATORBASE_HPP
#define CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_VECTORWRAPPERITERATORBASE_HPP

#include <iterator>
namespace task_mgmt {
    namespace datacollection {

        //This custom iterator is to help provide
        //the illusion that the user of VectorReadWrapper
        //is working directly on the underlying vector,
        //hiding the fact that they are only allowed
        //to touch a segment of it.


        class VectorWrapperIteratorBase {
            //typedefs:
            protected:
            using iterator_category = std::forward_iterator_tag;

            //Friends:
            friend bool operator==(
                VectorWrapperIteratorBase &lhs,
                VectorWrapperIteratorBase& rhs
            );

            friend bool operator!=(
                VectorWrapperIteratorBase& lhs,
                VectorWrapperIteratorBase& rhs
            );

            friend bool operator<(
                VectorWrapperIteratorBase& lhs,
                VectorWrapperIteratorBase& rhs
            );

            friend bool operator>(
                VectorWrapperIteratorBase& lhs,
                VectorWrapperIteratorBase& rhs
            );

            friend bool operator<=(
                VectorWrapperIteratorBase& lhs,
                VectorWrapperIteratorBase& rhs
            );

            friend bool operator>=(
                VectorWrapperIteratorBase& lhs,
                VectorWrapperIteratorBase& rhs
            );

            protected:
            size_t place;
            size_t range_size;
            
            protected:
            VectorWrapperIteratorBase(
                size_t place,
                size_t range_size
            );

            public:
            VectorWrapperIteratorBase() = delete;
            VectorWrapperIteratorBase(VectorWrapperIteratorBase& input);
            VectorWrapperIteratorBase(VectorWrapperIteratorBase&& input);
            VectorWrapperIteratorBase& operator++();
        };


        inline bool operator==(
            VectorWrapperIteratorBase& lhs,
            VectorWrapperIteratorBase& rhs
        ) {
            return lhs.place == rhs.place;
        }

        inline bool operator!=(
            VectorWrapperIteratorBase& lhs,
            VectorWrapperIteratorBase& rhs
        ){
            return !(lhs == rhs);
        };

        inline bool operator<(
            VectorWrapperIteratorBase& lhs,
            VectorWrapperIteratorBase& rhs
        ){
            return lhs.place < rhs.place;
        };

        inline bool operator>(
            VectorWrapperIteratorBase& lhs,
            VectorWrapperIteratorBase& rhs
        ){
            return lhs.place > rhs.place;
        };

        inline bool operator<=(
            VectorWrapperIteratorBase& lhs,
            VectorWrapperIteratorBase& rhs
        ){
            return !(lhs > rhs);
        };

        inline bool operator>=(
            VectorWrapperIteratorBase& lhs,
            VectorWrapperIteratorBase& rhs
        ){
            return !(lhs < rhs);
        };
    };
 };
#endif
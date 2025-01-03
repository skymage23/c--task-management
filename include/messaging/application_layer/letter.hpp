#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_APPLICATION_LAYER_LETTER_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_APPLICATION_LAYER_LETTER_HPP

#include <messaging/application_layer/baseletter.hpp>
namespace task_mgmt {
    namespace messaging {
        //T = exposed data type.
        //D = internal data type.
        template <class T, class D = T> class Letter : BaseLetter {
            protected:
            D data;

            public:
            T extract(){ return this -> data; };
        };

        template <class T> class UnitypeLetter : Letter<T> {
            public:
            UnitypeLetter(T input) : data(input){}
            T extract() { return this -> data; }
        };

        class ByteLetter : UnitypeLetter<char>{
            public:
            ByteLetter(char input) : UnitypeLetter(input){}
        };

        class IntLetter : UnitypeLetter<int>{
            public:
            IntLetter(int input) : UnitypeLetter(input){}  
        };

        class LongLetter : UnitypeLetter<long>{
            public:
            LongLetter(long input) : UnitypeLetter(input){}
        };

        class LongLongLetter : UnitypeLetter<long long>{
            public:
            LongLongLetter(long long input) : UnitypeLetter(input){}
        };

        class ShortLetter : UnitypeLetter<short>{
            public:
            ShortLetter(short input) : UnitypeLetter(input){}
        };

        class UnsignedByteLetter : UnitypeLetter<unsigned char>{
            public:
            UnsignedByteLetter(unsigned char input): UnitypeLetter(input){}
        };

        class UnsignedIntLetter : UnitypeLetter<unsigned int>{
            public:
            UnsignedIntLetter(unsigned int input) : UnitypeLetter(input){}
        };

        class UnsignedLongLetter : UnitypeLetter<unsigned long>{
            public:
            UnsignedLongLetter(unsigned long input) : UnitypeLetter(input){}
        };

        class UnsignedLongLongLetter : UnitypeLetter<unsigned long long>{
            public:
            UnsignedLongLongLetter(
                unsigned long long input
            ) : UnitypeLetter(input){}
        };

        class UnsignedShortLetter : UnitypeLetter<unsigned short>{
            public:
            UnsignedShortLetter(unsigned short input) : UnitypeLetter(input){}
        };

        class BoolLetter : UnitypeLetter<bool>{
            public:
            BoolLetter(bool input) : UnitypeLetter(input){}
        };

        class FloatLetter : UnitypeLetter<float>{
            public:
            FloatLetter(float input) : UnitypeLetter(input){}
        };

        class DoubleLetter : UnitypeLetter<double>{
            public:
            DoubleLetter(double input) : UnitypeLetter(input){}
        };
    };
};

#endif
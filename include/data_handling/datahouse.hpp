#ifndef CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_DATAHOUSE_HPP
#define CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_DATAHOUSE_HPP

#include <any>
#include <string>
#include <unordered_map>
#include <vector>

#include <data_handling/vectorwrapper.hpp>
#include <data_handling/vectorwritewrapper.hpp>
#include <data_handling/vectorreadwrapper.hpp>
#include <data_handling/serialization.hpp>


    //
    // Let me explain how this works because it is a bit unsize_tuitive.
    // This is a general purpose data collection that
    // can accept data of any type. It's purpose is to provide
    // a way for child Tasks to return values to their parents.
    // It also has the added benefit of being serializable
    // (provided that all entries with non-trivial datatypes
    // have associated SerializationHelper objects provided
    // by the library user), making it usable for dumping.
    // values to disk when the program is size_terrupted
    // and then later restoring them.
    //

    //
    // The wrapper objects wrap the underlying vector in a manner
    // that restricts their owners to only be allowed to read
    // certain elements out of the vector, but doing so while
    // giving the illusion that the wrapper IS the vector.
    // This is to make serialization and deserialization seamless
    // by allowing developers to use for loops to iterate over
    // the serialization and deserialization processes, as they
    // would understandibly want to do due to reasons of simplicity.
    //

namespace task_mgmt {
    namespace datacollection {
        //I COULD make a base class with a "do everything" method.
        //We are going to use type-erasure, but we are going to do so
        //using wrapper classes around the size_ternal vector that only
        //allow for reading and writing, respectively, the parts
        //of the size_ternal vector unique to that data object.
        

        class DataHouse {
            private:
            std::unordered_map<std::string, std::any> collection;

            public:
            DataHouse() = default;
            DataHouse(DataHouse&& input);

            void add_value(std::string name, std::any input);
            template <typename T> T read_value(std::string name);
            std::vector<char> serialize();
            void deserialize(std::vector<char>);
            void write_to_file(std::string filename);
            void read_from_file(std::string filename);
        };
    };
 };
#endif
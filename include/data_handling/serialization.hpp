#ifndef CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_SERIALIZATION_HPP
#define CPP_TASK_MANAGEMENT_INCLUDE_DATA_HANDLING_SERIALIZATION_HPP

#include <any>
#include <unordered_map>
#include <typeindex>

#include <data_handling/vectorreadwrapper.hpp>
#include <data_handling/vectorwritewrapper.hpp>

namespace task_mgmt {   
    namespace datacollection {
        class SerializationHelper {
            void serialize(
                std::any input,
                VectorWriteWrapper vec_writter);

            std::any deserialize(VectorReadWrapper vec_reader);
        };

      
        static std::unordered_map<
                  std::string,
                  SerializationHelper
        > serialization_helper_map;

        template <typename T>
        void add_serialization_helper(
            std::type_index type,
            std::unique_ptr<SerializationHelper>
        );

    };
 };
#endif
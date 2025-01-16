#include <data_handling/vectorwrapper.hpp>
#include <data_handling/vectorwritewrapper.hpp>

namespace task_mgmt {
    namespace datacollection {
        VectorWriteWrapper::VectorWriteWrapper(
            std::shared_ptr<std::vector<char>> vec  
        ) : VectorWrapper(vec){}

        VectorWriteWrapper::VectorWriteWrapper(VectorWriteWrapper&& input) : 
            VectorWrapper(std::move(input.internal_vector)){}

        void VectorWriteWrapper::append(char input){
            this -> internal_vector -> push_back(input);
        }
    };
 };
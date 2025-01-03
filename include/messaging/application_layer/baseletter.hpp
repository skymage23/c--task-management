#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_APPLICATION_LAYER_BASELETTER_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_APPLICATION_LAYER_BASELETTER_HPP


namespace task_mgmt {
    namespace messaging {
        class BaseLetter {
            protected:
            unsigned int recipient_id;
            unsigned int sender_id;
        };
    };
};

#endif
#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MAILBOX_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MAILBOX_HPP
namespace task_mgnt {
    namespace messaging {
        class Mailbox {
            public:
            
            public:
            Mailbox() = delete;
            Mailbox(Mailbox& input) = delete;
            Mailbox(Mailbox&& input) = delete;
        };
    };
};
#endif
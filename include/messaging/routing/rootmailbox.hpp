#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_ROOTMAILBOX_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_ROOTMAILBOX_HPP

#include <memory>
#include <vector>

#include <messaging/routing/mailbox.hpp>
namespace task_mgmt {
    namespace messaging{
        class RootMailbox : Mailbox {
            private:
            std::vector<Mailbox> children;

            public:
            RootMailbox();
            std::unique_ptr<Mailbox> create_mailbox();


            void notify_recipients();
            void send(BaseLetter& BaseLetter);
            BaseLetter receive();
        };
    };
};
#endif
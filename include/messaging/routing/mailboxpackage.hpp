#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOXPACKAGE_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOXPACKAGE_HPP
#include <messaging/routing/descriptors/mailbox_package_types.hpp>
#include <messaging/routing/descriptors/mailbox_transmission_types.hpp>

namespace task_mgmt {
    namespace messaging {
        //Class:
        struct MailboxPackage {
            unsigned int mb_sender_id;
            unsigned int mb_receiver_id;
            MailboxTransmissionTypes mp_trans_type;
            MailboxPackageTypes mb_package_type;

            MailboxPackage(
                unsigned int sender,
                unsigned int receiver,
                MailboxTransmissionTypes trans_type,
                MailboxPackageTypes package_type 
            );
        };
    };
};
#endif
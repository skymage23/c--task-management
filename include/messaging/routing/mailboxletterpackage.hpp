#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOXBaseLetterPACKAGE_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOXBaseLetterPACKAGE_HPP

#include <messaging/routing/descriptors/mailbox_package_types.hpp>
#include <messaging/routing/descriptors/mailbox_utility_package_types.hpp>
#include <messaging/application_layer/baseletter.hpp>
#include <messaging/routing/mailboxpackage.hpp>


namespace task_mgmt {
    namespace messaging {
        struct MailboxLetterPackage : MailboxPackage {
            BaseLetter payload;

            MailboxLetterPackage(
                unsigned int sender,
                unsigned int receiver,
                MailboxTransmissionTypes mp_trans_type,
                BaseLetter payload
            );

        };
    }; //namespace messaging
}; //namespace task_mgmt

#endif
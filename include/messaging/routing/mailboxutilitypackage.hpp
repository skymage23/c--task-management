#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOXUTILITYPACKAGE_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOXUTILITYPACKAGE_HPP

#include <messaging/routing/descriptors/mailbox_package_types.hpp>
#include <messaging/routing/descriptors/mailbox_utility_package_types.hpp>
#include <messaging/routing/mailboxpackage.hpp>
namespace task_mgmt {
    namespace messaging {
        struct MailboxUtilityPackage : MailboxPackage {
            MailboxUtilityPackageTypes mp_util_type;

            MailboxUtilityPackage(
                unsigned int sender,
                unsigned int receiver,
                MailboxTransmissionTypes mp_trans_type,
                MailboxUtilityPackageTypes up_type
            );
        };
    };
};
#endif
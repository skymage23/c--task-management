#include <messaging/routing/descriptors/mailbox_package_types.hpp>
#include <messaging/routing/descriptors/mailbox_utility_package_types.hpp>
#include <messaging/routing/mailboxpackage.hpp>
#include <messaging/routing/mailboxutilitypackage.hpp>
namespace task_mgmt {
    namespace messaging {
        MailboxUtilityPackage::MailboxUtilityPackage(
            unsigned int sender,
            unsigned int receiver,
            MailboxTransmissionTypes mp_trans_type,
            MailboxUtilityPackageTypes up_type
        ) : MailboxPackage(
            sender,
            receiver,
            mp_trans_type,
            MailboxPackageTypes::Utility
        ){}
    }; //namespace messaging
}; //namespace task_mgmt
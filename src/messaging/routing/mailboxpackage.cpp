#include <messaging/routing/descriptors/mailbox_package_types.hpp>
#include <messaging/routing/descriptors/mailbox_transmission_types.hpp>
#include <messaging/routing/mailboxpackage.hpp>

namespace task_mgmt {
    namespace messaging {
        MailboxPackage::MailboxPackage(
            unsigned int sender,
            unsigned int receiver,
            MailboxTransmissionTypes trans_type,
            MailboxPackageTypes package_type
        ) : mb_sender_id(sender), 
            mb_receiver_id(receiver),
            mp_trans_type(trans_type),
            mb_package_type(package_type){}
    };
};
#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_ROUTING_DESCRIPTORS_MAILBOX_PACKAGE_TYPES_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_ROUTING_DESCRIPTORS_MAILBOX_PACKAGE_TYPES_HPP
namespace task_mgmt {
    namespace messaging {
        enum class MailboxTransmissionTypes {
            Broadcast,
            SingleRecipient
        };
    };
};
#endif
#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_DESCRIPTORS_MAILBOX_UTILITY_PACKAGE_TYPES_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_DESCRIPTORS_MAILBOX_UTILITY_PACKAGE_TYPES_HPP
namespace task_mgmt {
    namespace messaging {
        enum class MailboxUtilityPackageTypes {
            WhoHas
            #ifndef DISALLOW_DIRECT_COMM
            ,
            DirectCommRequest,
            DirectCommRequestResponse,
            DirectCommCloseRequest,
            DirectCommCloseConfirm
            #endif 
        };
    };
};
#endif
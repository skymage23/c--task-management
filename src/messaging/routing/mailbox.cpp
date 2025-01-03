#include <memory>


#include <messaging/routing/descriptors/mailbox_package_types.hpp>
#include <messaging/routing/descriptors/mailbox_transmission_types.hpp>
#include <messaging/routing/descriptors/mailbox_utility_package_types.hpp>
#include <messaging/routing/mailbox.hpp>
#include <messaging/routing/mailboxutilitypackage.hpp>

namespace task_mgmt {
   namespace messaging {
        Mailbox::Mailbox(
            std::shared_ptr<Mailbox> parent,
            unsigned int id  
        ) : parent(parent),
            mailbox_id(id),

#ifndef DISALLOW_DIRECT_COMMS
            allow_direct_comms(true),
#endif

            have_mail(false),
            can_send(true)
        {}

        void Mailbox::package_ingress_and_dispatch(
            MailboxPackage input
        ) {
            switch(input.mb_package_type){
                case MailboxPackageTypes::Utility: {
                     break;   
                }

                case MailboxPackageTypes::Letter: {
                     break;
                }
            };
        }

        void Mailbox::utility_package_ingress_and_dispatch(
            MailboxUtilityPackage input
        ){
            switch(input.mp_util_type){
                case MailboxUtilityPackageTypes::WhoHas: {
                   break;   
                }

#ifndef DISALLOW_DIRECT_COMM
                case MailboxUtilityPackageTypes::DirectCommRequest: {
                    break;
                }

                case MailboxUtilityPackageTypes::DirectCommRequestResponse: {
                    break;   
                }

                case MailboxUtilityPackageTypes::DirectCommCloseRequest: {
                    break;
                }

                case MailboxUtilityPackageTypes::DirectCommCloseConfirm: {
                    break;
                }
#endif
            };
        }


   }; //namespace messaging
}; //namespace task_mgmt
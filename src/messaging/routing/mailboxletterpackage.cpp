#include <messaging/routing/descriptors/mailbox_package_types.hpp>
#include <messaging/routing/mailboxletterpackage.hpp>
#include <messaging/routing/mailboxpackage.hpp>

namespace task_mgmt {
    namespace messaging {
            MailboxLetterPackage::MailboxLetterPackage(
                  unsigned int sender,
                  unsigned int receiver,
                  MailboxTransmissionTypes mp_trans_type,
                  BaseLetter payload
            ) : MailboxPackage(
              sender,
              receiver,
              mp_trans_type,
              MailboxPackageTypes::Letter
            ){
                this -> payload = payload;
            }
    }; //namespace messaging
}; //namespace task_mgmt
#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOX_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MESSAGING_ROUTING_MAILBOX_HPP

#include <chrono>
#include <memory>

#ifndef DISALLOW_DIRECT_COMM
#include <unordered_map>
#endif

#include <vector>


#include <messaging/application_layer/baseletter.hpp>
#include <messaging/routing/mailboxpackage.hpp>
#include <messaging/routing/mailboxutilitypackage.hpp>
//#include <messaging/rootmailbox.hpp>
namespace task_mgmt {
    namespace messaging {
        struct MailboxRoutingRecord{
           unsigned int task_id;
           unsigned int mailbox_id;
           std::chrono::time_point<std::chrono::system_clock> timestamp;
        };


        class Mailbox {
            protected:
            std::shared_ptr<Mailbox> parent;
            std::vector<MailboxPackage> inbox;
            std::vector<MailboxPackage> outbox;
            unsigned int mailbox_id;

            #ifndef DISALLOW_DIRECT_COMM
            bool allow_direct_comms;  //Can bypass the routing system
                                      //in favor of directly touching the
                                      //client mailbox. Usage of this
                                      //feature requires that both parties
                                      //agree to this.
            std::unordered_map<unsigned int, Mailbox*> mb_ptr_map;
            #endif

            bool have_mail;
            bool can_send; //Not all Mailboxes can.
            

            protected:
            Mailbox(std::shared_ptr<Mailbox> parent, unsigned int id);

            //Called by the other party, directly or otherwise.
            //Puts the BaseLetter in the inbox and sets "have_mail"
            //to "true".
            void package_ingress_and_dispatch(MailboxPackage input);
            void utility_package_ingress_and_dispatch(MailboxUtilityPackage input);

            void utility_package_dispatch_handle_who_has(MailboxUtilityPackage input);
            void utility_package_dispatch_handle_direct_comm(MailboxUtilityPackage input);

            //ARP-like:
            unsigned int who_has(unsigned int task_id);



            public:
            //You're not suppossed to be able to create a Mailbox object.
            Mailbox() = delete;
            Mailbox(Mailbox& input) = delete;
            Mailbox(Mailbox&& input) = delete;
            
            //Notify interested parties (if any) that there
            //is new mail.
            virtual void notify_recipients();
            virtual void put_in_outgoing(BaseLetter& BaseLetter);
            virtual void send_outgoing();
            virtual BaseLetter receive();
            bool mail_for_me();
        };
    };
};
#endif
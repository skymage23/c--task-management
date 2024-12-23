#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MAILBOX_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_MAILBOX_HPP

#include <memory>
#include <vector>

#include <letter.hpp>

namespace task_mgnt {
    namespace messaging {
        class Mailbox {
            private:
            bool have_mail;
            bool can_send; //Not all Mailboxes can.
 
            protected:
            //Used when instantiating other parties.
            Mailbox(Mailbox* input);

            //Called by the other party, directly or otherwise.
            //Puts the letter in the inbox and sets "have_mail"
            //to "true".
            void receive(Letter input);

            public:
            Mailbox() = delete;
            Mailbox(Mailbox& input) = delete;
            Mailbox(Mailbox&& input) = delete;
            

            virtual Mailbox* create_other_party();
            //Notify interested parties (if any) that there
            //is new mail.
            virtual void notify_recipients();
            virtual void send(Letter& letter);
            virtual Letter receive();
            bool mail_for_me();
            bool can_send();
        };
    };
};
#endif
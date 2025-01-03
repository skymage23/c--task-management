#include <memory>
#include <thread>

#include <gtest/gtest.h>

#include <messaging/application_layer/letter.hpp>
#include <messaging/routing/mailbox.hpp>
#include <messaging/routing/rootmailbox.hpp>


TEST(messaging_basic_functionality, TestMessagePassing){
    char byte_to_send = 0x1;:w
    void run(
        std::unique_ptr<task_mgmt::messaging::Mailbox> client_mailbox,
        char data
    ){
        client_mailbox.request_direct_()
        client_mailbox.send(
            task_mgmt::messaging::ByteLetter(data);
        );
    }

    
    task_mgmt::messaging::RootMailbox mailbox;


    std::thread cli_thread(run, mailbox.create_mailbox());
    cli_thread.join();

    task_mgmt::messaging::ByteLetter letter = mailbox.receive();
    ASSERT_EQ(letter.extract(), byte_to_send);
}
//Don't assume this will be used directly.
//This is a thinking/scratchpad file.

#include <memory>
#include <thread>
#include <signal.h>

namespace tasks {
    namespace signal_handling {

        //Global signal handler:
        static void global_signal_handler(int signum){
            switch (signum){
                
            };
        }

        static void sig_thread_run(){

        }        

        static std::unique_ptr<std::thread> sig_thread = nullptr;


        void initialize_global_signal_handler(){
            sig_thread = std::make_unique<std::thread>(sig_thread_run);

        }

        //We are finished with the library
        //and need to unregister our signal handlers
        //and set them back to what they were before
        //we were initialized.
        void deinitialize_global_signal_handler(){
            if(sig_thread == nullptr){
                return;
            }
            sig_thread -> join();
            sig_thread.release();
            sig_thread = nullptr;
        }
    };
}; 
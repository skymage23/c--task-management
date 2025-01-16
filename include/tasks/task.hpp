#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASKS
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASKS

#include <concepts>
#include <future>
#include <memory>
#include <vector>


#include <messaging/application_layer/letter.hpp>
#include <task-controller/taskcontroller.hpp>
#include <task-runner/taskrunnerhandle.hpp>
namespace task_mgmt {
    //Tasks are always single threaded.
    //If you need more threads, break up your job
    //into batches that can be ran on multiple tasks
    //in parallel.
    //If the tasks need to share data, there are comms
    //channels that can bet set up for such.
    //
    //Provided the user has allowed the use of enough
    //system threads and the host has enough cores
    //to handle such, this framework always attempts
    //to run each task on its own thread, giving
    //the best possible parallel throughput.
    //
    //This class actually works a lot like how a video game
    //engine works. If you ever wonder why you have
    //frame rate drops, it's because some task or other
    //is taking too much time to complete, and
    //since neither the OS nor the game engine
    //are using timer interrupts to cap the amount of
    //time a piece of logic is allowed to run (
    //realistically, how can they?), it is always
    //allowed to run to completion. That's
    //why gamers prioritize single core
    //processing speed when selecting a CPU
    //for their new gaming computers. It's
    //also why game developers are demeaned
    //whenever they don't optimize their game's
    //single thread logic operation completion throughput.
    //
    //In other words, if you want to make the most of this class,
    //you need to take a lesson from game development and optimize
    //single thread logic operation completion throughput.
    //
    // To use this class, you first need to subclass it and provide implementations
    // for the run method and the lifecycle callbacks.
    class Task {
        private:
        TaskRunnerHandle runner_handle;

        private:
        //We need some way
        void initialize_task(TaskRunnerHandle input);
        void initialize_task(TaskRunnerHandle& input);
        void initialize_task(TaskRunnerHandle&& input); 
        friend class TaskController;

        protected:
        //messaging:
        template <typename T, typename D = T> void send_letter(
            unsigned int task_id,
            messaging::Letter<D,T> letter
        );

        template <typename T> void send_letter(
            unsigned int task_id,
            messaging::UnitypeLetter<T> letter
        );

        void send_letter(unsigned int task_id, messaging::ByteLetter letter);
        void send_letter(unsigned int task_id, messaging::IntLetter letter);
        void send_letter(unsigned int task_id, messaging::LongLetter letter);
        void send_letter(unsigned int task_id, messaging::LongLongLetter letter);
        void send_letter(unsigned int task_id, messaging::ShortLetter letter);
        void send_letter(unsigned int task_id, messaging::UnsignedByteLetter letter);
        void send_letter(unsigned int task_id, messaging::UnsignedIntLetter letter);
        void send_letter(unsigned int task_id, messaging::UnsignedLongLetter letter);
        void send_letter(unsigned int task_id, messaging::UnsignedLongLongLetter letter);
        void send_letter(unsigned int task_id, messaging::UnsignedShortLetter letter);
        void send_letter(unsigned int task_id, messaging::BoolLetter letter);
        void send_letter(unsigned int task_id, messaging::FloatLetter letter);
        void send_letter(unsigned int task_id, messaging::DoubleLetter letter);


        template <typename T, typename D = T> void send_letter(
            std::string task_name,
            messaging::Letter<D,T> letter
        );

        template <typename T> void send_letter(
            std::string task_name,
            messaging::UnitypeLetter<T> letter
        );

        void send_letter(std::string task_name, messaging::ByteLetter letter);
        void send_letter(std::string task_name, messaging::IntLetter letter);
        void send_letter(std::string task_name, messaging::LongLetter letter);
        void send_letter(std::string task_name, messaging::LongLongLetter letter);
        void send_letter(std::string task_name, messaging::ShortLetter letter);
        void send_letter(std::string task_name, messaging::UnsignedByteLetter letter);
        void send_letter(std::string task_name, messaging::UnsignedIntLetter letter);
        void send_letter(std::string task_name, messaging::UnsignedLongLetter letter);
        void send_letter(std::string task_name, messaging::UnsignedLongLongLetter letter);
        void send_letter(std::string task_name, messaging::UnsignedShortLetter letter);
        void send_letter(std::string task_name, messaging::BoolLetter letter);
        void send_letter(std::string task_name, messaging::FloatLetter letter);
        void send_letter(std::string task_name, messaging::DoubleLetter letter);

        //Request direct messaging with a specific task.
        //This sidesteps the routing overhead, making
        //communications potentially faster.
        //However, it now relies on mutex-locked queues,
        //meaning "faster" requires that your tasks
        //communicate often enough or send large enough
        //chunks of data that the cost of mutex-locking
        //the queues is small in comparision to the normal
        //data copying costs of using routed messaging.
        void request_direct_messaging(unsigned int task_id);

        //Returns a vector of task ids with which the current Task object
        //has a direct messaging agreement.
        std::unique_ptr<std::vector<unsigned int>> list_direct_messaging_agreements();

        //Close a direct messaging connection.
        void cancel_direct_messaging(unsigned int task_id);

        //Task Management:
        void request_task_execution(Task input);

        //Requests launch of a OneShotTask
        //OneShotTasks are unique in that
        //they cannot be messaged or communicated
        //with after the initial launch.
        //They are designed for simple, autonomous tasks,
        //like downloading information off of a network.
        //You can only communicate with them at their 
        //creation and when they return a datum.
        //Therefore, ensure all parameters needed are stored
        //inside the functor before calling this method
        //to launch the OneShotTask.
        template <std::invocable F> 
        std::future request_oneshot_task_execution(F&& functor);

        public:
        Task() = default;
        Task(Task& input) = delete;
        Task(Task&& input) = delete;


        /*These are all executed by the TaskRunner.*/
        //Lifecycle methods: 
        virtual void on_first_run();
        virtual void run();
        virtual void on_pause();
        virtual void on_resume();
        virtual void on_stop();
        virtual void on_task_exit();
    };
};
#endif
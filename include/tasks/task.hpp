#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASKS
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASKS

#include <messaging/application_layer/letter.hpp>
#include <task-controller/taskcontroller.hpp>
#include <task-runner/taskrunnerhandle.hpp>
namespace task_mgmt {
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
        template <class T, class D = T> void send_letter(
            unsigned int task_id,
            messaging::Letter<D,T> letter
        );

        template <class T> void send_letter(
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
}
#endif
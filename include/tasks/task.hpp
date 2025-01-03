#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASKS
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASKS

#include <task-controller/taskcontroller.hpp>

namespace task_mgmt {
    class Task {
        private:
        Task();
        friend class TaskController;

        public:
        virtual void run();
    };
}
#endif
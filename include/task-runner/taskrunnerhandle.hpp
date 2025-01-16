#ifndef CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASK_RUNNER_TASKRUNNERHANDLE_HPP
#define CPLUSPLUS_TASK_MANAGEMENT_INCLUDE_TASK_RUNNER_TASKRUNNERHANDLE_HPP
#include <task-runner/taskrunner.hpp>

namespace task_mgmt {
    class TaskRunnerHandle {
        private:
        TaskRunner runner;

        private:
        TaskRunnerHandle(TaskRunner runner);
        friend class TaskRunner;
    };
};
#endif
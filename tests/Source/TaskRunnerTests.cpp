/*
    Copyright (c) 2018-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#include "TaskRunnerTests.h"
#include "Ishiko/UserTasks/TaskRunner.h"
#include "Ishiko/UserTasks/SyncFunctionTask.h"

using namespace Ishiko;
using namespace Ishiko::Tests;

TaskRunnerTests::TaskRunnerTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TaskRunner tests", environment)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("Creation test 2", CreationTest2);
    append<HeapAllocationErrorsTest>("start test 1", StartTest1);
    append<HeapAllocationErrorsTest>("start test 2", StartTest2);
    append<HeapAllocationErrorsTest>("post test 1", PostTest1);
    append<HeapAllocationErrorsTest>("post test 2", PostTest2);
}

void TaskRunnerTests::CreationTest1(Test& test)
{
    TaskRunner taskRunner(1);
    
    ISHIKO_PASS();
}

void TaskRunnerTests::CreationTest2(Test& test)
{
    TaskRunner taskRunner(16);
    
    ISHIKO_PASS();
}

void TaskRunnerTests::StartTest1(Test& test)
{
    TaskRunner taskRunner(1);
    taskRunner.start();
    taskRunner.stop();
    taskRunner.join();

    ISHIKO_PASS();
}

void TaskRunnerTests::StartTest2(Test& test)
{
    TaskRunner taskRunner(16);
    taskRunner.start();
    taskRunner.stop();
    taskRunner.join();

    ISHIKO_PASS();
}

void TaskRunnerTests::PostTest1(Test& test)
{
    TaskRunner taskRunner(1);
    taskRunner.start();

    std::shared_ptr<Ishiko::SyncFunctionTask> task = std::make_shared<Ishiko::SyncFunctionTask>([](){});
    taskRunner.post(task);

    taskRunner.stop();
    taskRunner.join();

    ISHIKO_FAIL_IF_NOT(task->status() == Ishiko::Task::EStatus::eCompleted);
    ISHIKO_PASS();
}

void TaskRunnerTests::PostTest2(Test& test)
{
    TaskRunner taskRunner(16);
    taskRunner.start();

    std::shared_ptr<Ishiko::SyncFunctionTask> task = std::make_shared<Ishiko::SyncFunctionTask>([]() {});
    taskRunner.post(task);

    taskRunner.stop();
    taskRunner.join();

    ISHIKO_FAIL_IF_NOT(task->status() == Ishiko::Task::EStatus::eCompleted);
    ISHIKO_PASS();
}

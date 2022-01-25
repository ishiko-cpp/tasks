/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#include "TaskTests.h"
#include "Ishiko/UserTasks/SyncFunctionTask.h"

using namespace Ishiko::Tests;
using namespace Ishiko::UserTasks;

TaskTests::TaskTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Task tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
    append<HeapAllocationErrorsTest>("run test 2", RunTest2);
    append<HeapAllocationErrorsTest>("run test 3", RunTest3);
}

void TaskTests::CreationTest1(Test& test)
{
    Task task;

    ISHIKO_FAIL_IF_NEQ(task.status(), Task::EStatus::ePending);

    ISHIKO_PASS();
}

void TaskTests::RunTest1(Test& test)
{
    Task task;
    task.run();

    ISHIKO_FAIL_IF_NEQ(task.status(), Task::EStatus::eCompleted);

    ISHIKO_PASS();
}

void TaskTests::RunTest2(Test& test)
{
    SyncFunctionTask task([]() { throw std::exception(); });
    task.run();

    ISHIKO_FAIL_IF_NEQ(task.status(), Task::EStatus::eFailed);
    ISHIKO_PASS();
}

void TaskTests::RunTest3(Test& test)
{
    Task task;

    std::shared_ptr<TestTaskObserver> observer = std::make_shared<TestTaskObserver>();
    task.observers().add(observer);

    task.run();

    ISHIKO_FAIL_IF_NEQ(task.status(), Task::EStatus::eCompleted);
    ISHIKO_FAIL_IF_NEQ(observer->statuses().size(), 2);
    ISHIKO_FAIL_IF_NEQ(observer->statuses()[0], Task::EStatus::eRunning);
    ISHIKO_FAIL_IF_NEQ(observer->statuses()[1], Task::EStatus::eCompleted);
    ISHIKO_PASS();
}

void TestTaskObserver::onStatusChanged(const Task& source, Task::EStatus status)
{
    m_statuses.push_back(status);
}

const std::vector<Task::EStatus> TestTaskObserver::statuses() const
{
    return m_statuses;
}

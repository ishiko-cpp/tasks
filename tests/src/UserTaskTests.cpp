/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/workflows/blob/main/LICENSE.txt
*/

#include "UserTaskTests.hpp"
#include "Ishiko/Workflows/SyncFunctionTask.hpp"

using namespace Ishiko;

UserTaskTests::UserTaskTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Task tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
    append<HeapAllocationErrorsTest>("run test 2", RunTest2);
    append<HeapAllocationErrorsTest>("run test 3", RunTest3);
}

void UserTaskTests::CreationTest1(Test& test)
{
    UserTask task;

    ISHIKO_TEST_FAIL_IF_NEQ(task.status(), UserTask::EStatus::ePending);

    ISHIKO_TEST_PASS();
}

void UserTaskTests::RunTest1(Test& test)
{
    UserTask task;
    task.run();

    ISHIKO_TEST_FAIL_IF_NEQ(task.status(), UserTask::EStatus::eCompleted);

    ISHIKO_TEST_PASS();
}

void UserTaskTests::RunTest2(Test& test)
{
    SyncFunctionTask task([]() { throw std::exception(); });
    task.run();

    ISHIKO_TEST_FAIL_IF_NEQ(task.status(), UserTask::EStatus::eFailed);
    ISHIKO_TEST_PASS();
}

void UserTaskTests::RunTest3(Test& test)
{
    UserTask task;

    std::shared_ptr<TestTaskObserver> observer = std::make_shared<TestTaskObserver>();
    task.observers().add(observer);

    task.run();

    ISHIKO_TEST_FAIL_IF_NEQ(task.status(), UserTask::EStatus::eCompleted);
    ISHIKO_TEST_FAIL_IF_NEQ(observer->statuses().size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(observer->statuses()[0], UserTask::EStatus::eRunning);
    ISHIKO_TEST_FAIL_IF_NEQ(observer->statuses()[1], UserTask::EStatus::eCompleted);
    ISHIKO_TEST_PASS();
}

void TestTaskObserver::onStatusChanged(const UserTask& source, UserTask::EStatus status)
{
    m_statuses.push_back(status);
}

const std::vector<UserTask::EStatus> TestTaskObserver::statuses() const
{
    return m_statuses;
}

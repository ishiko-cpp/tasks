/*
    Copyright (c) 2018-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Tasks/blob/master/LICENSE.txt
*/

#include "TaskTests.h"

using namespace Ishiko::Tests;

TaskTests::TaskTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Task tests", environment)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
    append<HeapAllocationErrorsTest>("run test 2", RunTest2);
}

void TaskTests::CreationTest1(Test& test)
{
    Ishiko::Task task;

    ISHTF_FAIL_IF_NOT(task.status() == Ishiko::Task::EStatus::ePending);
    ISHTF_PASS();
}

void TaskTests::RunTest1(Test& test)
{
    Ishiko::Task task;
    task.run();

    ISHTF_FAIL_IF_NOT(task.status() == Ishiko::Task::EStatus::eCompleted);
    ISHTF_PASS();
}

void TaskTests::RunTest2(Test& test)
{
    Ishiko::Task task;

    std::shared_ptr<TestTaskObserver> observer = std::make_shared<TestTaskObserver>();
    task.observers().add(observer);

    task.run();

    ISHTF_FAIL_IF_NOT(task.status() == Ishiko::Task::EStatus::eCompleted);
    ISHTF_FAIL_IF_NOT(observer->statuses().size() == 2);
    ISHTF_FAIL_IF_NOT(observer->statuses()[0] == Ishiko::Task::EStatus::eRunning);
    ISHTF_FAIL_IF_NOT(observer->statuses()[1] == Ishiko::Task::EStatus::eCompleted);
    ISHTF_PASS();
}

void TestTaskObserver::onStatusChanged(const Ishiko::Task& source, Ishiko::Task::EStatus status)
{
    m_statuses.push_back(status);
}

const std::vector<Ishiko::Task::EStatus> TestTaskObserver::statuses() const
{
    return m_statuses;
}

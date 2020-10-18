/*
    Copyright (c) 2018-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Tasks/blob/master/LICENSE.txt
*/

#include "TasksTests.h"
#include "Ishiko/Tasks/Tasks.h"

using namespace Ishiko::Tests;

TasksTests::TasksTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Tasks tests", environment)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("add test 1", AddTest1);
    append<HeapAllocationErrorsTest>("addObserver test 1", AddObserverTest1);
    append<HeapAllocationErrorsTest>("removeObserver test 1", RemoveObserverTest1);
}

void TasksTests::CreationTest1(Test& test)
{
    Ishiko::Tasks tasks;

    ISHTF_FAIL_IF_NOT(tasks.size() == 0);
    ISHTF_PASS();
}

void TasksTests::AddTest1(Test& test)
{
    Ishiko::Tasks tasks;
    tasks.add(std::make_shared<Ishiko::Task>());
    
    ISHTF_FAIL_IF_NOT(tasks.size() == 1);
    ISHTF_PASS();
}

void TasksTests::AddObserverTest1(Test& test)
{
    Ishiko::Tasks tasks;
    std::shared_ptr<Ishiko::Tasks::Observer> observer = std::make_shared<Ishiko::Tasks::Observer>();
    tasks.observers().add(observer);

    ISHTF_PASS();
}

void TasksTests::RemoveObserverTest1(Test& test)
{
    Ishiko::Tasks tasks;
    std::shared_ptr<Ishiko::Tasks::Observer> observer = std::make_shared<Ishiko::Tasks::Observer>();
    tasks.observers().add(observer);
    tasks.observers().remove(observer);

    ISHTF_PASS();
}

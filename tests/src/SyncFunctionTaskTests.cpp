/*
    Copyright (c) 2018-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#include "SyncFunctionTaskTests.h"
#include "Ishiko/UserTasks/SyncFunctionTask.h"

using namespace Ishiko::Tests;
using namespace Ishiko::UserTasks;

SyncFunctionTaskTests::SyncFunctionTaskTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "SyncFunctionTask tests", environment)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
}

void SyncFunctionTaskTests::CreationTest1(Test& test)
{
    SyncFunctionTask task([]() -> void {});
    ISHIKO_PASS();
}

void SyncFunctionTaskTests::RunTest1(Test& test)
{
    SyncFunctionTask task([]() -> void {});
    task.run();

    ISHIKO_FAIL_IF_NOT(task.status() == Task::EStatus::eCompleted);
    ISHIKO_PASS();
}

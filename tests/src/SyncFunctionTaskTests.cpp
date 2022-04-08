/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#include "SyncFunctionTaskTests.h"
#include "Ishiko/UserTasks/SyncFunctionTask.h"

using namespace Ishiko;

SyncFunctionTaskTests::SyncFunctionTaskTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "SyncFunctionTask tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
}

void SyncFunctionTaskTests::CreationTest1(Test& test)
{
    SyncFunctionTask task([]() -> void {});
    ISHIKO_TEST_PASS();
}

void SyncFunctionTaskTests::RunTest1(Test& test)
{
    SyncFunctionTask task([]() -> void {});
    task.run();

    ISHIKO_TEST_FAIL_IF_NOT(task.status() == UserTask::EStatus::eCompleted);
    ISHIKO_TEST_PASS();
}

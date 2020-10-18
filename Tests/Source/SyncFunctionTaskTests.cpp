/*
    Copyright (c) 2018-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Tasks/blob/master/LICENSE.txt
*/

#include "SyncFunctionTaskTests.h"
#include "Ishiko/Tasks/SyncFunctionTask.h"

using namespace Ishiko::Tests;

SyncFunctionTaskTests::SyncFunctionTaskTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "SyncFunctionTask tests", environment)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
}

void SyncFunctionTaskTests::CreationTest1(Test& test)
{
    Ishiko::SyncFunctionTask task([]() -> void {});
    ISHTF_PASS();
}

void SyncFunctionTaskTests::RunTest1(Test& test)
{
    Ishiko::SyncFunctionTask task([]() -> void {});
    task.run();

    ISHTF_FAIL_IF_NOT(task.status() == Ishiko::Task::EStatus::eCompleted);
    ISHTF_PASS();
}

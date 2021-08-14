/*
    Copyright (c) 2015-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#include "TaskTests.h"
#include "SyncFunctionTaskTests.h"
#include "TasksTests.h"
#include "TaskRunnerTests.h"
#include <Ishiko/Tests/Core.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoUserTasks");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<TaskTests>();
    theTests.append<SyncFunctionTaskTests>();
    theTests.append<TasksTests>();
    theTests.append<TaskRunnerTests>();

    return theTestHarness.run();
}

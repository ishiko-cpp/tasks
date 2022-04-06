/*
    Copyright (c) 2015-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#include "TaskTests.h"
#include "SyncFunctionTaskTests.h"
#include "TasksTests.h"
#include "TaskRunnerTests.h"
#include "Ishiko/UserTasks/linkoptions.h"
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

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

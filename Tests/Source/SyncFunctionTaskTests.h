/*
    Copyright (c) 2018-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TEST_TASKS_SYNCFUNCTIONTASKTESTS_H_
#define _ISHIKO_TEST_TASKS_SYNCFUNCTIONTASKTESTS_H_

#include <Ishiko/Tests/Core.h>

class SyncFunctionTaskTests : public Ishiko::Tests::TestSequence
{
public:
    SyncFunctionTaskTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void CreationTest1(Ishiko::Tests::Test& test);
    static void RunTest1(Ishiko::Tests::Test& test);
};

#endif

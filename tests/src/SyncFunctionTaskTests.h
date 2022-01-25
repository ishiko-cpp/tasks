/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TESTS_SYNCFUNCTIONTASKTESTS_H_
#define _ISHIKO_CPP_USERTASKS_TESTS_SYNCFUNCTIONTASKTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class SyncFunctionTaskTests : public Ishiko::Tests::TestSequence
{
public:
    SyncFunctionTaskTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestContext& context);

private:
    static void CreationTest1(Ishiko::Tests::Test& test);
    static void RunTest1(Ishiko::Tests::Test& test);
};

#endif

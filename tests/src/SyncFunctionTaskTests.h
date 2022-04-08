/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TESTS_SYNCFUNCTIONTASKTESTS_H_
#define _ISHIKO_CPP_USERTASKS_TESTS_SYNCFUNCTIONTASKTESTS_H_

#include <Ishiko/TestFramework/Core.hpp>

class SyncFunctionTaskTests : public Ishiko::TestSequence
{
public:
    SyncFunctionTaskTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void RunTest1(Ishiko::Test& test);
};

#endif

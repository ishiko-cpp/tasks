/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TEST_TASKRUNNERTESTS_H_
#define _ISHIKO_CPP_USERTASKS_TEST_TASKRUNNERTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class TaskRunnerTests : public Ishiko::Tests::TestSequence
{
public:
    TaskRunnerTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestContext& context);

private:
    static void CreationTest1(Ishiko::Tests::Test& test);
    static void CreationTest2(Ishiko::Tests::Test& test);
    static void StartTest1(Ishiko::Tests::Test& test);
    static void StartTest2(Ishiko::Tests::Test& test);
    static void PostTest1(Ishiko::Tests::Test& test);
    static void PostTest2(Ishiko::Tests::Test& test);
};

#endif

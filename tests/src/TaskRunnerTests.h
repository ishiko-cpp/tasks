/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TEST_TASKRUNNERTESTS_H_
#define _ISHIKO_CPP_USERTASKS_TEST_TASKRUNNERTESTS_H_

#include <Ishiko/TestFramework/Core.hpp>

class TaskRunnerTests : public Ishiko::TestSequence
{
public:
    TaskRunnerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void CreationTest2(Ishiko::Test& test);
    static void StartTest1(Ishiko::Test& test);
    static void StartTest2(Ishiko::Test& test);
    static void PostTest1(Ishiko::Test& test);
    static void PostTest2(Ishiko::Test& test);
};

#endif

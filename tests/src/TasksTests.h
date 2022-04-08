/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TESTS_TASKSTESTS_H_
#define _ISHIKO_CPP_USERTASKS_TESTS_TASKSTESTS_H_

#include <Ishiko/TestFramework/Core.hpp>

class TasksTests : public Ishiko::TestSequence
{
public:
    TasksTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void AddTest1(Ishiko::Test& test);
    static void AddObserverTest1(Ishiko::Test& test);
    static void RemoveObserverTest1(Ishiko::Test& test);
};

#endif

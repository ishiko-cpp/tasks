/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TESTS_TASKTESTS_H_
#define _ISHIKO_CPP_USERTASKS_TESTS_TASKTESTS_H_

#include "Ishiko/UserTasks/Task.h"
#include <Ishiko/Tests/Core.hpp>

class TaskTests : public Ishiko::Tests::TestSequence
{
public:
    TaskTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestContext& context);

private:
    static void CreationTest1(Ishiko::Tests::Test& test);
    static void RunTest1(Ishiko::Tests::Test& test);
    static void RunTest2(Ishiko::Tests::Test& test);
    static void RunTest3(Ishiko::Tests::Test& test);
};

class TestTaskObserver : public Ishiko::UserTasks::Task::Observer
{
public:
    void onStatusChanged(const Ishiko::UserTasks::Task& source, Ishiko::UserTasks::Task::EStatus status) override;

    const std::vector<Ishiko::UserTasks::Task::EStatus> statuses() const;

public:
    std::vector<Ishiko::UserTasks::Task::EStatus> m_statuses;
};

#endif

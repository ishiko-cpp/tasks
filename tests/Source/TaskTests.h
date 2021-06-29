/*
    Copyright (c) 2018-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TEST_TASKS_TASKTESTS_H_
#define _ISHIKO_TEST_TASKS_TASKTESTS_H_

#include <Ishiko/Tests/Core.h>
#include "Ishiko/Tasks/Task.h"

class TaskTests : public Ishiko::Tests::TestSequence
{
public:
    TaskTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void CreationTest1(Ishiko::Tests::Test& test);
    static void RunTest1(Ishiko::Tests::Test& test);
    static void RunTest2(Ishiko::Tests::Test& test);
    static void RunTest3(Ishiko::Tests::Test& test);
};

class TestTaskObserver : public Ishiko::Task::Observer
{
public:
    void onStatusChanged(const Ishiko::Task& source, Ishiko::Task::EStatus status) override;

    const std::vector<Ishiko::Task::EStatus> statuses() const;

public:
    std::vector<Ishiko::Task::EStatus> m_statuses;
};

#endif

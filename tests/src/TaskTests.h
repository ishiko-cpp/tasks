/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TESTS_TASKTESTS_H_
#define _ISHIKO_CPP_USERTASKS_TESTS_TASKTESTS_H_

#include "Ishiko/UserTasks/UserTask.hpp"
#include <Ishiko/TestFramework/Core.hpp>

class TaskTests : public Ishiko::TestSequence
{
public:
    TaskTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void RunTest1(Ishiko::Test& test);
    static void RunTest2(Ishiko::Test& test);
    static void RunTest3(Ishiko::Test& test);
};

class TestTaskObserver : public Ishiko::UserTask::Observer
{
public:
    void onStatusChanged(const Ishiko::UserTask& source, Ishiko::UserTask::EStatus status) override;

    const std::vector<Ishiko::UserTask::EStatus> statuses() const;

public:
    std::vector<Ishiko::UserTask::EStatus> m_statuses;
};

#endif

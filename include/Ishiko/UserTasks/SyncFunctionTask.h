/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_SYNCFUNCTIONTASK_H_
#define _ISHIKO_CPP_USERTASKS_SYNCFUNCTIONTASK_H_

#include "UserTask.hpp"
#include <functional>

namespace Ishiko
{
namespace UserTasks
{

class SyncFunctionTask : public UserTask
{
public:
    SyncFunctionTask(std::function<void()> fct);

    void doRun() override;

private:
    std::function<void()> m_task;
};

}
}

#endif

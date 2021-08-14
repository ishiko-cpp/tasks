/*
    Copyright (c) 2018-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#include "SyncFunctionTask.h"

namespace Ishiko
{
namespace UserTasks
{

SyncFunctionTask::SyncFunctionTask(std::function<void()> fct)
    : m_task(fct)
{
}

void SyncFunctionTask::doRun()
{
    m_task();
}

}
}

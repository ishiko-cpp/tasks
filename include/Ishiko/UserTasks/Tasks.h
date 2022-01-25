/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TASKS_H_
#define _ISHIKO_CPP_USERTASKS_TASKS_H_

#include "Task.h"
#include <Ishiko/Collections.hpp>
#include <memory>

namespace Ishiko
{
namespace UserTasks
{

class Tasks : private Collections::ObservableVector<std::shared_ptr<Task>, Tasks>
{
public:
    typedef Collections::ObservableVector<std::shared_ptr<Task>, Tasks>::Observer Observer;

    size_t size() const;

    void add(std::shared_ptr<Task> task);

    Collections::ObservableVector<std::shared_ptr<Task>, Tasks>::Observers& observers();
};

}
}

#endif

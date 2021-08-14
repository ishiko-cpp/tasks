/*
    Copyright (c) 2018-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TASKS_TASKS_H_
#define _ISHIKO_TASKS_TASKS_H_

#include "Task.h"
#include "Ishiko/Collections/ObservableVector.h"
#include <memory>

namespace Ishiko
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

#include "linkoptions.h"

#endif

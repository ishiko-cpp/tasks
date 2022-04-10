/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TASKS_HPP_
#define _ISHIKO_CPP_USERTASKS_TASKS_HPP_

#include "UserTask.hpp"
#include <Ishiko/Collections.hpp>
#include <memory>

namespace Ishiko
{

class Tasks : private ObservableVector<std::shared_ptr<UserTask>, Tasks>
{
public:
    typedef ObservableVector<std::shared_ptr<UserTask>, Tasks>::Observer Observer;

    size_t size() const;

    void add(std::shared_ptr<UserTask> task);

    ObservableVector<std::shared_ptr<UserTask>, Tasks>::Observers& observers();
};

}

#endif

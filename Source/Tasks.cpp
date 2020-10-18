/*
    Copyright (c) 2018-2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Tasks/blob/master/LICENSE.txt
*/

#include "Tasks.h"

namespace Ishiko
{

size_t Tasks::size() const
{
    return Collections::ObservableVector<std::shared_ptr<Task>, Tasks>::size();
}

void Tasks::add(std::shared_ptr<Task> task)
{
    Collections::ObservableVector<std::shared_ptr<Task>, Tasks>::pushBack(task);
}

Collections::ObservableVector<std::shared_ptr<Task>, Tasks>::Observers& Tasks::observers()
{
    return Collections::ObservableVector<std::shared_ptr<Task>, Tasks>::observers();
}

}

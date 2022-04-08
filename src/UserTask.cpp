/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#include "UserTask.hpp"
#include <algorithm>

namespace Ishiko
{

void UserTask::Observer::onStatusChanged(const UserTask& source, EStatus status)
{
}

void UserTask::Observers::add(std::shared_ptr<Observer> observer)
{
    auto it = std::find_if(m_observers.begin(), m_observers.end(),
        [&observer](const std::pair<std::weak_ptr<Observer>, size_t>& o)
    {
        return (o.first.lock() == observer);
    }
    );
    if (it != m_observers.end())
    {
        ++it->second;
    }
    else
    {
        m_observers.push_back(std::pair<std::weak_ptr<Observer>, size_t>(observer, 1));
    }
}

void UserTask::Observers::remove(std::shared_ptr<Observer> observer)
{
    auto it = std::find_if(m_observers.begin(), m_observers.end(),
        [&observer](const std::pair<std::weak_ptr<Observer>, size_t>& o)
    {
        return (o.first.lock() == observer);
    }
    );
    if (it != m_observers.end())
    {
        --it->second;
        if (it->second == 0)
        {
            m_observers.erase(it);
        }
    }
}

void UserTask::Observers::notifyStatusChanged(const UserTask& source, EStatus status)
{
    for (std::pair<std::weak_ptr<Observer>, size_t>& o : m_observers)
    {
        std::shared_ptr<Observer> observer = o.first.lock();
        if (observer)
        {
            observer->onStatusChanged(source, status);
        }
        else
        {
            removeDeletedObservers();
        }
    }
}

void UserTask::Observers::removeDeletedObservers()
{
    auto it = std::remove_if(m_observers.begin(), m_observers.end(),
        [](const std::pair<std::weak_ptr<Observer>, size_t>& o)
    {
        return o.first.expired();
    }
    );
    m_observers.erase(it, m_observers.end());
}

UserTask::UserTask()
    : m_status(EStatus::ePending)
{
}

UserTask::EStatus UserTask::status() const
{
    return m_status;
}

void UserTask::run()
{
    m_status = EStatus::eRunning;
    observers().notifyStatusChanged(*this, m_status);
    try
    {
        doRun();
        m_status = EStatus::eCompleted;
    }
    catch (...)
    {
        m_status = EStatus::eFailed;
    }
    observers().notifyStatusChanged(*this, m_status);
}

void UserTask::doRun()
{
}

UserTask::Observers& UserTask::observers()
{
    return m_observers;
}

}

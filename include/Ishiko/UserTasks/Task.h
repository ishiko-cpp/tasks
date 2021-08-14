/*
    Copyright (c) 2018-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_TASK_H_
#define _ISHIKO_CPP_USERTASKS_TASK_H_

#include <vector>
#include <memory>

namespace Ishiko
{

class Task
{
public:
    enum class EStatus
    {
        ePending,
        eRunning,
        eCompleted,
        eFailed
    };

    class Observer
    {
    public:
        virtual ~Observer() = default;

        virtual void onStatusChanged(const Task& source, EStatus status);
    };

    class Observers final
    {
    public:
        void add(std::shared_ptr<Observer> observer);
        void remove(std::shared_ptr<Observer> observer);

        void notifyStatusChanged(const Task& source, EStatus status);

    private:
        void removeDeletedObservers();

    private:
        std::vector<std::pair<std::weak_ptr<Observer>, size_t>> m_observers;
    };

    Task();
    virtual ~Task() noexcept = default;

    EStatus status() const;

    void run();
    virtual void doRun();

    Observers& observers();

private:
    EStatus m_status;
    Observers m_observers;
};

}

#include "linkoptions.h"

#endif

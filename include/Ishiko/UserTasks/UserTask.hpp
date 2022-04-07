/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/user-tasks/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_USERTASKS_USERTASK_HPP_
#define _ISHIKO_CPP_USERTASKS_USERTASK_HPP_

#include <vector>
#include <memory>

namespace Ishiko
{

class UserTask
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

        virtual void onStatusChanged(const UserTask& source, EStatus status);
    };

    class Observers final
    {
    public:
        void add(std::shared_ptr<Observer> observer);
        void remove(std::shared_ptr<Observer> observer);

        void notifyStatusChanged(const UserTask& source, EStatus status);

    private:
        void removeDeletedObservers();

    private:
        std::vector<std::pair<std::weak_ptr<Observer>, size_t>> m_observers;
    };

    UserTask();
    virtual ~UserTask() noexcept = default;

    EStatus status() const;

    void run();
    virtual void doRun();

    Observers& observers();

private:
    EStatus m_status;
    Observers m_observers;
};

}

#endif

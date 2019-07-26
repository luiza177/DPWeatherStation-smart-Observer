#ifndef ISUBJECT_H
#define ISUBJECT_H
#include <memory>
#include "IObserver.h"

class ISubject
{
public:
    ISubject() {}
    virtual ~ISubject() {}
    virtual void registerObserver(std::shared_ptr<IObserver>& obs) = 0;
    virtual void removeObserver(std::shared_ptr<IObserver>& obs) = 0;
    virtual void notifyObservers() = 0;
};

#endif
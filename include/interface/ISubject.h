#ifndef ISUBJECT_H
#define ISUBJECT_H
#include <memory>
#include "IObserver.h"

class ISubject
{
public:
    ISubject() {}
    virtual ~ISubject() {}
    virtual void registerObserver(IObserver* obs) = 0;
    virtual void removeObserver(IObserver* obs) = 0;
    virtual void notifyObservers() = 0;
};

#endif
#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
public:
    IObserver() {}
    virtual ~IObserver() {}
    virtual void update(double temp, double humidity, double pressure) = 0;
};

#endif
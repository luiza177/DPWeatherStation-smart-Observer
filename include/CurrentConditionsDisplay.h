#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H
#include <iostream>
#include <memory>
#include "interface/ISubject.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class CurrentConditionsDisplay : public IObserver, IDisplayElement, std::enable_shared_from_this<CurrentConditionsDisplay>
{
private:
    double m_temperature, m_humidity;
    std::shared_ptr<ISubject> m_weatherData;
public:
    CurrentConditionsDisplay() {}
    virtual ~CurrentConditionsDisplay() {}
    void registerWithSubject(std::shared_ptr<ISubject> weatherData);
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif
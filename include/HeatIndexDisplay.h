#ifndef HEATINDEXDISPLAY_H
#define HEATINDEXDISPLAY_H
#include <iostream>
#include "interface/ISubject.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class HeatIndexDisplay : public IObserver, IDisplayElement, std::enable_shared_from_this<HeatIndexDisplay>
{
private:
    double m_temperature, m_humidity, m_heatIndex;
    std::shared_ptr<ISubject> m_weatherData;
    double computeHeatIndex(double ct, double rh);
public:
    HeatIndexDisplay() {}
    virtual ~HeatIndexDisplay() {}
    void registerWithSubject(std::shared_ptr<ISubject> weatherData);    
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif
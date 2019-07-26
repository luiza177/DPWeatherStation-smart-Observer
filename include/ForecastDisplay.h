#ifndef FORECASTDISPLAY_H
#define FORECASTDISPLAY_H
#include <iostream>
#include <memory>
#include "interface/ISubject.h"
#include "WeatherData.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class ForecastDisplay : public IObserver, IDisplayElement, std::enable_shared_from_this<ForecastDisplay>
{
private:
    double m_currentPressure = 29.92;  
	double m_lastPressure;
    std::shared_ptr<ISubject> m_weatherData;
public:
    ForecastDisplay(std::shared_ptr<ISubject> weatherData) : m_weatherData(weatherData) 
    {
        
        this->m_weatherData->registerObserver(shared_from_this());
    }
    virtual ~ForecastDisplay(){}
    
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif
#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H
#include <iostream>
#include "interface/ISubject.h"
#include "interface/IObserver.h"
#include "interface/IDisplayElement.h"

class StatisticsDisplay : public IObserver, IDisplayElement, std::enable_shared_from_this<StatisticsDisplay>
{
private:
    double m_temperature;
    std::shared_ptr<ISubject> m_weatherData;
    double m_maxTemp = 0.0;
	double m_minTemp = 200;
	double m_tempSum = 0.0;
	int m_numReadings = 0;
public:
    StatisticsDisplay(std::shared_ptr<ISubject> weatherData) : m_weatherData(weatherData) 
    {
        this->m_weatherData->registerObserver(shared_from_this());
    }
    virtual ~StatisticsDisplay() {}
    void update(double temp, double humidity, double pressure) override;
    void display() const override;
};
#endif
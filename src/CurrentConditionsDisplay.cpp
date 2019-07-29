#include "CurrentConditionsDisplay.h"

void CurrentConditionsDisplay::registerWithSubject(std::shared_ptr<ISubject> weatherData)
{
    m_weatherData = weatherData;
    this->m_weatherData->registerObserver(this);
}

void CurrentConditionsDisplay::update(double temp, double humidity, double pressure)
{
    this->m_temperature = temp;
    this->m_humidity = humidity;
    display();
}

void CurrentConditionsDisplay::display() const
{
    std::cout << "Current Conditions: " << m_temperature
        << "C degrees and " << m_humidity <<
        "% humidity" << std::endl;
};
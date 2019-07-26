#include "CurrentConditionsDisplay.h"

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
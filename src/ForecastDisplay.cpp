#include "ForecastDisplay.h"

void ForecastDisplay::registerWithSubject(std::shared_ptr<ISubject> weatherData)
{
    m_weatherData = weatherData;
    this->m_weatherData->registerObserver(this);
}

void ForecastDisplay::update(double temp, double humidity, double pressure)
{
    this->m_lastPressure = m_currentPressure;
    this->m_currentPressure = pressure;
    display();
}
void ForecastDisplay::display() const
{
    std::cout << "Forecast: ";
    if (m_currentPressure > m_lastPressure) 
    {
        std::cout << "Improving weather on the way!\n";
    } 
    else if (m_currentPressure == m_lastPressure) 
    {
        std::cout << "More of the same\n";
    } 
    else if (m_currentPressure < m_lastPressure) 
    {
        std::cout << "Watch out for cooler, rainy weather\n";
    }
}
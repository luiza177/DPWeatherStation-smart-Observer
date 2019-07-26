#include "StatisticsDisplay.h"

void StatisticsDisplay::update(double temp, double humidity, double pressure)
{
    m_tempSum += temp;
    m_numReadings++;
    if (temp > m_maxTemp)
    {
        m_maxTemp = temp;
    }
    if (temp < m_minTemp)
    {
        m_minTemp = temp;
    }
    display();
}
void StatisticsDisplay::display() const
{
    std::cout << "Avg/Max/Min temperature = " << (m_tempSum / m_numReadings)
        << "/" << m_maxTemp << "/" << m_minTemp << std::endl;
}
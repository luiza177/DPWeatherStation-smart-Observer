#include "WeatherData.h"

void WeatherData::registerObserver(IObserver* obs)
{
    std::shared_ptr<IObserver> obs_shared(obs);
    m_observers.insert(obs_shared);
}
void WeatherData::removeObserver(IObserver* obs)
{
    auto itr = std::find_if(m_observers.begin(), m_observers.end(), [&obs](auto iobs){ return iobs.get() == obs; });
    m_observers.erase(itr);
}
void WeatherData::notifyObservers()
{
    for(auto obs : m_observers) 
    {   
        // if (!obs.expired())
        // {
            // auto obs_shared = obs.lock();
            obs->update(m_temperature, 
                m_humidity, 
                m_pressure);
            // obs_shared.reset();
        // }
    }  
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}

void WeatherData::setMeasurements(double temp, double hum, double press) // TODO: write C++ version of python weather
{
    this->m_temperature = temp;
    this->m_humidity = hum;
    this->m_pressure = press;
    measurementsChanged();
}
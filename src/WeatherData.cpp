#include "WeatherData.h"

void WeatherData::registerObserver(std::shared_ptr<IObserver>& obs)
{
    m_observers.insert(obs);
    // std::weak_ptr<IObserver> obs_weak = obs; 
    // m_observers.push_back(obs);
}
void WeatherData::removeObserver(std::shared_ptr<IObserver>& obs)
{
    m_observers.erase(obs);
    // std::weak_ptr<IObserver> obs_weak = obs;
    // m_observers.erase(
    //     std::remove_if(m_observers.begin(), 
    //         m_observers.end(), 
    //         [&](const std::weak_ptr<IObserver>& wptr)
    //         {
    //             return wptr.expired() || wptr.lock() == obs;
    //         }
    //     ),
    //     this->m_observers.end()
    // );
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
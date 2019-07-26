#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <vector>
#include <algorithm>
#include <set>
#include "interface/ISubject.h"


struct compareWeakPtr
{
    bool operator()(const std::weak_ptr<IObserver>& lhs, const std::weak_ptr<IObserver>& rhs)
    {
        auto lhs_shared = lhs.lock();
        auto rhs_shared = rhs.lock();
        // if(!rhs_shared) { return false; }
        // if(!lhs_shared) { return true; }
        return lhs_shared.get() == rhs_shared.get();
    }
};

class WeatherData : public ISubject
{
private:
    // std::set<std::weak_ptr<IObserver>,compareWeakPtr> m_observers;
    std::vector<std::weak_ptr<IObserver>> m_observers;
    double m_temperature, m_humidity, m_pressure;
public:
    WeatherData() {}
    virtual ~WeatherData() {}

    void registerObserver(std::shared_ptr<IObserver>& obs) override;
    void removeObserver(std::shared_ptr<IObserver>& obs) override;
    void notifyObservers() override;
    void measurementsChanged();
    void setMeasurements(double temp, double hum, double press); // TODO: write C++ version of python weather
};

#endif
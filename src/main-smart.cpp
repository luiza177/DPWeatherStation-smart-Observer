#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "ForecastDisplay.h"
#include "StatisticsDisplay.h"
#include "HeatIndexDisplay.h"

//TODO: rethink set -> vector + search algorithm
//TODO: try weak_ptr again

//TODO: DEBUG

int main(int argc, char const *argv[])
{
    auto weatherData = std::make_shared<WeatherData>(WeatherData());
    auto currentConditionsDisplay = std::make_shared<CurrentConditionsDisplay>();
    currentConditionsDisplay->registerWithSubject(weatherData);

    auto heatIndexDisplay = std::make_shared<HeatIndexDisplay>(HeatIndexDisplay());
    heatIndexDisplay->registerWithSubject(weatherData);

    auto forecastDisplay = std::make_shared<ForecastDisplay>(ForecastDisplay());
    forecastDisplay->registerWithSubject(weatherData);

    auto statsDisplay = std::make_shared<StatisticsDisplay>(StatisticsDisplay());
    statsDisplay->registerWithSubject(weatherData);

    weatherData->setMeasurements(30, 65, 30.4);
    std::cout << std::endl;
    weatherData->setMeasurements(24, 70, 29.2);
    std::cout << std::endl;
    weatherData->removeObserver(heatIndexDisplay.get());
    weatherData->setMeasurements(27, 90, 29.2);

    return 0;
}

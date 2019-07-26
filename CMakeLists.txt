cmake_minimum_required(VERSION 3.15)
set(THIS WeatherStation-smart)

project(${THIS})

include_directories(include)

set(SOURCES_SMART
    src/main-smart.cpp
    src/CurrentConditionsDisplay.cpp
    src/ForecastDisplay.cpp
    src/StatisticsDisplay.cpp
    src/HeatIndexDisplay.cpp
    src/WeatherData.cpp
)

add_executable(${THIS} ${SOURCES_SMART})
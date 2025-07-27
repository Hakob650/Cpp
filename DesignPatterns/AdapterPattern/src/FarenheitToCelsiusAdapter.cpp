#include "../include/FarenheitToCelsiusAdapter.hpp"

FarenheitToCelsiusAdapter::FarenheitToCelsiusAdapter(std::unique_ptr<OldFarenheitSensor> sensor)
    : oldSensor(std::move(sensor)) {}

double FarenheitToCelsiusAdapter::getTemperatureCelsius()
{
    double farenheit = oldSensor->getTemperatureFarenheit();
    return (farenheit - 32) * 5.0 / 9.0;
}
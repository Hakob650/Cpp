#pragma once

class TemperatureSensor
{
public:
    virtual double getTemperatureCelsius() = 0;
    virtual ~TemperatureSensor() = default;
};
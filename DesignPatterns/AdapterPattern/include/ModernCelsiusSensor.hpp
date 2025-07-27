#pragma once

#include "TemperatureSensor.hpp"

class ModernCelsiusSensor : public TemperatureSensor
{
public:
    double getTemperatureCelsius() override;
};
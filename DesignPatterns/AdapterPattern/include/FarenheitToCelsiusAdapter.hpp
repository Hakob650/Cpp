#pragma once

#include <memory>
#include "TemperatureSensor.hpp"
#include "OldFarenheitSensor.hpp"

class FarenheitToCelsiusAdapter : public TemperatureSensor
{
private:
        std::unique_ptr<OldFarenheitSensor> oldSensor;
public:
        explicit FarenheitToCelsiusAdapter(std::unique_ptr<OldFarenheitSensor> sensor);
        double getTemperatureCelsius() override;
};
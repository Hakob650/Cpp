#include <iostream>
#include <vector>
#include <memory>

#include "include/TemperatureSensor.hpp"
#include "include/OldFarenheitSensor.hpp"
#include "include/FarenheitToCelsiusAdapter.hpp"
#include "include/ModernCelsiusSensor.hpp"

int main()
{
    std::vector<std::unique_ptr<TemperatureSensor>> sensors;

    auto legacySensor = std::make_unique<OldFarenheitSensor>();
    sensors.push_back(std::make_unique<FarenheitToCelsiusAdapter>(std::move(legacySensor)));

    sensors.push_back(std::make_unique<ModernCelsiusSensor>());

    for(const auto& sensor : sensors)
    {
        std::cout << "Temperature in Celsius: " << sensor->getTemperatureCelsius() << std::endl;
    }

    return 0;
}

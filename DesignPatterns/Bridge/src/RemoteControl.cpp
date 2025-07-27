#include <iostream>
#include "../include/RemoteControl.hpp"

RemoteControl::RemoteControl(std::shared_ptr<Device> dev) : device(std::move(dev)) {}

void RemoteControl::toggle_power() 
{
    if (device->is_enabled()) 
    {
        device->disable();
        std::cout << device->get_name() << " is now OFF\n";
    } 
    else 
    {
        device->enable();
        std::cout << device->get_name() << " is now ON\n";
    }
}

void RemoteControl::volume_up() 
{
    device->set_volume(device->get_volume() + 5);
    std::cout << device->get_name() << " volume: " << device->get_volume() << "\n";
}

void RemoteControl::volume_down() 
{
    device->set_volume(device->get_volume() - 5);
    std::cout << device->get_name() << " volume: " << device->get_volume() << "\n";
}

#include <iostream>
#include "../include/AdvancedRemoteControl.hpp"

AdvancedRemoteControl::AdvancedRemoteControl(std::shared_ptr<Device> dev)
    : RemoteControl(std::move(dev)) {}

void AdvancedRemoteControl::mute()
{
    device->set_volume(0);
    std::cout << device->get_name() << " is muted\n";
}

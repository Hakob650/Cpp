#pragma once

#include <memory>
#include "Device.hpp"

class RemoteControl
{
protected:
        std::shared_ptr<Device> device;
public:
        explicit RemoteControl(std::shared_ptr<Device> d);
        virtual void toggle_power();
        virtual void volume_up();
        virtual void volume_down();
};
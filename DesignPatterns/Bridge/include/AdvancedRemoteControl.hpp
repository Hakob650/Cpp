#pragma once

#include "RemoteControl.hpp"

class AdvancedRemoteControl : public RemoteControl
{
public:
        explicit AdvancedRemoteControl(std::shared_ptr<Device> device);
        void mute();
};
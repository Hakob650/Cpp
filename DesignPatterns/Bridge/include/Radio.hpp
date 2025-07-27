#pragma once

#include "Device.hpp"

class Radio : public Device
{
private:
        bool on = false;
        int volume = 20;
public:
        bool is_enabled() const override;
        void enable() override;
        void disable() override;
        int get_volume() const override;
        void set_volume(int volume) override;
        std::string get_name() const override;
};
#pragma once

#include "Device.hpp"

class TV : public Device
{
private:
        bool on = false;
        int volume = 10;
public:
        bool is_enabled() const override;
        void enable() override;
        void disable() override;
        int get_volume() const override;
        void set_volume(int volume) override;
        std::string get_name() const override;
};
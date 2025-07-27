#pragma once

#include <string>

class Device
{
public:
        virtual bool is_enabled() const = 0;
        virtual void enable() = 0;
        virtual void disable() = 0;
        virtual int get_volume() const = 0;
        virtual void set_volume(int volume) = 0;
        virtual std::string get_name()const = 0;
        virtual ~Device() = default;
};
#pragma once

#include <string>

class Message {
public:
    virtual ~Message() = default;
    virtual std::string getText(const std::string& message) const = 0;
};


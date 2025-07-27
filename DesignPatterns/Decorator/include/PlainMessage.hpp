#pragma once

#include "Message.hpp"

class PlainMessage : public Message {
public:
    std::string getText(const std::string& message) const override;
};



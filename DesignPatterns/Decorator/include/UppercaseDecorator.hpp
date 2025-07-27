#pragma once

#include <memory>
#include "Message.hpp"

class UpperCaseDecorator : public Message {
private:
    std::shared_ptr<Message> wrappee;

public:
    explicit UpperCaseDecorator(std::shared_ptr<Message> msg);
    std::string getText(const std::string& message) const override;
};


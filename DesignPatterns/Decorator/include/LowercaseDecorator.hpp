#pragma once

#include "Message.hpp"
#include <memory>

class LowerCaseDecorator : public Message {
private:
    std::shared_ptr<Message> wrappee;

public:
    explicit LowerCaseDecorator(std::shared_ptr<Message> msg);
    std::string getText(const std::string& message) const override;
};


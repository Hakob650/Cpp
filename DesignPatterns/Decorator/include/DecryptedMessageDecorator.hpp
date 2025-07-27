#pragma once

#include <memory>
#include <unordered_map>
#include "Message.hpp"

class DecryptedMessageDecorator : public Message {
private:
    std::shared_ptr<Message> wrappee;
    std::unordered_map<char, char> reverseCipher;

public:
    DecryptedMessageDecorator(std::shared_ptr<Message> msg, const std::unordered_map<char, char>& cipher);
    std::string getText(const std::string& message) const override;
};

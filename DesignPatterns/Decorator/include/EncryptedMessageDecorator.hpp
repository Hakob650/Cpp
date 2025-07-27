#pragma once

#include <memory>
#include <unordered_map>
#include "Message.hpp"

class EncryptedMessageDecorator : public Message {
private:
    std::shared_ptr<Message> wrappee;
    std::unordered_map<char, char> cipher;

public:
    EncryptedMessageDecorator(std::shared_ptr<Message> msg, const std::unordered_map<char, char>& cipherMap);
    std::string getText(const std::string& message) const override;
};


#include "../include/EncryptedMessageDecorator.hpp"

EncryptedMessageDecorator::EncryptedMessageDecorator(std::shared_ptr<Message> msg, const std::unordered_map<char, char>& cipherMap)
    : wrappee(std::move(msg)), cipher(cipherMap) {}

std::string EncryptedMessageDecorator::getText(const std::string& message) const 
{
    std::string input = wrappee->getText(message);
    for (auto& ch : input) {
        if (cipher.find(ch) != cipher.end()) {
            ch = cipher.at(ch);
        }
    }
    return input;
}

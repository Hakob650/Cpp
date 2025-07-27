#include "../include/DecryptedMessageDecorator.hpp"

DecryptedMessageDecorator::DecryptedMessageDecorator(std::shared_ptr<Message> msg, const std::unordered_map<char, char>& cipher)
    : wrappee(std::move(msg)) 
    {
        for (const auto& pair : cipher) 
        {
            reverseCipher[pair.second] = pair.first;
        }
    }

std::string DecryptedMessageDecorator::getText(const std::string& message) const 
{
    std::string input = wrappee->getText(message);
    for (auto& ch : input) {
        if (reverseCipher.find(ch) != reverseCipher.end()) {
            ch = reverseCipher.at(ch);
        }
    }
    return input;
}


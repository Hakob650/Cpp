#include <algorithm>
#include "../include/LowercaseDecorator.hpp"

LowerCaseDecorator::LowerCaseDecorator(std::shared_ptr<Message> msg) 
    : wrappee(std::move(msg)) {}

std::string LowerCaseDecorator::getText(const std::string& message) const 
{
    std::string result = wrappee->getText(message);
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

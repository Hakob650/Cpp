#include <algorithm>
#include "../include/UppercaseDecorator.hpp"

UpperCaseDecorator::UpperCaseDecorator(std::shared_ptr<Message> msg) 
    : wrappee(std::move(msg)) {}

std::string UpperCaseDecorator::getText(const std::string& message) const 
{
    std::string result = wrappee->getText(message);
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

#include <iostream>
#include <unordered_map>
#include <memory>

#include "include/PlainMessage.hpp"
#include "include/UppercaseDecorator.hpp"
#include "include/LowercaseDecorator.hpp"
#include "include/EncryptedMessageDecorator.hpp"
#include "include/DecryptedMessageDecorator.hpp"

int main() 
{
    std::unordered_map<char, char> cipher = {
        {'A','Q'}, {'B','W'}, {'C','E'}, {'D','R'}, {'E','T'}, {'F','Y'},
        {'G','U'}, {'H','I'}, {'I','O'}, {'J','P'}, {'K','A'}, {'L','S'},
        {'M','D'}, {'N','F'}, {'O','G'}, {'P','H'}, {'Q','J'}, {'R','K'},
        {'S','L'}, {'T','Z'}, {'U','X'}, {'V','C'}, {'W','V'}, {'X','B'},
        {'Y','N'}, {'Z','M'}, {'a','q'}, {'b','w'}, {'c','e'}, {'d','r'},
        {'e','t'}, {'f','y'}, {'g','u'}, {'h','i'}, {'i','o'}, {'j','p'},
        {'k','a'}, {'l','s'}, {'m','d'}, {'n','f'}, {'o','g'}, {'p','h'},
        {'q','j'}, {'r','k'}, {'s','l'}, {'t','z'}, {'u','x'}, {'v','c'},
        {'w','v'}, {'x','b'}, {'y','n'}, {'z','m'}
    };

    std::string input = "Hello, World!";

    auto base = std::make_shared<PlainMessage>();
    auto upper = std::make_shared<UpperCaseDecorator>(base);
    auto encrypted = std::make_shared<EncryptedMessageDecorator>(upper, cipher);
    auto decrypted = std::make_shared<DecryptedMessageDecorator>(encrypted, cipher);
    auto lower = std::make_shared<LowerCaseDecorator>(base);

    std::cout << "Original: " << base->getText(input) << "\n";
    std::cout << "Uppercase: " << upper->getText(input) << "\n";
    std::cout << "Encrypted: " << encrypted->getText(input) << "\n";
    std::cout << "Decrypted: " << decrypted->getText(input) << "\n";
    std::cout << "Lowercase: " << lower->getText(input) << "\n";

    return 0;
}

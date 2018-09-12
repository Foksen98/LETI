#include "algComparison.h"
#include <iostream>
#include <random>

const unsigned int AMOUNT_TESTS = 5;
const unsigned int PATTERN_LENGTH = 1500;
const unsigned int TEXT_LENGTH = 5000000;

// Генерация случайной строки
std::string generateRandomString(const unsigned int& len)
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 engine(rd());

    std::uniform_int_distribution<> dist(0, alphabet.size() - 1);

    std::string generatedString = "";
    for(int i = 0; i < len; ++i)
    {
        int randomIndex = dist(engine);
        generatedString += alphabet[randomIndex];
    }

    return generatedString;
}

int main ()
{
     AlgComparison cmp;
     std::string randPattern;
     std::string randText;

     // видимые тесты
     // #1
     randPattern = generateRandomString(4);
     randText = generateRandomString(100);
     std::cout << "Pattern: " << randPattern << "(4) | ";
     std::cout << "Text: " << randText << "(100)" << std::endl;
     cmp.compare(randPattern, randText);
     std::cout << std::endl;

     // #2
     randPattern = generateRandomString(10);
     randText = generateRandomString(1000);
     std::cout << "Pattern: " << randPattern << "(4) | ";
     std::cout << "Text: " << randText << "(100)" << std::endl;
     cmp.compare(randPattern, randText);
     std::cout << std::endl;

     // #3
     randPattern = generateRandomString(2);
     randText = generateRandomString(1000);
     std::cout << "Pattern: " << randPattern << "(4) | ";
     std::cout << "Text: " << randText << "(100)" << std::endl;
     cmp.compare(randPattern, randText);
     std::cout << std::endl;

     // #4
     randPattern = "aaaaaaaaaaaaaaaaaaaa";
     randText = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
     std::cout << "Pattern: " << randPattern << "(20) | ";
     std::cout << "Text: " << randText << "(100)" << std::endl;
     cmp.compare(randPattern, randText);
     std::cout << std::endl;

     // невидимые тесты
     for (size_t i = 0; i < AMOUNT_TESTS; ++i)
     {
         std::cout << "Pattern length: " << PATTERN_LENGTH << " | ";
         std::cout << "Text length: " << TEXT_LENGTH << std::endl;
         randPattern = generateRandomString(PATTERN_LENGTH);
         randText = generateRandomString(TEXT_LENGTH);
         cmp.compare(randPattern, randText);
         std::cout << std::endl;
     }


    return 0;
}

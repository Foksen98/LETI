#include "algComparison.h"
#include <iostream>

void AlgComparison::compare(std::string& pattern, std::string& text)
{
    std::cout << "KMP algorithm operations: " << kmpCompareAlgorithm(pattern, text) << " | ";
    std::cout << "Naive algorithm operations: " << naiveCompareAlgorithm(pattern, text) << std::endl;
}

//  префикс функция
std::vector<size_t> AlgComparison::prefixFunc (std::string& pattern)
{
    size_t length = pattern.length();
    std::vector<size_t> prefixVector(length);

    for (size_t i = 1; i < length; ++i)
    {
        size_t j = prefixVector[i - 1];
        while ((j > 0) && (pattern[i] != pattern[j]))
            j = prefixVector[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        prefixVector[i] = j;
    }

    return prefixVector;
}

//  наивный алгоритм поиска подстроки (возвращает количество сравнений)
long int AlgComparison::naiveCompareAlgorithm (std::string& pattern, std::string& text)
{
    long int amountComp = 0;
    size_t lenPattern = pattern.length();
    size_t lenText = text.length();

    for (size_t indexText = 0; indexText < (lenText - lenPattern + 1); ++indexText)
        for (size_t indexPattern = 0; indexPattern < lenPattern; ++indexPattern)
        {
            ++amountComp;
            if (pattern[indexPattern] != text[indexText + indexPattern])
                break;
        }

    return amountComp;
}

//  алгоритм Кнута-Морриса-Пратта (возвращает количество сравнений)
long int AlgComparison::kmpCompareAlgorithm (std::string& pattern, std::string& text)
{
    std::vector<size_t> prefixVector = prefixFunc(pattern);
    long int amountComp = 0;
    size_t lenPattern = pattern.length();
    size_t lenText = text.length();
    size_t indexPattern = 0;
    size_t indexText = 0;

    while (indexText < lenText)
    {
        if (text[indexText++] == pattern[indexPattern])
        {
            ++indexPattern;
            if (indexPattern == lenPattern)
                indexPattern = prefixVector[lenPattern - 1];
        }
        else if (indexPattern != 0)
        {
            --indexText;
            indexPattern = prefixVector[indexPattern - 1];
        }
        ++amountComp;
    }

    return amountComp;
}

#include "kmp.h"

//  префикс функция
std::vector<size_t> KMP::prefixFunc (std::string pattern)
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

//  алгоритм Кнута-Морриса-Пратта
std::vector<long int> KMP::kmpAlgorithm (std::string pattern, std::string text)
{
    std::vector<size_t> prefixVector = prefixFunc(pattern);
    std::vector<long int> indexVector;
    size_t lenPattern = pattern.length();
    size_t lenText = text.length();
    size_t indexPattern = 0;
    size_t indexText = 0;

    while (indexText < lenText)
        if (text[indexText++] == pattern[indexPattern])
        {
            ++indexPattern;
            if (indexPattern == lenPattern)
            {
                indexVector.push_back(indexText - lenPattern);
                indexPattern = prefixVector[lenPattern - 1];
            }
        }
        else if (indexPattern != 0)
        {
            --indexText;
            indexPattern = prefixVector[indexPattern - 1];
        }

    if (!indexVector.size())
        indexVector.push_back(-1);

    return indexVector;
}

//  алгоритм Кнута-Морриса-Пратта для сдвига (первое вхождение)
long int KMP::kmpShiftAlgorithm (std::string pattern, std::string text)
{
    std::vector<size_t> prefixVector = prefixFunc(pattern);
    size_t lenPattern = pattern.length();
    size_t lenText = text.length();
    size_t indexPattern = 0;
    size_t indexText = 0;

    while (indexText < (2 * lenText - 1))
        if (text[(indexText++ % lenText)] == pattern[indexPattern])
        {
            ++indexPattern;
            if (indexPattern == lenPattern)
                return (indexText - lenPattern);
        }
        else if (indexPattern != 0)
        {
            --indexText;
            indexPattern = prefixVector[indexPattern - 1];
        }

    return -1;
}

//  наивный алгоритм поиска подстроки (возвращает количество сравнений)
std::vector<long int> KMP::naiveAlgorithm (std::string pattern, std::string text)
{
    std::vector<long int> indexVector;
    size_t lenPattern = pattern.length();
    size_t lenText = text.length();

    for (size_t indexText = 0; indexText < (lenText - lenPattern + 1); ++indexText)
        for (size_t indexPattern = 0; indexPattern < lenPattern; ++indexPattern)
        {
            if (pattern[indexPattern] != text[indexText + indexPattern])
                break;
            else if (indexPattern == (lenPattern - 1))
                indexVector.push_back(indexText);
        }

    if (!indexVector.size())
        indexVector.push_back(-1);

    return indexVector;
}

#ifndef ALG_COMPARISON_H
#define ALG_COMPARISON_H

#include <string>
#include <vector>

class AlgComparison
{
public:
    void compare(std::string& pattern, std::string& text);

private:
    //  префикс функция
    std::vector<size_t> prefixFunc (std::string& pattern);
    //  наивный алгоритм поиска подстроки (возвращает количество сравнений)
    long int naiveCompareAlgorithm (std::string& pattern, std::string& text);
    //  алгоритм Кнута-Морриса-Пратта (возвращает количество сравнений)
    long int kmpCompareAlgorithm (std::string& pattern, std::string& text);
};

#endif

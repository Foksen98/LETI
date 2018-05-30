#ifndef KMP_H
#define KMP_H

#include <vector>
#include <string>

class KMP
{
public:
    //  префикс функция
    std::vector<size_t> prefixFunc (std::string& pattern);
    //  алгоритм Кнута-Морриса-Пратта
    std::vector<long int> kmpAlgorithm (std::string& pattern, std::string& text);
    //  алгоритм Кнута-Морриса-Пратта для сдвига (первое вхождение)
    long int kmpShiftAlgorithm (std::string& pattern, std::string& text);
    //  наивный алгоритм поиска подстроки (возвращает количество сравнений)
    std::vector<long int> naiveAlgorithm (std::string& pattern, std::string& text);
};

#endif

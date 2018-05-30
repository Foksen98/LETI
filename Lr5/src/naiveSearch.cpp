#include "kmp.h"
#include <iostream>

int main ()
{
    std::vector<long int> indexVector;
    std::string p;
    std::string t;

    std::cin >> p;
    std::cin >> t;

    KMP kmp;

    indexVector = kmp.naiveAlgorithm(p, t);
    size_t sizeIndVector = indexVector.size();

    std::cout << indexVector[0];
    for (size_t i = 1; i < sizeIndVector; ++i)
        std::cout << "," << indexVector[i];
    std::cout << std::endl;

    return 0;
}

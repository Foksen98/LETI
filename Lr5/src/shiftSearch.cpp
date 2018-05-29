#include "kmp.h"
#include <iostream>

int main ()
{
    std::string p;
    std::string t;

    std::cin >> p;
    std::cin >> t;

    KMP kmp;

    if (p.length() == t.length())
        std::cout << kmp.kmpShiftAlgorithm(t, p) << std::endl;
    else
        std::cout << "-1" << std::endl;

    return 0;
}

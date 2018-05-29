#include "kmpTest.h"
#include "../src/kmp.h"
#include <iostream>

struct testState
{
    std::string pattern;
    std::string string;
    std::vector<long int> results;

    friend std::ostream& operator<<(std::ostream& os, const testState& obj)
    {
        os << "[Text: " << obj.string << " | ";
        os << "Pattern: " << obj.pattern << " | ";
        os << "Result: ";

        for (auto result : obj.results)
        {
            os << result << " ";
        }
        os << "]" <<std::endl;

        return os;
    }
};

struct patternSearchTest : kmpTest, testing::WithParamInterface<testState>
{
    void SetUp()
    {
        std::cout << GetParam();
    }
};

TEST_P(patternSearchTest, searchPatternInText)
{
    auto state = GetParam();
    ASSERT_EQ(state.results, kmp->kmpAlgorithm(state.pattern, state.string));
}

INSTANTIATE_TEST_CASE_P(Default, patternSearchTest,
    testing::Values(
    testState{"a", "a", {0}},
    testState{"ab", "abab", {0, 2}},
    testState{"asd", "asfdasedkreadsda", {-1}},
    testState{"aaaa", "aaaabaaacaaaaad", {0, 9, 10}},
    testState{"ababcaba", "ababcabcdabababcababcababcaaa", {11, 16}},
    testState{"abcdabscabcdabia", "abcdabscabcdabiabcdabscabcdababcdabscabcdabiaabcdabscabcdabiaabcdascabcdabai", {0, 29, 45}},
    testState{"x", "xxxxcxvxxx", {0, 1, 2, 3, 5, 7, 8, 9}}
    ));

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

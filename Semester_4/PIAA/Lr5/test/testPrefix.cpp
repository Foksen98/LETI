#include "kmpTest.h"
#include "../src/kmp.h"
#include <iostream>

struct testState
{
    std::string string;
    std::vector<size_t> results;

    friend std::ostream& operator<<(std::ostream& os, const testState& obj)
    {
        os << "[String: " << obj.string << " | ";
        os << "Result: ";

        for (auto result : obj.results)
        {
            os << result << " ";
        }

        os << "]" <<std::endl;

      return os;
    }
};


struct prefixTest : kmpTest, testing::WithParamInterface<testState>
{
    void SetUp()
    {
        std::cout << GetParam();
    }
};

TEST_P(prefixTest, prefixFunction)
{
    auto state = GetParam();
    ASSERT_EQ(state.results, kmp->prefixFunc(state.string));
}


INSTANTIATE_TEST_CASE_P(Default, prefixTest,
    testing::Values(
    testState{"efefeftef", {0,0,1,2,3,4,0,1,2}},
    testState{"aaaaaaa", {0, 1, 2, 3, 4, 5, 6}},
    testState{"abcejlsdtf", {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    testState{"abaaba", {0, 0, 1, 1, 2, 3}},
    testState{"abcdabcabcdabcdab", {0, 0, 0, 0, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 4, 5, 6}},
    testState{"abcdabscabcdabia", {0, 0, 0, 0, 1, 2, 0, 0, 1, 2, 3, 4, 5, 6, 0, 1}}
    ));

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

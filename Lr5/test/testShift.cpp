#include "kmpTest.h"
#include "../src/kmp.h"
#include <iostream>

struct testState
{
    std::string checkingString;
    std::string sourceString;
    long int result;

    friend std::ostream& operator<<(std::ostream& os, const testState& obj)
    {
        os << "[Checking string(A): " << obj.checkingString << " | ";
        os << "Source(B): " << obj.sourceString << " | ";
        os << "Result: " << obj.result;
        os << "]" << std::endl;

        return os;
    }
};

struct checkShiftTest : kmpTest, testing::WithParamInterface<testState>
{
    void SetUp()
    {
      std::cout << GetParam();
    }
};

TEST_P(checkShiftTest, checkCycleShift)
{
    auto state = GetParam();
    ASSERT_EQ(state.result, kmp->kmpShiftAlgorithm(state.sourceString, state.checkingString));
}


INSTANTIATE_TEST_CASE_P(Default, checkShiftTest,
    testing::Values(
    testState{"defabc", "abcdef", 3},
    testState{"aaaaaaaaaaaa", "aaaaaaaaaaaa", 0},
    testState{"asdfghjkl", "lasdfghjk", 8},
    testState{"poploly", "lolypop", 3},
    testState{"iliketoworkwithstringsbutihavenotime", "tringsbutihavenotimeiliketoworkwiths", 16}
    ));

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

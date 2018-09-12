#ifndef KMP_TEST_H
#define KMP_TEST_H

#include <gtest/gtest.h>
#include "../src/kmp.h"

struct kmpTest : testing::Test
{
    KMP* kmp;
    kmpTest();
    ~kmpTest();
};

#endif

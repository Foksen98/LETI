#include "kmpTest.h"

kmpTest::kmpTest()
{
    kmp = new KMP;
}

kmpTest::~kmpTest()
{
    delete kmp;
}

#include "CppUTest/TestHarness.h"

extern "C"
{
#include "NumberOfFactors.h"
}

TEST_GROUP(NumberOfFactors) {};

TEST(NumberOfFactors, returnsTheNumberOfFactorsFor30)
{
  CHECK_EQUAL(8, NumberOfFactors_Count(30));
}

TEST(NumberOfFactors, returnsTheNumberOfFactorsFor28)
{
  CHECK_EQUAL(6, NumberOfFactors_Count(28));
}

TEST(NumberOfFactors, returnsTheNumberOfFactorsFor21)
{
  CHECK_EQUAL(4, NumberOfFactors_Count(21));
}

TEST(NumberOfFactors, returnsTheNumberOfFactorsFor76576500)
{
  CHECK_EQUAL(576, NumberOfFactors_Count(76576500));
}

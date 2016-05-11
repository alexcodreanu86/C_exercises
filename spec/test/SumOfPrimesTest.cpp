#include "CppUTest/TestHarness.h"

extern "C"
{
#include "SumOfPrimes.h"
}

TEST_GROUP(SumOfPrimes) {};

TEST(SumOfPrimes, returnsSumForPrimesSmallerThan10)
{
  UNSIGNED_LONGS_EQUAL(17, SumOfPrimes_SmallerThan(10));
}

TEST(SumOfPrimes, returnsSumFOrPrimesSmallerThan12)
{
  UNSIGNED_LONGS_EQUAL(28, SumOfPrimes_SmallerThan(12));
}

TEST(SumOfPrimes, returnsSumFOrPrimesSmallerThanTwoMill)
{
  UNSIGNED_LONGS_EQUAL(142913828922, SumOfPrimes_SmallerThan(2000000));
}

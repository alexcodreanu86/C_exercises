#include "CppUTest/TestHarness.h"

extern "C"
{
#include "NthPrime.h"
}

TEST_GROUP(NthPrime) {};

TEST(NthPrime, returnsSecondPrime)
{
  int number = NthPrime_Get(2);
  CHECK_EQUAL(3, number);
}

TEST(NthPrime, returnsSixthPrime)
{
  int number = NthPrime_Get(6);
  CHECK_EQUAL(13, number);
}

TEST(NthPrime, returnsNthPrime)
{
  int number = NthPrime_Get(10001);
  CHECK_EQUAL(104743, number);
}


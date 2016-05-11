#include "CppUTest/TestHarness.h"

extern "C"
{
#include "PythagoreanTriplets.h"
}

TEST_GROUP(PythagoreanTriplets) {};

TEST(PythagoreanTriplets, returnsProductOfMatchesForSum12)
{
  UNSIGNED_LONGS_EQUAL(60, PythagoreanTriplets_Product(3 + 4 + 5));
}

TEST(PythagoreanTriplets, returnsProductOfForSum1000)
{
  UNSIGNED_LONGS_EQUAL(31875000, PythagoreanTriplets_Product(1000));
}

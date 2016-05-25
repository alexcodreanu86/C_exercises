#include "CppUTest/TestHarness.h"

extern "C"
{
#include "DivisibleTriangularNumber.h"
}

TEST_GROUP(DivisibleTriangularNumber) {};

TEST(DivisibleTriangularNumber, returns28For5)
{
  UNSIGNED_LONGS_EQUAL(28 ,DivisibleTriangularNumber_withDivisorsOver(5));
}

TEST(DivisibleTriangularNumber, returnsResultFor100)
{
  UNSIGNED_LONGS_EQUAL(73920 ,DivisibleTriangularNumber_withDivisorsOver(100));
}

TEST(DivisibleTriangularNumber, returnsResultFor500)
{
  UNSIGNED_LONGS_EQUAL(76576500 ,DivisibleTriangularNumber_withDivisorsOver(500));
}

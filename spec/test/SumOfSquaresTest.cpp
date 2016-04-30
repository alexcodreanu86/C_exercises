#include "CppUTest/TestHarness.h"

extern "C"
{
#include "SumOfSquares.h"
}
TEST_GROUP(SumOfSquares) {};

TEST(SumOfSquares, returnsTheSumForOne)
{
  UNSIGNED_LONGS_EQUAL(1, SumOfSquares_calculate(1));
}

TEST(SumOfSquares, returnsTheSumForTwo)
{
  UNSIGNED_LONGS_EQUAL(5, SumOfSquares_calculate(2));
}

TEST(SumOfSquares, returnsTheSumForTen)
{
  UNSIGNED_LONGS_EQUAL(385, SumOfSquares_calculate(10));
}

TEST(SumOfSquares, returnsTheSquareSumOfTen)
{
  UNSIGNED_LONGS_EQUAL(3025, SumOfSquares_SquareOfSum(10));
}

TEST(SumOfSquares, returnsTheSquareSumDifferenceOfTen)
{
  UNSIGNED_LONGS_EQUAL(2640, SumOfSquares_SquareSumDifference(10));
}

TEST(SumOfSquares, returnsSquareOfSumForTwo)
{
  UNSIGNED_LONGS_EQUAL(9, SumOfSquares_SquareOfSum(2));
}

TEST(SumOfSquares, returnsTheSumForAHundred)
{
  UNSIGNED_LONGS_EQUAL(338350, SumOfSquares_calculate(100));
}

TEST(SumOfSquares, differenceBetweenSquareAndSum)
{
  UNSIGNED_LONGS_EQUAL(25502500, SumOfSquares_SquareOfSum(100));
}
TEST(SumOfSquares, returnsTheSquareSumDifferenceOfAHundred)
{
  UNSIGNED_LONGS_EQUAL(25164150, SumOfSquares_SquareSumDifference(100));
}

